#pragma once

#include "MinhaLinguagemBaseVisitor.h"
#include "TabelaSimbolos.h"

class ColetorClasses : public MinhaLinguagemBaseVisitor {
private:
    TabelaSimbolos& tabela;
    
public:
    ColetorClasses(TabelaSimbolos& tabela) : tabela(tabela) {}
    
    antlrcpp::Any visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext* ctx) override {
        
        if (!ctx->ID) {
            return nullptr; // Não processa se não tiver nome
        }            
        
        std::string nome = ctx->ID->getText();
        std::string superClasse = "";
        
        if (ctx->IDENTIFICADOR().size() > 1) {
            superClasse = ctx->IDENTIFICADOR(1)->getText();
        }
        
        Simbolo simbolo;
        simbolo.nome = nome;
        simbolo.tipo = TipoDado::CLASSE;
        simbolo.categoria = Categoria::CLASSE;
        simbolo.nivelEscopo = tabela.getNivelAtual();
        simbolo.nomeSuperClasse = superClasse; // Armazenar superclasse
        
        // Coletar construtores e membros
        std::vector<Simbolo> membros;
        for (auto membroCtx : ctx->membro()) {
            // Coletar variáveis membro
            if (auto varCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_variavelContext*>(membroCtx)) {
                std::string nomeMembro = varCtx->ID->getText();
                std::string tipoStr = varCtx->tipo()->getText();
                bool isVetor = (varCtx->ABRE_COLCHETES() != nullptr);
                
                TipoDado tipo = stringParaTipo(tipoStr);
                if (isVetor) {
                    // Converter para tipo vetorial
                    if (tipo == TipoDado::INT) tipo = TipoDado::VETOR_INT;
                    else if (tipo == TipoDado::FLOAT) tipo = TipoDado::VETOR_FLOAT;
                    else if (tipo == TipoDado::CHAR) tipo = TipoDado::VETOR_CHAR;
                    else if (tipo == TipoDado::STRING) tipo = TipoDado::VETOR_STRING;
                }
                
                membros.push_back(Simbolo{
                    nomeMembro,
                    tipo,
                    Categoria::VARIAVEL,
                    isVetor,
                    tabela.getNivelAtual()
                });
            }
            // Coletar métodos
            else if (auto funcCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_funcaoContext*>(membroCtx)) {
                std::string nomeMetodo = funcCtx->ID->getText();
                TipoDado tipoRetorno = stringParaTipo(funcCtx->tipo()->getText());
                
                std::vector<TipoDado> tiposParam;
                if (funcCtx->parametros()) {
                    for (auto param : funcCtx->parametros()->parametro()) {
                        tiposParam.push_back(stringParaTipo(param->tipo()->getText()));
                    }
                }
                
                membros.push_back(Simbolo{
                    nomeMetodo,
                    tipoRetorno,
                    tiposParam,
                    tabela.getNivelAtual()
                });
            }
            // Coletar construtores
            if (auto constrCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_construtorContext*>(membroCtx)) {
                std::string nomeConstr = constrCtx->IDENTIFICADOR(0)->getText();
                
                std::vector<TipoDado> tiposParam;
                if (constrCtx->parametros()) {
                    for (auto param : constrCtx->parametros()->parametro()) {
                        tiposParam.push_back(stringParaTipo(param->tipo()->getText()));
                    }
                }
                
                // Criar símbolo de construtor
                Simbolo construtor(
                    nomeConstr,
                    TipoDado::CONSTRUTOR,
                    tiposParam,
                    tabela.getNivelAtual()
                );
                construtor.categoria = Categoria::FUNCAO;
                
                membros.push_back(construtor);
            }
        }
        
        // Herdar membros da superclasse se existir
        if (!superClasse.empty()) {
            Simbolo* superSimbolo = tabela.buscarSimbolo(superClasse);
            if (superSimbolo) {
                for (const Simbolo& membroSuper : superSimbolo->membros) {
                    // Não herdar construtores
                    if (membroSuper.tipo != TipoDado::CONSTRUTOR) {
                        membros.push_back(membroSuper);
                    }
                }
            }
        }

        // Armazenar membros no símbolo da classe
        simbolo.membros = membros;
        
        if (!tabela.inserirSimbolo(simbolo)) {
            // Não reportar erro aqui, será verificado na análise semântica
        }
        
        return nullptr;
    }

private:
    // Função auxiliar para converter string para TipoDado
    TipoDado stringParaTipo(const std::string& tipoStr) {
        if (tipoStr == "int") return TipoDado::INT;
        if (tipoStr == "float") return TipoDado::FLOAT;
        if (tipoStr == "char") return TipoDado::CHAR;
        if (tipoStr == "string") return TipoDado::STRING;
        if (tipoStr == "void") return TipoDado::VOID;
        return TipoDado::CLASSE;
    }
};