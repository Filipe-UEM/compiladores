
// Generated from MinhaLinguagem.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  MinhaLinguagemLexer : public antlr4::Lexer {
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

