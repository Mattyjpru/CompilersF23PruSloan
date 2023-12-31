/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "PS_CG_Parser.yacc"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include "lex.yy.c"

    int yyerror(char *msg){
        printf("Invalid Program: %s\n", msg);
        exit(0);
    }

    int yylex();
    int yywrap();
    extern char* yytext;
    extern int line;
    extern int yylineno;

    //Symbol Table stuff
    int st_count=0;
    char useBuff[16];
    
    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        int intval;
        float dubval;
        int line_no;
        char* memLoc;
    } symbolTable[48];
    // struct stEntry SymbolTableList[5][48];

    struct stRtnValue{
        char * strVal;
        int intVal;
        double floatVal;
    };

    // Code Gen stuff
    struct node{
        char* token;
        struct node* leftchild;
        struct node* rightchild;
        // char* dataType;
    };
    struct node *head;
////////func protos
    struct node* buildNode(struct node* left, struct node* right, char* token);
    void printtree(struct node* );
    void printInorder(struct node *);
    void insert();
    int search(char*);
    void newSymbol(char, char*);
    void execute(struct node*);
    char* repD(char*, char);
    void walk(struct node*, FILE*);
    char* intIn(int, int, int, FILE*);
    int ST_get_index(char*);
    void assignmentGenerator(int, FILE*);
    void printStatementGenerator(char*, FILE*);
    void printVar(char* memAddress, char* type, FILE* filename);
    


    int SI = 0;
    int IR = 1;
    int FR = 1;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 72 "PS_CG_Parser.yacc"
{
    struct nt1 { 
		char name[100];
        // char dt[100];
		struct node* nd;
	} nd_obj; 
}
/* Line 193 of yacc.c.  */
#line 289 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 302 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNRULES -- Number of states.  */
#define YYNSTATES  92

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    13,    14,    16,    18,    21,
      24,    25,    34,    35,    46,    48,    50,    52,    55,    61,
      67,    73,    79,    85,    91,    97,    98,   103,   106,   107,
     113,   115,   117,   119,   121,   125,   129,   133,   135,   137,
     139,   140,   146
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    -1,    18,     3,    61,    42,
      62,    55,    -1,    -1,    64,    -1,    63,    -1,    64,    62,
      -1,    63,    62,    -1,    -1,    17,     3,    43,    75,    56,
      42,    66,    55,    -1,    -1,    11,    72,     3,    65,    43,
      75,    56,    42,    66,    55,    -1,    67,    -1,    68,    -1,
      70,    -1,    66,    66,    -1,    15,    43,     5,    56,    57,
      -1,    14,    43,     6,    56,    57,    -1,    16,    43,     4,
      56,    57,    -1,    15,    43,     3,    56,    57,    -1,    14,
      43,     3,    56,    57,    -1,    16,    43,     3,    56,    57,
      -1,    15,    43,    73,    56,    57,    -1,    -1,    72,     3,
      69,    57,    -1,    72,    70,    -1,    -1,     3,    71,    26,
      73,    57,    -1,    13,    -1,    23,    -1,     8,    -1,    74,
      -1,    73,    45,    73,    -1,    73,    52,    73,    -1,    43,
      73,    56,    -1,     5,    -1,     6,    -1,     3,    -1,    -1,
      72,     3,    76,    32,    75,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    93,    93,    95,    95,   100,   103,   104,   105,   106,
     107,   110,   115,   115,   121,   122,   123,   124,   128,   132,
     136,   140,   144,   148,   152,   159,   159,   163,   167,   167,
     175,   176,   177,   181,   182,   184,   186,   191,   192,   193,
     197,   197,   201
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "SCONSTANT", "ICONSTANT",
  "DCONSTANT", "K_DO", "K_DOUBLE", "K_ELSE", "K_EXIT", "K_FUNCTION",
  "K_IF", "K_INTEGER", "K_PRINT_DOUBLE", "K_PRINT_INTEGER",
  "K_PRINT_STRING", "K_PROCEDURE", "K_PROGRAM", "K_READ_DOUBLE",
  "K_READ_INTEGER", "K_READ_STRING", "K_RETURN", "K_STRING", "K_THEN",
  "K_WHILE", "ASSIGN", "ASSIGN_PLUS", "ASSIGN_MINUS", "ASSIGN_MULTIPLY",
  "ASSIGN_DIVIDE", "ASSIGN_MOD", "COMMA", "COMMENT", "DAND", "DIVIDE",
  "DOR", "DEQ", "GEQ", "GT", "LBRACKET", "LEQ", "LCURLY", "LPAREN", "LT",
  "MINUS", "DECREMENT", "MOD", "MULTIPLY", "NE", "NOT", "PERIOD", "PLUS",
  "INCREMENT", "RBRACKET", "RCURLY", "RPAREN", "SEMI", "$accept",
  "statement", "program", "@1", "task", "procedure", "function", "@2",
  "block", "print", "var", "@3", "assignment", "@4", "d_type", "expr",
  "value", "param_list", "@5", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    61,    60,    60,    62,    62,    62,    62,
      62,    63,    65,    64,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    69,    68,    68,    71,    70,
      72,    72,    72,    73,    73,    73,    73,    74,    74,    74,
      76,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     6,     0,     1,     1,     2,     2,
       0,     8,     0,    10,     1,     1,     1,     2,     5,     5,
       5,     5,     5,     5,     5,     0,     4,     2,     0,     5,
       1,     1,     1,     1,     3,     3,     3,     1,     1,     1,
       0,     5,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     2,     3,     1,     0,    10,     0,     0,
       0,     7,     6,    32,    30,    31,     0,     0,     4,     9,
       8,    12,    42,     0,     0,     0,    42,    40,     0,     0,
       0,     0,     0,    42,    28,     0,     0,     0,     0,    14,
      15,    16,     0,     0,    41,     0,     0,     0,     0,    11,
      17,    25,    27,     0,     0,     0,     0,    39,    37,    38,
       0,     0,    33,     0,     0,     0,    13,    39,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    29,    22,    19,    21,    18,    36,    34,    35,    24,
      23,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,    10,    11,    12,    23,    50,    39,
      40,    65,    41,    45,    42,    61,    62,    25,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int8 yypact[] =
{
     -16,     4,    28,   -28,   -28,   -28,   -11,    44,    27,    35,
       2,    44,    44,   -28,   -28,   -28,    66,    29,   -28,   -28,
     -28,   -28,    27,    30,    67,    15,    27,   -28,    32,    19,
      45,    31,    34,    27,   -28,    36,    37,    38,    -3,   -28,
     -28,   -28,    75,    31,   -28,    57,     0,    16,    62,   -28,
      31,    58,   -28,     1,    20,    26,    33,    39,    40,   -28,
      20,     6,   -28,    41,    42,    43,   -28,   -28,   -28,   -15,
      46,    47,    48,    49,     8,    20,    20,    50,    51,    52,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,   -28,   -28,    56,   -28,   -28,   -28,    -2,   -28,
     -28,   -28,    59,   -28,    10,   -27,   -28,   -25,   -28
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -29
static const yytype_int8 yytable[] =
{
      34,    29,     1,    55,    34,    13,    56,     4,    44,    13,
      14,    35,    36,    37,    14,    35,    36,    37,    16,    57,
      15,    58,    59,    67,    15,    68,    59,    69,     5,    38,
      75,     7,    24,    74,    34,    13,    24,    76,    17,    13,
      14,    53,    81,    24,    14,    35,    36,    37,    87,    88,
      15,    75,    49,    75,    15,     8,    66,    18,    76,    60,
      76,     9,    77,    60,    86,    63,    64,    19,    20,    21,
      27,    28,    22,    26,    31,    32,    43,    33,    51,    46,
      47,    48,    70,    54,   -28,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,    72,    73,    78,    79,     0,
      80,    52,     0,    82,    83,    84,    85,    89,    90,    91
};

static const yytype_int8 yycheck[] =
{
       3,    26,    18,     3,     3,     8,     6,     3,    33,     8,
      13,    14,    15,    16,    13,    14,    15,    16,     8,     3,
      23,     5,     6,     3,    23,     5,     6,    54,     0,    31,
      45,    42,    22,    60,     3,     8,    26,    52,     3,     8,
      13,    43,    57,    33,    13,    14,    15,    16,    75,    76,
      23,    45,    55,    45,    23,    11,    55,    55,    52,    43,
      52,    17,    56,    43,    56,     3,     4,    11,    12,     3,
       3,    56,    43,    43,    42,    56,    42,    32,     3,    43,
      43,    43,    56,    26,    26,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    56,    56,    56,    56,    -1,
      57,    42,    -1,    57,    57,    57,    57,    57,    57,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    59,    60,     3,     0,    61,    42,    11,    17,
      62,    63,    64,     8,    13,    23,    72,     3,    55,    62,
      62,     3,    43,    65,    72,    75,    43,     3,    56,    75,
      76,    42,    56,    32,     3,    14,    15,    16,    66,    67,
      68,    70,    72,    42,    75,    71,    43,    43,    43,    55,
      66,     3,    70,    66,    26,     3,     6,     3,     5,     6,
      43,    73,    74,     3,     4,    69,    55,     3,     5,    73,
      56,    56,    56,    56,    73,    45,    52,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    56,    73,    73,    57,
      57,    57
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 93 "PS_CG_Parser.yacc"
    { printf("Valid Program\n"); execute(head);}
    break;

  case 3:
#line 95 "PS_CG_Parser.yacc"
    {newSymbol('M', (yyvsp[(2) - (2)].nd_obj).name);}
    break;

  case 4:
#line 96 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd=buildNode( (yyvsp[(5) - (6)].nd_obj).nd, NULL, (yyvsp[(2) - (6)].nd_obj).name);
        head = (yyval.nd_obj).nd; 
    }
    break;

  case 6:
#line 103 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = buildNode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "task");}
    break;

  case 7:
#line 104 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = buildNode((yyvsp[(1) - (1)].nd_obj).nd, NULL, "task");}
    break;

  case 8:
#line 105 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = buildNode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "task");}
    break;

  case 9:
#line 106 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = buildNode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "task");}
    break;

  case 11:
#line 111 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode((yyvsp[(4) - (8)].nd_obj).nd, (yyvsp[(7) - (8)].nd_obj).nd, (yyvsp[(2) - (8)].nd_obj).name);
    }
    break;

  case 12:
