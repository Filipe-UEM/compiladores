
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "MinhaLinguagemParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MinhaLinguagemParser.
 */
class  MinhaLinguagemVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MinhaLinguagemParser.
   */
    virtual std::any visitPrograma(MinhaLinguagemParser::ProgramaContext *context) = 0;

    virtual std::any visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext *context) = 0;

    virtual std::any visitMembro(MinhaLinguagemParser::MembroContext *context) = 0;

    virtual std::any visitDeclaracao_construtor(MinhaLinguagemParser::Declaracao_construtorContext *context) = 0;

    virtual std::any visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *context) = 0;

    virtual std::any visitParametros(MinhaLinguagemParser::ParametrosContext *context) = 0;

    virtual std::any visitParametro(MinhaLinguagemParser::ParametroContext *context) = 0;

    virtual std::any visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *context) = 0;

    virtual std::any visitBloco(MinhaLinguagemParser::BlocoContext *context) = 0;

    virtual std::any visitVarDecl(MinhaLinguagemParser::VarDeclContext *context) = 0;

    virtual std::any visitControleDecl(MinhaLinguagemParser::ControleDeclContext *context) = 0;

    virtual std::any visitExprStmt(MinhaLinguagemParser::ExprStmtContext *context) = 0;

    virtual std::any visitReturnStmt(MinhaLinguagemParser::ReturnStmtContext *context) = 0;

    virtual std::any visitIf(MinhaLinguagemParser::IfContext *context) = 0;

    virtual std::any visitWhile(MinhaLinguagemParser::WhileContext *context) = 0;

    virtual std::any visitFor(MinhaLinguagemParser::ForContext *context) = 0;

    virtual std::any visitVariavel(MinhaLinguagemParser::VariavelContext *context) = 0;

    virtual std::any visitAtribuicaoVetor(MinhaLinguagemParser::AtribuicaoVetorContext *context) = 0;

    virtual std::any visitCharLiteral(MinhaLinguagemParser::CharLiteralContext *context) = 0;

    virtual std::any visitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *context) = 0;

    virtual std::any visitNewVetor(MinhaLinguagemParser::NewVetorContext *context) = 0;

    virtual std::any visitChamadaMetodo(MinhaLinguagemParser::ChamadaMetodoContext *context) = 0;

    virtual std::any visitString(MinhaLinguagemParser::StringContext *context) = 0;

    virtual std::any visitAtribuicaoMembro(MinhaLinguagemParser::AtribuicaoMembroContext *context) = 0;

    virtual std::any visitFloat(MinhaLinguagemParser::FloatContext *context) = 0;

    virtual std::any visitNewObjeto(MinhaLinguagemParser::NewObjetoContext *context) = 0;

    virtual std::any visitAcessoMembro(MinhaLinguagemParser::AcessoMembroContext *context) = 0;

    virtual std::any visitBinaria(MinhaLinguagemParser::BinariaContext *context) = 0;

    virtual std::any visitGrupo(MinhaLinguagemParser::GrupoContext *context) = 0;

    virtual std::any visitAtribuicao(MinhaLinguagemParser::AtribuicaoContext *context) = 0;

    virtual std::any visitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *context) = 0;

    virtual std::any visitInteiro(MinhaLinguagemParser::InteiroContext *context) = 0;

    virtual std::any visitTipo_base(MinhaLinguagemParser::Tipo_baseContext *context) = 0;

    virtual std::any visitTipo(MinhaLinguagemParser::TipoContext *context) = 0;

    virtual std::any visitAnotacao(MinhaLinguagemParser::AnotacaoContext *context) = 0;

    virtual std::any visitFuncaoMain(MinhaLinguagemParser::FuncaoMainContext *context) = 0;


};

