
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  MinhaLinguagemLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, PONTO_VIRGULA = 3, VIRGULA = 4, ABRE_PARENTESES = 5, 
    FECHA_PARENTESES = 6, ABRE_CHAVES = 7, FECHA_CHAVES = 8, ATRIBUICAO = 9, 
    ABRE_COLCHETES = 10, FECHA_COLCHETES = 11, PONTO = 12, DOIS_PONTOS = 13, 
    PUBLIC = 14, PRIVATE = 15, PROTECTED = 16, STATIC = 17, STRING_TYPE = 18, 
    OVERRIDE = 19, MAIS = 20, MENOS = 21, MULT = 22, DIV = 23, MAIOR = 24, 
    MAIOR_IGUAL = 25, MENOR = 26, MENOR_IGUAL = 27, IGUAL = 28, DIFERENTE = 29, 
    E_LOGICO = 30, OU_LOGICO = 31, IF = 32, ELSE = 33, WHILE = 34, FOR = 35, 
    CLASS = 36, RETURN = 37, INT = 38, FLOAT = 39, CHAR = 40, STRING = 41, 
    VOID = 42, IDENTIFICADOR = 43, NUM_INT = 44, NUM_FLOAT = 45, TEXTO = 46, 
    COMENTARIO = 47, COMENTARIO_BLOCO = 48, ESPACO = 49
  };

  explicit MinhaLinguagemLexer(antlr4::CharStream *input);

  ~MinhaLinguagemLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