#line 115 "PS_CG_Parser.yacc"
    {newSymbol('V', (yyvsp[(3) - (3)].nd_obj).name);}
    break;

  case 13:
#line 116 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode((yyvsp[(6) - (10)].nd_obj).nd, (yyvsp[(9) - (10)].nd_obj).nd, (yyvsp[(3) - (10)].nd_obj).name);
    }
    break;

  case 14:
#line 121 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 15:
#line 122 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 16:
#line 123 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 17:
#line 124 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = buildNode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "blocks");}
    break;

  case 18:
#line 129 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj).name), buildNode(NULL, NULL, (yyvsp[(3) - (5)].nd_obj).name), "print statement");
    }
    break;

  case 19:
#line 133 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj).name), buildNode(NULL, NULL, (yyvsp[(3) - (5)].nd_obj).name), "print statement");
    }
    break;

  case 20:
#line 137 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj).name), buildNode(NULL, NULL, (yyvsp[(3) - (5)].nd_obj).name), "print statement");
    }
    break;

  case 21:
#line 141 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj).name), buildNode(NULL, NULL, (yyvsp[(3) - (5)].nd_obj).name), "print statement");
    }
    break;

  case 22:
#line 145 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj).name), buildNode(NULL, NULL, (yyvsp[(3) - (5)].nd_obj).name), "print statement");
    }
    break;

  case 23:
#line 149 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj).name), buildNode(NULL, NULL, (yyvsp[(3) - (5)].nd_obj).name), "print statement");
    }
    break;

  case 24:
#line 153 "PS_CG_Parser.yacc"
    {
       (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj).name), (yyvsp[(3) - (5)].nd_obj).nd, "print statement");
    }
    break;

  case 25:
#line 159 "PS_CG_Parser.yacc"
    {newSymbol('V', (yyvsp[(2) - (2)].nd_obj).name);}
    break;

  case 26:
#line 160 "PS_CG_Parser.yacc"
    {
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(2) - (4)].nd_obj).name), NULL, "variable declaration");
    }
    break;

  case 27:
#line 163 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = (yyvsp[(2) - (2)].nd_obj).nd;}
    break;

  case 28:
#line 167 "PS_CG_Parser.yacc"
    {newSymbol('V', (yyvsp[(1) - (1)].nd_obj).name);}
    break;

  case 29:
#line 168 "PS_CG_Parser.yacc"
    { 
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(1) - (5)].nd_obj).name), (yyvsp[(4) - (5)].nd_obj).nd, "="); 
    }
    break;

  case 30:
#line 175 "PS_CG_Parser.yacc"
    {insert(); (yyval.nd_obj).nd = buildNode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name); }
    break;

  case 31:
#line 176 "PS_CG_Parser.yacc"
    {insert(); (yyval.nd_obj).nd = buildNode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name); }
    break;

  case 32:
#line 177 "PS_CG_Parser.yacc"
    {insert(); (yyval.nd_obj).nd = buildNode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name); }
    break;

  case 33:
#line 181 "PS_CG_Parser.yacc"
    { (yyval.nd_obj).nd = (yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 34:
#line 182 "PS_CG_Parser.yacc"
    { (yyval.nd_obj).nd = buildNode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).name); }
    break;

  case 35:
#line 184 "PS_CG_Parser.yacc"
    { (yyval.nd_obj).nd = buildNode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(3) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).name); }
    break;

  case 36:
#line 186 "PS_CG_Parser.yacc"
    { (yyval.nd_obj).nd = (yyvsp[(2) - (3)].nd_obj).nd; }
    break;

  case 37:
#line 191 "PS_CG_Parser.yacc"
    { newSymbol('I', (yyvsp[(1) - (1)].nd_obj).name); (yyval.nd_obj).nd = buildNode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name); }
    break;

  case 38:
#line 192 "PS_CG_Parser.yacc"
    { newSymbol('D', (yyvsp[(1) - (1)].nd_obj).name); (yyval.nd_obj).nd = buildNode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name); }
    break;

  case 39:
#line 193 "PS_CG_Parser.yacc"
    { newSymbol('V', (yyvsp[(1) - (1)].nd_obj).name); (yyval.nd_obj).nd = buildNode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name); }
    break;

  case 40:
#line 197 "PS_CG_Parser.yacc"
    { newSymbol('V', (yyvsp[(2) - (2)].nd_obj).name); }
    break;

  case 41:
#line 198 "PS_CG_Parser.yacc"
    { 
        (yyval.nd_obj).nd = buildNode(buildNode(NULL, NULL, (yyvsp[(2) - (5)].nd_obj).name), (yyvsp[(5) - (5)].nd_obj).nd, "Parameter List");
    }
    break;

  case 42:
#line 201 "PS_CG_Parser.yacc"
    {(yyval.nd_obj).nd = NULL;}
    break;


/* Line 1267 of yacc.c.  */
#line 1804 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 212 "PS_CG_Parser.yacc"

extern FILE* yyin;

int main(){
    do{
        yyparse();
        printf("\n\n");
        /* printf("%-25s %-15s %-15s %-15s\n","SYMBOL", "DATATYPE", "TYPE", "LINE NUMBER");
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
        } */
        for(int i=0;i<st_count;i++) {
            free(symbolTable[i].name);
            free(symbolTable[i].d_type);
            free(symbolTable[i].use);
            free(symbolTable[i].memLoc);
        }
    }while(!feof(yyin));
    /* printf("\n\n");
    printtree(head); 
    printf("\n\n"); */
    return 0;
}
void insert(){
    strcpy(useBuff, yytext);
}

////////////////////////// Function to replace the d to e in double strings /////////////////////////
char* repD(char* str, char target){
    char* here=strchr(str,target);
    while(here){
        *here='e';
        here=strchr(here, target);
    }
    return str;
}

