%{
#include "ast.h"
#include <memory>
#include <cstdio>

extern int yylex();
extern FILE* yyin;
void yyerror(const char* s);

std::unique_ptr<ProgramNode> programRoot = std::make_unique<ProgramNode>();
%}

%require "3.2"
%define api.value.type {std::unique_ptr<ASTNode>}
%define parse.error verbose

%token TOK_INT TOK_FLOAT TOK_CHAR TOK_STRING TOK_VOID
%token TOK_IF TOK_ELSE TOK_FOR TOK_WHILE TOK_RETURN
%token TOK_CLASS TOK_NEW TOK_THIS TOK_STATIC TOK_PUBLIC TOK_PRIVATE TOK_MAIN
%token TOK_ABRE_COLCHETE TOK_FECHA_COLCHETE
%token TOK_ATRIBUICAO TOK_MAIOR TOK_MENOR
%token TOK_MAIOR_IGUAL TOK_MENOR_IGUAL TOK_IGUALDADE TOK_DIFERENTE
%token TOK_E_LOGICO TOK_OU_LOGICO TOK_NEGACAO
%token TOK_PONTO TOK_PONTO_VIRGULA TOK_VIRGULA
%token TOK_ABRE_PARENTESES TOK_FECHA_PARENTESES
%token TOK_ABRE_CHAVE TOK_FECHA_CHAVE
%token TOK_MAIS TOK_MENOS TOK_MULT TOK_DIV
%token TOK_ID TOK_INT_LIT TOK_FLOAT_LIT TOK_CHAR_LIT TOK_STRING_LIT
%token TOK_ERRO TOK_EOF

%type <std::unique_ptr<ASTNode>> program class_decl function_decl variable_decl
%type <std::unique_ptr<ASTNode>> class_member statements statement expression_statement
%type <std::unique_ptr<ASTNode>> if_statement while_statement return_statement
%type <std::unique_ptr<ASTNode>> expression assignment logical_or logical_and
%type <std::unique_ptr<ASTNode>> equality comparison term factor unary primary
%type <std::string> type identifier

%start program

%%

program
    : class_decl {
        programRoot->addDeclaration(std::move($1));
    }
    | function_decl {
        programRoot->addDeclaration(std::move($1));
    }
    | program class_decl {
        programRoot->addDeclaration(std::move($2));
    }
    | program function_decl {
        programRoot->addDeclaration(std::move($2));
    }
    ;

class_decl
    : TOK_CLASS identifier TOK_ABRE_CHAVE class_members TOK_FECHA_CHAVE {
        $$ = std::make_unique<ClassNode>($2);
    }
    ;

class_members
    : /* vazio */
    | class_members class_member
    ;

class_member
    : function_decl
    | variable_decl
    ;

function_decl
    : type identifier TOK_ABRE_PARENTESES TOK_FECHA_PARENTESES 
      TOK_ABRE_CHAVE statements TOK_FECHA_CHAVE {
        $$ = std::make_unique<FunctionNode>($2);
    }
    ;

variable_decl
    : type identifier TOK_PONTO_VIRGULA {
        $$ = std::make_unique<VariableDeclNode>($1, $2);
    }
    | type identifier TOK_ATRIBUICAO expression TOK_PONTO_VIRGULA {
        $$ = std::make_unique<VariableDeclNode>($1, $2, std::move($4));
    }
    ;

statements
    : /* vazio */ { $$ = nullptr; }
    | statements statement { $$ = std::move($2); }
    ;

statement
    : variable_decl { $$ = std::move($1); }
    | expression_statement { $$ = std::move($1); }
    | if_statement { $$ = std::move($1); }
    | while_statement { $$ = std::move($1); }
    | return_statement { $$ = std::move($1); }
    ;

expression_statement
    : expression TOK_PONTO_VIRGULA { $$ = std::move($1); }
    ;

if_statement
    : TOK_IF TOK_ABRE_PARENTESES expression TOK_FECHA_PARENTESES 
      statement {
        $$ = std::make_unique<IfNode>(std::move($3), std::move($5), nullptr);
    }
    | TOK_IF TOK_ABRE_PARENTESES expression TOK_FECHA_PARENTESES 
      statement TOK_ELSE statement {
        $$ = std::make_unique<IfNode>(std::move($3), std::move($5), std::move($7));
    }
    ;

