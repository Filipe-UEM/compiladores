
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "MinhaLinguagemVisitor.h"


/**
 * This class provides an empty implementation of MinhaLinguagemVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MinhaLinguagemBaseVisitor : public MinhaLinguagemVisitor {
public:

  virtual std::any visitPrograma(MinhaLinguagemParser::ProgramaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaracao_classe(MinhaLinguagemParser::Declaracao_classeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMembro(MinhaLinguagemParser::MembroContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaracao_construtor(MinhaLinguagemParser::Declaracao_construtorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParametros(MinhaLinguagemParser::ParametrosContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParametro(MinhaLinguagemParser::ParametroContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBloco(MinhaLinguagemParser::BlocoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(MinhaLinguagemParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitControleDecl(MinhaLinguagemParser::ControleDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(MinhaLinguagemParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(MinhaLinguagemParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf(MinhaLinguagemParser::IfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhile(MinhaLinguagemParser::WhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor(MinhaLinguagemParser::ForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariavel(MinhaLinguagemParser::VariavelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtribuicaoVetor(MinhaLinguagemParser::AtribuicaoVetorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewVetor(MinhaLinguagemParser::NewVetorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChamadaMetodo(MinhaLinguagemParser::ChamadaMetodoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitString(MinhaLinguagemParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtribuicaoMembro(MinhaLinguagemParser::AtribuicaoMembroContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloat(MinhaLinguagemParser::FloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewObjeto(MinhaLinguagemParser::NewObjetoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAcessoMembro(MinhaLinguagemParser::AcessoMembroContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaria(MinhaLinguagemParser::BinariaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGrupo(MinhaLinguagemParser::GrupoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtribuicao(MinhaLinguagemParser::AtribuicaoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInteiro(MinhaLinguagemParser::InteiroContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTipo_base(MinhaLinguagemParser::Tipo_baseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTipo(MinhaLinguagemParser::TipoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnotacao(MinhaLinguagemParser::AnotacaoContext *ctx) override {
    return visitChildren(ctx);
  }


};