////////////////////////////////// New Symbol Table Stuff //////////////////////////////////////////
void newSymbol(char c, char* stringVal){
    if(!search(stringVal)){
        switch(c){
            case 'I':
                symbolTable[st_count].name=strdup(stringVal);
                symbolTable[st_count].intval = atoi(stringVal);
                symbolTable[st_count].d_type=strdup("CONST");
                symbolTable[st_count].line_no=line;    
                symbolTable[st_count].use=strdup("ICONSTANT");//this should be ICONSTANT but if i change it to that, it sets the 441 to 0?
                st_count++;
                break;
            case 'D':
                stringVal = strdup(repD(repD(stringVal,'d'),'D'));
                symbolTable[st_count].name=strdup(stringVal);
                symbolTable[st_count].dubval = atof(stringVal);
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


struct node* buildNode( struct node* left, struct node* right, char* token){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    char *newstr = (char*) malloc(strlen(token)+1);
    strcpy(newstr, token);
    newnode->leftchild = left;
    newnode->rightchild = right;
    newnode->token = newstr;
    /* printf("Built a node: %s\n", newstr); */
    return(newnode);
}

void printtree(struct node* tree) {
    printf("\n\n Inorder traversal of the Parse Tree: \n\n");
    printInorder(tree);
    printf("\n\n");
}

void printInorder(struct node *tree) {
    if (tree->leftchild) {
        printInorder(tree->leftchild);
    }
    printf("%s, ", tree->token);
    if (tree->rightchild) {
        printInorder(tree->rightchild);
    }
}


/////////////////////////////////////////code generator because we are bad at linking files/////////////////////////////////////



void execute(struct node* start){//will need to call this in the makeFILE
    FILE* urManeDotH=fopen("yourmain.h", "w+");
    
    fprintf(urManeDotH, "int yourmain() {\n");
    fprintf(urManeDotH, "SR -= %d;\n", st_count);//********
    walk(start, urManeDotH);
    fprintf(urManeDotH, "SR += %d;\n", st_count);//********
    fprintf(urManeDotH, "return 0;\n}");
    fclose(urManeDotH);
    }



void walk(struct node* yesde, FILE* filename){
    /* printf("walk\n"); */
        if(!(yesde->leftchild)&&!(yesde->rightchild)){
            /* printf("leaf\n"); */
        }
        else{
            if (strcmp(yesde->token, "=")==0){
                int varIndex = ST_get_index(yesde->leftchild->token);
                int valueIndex = ST_get_index(yesde->rightchild->token);

                symbolTable[varIndex].intval = symbolTable[valueIndex].intval;

                assignmentGenerator(varIndex, filename);
         
            }
                
            else if (strcmp(yesde->token, "print statement") == 0){
                printStatementGenerator(yesde->rightchild->token, filename);
      
            }
                
            else{
                if (yesde->leftchild) {
                    walk(yesde->leftchild, filename);
                }
                if (yesde->rightchild) {
                    walk(yesde->rightchild, filename);
                }
            }
        }
    }
    
void assignmentGenerator(int index, FILE* filename){//************************************
    if(index == -1){
        printf("THIS IS BAD\n");
        exit(0);
    }
    
    char* location;
    if (strcmp(symbolTable[index].d_type , "integer")==0) {
        location = intIn(symbolTable[index].intval, SI, IR, filename);
        IR++;
        symbolTable[index].memLoc=strdup(location);
        /* printf("%d\n", symbolTable[index].intval); */
    }
    else if(strcmp(symbolTable[index].d_type , "double")==0){
        /* printf("%f\n", symbolTable[index].dubval); */
    }
    else if(strcmp(symbolTable[index].d_type , "string")==0){
        /* printf("%s\n", symbolTable[index].name); */
    }
    free(location);
}

int ST_get_index(char* name){
    for(int i = 0; i < st_count; i++){
        if(strcmp(symbolTable[i].name, name) == 0){
            return i;
        }
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////////////
void printStatementGenerator(char* name, FILE* filename){//************************************

    int index = ST_get_index(name);
    printVar(symbolTable[index].memLoc, symbolTable[index].d_type, filename);
}

char* intIn(int intVal, int sLoc, int irLoc, FILE* filename){
    fprintf(filename,"R[%d] = %d;\n" , irLoc, intVal);
    /* printf("%d integer value is: \n", intVal); */
    fprintf(filename, "F23_Time += 1;\n");
    fprintf(filename, "Mem[SR + %d] = R[%d];\n", sLoc, irLoc);
    
    fprintf(filename, "F23_Time += 20 + 1;\n");
    char* buff;
    buff = malloc(sizeof(char)*20);
    sprintf(buff, "Mem[SR + %d]", sLoc);
    return buff;
    }

void printVar(char* memAddress, char* type, FILE* filename){

    if (strcmp(type , "integer")==0){
        fprintf(filename, "print_int(%s);\n", memAddress);
    }
    if (strcmp(type , "string")==0){
        fprintf(filename, "print_string(%s);\n", memAddress);
    }
    fprintf(filename, "F23_Time += 20 + 1;\n");
}


    
    
