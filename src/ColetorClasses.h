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
        return nullptr;
    }
    
    std::string nomeClasse = ctx->ID->getText();
    std::string superClasse = "";
    
    if (ctx->IDENTIFICADOR().size() > 1) {
        superClasse = ctx->IDENTIFICADOR(1)->getText();
    }
    
    Simbolo simbolo;
    simbolo.nome = nomeClasse;
    simbolo.tipo = TipoDado::CLASSE;
    simbolo.categoria = Categoria::CLASSE;
    simbolo.nivelEscopo = tabela.getNivelAtual();
    simbolo.nomeSuperClasse = superClasse;
    
    // Coletar membros
    std::vector<Simbolo> membros;
    
    for (auto membroCtx : ctx->membro()) {
        if (auto varCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_variavelContext*>(membroCtx)) {
    std::string nomeMembro = varCtx->ID->getText();
    std::string tipoStr = varCtx->tipo()->getText();
    bool isVetor = (varCtx->ABRE_COLCHETES() != nullptr);
    
    TipoDado tipo = stringParaTipo(tipoStr);
    if (isVetor) {
        if (tipo == TipoDado::INT) tipo = TipoDado::VETOR_INT;
        else if (tipo == TipoDado::FLOAT) tipo = TipoDado::VETOR_FLOAT;
        else if (tipo == TipoDado::CHAR) tipo = TipoDado::VETOR_CHAR;
        else if (tipo == TipoDado::STRING) tipo = TipoDado::VETOR_STRING;
    }
    
    Simbolo membroSimbolo{
        nomeMembro,
        tipo,
        Categoria::VARIAVEL,
        isVetor,
        tabela.getNivelAtual()
    };
    membroSimbolo.nomeClasse = nomeClasse;
    membros.push_back(membroSimbolo);
}
        else if (auto constrCtx = dynamic_cast<MinhaLinguagemParser::Declaracao_construtorContext*>(membroCtx)) {
            std::string nomeConstr = constrCtx->IDENTIFICADOR(0)->getText();
            
            std::vector<TipoDado> tiposParam;
            if (constrCtx->parametros()) {
                for (auto param : constrCtx->parametros()->parametro()) {
                    tiposParam.push_back(stringParaTipo(param->tipo()->getText()));
                }
            }
            
            Simbolo construtor(
                nomeConstr,
                TipoDado::CONSTRUTOR,
                tiposParam,
                tabela.getNivelAtual()
            );
            construtor.categoria = Categoria::FUNCAO;
            construtor.nomeClasse = nomeClasse; // Adicione esta linha
            
            membros.push_back(construtor);
        }
    }
    
    // Processar herança
    if (!superClasse.empty()) {
        Simbolo* superSimbolo = tabela.buscarSimbolo(superClasse);
        if (superSimbolo) {
            for (const Simbolo& membroSuper : superSimbolo->membros) {
                if (membroSuper.tipo != TipoDado::CONSTRUTOR) {
                    membros.push_back(membroSuper);
                }
            }
        }
    }

    simbolo.membros = membros;
    tabela.inserirSimbolo(simbolo);
    
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