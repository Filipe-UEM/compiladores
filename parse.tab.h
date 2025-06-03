/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TIPO_INT = 258,                /* TIPO_INT  */
    TIPO_FLOAT = 259,              /* TIPO_FLOAT  */
    TIPO_CHAR = 260,               /* TIPO_CHAR  */
    TIPO_STRING = 261,             /* TIPO_STRING  */
    VOID = 262,                    /* VOID  */
    IF = 263,                      /* IF  */
    ELSE = 264,                    /* ELSE  */
    FOR = 265,                     /* FOR  */
    WHILE = 266,                   /* WHILE  */
    RETURN = 267,                  /* RETURN  */
    CLASS = 268,                   /* CLASS  */
    NEW = 269,                     /* NEW  */
    THIS = 270,                    /* THIS  */
    STATIC = 271,                  /* STATIC  */
    PUBLIC = 272,                  /* PUBLIC  */
    PRIVATE = 273,                 /* PRIVATE  */
    MAIN = 274,                    /* MAIN  */
    IGUALDADE = 275,               /* IGUALDADE  */
    DIFERENTE = 276,               /* DIFERENTE  */
    MAIOR_IGUAL = 277,             /* MAIOR_IGUAL  */
    MENOR_IGUAL = 278,             /* MENOR_IGUAL  */
    MAIOR = 279,                   /* MAIOR  */
    MENOR = 280,                   /* MENOR  */
    ATRIBUICAO = 281,              /* ATRIBUICAO  */
    E_LOGICO = 282,                /* E_LOGICO  */
    OU_LOGICO = 283,               /* OU_LOGICO  */
    NEGACAO = 284,                 /* NEGACAO  */
    SOMA = 285,                    /* SOMA  */
    SUBTRACAO = 286,               /* SUBTRACAO  */
    MULTIPLICACAO = 287,           /* MULTIPLICACAO  */
    DIVISAO = 288,                 /* DIVISAO  */
    PONTO = 289,                   /* PONTO  */
    PONTO_VIRGULA = 290,           /* PONTO_VIRGULA  */
    VIRGULA = 291,                 /* VIRGULA  */
    ABRE_PARENTESES = 292,         /* ABRE_PARENTESES  */
    FECHA_PARENTESES = 293,        /* FECHA_PARENTESES  */
    ABRE_CHAVES = 294,             /* ABRE_CHAVES  */
    FECHA_CHAVES = 295,            /* FECHA_CHAVES  */
    ABRE_COLCHETES = 296,          /* ABRE_COLCHETES  */
    FECHA_COLCHETES = 297,         /* FECHA_COLCHETES  */
    STRING_LITERAL = 298,          /* STRING_LITERAL  */
    CHAR_LITERAL = 299,            /* CHAR_LITERAL  */
    INT = 300,                     /* INT  */
    FLOAT = 301,                   /* FLOAT  */
    IDENTIFICADOR = 302            /* IDENTIFICADOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
