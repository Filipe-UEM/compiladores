
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  MinhaLinguagemParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, PONTO_VIRGULA = 4, VIRGULA = 5, ABRE_PARENTESES = 6, 
    FECHA_PARENTESES = 7, ABRE_CHAVES = 8, FECHA_CHAVES = 9, ATRIBUICAO = 10, 
    ABRE_COLCHETES = 11, FECHA_COLCHETES = 12, PONTO = 13, DOIS_PONTOS = 14, 
    PUBLIC = 15, PRIVATE = 16, PROTECTED = 17, STATIC = 18, STRING_TYPE = 19, 
    OVERRIDE = 20, MAIS = 21, MENOS = 22, MULT = 23, DIV = 24, MAIOR = 25, 
    MAIOR_IGUAL = 26, MENOR = 27, MENOR_IGUAL = 28, IGUAL = 29, DIFERENTE = 30, 
    E_LOGICO = 31, OU_LOGICO = 32, IF = 33, ELSE = 34, WHILE = 35, FOR = 36, 
    CLASS = 37, RETURN = 38, INT = 39, FLOAT = 40, CHAR = 41, STRING = 42, 
    VOID = 43, IDENTIFICADOR = 44, NUM_INT = 45, NUM_FLOAT = 46, TEXTO = 47, 
    COMENTARIO = 48, COMENTARIO_BLOCO = 49, ESPACO = 50, CARACTERE = 51
  };

  enum {
    RulePrograma = 0, RuleDeclaracao_classe = 1, RuleMembro = 2, RuleDeclaracao_construtor = 3, 
    RuleDeclaracao_funcao = 4, RuleParametros = 5, RuleParametro = 6, RuleDeclaracao_variavel = 7, 
    RuleBloco = 8, RuleDeclaracao = 9, RuleEstrutura_controle = 10, RuleExpressao = 11, 
    RuleTipo_base = 12, RuleTipo = 13, RuleAnotacao = 14, RuleFuncaoMain = 15
  };

  explicit MinhaLinguagemParser(antlr4::TokenStream *input);

  MinhaLinguagemParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MinhaLinguagemParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramaContext;
  class Declaracao_classeContext;
  class MembroContext;
  class Declaracao_construtorContext;
  class Declaracao_funcaoContext;
  class ParametrosContext;
  class ParametroContext;
  class Declaracao_variavelContext;
  class BlocoContext;
  class DeclaracaoContext;
  class Estrutura_controleContext;
  class ExpressaoContext;
  class Tipo_baseContext;
  class TipoContext;
  class AnotacaoContext;
  class FuncaoMainContext; 

  class  ProgramaContext : public antlr4::ParserRuleContext {
  public:
    ProgramaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Declaracao_classeContext *> declaracao_classe();
    Declaracao_classeContext* declaracao_classe(size_t i);
    std::vector<Declaracao_funcaoContext *> declaracao_funcao();
    Declaracao_funcaoContext* declaracao_funcao(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramaContext* programa();

  class  Declaracao_classeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *ID = nullptr;
    Declaracao_classeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CLASS();
    antlr4::tree::TerminalNode *ABRE_CHAVES();
    antlr4::tree::TerminalNode *FECHA_CHAVES();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFICADOR();
    antlr4::tree::TerminalNode* IDENTIFICADOR(size_t i);
    antlr4::tree::TerminalNode *STATIC();
    std::vector<MembroContext *> membro();
    MembroContext* membro(size_t i);
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *PROTECTED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaracao_classeContext* declaracao_classe();

  class  MembroContext : public antlr4::ParserRuleContext {
  public:
    MembroContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Declaracao_variavelContext *declaracao_variavel();
    AnotacaoContext *anotacao();
    Declaracao_funcaoContext *declaracao_funcao();
    Declaracao_construtorContext *declaracao_construtor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MembroContext* membro();

  class  Declaracao_construtorContext : public antlr4::ParserRuleContext {
  public:
    Declaracao_construtorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFICADOR();
    antlr4::tree::TerminalNode* IDENTIFICADOR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ABRE_PARENTESES();
    antlr4::tree::TerminalNode* ABRE_PARENTESES(size_t i);
    std::vector<antlr4::tree::TerminalNode *> FECHA_PARENTESES();
    antlr4::tree::TerminalNode* FECHA_PARENTESES(size_t i);
    BlocoContext *bloco();
    ParametrosContext *parametros();
    antlr4::tree::TerminalNode *DOIS_PONTOS();
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *PROTECTED();
    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VIRGULA();
    antlr4::tree::TerminalNode* VIRGULA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaracao_construtorContext* declaracao_construtor();

  class  Declaracao_funcaoContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *ID = nullptr;
    Declaracao_funcaoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TipoContext *tipo();
    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    BlocoContext *bloco();
    antlr4::tree::TerminalNode *IDENTIFICADOR();
    ParametrosContext *parametros();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaracao_funcaoContext* declaracao_funcao();

  class  ParametrosContext : public antlr4::ParserRuleContext {
  public:
    ParametrosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParametroContext *> parametro();
    ParametroContext* parametro(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VIRGULA();
    antlr4::tree::TerminalNode* VIRGULA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametrosContext* parametros();

  class  ParametroContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *ID = nullptr;
    ParametroContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TipoContext *tipo();
    antlr4::tree::TerminalNode *IDENTIFICADOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametroContext* parametro();

  class  Declaracao_variavelContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *ID = nullptr;
    Declaracao_variavelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TipoContext *tipo();
    antlr4::tree::TerminalNode *PONTO_VIRGULA();
    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ABRE_COLCHETES();
    antlr4::tree::TerminalNode *FECHA_COLCHETES();
    antlr4::tree::TerminalNode *ATRIBUICAO();
    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *PRIVATE();
    antlr4::tree::TerminalNode *PROTECTED();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaracao_variavelContext* declaracao_variavel();

  class  BlocoContext : public antlr4::ParserRuleContext {
  public:
    BlocoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABRE_CHAVES();
    antlr4::tree::TerminalNode *FECHA_CHAVES();
    std::vector<DeclaracaoContext *> declaracao();
    DeclaracaoContext* declaracao(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlocoContext* bloco();

  class  DeclaracaoContext : public antlr4::ParserRuleContext {
  public:
    DeclaracaoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DeclaracaoContext() = default;
    void copyFrom(DeclaracaoContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprStmtContext : public DeclaracaoContext {
  public:
    ExprStmtContext(DeclaracaoContext *ctx);

    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *PONTO_VIRGULA();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarDeclContext : public DeclaracaoContext {
  public:
    VarDeclContext(DeclaracaoContext *ctx);

    Declaracao_variavelContext *declaracao_variavel();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStmtContext : public DeclaracaoContext {
  public:
    ReturnStmtContext(DeclaracaoContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *PONTO_VIRGULA();
    ExpressaoContext *expressao();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ControleDeclContext : public DeclaracaoContext {
  public:
    ControleDeclContext(DeclaracaoContext *ctx);

    Estrutura_controleContext *estrutura_controle();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DeclaracaoContext* declaracao();

  class  Estrutura_controleContext : public antlr4::ParserRuleContext {
  public:
    Estrutura_controleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Estrutura_controleContext() = default;
    void copyFrom(Estrutura_controleContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ForContext : public Estrutura_controleContext {
  public:
    ForContext(Estrutura_controleContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    std::vector<antlr4::tree::TerminalNode *> PONTO_VIRGULA();
    antlr4::tree::TerminalNode* PONTO_VIRGULA(size_t i);
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    BlocoContext *bloco();
    Declaracao_variavelContext *declaracao_variavel();
    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileContext : public Estrutura_controleContext {
  public:
    WhileContext(Estrutura_controleContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    BlocoContext *bloco();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfContext : public Estrutura_controleContext {
  public:
    IfContext(Estrutura_controleContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    std::vector<BlocoContext *> bloco();
    BlocoContext* bloco(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Estrutura_controleContext* estrutura_controle();

  class  ExpressaoContext : public antlr4::ParserRuleContext {
  public:
    ExpressaoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressaoContext() = default;
    void copyFrom(ExpressaoContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VariavelContext : public ExpressaoContext {
  public:
    VariavelContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFICADOR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtribuicaoVetorContext : public ExpressaoContext {
  public:
    AtribuicaoVetorContext(ExpressaoContext *ctx);

    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    antlr4::tree::TerminalNode *ABRE_COLCHETES();
    antlr4::tree::TerminalNode *FECHA_COLCHETES();
    antlr4::tree::TerminalNode *ATRIBUICAO();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharLiteralContext : public ExpressaoContext {
  public:
    CharLiteralContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *CARACTERE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ChamadaFuncaoContext : public ExpressaoContext {
  public:
    ChamadaFuncaoContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VIRGULA();
    antlr4::tree::TerminalNode* VIRGULA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewVetorContext : public ExpressaoContext {
  public:
    NewVetorContext(ExpressaoContext *ctx);

    Tipo_baseContext *tipo_base();
    antlr4::tree::TerminalNode *ABRE_COLCHETES();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *FECHA_COLCHETES();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ChamadaMetodoContext : public ExpressaoContext {
  public:
    ChamadaMetodoContext(ExpressaoContext *ctx);

    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    antlr4::tree::TerminalNode *PONTO();
    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    std::vector<antlr4::tree::TerminalNode *> VIRGULA();
    antlr4::tree::TerminalNode* VIRGULA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringContext : public ExpressaoContext {
  public:
    StringContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *TEXTO();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtribuicaoMembroContext : public ExpressaoContext {
  public:
    AtribuicaoMembroContext(ExpressaoContext *ctx);

    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    antlr4::tree::TerminalNode *PONTO();
    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ATRIBUICAO();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatContext : public ExpressaoContext {
  public:
    FloatContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *NUM_FLOAT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewObjetoContext : public ExpressaoContext {
  public:
    NewObjetoContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    std::vector<antlr4::tree::TerminalNode *> VIRGULA();
    antlr4::tree::TerminalNode* VIRGULA(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AcessoMembroContext : public ExpressaoContext {
  public:
    AcessoMembroContext(ExpressaoContext *ctx);

    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *PONTO();
    antlr4::tree::TerminalNode *IDENTIFICADOR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinariaContext : public ExpressaoContext {
  public:
    BinariaContext(ExpressaoContext *ctx);

    antlr4::Token *op = nullptr;
    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MAIS();
    antlr4::tree::TerminalNode *MENOS();
    antlr4::tree::TerminalNode *MAIOR();
    antlr4::tree::TerminalNode *MAIOR_IGUAL();
    antlr4::tree::TerminalNode *MENOR();
    antlr4::tree::TerminalNode *MENOR_IGUAL();
    antlr4::tree::TerminalNode *IGUAL();
    antlr4::tree::TerminalNode *DIFERENTE();
    antlr4::tree::TerminalNode *E_LOGICO();
    antlr4::tree::TerminalNode *OU_LOGICO();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GrupoContext : public ExpressaoContext {
  public:
    GrupoContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtribuicaoContext : public ExpressaoContext {
  public:
    AtribuicaoContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ATRIBUICAO();
    ExpressaoContext *expressao();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AcessoVetorContext : public ExpressaoContext {
  public:
    AcessoVetorContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ABRE_COLCHETES();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *FECHA_COLCHETES();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InteiroContext : public ExpressaoContext {
  public:
    InteiroContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *NUM_INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressaoContext* expressao();
  ExpressaoContext* expressao(int precedence);
  class  Tipo_baseContext : public antlr4::ParserRuleContext {
  public:
    Tipo_baseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *STRING_TYPE();
    antlr4::tree::TerminalNode *IDENTIFICADOR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tipo_baseContext* tipo_base();

  class  TipoContext : public antlr4::ParserRuleContext {
  public:
    TipoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Tipo_baseContext *tipo_base();
    antlr4::tree::TerminalNode *ABRE_COLCHETES();
    antlr4::tree::TerminalNode *FECHA_COLCHETES();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TipoContext* tipo();

  class  AnotacaoContext : public antlr4::ParserRuleContext {
  public:
    AnotacaoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OVERRIDE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AnotacaoContext* anotacao();

  class  FuncaoMainContext : public antlr4::ParserRuleContext {
  public:
    FuncaoMainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    BlocoContext *bloco();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncaoMainContext* funcaoMain();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressaoSempred(ExpressaoContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

