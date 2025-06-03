%{
#include <iostream>
using namespace std;

// Protótipo da função yywrap


%}

%%

"int"             { cout << "TOKEN: TIPO_INT" << endl; }
"float"           { cout << "TOKEN: TIPO_FLOAT" << endl; }
"char"            { cout << "TOKEN: TIPO_CHAR" << endl; }
"string"          { cout << "TOKEN: TIPO_STRING" << endl; }
"void"            { cout << "TOKEN: VOID" << endl; }
"if"              { cout << "TOKEN: IF" << endl; }
"else"            { cout << "TOKEN: ELSE" << endl; }
"for"             { cout << "TOKEN: FOR" << endl; }
"while"           { cout << "TOKEN: WHILE" << endl; }
"return"          { cout << "TOKEN: RETURN" << endl; }
"class"           { cout << "TOKEN: CLASS" << endl; }
"new"             { cout << "TOKEN: NEW" << endl; }
"this"            { cout << "TOKEN: THIS" << endl; }
"static"          { cout << "TOKEN: STATIC" << endl; }
"public"          { cout << "TOKEN: PUBLIC" << endl; }
"private"         { cout << "TOKEN: PRIVATE" << endl; }
"main"            { cout << "TOKEN: MAIN" << endl; }

"=="            { cout << "TOKEN: IGUALDADE" << endl; }
"!="            { cout << "TOKEN: DIFERENTE" << endl; }
">="            { cout << "TOKEN: MAIOR_IGUAL" << endl; }
"<="            { cout << "TOKEN: MENOR_IGUAL" << endl; }
">"             { cout << "TOKEN: MAIOR" << endl; }
"<"             { cout << "TOKEN: MENOR" << endl; }
"="             { cout << "TOKEN: ATRIBUICAO" << endl; }
"&&"            { cout << "TOKEN: E_LOGICO" << endl; }
"||"            { cout << "TOKEN: OU_LOGICO" << endl; }
"!"             { cout << "TOKEN: NEGACAO" << endl; }
"+"             { cout << "TOKEN: SOMA" << endl; }
"-"             { cout << "TOKEN: SUBTRACAO" << endl; }
"*"             { cout << "TOKEN: MULTIPLICACAO" << endl; }
"/"             { cout << "TOKEN: DIVISAO" << endl; }
"."             { cout << "TOKEN: PONTO" << endl; }  // Para chamadas de método

";"             { cout << "TOKEN: PONTO_VIRGULA" << endl; }
","             { cout << "TOKEN: VIRGULA" << endl; }
"("             { cout << "TOKEN: ABRE_PARENTESES" << endl; }
")"             { cout << "TOKEN: FECHA_PARENTESES" << endl; }
"{"             { cout << "TOKEN: ABRE_CHAVES" << endl; }
"}"             { cout << "TOKEN: FECHA_CHAVES" << endl; }
"["             { cout << "TOKEN: ABRE_COLCHETES" << endl; }
"]"             { cout << "TOKEN: FECHA_COLCHETES" << endl; }

\"([^\"\n]*)\"  { cout << "TOKEN: STRING_LITERAL (" << yytext << ")" << endl; }
\'.\'           { cout << "TOKEN: CHAR_LITERAL (" << yytext << ")" << endl; }
\'\\n\'         { cout << "TOKEN: CHAR_LITERAL (\\n)" << endl; }
\'\\t\'         { cout << "TOKEN: CHAR_LITERAL (\\t)" << endl; }

[0-9]+\.[0-9]+  { cout << "TOKEN: FLOAT (" << yytext << ")" << endl; }
[0-9]+          { cout << "TOKEN: INT (" << yytext << ")" << endl; }

[a-zA-Z_][a-zA-Z0-9_]* {
    cout << "TOKEN: IDENTIFICADOR (" << yytext << ")" << endl;
}

[ \t\r\n]+      { /* ignora espaços */ }

"//".*          { /* Comentário de linha - ignora */ }

"/*"            { 
    int c;
    while ((c = yyinput()) != 0) {
        if (c == '*') {
            if ((c = yyinput()) == '/') break;
            else unput(c);
        }
    }
}

.               { cout << "TOKEN: CARACTERE_NAO_RECONHECIDO (" << yytext << ")" << endl; }

%%

int yywrap() { return 1; }
