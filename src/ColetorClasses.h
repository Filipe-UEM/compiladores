#pragma once

#include "MinhaLinguagemBaseVisitor.h"
#include "TabelaSimbolos.h"

class ColetorClasses : public MinhaLinguagemBaseVisitor {
private:
    TabelaSimbolos& tabela;
    
public:
    ColetorClasses(TabelaSimbolos& tabela) : tabela(tabela) {}

    TipoDado converterParaTipoVetorial(TipoDado base) {
    switch(base) {
        case TipoDado::INT: return TipoDado::VETOR_INT;
        case TipoDado::FLOAT: return TipoDado::VETOR_FLOAT;
        case TipoDado::CHAR: return TipoDado::VETOR_CHAR;
        case TipoDado::STRING: return TipoDado::VETOR_STRING;
        default: return base;
        }
    }
  
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
                
        // Herdar apenas membros não construtores
        if (!superClasse.empty()) {
            Simbolo* superSimbolo = tabela.buscarSimbolo(superClasse);
            if (superSimbolo) {
                for (const Simbolo& membroSuper : superSimbolo->membros) {
                    // Pular construtores na herança
                    if (membroSuper.tipo != TipoDado::CONSTRUTOR) {
                        membros.push_back(membroSuper);
                    }
                }
            }
        }

        for (auto membroCtx : ctx->membro()) {
            // Processar construtores
            if (auto constrCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_construtorContext*>(membroCtx)) {
                std::string nomeConstr = constrCtx->IDENTIFICADOR(0)->getText();
                std::vector<TipoDado> tiposParam;
                
                if (constrCtx->parametros()) {
                    for (auto param : constrCtx->parametros()->parametro()) {
                        tiposParam.push_back(stringParaTipo(param->tipo()->getText()));
                    }
                }
                
                membros.push_back(Simbolo{
                    nomeConstr,
                    TipoDado::CONSTRUTOR,
                    tiposParam,
                    tabela.getNivelAtual()
                });
            }
            // Processar funções
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
            // Processar variáveis
            else if (auto varCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_variavelContext*>(membroCtx)) {
                std::string nomeMembro = varCtx->ID->getText();
                std::string tipoStr = varCtx->tipo()->getText();
                bool isVetor = (varCtx->ABRE_COLCHETES() != nullptr);
                
                TipoDado tipo;
                if (isVetor) {
                    tipo = converterParaTipoVetorial(stringParaTipo(tipoStr));
                } else {
                    tipo = stringParaTipo(tipoStr);
                }
                
                Simbolo s{
                    nomeMembro,
                    tipo,
                    Categoria::VARIAVEL,
                    isVetor,
                    tabela.getNivelAtual()
                };
                
                // Armazenar nome da classe se for tipo classe
                if (tipo == TipoDado::CLASSE) {
                    s.nomeClasse = tipoStr;
                }
                
                membros.push_back(s);
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