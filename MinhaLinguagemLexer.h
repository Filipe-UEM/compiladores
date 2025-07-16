
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  MinhaLinguagemLexer : public antlr4::Lexer {
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
    COMENTARIO = 48, COMENTARIO_BLOCO = 49, ESPACO = 50
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

