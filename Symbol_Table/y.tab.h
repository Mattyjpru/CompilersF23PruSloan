/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     K_DO = 258,
     K_DOUBLE = 259,
     K_ELSE = 260,
     K_EXIT = 261,
     K_FUNCTION = 262,
     K_IF = 263,
     K_INTEGER = 264,
     K_PRINT_DOUBLE = 265,
     K_PRINT_INTEGER = 266,
     K_PRINT_STRING = 267,
     K_PROCEDURE = 268,
     K_PROGRAM = 269,
     K_READ_DOUBLE = 270,
     K_READ_INTEGER = 271,
     K_READ_STRING = 272,
     K_RETURN = 273,
     K_STRING = 274,
     K_THEN = 275,
     K_WHILE = 276,
     ASSIGN = 277,
     ASSIGN_PLUS = 278,
     ASSIGN_MINUS = 279,
     ASSIGN_MULTIPLY = 280,
     ASSIGN_DIVIDE = 281,
     ASSIGN_MOD = 282,
     COMMA = 283,
     COMMENT = 284,
     DAND = 285,
     DIVIDE = 286,
     DOR = 287,
     DEQ = 288,
     GEQ = 289,
     GT = 290,
     LBRACKET = 291,
     LEQ = 292,
     LCURLY = 293,
     LPAREN = 294,
     LT = 295,
     MINUS = 296,
     DECREMENT = 297,
     MOD = 298,
     MULTIPLY = 299,
     NE = 300,
     NOT = 301,
     PERIOD = 302,
     PLUS = 303,
     INCREMENT = 304,
     RBRACKET = 305,
     RCURLY = 306,
     RPAREN = 307,
     SEMI = 308,
     IDENTIFIER = 309,
     SCONSTANT = 310,
     ICONSTANT = 311,
     DCONSTANT = 312
   };
#endif
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 67 "PS_ST_Parser.yacc"
{
    int iVal;
    double dVal;
    char  *sVal;
}
/* Line 1529 of yacc.c.  */
#line 169 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

