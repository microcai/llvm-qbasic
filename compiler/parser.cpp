/* A Bison parser, made by GNU Bison 2.6.4.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.6.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 358 of yacc.c  */
#line 22 "parser.ypp"


/* Include main header file. */
#include "qbc.h"

extern	StatementAST * program;

extern int yylex (void);
extern int yylex_destroy(void);
extern void yyerror (char *msg);
extern int yylineno;
#define error printf
#define debug printf

/* Types of functions. */
enum {
   ftNONE, ftNUMBER, ftSTRING
};


/* Global variables. */
char *current_function = NULL;  /* name of currently parsed function */
int in_loop = 0;                /* in loop? */

/* Local variables. */
int cfunction_type = 0;			/* C function type */
int continue_corrections = 0;   /* continue corrections */
int function_type = ftNONE;     /* contains function type while parsing function */
int unclosed_dos = 0;           /* unclosed "if" count */
int unclosed_fors = 0;          /* unclosed "for" count */
int unclosed_ifs = 0;           /* unclosed "if" count */
int unclosed_repeats = 0;       /* unclosed "repeat" count */
int unclosed_subs = 0;          /* unclosed subroutine count */
int unclosed_switches = 0;      /* unclosed "switch" count */
int unclosed_whiles = 0;        /* unclosed "while" count */
bool until_eol = false;          /* read to end of line? */
struct cli *cli = NULL;         /* call list items stack (for structure definitions) */
struct cli *next_cli = NULL;    /* used for call list items stack */
struct cli *old_cli = NULL;     /* used for call list items stack */
struct command *cmd = NULL;     /* pointer to a command (for structure definitions) */
struct data *data;              /* current data collection */

/* Sanity check routine. */
void not_inside_loop_or_conditional (char *what) {
   /* Display an error if necessary. */
   if ((unclosed_dos || unclosed_fors || unclosed_repeats || unclosed_whiles) || (unclosed_ifs || unclosed_switches)) {
      if ((unclosed_dos || unclosed_fors || unclosed_repeats || unclosed_whiles) && (unclosed_ifs || unclosed_switches)) {
         error ("cannot %s inside a loop, \"if\" statement, or \"switch\" construct", what);
      }
      else if (unclosed_dos || unclosed_fors || unclosed_repeats || unclosed_whiles) {
         error ("cannot %s inside a loop", what);
      }
      else if (unclosed_ifs || unclosed_switches) {
         error ("cannot %s inside an \"if\" statement or \"switch\" construct", what);
      }
   }

   /* Return. */
   return;
}


/* Line 358 of yacc.c  */
#line 131 "/home/cai/projects/basic/compiler/parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_HOME_CAI_PROJECTS_BASIC_COMPILER_PARSER_HPP_INCLUDED
# define YY_YY_HOME_CAI_PROJECTS_BASIC_COMPILER_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tNUMBER = 258,
     tSTRING = 259,
     tNUMSYM = 260,
     tSTRSYM = 261,
     tSEPARATOR = 262,
     tAND = 263,
     tOR = 264,
     tNOT = 265,
     tEOR = 266,
     tBREAK = 267,
     tCONTINUE = 268,
     tSUB = 269,
     tENDSUB = 270,
     tRETURN = 271,
     tCOMPILE = 272,
     tEXECUTERETURNNUMBER = 273,
     tEXECUTERETURNSTRING = 274,
     tCSUB = 275,
     tFROM = 276,
     tGOTO = 277,
     tGOSUB = 278,
     tLABEL = 279,
     tENABLE = 280,
     tDISABLE = 281,
     tEOPROG = 282,
     tNEWFILE = 283,
     tEXIT = 284,
     tEXPLICIT = 285,
     tFOR = 286,
     tTO = 287,
     tNEXT = 288,
     tSTEP = 289,
     tWHILE = 290,
     tWEND = 291,
     tREPEAT = 292,
     tUNTIL = 293,
     tDO = 294,
     tLOOP = 295,
     tIF = 296,
     tTHEN = 297,
     tELSE = 298,
     tELSEIF = 299,
     tENDIF = 300,
     tAS = 301,
     tLET = 302,
     tDIM = 303,
     tLOCAL = 304,
     tSTATIC = 305,
     tARDIM = 306,
     tARSIZE = 307,
     tINC = 308,
     tDEC = 309,
     tNEQ = 310,
     tLEQ = 311,
     tGEQ = 312,
     tLTN = 313,
     tGTN = 314,
     tEQU = 315,
     tPOW = 316,
     tPRINT = 317,
     tINPUT = 318,
     tLINE = 319,
     tUSING = 320,
     tSTRUCT = 321,
     tENDSTRUCT = 322,
     tSWITCH = 323,
     tSEND = 324,
     tCASE = 325,
     tDEFAULT = 326,
     tDATA = 327,
     tENDDATA = 328,
     tREAD = 329,
     tRESTORE = 330,
     tABS = 331,
     tSIG = 332,
     tRAN = 333,
     tSQR = 334,
     tSQRT = 335,
     tINT = 336,
     tFRAC = 337,
     tMIN = 338,
     tMAX = 339,
     tLEFT = 340,
     tRIGHT = 341,
     tMID = 342,
     tUPPER = 343,
     tLOWER = 344,
     tOPEN = 345,
     tCLOSE = 346,
     tEOF = 347,
     tSEEK = 348,
     tTELL = 349,
     tPEEK = 350,
     tPOKE = 351,
     tSIN = 352,
     tASIN = 353,
     tCOS = 354,
     tACOS = 355,
     tTAN = 356,
     tATAN = 357,
     tEXP = 358,
     tLOG = 359,
     tSTR = 360,
     tCHR = 361,
     tVAL = 362,
     tASC = 363,
     tLEN = 364,
     tSYSTEM = 365,
     tARG = 366,
     tENV = 367,
     tTIME = 368,
     tDATE = 369,
     tTOKEN = 370,
     tTOKENALT = 371,
     tSPLIT = 372,
     tSPLITALT = 373,
     tGLOB = 374,
     tTRIM = 375,
     tLTRIM = 376,
     tRTRIM = 377,
     tINSTR = 378,
     tRINSTR = 379,
     tMOD = 380,
     UPLUS = 381,
     UMINUS = 382
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 374 of yacc.c  */
#line 85 "parser.ypp"

	char *string;         /* quoted string */
	char *symbol;         /* general symbol */
	double number;        /* double number */
	int separator;        /* separator */
	PrintIntroAST *print_intro;
	PrintListAST * print_list;
	NumberExprAST* number_expression;
	StatementAST * statement;
	


