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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    K_DO = 258,                    /* K_DO  */
    K_DOUBLE = 259,                /* K_DOUBLE  */
    K_ELSE = 260,                  /* K_ELSE  */
    K_EXIT = 261,                  /* K_EXIT  */
    K_FUNCTION = 262,              /* K_FUNCTION  */
    K_IF = 263,                    /* K_IF  */
    K_INTEGER = 264,               /* K_INTEGER  */
    K_PRINT_DOUBLE = 265,          /* K_PRINT_DOUBLE  */
    K_PRINT_INTEGER = 266,         /* K_PRINT_INTEGER  */
    K_PRINT_STRING = 267,          /* K_PRINT_STRING  */
    K_PROCEDURE = 268,             /* K_PROCEDURE  */
    K_PROGRAM = 269,               /* K_PROGRAM  */
    K_READ_DOUBLE = 270,           /* K_READ_DOUBLE  */
    K_READ_INTEGER = 271,          /* K_READ_INTEGER  */
    K_READ_STRING = 272,           /* K_READ_STRING  */
    K_RETURN = 273,                /* K_RETURN  */
    K_STRING = 274,                /* K_STRING  */
    K_THEN = 275,                  /* K_THEN  */
    K_WHILE = 276,                 /* K_WHILE  */
    ASSIGN = 277,                  /* ASSIGN  */
    ASSIGN_PLUS = 278,             /* ASSIGN_PLUS  */
    ASSIGN_MINUS = 279,            /* ASSIGN_MINUS  */
    ASSIGN_MULTIPLY = 280,         /* ASSIGN_MULTIPLY  */
    ASSIGN_DIVIDE = 281,           /* ASSIGN_DIVIDE  */
    ASSIGN_MOD = 282,              /* ASSIGN_MOD  */
    COMMA = 283,                   /* COMMA  */
    COMMENT = 284,                 /* COMMENT  */
    DAND = 285,                    /* DAND  */
    DIVIDE = 286,                  /* DIVIDE  */
    DOR = 287,                     /* DOR  */
    DEQ = 288,                     /* DEQ  */
    GEQ = 289,                     /* GEQ  */
    GT = 290,                      /* GT  */
    LBRACKET = 291,                /* LBRACKET  */
    LEQ = 292,                     /* LEQ  */
    LCURLY = 293,                  /* LCURLY  */
    LPAREN = 294,                  /* LPAREN  */
    LT = 295,                      /* LT  */
    MINUS = 296,                   /* MINUS  */
    DECREMENT = 297,               /* DECREMENT  */
    MOD = 298,                     /* MOD  */
    MULTIPLY = 299,                /* MULTIPLY  */
    NE = 300,                      /* NE  */
    NOT = 301,                     /* NOT  */
    PERIOD = 302,                  /* PERIOD  */
    PLUS = 303,                    /* PLUS  */
    INCREMENT = 304,               /* INCREMENT  */
    RBRACKET = 305,                /* RBRACKET  */
    RCURLY = 306,                  /* RCURLY  */
    RPAREN = 307,                  /* RPAREN  */
    SEMI = 308,                    /* SEMI  */
    IDENTIFIER = 309,              /* IDENTIFIER  */
    SCONSTANT = 310,               /* SCONSTANT  */
    ICONSTANT = 311,               /* ICONSTANT  */
    DCONSTANT = 312                /* DCONSTANT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define K_DO 258
#define K_DOUBLE 259
#define K_ELSE 260
#define K_EXIT 261
#define K_FUNCTION 262
#define K_IF 263
#define K_INTEGER 264
#define K_PRINT_DOUBLE 265
#define K_PRINT_INTEGER 266
#define K_PRINT_STRING 267
#define K_PROCEDURE 268
#define K_PROGRAM 269
#define K_READ_DOUBLE 270
#define K_READ_INTEGER 271
#define K_READ_STRING 272
#define K_RETURN 273
#define K_STRING 274
#define K_THEN 275
#define K_WHILE 276
#define ASSIGN 277
#define ASSIGN_PLUS 278
#define ASSIGN_MINUS 279
#define ASSIGN_MULTIPLY 280
#define ASSIGN_DIVIDE 281
#define ASSIGN_MOD 282
#define COMMA 283
#define COMMENT 284
#define DAND 285
#define DIVIDE 286
#define DOR 287
#define DEQ 288
#define GEQ 289
#define GT 290
#define LBRACKET 291
#define LEQ 292
#define LCURLY 293
#define LPAREN 294
#define LT 295
#define MINUS 296
#define DECREMENT 297
#define MOD 298
#define MULTIPLY 299
#define NE 300
#define NOT 301
#define PERIOD 302
#define PLUS 303
#define INCREMENT 304
#define RBRACKET 305
#define RCURLY 306
#define RPAREN 307
#define SEMI 308
#define IDENTIFIER 309
#define SCONSTANT 310
#define ICONSTANT 311
#define DCONSTANT 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 84 "PS_ST_Parser.yacc"

    int iVal;
    double dVal;
    char  *sVal;

#line 187 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
