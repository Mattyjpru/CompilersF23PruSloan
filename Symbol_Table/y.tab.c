/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "PS_ST_Parser.yacc"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }
    int yylex();
    extern char* yytext;
    extern int line;
    extern FILE* yyin;
    int nodeCount = 0;
    int st_loc=0;
    char use[16];
    //Symbol Table stuff

    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        char* val;
        int line_no;
    } symbolTable[48];

    void insert(){
        strcpy(use, yytext);
    }

    int search(char* in){
        for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].name, in)==0){
                return -1;
            }
        }
        return 0;
    }

    void newSymbol(char c){
        int q=search(yytext);
        if(q==0){
            switch(c){
                case 'V':
                    symbolTable[st_loc].name=strdup(yytext);
                    symbolTable[st_loc].d_type=strdup(use);
                    symbolTable[st_loc].line_no=line;
                    symbolTable[st_loc].use=strdup("Variable");
                    st_loc++;
                    break;
                case 'D':
                    symbolTable[st_loc].name=strdup(yytext);        
                    symbolTable[st_loc].d_type=strdup(use);     
                    symbolTable[st_loc].line_no=line;    
                    symbolTable[st_loc].use=strdup("Procedure");
                    st_loc++;
                    break;
                case 'C':
                    symbolTable[st_loc].name=strdup(yytext);
                    symbolTable[st_loc].d_type=strdup("CONST");
                    symbolTable[st_loc].line_no=line;
                    symbolTable[st_loc].use=strdup("Constant");
                    st_loc++;
                    break;
                case 'K':
                    symbolTable[st_loc].name=strdup(yytext);
                    symbolTable[st_loc].d_type=strdup("None");
                    symbolTable[st_loc].line_no=line;
                    symbolTable[st_loc].use=strdup("Keyword");
                    st_loc++;
                    break;
                case 'F':
                    symbolTable[st_loc].name=strdup(yytext);
                    symbolTable[st_loc].d_type=strdup(use);
                    symbolTable[st_loc].line_no=line;
                    symbolTable[st_loc].use=strdup("Function");
                    st_loc++;
                    break;

            }
        }
    }

