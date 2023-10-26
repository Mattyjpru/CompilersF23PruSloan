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




/* Copy the first part of user declarations.  */
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
    char useBuff[16];
    //Symbol Table stuff

    struct stEntry{
        char* name;
        char* d_type;
        char* use;
        char* val;
        int line_no;
    } symbolTable[48];

    void insert(){
        strcpy(useBuff, yytext);
    }

    int searchS(char* in){
        for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].name, in)==0){
                return -1;
            }
        }
        return 0;
    }

    int searchI(int in){
        for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].use, "ICONSTANT")==0)
            {
                if(symbolTable[i].val==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }

    int searchD(double in){
         for(int i=0; i<st_loc; i++){
            if(strcmp(symbolTable[i].use, "DCONSTANT")==0)
            {
                if(symbolTable[i].val==in){
                    return -1;
                    break;
                }
            }
        }
        return 0;
    }




    void newSymbol(char c){
        switch(c){
            case 'V':

                symbolTable[st_loc].name=yylval.sVal;
                symbolTable[st_loc].d_type=strdup(useBuff);
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("IDENTIFIER");
                st_loc++;
                break;
            case 'P':
                symbolTable[st_loc].name=strdup(yytext);        
                symbolTable[st_loc].d_type=strdup(useBuff);    
                symbolTable[st_loc].line_no=line;    
                symbolTable[st_loc].use=strdup("PROCEDURE");
                st_loc++;
                break;
            case 'I':
                symbolTable[st_loc].name=yylval.iVal;
                symbolTable[st_loc].d_type=strdup("CONST");
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("ICONSTANT");
                st_loc++;
                break;
            case 'D':
                symbolTable[st_loc].name=yylval.dVal;
                symbolTable[st_loc].d_type=strdup("CONST");
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("DCONSTANT");
                st_loc++;
                break;
            case 'S':
                symbolTable[st_loc].name=yylval.sVal;
                symbolTable[st_loc].d_type=strdup("CONST");
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("SCONSTANT");
                st_loc++;
                break;
            case 'F':
                symbolTable[st_loc].name=strdup(yytext);
                symbolTable[st_loc].d_type=strdup(useBuff);
                symbolTable[st_loc].line_no=line;
                symbolTable[st_loc].use=strdup("FUNCTION");
                st_loc++;
                break;

        }
    }


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
#line 118 "PS_ST_Parser.yacc"
{
    int iVal;
    double dVal;
    char  *sVal;
}
/* Line 193 of yacc.c.  */
#line 333 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 346 "y.tab.c"

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
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  134

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
       0,     0,     3,     5,     6,    13,    15,    17,    20,    23,
      24,    34,    35,    36,    46,    47,    48,    60,    61,    62,
      73,    75,    77,    79,    82,    85,    88,    90,    91,    98,
      99,   106,   107,   114,   115,   122,   123,   130,   131,   138,
     144,   145,   150,   153,   154,   155,   162,   163,   164,   171,
     172,   173,   180,   181,   187,   189,   191,   193,   195,   197,
     199,   203,   207,   211,   214,   215,   221
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    60,    -1,    -1,    14,    54,    61,    38,
      62,    51,    -1,    67,    -1,    63,    -1,    62,    67,    -1,
      62,    63,    -1,    -1,    13,    54,    64,    39,    92,    52,
      38,    72,    51,    -1,    -1,    -1,    13,    65,    54,    66,
      39,    52,    38,    72,    51,    -1,    -1,    -1,     7,    68,
      90,    54,    69,    39,    92,    52,    38,    72,    51,    -1,
      -1,    -1,     7,    70,    90,    54,    71,    39,    52,    38,
      72,    51,    -1,    73,    -1,    80,    -1,    82,    -1,    73,
      72,    -1,    80,    72,    -1,    82,    72,    -1,    94,    -1,
      -1,    11,    39,    56,    74,    52,    53,    -1,    -1,    10,
      39,    57,    75,    52,    53,    -1,    -1,    12,    39,    55,
      76,    52,    53,    -1,    -1,    11,    39,    54,    77,    52,
      53,    -1,    -1,    10,    39,    54,    78,    52,    53,    -1,
      -1,    12,    39,    54,    79,    52,    53,    -1,    11,    39,
      91,    52,    53,    -1,    -1,    90,    54,    81,    53,    -1,
      90,    82,    -1,    -1,    -1,    54,    83,    22,    56,    84,
      53,    -1,    -1,    -1,    54,    85,    22,    57,    86,    53,
      -1,    -1,    -1,    54,    87,    22,    55,    88,    53,    -1,
      -1,    54,    89,    22,    91,    53,    -1,     9,    -1,    19,
      -1,     4,    -1,    56,    -1,    57,    -1,    54,    -1,    91,
      41,    91,    -1,    91,    48,    91,    -1,    39,    91,    52,
      -1,    90,    54,    -1,    -1,    90,    54,    93,    28,    92,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   136,   136,   139,   139,   142,   144,   145,   146,   150,
     150,   151,   151,   151,   155,   155,   155,   156,   156,   156,
     160,   162,   164,   166,   168,   170,   172,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   182,   183,
     188,   188,   189,   194,   194,   194,   195,   195,   195,   196,
     196,   196,   197,   197,   202,   203,   204,   208,   209,   210,
     211,   213,   215,   221,   222,   222,   225
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "K_DO", "K_DOUBLE", "K_ELSE", "K_EXIT",
  "K_FUNCTION", "K_IF", "K_INTEGER", "K_PRINT_DOUBLE", "K_PRINT_INTEGER",
  "K_PRINT_STRING", "K_PROCEDURE", "K_PROGRAM", "K_READ_DOUBLE",
  "K_READ_INTEGER", "K_READ_STRING", "K_RETURN", "K_STRING", "K_THEN",
  "K_WHILE", "ASSIGN", "ASSIGN_PLUS", "ASSIGN_MINUS", "ASSIGN_MULTIPLY",
  "ASSIGN_DIVIDE", "ASSIGN_MOD", "COMMA", "COMMENT", "DAND", "DIVIDE",
  "DOR", "DEQ", "GEQ", "GT", "LBRACKET", "LEQ", "LCURLY", "LPAREN", "LT",
  "MINUS", "DECREMENT", "MOD", "MULTIPLY", "NE", "NOT", "PERIOD", "PLUS",
  "INCREMENT", "RBRACKET", "RCURLY", "RPAREN", "SEMI", "IDENTIFIER",
  "SCONSTANT", "ICONSTANT", "DCONSTANT", "$accept", "statement", "program",
  "@1", "task", "procedure", "@2", "@3", "@4", "function", "@5", "@6",
  "@7", "@8", "block", "print", "@9", "@10", "@11", "@12", "@13", "@14",
  "var", "@15", "assignment", "@16", "@17", "@18", "@19", "@20", "@21",
  "@22", "d_type", "expr", "param_list", "@23", "epsilon", 0
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
       0,    58,    59,    61,    60,    62,    62,    62,    62,    64,
      63,    65,    66,    63,    68,    69,    67,    70,    71,    67,
      72,    72,    72,    72,    72,    72,    72,    74,    73,    75,
      73,    76,    73,    77,    73,    78,    73,    79,    73,    73,
      81,    80,    80,    83,    84,    82,    85,    86,    82,    87,
      88,    82,    89,    82,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    92,    93,    92,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     6,     1,     1,     2,     2,     0,
       9,     0,     0,     9,     0,     0,    11,     0,     0,    10,
       1,     1,     1,     2,     2,     2,     1,     0,     6,     0,
       6,     0,     6,     0,     6,     0,     6,     0,     6,     5,
       0,     4,     2,     0,     0,     6,     0,     0,     6,     0,
       0,     6,     0,     5,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     2,     0,     5,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     0,    14,     0,
       0,     6,     5,     0,     0,     9,     0,     4,     8,     7,
      56,    54,    55,     0,     0,     0,    12,    15,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,    66,    66,     0,    66,     0,     0,
       0,     0,    43,     0,    20,    21,    22,     0,    26,     0,
      66,     0,    65,     0,     0,     0,     0,     0,     0,     0,
      10,    23,    24,    25,    40,    42,    13,     0,    19,    35,
      29,     0,    59,    57,    58,     0,    37,    31,     0,     0,
       0,     0,     0,    16,     0,     0,    59,    57,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    47,    50,     0,
      41,     0,     0,    62,     0,     0,    60,    61,    39,     0,
       0,     0,     0,     0,    53,    36,    30,    34,    28,    38,
      32,    45,    48,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,    10,    11,    25,    16,    30,    12,
      13,    31,    14,    32,    53,    54,   100,    95,   105,    99,
      94,   104,    55,    92,    56,    66,   121,    67,   122,    68,
     123,    69,    57,    85,    34,    43,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int8 yypact[] =
{
       0,   -29,    39,   -73,   -73,   -73,     4,    19,   -73,    -8,
      -3,   -73,   -73,    18,    18,   -73,    -7,   -73,   -73,   -73,
     -73,   -73,   -73,     5,     7,    23,   -73,   -73,   -73,    18,
      24,    25,    26,    12,    15,    16,    18,    17,    29,    32,
      33,    20,    35,    46,    -4,    -4,    37,    -4,    18,    38,
      40,    41,   -73,    27,    -4,    -4,    -4,    22,   -73,    30,
      -4,    31,   -73,   -16,   -36,   -42,    61,    62,    63,    64,
     -73,   -73,   -73,   -73,    65,   -73,   -73,    42,   -73,   -73,
     -73,   -23,    36,    43,   -73,     3,   -73,   -73,    34,    44,
      45,   -23,    49,   -73,    47,    51,   -73,   -73,     8,    52,
      53,   -23,   -23,    54,    56,    57,   -73,   -73,   -73,   -13,
     -73,    58,    59,   -73,    60,    66,   -73,   -73,   -73,    67,
      68,    69,    70,    71,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,   -73,   -73,    79,   -73,   -73,   -73,    81,
     -73,   -73,   -73,   -73,    -2,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,    72,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -12,   -72,   -25,   -73,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      20,    23,    24,    81,     8,    21,    49,    50,    51,    98,
       9,    41,    86,    87,     1,    22,    81,    33,    82,   109,
      83,    84,    20,    62,    33,     4,     8,    21,   101,   116,
     117,    96,     9,    97,    84,   102,    33,    22,    79,     5,
     124,    80,     7,    59,   101,    61,    15,    26,    17,   101,
      52,   102,    71,    72,    73,   103,   102,   -64,    77,    27,
     113,    28,    29,    35,    36,    37,    38,    39,    40,    42,
      44,    45,    46,    47,    48,    60,    74,    63,    70,    64,
      65,    76,    78,    88,    89,    90,    91,   -43,   -33,    18,
     106,    19,     0,    93,     0,   -27,     0,     0,     0,   111,
     108,   107,   110,   112,   114,   115,     0,   118,   119,   120,
       0,   125,   126,   127,     0,     0,     0,     0,     0,   128,
     129,   130,   131,   132,   133,     0,     0,     0,     0,    75
};

static const yytype_int8 yycheck[] =
{
       4,    13,    14,    39,     7,     9,    10,    11,    12,    81,
      13,    36,    54,    55,    14,    19,    39,    29,    54,    91,
      56,    57,     4,    48,    36,    54,     7,     9,    41,   101,
     102,    54,    13,    56,    57,    48,    48,    19,    54,     0,
      53,    57,    38,    45,    41,    47,    54,    54,    51,    41,
      54,    48,    54,    55,    56,    52,    48,    28,    60,    54,
      52,    54,    39,    39,    39,    39,    54,    52,    52,    52,
      38,    38,    52,    38,    28,    38,    54,    39,    51,    39,
      39,    51,    51,    22,    22,    22,    22,    22,    52,    10,
      56,    10,    -1,    51,    -1,    52,    -1,    -1,    -1,    52,
      55,    57,    53,    52,    52,    52,    -1,    53,    52,    52,
      -1,    53,    53,    53,    -1,    -1,    -1,    -1,    -1,    53,
      53,    53,    53,    53,    53,    -1,    -1,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    59,    60,    54,     0,    61,    38,     7,    13,
      62,    63,    67,    68,    70,    54,    65,    51,    63,    67,
       4,     9,    19,    90,    90,    64,    54,    54,    54,    39,
      66,    69,    71,    90,    92,    39,    39,    39,    54,    52,
      52,    92,    52,    93,    38,    38,    52,    38,    28,    10,
      11,    12,    54,    72,    73,    80,    82,    90,    94,    72,
      38,    72,    92,    39,    39,    39,    83,    85,    87,    89,
      51,    72,    72,    72,    54,    82,    51,    72,    51,    54,
      57,    39,    54,    56,    57,    91,    54,    55,    22,    22,
      22,    22,    81,    51,    78,    75,    54,    56,    91,    77,
      74,    41,    48,    52,    79,    76,    56,    57,    55,    91,
      53,    52,    52,    52,    52,    52,    91,    91,    53,    52,
      52,    84,    86,    88,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53
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
#line 136 "PS_ST_Parser.yacc"
    { printf("Valid Program\n");
                  exit(0);  }
    break;

  case 3:
#line 139 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 5:
#line 143 "PS_ST_Parser.yacc"
    {newSymbol('F');}
    break;

  case 6:
#line 144 "PS_ST_Parser.yacc"
    {newSymbol('P');}
    break;

  case 7:
#line 145 "PS_ST_Parser.yacc"
    {newSymbol('F');}
    break;

  case 8:
#line 146 "PS_ST_Parser.yacc"
    {newSymbol('P');}
    break;

  case 9:
#line 150 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 11:
#line 151 "PS_ST_Parser.yacc"
    {newSymbol('P');}
    break;

  case 12:
#line 151 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 14:
#line 155 "PS_ST_Parser.yacc"
    {newSymbol('F');}
    break;

  case 15:
#line 155 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 17:
#line 156 "PS_ST_Parser.yacc"
    {newSymbol('F');}
    break;

  case 18:
#line 156 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 20:
#line 161 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 21:
#line 163 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 22:
#line 165 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 23:
#line 167 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 24:
#line 169 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 25:
#line 171 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 26:
#line 173 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 27:
#line 177 "PS_ST_Parser.yacc"
    {newSymbol('I');}
    break;

  case 29:
#line 178 "PS_ST_Parser.yacc"
    {newSymbol('D');}
    break;

  case 31:
#line 179 "PS_ST_Parser.yacc"
    {newSymbol('S');}
    break;

  case 33:
#line 180 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 35:
#line 181 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 37:
#line 182 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 39:
#line 184 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 40:
#line 188 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 42:
#line 190 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 43:
#line 194 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 44:
#line 194 "PS_ST_Parser.yacc"
    {newSymbol('I');}
    break;

  case 46:
#line 195 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 47:
#line 195 "PS_ST_Parser.yacc"
    {newSymbol('D');}
    break;

  case 49:
#line 196 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 50:
#line 196 "PS_ST_Parser.yacc"
    {newSymbol('S');}
    break;

  case 52:
#line 197 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 54:
#line 202 "PS_ST_Parser.yacc"
    {insert();}
    break;

  case 55:
#line 203 "PS_ST_Parser.yacc"
    {insert();}
    break;

  case 56:
#line 204 "PS_ST_Parser.yacc"
    {insert();}
    break;

  case 57:
#line 208 "PS_ST_Parser.yacc"
    {newSymbol('I');}
    break;

  case 58:
#line 209 "PS_ST_Parser.yacc"
    {newSymbol('D');}
    break;

  case 59:
#line 210 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 60:
#line 212 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 61:
#line 214 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 62:
#line 216 "PS_ST_Parser.yacc"
    {printf("!");}
    break;

  case 63:
#line 221 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 64:
#line 222 "PS_ST_Parser.yacc"
    {newSymbol('V');}
    break;

  case 66:
#line 225 "PS_ST_Parser.yacc"
    {printf("!");}
    break;


/* Line 1267 of yacc.c.  */
#line 1904 "y.tab.c"
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


#line 227 "PS_ST_Parser.yacc"


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