/* Line 374 of yacc.c  */
#line 314 "/home/cai/projects/basic/compiler/parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_HOME_CAI_PROJECTS_BASIC_COMPILER_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 377 of yacc.c  */
#line 342 "/home/cai/projects/basic/compiler/parser.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  207
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3370

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  138
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  138
/* YYNRULES -- Number of rules.  */
#define YYNRULES  386
/* YYNRULES -- Number of states.  */
#define YYNSTATES  848

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   382

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   137,     2,     2,     2,     2,
     134,   135,   127,   126,   136,   125,   132,   128,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   133,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     129,   130,   131
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    12,    14,    15,    20,    21,
      23,    25,    27,    30,    33,    35,    37,    39,    41,    43,
      45,    47,    49,    51,    53,    55,    57,    59,    61,    62,
      66,    67,    71,    75,    80,    81,    85,    86,    91,    93,
      96,    99,   102,   107,   109,   112,   117,   124,   127,   132,
     139,   140,   144,   145,   149,   152,   155,   158,   161,   164,
     169,   172,   173,   179,   180,   186,   187,   194,   197,   200,
     202,   205,   208,   210,   214,   216,   219,   221,   223,   227,
     231,   235,   239,   243,   245,   249,   253,   257,   261,   272,
     281,   290,   299,   303,   305,   307,   309,   311,   313,   315,
     319,   323,   330,   337,   346,   353,   358,   365,   374,   379,
     384,   389,   394,   399,   404,   411,   416,   423,   428,   430,
     432,   437,   442,   443,   449,   450,   455,   456,   461,   464,
     468,   472,   476,   480,   484,   488,   493,   500,   502,   507,
     512,   519,   526,   528,   530,   534,   538,   542,   546,   550,
     554,   557,   560,   564,   568,   572,   576,   580,   584,   586,
     590,   592,   594,   599,   604,   609,   614,   619,   624,   631,
     636,   641,   648,   653,   658,   663,   668,   673,   678,   683,
     687,   694,   701,   706,   711,   716,   723,   732,   739,   748,
     753,   760,   767,   774,   783,   790,   799,   806,   811,   818,
     825,   834,   839,   844,   845,   851,   854,   856,   858,   860,
     864,   868,   870,   872,   874,   876,   878,   880,   882,   886,
     888,   890,   891,   892,   893,   894,   906,   908,   910,   912,
     914,   915,   916,   917,   928,   930,   932,   933,   935,   939,
     941,   943,   945,   947,   949,   953,   955,   957,   959,   961,
     963,   967,   969,   971,   973,   975,   976,   978,   982,   984,
     986,   988,   990,   991,   992,   993,   994,  1009,  1011,  1013,
    1014,  1016,  1017,  1020,  1021,  1022,  1023,  1033,  1035,  1038,
    1040,  1042,  1043,  1044,  1049,  1050,  1051,  1052,  1058,  1059,
    1060,  1066,  1068,  1069,  1072,  1073,  1074,  1075,  1083,  1085,
    1086,  1089,  1090,  1091,  1097,  1099,  1100,  1104,  1105,  1106,
    1107,  1118,  1119,  1120,  1126,  1127,  1133,  1135,  1137,  1139,
    1140,  1143,  1144,  1145,  1146,  1154,  1156,  1158,  1160,  1162,
    1163,  1165,  1169,  1171,  1175,  1181,  1185,  1186,  1190,  1191,
    1196,  1197,  1202,  1203,  1210,  1212,  1213,  1216,  1219,  1224,
    1226,  1228,  1232,  1234,  1238,  1239,  1247,  1248,  1256,  1259,
    1263,  1265,  1268,  1271,  1274,  1277,  1278,  1280,  1284,  1287,
    1294,  1298,  1303,  1307,  1313,  1317,  1323,  1325,  1329,  1332,
    1339,  1343,  1344,  1352,  1356,  1362,  1366
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     139,     0,    -1,   140,    27,    -1,   141,    -1,   140,    28,
     141,    -1,   143,    -1,    -1,   141,     7,   142,   143,    -1,
      -1,   144,    -1,   161,    -1,   162,    -1,    47,   161,    -1,
      47,   162,    -1,   237,    -1,   241,    -1,   221,    -1,   202,
      -1,   232,    -1,   226,    -1,   210,    -1,    12,    -1,    13,
      -1,   182,    -1,   189,    -1,   263,    -1,   176,    -1,   178,
      -1,    -1,    49,   145,   196,    -1,    -1,    50,   146,   198,
      -1,    62,   259,   252,    -1,    62,   259,   252,   133,    -1,
      -1,    63,   147,   253,    -1,    -1,    64,    63,   148,   253,
      -1,    16,    -1,    16,   167,    -1,    16,   164,    -1,    48,
     175,    -1,   110,   134,   164,   135,    -1,    29,    -1,    29,
     167,    -1,    90,   174,   136,   164,    -1,    90,   174,   136,
     164,   136,   164,    -1,    91,   174,    -1,    93,   174,   136,
     167,    -1,    93,   174,   136,   167,   136,   164,    -1,    -1,
      25,   149,   260,    -1,    -1,    26,   150,   260,    -1,    54,
     261,    -1,    53,   262,    -1,    22,   269,    -1,    23,   269,
      -1,    24,   269,    -1,    96,   174,   136,   167,    -1,    17,
     164,    -1,    -1,    18,   134,   151,   180,   135,    -1,    -1,
      19,   134,   152,   180,   135,    -1,    -1,    72,   269,   153,
     214,   154,    73,    -1,    74,   158,    -1,    75,   160,    -1,
     155,    -1,   154,   155,    -1,   156,   214,    -1,   157,    -1,
     156,   136,   157,    -1,     3,    -1,   125,     3,    -1,     4,
      -1,   159,    -1,   158,   136,   159,    -1,   269,    21,   269,
      -1,   272,    21,   269,    -1,   270,    21,   269,    -1,   273,
      21,   269,    -1,   269,    -1,   160,   136,   269,    -1,   269,
      60,   167,    -1,   177,    60,   167,    -1,   272,    60,   164,
      -1,    87,   134,   163,   136,   167,   136,   167,   135,    60,
     164,    -1,    87,   134,   163,   136,   167,   135,    60,   164,
      -1,    85,   134,   163,   136,   167,   135,    60,   164,    -1,
      86,   134,   163,   136,   167,   135,    60,   164,    -1,   179,
      60,   164,    -1,   272,    -1,   273,    -1,   272,    -1,   165,
      -1,   178,    -1,     4,    -1,   164,   126,   164,    -1,   134,
     164,   135,    -1,    85,   134,   164,   136,   167,   135,    -1,
      86,   134,   164,   136,   167,   135,    -1,    87,   134,   164,
     136,   167,   136,   167,   135,    -1,    87,   134,   164,   136,
     167,   135,    -1,   105,   134,   167,   135,    -1,   105,   134,
     167,   136,   164,   135,    -1,   105,   134,   167,   136,   164,
     136,   164,   135,    -1,   106,   134,   167,   135,    -1,    88,
     134,   164,   135,    -1,    89,   134,   164,   135,    -1,   121,
     134,   164,   135,    -1,   122,   134,   164,   135,    -1,   120,
     134,   164,   135,    -1,   116,   134,   163,   136,   164,   135,
      -1,   116,   134,   163,   135,    -1,   118,   134,   163,   136,
     164,   135,    -1,   118,   134,   163,   135,    -1,   114,    -1,
     113,    -1,   111,   134,   167,   135,    -1,   112,   134,   164,
     135,    -1,    -1,    19,   134,   166,   180,   135,    -1,    -1,
     167,     9,   168,   167,    -1,    -1,   167,     8,   169,   167,
      -1,    10,   167,    -1,   167,    60,   167,    -1,   167,    55,
     167,    -1,   167,    58,   167,    -1,   167,    56,   167,    -1,
     167,    59,   167,    -1,   167,    57,   167,    -1,    92,   134,
     174,   135,    -1,   119,   134,   164,   136,   164,   135,    -1,
       3,    -1,    51,   134,   170,   135,    -1,    51,   134,   171,
     135,    -1,    52,   134,   170,   136,   167,   135,    -1,    52,
     134,   171,   136,   167,   135,    -1,   176,    -1,   269,    -1,
     167,   126,   167,    -1,   167,   125,   167,    -1,   167,   127,
     167,    -1,   167,   128,   167,    -1,   167,   129,   167,    -1,
     167,    61,   167,    -1,   125,   167,    -1,   126,   167,    -1,
     164,    60,   164,    -1,   164,    55,   164,    -1,   164,    58,
     164,    -1,   164,    56,   164,    -1,   164,    59,   164,    -1,
     164,    57,   164,    -1,   172,    -1,   134,   167,   135,    -1,
     271,    -1,   275,    -1,    97,   134,   167,   135,    -1,    98,
     134,   167,   135,    -1,    99,   134,   167,   135,    -1,   100,
     134,   167,   135,    -1,   101,   134,   167,   135,    -1,   102,
     134,   167,   135,    -1,   102,   134,   167,   136,   167,   135,
      -1,   103,   134,   167,   135,    -1,   104,   134,   167,   135,
      -1,   104,   134,   167,   136,   167,   135,    -1,    81,   134,
     167,   135,    -1,    79,   134,   167,   135,    -1,    80,   134,
     167,   135,    -1,    82,   134,   167,   135,    -1,    76,   134,
     167,   135,    -1,    77,   134,   167,   135,    -1,    78,   134,
     167,   135,    -1,    78,   134,   135,    -1,    83,   134,   167,
     136,   167,   135,    -1,    84,   134,   167,   136,   167,   135,
      -1,   109,   134,   164,   135,    -1,   107,   134,   164,   135,
      -1,   108,   134,   164,   135,    -1,   123,   134,   164,   136,
     164,   135,    -1,   123,   134,   164,   136,   164,   136,   167,
     135,    -1,   124,   134,   164,   136,   164,   135,    -1,   124,
     134,   164,   136,   164,   136,   167,   135,    -1,   110,   134,
     164,   135,    -1,     8,   134,   167,   136,   167,   135,    -1,
       9,   134,   167,   136,   167,   135,    -1,    11,   134,   167,
     136,   167,   135,    -1,   115,   134,   164,   136,   171,   136,
     164,   135,    -1,   115,   134,   164,   136,   171,   135,    -1,
     117,   134,   164,   136,   171,   136,   164,   135,    -1,   117,
     134,   164,   136,   171,   135,    -1,    90,   134,   164,   135,
      -1,    90,   134,   164,   136,   164,   135,    -1,    90,   134,
     174,   136,   164,   135,    -1,    90,   134,   174,   136,   164,
     136,   164,   135,    -1,    94,   134,   174,   135,    -1,    95,
     134,   174,   135,    -1,    -1,    18,   134,   173,   180,   135,
      -1,   137,   167,    -1,   167,    -1,   270,    -1,   273,    -1,
     175,   136,   270,    -1,   175,   136,   273,    -1,   270,    -1,
     271,    -1,   270,    -1,   273,    -1,   275,    -1,   273,    -1,
     181,    -1,   180,   136,   181,    -1,   164,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    14,   183,   184,   188,   185,   134,
     200,   135,   186,   141,   187,    -1,    27,    -1,    15,    -1,
     269,    -1,   272,    -1,    -1,    -1,    -1,    20,   190,   193,
     191,   134,   194,   135,   192,    21,     4,    -1,   269,    -1,
     272,    -1,    -1,   195,    -1,   194,   136,   195,    -1,   269,
      -1,   272,    -1,   271,    -1,   275,    -1,   197,    -1,   196,
     136,   197,    -1,   269,    -1,   272,    -1,   270,    -1,   273,
      -1,   199,    -1,   198,   136,   199,    -1,   269,    -1,   272,
      -1,   270,    -1,   273,    -1,    -1,   201,    -1,   200,   136,
     201,    -1,   269,    -1,   272,    -1,   271,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    31,   203,   269,    60,   204,   167,
      32,   167,   209,   205,   141,   206,   207,   208,    -1,    27,
      -1,    33,    -1,    -1,   269,    -1,    -1,    34,   167,    -1,
      -1,    -1,    -1,    68,   211,   212,   215,   214,   216,   218,
      69,   213,    -1,     7,    -1,   214,     7,    -1,   167,    -1,
     164,    -1,    -1,    -1,   216,    70,   217,   215,    -1,    -1,
      -1,    -1,    71,     7,   219,   220,   141,    -1,    -1,    -1,
      39,   222,   223,   141,   224,    -1,    27,    -1,    -1,    40,
     225,    -1,    -1,    -1,    -1,    35,   227,   228,   167,   229,
     141,   230,    -1,    27,    -1,    -1,    36,   231,    -1,    -1,
      -1,    37,   233,   234,   141,   235,    -1,    27,    -1,    -1,
      38,   167,   236,    -1,    -1,    -1,    -1,   246,   167,   238,
      42,   141,   239,   248,   247,   240,   245,    -1,    -1,    -1,
     246,   167,   242,   144,   243,    -1,    -1,   246,   167,   244,
     214,   144,    -1,    27,    -1,    45,    -1,    41,    -1,    -1,
      43,   141,    -1,    -1,    -1,    -1,    44,   167,    42,   249,
     141,   250,   248,    -1,   269,    -1,   272,    -1,   270,    -1,
     273,    -1,    -1,   167,    -1,   167,    65,   164,    -1,   164,
      -1,   252,   136,   167,    -1,   252,   136,   167,    65,   164,
      -1,   252,   136,   164,    -1,    -1,   254,   258,   251,    -1,
      -1,   137,   269,   255,   251,    -1,    -1,   137,     3,   256,
     251,    -1,    -1,   137,   134,   167,   135,   257,   251,    -1,
     164,    -1,    -1,   137,   269,    -1,   137,     3,    -1,   137,
     134,   167,   135,    -1,    30,    -1,   269,    -1,   261,   136,
     269,    -1,   269,    -1,   262,   136,   269,    -1,    -1,    66,
     268,   269,   264,   214,   266,    67,    -1,    -1,    66,   268,
     270,   265,   214,   266,    67,    -1,   267,   214,    -1,   266,
     267,   214,    -1,   263,    -1,   268,   269,    -1,   268,   272,
      -1,   268,   270,    -1,   268,   273,    -1,    -1,     5,    -1,
     269,   132,     5,    -1,     5,   134,    -1,   270,   132,     5,
     134,   180,   135,    -1,   270,   132,     5,    -1,   269,   132,
       5,   134,    -1,     5,   134,   135,    -1,   271,   132,     5,
     134,   135,    -1,   271,   132,     5,    -1,   269,   132,     5,
     134,   135,    -1,     6,    -1,   269,   132,     6,    -1,     6,
     134,    -1,   270,   132,     6,   134,   180,   135,    -1,   270,
     132,     6,    -1,    -1,   269,   132,     6,   134,   274,   180,
     135,    -1,     6,   134,   135,    -1,   271,   132,     6,   134,
     135,    -1,   271,   132,     6,    -1,   269,   132,     6,   134,
     135,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   173,   173,   185,   186,   189,   190,   190,   199,   200,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   216,   218,   219,   220,   221,   222,   223,   223,
     224,   224,   225,   232,   237,   237,   238,   238,   239,   242,
     247,   248,   249,   252,   253,   254,   255,   256,   257,   258,
     259,   259,   260,   260,   261,   262,   263,   266,   267,   270,
     271,   272,   272,   275,   275,   276,   276,   277,   278,   281,
     282,   285,   288,   289,   292,   293,   294,   297,   298,   301,
     302,   303,   304,   307,   308,   311,   312,   315,   316,   317,
     318,   319,   320,   325,   326,   329,   330,   331,   332,   333,
     334,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   358,   361,   361,   362,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     397,   400,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   444,   447,   448,   451,   452,   453,
     454,   457,   458,   461,   464,   465,   468,   471,   472,   475,
     476,   479,   479,   481,   484,   479,   493,   496,   499,   502,
     505,   512,   520,   505,   544,   550,   558,   559,   560,   563,
     566,   569,   572,   577,   578,   581,   582,   583,   584,   587,
     588,   591,   592,   593,   594,   597,   598,   599,   602,   603,
     604,   605,   608,   609,   614,   628,   608,   634,   635,   638,
     639,   642,   643,   646,   646,   648,   646,   651,   652,   655,
     656,   659,   660,   660,   664,   665,   665,   665,   668,   668,
     668,   673,   674,   674,   677,   677,   678,   677,   684,   685,
     685,   688,   688,   688,   693,   695,   694,   698,   699,   701,
     698,   705,   706,   705,   707,   707,   711,   712,   715,   718,
     719,   722,   724,   726,   723,   730,   731,   732,   733,   736,
     737,   742,   744,   746,   748,   750,   754,   754,   755,   755,
     756,   756,   757,   757,   760,   764,   769,   770,   771,   774,
     777,   778,   781,   782,   786,   786,   802,   802,   820,   821,
     824,   825,   833,   841,   849,   859,   867,   868,   871,   873,
     874,   875,   878,   881,   882,   883,   886,   887,   890,   891,
     892,   893,   893,   896,   897,   898,   899
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tNUMBER", "tSTRING", "tNUMSYM",
  "tSTRSYM", "tSEPARATOR", "tAND", "tOR", "tNOT", "tEOR", "tBREAK",
  "tCONTINUE", "tSUB", "tENDSUB", "tRETURN", "tCOMPILE",
  "tEXECUTERETURNNUMBER", "tEXECUTERETURNSTRING", "tCSUB", "tFROM",
  "tGOTO", "tGOSUB", "tLABEL", "tENABLE", "tDISABLE", "tEOPROG",
  "tNEWFILE", "tEXIT", "tEXPLICIT", "tFOR", "tTO", "tNEXT", "tSTEP",
  "tWHILE", "tWEND", "tREPEAT", "tUNTIL", "tDO", "tLOOP", "tIF", "tTHEN",
  "tELSE", "tELSEIF", "tENDIF", "tAS", "tLET", "tDIM", "tLOCAL", "tSTATIC",
  "tARDIM", "tARSIZE", "tINC", "tDEC", "tNEQ", "tLEQ", "tGEQ", "tLTN",
  "tGTN", "tEQU", "tPOW", "tPRINT", "tINPUT", "tLINE", "tUSING", "tSTRUCT",
  "tENDSTRUCT", "tSWITCH", "tSEND", "tCASE", "tDEFAULT", "tDATA",
  "tENDDATA", "tREAD", "tRESTORE", "tABS", "tSIG", "tRAN", "tSQR", "tSQRT",
  "tINT", "tFRAC", "tMIN", "tMAX", "tLEFT", "tRIGHT", "tMID", "tUPPER",
  "tLOWER", "tOPEN", "tCLOSE", "tEOF", "tSEEK", "tTELL", "tPEEK", "tPOKE",
  "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG",
  "tSTR", "tCHR", "tVAL", "tASC", "tLEN", "tSYSTEM", "tARG", "tENV",
  "tTIME", "tDATE", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB",
  "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "'-'", "'+'", "'*'",
  "'/'", "tMOD", "UPLUS", "UMINUS", "'.'", "';'", "'('", "')'", "','",
  "'#'", "$accept", "program", "list_of_statement_lists", "statement_list",
  "$@1", "statement", "non_empty_statement", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "data_list", "data_row",
  "data_row_items", "data_item", "read_list", "read_item", "restore_list",
  "number_assignment", "string_assignment", "string_scalar_or_array",
  "string_expression", "string_function", "$@11", "number_expression",
  "$@12", "$@13", "number_arrayref", "string_arrayref", "number_function",
  "$@14", "hashed_number", "dim_list",
  "number_function_or_array_any_params",
  "number_function_or_array_with_params",
  "string_function_or_array_any_params",
  "string_function_or_array_with_params", "call_list", "call_item",
  "function_definition", "$@15", "$@16", "$@17", "$@18", "endsub",
  "function_name", "cfunction_definition", "$@19", "$@20", "$@21",
  "cfunction_name", "cfunction_param_list", "cfunction_param_item",
  "local_list", "local_item", "static_list", "static_item", "param_list",
  "param_item", "for_loop", "$@22", "$@23", "$@24", "$@25", "next",
  "next_symbol", "step_part", "switch_number_or_string", "$@26", "$@27",
  "$@28", "separator_list", "number_or_string", "case_list", "$@29",
  "default", "$@30", "$@31", "do_loop", "$@32", "$@33", "loop", "$@34",
  "while_loop", "$@35", "$@36", "$@37", "wend", "$@38", "repeat_loop",
  "$@39", "$@40", "until", "$@41", "if_clause", "$@42", "$@43", "$@44",
  "short_if", "$@45", "$@46", "$@47", "endif", "if_part", "else_part",
  "elseif_part", "$@48", "$@49", "input", "print_list", "input_body",
  "$@50", "$@51", "$@52", "$@53", "prompt", "print_intro", "option",
  "dec_list", "inc_list", "structure_definition", "$@54", "$@55",
  "structure_definition_parts", "structure_definition_variable", "new_cli",
  "numsym_s", "numsym_a", "numsym_a_no_calls", "strsym_s", "strsym_a",
  "$@56", "strsym_a_no_calls", YY_NULL
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,    45,    43,    42,    47,   380,
     381,   382,    46,    59,    40,    41,    44,    35
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   138,   139,   140,   140,   141,   142,   141,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   145,   144,
     146,   144,   144,   144,   147,   144,   148,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     149,   144,   150,   144,   144,   144,   144,   144,   144,   144,
     144,   151,   144,   152,   144,   153,   144,   144,   144,   154,
     154,   155,   156,   156,   157,   157,   157,   158,   158,   159,
     159,   159,   159,   160,   160,   161,   161,   162,   162,   162,
     162,   162,   162,   163,   163,   164,   164,   164,   164,   164,
     164,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   166,   165,   168,   167,   169,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     170,   171,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   172,   174,   174,   175,   175,   175,
     175,   176,   176,   177,   178,   178,   179,   180,   180,   181,
     181,   183,   184,   185,   186,   182,   187,   187,   188,   188,
     190,   191,   192,   189,   193,   193,   194,   194,   194,   195,
     195,   195,   195,   196,   196,   197,   197,   197,   197,   198,
     198,   199,   199,   199,   199,   200,   200,   200,   201,   201,
     201,   201,   203,   204,   205,   206,   202,   207,   207,   208,
     208,   209,   209,   211,   212,   213,   210,   214,   214,   215,
     215,   216,   217,   216,   218,   219,   220,   218,   222,   223,
     221,   224,   225,   224,   227,   228,   229,   226,   230,   231,
     230,   233,   234,   232,   235,   236,   235,   238,   239,   240,
     237,   242,   243,   241,   244,   241,   245,   245,   246,   247,
     247,   248,   249,   250,   248,   251,   251,   251,   251,   252,
     252,   252,   252,   252,   252,   252,   254,   253,   255,   253,
     256,   253,   257,   253,   258,   259,   259,   259,   259,   260,
     261,   261,   262,   262,   264,   263,   265,   263,   266,   266,
     267,   267,   267,   267,   267,   268,   269,   269,   270,   270,
     270,   270,   271,   271,   271,   271,   272,   272,   273,   273,
     273,   274,   273,   275,   275,   275,   275
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     1,     0,     4,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       0,     3,     3,     4,     0,     3,     0,     4,     1,     2,
       2,     2,     4,     1,     2,     4,     6,     2,     4,     6,
       0,     3,     0,     3,     2,     2,     2,     2,     2,     4,
       2,     0,     5,     0,     5,     0,     6,     2,     2,     1,
       2,     2,     1,     3,     1,     2,     1,     1,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,    10,     8,
       8,     8,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     6,     6,     8,     6,     4,     6,     8,     4,     4,
       4,     4,     4,     4,     6,     4,     6,     4,     1,     1,
       4,     4,     0,     5,     0,     4,     0,     4,     2,     3,
       3,     3,     3,     3,     3,     4,     6,     1,     4,     4,
       6,     6,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     1,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     3,
       6,     6,     4,     4,     4,     6,     8,     6,     8,     4,
       6,     6,     6,     8,     6,     8,     6,     4,     6,     6,
       8,     4,     4,     0,     5,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     0,     0,     0,     0,    11,     1,     1,     1,     1,
       0,     0,     0,    10,     1,     1,     0,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     0,     1,     3,     1,     1,
       1,     1,     0,     0,     0,     0,    14,     1,     1,     0,
       1,     0,     2,     0,     0,     0,     9,     1,     2,     1,
       1,     0,     0,     4,     0,     0,     0,     5,     0,     0,
       5,     1,     0,     2,     0,     0,     0,     7,     1,     0,
       2,     0,     0,     5,     1,     0,     3,     0,     0,     0,
      10,     0,     0,     5,     0,     5,     1,     1,     1,     0,
       2,     0,     0,     0,     7,     1,     1,     1,     1,     0,
       1,     3,     1,     3,     5,     3,     0,     3,     0,     4,
       0,     4,     0,     6,     1,     0,     2,     2,     4,     1,
       1,     3,     1,     3,     0,     7,     0,     7,     2,     3,
       1,     2,     2,     2,     2,     0,     1,     3,     2,     6,
       3,     4,     3,     5,     3,     5,     1,     3,     2,     6,
       3,     0,     7,     3,     5,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       8,   366,   376,    21,    22,   221,    38,     0,     0,     0,
     230,     0,     0,     0,    50,    52,    43,   262,   294,   301,
     288,   318,     0,     0,    28,    30,     0,     0,   345,    34,
       0,   365,   273,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,     9,    10,
      11,    26,     0,    27,     0,    23,    24,    17,    20,    16,
      19,    18,    14,    15,     0,    25,     0,   211,   212,     0,
     214,   215,   368,   378,   222,   137,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     118,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    96,    39,   158,   142,    97,
     143,   211,    95,   214,     0,    60,     0,     0,     0,    61,
      63,     0,   366,    56,    57,    58,     0,     0,     0,    44,
       0,   295,   302,   289,   366,   376,    12,    13,     0,   213,
     216,     0,    41,     0,   207,   208,     0,     0,    55,   352,
      54,   350,     0,   329,   336,    36,     0,   274,    65,    67,
      77,     0,     0,     0,     0,    68,    83,     0,     0,     0,
       0,   206,     0,    47,     0,     0,     0,     1,     2,     8,
       6,     0,     0,   311,     0,     0,     0,     0,     0,   372,
     383,     0,     0,     0,   128,     0,   203,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   124,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   376,   231,   234,   235,     0,   349,    51,    53,
       0,     0,     8,     8,   368,   378,     0,     0,     0,    29,
     243,   245,   247,   246,   248,    31,   249,   251,   253,   252,
     254,     0,     0,   347,     0,   346,   332,   330,    32,     0,
      35,     0,   336,   354,   356,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,     0,   205,
       0,     0,     0,     0,     4,     8,    86,    92,     0,     0,
       0,    85,   367,   377,   370,   380,   374,   385,    87,   223,
     228,   229,     0,     0,     0,     0,     0,   366,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,   179,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   159,   153,   155,   157,   154,   156,   152,
      99,     0,     0,   130,   132,   134,   131,   133,   129,   149,
     145,   144,   146,   147,   148,   219,   220,     0,   217,     0,
       0,     0,   367,   263,   296,     0,     0,   367,   377,   209,
     210,     0,     0,     0,   353,   351,     0,     0,    33,     0,
     340,     0,   338,   344,     0,    37,     0,     0,     0,     0,
     280,   279,     0,   277,     0,    78,    79,    81,    80,    82,
      84,     0,     0,     0,    45,    48,    59,    42,     7,     8,
     312,     0,   371,   381,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,     0,     0,
       0,   176,   177,   178,   173,   174,   172,   175,     0,     0,
       0,     0,     0,   109,   110,   197,     0,     0,   135,   201,
     202,   162,   163,   164,   165,   166,   167,     0,   169,   170,
       0,   105,     0,   108,   183,   184,   182,   189,   120,   121,
       0,   115,     0,     0,   117,     0,     0,   113,   111,   112,
       0,     0,   127,   125,    62,     0,    64,   236,   377,     0,
       8,   304,     0,   303,   291,   292,   290,   371,   381,   244,
     250,   348,   331,   335,   333,     0,     0,     0,   337,   325,
     327,   326,   328,   365,   365,   281,    74,    76,   278,     0,
       0,    69,     0,    72,     0,     0,     0,     0,     0,   308,
     313,   315,   375,   386,     0,     0,     0,   373,   384,   255,
       0,     0,     0,   204,   123,   367,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   218,   376,     0,   237,
     239,   241,   240,   242,     0,     0,   305,   293,     0,   341,
     342,   339,   360,   365,     0,     0,   365,   284,    75,    66,
      70,     0,    71,     0,     0,     0,     0,    46,    49,   321,
       0,   369,   379,     0,   256,   258,   260,   259,   261,   190,
     191,   192,     0,     0,   140,   141,   180,   181,   101,   102,
     104,     0,   198,   199,     0,   168,   171,   106,     0,   194,
       0,   114,   196,     0,   116,   136,   185,     0,   187,     0,
     232,     0,     0,     0,   298,   299,   297,   306,   334,     0,
     355,     0,   358,   361,   363,   362,   364,   357,   282,     0,
       0,    73,     0,     0,     0,     0,     0,   319,   382,   224,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
     377,   271,   300,   343,   359,     0,   285,   275,    90,    91,
      89,     0,     0,     8,   309,     8,   257,   103,   200,   107,
     193,   195,   186,   188,     0,     0,   264,   283,   286,   276,
       0,   322,   320,     0,     0,   233,   272,     8,     8,    88,
       8,   316,   317,   310,   227,   226,   225,   265,   287,   323,
       0,   321,   267,   268,   269,   324,   266,   270
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    44,    45,    46,   365,    47,    48,   176,   177,   184,
     342,   156,   157,   300,   301,   346,   630,   631,   632,   633,
     189,   190,   195,    49,    50,   353,   158,   135,   386,   201,
     452,   451,   389,   390,   137,   385,   202,   172,   138,    52,
     139,    54,   467,   468,    55,    74,   221,   528,   805,   836,
     379,    56,   151,   470,   788,   303,   678,   679,   319,   320,
     325,   326,   713,   714,    57,   160,   599,   827,   840,   844,
     846,   816,    58,   187,   345,   819,   504,   502,   697,   795,
     770,   818,   828,    59,   163,   313,   606,   687,    60,   161,
     311,   600,   756,   792,    61,   162,   312,   603,   757,    62,
     368,   709,   823,    63,   369,   640,   370,   833,    64,   804,
     777,   830,   841,   618,   338,   340,   341,   617,   615,   759,
     494,   183,   308,   180,   178,    65,   497,   499,   693,   694,
     695,   140,   141,    68,   142,   143,   644,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -610