#line 154 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 327 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_K_DO = 3,                       /* K_DO  */
  YYSYMBOL_K_DOUBLE = 4,                   /* K_DOUBLE  */
  YYSYMBOL_K_ELSE = 5,                     /* K_ELSE  */
  YYSYMBOL_K_EXIT = 6,                     /* K_EXIT  */
  YYSYMBOL_K_FUNCTION = 7,                 /* K_FUNCTION  */
  YYSYMBOL_K_IF = 8,                       /* K_IF  */
  YYSYMBOL_K_INTEGER = 9,                  /* K_INTEGER  */
  YYSYMBOL_K_PRINT_DOUBLE = 10,            /* K_PRINT_DOUBLE  */
  YYSYMBOL_K_PRINT_INTEGER = 11,           /* K_PRINT_INTEGER  */
  YYSYMBOL_K_PRINT_STRING = 12,            /* K_PRINT_STRING  */
  YYSYMBOL_K_PROCEDURE = 13,               /* K_PROCEDURE  */
  YYSYMBOL_K_PROGRAM = 14,                 /* K_PROGRAM  */
  YYSYMBOL_K_READ_DOUBLE = 15,             /* K_READ_DOUBLE  */
  YYSYMBOL_K_READ_INTEGER = 16,            /* K_READ_INTEGER  */
  YYSYMBOL_K_READ_STRING = 17,             /* K_READ_STRING  */
  YYSYMBOL_K_RETURN = 18,                  /* K_RETURN  */
  YYSYMBOL_K_STRING = 19,                  /* K_STRING  */
  YYSYMBOL_K_THEN = 20,                    /* K_THEN  */
  YYSYMBOL_K_WHILE = 21,                   /* K_WHILE  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_ASSIGN_PLUS = 23,               /* ASSIGN_PLUS  */
  YYSYMBOL_ASSIGN_MINUS = 24,              /* ASSIGN_MINUS  */
  YYSYMBOL_ASSIGN_MULTIPLY = 25,           /* ASSIGN_MULTIPLY  */
  YYSYMBOL_ASSIGN_DIVIDE = 26,             /* ASSIGN_DIVIDE  */
  YYSYMBOL_ASSIGN_MOD = 27,                /* ASSIGN_MOD  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_COMMENT = 29,                   /* COMMENT  */
  YYSYMBOL_DAND = 30,                      /* DAND  */
  YYSYMBOL_DIVIDE = 31,                    /* DIVIDE  */
  YYSYMBOL_DOR = 32,                       /* DOR  */
  YYSYMBOL_DEQ = 33,                       /* DEQ  */
  YYSYMBOL_GEQ = 34,                       /* GEQ  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_LBRACKET = 36,                  /* LBRACKET  */
  YYSYMBOL_LEQ = 37,                       /* LEQ  */
  YYSYMBOL_LCURLY = 38,                    /* LCURLY  */
  YYSYMBOL_LPAREN = 39,                    /* LPAREN  */
  YYSYMBOL_LT = 40,                        /* LT  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_DECREMENT = 42,                 /* DECREMENT  */
  YYSYMBOL_MOD = 43,                       /* MOD  */
  YYSYMBOL_MULTIPLY = 44,                  /* MULTIPLY  */
  YYSYMBOL_NE = 45,                        /* NE  */
  YYSYMBOL_NOT = 46,                       /* NOT  */
  YYSYMBOL_PERIOD = 47,                    /* PERIOD  */
  YYSYMBOL_PLUS = 48,                      /* PLUS  */
  YYSYMBOL_INCREMENT = 49,                 /* INCREMENT  */
  YYSYMBOL_RBRACKET = 50,                  /* RBRACKET  */
  YYSYMBOL_RCURLY = 51,                    /* RCURLY  */
  YYSYMBOL_RPAREN = 52,                    /* RPAREN  */
  YYSYMBOL_SEMI = 53,                      /* SEMI  */
  YYSYMBOL_IDENTIFIER = 54,                /* IDENTIFIER  */
  YYSYMBOL_SCONSTANT = 55,                 /* SCONSTANT  */
  YYSYMBOL_ICONSTANT = 56,                 /* ICONSTANT  */
  YYSYMBOL_DCONSTANT = 57,                 /* DCONSTANT  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_task = 62,                      /* task  */
  YYSYMBOL_procedure = 63,                 /* procedure  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_function = 68,                  /* function  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_70_7 = 70,                      /* $@7  */
  YYSYMBOL_71_8 = 71,                      /* $@8  */
  YYSYMBOL_72_9 = 72,                      /* $@9  */
  YYSYMBOL_block = 73,                     /* block  */
  YYSYMBOL_print = 74,                     /* print  */
  YYSYMBOL_75_10 = 75,                     /* $@10  */
  YYSYMBOL_76_11 = 76,                     /* $@11  */
  YYSYMBOL_77_12 = 77,                     /* $@12  */
  YYSYMBOL_78_13 = 78,                     /* $@13  */
  YYSYMBOL_79_14 = 79,                     /* $@14  */
  YYSYMBOL_80_15 = 80,                     /* $@15  */
  YYSYMBOL_var = 81,                       /* var  */
  YYSYMBOL_82_16 = 82,                     /* $@16  */
  YYSYMBOL_assignment = 83,                /* assignment  */
  YYSYMBOL_84_17 = 84,                     /* $@17  */
  YYSYMBOL_85_18 = 85,                     /* $@18  */
  YYSYMBOL_86_19 = 86,                     /* $@19  */
  YYSYMBOL_87_20 = 87,                     /* $@20  */
  YYSYMBOL_88_21 = 88,                     /* $@21  */
  YYSYMBOL_89_22 = 89,                     /* $@22  */
  YYSYMBOL_90_23 = 90,                     /* $@23  */
  YYSYMBOL_d_type = 91,                    /* d_type  */
  YYSYMBOL_expr = 92,                      /* expr  */
  YYSYMBOL_param_list = 93,                /* param_list  */
  YYSYMBOL_94_24 = 94,                     /* $@24  */
  YYSYMBOL_epsilon = 95                    /* epsilon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   102,   102,   105,   105,   108,   110,   111,   112,   116,
     116,   116,   117,   117,   117,   122,   122,   122,   123,   123,
     123,   128,   130,   132,   134,   136,   138,   140,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   150,
     151,   156,   156,   157,   162,   162,   162,   163,   163,   163,
     164,   164,   164,   165,   165,   170,   171,   172,   176,   177,
     178,   179,   181,   183,   189,   190,   190,   193
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "K_DO", "K_DOUBLE",
  "K_ELSE", "K_EXIT", "K_FUNCTION", "K_IF", "K_INTEGER", "K_PRINT_DOUBLE",
  "K_PRINT_INTEGER", "K_PRINT_STRING", "K_PROCEDURE", "K_PROGRAM",
  "K_READ_DOUBLE", "K_READ_INTEGER", "K_READ_STRING", "K_RETURN",
  "K_STRING", "K_THEN", "K_WHILE", "ASSIGN", "ASSIGN_PLUS", "ASSIGN_MINUS",
  "ASSIGN_MULTIPLY", "ASSIGN_DIVIDE", "ASSIGN_MOD", "COMMA", "COMMENT",
  "DAND", "DIVIDE", "DOR", "DEQ", "GEQ", "GT", "LBRACKET", "LEQ", "LCURLY",
  "LPAREN", "LT", "MINUS", "DECREMENT", "MOD", "MULTIPLY", "NE", "NOT",
  "PERIOD", "PLUS", "INCREMENT", "RBRACKET", "RCURLY", "RPAREN", "SEMI",
  "IDENTIFIER", "SCONSTANT", "ICONSTANT", "DCONSTANT", "$accept",
  "statement", "program", "$@1", "task", "procedure", "$@2", "$@3", "$@4",
  "$@5", "function", "$@6", "$@7", "$@8", "$@9", "block", "print", "$@10",
  "$@11", "$@12", "$@13", "$@14", "$@15", "var", "$@16", "assignment",
  "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "d_type", "expr",
  "param_list", "$@24", "epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,   -36,    39,   -71,   -71,   -71,     2,     4,   -71,   -71,
      -3,   -71,   -71,    16,    16,     1,     5,   -71,   -71,   -71,
     -71,   -71,   -71,     6,     7,   -71,   -71,   -71,   -71,     3,
      17,    23,    25,    16,    13,    16,    14,    15,    18,    29,
      19,    30,    44,    35,    -4,    36,    -4,    47,    -4,    37,
      38,    40,   -71,    27,    -4,    -4,    -4,    26,   -71,    -4,
      31,    16,    32,   -38,   -30,   -17,    59,    62,    63,    64,
     -71,   -71,   -71,   -71,    65,   -71,    41,   -71,   -71,   -71,
     -71,   -71,   -26,    42,    43,   -71,    -7,   -71,   -71,    33,
      34,    45,   -26,    46,   -71,    49,    50,   -71,   -71,    -5,
      51,    52,   -26,   -26,    53,    55,    56,   -71,   -71,   -71,
      10,   -71,    57,    58,   -71,    60,    61,   -71,   -71,   -71,
      66,    67,    68,    69,    70,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     0,    15,     9,
       0,     6,     5,     0,     0,     0,     0,     4,     8,     7,
      57,    55,    56,     0,     0,    10,    13,    16,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    64,     0,    67,     0,    67,     0,    67,     0,
       0,     0,    44,     0,    21,    22,    23,     0,    27,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    24,    25,    26,    41,    43,     0,    20,    66,    11,
      36,    30,     0,    60,    58,    59,     0,    38,    32,     0,
       0,     0,     0,     0,    17,     0,     0,    60,    58,     0,
       0,     0,     0,     0,     0,     0,     0,    45,    48,    51,
       0,    42,     0,     0,    63,     0,     0,    61,    62,    40,
       0,     0,     0,     0,     0,    54,    37,    31,    35,    29,
      39,    33,    46,    49,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,   -71,   -71,    78,   -71,   -71,   -71,   -71,
      80,   -71,   -71,   -71,   -71,    -2,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,    48,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -12,   -70,   -32,   -71,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     6,    10,    11,    15,    29,    16,    30,
      12,    13,    31,    14,    32,    53,    54,   101,    96,   106,
     100,    95,   105,    55,    93,    56,    66,   122,    67,   123,
      68,   124,    69,    57,    86,    38,    47,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    23,    24,    40,     8,    21,    49,    50,    51,    82,
       9,     8,    99,    82,     1,    22,    80,     9,     4,    81,
      20,    37,   110,    37,    83,    21,    84,    85,    97,    78,
      98,    85,   117,   118,   102,    22,   102,    87,    88,     5,
       7,   103,    33,   103,    60,   104,    62,   114,    17,    37,
      52,   102,    71,    72,    73,    25,    34,    76,   103,    26,
      27,    28,    35,   125,    36,    39,    41,    44,    46,    42,
      43,    45,   -65,    48,    59,    61,    63,    64,    70,    65,
      74,    89,    77,    79,    90,    91,    92,   -44,    18,   107,
      19,   108,    94,     0,   -34,   -28,     0,     0,     0,   111,
     109,   112,   113,   115,   116,    75,   119,   120,   121,     0,
     126,   127,     0,   128,   129,     0,     0,     0,     0,   130,
     131,   132,   133,   134
};

static const yytype_int8 yycheck[] =
{
       4,    13,    14,    35,     7,     9,    10,    11,    12,    39,
      13,     7,    82,    39,    14,    19,    54,    13,    54,    57,
       4,    33,    92,    35,    54,     9,    56,    57,    54,    61,
      56,    57,   102,   103,    41,    19,    41,    54,    55,     0,
      38,    48,    39,    48,    46,    52,    48,    52,    51,    61,
      54,    41,    54,    55,    56,    54,    39,    59,    48,    54,
      54,    54,    39,    53,    39,    52,    52,    38,    38,    54,
      52,    52,    28,    38,    38,    28,    39,    39,    51,    39,
      54,    22,    51,    51,    22,    22,    22,    22,    10,    56,
      10,    57,    51,    -1,    52,    52,    -1,    -1,    -1,    53,
      55,    52,    52,    52,    52,    57,    53,    52,    52,    -1,
      53,    53,    -1,    53,    53,    -1,    -1,    -1,    -1,    53,
      53,    53,    53,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    59,    60,    54,     0,    61,    38,     7,    13,
      62,    63,    68,    69,    71,    64,    66,    51,    63,    68,
       4,     9,    19,    91,    91,    54,    54,    54,    54,    65,
      67,    70,    72,    39,    39,    39,    39,    91,    93,    52,
      93,    52,    54,    52,    38,    52,    38,    94,    38,    10,
      11,    12,    54,    73,    74,    81,    83,    91,    95,    38,
      73,    28,    73,    39,    39,    39,    84,    86,    88,    90,
      51,    73,    73,    73,    54,    83,    73,    51,    93,    51,
      54,    57,    39,    54,    56,    57,    92,    54,    55,    22,
      22,    22,    22,    82,    51,    79,    76,    54,    56,    92,
      78,    75,    41,    48,    52,    80,    77,    56,    57,    55,
      92,    53,    52,    52,    52,    52,    52,    92,    92,    53,
      52,    52,    85,    87,    89,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    61,    60,    62,    62,    62,    62,    64,
      65,    63,    66,    67,    63,    69,    70,    68,    71,    72,
      68,    73,    73,    73,    73,    73,    73,    73,    75,    74,
      76,    74,    77,    74,    78,    74,    79,    74,    80,    74,
      74,    82,    81,    81,    84,    85,    83,    86,    87,    83,
      88,    89,    83,    90,    83,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    94,    93,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     6,     1,     1,     2,     2,     0,
       0,    10,     0,     0,     9,     0,     0,    11,     0,     0,
      10,     1,     1,     1,     2,     2,     2,     1,     0,     6,
       0,     6,     0,     6,     0,     6,     0,     6,     0,     6,
       5,     0,     4,     2,     0,     0,     6,     0,     0,     6,
       0,     0,     6,     0,     5,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     2,     0,     5,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* statement: program  */
