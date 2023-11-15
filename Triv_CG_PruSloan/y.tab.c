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
#line 1 "PS_CG_Parser.yacc"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    struct node{
        char* token;
        struct node* leftchild;
        struct node* rightchild;
        // char* dataType;
    };
    struct node *head;

    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }

    int yylex();
    extern char* yytext;
    extern int line;
    extern int yylineno;
    // int nodeCount = 0;
    int st_count=0;
    char useBuff[16];
    //Symbol Table stuff

    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        int intval;
        float dubval;
        int line_no;
    } symbolTable[48];

    struct node* buildNode(struct node*, struct node*, char*);
    void printtree(struct node* );
    void printInorder(struct node *);

    void insert();
    int search(char*);
    // int search_I(int);
    // int search_D(double);
    void newSymbol(char, char*);
    // void newSymbol_I(int);
    // void newSymbol_D(double);

#line 119 "y.tab.c"

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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    SCONSTANT = 259,               /* SCONSTANT  */
    ICONSTANT = 260,               /* ICONSTANT  */
    DCONSTANT = 261,               /* DCONSTANT  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "PS_CG_Parser.yacc"

    struct nt1 { 
		char name[100];
        char dt[100];
		struct node* nd;
	} nd_obj; 

#line 294 "y.tab.c"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_SCONSTANT = 4,                  /* SCONSTANT  */
  YYSYMBOL_ICONSTANT = 5,                  /* ICONSTANT  */
  YYSYMBOL_DCONSTANT = 6,                  /* DCONSTANT  */
  YYSYMBOL_K_DO = 7,                       /* K_DO  */
  YYSYMBOL_K_DOUBLE = 8,                   /* K_DOUBLE  */
  YYSYMBOL_K_ELSE = 9,                     /* K_ELSE  */
  YYSYMBOL_K_EXIT = 10,                    /* K_EXIT  */
  YYSYMBOL_K_FUNCTION = 11,                /* K_FUNCTION  */
  YYSYMBOL_K_IF = 12,                      /* K_IF  */
  YYSYMBOL_K_INTEGER = 13,                 /* K_INTEGER  */
  YYSYMBOL_K_PRINT_DOUBLE = 14,            /* K_PRINT_DOUBLE  */
  YYSYMBOL_K_PRINT_INTEGER = 15,           /* K_PRINT_INTEGER  */
  YYSYMBOL_K_PRINT_STRING = 16,            /* K_PRINT_STRING  */
  YYSYMBOL_K_PROCEDURE = 17,               /* K_PROCEDURE  */
  YYSYMBOL_K_PROGRAM = 18,                 /* K_PROGRAM  */
  YYSYMBOL_K_READ_DOUBLE = 19,             /* K_READ_DOUBLE  */
  YYSYMBOL_K_READ_INTEGER = 20,            /* K_READ_INTEGER  */
  YYSYMBOL_K_READ_STRING = 21,             /* K_READ_STRING  */
  YYSYMBOL_K_RETURN = 22,                  /* K_RETURN  */
  YYSYMBOL_K_STRING = 23,                  /* K_STRING  */
  YYSYMBOL_K_THEN = 24,                    /* K_THEN  */
  YYSYMBOL_K_WHILE = 25,                   /* K_WHILE  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_ASSIGN_PLUS = 27,               /* ASSIGN_PLUS  */
  YYSYMBOL_ASSIGN_MINUS = 28,              /* ASSIGN_MINUS  */
  YYSYMBOL_ASSIGN_MULTIPLY = 29,           /* ASSIGN_MULTIPLY  */
  YYSYMBOL_ASSIGN_DIVIDE = 30,             /* ASSIGN_DIVIDE  */
  YYSYMBOL_ASSIGN_MOD = 31,                /* ASSIGN_MOD  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_COMMENT = 33,                   /* COMMENT  */
  YYSYMBOL_DAND = 34,                      /* DAND  */
  YYSYMBOL_DIVIDE = 35,                    /* DIVIDE  */
  YYSYMBOL_DOR = 36,                       /* DOR  */
  YYSYMBOL_DEQ = 37,                       /* DEQ  */
  YYSYMBOL_GEQ = 38,                       /* GEQ  */
  YYSYMBOL_GT = 39,                        /* GT  */
  YYSYMBOL_LBRACKET = 40,                  /* LBRACKET  */
  YYSYMBOL_LEQ = 41,                       /* LEQ  */
  YYSYMBOL_LCURLY = 42,                    /* LCURLY  */
  YYSYMBOL_LPAREN = 43,                    /* LPAREN  */
  YYSYMBOL_LT = 44,                        /* LT  */
  YYSYMBOL_MINUS = 45,                     /* MINUS  */
  YYSYMBOL_DECREMENT = 46,                 /* DECREMENT  */
  YYSYMBOL_MOD = 47,                       /* MOD  */
  YYSYMBOL_MULTIPLY = 48,                  /* MULTIPLY  */
  YYSYMBOL_NE = 49,                        /* NE  */
  YYSYMBOL_NOT = 50,                       /* NOT  */
  YYSYMBOL_PERIOD = 51,                    /* PERIOD  */
  YYSYMBOL_PLUS = 52,                      /* PLUS  */
  YYSYMBOL_INCREMENT = 53,                 /* INCREMENT  */
  YYSYMBOL_RBRACKET = 54,                  /* RBRACKET  */
  YYSYMBOL_RCURLY = 55,                    /* RCURLY  */
  YYSYMBOL_RPAREN = 56,                    /* RPAREN  */
  YYSYMBOL_SEMI = 57,                      /* SEMI  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_task = 62,                      /* task  */
  YYSYMBOL_procedure = 63,                 /* procedure  */
  YYSYMBOL_function = 64,                  /* function  */
  YYSYMBOL_block = 65,                     /* block  */
  YYSYMBOL_print = 66,                     /* print  */
  YYSYMBOL_var = 67,                       /* var  */
  YYSYMBOL_68_2 = 68,                      /* $@2  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_70_3 = 70,                      /* $@3  */
  YYSYMBOL_d_type = 71,                    /* d_type  */
  YYSYMBOL_expr = 72,                      /* expr  */
  YYSYMBOL_param_list = 73,                /* param_list  */
  YYSYMBOL_74_4 = 74                       /* $@4  */
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
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  92

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
       0,    70,    70,    72,    72,    78,    79,    80,    81,    84,
      85,    89,    93,    94,    95,    96,    97,    98,    99,   104,
     105,   106,   107,   108,   109,   110,   114,   114,   115,   119,
     119,   125,   126,   127,   131,   132,   133,   134,   135,   136,
     145,   146,   146,   147
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "SCONSTANT", "ICONSTANT", "DCONSTANT", "K_DO", "K_DOUBLE", "K_ELSE",
  "K_EXIT", "K_FUNCTION", "K_IF", "K_INTEGER", "K_PRINT_DOUBLE",
  "K_PRINT_INTEGER", "K_PRINT_STRING", "K_PROCEDURE", "K_PROGRAM",
  "K_READ_DOUBLE", "K_READ_INTEGER", "K_READ_STRING", "K_RETURN",
  "K_STRING", "K_THEN", "K_WHILE", "ASSIGN", "ASSIGN_PLUS", "ASSIGN_MINUS",
  "ASSIGN_MULTIPLY", "ASSIGN_DIVIDE", "ASSIGN_MOD", "COMMA", "COMMENT",
  "DAND", "DIVIDE", "DOR", "DEQ", "GEQ", "GT", "LBRACKET", "LEQ", "LCURLY",
  "LPAREN", "LT", "MINUS", "DECREMENT", "MOD", "MULTIPLY", "NE", "NOT",
  "PERIOD", "PLUS", "INCREMENT", "RBRACKET", "RCURLY", "RPAREN", "SEMI",
  "$accept", "statement", "program", "$@1", "task", "procedure",
  "function", "block", "print", "var", "$@2", "assignment", "$@3",
  "d_type", "expr", "param_list", "$@4", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,    21,    26,   -45,   -45,   -45,     8,    22,    15,    37,
     -11,   -45,   -45,   -45,   -45,   -45,    45,     9,   -45,   -45,
     -45,    11,    15,    15,    46,    -1,     0,    29,    20,    23,
      32,     6,     6,    15,   -45,    24,    25,    27,    14,     6,
       6,     6,    60,    16,   -45,    40,     7,    -2,    31,   -45,
     -45,   -45,   -45,    47,   -45,   -45,     2,    18,    28,    30,
      33,   -45,     2,    -9,    34,    35,    36,   -45,   -45,   -15,
      38,    39,    41,    42,     1,     2,     2,    43,    44,    48,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     9,     0,     0,
       0,     6,     5,    33,    31,    32,     0,     0,     4,     8,
       7,     0,    43,    43,     0,     0,     0,    40,     0,     0,
       0,    18,    18,    43,    29,     0,     0,     0,     0,    12,
      13,    14,     0,     0,    42,     0,     0,     0,     0,    10,
      15,    16,    17,    26,    28,    11,     0,     0,     0,    36,
      34,    35,     0,     0,     0,     0,     0,    36,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    30,    23,    20,    22,    19,    39,    37,    38,    25,
      24,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,    62,    65,    19,   -45,   -45,
     -45,    50,   -45,    -6,   -44,    -8,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     6,    10,    11,    12,    38,    39,    40,
      66,    41,    45,    42,    63,    25,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       8,    59,    16,    60,    61,    67,     9,    68,    61,    34,
      57,     1,    69,    58,    13,    26,    24,    24,    74,    14,
      35,    36,    37,    13,     4,    44,     5,    24,    14,    15,
      75,    87,    88,     8,    64,    65,    75,    76,    15,     9,
      17,    62,    81,    76,    18,    62,    75,    77,    21,    27,
       7,    43,    22,    76,    23,    28,    29,    86,    50,    51,
      52,   -41,    31,    53,    33,    32,    56,    46,    47,    49,
      48,    55,    19,   -29,    70,    20,     0,     0,     0,     0,
       0,     0,     0,     0,    71,     0,    72,     0,     0,    73,
      78,    79,    54,    80,     0,    82,    83,     0,    84,    85,
      89,    90,     0,     0,     0,    91
};

