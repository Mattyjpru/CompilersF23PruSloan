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
    #include"lex.yy.c"
    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }
    int yylex();
    int nodeCount = 0;
    int st_loc=0;
    char use[16];
    //Symbol Table stuff

    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        //char* val;
        int line_no;
    } symbolTable[2048];

    void insert(){
        strcpy(use, yytext);
    }

    int search(char* use){
        for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].name, use)==0){
                return -1;
            }
        }
        return 0;
    }

    void newSymbol(char c){
        int q=search(yytext);
        if(!q)/*?*/{
            switch(c){
                case 'V':

                    st_loc++;
                    break;
                case 'H':

                    st_loc++;
                    break;
                case 'C':

                    st_loc++;
                    break;
                case 'K':
                    st_loc++;
                    break;
                case 'F':

                    st_loc++;
                    break;

            }
        }
    }

#line 136 "y.tab.c"

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
#line 66 "PS_ST_Parser.yacc"

    int iVal;
    double dVal;
    char  *sVal;

#line 309 "y.tab.c"

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
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_task = 63,                      /* task  */
  YYSYMBOL_procedure = 64,                 /* procedure  */
  YYSYMBOL_function = 65,                  /* function  */
  YYSYMBOL_block = 66,                     /* block  */
  YYSYMBOL_print = 67,                     /* print  */
  YYSYMBOL_var = 68,                       /* var  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_d_type = 70,                    /* d_type  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_param_list = 72,                /* param_list  */
  YYSYMBOL_epsilon = 73                    /* epsilon  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

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
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    86,    86,    86,    91,    95,    99,   103,
     110,   114,   121,   125,   132,   136,   140,   144,   148,   152,
     156,   163,   168,   172,   176,   180,   184,   188,   195,   199,
     206,   211,   215,   219,   227,   231,   235,   242,   246,   251,
     255,   259,   263,   271,   275,   281
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
  "statement", "program", "$@1", "$@2", "task", "procedure", "function",
  "block", "print", "var", "assignment", "d_type", "expr", "param_list",
  "epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,   -52,     3,   -52,   -24,   -52,   -52,    -6,    10,    62,
     -13,     5,   -52,   -52,   -52,   -52,   -52,    -7,     9,   -52,
     -52,   -52,    12,     0,     7,    11,    -1,     2,    19,    21,
      -4,    47,    41,    -4,    44,    45,    46,    48,    61,    35,
      -4,    -4,    -4,    34,   -52,    62,    -4,    38,    -4,   -26,
     -12,   -34,   -17,   -52,   -52,   -52,   -52,   -20,   -52,   -52,
      39,   -52,    40,    42,    43,     4,    49,    50,   -52,    26,
      51,    52,   -52,    53,    54,    55,    24,   -52,   -52,   -52,
      56,    57,   -52,    28,    58,    59,     4,     4,    60,    63,
      64,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     2,     0,     1,     4,     0,     0,     0,
       0,     0,     7,     6,    36,    34,    35,     0,     0,     5,
       9,     8,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    43,     0,    45,     0,     0,     0,     0,     0,     0,
      14,    15,    16,     0,    20,     0,    45,     0,    45,     0,
       0,     0,     0,    11,    17,    18,    19,     0,    29,    44,
       0,    13,     0,     0,     0,     0,    39,    37,    38,     0,
       0,     0,    39,     0,    37,    38,     0,    28,    10,    12,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    30,    31,    33,    25,    22,    42,    24,    21,
      40,    41,    27,    26,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,   -52,   -52,   -52,    81,    82,    22,   -52,
     -52,    71,     1,   -51,   -11,   -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     7,    11,    12,    13,    39,    40,
      41,    42,    43,    69,    27,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      14,    76,    52,     5,    14,    15,    35,    36,    37,    15,
      17,    14,     9,    29,    83,    16,    15,     9,    10,    16,
      70,    71,    65,    10,    26,    26,    16,    65,    63,     1,
       6,    64,     8,    77,    59,   100,   101,    72,    73,    74,
      75,    18,    66,    65,    67,    68,    26,    22,    23,    30,
      38,    24,    25,    31,    32,    47,    19,    33,    72,    28,
      82,    68,    54,    55,    56,    86,    14,    86,    60,    86,
      62,    15,    87,    34,    87,    45,    87,    94,    88,    46,
      97,    16,    48,    52,    49,    50,    53,    51,    57,    61,
      78,    79,    20,    21,    80,    81,     0,     0,     0,     0,
       0,    84,    85,    89,    90,     0,    91,    92,    93,    95,
      96,    98,    99,   102,    58,     0,   103,   104
};

static const yytype_int8 yycheck[] =
{
       4,    52,    22,     0,     4,     9,    10,    11,    12,     9,
       9,     4,     7,    24,    65,    19,     9,     7,    13,    19,
      54,    55,    39,    13,    23,    24,    19,    39,    54,    14,
      54,    57,    38,    53,    45,    86,    87,    54,    55,    56,
      57,    54,    54,    39,    56,    57,    45,    54,    39,    38,
      54,    39,    52,    54,    52,    33,    51,    38,    54,    52,
      56,    57,    40,    41,    42,    41,     4,    41,    46,    41,
      48,     9,    48,    52,    48,    28,    48,    53,    52,    38,
      52,    19,    38,    22,    39,    39,    51,    39,    54,    51,
      51,    51,    11,    11,    52,    52,    -1,    -1,    -1,    -1,
      -1,    52,    52,    52,    52,    -1,    53,    53,    53,    53,
      53,    53,    53,    53,    43,    -1,    53,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    59,    60,    61,     0,    54,    62,    38,     7,
      13,    63,    64,    65,     4,     9,    19,    70,    54,    51,
      64,    65,    54,    39,    39,    52,    70,    72,    52,    72,
      38,    54,    52,    38,    52,    10,    11,    12,    54,    66,
      67,    68,    69,    70,    73,    28,    38,    66,    38,    39,
      39,    39,    22,    51,    66,    66,    66,    54,    69,    72,
      66,    51,    66,    54,    57,    39,    54,    56,    57,    71,
      54,    55,    54,    55,    56,    57,    71,    53,    51,    51,
      52,    52,    56,    71,    52,    52,    41,    48,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    52,    53,    53,
      71,    71,    53,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    61,    62,    60,    63,    63,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    71,    71,    72,    72,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     0,     7,     1,     1,     2,     2,
       8,     7,     9,     8,     1,     1,     1,     2,     2,     2,
       1,     5,     5,     5,     5,     5,     5,     5,     3,     2,
       4,     4,     4,     4,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     2,     4,     0
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
#line 83 "PS_ST_Parser.yacc"
            { printf("Valid Program\n");
                  exit(0);  }
#line 1431 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 86 "PS_ST_Parser.yacc"
                   {insert();}
#line 1437 "y.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 86 "PS_ST_Parser.yacc"
                                         {}
#line 1443 "y.tab.c"
    break;

  case 5: /* program: K_PROGRAM $@1 IDENTIFIER $@2 LCURLY task RCURLY  */