#line 102 "PS_ST_Parser.yacc"
            { printf("Valid Program\n");
                  exit(0);  }
#line 1494 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 105 "PS_ST_Parser.yacc"
                               {newSymbol('V');}
#line 1500 "y.tab.c"
    break;

  case 5: /* task: function  */
#line 109 "PS_ST_Parser.yacc"
    {newSymbol('F');}
#line 1506 "y.tab.c"
    break;

  case 6: /* task: procedure  */
#line 110 "PS_ST_Parser.yacc"
                {newSymbol('D');}
#line 1512 "y.tab.c"
    break;

  case 7: /* task: task function  */
#line 111 "PS_ST_Parser.yacc"
                    {newSymbol('F');}
#line 1518 "y.tab.c"
    break;

  case 8: /* task: task procedure  */
#line 112 "PS_ST_Parser.yacc"
                     {newSymbol('D');}
#line 1524 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 116 "PS_ST_Parser.yacc"
                {newSymbol('D');}
#line 1530 "y.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 116 "PS_ST_Parser.yacc"
                                             {newSymbol('V');}
#line 1536 "y.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 117 "PS_ST_Parser.yacc"
                  {newSymbol('D');}
#line 1542 "y.tab.c"
    break;

  case 13: /* $@5: %empty  */
#line 117 "PS_ST_Parser.yacc"
                                               {newSymbol('V');}
