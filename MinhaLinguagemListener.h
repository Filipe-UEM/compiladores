
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "MinhaLinguagemParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MinhaLinguagemParser.
 */
class  MinhaLinguagemListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPrograma(MinhaLinguagemParser::ProgramaContext *ctx) = 0;
  virtual void exitPrograma(MinhaLinguagemParser::ProgramaContext *ctx) = 0;

  virtual void enterDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext *ctx) = 0;
  virtual void exitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext *ctx) = 0;

  virtual void enterMembro(MinhaLinguagemParser::MembroContext *ctx) = 0;
  virtual void exitMembro(MinhaLinguagemParser::MembroContext *ctx) = 0;

  virtual void enterDeclaracao_construtor(MinhaLinguagemParser::Declaracao_construtorContext *ctx) = 0;
  virtual void exitDeclaracao_construtor(MinhaLinguagemParser::Declaracao_construtorContext *ctx) = 0;

  virtual void enterDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *ctx) = 0;
  virtual void exitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *ctx) = 0;

  virtual void enterParametros(MinhaLinguagemParser::ParametrosContext *ctx) = 0;
  virtual void exitParametros(MinhaLinguagemParser::ParametrosContext *ctx) = 0;

  virtual void enterParametro(MinhaLinguagemParser::ParametroContext *ctx) = 0;
  virtual void exitParametro(MinhaLinguagemParser::ParametroContext *ctx) = 0;

  virtual void enterDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *ctx) = 0;
  virtual void exitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *ctx) = 0;

  virtual void enterBloco(MinhaLinguagemParser::BlocoContext *ctx) = 0;
  virtual void exitBloco(MinhaLinguagemParser::BlocoContext *ctx) = 0;

  virtual void enterVarDecl(MinhaLinguagemParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(MinhaLinguagemParser::VarDeclContext *ctx) = 0;

  virtual void enterControleDecl(MinhaLinguagemParser::ControleDeclContext *ctx) = 0;
  virtual void exitControleDecl(MinhaLinguagemParser::ControleDeclContext *ctx) = 0;

  virtual void enterExprStmt(MinhaLinguagemParser::ExprStmtContext *ctx) = 0;
  virtual void exitExprStmt(MinhaLinguagemParser::ExprStmtContext *ctx) = 0;

  virtual void enterReturnStmt(MinhaLinguagemParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(MinhaLinguagemParser::ReturnStmtContext *ctx) = 0;

  virtual void enterIf(MinhaLinguagemParser::IfContext *ctx) = 0;
  virtual void exitIf(MinhaLinguagemParser::IfContext *ctx) = 0;

  virtual void enterWhile(MinhaLinguagemParser::WhileContext *ctx) = 0;
  virtual void exitWhile(MinhaLinguagemParser::WhileContext *ctx) = 0;

  virtual void enterFor(MinhaLinguagemParser::ForContext *ctx) = 0;
  virtual void exitFor(MinhaLinguagemParser::ForContext *ctx) = 0;

  virtual void enterVariavel(MinhaLinguagemParser::VariavelContext *ctx) = 0;
  virtual void exitVariavel(MinhaLinguagemParser::VariavelContext *ctx) = 0;

  virtual void enterAtribuicaoVetor(MinhaLinguagemParser::AtribuicaoVetorContext *ctx) = 0;
  virtual void exitAtribuicaoVetor(MinhaLinguagemParser::AtribuicaoVetorContext *ctx) = 0;

  virtual void enterCharLiteral(MinhaLinguagemParser::CharLiteralContext *ctx) = 0;
  virtual void exitCharLiteral(MinhaLinguagemParser::CharLiteralContext *ctx) = 0;

  virtual void enterChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *ctx) = 0;
  virtual void exitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *ctx) = 0;

  virtual void enterNewVetor(MinhaLinguagemParser::NewVetorContext *ctx) = 0;
  virtual void exitNewVetor(MinhaLinguagemParser::NewVetorContext *ctx) = 0;

  virtual void enterChamadaMetodo(MinhaLinguagemParser::ChamadaMetodoContext *ctx) = 0;
  virtual void exitChamadaMetodo(MinhaLinguagemParser::ChamadaMetodoContext *ctx) = 0;

  virtual void enterString(MinhaLinguagemParser::StringContext *ctx) = 0;
  virtual void exitString(MinhaLinguagemParser::StringContext *ctx) = 0;

  virtual void enterAtribuicaoMembro(MinhaLinguagemParser::AtribuicaoMembroContext *ctx) = 0;
  virtual void exitAtribuicaoMembro(MinhaLinguagemParser::AtribuicaoMembroContext *ctx) = 0;

  virtual void enterFloat(MinhaLinguagemParser::FloatContext *ctx) = 0;
  virtual void exitFloat(MinhaLinguagemParser::FloatContext *ctx) = 0;

  virtual void enterNewObjeto(MinhaLinguagemParser::NewObjetoContext *ctx) = 0;
  virtual void exitNewObjeto(MinhaLinguagemParser::NewObjetoContext *ctx) = 0;

  virtual void enterAcessoMembro(MinhaLinguagemParser::AcessoMembroContext *ctx) = 0;
  virtual void exitAcessoMembro(MinhaLinguagemParser::AcessoMembroContext *ctx) = 0;

  virtual void enterBinaria(MinhaLinguagemParser::BinariaContext *ctx) = 0;
  virtual void exitBinaria(MinhaLinguagemParser::BinariaContext *ctx) = 0;

  virtual void enterGrupo(MinhaLinguagemParser::GrupoContext *ctx) = 0;
  virtual void exitGrupo(MinhaLinguagemParser::GrupoContext *ctx) = 0;

  virtual void enterAtribuicao(MinhaLinguagemParser::AtribuicaoContext *ctx) = 0;
  virtual void exitAtribuicao(MinhaLinguagemParser::AtribuicaoContext *ctx) = 0;

  virtual void enterAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *ctx) = 0;
  virtual void exitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *ctx) = 0;

  virtual void enterInteiro(MinhaLinguagemParser::InteiroContext *ctx) = 0;
  virtual void exitInteiro(MinhaLinguagemParser::InteiroContext *ctx) = 0;

  virtual void enterTipo_base(MinhaLinguagemParser::Tipo_baseContext *ctx) = 0;
  virtual void exitTipo_base(MinhaLinguagemParser::Tipo_baseContext *ctx) = 0;

  virtual void enterTipo(MinhaLinguagemParser::TipoContext *ctx) = 0;
  virtual void exitTipo(MinhaLinguagemParser::TipoContext *ctx) = 0;

  virtual void enterAnotacao(MinhaLinguagemParser::AnotacaoContext *ctx) = 0;
  virtual void exitAnotacao(MinhaLinguagemParser::AnotacaoContext *ctx) = 0;

  virtual void enterFuncaoMain(MinhaLinguagemParser::FuncaoMainContext *ctx) = 0;
  virtual void exitFuncaoMain(MinhaLinguagemParser::FuncaoMainContext *ctx) = 0;


};