#line 87 "PS_ST_Parser.yacc"
    {

    }
#line 1451 "y.tab.c"
    break;

  case 6: /* task: function  */
#line 92 "PS_ST_Parser.yacc"
    {

    }
#line 1459 "y.tab.c"
    break;

  case 7: /* task: procedure  */
#line 96 "PS_ST_Parser.yacc"
    {

    }
#line 1467 "y.tab.c"
    break;

  case 8: /* task: task function  */
#line 100 "PS_ST_Parser.yacc"
    {

    }
#line 1475 "y.tab.c"
    break;

  case 9: /* task: task procedure  */
#line 104 "PS_ST_Parser.yacc"
    {

    }
#line 1483 "y.tab.c"
    break;

  case 10: /* procedure: K_PROCEDURE IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY  */
#line 111 "PS_ST_Parser.yacc"
    {

    }
#line 1491 "y.tab.c"
    break;

  case 11: /* procedure: K_PROCEDURE IDENTIFIER LPAREN RPAREN LCURLY block RCURLY  */
#line 115 "PS_ST_Parser.yacc"
    {

    }
#line 1499 "y.tab.c"
    break;

  case 12: /* function: K_FUNCTION d_type IDENTIFIER LPAREN param_list RPAREN LCURLY block RCURLY  */
#line 122 "PS_ST_Parser.yacc"
    {

    }
#line 1507 "y.tab.c"
    break;

  case 13: /* function: K_FUNCTION d_type IDENTIFIER LPAREN RPAREN LCURLY block RCURLY  */
#line 126 "PS_ST_Parser.yacc"
    {

    }
#line 1515 "y.tab.c"
    break;

  case 14: /* block: print  */
#line 133 "PS_ST_Parser.yacc"
    {

    }
#line 1523 "y.tab.c"
    break;

  case 15: /* block: var  */
#line 137 "PS_ST_Parser.yacc"
    {

    }
#line 1531 "y.tab.c"
    break;

  case 16: /* block: assignment  */
#line 141 "PS_ST_Parser.yacc"
    {

    }
#line 1539 "y.tab.c"
    break;

  case 17: /* block: print block  */
#line 145 "PS_ST_Parser.yacc"
    {

    }
#line 1547 "y.tab.c"
    break;

  case 18: /* block: var block  */
#line 149 "PS_ST_Parser.yacc"
    {

    }
#line 1555 "y.tab.c"
    break;

  case 19: /* block: assignment block  */
#line 153 "PS_ST_Parser.yacc"
    {

    }
#line 1563 "y.tab.c"
    break;

  case 20: /* block: epsilon  */
#line 157 "PS_ST_Parser.yacc"
    {
        
    }
#line 1571 "y.tab.c"
    break;

  case 21: /* print: K_PRINT_INTEGER LPAREN ICONSTANT RPAREN SEMI  */
