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
     K_PROGRAM = 258,
     K_FUNCTION = 259,
     ICONSTANT = 260,
     K_PRINT_INTEGER = 261,
     K_PRINT_STRING = 262,
     IDENTIFIER = 263,
     K_INTEGER = 264,
     K_STRING = 265,
     LPAREN = 266,
     LCURLY = 267,
     RPAREN = 268,
     RCURLY = 269,
     COMMA = 270,
     ASSIGN = 271,
     SEMI = 272,
     SCONSTANT = 273,
     K_PROCEDURE = 274,
     PLUS = 275,
     MINUS = 276
   };
#endif
/* Tokens.  */
#define K_PROGRAM 258
#define K_FUNCTION 259
#define ICONSTANT 260
#define K_PRINT_INTEGER 261
#define K_PRINT_STRING 262
#define IDENTIFIER 263
#define K_INTEGER 264
#define K_STRING 265
#define LPAREN 266
#define LCURLY 267
#define RPAREN 268
#define RCURLY 269
#define COMMA 270
#define ASSIGN 271
#define SEMI 272
#define SCONSTANT 273
#define K_PROCEDURE 274
#define PLUS 275
#define MINUS 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 12 "PSSimParser.yacc"
{
    double dVal;
    int iVal;
}
/* Line 1529 of yacc.c.  */
#line 96 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