static const yytype_int16 yypact[] =
{
    3260,   -94,   -83,  -610,  -610,  -610,  2523,   569,   -48,   -46,
    -610,    96,    96,    96,  -610,  -610,  2523,  -610,  -610,  -610,
    -610,  -610,    93,   133,  -610,  -610,    96,    96,   -34,  -610,
     131,  -610,  -610,    96,   164,    96,    66,    92,   104,  2192,
    2192,  2192,  2192,   123,   196,   217,   308,  -610,  -610,  -610,
    -610,  -610,   202,  -610,   238,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  2523,  -610,   -43,   -17,   204,   280,
     298,  -610,   228,   231,  -610,  -610,  -610,   262,   279,  2523,
     287,   301,   313,   327,   339,   354,   356,   362,   365,   384,
     386,   388,   391,   397,   421,   426,   447,   453,   455,   470,
     482,   488,   489,   491,   495,   502,   505,   510,   513,   514,
     516,   517,   519,   532,   535,   536,   537,   539,   542,  -610,
    -610,   550,   552,   558,   559,   560,   562,   563,   567,   568,
     573,  2523,  2523,  2523,   374,  -610,  2099,  -610,  -610,  -610,
     310,   353,  -610,  -610,   569,   259,   310,   353,   204,  -610,
    -610,   291,  -610,   395,   395,   395,   610,   610,   374,  2099,
      96,  -610,  -610,  -610,   574,   575,  -610,  -610,    -7,   353,
    -610,   575,   529,   579,   353,  -610,   164,   164,   576,   395,
     577,   395,    25,  2523,   509,  -610,   709,  -610,   395,   580,
    -610,     4,     8,   694,   696,   582,   395,   164,   164,   164,
    2523,  2099,   583,  -610,   585,   587,   569,  -610,  -610,  3260,
    -610,  2523,   569,    62,  2523,   337,   393,   410,   569,  -610,
    -610,   291,  2523,  2523,   351,  2523,  -610,  -610,   414,   414,
    2523,  2523,  2390,  2523,  2523,  2523,  2523,  2523,  2523,   569,
     569,   569,   569,   569,  2192,  2192,  2192,  2192,  2523,  2523,
    2523,  2523,  2523,  2523,  2523,  2523,  2523,  2523,   569,   569,
     569,   569,  2523,   569,   569,   164,   569,   164,   569,   569,
     569,   569,   569,   569,   659,   659,   233,   195,   569,   569,
     569,   569,   569,   569,   569,  -610,  -610,  2523,  2523,  2523,
    2523,  2523,  2523,  2523,  2523,  2523,  2523,  2523,  2523,   -70,
    2523,  2523,  -610,  -610,   593,  -610,   721,  -610,  -610,  -610,
      -6,  2523,  3260,  3260,  -610,  -610,   435,   133,   454,   591,
    -610,   601,   353,  -610,  -610,   599,  -610,   601,   353,  -610,
    -610,    96,    96,  -610,  2523,   395,   374,  1995,   -49,    33,
    -610,   569,   509,   604,   605,  2523,   732,   164,    96,    96,
      96,    96,    96,   608,   601,  -610,  -610,   609,   611,  2099,
     569,  2523,  2523,   -62,   308,  3260,  2099,   259,   704,  3260,
     732,  2099,   614,   616,   618,   619,   620,   621,   259,  -610,
     593,  -610,   483,   907,   994,  2523,  2523,   622,   624,   627,
     628,   617,   204,  -610,   629,   633,  1031,  1227,  -610,  1290,
    1315,  1453,  1494,  1507,  1015,  1051,   -87,   -26,   -20,    31,
      67,    19,   641,   643,   644,   649,  1539,  1551,  1650,  1690,
    1705,    36,  1786,   175,   506,  1950,    85,   211,   229,   251,
    1971,   252,     6,   139,    69,   373,   101,   253,   254,   255,
     173,   208,  -610,  -610,   259,   259,   259,   259,   259,   259,
    -610,  2523,  2523,   603,   247,   736,    88,   378,   467,  -610,
      46,    46,   659,   659,   659,   374,  2099,   375,  -610,   377,
     630,   511,  -610,  -610,  2099,    45,    41,   654,   655,   353,
    -610,   655,   164,   164,   395,   395,  1984,   569,  -610,  2523,
    -610,  2523,   395,   259,   164,  -610,   785,   732,   786,   732,
     374,  2099,   732,  -610,    43,  -610,   395,   395,   395,   395,
     395,  2523,  2523,  2523,   209,  1186,  2099,  -610,  -610,  3260,
    -610,  3171,   663,   664,  2523,  2523,   666,   669,   672,  2523,
    2523,  2523,   394,   398,   228,   231,  -610,  -610,   531,  2523,
    2523,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  2523,  2523,
    2523,  2523,  2523,  -610,  -610,  -610,   569,   569,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  2523,  -610,  -610,
    2523,  -610,   569,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
     414,  -610,   569,   414,  -610,   569,   569,  -610,  -610,  -610,
     569,   569,   351,     2,  -610,  2523,  -610,   541,  -610,  2523,
    3260,  -610,  2523,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,   259,   374,  2946,   164,  2006,   164,  -610,   601,
     353,  -610,  -610,    14,    14,   800,  -610,  -610,  -610,   805,
      12,  -610,    -2,  -610,  2196,  2324,   778,   569,   569,   308,
    -610,  -610,  -610,  -610,  2523,   413,   416,  -610,  -610,   541,
    2527,  2642,  2655,  -610,  -610,   675,   676,  2666,  2677,  2696,
    2777,  2788,  2799,   881,   266,   151,  2810,  2821,   159,   423,
     267,   433,   269,   288,   190,   192,  -610,   624,   441,  -610,
     679,   204,  -610,  -610,  2957,   174,  2099,  -610,   569,  -610,
    -610,  -610,  -610,   504,   732,   164,   512,   528,  -610,  -610,
    -610,    28,   800,   752,   755,   756,  2523,   259,   259,   773,
     466,  -610,  -610,   478,  -610,   679,   204,  -610,  -610,  -610,
    -610,  -610,   663,   664,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  2523,  -610,  -610,   569,  -610,  -610,  -610,   569,  -610,
     569,  -610,  -610,   569,  -610,  -610,  -610,  2523,  -610,  2523,
    -610,   541,   615,  2523,  -610,  -610,  -610,  -610,   259,   164,
    -610,   732,   800,   601,   353,  -610,  -610,  -610,  -610,   811,
     750,  -610,   569,   569,   569,  2832,  2523,   781,  -610,  -610,
     541,  2913,   336,   346,   349,   360,  2924,  2935,   804,  -610,
     676,  3035,  -610,  -610,   800,  2523,  -610,  -610,   259,   259,
     259,   761,  3046,  3260,  -610,  3260,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,   822,  2523,  -610,  -610,  -610,  -610,
     569,  -610,   308,    10,    75,  -610,  2099,  3260,  3260,   259,
    3260,  -610,  -610,  -610,  -610,  -610,  -610,   308,   308,   308,
     125,   773,  -610,  -610,    96,  -610,  -610,   395
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -610,  -610,  -610,  -200,  -610,   464,  -365,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,   201,  -610,   140,
    -610,   485,  -610,   818,   820,  -132,   949,  -610,  -610,  1639,
    -610,  -610,   623,  -226,  -610,  -610,   -22,  -610,   105,  -610,
     124,  -610,  -277,   248,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,    94,  -610,   364,
    -610,   367,  -610,    73,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -356,    52,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
      13,  -610,  -610,  -609,  -610,   515,  -610,  -610,  -610,  -610,
    -610,  -610,   698,  -610,  -610,  -582,  -610,  -610,   232,  -447,
     827,     0,   185,  1217,   501,   584,  -610,  -227
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -315
static const yytype_int16 yytable[] =
{
      66,   393,   393,   395,   520,   503,   689,   146,   691,   364,
     285,   153,   154,   155,   521,   626,   627,   214,   203,   204,
     205,   628,   168,   173,   469,   348,   179,   181,   333,   349,
     152,   626,   627,   188,   191,   196,   490,   831,   152,   284,
      72,   692,   692,  -213,   285,   286,   626,   627,   210,   550,
     628,    73,   210,   214,   473,   832,   284,   287,   288,   289,
     290,   291,   292,   293,   284,   442,   357,   358,   604,  -314,
     285,   286,   601,   517,   278,   279,   280,   281,   282,   283,
      31,   605,   210,   602,   488,   699,   149,   489,   150,   215,
     834,   287,   288,   289,   290,   291,   292,   293,   164,   165,
     284,   152,   835,   182,  -307,    51,   284,   293,   532,   533,
     551,   692,   475,   476,   692,   216,   552,   287,   288,   289,
     290,   291,   292,   293,    53,   316,   306,   294,   295,   296,
     297,   298,   284,   433,   701,   435,   316,   629,   164,   171,
     216,   623,   580,   624,   146,   284,   625,   291,   292,   293,
     793,   304,   842,   629,   555,   556,   641,   284,   843,   334,
     310,   294,   295,   296,   297,   298,   553,   491,   629,   164,
     165,   566,   567,   296,   297,   298,   321,   327,    36,    37,
      38,   210,   335,   285,   286,    67,   343,   294,   295,   296,
     297,   298,   147,   284,   185,   284,   207,   354,   354,   354,
     197,   754,   554,   285,   286,   583,   146,   169,   174,    66,
     755,   284,   146,   294,   295,   296,   297,   298,   146,   192,
     574,   380,   412,   413,   414,   415,   198,   284,   391,   391,
     287,   288,   289,   290,   291,   292,   293,   586,   199,   146,
     146,   146,   146,   146,   208,   209,   761,   645,   646,   761,
     287,   288,   289,   290,   291,   292,   293,   206,   146,   146,
     146,   146,   211,   146,   146,   354,   146,   354,   146,   146,
     146,   146,   146,   146,   581,   582,   702,   284,   146,   146,
     146,   146,   146,   146,   146,   284,   733,   734,   278,   279,
     280,   281,   282,   283,   737,   738,   152,   302,   212,   284,
     294,   295,   296,   297,   298,   290,   291,   292,   293,   590,
     569,   570,    66,    66,    51,   210,   284,   173,   284,   639,
     294,   295,   296,   297,   298,   746,   747,   748,   749,   147,
     443,   484,   485,    53,   284,   284,   217,   284,   762,   492,
     218,   146,   372,   373,   591,   637,   575,   191,   506,   507,
     508,   509,   510,   393,   669,   284,   393,   671,  -216,   284,
     146,   322,   328,   219,   576,    66,   220,   710,   442,    66,
     683,   344,   294,   295,   296,   297,   298,   284,   284,   284,
     284,   284,   147,   147,   147,   284,   577,   579,   587,   588,
     589,   147,   284,   284,    67,   284,   222,   147,   374,   375,
     685,   732,   741,   147,   744,   794,   287,   288,   289,   290,
     291,   292,   293,   223,   284,   376,   377,    51,    51,   387,
     388,   225,   718,   745,   147,   147,   147,   147,   147,   278,
     279,   280,   281,   282,   283,   226,    53,    53,   292,   293,
     477,   478,   215,   147,   147,   147,   147,   227,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   477,
     481,   228,   284,   147,   147,   147,   147,   147,   147,   147,
      51,   808,   284,   229,    51,   284,   294,   295,   296,   297,
     298,   809,   321,   327,   810,   216,   284,   146,   230,    53,
     231,   285,   286,    53,   619,   811,   232,    67,    67,   233,
     284,    69,   479,   294,   295,   296,   297,   298,   584,   585,
     594,   595,   596,   595,   285,   286,   472,   598,   234,    66,
     235,    66,   236,    69,   683,   237,   147,   306,   293,   653,
     595,   238,   192,   654,   595,   193,   655,   656,   287,   288,
     289,   290,   291,   292,   293,   147,   387,   677,   711,   595,
      67,   712,   595,   718,    67,   239,   146,   146,   739,   740,
     240,   287,   288,   289,   290,   291,   292,   293,   742,   743,
      31,   760,   146,    76,     1,     2,   750,   751,    31,   767,
     391,   241,   146,   391,    70,   146,   146,   242,    82,   243,
     146,   146,   294,   295,   296,   297,   298,   680,   768,   769,
      66,   778,   595,   822,   244,   824,   170,   175,   294,   295,
     296,   297,   298,   779,   780,   619,   245,   619,   194,   529,
     655,   790,   246,   247,    51,   248,    51,   837,   838,   249,
     839,   294,   295,   296,   297,   298,   250,   146,   146,   251,
     307,   571,   572,    53,   252,    53,   339,   253,   254,   715,
     255,   256,   305,   257,    94,    95,    96,    97,    98,   288,
     289,   290,   291,   292,   293,   317,   258,   322,   328,   259,
     260,   261,   147,   262,   111,   112,   263,   323,   329,   620,
     117,   118,   119,   120,   264,   122,   265,   124,   146,   126,
     127,   128,   266,   267,   268,   763,   269,   270,   355,   355,
     355,   271,   272,   144,    67,    51,    67,   273,   314,   315,
      69,   318,   331,   332,   164,   350,   347,   351,   352,   360,
     293,   361,   381,   362,    53,   471,   472,   482,   294,   295,
     296,   297,   298,   316,   146,   483,   496,   498,   146,   503,
     146,   147,   147,   146,   511,   512,   519,   513,   522,   538,
     523,   680,   524,   525,   526,   527,   534,   147,   535,   619,
     324,   330,   536,   537,   597,   539,   355,   147,   355,   540,
     147,   147,   146,   146,   146,   147,   147,   557,   558,   559,
     715,   356,   356,   356,   560,    67,   285,   286,   607,   608,
     477,   374,   288,    70,   290,   291,   292,   293,   642,   643,
     620,   647,   620,    66,   648,    66,   649,   628,   698,   722,
     723,   752,   772,    69,    69,   773,   774,   776,   796,   797,
     146,   820,   147,   147,   803,   814,   825,    66,    66,   518,
      66,   700,   505,   287,   288,   289,   290,   291,   292,   293,
     166,   771,   167,   676,   847,   789,   609,   817,   193,   356,
     610,   356,   394,   806,   845,   309,   696,   495,   186,     0,
       0,   294,   295,   296,   297,   298,    69,     0,     0,     0,
      69,     0,     0,   147,     0,     0,     0,     0,     0,     0,
     764,     0,     0,     0,     0,     0,     0,     0,     0,   285,
     286,     0,     0,     0,     0,     0,    70,    70,     0,     0,
       0,   480,     0,   294,   295,   296,   297,   298,    51,     0,
      51,     0,     0,   705,   706,   285,   286,     0,     0,   147,
       0,     0,     0,   147,     0,   147,     0,    53,   147,    53,
       0,   194,    51,    51,     0,    51,   287,   288,   289,   290,
     291,   292,   293,     0,   620,     0,     0,     0,     0,    70,
       0,    53,    53,    70,    53,   134,   145,   147,   147,   147,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   323,   329,     0,     0,     0,    67,     0,
      67,     0,     0,     0,     0,   621,     0,     0,     0,     0,
       0,     0,   285,   286,     0,   147,   294,   295,   296,   297,
     298,     0,    67,    67,     0,    67,   730,   731,     0,     0,
      69,     0,    69,   285,   286,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,     0,   285,
     286,     0,     0,   530,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,   285,
     286,     0,     0,     0,     0,     0,   324,   330,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,   622,     0,
       0,     0,   276,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,   299,     0,     0,     0,     0,   682,     0,
       0,    69,     0,    70,     0,    70,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,   621,     0,   621,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
     531,     0,   336,     0,     0,     0,     0,     0,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,     0,
     717,   548,     0,     0,     0,   363,   294,   295,   296,   297,
     298,   367,     0,     0,     0,     0,   541,   378,     0,     0,
       0,     0,     0,     0,     0,     0,   294,   295,   296,   297,
     298,     0,     0,     0,    70,     0,     0,   549,   406,   407,
     408,   409,   410,   411,   285,   286,   765,     0,     0,   622,
       0,   622,     0,     0,     0,     0,     0,   426,   427,   428,
     429,     0,   431,   432,     0,   434,     0,   436,   437,   438,
     439,   440,   441,     0,   148,     0,     0,   444,   445,   446,
     447,   448,   449,   450,     0,   285,   286,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,   465,
     465,     0,   682,     0,     0,     0,     0,     0,     0,     0,
     621,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   766,
       0,   717,   287,   288,   289,   290,   291,   292,   293,     0,
     493,     0,     0,     0,   500,     0,     0,     0,   285,   286,
       0,     0,     0,     0,    69,     0,    69,     0,     0,   514,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,     0,   638,   285,   286,     0,     0,     0,    69,    69,
       0,    69,     0,     0,   465,   465,     0,     0,     0,     0,
       0,     0,     0,   622,     0,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   148,   542,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    70,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    70,     0,    70,   294,   295,   296,   297,   298,
       0,     0,     0,   148,     0,   543,     0,     0,     0,   148,
       0,     0,     0,     0,     0,   148,   612,     0,   613,     0,
     294,   295,   296,   297,   298,   392,   392,     0,     0,     0,
     544,     0,     0,     0,     0,     0,   148,   148,   148,   148,
     148,   285,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   465,   465,   148,   148,   148,   148,     0,
     148,   148,     0,   148,     0,   148,   148,   148,   148,   148,
     148,     0,     0,     0,     0,   148,   148,   148,   148,   148,
     148,   148,   285,   286,     0,   664,   665,     0,   287,   288,
     289,   290,   291,   292,   293,   285,   286,     0,     0,     0,
       0,   668,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   670,     0,     0,   672,   673,     0,     0,     0,   674,
     675,     0,     0,     0,   465,     0,     0,   285,   286,   287,
     288,   289,   290,   291,   292,   293,     0,     0,   148,   285,
     286,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   294,   295,
     296,   297,   298,     0,     0,     0,   707,   708,   545,     0,
       0,     0,     0,   465,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,   546,
       0,     0,   294,   295,   296,   297,   298,   758,     0,     0,
       0,     0,   547,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,   285,   286,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,   561,     0,   294,   295,   296,   297,
     298,     0,     0,   782,     0,     0,   562,   783,     0,   784,
       0,     0,   785,     0,     0,     0,     0,     0,   285,   286,
       0,     0,     0,   213,   148,   287,   288,   289,   290,   291,
     292,   293,     0,   285,   286,     0,     0,     0,   224,     0,
       0,   798,   799,   800,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   500,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,   829,
     274,   275,   277,   148,   148,   294,   295,   296,   297,   298,
       0,     0,     0,     0,     0,   563,     0,     0,     0,   148,
       0,     0,     0,     0,   285,   286,     0,   148,     0,   148,
     148,     0,   148,   148,     0,     0,     0,   148,   148,     0,
       0,     0,     0,     0,   681,   294,   295,   296,   297,   298,
       0,     0,   337,     0,     0,   564,     0,     0,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   359,
     565,   287,   288,   289,   290,   291,   292,   293,     0,     0,
     366,     0,     0,   371,   148,   148,     0,     0,     0,     0,
       0,   382,   383,     0,   384,     0,   716,     0,     0,   396,
     397,   399,   400,   401,   402,   403,   404,   405,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,     0,     0,     0,
       0,   430,     0,     0,     0,   148,     0,     0,     0,     0,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,   568,     0,     0,     0,     0,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,     0,   466,
     466,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   148,     0,     0,     0,   148,     0,   148,   285,   286,
     148,     0,     0,     0,     0,     0,     0,     0,   681,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,   285,
     286,     0,     0,     0,   501,     0,     0,     0,     0,   148,
     148,   148,   285,   286,     0,     0,     0,   716,     0,     0,
     515,   516,     0,   285,   286,   287,   288,   289,   290,   291,
     292,   293,     0,     0,   285,   286,     0,     0,     0,     0,
       0,     0,     0,     0,   466,   466,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,   148,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
     487,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,   294,   295,   296,   297,   298,
       0,     0,     0,     0,     0,   573,     0,     0,     0,     0,
     592,   593,     0,     0,     0,     0,   294,   295,   296,   297,
     298,     0,     0,     0,     0,     0,   578,   285,   286,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,   611,
     294,   295,   296,   297,   298,     0,     0,     0,   614,     0,
     616,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,   690,     0,     0,     0,     0,     0,     0,     0,     0,
     634,   635,   636,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,   466,   466,     0,     0,     0,   650,   651,
     652,     0,     0,     0,     0,     0,     0,     0,   657,   658,
       0,     0,     0,     0,     0,     0,     0,   659,   660,   661,
     662,   663,     0,     0,     0,    75,    76,     1,     2,     0,
      77,    78,    79,    80,   285,   286,   666,     0,     0,   667,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,   466,     0,     0,     0,   684,     0,
       0,   686,     0,    83,    84,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   466,   100,     0,   101,   102,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     0,
       0,   294,   295,   296,   297,   298,   133,     0,     0,   200,
       0,   703,   285,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   775,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     781,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,   786,     0,   787,     0,
       0,     0,   791,    75,    76,     1,     2,     0,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,    81,    82,
       0,     0,     0,     0,     0,   802,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,     0,     0,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,   826,     0,     0,     0,     0,   704,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   100,     0,   101,   102,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,     0,
       0,     0,     0,     0,   133,   398,    75,    76,     1,     2,
       0,    77,    78,    79,    80,   285,   286,     0,     0,     0,
       0,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   100,     0,   101,   102,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     285,   286,   294,   295,   296,   297,   298,   133,     0,     0,
       0,     0,   719,   285,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,   285,   286,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,   720,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
     721,   294,   295,   296,   297,   298,   285,   286,     0,     0,
       0,   724,   294,   295,   296,   297,   298,   285,   286,     0,
       0,     0,   725,     0,     0,     0,     0,     0,   285,   286,
       0,   294,   295,   296,   297,   298,     0,     0,     0,   285,
     286,   726,   287,   288,   289,   290,   291,   292,   293,     0,
     285,   286,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,   727,   294,   295,   296,   297,   298,     0,     0,
       0,   285,   286,   728,   294,   295,   296,   297,   298,     0,
       0,     0,   285,   286,   729,   294,   295,   296,   297,   298,
       0,     0,     0,   285,   286,   735,   294,   295,   296,   297,
     298,     0,     0,     0,   285,   286,   736,   294,   295,   296,
     297,   298,     0,     0,     0,   285,   286,   801,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,   753,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,   688,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,   285,   286,     0,     0,     0,   807,   294,
     295,   296,   297,   298,   285,   286,     0,     0,     0,   812,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   815,
     813,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,   821,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,     0,
       0,   294,   295,   296,   297,   298,     1,     2,   628,     0,
       0,     0,     0,     3,     4,     5,     0,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    14,    15,     0,     0,
      16,     0,    17,     0,     0,     0,    18,     0,    19,     0,
      20,     0,    21,     0,     0,     0,     0,     0,    22,    23,
      24,    25,     0,     0,    26,    27,     0,     0,     0,     0,
       0,     0,     0,    28,    29,    30,     0,    31,     0,    32,
       0,     0,     0,    33,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,     0,
       0,    39,    40,     0,    41,     1,     2,    42,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     7,     8,     9,
      10,    43,    11,    12,    13,    14,    15,     0,     0,    16,
       0,    17,     0,     0,     0,    18,     0,    19,     0,    20,
       0,    21,     0,     0,     0,     0,     0,    22,    23,    24,
      25,     0,     0,    26,    27,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,     0,    31,     0,    32,     0,
       0,     0,    33,     0,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,    40,     0,    41,     0,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-610)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,   228,   229,   229,   369,     7,   615,     7,   617,   209,
       8,    11,    12,    13,   370,     3,     4,    60,    40,    41,
      42,     7,    22,    23,   301,    21,    26,    27,     3,    21,
       5,     3,     4,    33,    34,    35,     3,    27,     5,   126,
     134,   623,   624,    60,     8,     9,     3,     4,     7,   136,
       7,   134,     7,    60,    60,    45,   126,    55,    56,    57,
      58,    59,    60,    61,   126,   135,   198,   199,    27,     7,
       8,     9,    27,   135,    55,    56,    57,    58,    59,    60,
      66,    40,     7,    38,   133,    73,   134,   136,   134,   132,
      15,    55,    56,    57,    58,    59,    60,    61,     5,     6,
     126,     5,    27,   137,    42,     0,   126,    61,   385,   386,
     136,   693,   312,   313,   696,   132,   136,    55,    56,    57,
      58,    59,    60,    61,     0,   132,   132,   125,   126,   127,
     128,   129,   126,   265,   136,   267,   132,   125,     5,     6,
     132,   497,   136,   499,   144,   126,   502,    59,    60,    61,
     759,   151,    27,   125,   135,   136,   521,   126,    33,   134,
     160,   125,   126,   127,   128,   129,   135,   134,   125,     5,
       6,   135,   136,   127,   128,   129,   176,   177,    85,    86,
      87,     7,   182,     8,     9,     0,   186,   125,   126,   127,
     128,   129,     7,   126,    63,   126,     0,   197,   198,   199,
     134,    27,   135,     8,     9,   136,   206,    22,    23,   209,
      36,   126,   212,   125,   126,   127,   128,   129,   218,    34,
     135,   221,   244,   245,   246,   247,   134,   126,   228,   229,
      55,    56,    57,    58,    59,    60,    61,   136,   134,   239,
     240,   241,   242,   243,    27,    28,   693,   524,   525,   696,
      55,    56,    57,    58,    59,    60,    61,   134,   258,   259,
     260,   261,    60,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   135,   136,   632,   126,   278,   279,
     280,   281,   282,   283,   284,   126,   135,   136,    55,    56,
      57,    58,    59,    60,   135,   136,     5,     6,    60,   126,
     125,   126,   127,   128,   129,    58,    59,    60,    61,   136,
     135,   136,   312,   313,   209,     7,   126,   317,   126,   519,
     125,   126,   127,   128,   129,   135,   136,   135,   136,   144,
     135,   331,   332,   209,   126,   126,   132,   126,   694,   339,
      60,   341,     5,     6,   136,   136,   135,   347,   348,   349,
     350,   351,   352,   580,   580,   126,   583,   583,    60,   126,
     360,   176,   177,   135,   135,   365,   135,   644,   135,   369,
     597,   186,   125,   126,   127,   128,   129,   126,   126,   126,
     126,   126,   197,   198,   199,   126,   135,   135,   135,   135,
     135,   206,   126,   126,   209,   126,   134,   212,     5,     6,
     600,   135,   135,   218,   135,   761,    55,    56,    57,    58,
      59,    60,    61,   134,   126,     5,     6,   312,   313,     5,
       6,   134,   649,   135,   239,   240,   241,   242,   243,    55,
      56,    57,    58,    59,    60,   134,   312,   313,    60,    61,
       5,     6,   132,   258,   259,   260,   261,   134,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,     5,
       6,   134,   126,   278,   279,   280,   281,   282,   283,   284,
     365,   135,   126,   134,   369,   126,   125,   126,   127,   128,
     129,   135,   482,   483,   135,   132,   126,   487,   134,   365,
     134,     8,     9,   369,   494,   135,   134,   312,   313,   134,
     126,     0,   317,   125,   126,   127,   128,   129,   135,   136,
     135,   136,   135,   136,     8,     9,     5,     6,   134,   519,
     134,   521,   134,    22,   751,   134,   341,   132,    61,   135,
     136,   134,   347,   135,   136,    34,     5,     6,    55,    56,
      57,    58,    59,    60,    61,   360,     5,     6,   135,   136,
     365,   135,   136,   780,   369,   134,   556,   557,   135,   136,
     134,    55,    56,    57,    58,    59,    60,    61,   135,   136,
      66,    67,   572,     4,     5,     6,   135,   136,    66,    67,
     580,   134,   582,   583,     0,   585,   586,   134,    19,   134,
     590,   591,   125,   126,   127,   128,   129,   597,    70,    71,
     600,   135,   136,   803,   134,   805,    22,    23,   125,   126,
     127,   128,   129,   135,   136,   615,   134,   617,    34,   136,
       5,     6,   134,   134,   519,   134,   521,   827,   828,   134,
     830,   125,   126,   127,   128,   129,   134,   637,   638,   134,
      30,   135,   136,   519,   134,   521,   137,   134,   134,   649,
     134,   134,   151,   134,    85,    86,    87,    88,    89,    56,
      57,    58,    59,    60,    61,   136,   134,   482,   483,   134,
     134,   134,   487,   134,   105,   106,   134,   176,   177,   494,
     111,   112,   113,   114,   134,   116,   134,   118,   688,   120,
     121,   122,   134,   134,   134,   695,   134,   134,   197,   198,
     199,   134,   134,   134,   519,   600,   521,   134,   134,   134,
     209,   132,   136,   136,     5,    21,   136,    21,   136,   136,
      61,   136,   221,   136,   600,   132,     5,   136,   125,   126,
     127,   128,   129,   132,   734,   136,   132,   132,   738,     7,
     740,   556,   557,   743,   136,   136,    42,   136,   134,   132,
     134,   751,   134,   134,   134,   134,   134,   572,   134,   759,
     176,   177,   135,   135,   134,   136,   265,   582,   267,   136,
     585,   586,   772,   773,   774,   590,   591,   136,   135,   135,
     780,   197,   198,   199,   135,   600,     8,     9,   134,   134,
       5,     5,    56,   209,    58,    59,    60,    61,   135,   135,
     615,   135,   617,   803,   135,   805,   134,     7,     3,   134,
     134,   132,    60,   312,   313,    60,    60,    44,     7,    69,
     820,    60,   637,   638,    43,    21,     4,   827,   828,   365,
     830,   630,   347,    55,    56,    57,    58,    59,    60,    61,
      22,   701,    22,   595,   844,   751,   482,   795,   347,   265,
     483,   267,   229,   780,   841,   157,   624,   342,    31,    -1,
      -1,   125,   126,   127,   128,   129,   365,    -1,    -1,    -1,
     369,    -1,    -1,   688,    -1,    -1,    -1,    -1,    -1,    -1,
     695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,   312,   313,    -1,    -1,
      -1,   317,    -1,   125,   126,   127,   128,   129,   803,    -1,
     805,    -1,    -1,   135,   136,     8,     9,    -1,    -1,   734,
      -1,    -1,    -1,   738,    -1,   740,    -1,   803,   743,   805,
      -1,   347,   827,   828,    -1,   830,    55,    56,    57,    58,
      59,    60,    61,    -1,   759,    -1,    -1,    -1,    -1,   365,
      -1,   827,   828,   369,   830,     6,     7,   772,   773,   774,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   482,   483,    -1,    -1,    -1,   803,    -1,
     805,    -1,    -1,    -1,    -1,   494,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,   820,   125,   126,   127,   128,
     129,    -1,   827,   828,    -1,   830,   135,   136,    -1,    -1,
     519,    -1,   521,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,     8,
       9,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,   482,   483,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,   494,    -1,
      -1,    -1,   133,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,   144,    -1,    -1,    -1,    -1,   597,    -1,
      -1,   600,    -1,   519,    -1,   521,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,   615,    -1,   617,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
     649,   136,    -1,    -1,    -1,   206,   125,   126,   127,   128,
     129,   212,    -1,    -1,    -1,    -1,   135,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,    -1,   600,    -1,    -1,   136,   239,   240,
     241,   242,   243,   244,     8,     9,   695,    -1,    -1,   615,
      -1,   617,    -1,    -1,    -1,    -1,    -1,   258,   259,   260,
     261,    -1,   263,   264,    -1,   266,    -1,   268,   269,   270,
     271,   272,   273,    -1,     7,    -1,    -1,   278,   279,   280,
     281,   282,   283,   284,    -1,     8,     9,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,   300,
     301,    -1,   751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     759,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   695,
      -1,   780,    55,    56,    57,    58,    59,    60,    61,    -1,
     341,    -1,    -1,    -1,   345,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,   803,    -1,   805,    -1,    -1,   360,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,     8,     9,    -1,    -1,    -1,   827,   828,
      -1,   830,    -1,    -1,   385,   386,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   759,    -1,    55,    56,    57,    58,    59,
      60,    61,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,   144,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   803,    -1,   805,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   827,   828,    -1,   830,   125,   126,   127,   128,   129,
      -1,    -1,    -1,   206,    -1,   135,    -1,    -1,    -1,   212,
      -1,    -1,    -1,    -1,    -1,   218,   487,    -1,   489,    -1,
     125,   126,   127,   128,   129,   228,   229,    -1,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,   239,   240,   241,   242,
     243,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   524,   525,   258,   259,   260,   261,    -1,
     263,   264,    -1,   266,    -1,   268,   269,   270,   271,   272,
     273,    -1,    -1,    -1,    -1,   278,   279,   280,   281,   282,
     283,   284,     8,     9,    -1,   556,   557,    -1,    55,    56,
      57,    58,    59,    60,    61,     8,     9,    -1,    -1,    -1,
      -1,   572,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   582,    -1,    -1,   585,   586,    -1,    -1,    -1,   590,
     591,    -1,    -1,    -1,   595,    -1,    -1,     8,     9,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,   341,     8,
       9,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,   125,   126,
     127,   128,   129,    -1,    -1,    -1,   637,   638,   135,    -1,
      -1,    -1,    -1,   644,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
      -1,    -1,   125,   126,   127,   128,   129,   688,    -1,    -1,
      -1,    -1,   135,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,   135,    -1,   125,   126,   127,   128,
     129,    -1,    -1,   734,    -1,    -1,   135,   738,    -1,   740,
      -1,    -1,   743,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    64,   487,    55,    56,    57,    58,    59,
      60,    61,    -1,     8,     9,    -1,    -1,    -1,    79,    -1,
      -1,   772,   773,   774,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   795,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,   820,
     131,   132,   133,   556,   557,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   572,
      -1,    -1,    -1,    -1,     8,     9,    -1,   580,    -1,   582,
     583,    -1,   585,   586,    -1,    -1,    -1,   590,   591,    -1,
      -1,    -1,    -1,    -1,   597,   125,   126,   127,   128,   129,
      -1,    -1,   183,    -1,    -1,   135,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,   200,
     135,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
     211,    -1,    -1,   214,   637,   638,    -1,    -1,    -1,    -1,
      -1,   222,   223,    -1,   225,    -1,   649,    -1,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,   688,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
     301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     311,   734,    -1,    -1,    -1,   738,    -1,   740,     8,     9,
     743,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   751,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,    -1,    -1,     8,
       9,    -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,   772,
     773,   774,     8,     9,    -1,    -1,    -1,   780,    -1,    -1,
     361,   362,    -1,     8,     9,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,   386,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,   820,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,
     451,   452,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,   135,     8,     9,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     125,   126,   127,   128,   129,    -1,    -1,    -1,   489,    -1,
     491,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,   512,   513,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,   524,   525,    -1,    -1,    -1,   529,   530,
     531,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,   540,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   548,   549,   550,
     551,   552,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,     8,     9,   567,    -1,    -1,   570,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,   595,    -1,    -1,    -1,   599,    -1,
      -1,   602,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   644,    92,    -1,    94,    95,    -1,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    -1,
      -1,   125,   126,   127,   128,   129,   134,    -1,    -1,   137,
      -1,   135,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   706,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,   747,    -1,   749,    -1,
      -1,    -1,   753,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,   776,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   795,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,   129,   815,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    -1,    94,    95,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,     8,     9,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    -1,    94,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       8,     9,   125,   126,   127,   128,   129,   134,    -1,    -1,
      -1,    -1,   135,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,     8,     9,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,
     125,   126,   127,   128,   129,     8,     9,    -1,    -1,    -1,
     135,   125,   126,   127,   128,   129,     8,     9,    -1,    -1,
      -1,   135,   125,   126,   127,   128,   129,     8,     9,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,     8,
       9,   135,    55,    56,    57,    58,    59,    60,    61,    -1,
       8,     9,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,    -1,   135,   125,   126,   127,   128,   129,    -1,    -1,
      -1,     8,     9,   135,   125,   126,   127,   128,   129,    -1,
      -1,    -1,     8,     9,   135,   125,   126,   127,   128,   129,
      -1,    -1,    -1,     8,     9,   135,   125,   126,   127,   128,
     129,    -1,    -1,    -1,     8,     9,   135,   125,   126,   127,
     128,   129,    -1,    -1,    -1,     8,     9,   135,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    32,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    65,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,   129,     8,     9,    -1,    -1,    -1,   135,   125,
     126,   127,   128,   129,     8,     9,    -1,    -1,    -1,   135,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    34,
     135,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    42,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,   129,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    -1,    -1,
      29,    -1,    31,    -1,    -1,    -1,    35,    -1,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    -1,    66,    -1,    68,
      -1,    -1,    -1,    72,    -1,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,
      -1,    90,    91,    -1,    93,     5,     6,    96,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,   110,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    -1,    66,    -1,    68,    -1,
      -1,    -1,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,
      90,    91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     5,     6,    12,    13,    14,    16,    17,    18,    19,
      20,    22,    23,    24,    25,    26,    29,    31,    35,    37,
      39,    41,    47,    48,    49,    50,    53,    54,    62,    63,
      64,    66,    68,    72,    74,    75,    85,    86,    87,    90,
      91,    93,    96,   110,   139,   140,   141,   143,   144,   161,
     162,   176,   177,   178,   179,   182,   189,   202,   210,   221,
     226,   232,   237,   241,   246,   263,   269,   270,   271,   272,
     273,   275,   134,   134,   183,     3,     4,     8,     9,    10,
      11,    18,    19,    51,    52,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      92,    94,    95,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   134,   164,   165,   167,   172,   176,   178,
     269,   270,   272,   273,   134,   164,   269,   270,   271,   134,
     134,   190,     5,   269,   269,   269,   149,   150,   164,   167,
     203,   227,   233,   222,     5,     6,   161,   162,   269,   270,
     273,     6,   175,   269,   270,   273,   145,   146,   262,   269,
     261,   269,   137,   259,   147,    63,   268,   211,   269,   158,
     159,   269,   270,   272,   273,   160,   269,   134,   134,   134,
     137,   167,   174,   174,   174,   174,   134,     0,    27,    28,
       7,    60,    60,   167,    60,   132,   132,   132,    60,   135,
     135,   184,   134,   134,   167,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   167,   167,   164,   167,    55,    56,
      57,    58,    59,    60,   126,     8,     9,    55,    56,    57,
      58,    59,    60,    61,   125,   126,   127,   128,   129,   164,
     151,   152,     6,   193,   269,   272,   132,    30,   260,   260,
     269,   228,   234,   223,   134,   134,   132,   136,   132,   196,
     197,   269,   270,   272,   273,   198,   199,   269,   270,   272,
     273,   136,   136,     3,   134,   269,   164,   167,   252,   137,
     253,   254,   148,   269,   270,   212,   153,   136,    21,    21,
      21,    21,   136,   163,   269,   272,   273,   163,   163,   167,
     136,   136,   136,   164,   141,   142,   167,   164,   238,   242,
     244,   167,     5,     6,     5,     6,     5,     6,   164,   188,
     269,   272,   167,   167,   167,   173,   166,     5,     6,   170,
     171,   269,   271,   275,   170,   171,   167,   167,   135,   167,
     167,   167,   167,   167,   167,   167,   164,   164,   164,   164,
     164,   164,   174,   174,   174,   174,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   164,   164,   164,   164,
     167,   164,   164,   163,   164,   163,   164,   164,   164,   164,
     164,   164,   135,   135,   164,   164,   164,   164,   164,   164,
     164,   169,   168,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   164,   167,   180,   181,   180,
     191,   132,     5,    60,   167,   141,   141,     5,     6,   270,
     273,     6,   136,   136,   269,   269,   167,    65,   133,   136,
       3,   134,   269,   164,   258,   253,   132,   264,   132,   265,
     164,   167,   215,     7,   214,   159,   269,   269,   269,   269,
     269,   136,   136,   136,   164,   167,   167,   135,   143,    42,
     144,   214,   134,   134,   134,   134,   134,   134,   185,   136,
     136,   136,   180,   180,   134,   134,   135,   135,   132,   136,
     136,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     136,   136,   136,   135,   135,   135,   136,   136,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   136,   135,   135,
     136,   135,   136,   135,   135,   135,   135,   135,   135,   135,
     136,   135,   136,   136,   135,   136,   136,   135,   135,   135,
     136,   136,   167,   167,   135,   136,   135,   134,     6,   204,
     229,    27,    38,   235,    27,    40,   224,   134,   134,   197,
     199,   135,   164,   164,   167,   256,   167,   255,   251,   269,
     270,   272,   273,   214,   214,   214,     3,     4,     7,   125,
     154,   155,   156,   157,   167,   167,   167,   136,   136,   141,
     243,   144,   135,   135,   274,   180,   180,   135,   135,   134,
     167,   167,   167,   135,   135,     5,     6,   167,   167,   167,
     167,   167,   167,   167,   164,   164,   167,   167,   164,   171,
     164,   171,   164,   164,   164,   164,   181,     6,   194,   195,
     269,   271,   272,   275,   167,   141,   167,   225,    65,   251,
     135,   251,   263,   266,   267,   268,   266,   216,     3,    73,
     155,   136,   214,   135,   135,   135,   136,   164,   164,   239,
     180,   135,   135,   200,   201,   269,   271,   272,   275,   135,
     135,   135,   134,   134,   135,   135,   135,   135,   135,   135,
     135,   136,   135,   135,   136,   135,   135,   135,   136,   135,
     136,   135,   135,   136,   135,   135,   135,   136,   135,   136,
     135,   136,   132,    32,    27,    36,   230,   236,   164,   257,
      67,   267,   214,   269,   270,   272,   273,    67,    70,    71,
     218,   157,    60,    60,    60,   167,    44,   248,   135,   135,
     136,   167,   164,   164,   164,   164,   167,   167,   192,   195,
       6,   167,   231,   251,   214,   217,     7,    69,   164,   164,
     164,   135,   167,    43,   247,   186,   201,   135,   135,   135,
     135,   135,   135,   135,    21,    34,   209,   215,   219,   213,
      60,    42,   141,   240,   141,     4,   167,   205,   220,   164,
     249,    27,    45,   245,    15,    27,   187,   141,   141,   141,
     206,   250,    27,    33,   207,   248,   208,   269
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YYLVAL_INITIALIZE
# define YYLVAL_INITIALIZE()
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  YYLVAL_INITIALIZE ();
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1813 of yacc.c  */
#line 178 "parser.ypp"
    {
			program = (yyvsp[(1) - (2)].statement);
			debug("program ended\n");
			/*add_command (cEOPROG, NULL);*/ yylex_destroy (); YYACCEPT;
		}
    break;

  case 3:
/* Line 1813 of yacc.c  */
#line 185 "parser.ypp"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); debug("list_of_statement_lists\n"); }
    break;

  case 5:
/* Line 1813 of yacc.c  */
#line 189 "parser.ypp"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement);}
    break;

  case 6:
/* Line 1813 of yacc.c  */
#line 190 "parser.ypp"
    { yylineno += (yyvsp[(2) - (2)].separator); }
    break;

  case 7:
/* Line 1813 of yacc.c  */
#line 190 "parser.ypp"
    {
		if((yyvsp[(4) - (4)].statement)){
			debug("got statement_list now %p\n",(yyvsp[(4) - (4)].statement));
			(yyval.statement) = (yyvsp[(1) - (4)].statement);
			(yyvsp[(1) - (4)].statement)->append((yyvsp[(4) - (4)].statement));
		}
	}
    break;

  case 8:
/* Line 1813 of yacc.c  */
#line 199 "parser.ypp"
    { (yyval.statement) = 0 ;}
    break;

  case 9:
/* Line 1813 of yacc.c  */
#line 200 "parser.ypp"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 21:
/* Line 1813 of yacc.c  */
#line 215 "parser.ypp"
    { /*add_command (cBREAK, NULL); */ if (! (in_loop)) { error ("cannot \"break\" outside of loop"); } }
    break;

  case 22:
/* Line 1813 of yacc.c  */
#line 217 "parser.ypp"
    { /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/ if (! (in_loop)) { error ("cannot \"continue\" outside of loop"); } }
    break;

  case 26:
/* Line 1813 of yacc.c  */
#line 221 "parser.ypp"
    { }
    break;

  case 27:
/* Line 1813 of yacc.c  */
#line 222 "parser.ypp"
    { }
    break;

  case 28:
/* Line 1813 of yacc.c  */
#line 223 "parser.ypp"
    {if (function_type==ftNONE) error("declaring variables \"local\" outside of a function has no effect"); }
    break;

  case 30:
/* Line 1813 of yacc.c  */
#line 224 "parser.ypp"
    {if (function_type==ftNONE) error("declaring variables \"static\" outside of a function has no effect"); }
    break;

  case 32:
/* Line 1813 of yacc.c  */
#line 225 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now\n");
	   //TODO 最后一个是 \new line
	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yyvsp[(2) - (3)].print_intro)),PrintListASTPtr((yyvsp[(3) - (3)].print_list)));
   }
    break;

  case 33:
