%{
#include <cstdlib>
#include <string>
#include <iostream>
#include "tokens.h"

using namespace std;

extern YYSTYPE yylval;
%}

%option noyywrap
%option noinput
%option nounput

%x COMMENT

%%

"int"             { cout << "TOK_INT\n"; return TOK_INT; }
"float"           { cout << "TOK_FLOAT\n"; return TOK_FLOAT; }
"char"            { cout << "TOK_CHAR\n"; return TOK_CHAR; }
"string"          { cout << "TOK_STRING\n"; return TOK_STRING; }
"void"            { cout << "TOK_VOID\n"; return TOK_VOID; }
"if"              { cout << "TOK_IF\n"; return TOK_IF; }
"else"            { cout << "TOK_ELSE\n"; return TOK_ELSE; }
"for"             { cout << "TOK_FOR\n"; return TOK_FOR; }
"while"           { cout << "TOK_WHILE\n"; return TOK_WHILE; }
"return"          { cout << "TOK_RETURN\n"; return TOK_RETURN; }
"class"           { cout << "TOK_CLASS\n"; return TOK_CLASS; }
"new"             { cout << "TOK_NEW\n"; return TOK_NEW; }
"this"            { cout << "TOK_THIS\n"; return TOK_THIS; }
"static"          { cout << "TOK_STATIC\n"; return TOK_STATIC; }
"public"          { cout << "TOK_PUBLIC\n"; return TOK_PUBLIC; }
"private"         { cout << "TOK_PRIVATE\n"; return TOK_PRIVATE; }
"main"            { cout << "TOK_MAIN\n"; return TOK_MAIN; }

"=="              { cout << "TOK_IGUALDADE\n"; return TOK_IGUALDADE; }
"!="              { cout << "TOK_DIFERENTE\n"; return TOK_DIFERENTE; }
">="              { cout << "TOK_MAIOR_IGUAL\n"; return TOK_MAIOR_IGUAL; }
"<="              { cout << "TOK_MENOR_IGUAL\n"; return TOK_MENOR_IGUAL; }
">"               { cout << "TOK_MAIOR\n"; return TOK_MAIOR; }
"<"               { cout << "TOK_MENOR\n"; return TOK_MENOR; }
"="               { cout << "TOK_ATRIBUICAO\n"; return TOK_ATRIBUICAO; }
"&&"              { cout << "TOK_E_LOGICO\n"; return TOK_E_LOGICO; }
"||"              { cout << "TOK_OU_LOGICO\n"; return TOK_OU_LOGICO; }
"!"               { cout << "TOK_NEGACAO\n"; return TOK_NEGACAO; }
"+"               { cout << "TOK_MAIS\n"; return TOK_MAIS; }
"-"               { cout << "TOK_MENOS\n"; return TOK_MENOS; }
"*"               { cout << "TOK_MULT\n"; return TOK_MULT; }
"/"               { cout << "TOK_DIV\n"; return TOK_DIV; }
"."               { cout << "TOK_PONTO\n"; return TOK_PONTO; }

";"               { cout << "TOK_PONTO_VIRGULA\n"; return TOK_PONTO_VIRGULA; }
","               { cout << "TOK_VIRGULA\n"; return TOK_VIRGULA; }
"("               { cout << "TOK_ABRE_PARENTESES\n"; return TOK_ABRE_PARENTESES; }
")"               { cout << "TOK_FECHA_PARENTESES\n"; return TOK_FECHA_PARENTESES; }
"{"               { cout << "TOK_ABRE_CHAVE\n"; return TOK_ABRE_CHAVE; }
"}"               { cout << "TOK_FECHA_CHAVE\n"; return TOK_FECHA_CHAVE; }
"["               { cout << "TOK_ABRE_COLCHETE\n"; return TOK_ABRE_COLCHETE; }
"]"               { cout << "TOK_FECHA_COLCHETE\n"; return TOK_FECHA_COLCHETE; }

\"(\\.|[^\\"])*\" { 
    string text(yytext);
    string content = text.substr(1, text.size() - 2);
    yylval.str_val = new string(content);
    cout << "TOK_STRING_LIT: " << content << "\n"; 
    return TOK_STRING_LIT; 
}

\'.\'             { 
    yylval.char_val = yytext[1]; 
    cout << "TOK_CHAR_LIT: '" << yytext[1] << "'\n"; 
    return TOK_CHAR_LIT; 
}

\'\\n\'           { 
    yylval.char_val = '\n'; 
    cout << "TOK_CHAR_LIT: '\\n'\n"; 
    return TOK_CHAR_LIT; 
}

\'\\t\'           { 
    yylval.char_val = '\t'; 
    cout << "TOK_CHAR_LIT: '\\t'\n"; 
    return TOK_CHAR_LIT; 
}

[0-9]+\.[0-9]+    { 
    yylval.float_val = atof(yytext); 
    cout << "TOK_FLOAT_LIT: " << yytext << "\n"; 
    return TOK_FLOAT_LIT; 
}

[0-9]+            { 
    yylval.int_val = atoi(yytext); 
    cout << "TOK_INT_LIT: " << yytext << "\n"; 
    return TOK_INT_LIT; 
}

[a-zA-Z_][a-zA-Z0-9_]* { 
    yylval.str_val = new string(yytext); 
    cout << "TOK_ID: " << yytext << "\n"; 
    return TOK_ID; 
}

[ \t\r\n]+        { /* ignora espaços */ }

"//"[^\n]*        { /* Comentário de linha - ignora */ }

"/*"              { 
    cout << "INICIO_COMENTARIO_BLOCO\n";
    BEGIN(COMMENT); 
}
<COMMENT>{
    "*/"          { 
        cout << "FIM_COMENTARIO_BLOCO\n";
        BEGIN(INITIAL); 
    }
    [^*]+         { /* Consome qualquer coisa que não seja '*' */ }
    "*"           { /* Consome '*' isolado */ }
    <<EOF>>       { 
        cerr << "ERRO: Comentário de bloco não fechado\n"; 
        return TOK_ERRO; 
    }
}

.                 { 
    cout << "TOK_ERRO: '" << yytext << "'\n"; 
    return TOK_ERRO; 
}

%%

int main() {
    cout << "===== ANALISADOR LÉXICO INICIADO =====" << endl;
    while (int token = yylex()) {
        // Processa todos os tokens até EOF (token 0)
    }
    cout << "===== ANÁLISE LÉXICA CONCLUÍDA =====" << endl;
    return 0;
}