#line 1548 "y.tab.c"
    break;

  case 15: /* $@6: %empty  */
#line 122 "PS_ST_Parser.yacc"
               {newSymbol('F');}
#line 1554 "y.tab.c"
    break;

  case 16: /* $@7: %empty  */
#line 122 "PS_ST_Parser.yacc"
                                                   {newSymbol('V');}
#line 1560 "y.tab.c"
    break;

  case 18: /* $@8: %empty  */
#line 123 "PS_ST_Parser.yacc"
                 {newSymbol('F');}
#line 1566 "y.tab.c"
    break;

  case 19: /* $@9: %empty  */
#line 123 "PS_ST_Parser.yacc"
                                                     {newSymbol('V');}
#line 1572 "y.tab.c"
    break;

  case 22: /* block: var  */
#line 131 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1578 "y.tab.c"
    break;

  case 23: /* block: assignment  */
#line 133 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1584 "y.tab.c"
    break;

  case 24: /* block: print block  */
#line 135 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1590 "y.tab.c"
    break;

  case 25: /* block: var block  */
#line 137 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1596 "y.tab.c"
    break;

  case 26: /* block: assignment block  */
#line 139 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1602 "y.tab.c"
    break;

  case 27: /* block: epsilon  */
#line 141 "PS_ST_Parser.yacc"
   {printf("!");}