static const yytype_int8 yycheck[] =
{
      11,     3,     8,     5,     6,     3,    17,     5,     6,     3,
       3,    18,    56,     6,     8,    23,    22,    23,    62,    13,
      14,    15,    16,     8,     3,    33,     0,    33,    13,    23,
      45,    75,    76,    11,     3,     4,    45,    52,    23,    17,
       3,    43,    57,    52,    55,    43,    45,    56,     3,     3,
      42,    32,    43,    52,    43,    56,    56,    56,    39,    40,
      41,    32,    42,     3,    32,    42,    26,    43,    43,    55,
      43,    55,    10,    26,    56,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    56,    -1,    -1,    56,
      56,    56,    42,    57,    -1,    57,    57,    -1,    57,    57,
      57,    57,    -1,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    59,    60,     3,     0,    61,    42,    11,    17,
      62,    63,    64,     8,    13,    23,    71,     3,    55,    63,
      64,     3,    43,    43,    71,    73,    73,     3,    56,    56,
      74,    42,    42,    32,     3,    14,    15,    16,    65,    66,
      67,    69,    71,    65,    73,    70,    43,    43,    43,    55,
      65,    65,    65,     3,    69,    55,    26,     3,     6,     3,
       5,     6,    43,    72,     3,     4,    68,     3,     5,    72,
      56,    56,    56,    56,    72,    45,    52,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    56,    72,    72,    57,
      57,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    61,    60,    62,    62,    62,    62,    63,
      63,    64,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    68,    67,    67,    70,
      69,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      73,    74,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     6,     1,     1,     2,     2,     0,
       8,     9,     1,     1,     1,     2,     2,     2,     0,     5,
       5,     5,     5,     5,     5,     5,     0,     4,     2,     0,
       5,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       2,     0,     5,     0
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
#line 70 "PS_CG_Parser.yacc"
            { printf("Valid Program\n"); }
#line 1411 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 72 "PS_CG_Parser.yacc"
                             {newSymbol('M', (yyvsp[0].nd_obj).dt);}
#line 1417 "y.tab.c"
    break;

  case 4: /* program: K_PROGRAM IDENTIFIER $@1 LCURLY task RCURLY  */
#line 73 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd=buildNode((yyvsp[-4].nd_obj).nd,(yyvsp[-2].nd_obj).nd,(yyvsp[-4].nd_obj).dt); head = (yyval.nd_obj).nd; 
    }
