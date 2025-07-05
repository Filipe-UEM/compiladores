#ifndef SEMANTIC_VISITOR_H
#define SEMANTIC_VISITOR_H

#include "MinhaLinguagemBaseVisitor.h"
#include "SymbolTable.h"
#include "MinhaLinguagemParser.h"
#include <string>
#include <vector>

class SemanticVisitor : public MinhaLinguagemBaseVisitor {
private:
    SymbolTable symbolTable;
    std::string currentFunctionType = "void";
    bool inFunction = false;
    bool inLoop = false;

    // Métodos auxiliares
    void checkTypeCompatibility(const std::string& expected, const std::string& actual, const std::string& context);
    std::string getExpressionType(MinhaLinguagemParser::ExpressaoContext *ctx);

public:
    // Visitas para declarações
    antlrcpp::Any visitPrograma(MinhaLinguagemParser::ProgramaContext *ctx) override;
    antlrcpp::Any visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext *ctx) override;
    antlrcpp::Any visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *ctx) override;
    antlrcpp::Any visitParametros(MinhaLinguagemParser::ParametrosContext *ctx) override;
    antlrcpp::Any visitParametro(MinhaLinguagemParser::ParametroContext *ctx) override;
    antlrcpp::Any visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *ctx) override;
    antlrcpp::Any visitBloco(MinhaLinguagemParser::BlocoContext *ctx) override;
    
    // Visitas para estruturas de controle
    antlrcpp::Any visitIf(MinhaLinguagemParser::IfContext *ctx) override;
    antlrcpp::Any visitWhile(MinhaLinguagemParser::WhileContext *ctx) override;
    antlrcpp::Any visitFor(MinhaLinguagemParser::ForContext *ctx) override;
    
    // Visitas para expressões
    antlrcpp::Any visitAtribuicao(MinhaLinguagemParser::AtribuicaoContext *ctx) override;
    antlrcpp::Any visitBinaria(MinhaLinguagemParser::BinariaContext *ctx) override;
    antlrcpp::Any visitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *ctx) override;
    antlrcpp::Any visitReturnStat(MinhaLinguagemParser::ReturnStatContext *ctx) override;
    antlrcpp::Any visitNew(MinhaLinguagemParser::NewContext *ctx) override;
    antlrcpp::Any visitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *ctx) override;
    
    // Visitas para tipos de expressões
    antlrcpp::Any visitInteiro(MinhaLinguagemParser::InteiroContext *ctx) override;
    antlrcpp::Any visitFloat(MinhaLinguagemParser::FloatContext *ctx) override;
    antlrcpp::Any visitString(MinhaLinguagemParser::StringContext *ctx) override;
    antlrcpp::Any visitVariavel(MinhaLinguagemParser::VariavelContext *ctx) override;

    antlrcpp::Any visitAtribuicaoArray(MinhaLinguagemParser::AtribuicaoArrayContext *ctx) override;
};

#endif