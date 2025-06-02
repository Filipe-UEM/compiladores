#pragma once

#include <string>

// Tipos de tokens
enum TokenType {
    // Palavras-chave
    TOK_INT, TOK_FLOAT, TOK_CHAR, TOK_STRING,
    TOK_IF, TOK_ELSE, TOK_FOR, TOK_WHILE,
    TOK_CLASS, TOK_RETURN, TOK_PRINT,
    
    // Símbolos
    TOK_ABRE_COLCHETE, TOK_FECHA_COLCHETE,
    TOK_ATRIBUICAO, TOK_MAIOR, TOK_MENOR,
    TOK_PONTO, TOK_PONTO_VIRGULA,
    TOK_ABRE_PARENTESES, TOK_FECHA_PARENTESES,
    TOK_ABRE_CHAVE, TOK_FECHA_CHAVE, TOK_VIRGULA,
    TOK_MAIS, TOK_MENOS, TOK_MULT, TOK_DIV,
    
    // Literais e identificadores
    TOK_ID, TOK_INT_LIT, TOK_FLOAT_LIT,
    TOK_CHAR_LIT, TOK_STRING_LIT,
    
    // Especiais
    TOK_ERRO, TOK_EOF
};

// Estrutura para valores dos tokens
union YYSTYPE {
    int int_val;
    float float_val;
    char char_val;
    std::string* str_val;
};

extern YYSTYPE yylval;