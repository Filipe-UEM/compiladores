%{
#include <iostream>
#include <string>
#include <cstring>  // Para strlen()

using namespace std;



// Definir constantes para tokens (opcional)
#define TOK_IF 1
#define TOK_ELSE 2
#define TOK_WHILE 3
#define TOK_FUNCAO 4
%}

%option noyywrap


%%

"if"              { cout << "TOKEN: IF" << endl; }
"else"            { cout << "TOKEN: ELSE" << endl; }
"while"           { cout << "TOKEN: WHILE" << endl; }
"for"             { cout << "TOKEN: FOR" << endl; }
"return"          { cout << "TOKEN: RETURN" << endl; }

"int"             { cout << "TOKEN: TIPO_INT" << endl; }
"float"           { cout << "TOKEN: TIPO_FLOAT" << endl; }
"char"            { cout << "TOKEN: TIPO_CHAR" << endl; }
"string"          { cout << "TOKEN: TIPO_STRING" << endl; }
"void"            { cout << "TOKEN: VOID" << endl; }

"=="              { cout << "TOKEN: IGUALDADE" << endl; }
"!="              { cout << "TOKEN: DIFERENTE" << endl; }
">="              { cout << "TOKEN: MAIOR_IGUAL" << endl; }
"<="              { cout << "TOKEN: MENOR_IGUAL" << endl; }
">"               { cout << "TOKEN: MAIOR" << endl; }
"<"               { cout << "TOKEN: MENOR" << endl; }
"="               { cout << "TOKEN: ATRIBUICAO" << endl; }
"&&"              { cout << "TOKEN: E_LOGICO" << endl; }
"||"              { cout << "TOKEN: OU_LOGICO" << endl; }
"!"               { cout << "TOKEN: NEGACAO" << endl; }
"+"               { cout << "TOKEN: SOMA" << endl; }
"-"               { cout << "TOKEN: SUBTRACAO" << endl; }
"*"               { cout << "TOKEN: MULTIPLICACAO" << endl; }
"/"               { cout << "TOKEN: DIVISAO" << endl; }
"."               { cout << "TOKEN: PONTO" << endl; }

";"               { cout << "TOKEN: PONTO_VIRGULA" << endl; }
","               { cout << "TOKEN: VIRGULA" << endl; }
"("               { cout << "TOKEN: ABRE_PARENTESES" << endl; }
")"               { cout << "TOKEN: FECHA_PARENTESES" << endl; }
"{"               { cout << "TOKEN: ABRE_CHAVES" << endl; }
"}"               { cout << "TOKEN: FECHA_CHAVES" << endl; }
"["               { cout << "TOKEN: ABRE_COLCHETES" << endl; }
"]"               { cout << "TOKEN: FECHA_COLCHETES" << endl; }

\"([^\"\n]*)\"    { cout << "TOKEN: STRING_LITERAL (" << yytext << ")" << endl; }
\'.\'             { cout << "TOKEN: CHAR_LITERAL (" << yytext << ")" << endl; }
\'\\n\'           { cout << "TOKEN: CHAR_LITERAL (\\n)" << endl; }
\'\\t\'           { cout << "TOKEN: CHAR_LITERAL (\\t)" << endl; }

[0-9]+\.[0-9]+    { cout << "TOKEN: FLOAT (" << yytext << ")" << endl; }
[0-9]+            { cout << "TOKEN: INT (" << yytext << ")" << endl; }

[a-zA-Z_][a-zA-Z0-9_]*"(" {
    // Reconhecimento de funções
    std::string func_name(yytext, strlen(yytext) - 1);
    cout << "TOKEN: FUNCAO (" << func_name << ")" << endl;
    unput('(');
}

[a-zA-Z_][a-zA-Z0-9_]* {
    cout << "TOKEN: IDENTIFICADOR (" << yytext << ")" << endl;
}

[ \t\r\n]+        { /* ignora espaços */ }

"//".*            { /* Comentário de linha - ignora */ }

"/*"              { 
    // Comentário de bloco
    int c;
    while ((c = yyinput()) != 0) {
        if (c == '*') {
            if ((c = yyinput()) == '/') break;
            else unput(c);
        }
    }
}

.                 { cout << "TOKEN: CARACTERE_NAO_RECONHECIDO (" << yytext << ")" << endl; }

%%

int main() {
    cout << "===== ANALISADOR LÉXICO =====" << endl;
    cout << "Iniciando análise..." << endl;
    yylex();
    cout << "Análise concluída com sucesso!" << endl;
    return 0;
}