#line 1608 "y.tab.c"
    break;

  case 28: /* $@10: %empty  */
#line 145 "PS_ST_Parser.yacc"
                                     {newSymbol('C');}
#line 1614 "y.tab.c"
    break;

  case 30: /* $@11: %empty  */
#line 146 "PS_ST_Parser.yacc"
                                     {newSymbol('C');}
#line 1620 "y.tab.c"
    break;

  case 32: /* $@12: %empty  */
#line 147 "PS_ST_Parser.yacc"
                                      {newSymbol('C');}
#line 1626 "y.tab.c"
    break;

  case 34: /* $@13: %empty  */
#line 148 "PS_ST_Parser.yacc"
                                        {newSymbol('V');}
#line 1632 "y.tab.c"
    break;

  case 36: /* $@14: %empty  */
#line 149 "PS_ST_Parser.yacc"
                                       {newSymbol('V');}
#line 1638 "y.tab.c"
    break;

  case 38: /* $@15: %empty  */
#line 150 "PS_ST_Parser.yacc"
                                       {newSymbol('V');}
#line 1644 "y.tab.c"
    break;

  case 40: /* print: K_PRINT_INTEGER LPAREN expr RPAREN SEMI  */
#line 152 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1650 "y.tab.c"
    break;

  case 41: /* $@16: %empty  */
#line 156 "PS_ST_Parser.yacc"
                      {newSymbol('V');}
#line 1656 "y.tab.c"
    break;

  case 43: /* var: d_type assignment  */
#line 158 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1662 "y.tab.c"
    break;

  case 44: /* $@17: %empty  */