/* Line 1813 of yacc.c  */
#line 232 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now\n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yyvsp[(2) - (4)].print_intro)),PrintListASTPtr((yyvsp[(3) - (4)].print_list)));
   }
    break;

  case 34:
/* Line 1813 of yacc.c  */
#line 237 "parser.ypp"
    { until_eol = false; }
    break;

  case 35:
/* Line 1813 of yacc.c  */
#line 237 "parser.ypp"
    {}
    break;

  case 36:
/* Line 1813 of yacc.c  */
#line 238 "parser.ypp"
    { until_eol = true; }
    break;

  case 37:
/* Line 1813 of yacc.c  */
#line 238 "parser.ypp"
    {}
    break;

  case 38:
/* Line 1813 of yacc.c  */
#line 239 "parser.ypp"
    {
	   
             }
    break;

  case 39:
/* Line 1813 of yacc.c  */
#line 242 "parser.ypp"
    {

	   
   }
    break;

  case 40:
/* Line 1813 of yacc.c  */
#line 247 "parser.ypp"
    { }
    break;

  case 42:
/* Line 1813 of yacc.c  */
#line 249 "parser.ypp"
    {
	   
}
    break;

  case 43:
/* Line 1813 of yacc.c  */
#line 252 "parser.ypp"
    {}
    break;

  case 44:
/* Line 1813 of yacc.c  */
#line 253 "parser.ypp"
    {}
    break;

  case 45:
/* Line 1813 of yacc.c  */
#line 254 "parser.ypp"
    {}
    break;

  case 46:
/* Line 1813 of yacc.c  */
#line 255 "parser.ypp"
    {}
    break;

  case 47:
/* Line 1813 of yacc.c  */
#line 256 "parser.ypp"
    {}
    break;

  case 48:
/* Line 1813 of yacc.c  */
#line 257 "parser.ypp"
    {}
    break;

  case 49:
/* Line 1813 of yacc.c  */
#line 258 "parser.ypp"
    {}
    break;

  case 50:
/* Line 1813 of yacc.c  */
#line 259 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 52:
/* Line 1813 of yacc.c  */
#line 260 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 56:
/* Line 1813 of yacc.c  */
#line 263 "parser.ypp"
    {

   }
    break;

  case 57:
/* Line 1813 of yacc.c  */
#line 266 "parser.ypp"
    {  }
    break;

  case 58:
/* Line 1813 of yacc.c  */
#line 267 "parser.ypp"
    {

   }
    break;

  case 59:
/* Line 1813 of yacc.c  */
#line 270 "parser.ypp"
    {  }
    break;

  case 60:
/* Line 1813 of yacc.c  */
#line 271 "parser.ypp"
    {  }
    break;

  case 61:
/* Line 1813 of yacc.c  */
#line 272 "parser.ypp"
    {  }
    break;

  case 62:
/* Line 1813 of yacc.c  */
#line 272 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 63:
/* Line 1813 of yacc.c  */
#line 275 "parser.ypp"
    { }
    break;

  case 64:
/* Line 1813 of yacc.c  */
#line 275 "parser.ypp"
    {  }
    break;

  case 65:
/* Line 1813 of yacc.c  */
#line 276 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 74:
/* Line 1813 of yacc.c  */
#line 292 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 75:
/* Line 1813 of yacc.c  */
#line 293 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 76:
/* Line 1813 of yacc.c  */
#line 294 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 79:
/* Line 1813 of yacc.c  */
#line 301 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 80:
/* Line 1813 of yacc.c  */
#line 302 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 1813 of yacc.c  */
#line 303 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 82:
/* Line 1813 of yacc.c  */
#line 304 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 83:
/* Line 1813 of yacc.c  */
#line 307 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 84:
/* Line 1813 of yacc.c  */
#line 308 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 85:
/* Line 1813 of yacc.c  */
#line 311 "parser.ypp"
    {/*add_command(cPOPNUMSYM,dotify($1));*/}
    break;

  case 86:
/* Line 1813 of yacc.c  */
#line 312 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 87:
/* Line 1813 of yacc.c  */
#line 315 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 88:
/* Line 1813 of yacc.c  */
#line 316 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 89:
/* Line 1813 of yacc.c  */
#line 317 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 90:
/* Line 1813 of yacc.c  */
#line 318 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 91:
/* Line 1813 of yacc.c  */
#line 319 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 92:
/* Line 1813 of yacc.c  */
#line 320 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 93:
/* Line 1813 of yacc.c  */
#line 325 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 94:
/* Line 1813 of yacc.c  */
#line 326 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 95:
/* Line 1813 of yacc.c  */
#line 329 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 97:
/* Line 1813 of yacc.c  */
#line 331 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 98:
/* Line 1813 of yacc.c  */
#line 332 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 99:
/* Line 1813 of yacc.c  */
#line 333 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 101:
/* Line 1813 of yacc.c  */
#line 337 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 102:
/* Line 1813 of yacc.c  */
#line 338 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 103:
/* Line 1813 of yacc.c  */
#line 339 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 104:
/* Line 1813 of yacc.c  */
#line 340 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 105:
/* Line 1813 of yacc.c  */
#line 341 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 106:
/* Line 1813 of yacc.c  */
#line 342 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 107:
/* Line 1813 of yacc.c  */
#line 343 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 108:
/* Line 1813 of yacc.c  */
#line 344 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 109:
/* Line 1813 of yacc.c  */
#line 345 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 110:
/* Line 1813 of yacc.c  */
#line 346 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 111:
/* Line 1813 of yacc.c  */
#line 347 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 112:
/* Line 1813 of yacc.c  */
#line 348 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 113:
/* Line 1813 of yacc.c  */
#line 349 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 114:
/* Line 1813 of yacc.c  */
#line 350 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 115:
/* Line 1813 of yacc.c  */
#line 351 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 116:
/* Line 1813 of yacc.c  */
#line 352 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 117:
/* Line 1813 of yacc.c  */
#line 353 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 118:
/* Line 1813 of yacc.c  */
#line 354 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 119:
/* Line 1813 of yacc.c  */
#line 355 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 120:
/* Line 1813 of yacc.c  */
#line 356 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 121:
/* Line 1813 of yacc.c  */
#line 357 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 122:
/* Line 1813 of yacc.c  */
#line 358 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 123:
/* Line 1813 of yacc.c  */
#line 358 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 124:
/* Line 1813 of yacc.c  */
#line 361 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 125:
/* Line 1813 of yacc.c  */
#line 361 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 126:
/* Line 1813 of yacc.c  */
#line 362 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 127:
/* Line 1813 of yacc.c  */
#line 362 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 128:
/* Line 1813 of yacc.c  */
#line 363 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 129:
/* Line 1813 of yacc.c  */
#line 364 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 130:
/* Line 1813 of yacc.c  */
#line 365 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 131:
/* Line 1813 of yacc.c  */
#line 366 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 132:
/* Line 1813 of yacc.c  */
#line 367 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 133:
/* Line 1813 of yacc.c  */
#line 368 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 134:
/* Line 1813 of yacc.c  */
#line 369 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 135:
/* Line 1813 of yacc.c  */
#line 370 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 136:
/* Line 1813 of yacc.c  */
#line 371 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 137:
/* Line 1813 of yacc.c  */
#line 372 "parser.ypp"
    { (yyval.number_expression) = new ConstNumberExprAST((yyvsp[(1) - (1)].number));  }
    break;

  case 138:
