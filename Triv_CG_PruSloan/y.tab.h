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
     IDENTIFIER = 258,
     SCONSTANT = 259,
     ICONSTANT = 260,
     DCONSTANT = 261,
     K_DO = 262,
     K_DOUBLE = 263,
     K_ELSE = 264,
     K_EXIT = 265,
     K_FUNCTION = 266,
     K_IF = 267,
     K_INTEGER = 268,
     K_PRINT_DOUBLE = 269,
     K_PRINT_INTEGER = 270,
     K_PRINT_STRING = 271,
     K_PROCEDURE = 272,
     K_PROGRAM = 273,
     K_READ_DOUBLE = 274,
     K_READ_INTEGER = 275,
     K_READ_STRING = 276,
     K_RETURN = 277,
     K_STRING = 278,
     K_THEN = 279,
     K_WHILE = 280,
     ASSIGN = 281,
     ASSIGN_PLUS = 282,
     ASSIGN_MINUS = 283,
     ASSIGN_MULTIPLY = 284,
     ASSIGN_DIVIDE = 285,
     ASSIGN_MOD = 286,
     COMMA = 287,
     COMMENT = 288,
     DAND = 289,
     DIVIDE = 290,
     DOR = 291,
     DEQ = 292,
     GEQ = 293,
     GT = 294,
     LBRACKET = 295,
     LEQ = 296,
     LCURLY = 297,
     LPAREN = 298,
     LT = 299,
     MINUS = 300,
     DECREMENT = 301,
     MOD = 302,
     MULTIPLY = 303,
     NE = 304,
     NOT = 305,
     PERIOD = 306,
     PLUS = 307,
     INCREMENT = 308,
     RBRACKET = 309,
     RCURLY = 310,
     RPAREN = 311,
     SEMI = 312
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define SCONSTANT 259
#define ICONSTANT 260
#define DCONSTANT 261
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 47 "PS_CG_Parser.yacc"
{
    struct nt1 { 
		char name[100];
        // char name[100];
		struct node* nd;
	} nd_obj; 
}
/* Line 1529 of yacc.c.  */
#line 171 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