#line 164 "PS_ST_Parser.yacc"
    {

    }
#line 1579 "y.tab.c"
    break;

  case 22: /* print: K_PRINT_DOUBLE LPAREN DCONSTANT RPAREN SEMI  */
#line 169 "PS_ST_Parser.yacc"
    {

    }
#line 1587 "y.tab.c"
    break;

  case 23: /* print: K_PRINT_STRING LPAREN SCONSTANT RPAREN SEMI  */
#line 173 "PS_ST_Parser.yacc"
    {

    }
#line 1595 "y.tab.c"
    break;

  case 24: /* print: K_PRINT_INTEGER LPAREN IDENTIFIER RPAREN SEMI  */
#line 177 "PS_ST_Parser.yacc"
    {

    }
#line 1603 "y.tab.c"
    break;

  case 25: /* print: K_PRINT_DOUBLE LPAREN IDENTIFIER RPAREN SEMI  */
#line 181 "PS_ST_Parser.yacc"
    {

    }
#line 1611 "y.tab.c"
    break;

  case 26: /* print: K_PRINT_STRING LPAREN IDENTIFIER RPAREN SEMI  */
#line 185 "PS_ST_Parser.yacc"
    {

    }
#line 1619 "y.tab.c"
    break;

  case 27: /* print: K_PRINT_INTEGER LPAREN expr RPAREN SEMI  */
#line 189 "PS_ST_Parser.yacc"
    {

    }
#line 1627 "y.tab.c"
    break;

  case 28: /* var: d_type IDENTIFIER SEMI  */
#line 196 "PS_ST_Parser.yacc"
    {

    }
#line 1635 "y.tab.c"
    break;

  case 29: /* var: d_type assignment  */
#line 200 "PS_ST_Parser.yacc"
    {

    }
#line 1643 "y.tab.c"
    break;

  case 30: /* assignment: IDENTIFIER ASSIGN ICONSTANT SEMI  */
#line 207 "PS_ST_Parser.yacc"
    {

    }
#line 1651 "y.tab.c"
    break;

  case 31: /* assignment: IDENTIFIER ASSIGN DCONSTANT SEMI  */
#line 212 "PS_ST_Parser.yacc"
    {
        printf("yeah Booooooi %f\n", (yyvsp[-1].dVal));
    }
#line 1659 "y.tab.c"
    break;

  case 32: /* assignment: IDENTIFIER ASSIGN SCONSTANT SEMI  */
#line 216 "PS_ST_Parser.yacc"
    {

    }
#line 1667 "y.tab.c"
    break;

  case 33: /* assignment: IDENTIFIER ASSIGN expr SEMI  */
#line 220 "PS_ST_Parser.yacc"
    {

    }
#line 1675 "y.tab.c"
    break;

  case 34: /* d_type: K_INTEGER  */
#line 228 "PS_ST_Parser.yacc"
    {

    }
#line 1683 "y.tab.c"
    break;

  case 35: /* d_type: K_STRING  */
#line 232 "PS_ST_Parser.yacc"
    {

    }
#line 1691 "y.tab.c"
    break;

  case 36: /* d_type: K_DOUBLE  */
#line 236 "PS_ST_Parser.yacc"
    {

    }
#line 1699 "y.tab.c"
    break;

  case 37: /* expr: ICONSTANT  */
#line 243 "PS_ST_Parser.yacc"
    {

    }
#line 1707 "y.tab.c"
    break;

  case 38: /* expr: DCONSTANT  */
#line 247 "PS_ST_Parser.yacc"
    {

    }
#line 1715 "y.tab.c"
    break;

  case 39: /* expr: IDENTIFIER  */
#line 252 "PS_ST_Parser.yacc"
    {

    }
#line 1723 "y.tab.c"
    break;

  case 40: /* expr: expr MINUS expr  */
#line 256 "PS_ST_Parser.yacc"
    {

    }
#line 1731 "y.tab.c"
    break;

  case 41: /* expr: expr PLUS expr  */
#line 260 "PS_ST_Parser.yacc"
    {

    }
#line 1739 "y.tab.c"
    break;

  case 42: /* expr: LPAREN expr RPAREN  */
#line 264 "PS_ST_Parser.yacc"
    {

    }
#line 1747 "y.tab.c"
    break;

  case 43: /* param_list: d_type IDENTIFIER  */
#line 272 "PS_ST_Parser.yacc"
    {

    }
#line 1755 "y.tab.c"
    break;

  case 44: /* param_list: d_type IDENTIFIER COMMA param_list  */
#line 276 "PS_ST_Parser.yacc"
    {

    }
#line 1763 "y.tab.c"
    break;


#line 1767 "y.tab.c"

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

#line 283 "PS_ST_Parser.yacc"

extern FILE* yyin;

int main(int argc ,char** argv){
    do {
        /* printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");
        printf("Walking through the Parse Tree Begins Here\n");
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n");  */
        yyparse();
    } while ( !feof( yyin ) );
    // code generator goes here
}
