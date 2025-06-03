%{
#include <iostream>
using namespace std;

void yyerror(const char *s);
int yylex();
%}

/* Definindo os tokens (vindos do Flex) */
%token TIPO_INT TIPO_FLOAT TIPO_CHAR TIPO_STRING VOID
%token IF ELSE FOR WHILE RETURN
%token CLASS NEW THIS STATIC PUBLIC PRIVATE MAIN
%token IGUALDADE DIFERENTE MAIOR_IGUAL MENOR_IGUAL MAIOR MENOR
%token ATRIBUICAO E_LOGICO OU_LOGICO NEGACAO
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO PONTO
%token PONTO_VIRGULA VIRGULA ABRE_PARENTESES FECHA_PARENTESES
%token ABRE_CHAVES FECHA_CHAVES ABRE_COLCHETES FECHA_COLCHETES
%token STRING_LITERAL CHAR_LITERAL
%token INT FLOAT
%token IDENTIFICADOR

%%

/* 📜 As regras da linguagem começam aqui */

programa:
      declaracoes
    ;

declaracoes:
      declaracoes declaracao
    | declaracao
    ;

declaracao:
      declaracao_variavel
    | declaracao_funcao
    ;

declaracao_variavel:
      tipo IDENTIFICADOR PONTO_VIRGULA
    | tipo IDENTIFICADOR ABRE_COLCHETES INT FECHA_COLCHETES PONTO_VIRGULA
    ;

tipo:
      TIPO_INT
    | TIPO_FLOAT
    | TIPO_CHAR
    | TIPO_STRING
    | VOID
    ;

declaracao_funcao:
      tipo IDENTIFICADOR ABRE_PARENTESES FECHA_PARENTESES bloco
    ;

bloco:
      ABRE_CHAVES comandos FECHA_CHAVES
    ;

comandos:
      comandos comando
    | comando
    ;

comando:
      declaracao_variavel
    | estrutura_if
    | estrutura_while
    | estrutura_for
    | RETURN expressao PONTO_VIRGULA
    | chamada_funcao PONTO_VIRGULA
    | bloco
    ;

estrutura_if:
      IF ABRE_PARENTESES expressao FECHA_PARENTESES comando
    | IF ABRE_PARENTESES expressao FECHA_PARENTESES comando ELSE comando
    ;

estrutura_while:
      WHILE ABRE_PARENTESES expressao FECHA_PARENTESES comando
    ;

estrutura_for:
      FOR ABRE_PARENTESES declaracao_variavel expressao PONTO_VIRGULA expressao FECHA_PARENTESES comando
    ;

chamada_funcao:
      IDENTIFICADOR ABRE_PARENTESES FECHA_PARENTESES
    ;

expressao:
      expressao SOMA expressao
    | expressao SUBTRACAO expressao
    | expressao MULTIPLICACAO expressao
    | expressao DIVISAO expressao
    | expressao IGUALDADE expressao
    | expressao DIFERENTE expressao
    | expressao MAIOR expressao
    | expressao MENOR expressao
    | expressao MAIOR_IGUAL expressao
    | expressao MENOR_IGUAL expressao
    | expressao E_LOGICO expressao
    | expressao OU_LOGICO expressao
    | IDENTIFICADOR
    | INT
    | FLOAT
    | STRING_LITERAL
    | CHAR_LITERAL
    | ABRE_PARENTESES expressao FECHA_PARENTESES
    ;

%%

void yyerror(const char *s) {
    cout << "Erro sintático: " << s << endl;
}

int main() {
    cout << "Iniciando análise sintática..." << endl;
    yyparse();
    cout << "Análise sintática concluída." << endl;
    return 0;
}