#line 1425 "y.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 114 "PS_CG_Parser.yacc"
                     {newSymbol('V', (yyvsp[0].nd_obj).dt);}
#line 1431 "y.tab.c"
    break;

  case 29: /* $@3: %empty  */
#line 119 "PS_CG_Parser.yacc"
               {newSymbol('V', (yyvsp[0].nd_obj).dt);}
#line 1437 "y.tab.c"
    break;

  case 30: /* assignment: IDENTIFIER $@3 ASSIGN expr SEMI  */
#line 120 "PS_CG_Parser.yacc"
        { (yyvsp[-4].nd_obj).nd = buildNode(NULL, NULL, (yyvsp[-4].nd_obj).dt); (yyval.nd_obj).nd = buildNode((yyvsp[-4].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "="); }
#line 1443 "y.tab.c"
    break;

  case 34: /* expr: ICONSTANT  */
#line 131 "PS_CG_Parser.yacc"
              { newSymbol('I', (yyvsp[0].nd_obj).dt); }
#line 1449 "y.tab.c"
    break;

  case 35: /* expr: DCONSTANT  */
#line 132 "PS_CG_Parser.yacc"
                { newSymbol('D', (yyvsp[0].nd_obj).dt); }
#line 1455 "y.tab.c"
    break;

  case 36: /* expr: IDENTIFIER  */
#line 133 "PS_CG_Parser.yacc"
                 { newSymbol('V', (yyvsp[0].nd_obj).dt);}
#line 1461 "y.tab.c"
    break;

  case 40: /* param_list: d_type IDENTIFIER  */
#line 145 "PS_CG_Parser.yacc"
                      { newSymbol('V', (yyvsp[0].nd_obj).dt); }
#line 1467 "y.tab.c"
    break;

  case 41: /* $@4: %empty  */
#line 146 "PS_CG_Parser.yacc"
                       { newSymbol('V', (yyvsp[0].nd_obj).dt); }
#line 1473 "y.tab.c"
    break;


#line 1477 "y.tab.c"

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

#line 158 "PS_CG_Parser.yacc"

extern FILE* yyin;

int main(){
    do{
        yyparse();
        printf("\n\n");
        printf("%-25s %-15s %-15s %-15s\n","SYMBOL", "DATATYPE", "TYPE", "LINE NUMBER");
        printf("___________________________________________________________________________\n\n");

        for(int i=0; i<st_count; i++) {
            if(strcmp(symbolTable[i].use, "ICONSTANT") == 0){
                printf("%-25d %-15s %-15s %-15d\n", symbolTable[i].intval, symbolTable[i].d_type, symbolTable[i].use, symbolTable[i].line_no);
            }
            else if(strcmp(symbolTable[i].use, "DCONSTANT") == 0){
                printf("%-25f %-15s %-15s %-15d\n", symbolTable[i].dubval, symbolTable[i].d_type, symbolTable[i].use, symbolTable[i].line_no);
            }
            else{
                printf("%-25s %-15s %-15s %-15d\n", symbolTable[i].name, symbolTable[i].d_type, symbolTable[i].use, symbolTable[i].line_no);
            }
        }
        for(int i=0;i<st_count;i++) {
            free(symbolTable[i].name);
            free(symbolTable[i].d_type);
            free(symbolTable[i].use);
        }
    }while(!feof(yyin));
    return 0;
}
    void insert(){
        strcpy(useBuff, yytext);
    }

    /* int search_S(char* in){
        for(int i=0; i<st_count; i++){
            if((strcmp(symbolTable[i].use, "ICONSTANT") != 0) && (strcmp(symbolTable[i].use, "DCONSTANT") != 0)){
                if(strcmp(symbolTable[i].name, in)==0){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }

    int search_I(int in){
        for(int i=0; i<st_count; i++){
            if(strcmp(symbolTable[i].use, "ICONSTANT")==0)
            {
                if(symbolTable[i].intval==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }

    int search_D(double in){
         for(int i=0; i<st_count; i++){
            if(strcmp(symbolTable[i].use, "DCONSTANT")==0)
            {
                if(symbolTable[i].dubval==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    } */

    /* void newSymbol_S(char c, char* stringVal){
        if(!search_S(stringVal)){
            switch(c){
                case 'V':
                    symbolTable[st_count].name=strdup(stringVal);
                    symbolTable[st_count].d_type=strdup(useBuff);
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("IDENTIFIER");
                    st_count++;
                    break;
                case 'P':
                    symbolTable[st_count].name=strdup(stringVal);        
                    symbolTable[st_count].d_type=strdup("void");    
                    symbolTable[st_count].line_no=line;    
                    symbolTable[st_count].use=strdup("PROCEDURE");
                    st_count++;
                    break;
                case 'S':
                    symbolTable[st_count].name=strdup(stringVal); 
                    symbolTable[st_count].d_type=strdup("CONST");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("SCONSTANT");
                    st_count++;
                    break;
                case 'F':
                    symbolTable[st_count].name=strdup(stringVal); 
                    symbolTable[st_count].d_type=strdup(useBuff);
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("FUNCTION");
                    st_count++;
                    break;
                case 'M':
                    symbolTable[st_count].name=strdup(stringVal); 
                    symbolTable[st_count].d_type=strdup("N/A");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("PROGRAM");
                    st_count++;
                    break;
            }
        }
    }

    void newSymbol_I(int iconstVal){
        if(!search_I(iconstVal)){
            symbolTable[st_count].intval=iconstVal;
            symbolTable[st_count].d_type=strdup("CONST");
            symbolTable[st_count].line_no=line;
            symbolTable[st_count].use=strdup("ICONSTANT");
            st_count++;
        }
    }

    void newSymbol_D(double dconstVal){
        if(!search_D(dconstVal)){
            symbolTable[st_count].dubval=dconstVal;
            symbolTable[st_count].d_type=strdup("CONST");
            symbolTable[st_count].line_no=line;
            symbolTable[st_count].use=strdup("DCONSTANT");
            st_count++;
        }
    } */


////////////////////////////////// New Symbol Table Stuff //////////////////////////////////////////
    void newSymbol(char c, char* stringVal){
        if(!search(stringVal)){
            switch(c){
                case 'I':
                    symbolTable[st_count].name=strdup(stringVal);        
                    symbolTable[st_count].d_type=strdup("CONST");
                    symbolTable[st_count].line_no=line;    
                    symbolTable[st_count].use=strdup("PROCEDURE");
                    st_count++;
                    break;
                case 'D':
                    symbolTable[st_count].name=strdup(stringVal);   
                    symbolTable[st_count].d_type=strdup("CONST");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("DCONSTANT");
                    st_count++;
                    break;
                case 'V':
                    symbolTable[st_count].name=strdup(stringVal);
                    symbolTable[st_count].d_type=strdup(useBuff);
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("IDENTIFIER");
                    st_count++;
                    break;
                case 'P':
                    symbolTable[st_count].name=strdup(stringVal);        
                    symbolTable[st_count].d_type=strdup("void");    
                    symbolTable[st_count].line_no=line;    
                    symbolTable[st_count].use=strdup("PROCEDURE");
                    st_count++;
                    break;
                case 'S':
                    symbolTable[st_count].name=strdup(stringVal); 
                    symbolTable[st_count].d_type=strdup("CONST");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("SCONSTANT");
                    st_count++;
                    break;
                case 'F':
                    symbolTable[st_count].name=strdup(stringVal); 
                    symbolTable[st_count].d_type=strdup(useBuff);
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("FUNCTION");
                    st_count++;
                    break;
                case 'M':
                    symbolTable[st_count].name=strdup(stringVal); 
                    symbolTable[st_count].d_type=strdup("N/A");
                    symbolTable[st_count].line_no=line;
                    symbolTable[st_count].use=strdup("PROGRAM");
                    st_count++;
                    break;
            }
        }
    }

    int search(char* in){
        for(int i=0; i<st_count; i++){
            if(strcmp(symbolTable[i].name, in)==0){
                return -1;
                break;
            }
        }
        return 0;
    }


////////////////////////////below may need tweaking/////////////////////////////////
    struct node* buildNode( struct node* leftchild, struct node* rightchild, char* token){
        struct node *newnode = (struct node*) malloc(sizeof(struct node));
        char *newstr = (char*) malloc(strlen(token)+1);
        strcpy(newstr, token);
        newnode->leftchild = leftchild;
        newnode->rightchild = rightchild;
        newnode->token = newstr;
        return(newnode);
    }

    void printtree(struct node* tree) {
        printf("\n\n Inorder traversal of the Parse Tree: \n\n");
        printInorder(tree);
        printf("\n\n");
    }

    void printInorder(struct node *tree) {
        int i;
        if (tree->leftchild) {
            printInorder(tree->leftchild);
        }
        printf("%s, ", tree->token);
        if (tree->rightchild) {
            printInorder(tree->rightchild);
        }
    }