/* Line 1813 of yacc.c  */
#line 373 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 139:
/* Line 1813 of yacc.c  */
#line 374 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 140:
/* Line 1813 of yacc.c  */
#line 375 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 141:
/* Line 1813 of yacc.c  */
#line 376 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 142:
/* Line 1813 of yacc.c  */
#line 377 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 143:
/* Line 1813 of yacc.c  */
#line 378 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify($1));*/}
    break;

  case 144:
/* Line 1813 of yacc.c  */
#line 379 "parser.ypp"
    {/*create_numbin('+');*/}
    break;

  case 145:
/* Line 1813 of yacc.c  */
#line 380 "parser.ypp"
    {/*create_numbin('-');*/}
    break;

  case 146:
/* Line 1813 of yacc.c  */
#line 381 "parser.ypp"
    {/*create_numbin('*');*/}
    break;

  case 147:
/* Line 1813 of yacc.c  */
#line 382 "parser.ypp"
    {/*create_numbin('/');*/}
    break;

  case 148:
/* Line 1813 of yacc.c  */
#line 383 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 149:
/* Line 1813 of yacc.c  */
#line 384 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 150:
/* Line 1813 of yacc.c  */
#line 385 "parser.ypp"
    { /*add_command(cNEGATE,NULL);*/ }
    break;

  case 151:
/* Line 1813 of yacc.c  */
#line 386 "parser.ypp"
    { /* do nothing */ }
    break;

  case 152:
/* Line 1813 of yacc.c  */
#line 387 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 153:
/* Line 1813 of yacc.c  */
#line 388 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 154:
/* Line 1813 of yacc.c  */
#line 389 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 155:
/* Line 1813 of yacc.c  */
#line 390 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 156:
/* Line 1813 of yacc.c  */
#line 391 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 157:
/* Line 1813 of yacc.c  */
#line 392 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 160:
/* Line 1813 of yacc.c  */
#line 397 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 161:
/* Line 1813 of yacc.c  */
#line 400 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 162:
/* Line 1813 of yacc.c  */
#line 403 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 163:
/* Line 1813 of yacc.c  */
#line 404 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 164:
/* Line 1813 of yacc.c  */
#line 405 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 165:
/* Line 1813 of yacc.c  */
#line 406 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 166:
/* Line 1813 of yacc.c  */
#line 407 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 167:
/* Line 1813 of yacc.c  */
#line 408 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 168:
/* Line 1813 of yacc.c  */
#line 409 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 169:
/* Line 1813 of yacc.c  */
#line 410 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 170:
/* Line 1813 of yacc.c  */
#line 411 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 171:
/* Line 1813 of yacc.c  */
#line 412 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 172:
/* Line 1813 of yacc.c  */
#line 413 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 173:
/* Line 1813 of yacc.c  */
#line 414 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 174:
/* Line 1813 of yacc.c  */
#line 415 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 175:
/* Line 1813 of yacc.c  */
#line 416 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 176:
/* Line 1813 of yacc.c  */
#line 417 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 177:
/* Line 1813 of yacc.c  */
#line 418 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 178:
/* Line 1813 of yacc.c  */
#line 419 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 179:
/* Line 1813 of yacc.c  */
#line 420 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 180:
/* Line 1813 of yacc.c  */
#line 421 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 181:
/* Line 1813 of yacc.c  */
#line 422 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 182:
/* Line 1813 of yacc.c  */
#line 423 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 183:
/* Line 1813 of yacc.c  */
#line 424 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 184:
/* Line 1813 of yacc.c  */
#line 425 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 185:
/* Line 1813 of yacc.c  */
#line 426 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 186:
/* Line 1813 of yacc.c  */
#line 427 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 187:
/* Line 1813 of yacc.c  */
#line 428 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 188:
/* Line 1813 of yacc.c  */
#line 429 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 189:
/* Line 1813 of yacc.c  */
#line 430 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 190:
/* Line 1813 of yacc.c  */
#line 431 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 191:
/* Line 1813 of yacc.c  */
#line 432 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 192:
/* Line 1813 of yacc.c  */
#line 433 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 193:
/* Line 1813 of yacc.c  */
#line 434 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 194:
/* Line 1813 of yacc.c  */
#line 435 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 195:
/* Line 1813 of yacc.c  */
#line 436 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 196:
/* Line 1813 of yacc.c  */
#line 437 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 197:
/* Line 1813 of yacc.c  */
#line 438 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 198:
/* Line 1813 of yacc.c  */
#line 439 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 199:
/* Line 1813 of yacc.c  */
#line 440 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 200:
/* Line 1813 of yacc.c  */
#line 441 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 201:
/* Line 1813 of yacc.c  */
#line 442 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 202:
/* Line 1813 of yacc.c  */
#line 443 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 203:
/* Line 1813 of yacc.c  */
#line 444 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 204:
/* Line 1813 of yacc.c  */
#line 444 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 207:
/* Line 1813 of yacc.c  */
#line 451 "parser.ypp"
    {/*create_dim(dotify($1),'N');*/}
    break;

  case 208:
/* Line 1813 of yacc.c  */
#line 452 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 209:
/* Line 1813 of yacc.c  */
#line 453 "parser.ypp"
    {/*create_dim(dotify($3),'N');*/}
    break;

  case 210:
/* Line 1813 of yacc.c  */
#line 454 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 211:
/* Line 1813 of yacc.c  */
#line 457 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 212:
/* Line 1813 of yacc.c  */
#line 458 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 213:
/* Line 1813 of yacc.c  */
#line 461 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 214:
/* Line 1813 of yacc.c  */
#line 464 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 215:
/* Line 1813 of yacc.c  */
#line 465 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 216:
/* Line 1813 of yacc.c  */
#line 468 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 217:
/* Line 1813 of yacc.c  */
#line 471 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 218:
/* Line 1813 of yacc.c  */
#line 472 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 221:
/* Line 1813 of yacc.c  */
#line 479 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 222:
/* Line 1813 of yacc.c  */
#line 479 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
if (function_type!=ftNONE) {error("functions cannot be nested");}}
    break;

  case 223:
/* Line 1813 of yacc.c  */
#line 481 "parser.ypp"
    {
	   
}
    break;

  case 224:
/* Line 1813 of yacc.c  */
#line 484 "parser.ypp"
    {
	   
}
    break;

  case 225:
/* Line 1813 of yacc.c  */
#line 488 "parser.ypp"
    {
	
   }
    break;

  case 226:
/* Line 1813 of yacc.c  */
#line 493 "parser.ypp"
    {
	//if (unclosed_subs) { error ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : ""); }
	}
    break;

  case 227:
/* Line 1813 of yacc.c  */
#line 496 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 228:
/* Line 1813 of yacc.c  */
#line 499 "parser.ypp"
    {
	//function_type=ftNUMBER;current_function = dotify ($1); $$ = dotify ($1);
	}
    break;

  case 229:
/* Line 1813 of yacc.c  */
#line 502 "parser.ypp"
    {/*function_type=ftSTRING;current_function = dotify ($1); $$ = dotify ($1);*/}
    break;

  case 230:
/* Line 1813 of yacc.c  */
#line 505 "parser.ypp"
    {
//                          not_inside_loop_or_conditional ("define a module function");
//                          if (function_type != ftNONE) {
//                             error ("a module function may not be defined inside another function");
//                          }
//                          pushlabel();
                      }
    break;

  case 231:
/* Line 1813 of yacc.c  */
#line 512 "parser.ypp"
    {
//                          create_label (dotify ($3), cUSER_FUNCTION);
//                          add_command (cPUSHSYMLIST, NULL);
//                          add_command (cCLEARREFS, NULL);
//                          firstref = lastcmd;
//                          lastref = lastcmd;
//                          create_numparam ();
                      }
    break;

  case 232:
/* Line 1813 of yacc.c  */
#line 520 "parser.ypp"
    {
//                          create_require (stFREE);
//                          add_command (cPOP, NULL);
                      }
    break;

  case 233:
