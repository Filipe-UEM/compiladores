
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

    virtual std::any visitDeclaracao_funcao(MinhaLinguagemParser::Declaracao_funcaoContext *context) = 0;

    virtual std::any visitParametros(MinhaLinguagemParser::ParametrosContext *context) = 0;

    virtual std::any visitParametro(MinhaLinguagemParser::ParametroContext *context) = 0;

    virtual std::any visitDeclaracao_variavel(MinhaLinguagemParser::Declaracao_variavelContext *context) = 0;

    virtual std::any visitBloco(MinhaLinguagemParser::BlocoContext *context) = 0;

    virtual std::any visitDeclaracao(MinhaLinguagemParser::DeclaracaoContext *context) = 0;

    virtual std::any visitIf(MinhaLinguagemParser::IfContext *context) = 0;

    virtual std::any visitWhile(MinhaLinguagemParser::WhileContext *context) = 0;

    virtual std::any visitFor(MinhaLinguagemParser::ForContext *context) = 0;

    virtual std::any visitVariavel(MinhaLinguagemParser::VariavelContext *context) = 0;

    virtual std::any visitFloat(MinhaLinguagemParser::FloatContext *context) = 0;

    virtual std::any visitNew(MinhaLinguagemParser::NewContext *context) = 0;

    virtual std::any visitBinaria(MinhaLinguagemParser::BinariaContext *context) = 0;

    virtual std::any visitChamadaFuncao(MinhaLinguagemParser::ChamadaFuncaoContext *context) = 0;

    virtual std::any visitGrupo(MinhaLinguagemParser::GrupoContext *context) = 0;

    virtual std::any visitString(MinhaLinguagemParser::StringContext *context) = 0;

    virtual std::any visitAtribuicao(MinhaLinguagemParser::AtribuicaoContext *context) = 0;

    virtual std::any visitAcessoVetor(MinhaLinguagemParser::AcessoVetorContext *context) = 0;

    virtual std::any visitInteiro(MinhaLinguagemParser::InteiroContext *context) = 0;

    virtual std::any visitTipo(MinhaLinguagemParser::TipoContext *context) = 0;


};