#line 162 "PS_ST_Parser.yacc"
               {newSymbol('V');}
#line 1668 "y.tab.c"
    break;

  case 45: /* $@18: %empty  */
#line 162 "PS_ST_Parser.yacc"
                                                  {newSymbol('C');}
#line 1674 "y.tab.c"
    break;

  case 47: /* $@19: %empty  */
#line 163 "PS_ST_Parser.yacc"
                {newSymbol('V');}
#line 1680 "y.tab.c"
    break;

  case 48: /* $@20: %empty  */
#line 163 "PS_ST_Parser.yacc"
                                                   {newSymbol('C');}
#line 1686 "y.tab.c"
    break;

  case 50: /* $@21: %empty  */
#line 164 "PS_ST_Parser.yacc"
                 {newSymbol('V');}
#line 1692 "y.tab.c"
    break;

  case 51: /* $@22: %empty  */
#line 164 "PS_ST_Parser.yacc"
                                                    {newSymbol('C');}
#line 1698 "y.tab.c"
    break;

  case 53: /* $@23: %empty  */
#line 165 "PS_ST_Parser.yacc"
                 {newSymbol('V');}
#line 1704 "y.tab.c"
    break;

  case 55: /* d_type: K_INTEGER  */
#line 170 "PS_ST_Parser.yacc"
              {insert();}
#line 1710 "y.tab.c"
    break;

  case 56: /* d_type: K_STRING  */
#line 171 "PS_ST_Parser.yacc"
               {insert();}
#line 1716 "y.tab.c"
    break;

  case 57: /* d_type: K_DOUBLE  */
#line 172 "PS_ST_Parser.yacc"
              {insert();}
#line 1722 "y.tab.c"
    break;

  case 58: /* expr: ICONSTANT  */
#line 176 "PS_ST_Parser.yacc"
              {newSymbol('C');}
#line 1728 "y.tab.c"
    break;

  case 59: /* expr: DCONSTANT  */
#line 177 "PS_ST_Parser.yacc"
                {newSymbol('C');}
#line 1734 "y.tab.c"
    break;

  case 60: /* expr: IDENTIFIER  */
#line 178 "PS_ST_Parser.yacc"
                 {newSymbol('V');}
#line 1740 "y.tab.c"
    break;

  case 61: /* expr: expr MINUS expr  */
#line 180 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1746 "y.tab.c"
    break;

  case 62: /* expr: expr PLUS expr  */
#line 182 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1752 "y.tab.c"
    break;

  case 63: /* expr: LPAREN expr RPAREN  */
#line 184 "PS_ST_Parser.yacc"
    {printf("!");}
#line 1758 "y.tab.c"
    break;

  case 64: /* param_list: d_type IDENTIFIER  */
#line 189 "PS_ST_Parser.yacc"
                      {newSymbol('V');}
#line 1764 "y.tab.c"
    break;

  case 65: /* $@24: %empty  */
#line 190 "PS_ST_Parser.yacc"
                        {newSymbol('V');}
#line 1770 "y.tab.c"
    break;


#line 1774 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 195 "PS_ST_Parser.yacc"


int main(int argc ,char** argv){
    do {
        /* printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Walking through the Parse Tree Begins Here\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");  */
        yyparse();
    } while ( !feof( yyin ) );
    for (int i=0;i<st_loc;i++){
        if(symbolTable[i].name){
            printf("%s",symbolTable[i].name);
            printf("\t");
        }
        else{
            printf("\t\t");
        }

        if(symbolTable[i].d_type){
            printf("%s",symbolTable[i].d_type);
            printf("\t");
        }
        else{
            printf("\t\t");
        }

        if(symbolTable[i].use){
            printf("%s",symbolTable[i].use);
            printf("\t");
        }
        else{
            printf("\t\t");
        }

        if(symbolTable[i].val){
            printf("%s",symbolTable[i].val);
            printf("\t");
        }
        else{
            printf("\t\t");
        }

        if(symbolTable[i].line_no){
            printf("%d",symbolTable[i].line_no);
            printf("\t");
        }
        else{
            printf("\t\t");
        }
    }
    // code generator goes here
}