/* Line 1813 of yacc.c  */
#line 524 "parser.ypp"
    {
//                          add_command (cCALL_EXTERNAL, $3);
//                          add_command (cCLEARREFS, NULL);
//                          lastcmd->nextref = firstref;
//                          add_command (cPOPSYMLIST, NULL);
//                          create_retval (function_type, function_type);
//                          function_type = ftNONE;
//                          add_command (cRET_FROM_FUN, NULL);
//                          lastref = NULL;
//                          create_endfunction ();
//                          poplabel ();
//                          module = yabmod_load_module ($10);
//                          if (module == NULL) error ("could not load module \"%s\"", $10);
//                          cfunction = yabmod_load_cfunction (module, $3, cfunction_type);
//                          if (cfunction == NULL)
//								error ("could not load function \"%s\" from module \"%s\"", $3, $10);
//                          cfunction_type = YABMOD_INTERFACE_TYPE_NONE;
                      }
    break;

  case 234:
/* Line 1813 of yacc.c  */
#line 544 "parser.ypp"
    {
//                    function_type = ftNUMBER;
//                    cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_NUMBER;
//                    current_function = mystrdup ($1);
//                    $$ = mystrdup ($1);
                }
    break;

  case 235:
/* Line 1813 of yacc.c  */
#line 550 "parser.ypp"
    {
//         function_type = ftSTRING;
//         cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_STRING;
//         current_function = mystrdup ($1);
//         $$ = mystrdup ($1);
     }
    break;

  case 239:
/* Line 1813 of yacc.c  */
#line 563 "parser.ypp"
    {
//                          create_require (stNUMBER); create_makelocal (dotify ($1), syNUMBER); add_command (cPOPNUMSYM, dotify ($1));
                      }
    break;

  case 240:
/* Line 1813 of yacc.c  */
#line 566 "parser.ypp"
    {
//         create_require (stSTRING); create_makelocal (dotify ($1), sySTRING); add_command (cPOPSTRSYM, dotify ($1));
     }
    break;

  case 241:
/* Line 1813 of yacc.c  */
#line 569 "parser.ypp"
    {
//         create_require (stNUMBERARRAYREF); create_arraylink (dotify ($1), stNUMBERARRAYREF);
     }
    break;

  case 242:
/* Line 1813 of yacc.c  */
#line 572 "parser.ypp"
    {
//         create_require (stSTRINGARRAYREF); create_arraylink (dotify ($1), stSTRINGARRAYREF);
     }
    break;

  case 245:
/* Line 1813 of yacc.c  */
#line 581 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 246:
/* Line 1813 of yacc.c  */
#line 582 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 247:
/* Line 1813 of yacc.c  */
#line 583 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 248:
/* Line 1813 of yacc.c  */
#line 584 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 251:
/* Line 1813 of yacc.c  */
#line 591 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 252:
/* Line 1813 of yacc.c  */
#line 592 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 253:
/* Line 1813 of yacc.c  */
#line 593 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 254:
/* Line 1813 of yacc.c  */
#line 594 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 258:
/* Line 1813 of yacc.c  */
#line 602 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 259:
/* Line 1813 of yacc.c  */
#line 603 "parser.ypp"
    {/*create_require(stSTRING);create_makelocal(dotify ($1),sySTRING);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 260:
/* Line 1813 of yacc.c  */
#line 604 "parser.ypp"
    {/*create_require(stNUMBERARRAYREF);create_arraylink(dotify ($1),stNUMBERARRAYREF);*/}
    break;

  case 261:
/* Line 1813 of yacc.c  */
#line 605 "parser.ypp"
    {/*create_require(stSTRINGARRAYREF);create_arraylink(dotify ($1),stSTRINGARRAYREF);*/}
    break;

  case 262:
/* Line 1813 of yacc.c  */
#line 608 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 263:
/* Line 1813 of yacc.c  */
#line 609 "parser.ypp"
    { /*pushname (dotify ($3));    /* used to check for symbol match */
//              add_command(cRESETSKIPONCE,NULL);
// //         pushgoto();add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);
			}
    break;

  case 264:
/* Line 1813 of yacc.c  */
#line 614 "parser.ypp"
    { /* pushes another number expression */
//         add_command(cSKIPONCE,NULL);
//         pushlabel();
//         add_command(cSTARTFOR,NULL);
//         add_command(cPOPNUMSYM,dotify ($3));
//         poplabel();
//         add_command(cPUSHNUMSYM,dotify ($3));
//         add_command(cFORINCREMENT,NULL);
//         add_command(cPOPNUMSYM,dotify ($3));
//         add_command(cPUSHNUMSYM,dotify ($3));
//         add_command(cFORCHECK,NULL);
//         add_command(cDECIDE,NULL);
//              pushlabel();
	 }
    break;

  case 265:
/* Line 1813 of yacc.c  */
#line 628 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 266:
/* Line 1813 of yacc.c  */
#line 630 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 267:
/* Line 1813 of yacc.c  */
#line 634 "parser.ypp"
    {if (unclosed_fors) { error ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : ""); } }
    break;

  case 268:
/* Line 1813 of yacc.c  */
#line 635 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 269:
/* Line 1813 of yacc.c  */
#line 638 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 270:
/* Line 1813 of yacc.c  */
#line 639 "parser.ypp"
    { /*if (strcmp (pop (stSTRING)->pointer, dotify ($1)) != 0) */{ error ("symbols used for \"for\" and \"next\" do not match"); } }
    break;

  case 271:
/* Line 1813 of yacc.c  */
#line 642 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 273:
/* Line 1813 of yacc.c  */
#line 646 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 274:
/* Line 1813 of yacc.c  */
#line 646 "parser.ypp"
    {/*push_switch_id();add_command(cPUSH_SWITCH_MARK,NULL);create_break_mark(0,1);
   continue_corrections ++; add_command(cCONTINUE_CORRECTION, NULL)->tag = continue_corrections;*/}
    break;

  case 275:
/* Line 1813 of yacc.c  */
#line 648 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 276:
/* Line 1813 of yacc.c  */
#line 648 "parser.ypp"
    {continue_corrections --; /*create_break_mark(-1,0);add_command(cBREAK_HERE,NULL);create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);create_clean_switch_mark(0,false);pop_switch_id();*/}
    break;

  case 277:
/* Line 1813 of yacc.c  */
#line 651 "parser.ypp"
    { yylineno += (yyvsp[(1) - (1)].separator); }
    break;

  case 278:
/* Line 1813 of yacc.c  */
#line 652 "parser.ypp"
    { yylineno += (yyvsp[(2) - (2)].separator); }
    break;

  case 282:
/* Line 1813 of yacc.c  */
#line 660 "parser.ypp"
    {/*create_break_mark(-1,0);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 283:
/* Line 1813 of yacc.c  */
#line 661 "parser.ypp"
    {/*add_command(cSWITCH_COMPARE,NULL);add_command(cDECIDE,NULL);add_command(cMINOR_BREAK,NULL);create_break_mark(1,0);} statement_list {add_command(cNEXT_CASE,NULL);*/}
    break;

  case 285:
/* Line 1813 of yacc.c  */
#line 665 "parser.ypp"
    { yylineno+=(yyvsp[(2) - (2)].separator); }
    break;

  case 286:
/* Line 1813 of yacc.c  */
#line 665 "parser.ypp"
    {/*create_break_mark(-1,0); add_command(cBREAK_HERE,NULL);*/}
    break;

  case 288:
/* Line 1813 of yacc.c  */
#line 668 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 289:
/* Line 1813 of yacc.c  */
#line 668 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 291:
/* Line 1813 of yacc.c  */
#line 673 "parser.ypp"
    {if (unclosed_dos) { error ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 292:
/* Line 1813 of yacc.c  */
#line 674 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 293:
/* Line 1813 of yacc.c  */
#line 674 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 294:
/* Line 1813 of yacc.c  */
#line 677 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 295:
/* Line 1813 of yacc.c  */
#line 677 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 296:
/* Line 1813 of yacc.c  */
#line 678 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 298:
/* Line 1813 of yacc.c  */
#line 684 "parser.ypp"
    {if (unclosed_whiles) { error ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 299:
/* Line 1813 of yacc.c  */
#line 685 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 300:
/* Line 1813 of yacc.c  */
#line 685 "parser.ypp"
    {/*swap();popgoto();poplabel();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 301:
/* Line 1813 of yacc.c  */
#line 688 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 302:
/* Line 1813 of yacc.c  */
#line 688 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 304:
/* Line 1813 of yacc.c  */
#line 693 "parser.ypp"
    {if (unclosed_repeats) { error ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 305:
/* Line 1813 of yacc.c  */
#line 695 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 306:
/* Line 1813 of yacc.c  */
#line 695 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 307:
/* Line 1813 of yacc.c  */
#line 698 "parser.ypp"
    {/*add_command(cDECIDE,NULL);storelabel();pushlabel();*/}
    break;

  case 308:
/* Line 1813 of yacc.c  */
#line 699 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 309:
/* Line 1813 of yacc.c  */
#line 701 "parser.ypp"
    {/*poplabel();*/}
    break;

  case 311:
/* Line 1813 of yacc.c  */
#line 705 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 312:
/* Line 1813 of yacc.c  */
#line 706 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 313:
/* Line 1813 of yacc.c  */
#line 706 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 314:
/* Line 1813 of yacc.c  */
#line 707 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 315:
/* Line 1813 of yacc.c  */
#line 708 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 316:
/* Line 1813 of yacc.c  */
#line 711 "parser.ypp"
    {if (unclosed_ifs) { error ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 317:
/* Line 1813 of yacc.c  */
#line 712 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 318:
/* Line 1813 of yacc.c  */
#line 715 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 322:
/* Line 1813 of yacc.c  */
#line 724 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 323:
/* Line 1813 of yacc.c  */
#line 726 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 325:
/* Line 1813 of yacc.c  */
#line 730 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 326:
/* Line 1813 of yacc.c  */
#line 731 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 327:
/* Line 1813 of yacc.c  */
#line 732 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 328:
/* Line 1813 of yacc.c  */
#line 733 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 329:
/* Line 1813 of yacc.c  */
#line 736 "parser.ypp"
    { error("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 330:
/* Line 1813 of yacc.c  */
#line 737 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yyvsp[(1) - (1)].number_expression)));
   }
    break;

  case 331:
/* Line 1813 of yacc.c  */
#line 743 "parser.ypp"
    { /*create_print ('u'); */}
    break;

  case 332:
/* Line 1813 of yacc.c  */
#line 745 "parser.ypp"
    { debug("print with string\n"); }
    break;

  case 333:
/* Line 1813 of yacc.c  */
#line 747 "parser.ypp"
    { (yyval.print_list) = (yyvsp[(1) - (3)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yyvsp[(3) - (3)].number_expression))) ; }
    break;

  case 334:
/* Line 1813 of yacc.c  */
#line 749 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 335:
/* Line 1813 of yacc.c  */
#line 751 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 336:
/* Line 1813 of yacc.c  */
#line 754 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 338:
/* Line 1813 of yacc.c  */
#line 755 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 340:
/* Line 1813 of yacc.c  */
#line 756 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 342:
/* Line 1813 of yacc.c  */
#line 757 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 344:
/* Line 1813 of yacc.c  */
#line 761 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 345:
/* Line 1813 of yacc.c  */
#line 764 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 346:
/* Line 1813 of yacc.c  */
#line 769 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 347:
/* Line 1813 of yacc.c  */
#line 770 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 348:
/* Line 1813 of yacc.c  */
#line 771 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 349:
/* Line 1813 of yacc.c  */
#line 774 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 350:
/* Line 1813 of yacc.c  */
#line 777 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 351:
/* Line 1813 of yacc.c  */
#line 778 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 352:
/* Line 1813 of yacc.c  */
#line 781 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 353:
/* Line 1813 of yacc.c  */
#line 782 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 354:
/* Line 1813 of yacc.c  */
#line 786 "parser.ypp"
    {
//                          if (cli->next == NULL) {
//                             cmd = add_command (cSTRUCT, dotify ($3));
//                          }
//                          else {
//                             cmd = add_command (cSTRUCT, $3);
//                          }
//                          cmd->args = cli->items;
//                          cmd->tag = syNUMBER;
                      }
    break;

  case 355:
/* Line 1813 of yacc.c  */
#line 796 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 356:
/* Line 1813 of yacc.c  */
#line 802 "parser.ypp"
    {
//         if (cli->next == NULL) {
//            cmd = add_command (cSTRUCT, dotify ($3));
//         }
//         else {
//            cmd = add_command (cSTRUCT, $3);
//         }
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
     }
    break;

  case 357:
/* Line 1813 of yacc.c  */
#line 812 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 361:
/* Line 1813 of yacc.c  */
#line 825 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 362:
/* Line 1813 of yacc.c  */
#line 833 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 363:
/* Line 1813 of yacc.c  */
#line 841 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 364:
/* Line 1813 of yacc.c  */
#line 849 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 365:
/* Line 1813 of yacc.c  */
#line 859 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 366:
/* Line 1813 of yacc.c  */
#line 867 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 367:
/* Line 1813 of yacc.c  */
#line 868 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 368:
/* Line 1813 of yacc.c  */
#line 871 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 369:
/* Line 1813 of yacc.c  */
#line 873 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 370:
/* Line 1813 of yacc.c  */
#line 874 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 371:
/* Line 1813 of yacc.c  */
#line 875 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 372:
/* Line 1813 of yacc.c  */
#line 878 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 373:
/* Line 1813 of yacc.c  */
#line 881 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 374:
/* Line 1813 of yacc.c  */
#line 882 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 375:
/* Line 1813 of yacc.c  */
#line 883 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 376:
/* Line 1813 of yacc.c  */
#line 886 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 377:
/* Line 1813 of yacc.c  */
#line 887 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 378:
/* Line 1813 of yacc.c  */
#line 890 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 379:
/* Line 1813 of yacc.c  */
#line 891 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 380:
/* Line 1813 of yacc.c  */
#line 892 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 1813 of yacc.c  */
#line 893 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 382:
/* Line 1813 of yacc.c  */
#line 893 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 383:
/* Line 1813 of yacc.c  */
#line 896 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 384:
/* Line 1813 of yacc.c  */
#line 897 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 385:
/* Line 1813 of yacc.c  */
#line 898 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 386:
/* Line 1813 of yacc.c  */
#line 899 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 1813 of yacc.c  */
#line 4939 "/home/cai/projects/basic/compiler/parser.cpp"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


