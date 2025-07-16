
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "MinhaLinguagemListener.h"


/**
 * This class provides an empty implementation of MinhaLinguagemListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MinhaLinguagemBaseListener : public MinhaLinguagemListener {
public:

  virtual void enterPrograma(MinhaLinguagemParser::ProgramaContext * /*ctx*/) override { }
  virtual void exitPrograma(MinhaLinguagemParser::ProgramaContext * /*ctx*/) override { }

  virtual void enterDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext * /*ctx*/) override { }
  virtual void exitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext * /*ctx*/) override { }

  virtual void enterMembro(MinhaLinguagemParser::MembroContext * /*ctx*/) override { }
  virtual void exitMembro(MinhaLinguagemParser::MembroContext * /*ctx*/) override { }

  virtual void enterDeclaracao_construtor(MinhaLinguagemParser::Declaracao_construtorContext * /*ctx*/) override { }
  virtual void exitDeclaracao_construtor(MinhaLinguagemParser::Declaracao_construtorContext * /*ctx*/) override { }

  virtual void enterDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext * /*ctx*/) override { }
  virtual void exitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext * /*ctx*/) override { }

  virtual void enterParametros(MinhaLinguagemParser::ParametrosContext * /*ctx*/) override { }
  virtual void exitParametros(MinhaLinguagemParser::ParametrosContext * /*ctx*/) override { }

  virtual void enterParametro(MinhaLinguagemParser::ParametroContext * /*ctx*/) override { }
  virtual void exitParametro(MinhaLinguagemParser::ParametroContext * /*ctx*/) override { }

  virtual void enterDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext * /*ctx*/) override { }
  virtual void exitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext * /*ctx*/) override { }

  virtual void enterBloco(MinhaLinguagemParser::BlocoContext * /*ctx*/) override { }
  virtual void exitBloco(MinhaLinguagemParser::BlocoContext * /*ctx*/) override { }

  virtual void enterVarDecl(MinhaLinguagemParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(MinhaLinguagemParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterControleDecl(MinhaLinguagemParser::ControleDeclContext * /*ctx*/) override { }
  virtual void exitControleDecl(MinhaLinguagemParser::ControleDeclContext * /*ctx*/) override { }

  virtual void enterExprStmt(MinhaLinguagemParser::ExprStmtContext * /*ctx*/) override { }
  virtual void exitExprStmt(MinhaLinguagemParser::ExprStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(MinhaLinguagemParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(MinhaLinguagemParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterIf(MinhaLinguagemParser::IfContext * /*ctx*/) override { }
  virtual void exitIf(MinhaLinguagemParser::IfContext * /*ctx*/) override { }

  virtual void enterWhile(MinhaLinguagemParser::WhileContext * /*ctx*/) override { }
  virtual void exitWhile(MinhaLinguagemParser::WhileContext * /*ctx*/) override { }

  virtual void enterFor(MinhaLinguagemParser::ForContext * /*ctx*/) override { }
  virtual void exitFor(MinhaLinguagemParser::ForContext * /*ctx*/) override { }

  virtual void enterVariavel(MinhaLinguagemParser::VariavelContext * /*ctx*/) override { }
  virtual void exitVariavel(MinhaLinguagemParser::VariavelContext * /*ctx*/) override { }

  virtual void enterAtribuicaoVetor(MinhaLinguagemParser::AtribuicaoVetorContext * /*ctx*/) override { }
  virtual void exitAtribuicaoVetor(MinhaLinguagemParser::AtribuicaoVetorContext * /*ctx*/) override { }

  virtual void enterCharLiteral(MinhaLinguagemParser::CharLiteralContext * /*ctx*/) override { }
  virtual void exitCharLiteral(MinhaLinguagemParser::CharLiteralContext * /*ctx*/) override { }

  virtual void enterChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext * /*ctx*/) override { }
  virtual void exitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext * /*ctx*/) override { }

  virtual void enterNewVetor(MinhaLinguagemParser::NewVetorContext * /*ctx*/) override { }
  virtual void exitNewVetor(MinhaLinguagemParser::NewVetorContext * /*ctx*/) override { }

  virtual void enterChamadaMetodo(MinhaLinguagemParser::ChamadaMetodoContext * /*ctx*/) override { }
  virtual void exitChamadaMetodo(MinhaLinguagemParser::ChamadaMetodoContext * /*ctx*/) override { }

  virtual void enterString(MinhaLinguagemParser::StringContext * /*ctx*/) override { }
  virtual void exitString(MinhaLinguagemParser::StringContext * /*ctx*/) override { }

  virtual void enterAtribuicaoMembro(MinhaLinguagemParser::AtribuicaoMembroContext * /*ctx*/) override { }
  virtual void exitAtribuicaoMembro(MinhaLinguagemParser::AtribuicaoMembroContext * /*ctx*/) override { }

  virtual void enterFloat(MinhaLinguagemParser::FloatContext * /*ctx*/) override { }
  virtual void exitFloat(MinhaLinguagemParser::FloatContext * /*ctx*/) override { }

  virtual void enterNewObjeto(MinhaLinguagemParser::NewObjetoContext * /*ctx*/) override { }
  virtual void exitNewObjeto(MinhaLinguagemParser::NewObjetoContext * /*ctx*/) override { }

  virtual void enterAcessoMembro(MinhaLinguagemParser::AcessoMembroContext * /*ctx*/) override { }
  virtual void exitAcessoMembro(MinhaLinguagemParser::AcessoMembroContext * /*ctx*/) override { }

  virtual void enterBinaria(MinhaLinguagemParser::BinariaContext * /*ctx*/) override { }
  virtual void exitBinaria(MinhaLinguagemParser::BinariaContext * /*ctx*/) override { }

  virtual void enterGrupo(MinhaLinguagemParser::GrupoContext * /*ctx*/) override { }
  virtual void exitGrupo(MinhaLinguagemParser::GrupoContext * /*ctx*/) override { }

  virtual void enterAtribuicao(MinhaLinguagemParser::AtribuicaoContext * /*ctx*/) override { }
  virtual void exitAtribuicao(MinhaLinguagemParser::AtribuicaoContext * /*ctx*/) override { }

  virtual void enterAcessoVetor(MinhaLinguagemParser::AcessoVetorContext * /*ctx*/) override { }
  virtual void exitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext * /*ctx*/) override { }

  virtual void enterInteiro(MinhaLinguagemParser::InteiroContext * /*ctx*/) override { }
  virtual void exitInteiro(MinhaLinguagemParser::InteiroContext * /*ctx*/) override { }

  virtual void enterTipo_base(MinhaLinguagemParser::Tipo_baseContext * /*ctx*/) override { }
  virtual void exitTipo_base(MinhaLinguagemParser::Tipo_baseContext * /*ctx*/) override { }

  virtual void enterTipo(MinhaLinguagemParser::TipoContext * /*ctx*/) override { }
  virtual void exitTipo(MinhaLinguagemParser::TipoContext * /*ctx*/) override { }

  virtual void enterAnotacao(MinhaLinguagemParser::AnotacaoContext * /*ctx*/) override { }
  virtual void exitAnotacao(MinhaLinguagemParser::AnotacaoContext * /*ctx*/) override { }

  virtual void enterFuncaoMain(MinhaLinguagemParser::FuncaoMainContext * /*ctx*/) override { }
  virtual void exitFuncaoMain(MinhaLinguagemParser::FuncaoMainContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

