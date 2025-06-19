
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  MinhaLinguagemParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, PONTO_VIRGULA = 2, VIRGULA = 3, ABRE_PARENTESES = 4, FECHA_PARENTESES = 5, 
    ABRE_CHAVES = 6, FECHA_CHAVES = 7, ATRIBUICAO = 8, ABRE_COLCHETES = 9, 
    FECHA_COLCHETES = 10, MAIS = 11, MENOS = 12, MULT = 13, DIV = 14, MAIOR = 15, 
    MAIOR_IGUAL = 16, MENOR = 17, MENOR_IGUAL = 18, IGUAL = 19, DIFERENTE = 20, 
    E_LOGICO = 21, OU_LOGICO = 22, IF = 23, ELSE = 24, WHILE = 25, FOR = 26, 
    CLASS = 27, RETURN = 28, INT = 29, FLOAT = 30, CHAR = 31, STRING = 32, 
    VOID = 33, IDENTIFICADOR = 34, NUM_INT = 35, NUM_FLOAT = 36, TEXTO = 37, 
    COMENTARIO = 38, COMENTARIO_BLOCO = 39, ESPACO = 40
  };

  enum {
    RulePrograma = 0, RuleDeclaracao_classe = 1, RuleMembro = 2, RuleDeclaracao_funcao = 3, 
    RuleParametros = 4, RuleParametro = 5, RuleDeclaracao_variavel = 6, 
    RuleBloco = 7, RuleDeclaracao = 8, RuleEstrutura_controle = 9, RuleExpressao = 10, 
    RuleTipo = 11
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
  class Declaracao_funcaoContext;
  class ParametrosContext;
  class ParametroContext;
  class Declaracao_variavelContext;
  class BlocoContext;
  class DeclaracaoContext;
  class Estrutura_controleContext;
  class ExpressaoContext;
  class TipoContext; 

  class  ProgramaContext : public antlr4::ParserRuleContext {
  public:
    ProgramaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<Declaracao_classeContext *> declaracao_classe();
    Declaracao_classeContext* declaracao_classe(size_t i);
    std::vector<Declaracao_funcaoContext *> declaracao_funcao();
    Declaracao_funcaoContext* declaracao_funcao(size_t i);


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
    antlr4::tree::TerminalNode *IDENTIFICADOR();
    std::vector<MembroContext *> membro();
    MembroContext* membro(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Declaracao_classeContext* declaracao_classe();

  class  MembroContext : public antlr4::ParserRuleContext {
  public:
    MembroContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Declaracao_variavelContext *declaracao_variavel();
    Declaracao_funcaoContext *declaracao_funcao();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MembroContext* membro();

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


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlocoContext* bloco();

  class  DeclaracaoContext : public antlr4::ParserRuleContext {
  public:
    DeclaracaoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Declaracao_variavelContext *declaracao_variavel();
    Estrutura_controleContext *estrutura_controle();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *PONTO_VIRGULA();
    antlr4::tree::TerminalNode *RETURN();


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
    Declaracao_variavelContext *declaracao_variavel();
    std::vector<ExpressaoContext *> expressao();
    ExpressaoContext* expressao(size_t i);
    antlr4::tree::TerminalNode *PONTO_VIRGULA();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();
    BlocoContext *bloco();

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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatContext : public ExpressaoContext {
  public:
    FloatContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *NUM_FLOAT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewContext : public ExpressaoContext {
  public:
    NewContext(ExpressaoContext *ctx);

    TipoContext *tipo();
    antlr4::tree::TerminalNode *ABRE_COLCHETES();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *FECHA_COLCHETES();

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

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GrupoContext : public ExpressaoContext {
  public:
    GrupoContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *ABRE_PARENTESES();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *FECHA_PARENTESES();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringContext : public ExpressaoContext {
  public:
    StringContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *TEXTO();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtribuicaoContext : public ExpressaoContext {
  public:
    AtribuicaoContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ATRIBUICAO();
    ExpressaoContext *expressao();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AcessoVetorContext : public ExpressaoContext {
  public:
    AcessoVetorContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFICADOR();
    antlr4::tree::TerminalNode *ABRE_COLCHETES();
    ExpressaoContext *expressao();
    antlr4::tree::TerminalNode *FECHA_COLCHETES();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InteiroContext : public ExpressaoContext {
  public:
    InteiroContext(ExpressaoContext *ctx);

    antlr4::tree::TerminalNode *NUM_INT();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressaoContext* expressao();
  ExpressaoContext* expressao(int precedence);
  class  TipoContext : public antlr4::ParserRuleContext {
  public:
    TipoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *ABRE_COLCHETES();
    antlr4::tree::TerminalNode *FECHA_COLCHETES();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *VOID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TipoContext* tipo();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressaoSempred(ExpressaoContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