while_statement
    : TOK_WHILE TOK_ABRE_PARENTESES expression TOK_FECHA_PARENTESES 
      statement {
        $$ = std::make_unique<WhileNode>(std::move($3), std::move($5));
    }
    ;

return_statement
    : TOK_RETURN expression TOK_PONTO_VIRGULA {
        $$ = std::move($2); // Implementação simplificada
    }
    | TOK_RETURN TOK_PONTO_VIRGULA {
        $$ = nullptr; // Implementação simplificada
    }
    ;

expression
    : assignment { $$ = std::move($1); }
    ;

assignment
    : identifier TOK_ATRIBUICAO expression {
        $$ = std::make_unique<AssignmentNode>($1, std::move($3));
    }
    | logical_or { $$ = std::move($1); }
    ;

logical_or
    : logical_and { $$ = std::move($1); }
    | logical_or TOK_OU_LOGICO logical_and {
        $$ = std::make_unique<BinaryOpNode>("||", std::move($1), std::move($3));
    }
    ;

logical_and
    : equality { $$ = std::move($1); }
    | logical_and TOK_E_LOGICO equality {
        $$ = std::make_unique<BinaryOpNode>("&&", std::move($1), std::move($3));
    }
    ;

equality
    : comparison { $$ = std::move($1); }
    | equality TOK_IGUALDADE comparison {
        $$ = std::make_unique<BinaryOpNode>("==", std::move($1), std::move($3));
    }
    | equality TOK_DIFERENTE comparison {
        $$ = std::make_unique<BinaryOpNode>("!=", std::move($1), std::move($3));
    }
    ;

comparison
    : term { $$ = std::move($1); }
    | comparison TOK_MAIOR term {
        $$ = std::make_unique<BinaryOpNode>(">", std::move($1), std::move($3));
    }
    | comparison TOK_MENOR term {
        $$ = std::make_unique<BinaryOpNode>("<", std::move($1), std::move($3));
    }
    | comparison TOK_MAIOR_IGUAL term {
        $$ = std::make_unique<BinaryOpNode>(">=", std::move($1), std::move($3));
    }
    | comparison TOK_MENOR_IGUAL term {
        $$ = std::make_unique<BinaryOpNode>("<=", std::move($1), std::move($3));
    }
    ;

term
    : factor { $$ = std::move($1); }
    | term TOK_MAIS factor {
        $$ = std::make_unique<BinaryOpNode>("+", std::move($1), std::move($3));
    }
    | term TOK_MENOS factor {
        $$ = std::make_unique<BinaryOpNode>("-", std::move($1), std::move($3));
    }
    ;

factor
    : unary { $$ = std::move($1); }
    | factor TOK_MULT unary {
        $$ = std::make_unique<BinaryOpNode>("*", std::move($1), std::move($3));
    }
    | factor TOK_DIV unary {
        $$ = std::make_unique<BinaryOpNode>("/", std::move($1), std::move($3));
    }
    ;

unary
    : primary { $$ = std::move($1); }
    | TOK_MENOS unary {
        $$ = std::make_unique<BinaryOpNode>("-", 
            std::make_unique<LiteralNode>("0", "int"), std::move($2));
    }
    | TOK_NEGACAO unary {
        $$ = std::make_unique<BinaryOpNode>("!", std::move($2), nullptr);
    }
    ;

primary
    : identifier {
        $$ = std::make_unique<IdentifierNode>($1);
    }
    | TOK_INT_LIT {
        $$ = std::make_unique<LiteralNode>(std::to_string(yylval.int_val), "int");
    }
    | TOK_FLOAT_LIT {
        $$ = std::make_unique<LiteralNode>(std::to_string(yylval.float_val), "float");
    }
    | TOK_STRING_LIT {
        $$ = std::make_unique<LiteralNode>(*yylval.str_val, "string");
    }
    | TOK_ABRE_PARENTESES expression TOK_FECHA_PARENTESES {
        $$ = std::move($2);
    }
    ;

type
    : TOK_INT { $$ = "int"; }
    | TOK_FLOAT { $$ = "float"; }
    | TOK_CHAR { $$ = "char"; }
    | TOK_STRING { $$ = "string"; }
    | TOK_VOID { $$ = "void"; }
    ;

identifier
    : TOK_ID { $$ = *yylval.str_val; }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    yyparse();
    
    if (programRoot) {
        std::cout << "=== ÁRVORE SINTÁTICA ===" << std::endl;
        programRoot->print();
    }

    fclose(yyin);
    return 0;
}