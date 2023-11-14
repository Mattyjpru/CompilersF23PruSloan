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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    SCONSTANT = 259,               /* SCONSTANT  */
    DCONSTANT = 260,               /* DCONSTANT  */
    ICONSTANT = 261,               /* ICONSTANT  */
    K_DO = 262,                    /* K_DO  */
    K_DOUBLE = 263,                /* K_DOUBLE  */
    K_ELSE = 264,                  /* K_ELSE  */
    K_EXIT = 265,                  /* K_EXIT  */
    K_FUNCTION = 266,              /* K_FUNCTION  */
    K_IF = 267,                    /* K_IF  */
    K_INTEGER = 268,               /* K_INTEGER  */
    K_PRINT_DOUBLE = 269,          /* K_PRINT_DOUBLE  */
    K_PRINT_INTEGER = 270,         /* K_PRINT_INTEGER  */
    K_PRINT_STRING = 271,          /* K_PRINT_STRING  */
    K_PROCEDURE = 272,             /* K_PROCEDURE  */
    K_PROGRAM = 273,               /* K_PROGRAM  */
    K_READ_DOUBLE = 274,           /* K_READ_DOUBLE  */
    K_READ_INTEGER = 275,          /* K_READ_INTEGER  */
    K_READ_STRING = 276,           /* K_READ_STRING  */
    K_RETURN = 277,                /* K_RETURN  */
    K_STRING = 278,                /* K_STRING  */
    K_THEN = 279,                  /* K_THEN  */
    K_WHILE = 280,                 /* K_WHILE  */
    ASSIGN = 281,                  /* ASSIGN  */
    ASSIGN_PLUS = 282,             /* ASSIGN_PLUS  */
    ASSIGN_MINUS = 283,            /* ASSIGN_MINUS  */
    ASSIGN_MULTIPLY = 284,         /* ASSIGN_MULTIPLY  */
    ASSIGN_DIVIDE = 285,           /* ASSIGN_DIVIDE  */
    ASSIGN_MOD = 286,              /* ASSIGN_MOD  */
    COMMA = 287,                   /* COMMA  */
    COMMENT = 288,                 /* COMMENT  */
    DAND = 289,                    /* DAND  */
    DIVIDE = 290,                  /* DIVIDE  */
    DOR = 291,                     /* DOR  */
    DEQ = 292,                     /* DEQ  */
    GEQ = 293,                     /* GEQ  */
    GT = 294,                      /* GT  */
    LBRACKET = 295,                /* LBRACKET  */
    LEQ = 296,                     /* LEQ  */
    LCURLY = 297,                  /* LCURLY  */
    LPAREN = 298,                  /* LPAREN  */
    LT = 299,                      /* LT  */
    MINUS = 300,                   /* MINUS  */
    DECREMENT = 301,               /* DECREMENT  */
    MOD = 302,                     /* MOD  */
    MULTIPLY = 303,                /* MULTIPLY  */
    NE = 304,                      /* NE  */
    NOT = 305,                     /* NOT  */
    PERIOD = 306,                  /* PERIOD  */
    PLUS = 307,                    /* PLUS  */
    INCREMENT = 308,               /* INCREMENT  */
    RBRACKET = 309,                /* RBRACKET  */
    RCURLY = 310,                  /* RCURLY  */
    RPAREN = 311,                  /* RPAREN  */
    SEMI = 312                     /* SEMI  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define SCONSTANT 259
#define DCONSTANT 260
#define ICONSTANT 261
#define K_DO 262
#define K_DOUBLE 263
#define K_ELSE 264
#define K_EXIT 265
#define K_FUNCTION 266
#define K_IF 267
#define K_INTEGER 268
#define K_PRINT_DOUBLE 269
#define K_PRINT_INTEGER 270
#define K_PRINT_STRING 271
#define K_PROCEDURE 272
#define K_PROGRAM 273
#define K_READ_DOUBLE 274
#define K_READ_INTEGER 275
#define K_READ_STRING 276
#define K_RETURN 277
#define K_STRING 278
#define K_THEN 279
#define K_WHILE 280
#define ASSIGN 281
#define ASSIGN_PLUS 282
#define ASSIGN_MINUS 283
#define ASSIGN_MULTIPLY 284
#define ASSIGN_DIVIDE 285
#define ASSIGN_MOD 286
#define COMMA 287
#define COMMENT 288
#define DAND 289
#define DIVIDE 290
#define DOR 291
#define DEQ 292
#define GEQ 293
#define GT 294
#define LBRACKET 295
#define LEQ 296
#define LCURLY 297
#define LPAREN 298
#define LT 299
#define MINUS 300
#define DECREMENT 301
#define MOD 302
#define MULTIPLY 303
#define NE 304
#define NOT 305
#define PERIOD 306
#define PLUS 307
#define INCREMENT 308
#define RBRACKET 309
#define RCURLY 310
#define RPAREN 311
#define SEMI 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "PS_ST_Parser.yacc"

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
