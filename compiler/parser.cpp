/* A Bison parser, made by GNU Bison 2.6.4.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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


/* First part of user declarations.  */
/* Line 278 of lalr1.cc  */
#line 24 "parser.ypp"


/* Include main header file. */
#include "qbc.h"
#include "parser.hpp"
#include <boost/concept_check.hpp>

extern	StatementAST * program;


extern int yylex(qb::parser::semantic_type * yylval_param );

//extern int yylex_destroy(void);
//extern void yyerror (char *msg);
extern int yylineno;
//#define error printf
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

/* Sanity check routine. */
void not_inside_loop_or_conditional (char *what) {
   /* Display an error if necessary. */
   if ((unclosed_dos || unclosed_fors || unclosed_repeats || unclosed_whiles) || (unclosed_ifs || unclosed_switches)) {
      if ((unclosed_dos || unclosed_fors || unclosed_repeats || unclosed_whiles) && (unclosed_ifs || unclosed_switches)) {
         printf ("cannot %s inside a loop, \"if\" statement, or \"switch\" construct", what);
      }
      else if (unclosed_dos || unclosed_fors || unclosed_repeats || unclosed_whiles) {
         printf ("cannot %s inside a loop", what);
      }
      else if (unclosed_ifs || unclosed_switches) {
         printf ("cannot %s inside an \"if\" statement or \"switch\" construct", what);
      }
   }

   /* Return. */
   return;
}

void qb::parser::error(const parser::location_type& loc, const std::string& msg)
{
	std::cerr << "syntex error "<< msg << " at " << loc.begin.line << std::endl ;
}



/* Line 278 of lalr1.cc  */
#line 106 "/home/cai/projects/basic/compiler/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */

/* Line 284 of lalr1.cc  */
#line 114 "/home/cai/projects/basic/compiler/parser.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

/* Line 352 of lalr1.cc  */
#line 22 "parser.ypp"
namespace qb {
/* Line 352 of lalr1.cc  */
#line 210 "/home/cai/projects/basic/compiler/parser.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {
  }

  parser::~parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:
/* Line 661 of lalr1.cc  */
#line 185 "parser.ypp"
    {
			program = (yysemantic_stack_[(2) - (1)].statement);
			debug("program ended\n");
			/*add_command (cEOPROG, NULL);*/
			// yylex_destroy (); YYACCEPT;
		}
    break;

  case 3:
/* Line 661 of lalr1.cc  */
#line 193 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); debug("list_of_statement_lists\n"); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 197 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement);}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 198 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 198 "parser.ypp"
    {
		if((yysemantic_stack_[(4) - (4)].statement)){
			debug("got statement_list now %p\n",(yysemantic_stack_[(4) - (4)].statement));
			(yyval.statement) = (yysemantic_stack_[(4) - (1)].statement);
			(yysemantic_stack_[(4) - (1)].statement)->append((yysemantic_stack_[(4) - (4)].statement));
		}
	}
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 207 "parser.ypp"
    { (yyval.statement) = 0 ;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 208 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 222 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { printf ("cannot \"break\" outside of loop"); }
   }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 226 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   printf ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 235 "parser.ypp"
    { }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 236 "parser.ypp"
    { }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 237 "parser.ypp"
    {if (function_type==ftNONE) printf("declaring variables \"local\" outside of a function has no effect"); }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 238 "parser.ypp"
    {if (function_type==ftNONE) printf("declaring variables \"static\" outside of a function has no effect"); }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now\n");
	   //TODO 最后一个是 \new line
	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(3) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(3) - (3)].print_list)));
   }
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 246 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now\n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 251 "parser.ypp"
    { until_eol = false; }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 251 "parser.ypp"
    {}
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 252 "parser.ypp"
    { until_eol = true; }
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 252 "parser.ypp"
    {}
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 253 "parser.ypp"
    {
	   
             }
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 256 "parser.ypp"
    {

	   
   }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 261 "parser.ypp"
    { }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 263 "parser.ypp"
    {
	   
}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 266 "parser.ypp"
    {}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 267 "parser.ypp"
    {}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 268 "parser.ypp"
    {}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 269 "parser.ypp"
    {}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 270 "parser.ypp"
    {}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 271 "parser.ypp"
    {}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 272 "parser.ypp"
    {}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 273 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 274 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 277 "parser.ypp"
    {

   }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 280 "parser.ypp"
    {  }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 281 "parser.ypp"
    {

   }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 284 "parser.ypp"
    {  }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 285 "parser.ypp"
    {  }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 286 "parser.ypp"
    {  }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 286 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    { }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    {  }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 290 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 306 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 308 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 79:
/* Line 661 of lalr1.cc  */
#line 315 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 316 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 317 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 318 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 321 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 322 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 325 "parser.ypp"
    {/*add_command(cPOPNUMSYM,dotify($1));*/}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 326 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 330 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 331 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 332 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 333 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 334 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 339 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 340 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 343 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 345 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 346 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 347 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 351 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 352 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 353 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 354 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 355 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 356 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 358 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 359 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 360 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 361 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 362 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 363 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 364 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 366 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 367 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 368 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 369 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 370 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 371 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 375 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 375 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 376 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 376 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 377 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 381 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 382 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    { (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));  }
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 389 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 390 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify($1));*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*create_numbin('+');*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    {/*create_numbin('-');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {/*create_numbin('*');*/}
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    {/*create_numbin('/');*/}
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    { /*add_command(cNEGATE,NULL);*/ }
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    { /* do nothing */ }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 414 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 419 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 420 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 421 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 422 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 423 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 425 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 427 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 428 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 429 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 430 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 431 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 432 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 433 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 435 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 436 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 437 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 438 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 439 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 440 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 441 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 442 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 443 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 444 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 445 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 446 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 447 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 448 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 449 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 450 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 451 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 452 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 453 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 454 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 455 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 456 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 457 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 458 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 458 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 207:
/* Line 661 of lalr1.cc  */
#line 465 "parser.ypp"
    {/*create_dim(dotify($1),'N');*/}
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 466 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 467 "parser.ypp"
    {/*create_dim(dotify($3),'N');*/}
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 468 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 471 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 472 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 475 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 478 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 479 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 482 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
if (function_type!=ftNONE) {printf("functions cannot be nested");}}
    break;

  case 223:
/* Line 661 of lalr1.cc  */
#line 495 "parser.ypp"
    {
	   
}
    break;

  case 224:
/* Line 661 of lalr1.cc  */
#line 498 "parser.ypp"
    {
	   
}
    break;

  case 225:
/* Line 661 of lalr1.cc  */
#line 502 "parser.ypp"
    {
	
   }
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 507 "parser.ypp"
    {
		if (unclosed_subs)
		{
			printf ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 513 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 516 "parser.ypp"
    {
	//function_type=ftNUMBER;current_function = dotify ($1); $$ = dotify ($1);
	}
    break;

  case 229:
/* Line 661 of lalr1.cc  */
#line 519 "parser.ypp"
    {/*function_type=ftSTRING;current_function = dotify ($1); $$ = dotify ($1);*/}
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 522 "parser.ypp"
    {
	
                      }
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 525 "parser.ypp"
    {
						  
                      }
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 528 "parser.ypp"
    {
						  
                      }
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 531 "parser.ypp"
    {
						  
                      }
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 536 "parser.ypp"
    {
//                    function_type = ftNUMBER;
//                    cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_NUMBER;
//                    current_function = mystrdup ($1);
//                    $$ = mystrdup ($1);
                }
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 542 "parser.ypp"
    {
//         function_type = ftSTRING;
//         cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_STRING;
//         current_function = mystrdup ($1);
//         $$ = mystrdup ($1);
     }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 555 "parser.ypp"
    {
//                          create_require (stNUMBER); create_makelocal (dotify ($1), syNUMBER); add_command (cPOPNUMSYM, dotify ($1));
                      }
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 558 "parser.ypp"
    {
//         create_require (stSTRING); create_makelocal (dotify ($1), sySTRING); add_command (cPOPSTRSYM, dotify ($1));
     }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 561 "parser.ypp"
    {
//         create_require (stNUMBERARRAYREF); create_arraylink (dotify ($1), stNUMBERARRAYREF);
     }
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 564 "parser.ypp"
    {
//         create_require (stSTRINGARRAYREF); create_arraylink (dotify ($1), stSTRINGARRAYREF);
     }
    break;

  case 245:
/* Line 661 of lalr1.cc  */
#line 573 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 574 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 247:
/* Line 661 of lalr1.cc  */
#line 575 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 248:
/* Line 661 of lalr1.cc  */
#line 576 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 583 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 252:
/* Line 661 of lalr1.cc  */
#line 584 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 585 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 254:
/* Line 661 of lalr1.cc  */
#line 586 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 594 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 595 "parser.ypp"
    {
	   
}
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 598 "parser.ypp"
    {
	   
}
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 601 "parser.ypp"
    {
	   
}
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 606 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 607 "parser.ypp"
    {
				 
			}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 611 "parser.ypp"
    {
	 }
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 613 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 615 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 619 "parser.ypp"
    {
		if (unclosed_fors) {
			printf ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 624 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 627 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 628 "parser.ypp"
    {  }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 631 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 635 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 635 "parser.ypp"
    {
	}
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 637 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 276:
/* Line 661 of lalr1.cc  */
#line 637 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 642 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 643 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 651 "parser.ypp"
    {
	   
}
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 654 "parser.ypp"
    {
		   
	}
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 660 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 660 "parser.ypp"
    {

	   
}
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 666 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 666 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 671 "parser.ypp"
    {if (unclosed_dos) { printf ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 672 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 672 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 675 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 675 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 676 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 682 "parser.ypp"
    {if (unclosed_whiles) { printf ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 683 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 683 "parser.ypp"
    { }
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 686 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 686 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 691 "parser.ypp"
    {if (unclosed_repeats) { printf ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 693 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 693 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 696 "parser.ypp"
    {/*add_command(cDECIDE,NULL);storelabel();pushlabel();*/}
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 697 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 699 "parser.ypp"
    {/*poplabel();*/}
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 703 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 704 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 704 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 705 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 706 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 709 "parser.ypp"
    {if (unclosed_ifs) { printf ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 710 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 713 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 724 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 728 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 729 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 730 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 731 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 734 "parser.ypp"
    { printf("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 735 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 741 "parser.ypp"
    { /*create_print ('u'); */}
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    { debug("print with string\n"); }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 745 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 747 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 749 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 752 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 753 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 754 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 755 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 759 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 762 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 767 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 768 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 769 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 772 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 775 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 776 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 779 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 780 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
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
/* Line 661 of lalr1.cc  */
#line 794 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 800 "parser.ypp"
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
/* Line 661 of lalr1.cc  */
#line 810 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 823 "parser.ypp"
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
/* Line 661 of lalr1.cc  */
#line 831 "parser.ypp"
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
/* Line 661 of lalr1.cc  */
#line 839 "parser.ypp"
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
/* Line 661 of lalr1.cc  */
#line 847 "parser.ypp"
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
/* Line 661 of lalr1.cc  */
#line 857 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 865 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 866 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 869 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 871 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 872 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 873 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 876 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 879 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 880 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 881 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 884 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 885 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 888 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 889 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 890 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 891 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 891 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 894 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 895 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 896 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 897 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2540 "/home/cai/projects/basic/compiler/parser.cpp"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int parser::yypact_ninf_ = -610;
  const short int
  parser::yypact_[] =
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

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  parser::yydefact_[] =
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

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
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

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
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

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -315;
  const short int
  parser::yytable_[] =
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

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
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

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  parser::yystos_[] =
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

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
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
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  parser::yyr1_[] =
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
  const unsigned char
  parser::yyr2_[] =
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

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
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


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
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

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
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

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   180,   180,   193,   194,   197,   198,   198,   207,   208,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   226,   232,   233,   234,   235,   236,   237,   237,
     238,   238,   239,   246,   251,   251,   252,   252,   253,   256,
     261,   262,   263,   266,   267,   268,   269,   270,   271,   272,
     273,   273,   274,   274,   275,   276,   277,   280,   281,   284,
     285,   286,   286,   289,   289,   290,   290,   291,   292,   295,
     296,   299,   302,   303,   306,   307,   308,   311,   312,   315,
     316,   317,   318,   321,   322,   325,   326,   329,   330,   331,
     332,   333,   334,   339,   340,   343,   344,   345,   346,   347,
     348,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   372,   375,   375,   376,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     411,   414,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   458,   461,   462,   465,   466,   467,
     468,   471,   472,   475,   478,   479,   482,   485,   486,   489,
     490,   493,   493,   495,   498,   493,   507,   513,   516,   519,
     522,   525,   528,   522,   536,   542,   550,   551,   552,   555,
     558,   561,   564,   569,   570,   573,   574,   575,   576,   579,
     580,   583,   584,   585,   586,   589,   590,   591,   594,   595,
     598,   601,   606,   607,   611,   613,   606,   619,   624,   627,
     628,   631,   632,   635,   635,   637,   635,   642,   643,   646,
     647,   650,   651,   651,   659,   660,   660,   660,   666,   666,
     666,   671,   672,   672,   675,   675,   676,   675,   682,   683,
     683,   686,   686,   686,   691,   693,   692,   696,   697,   699,
     696,   703,   704,   703,   705,   705,   709,   710,   713,   716,
     717,   720,   722,   724,   721,   728,   729,   730,   731,   734,
     735,   740,   742,   744,   746,   748,   752,   752,   753,   753,
     754,   754,   755,   755,   758,   762,   767,   768,   769,   772,
     775,   776,   779,   780,   784,   784,   800,   800,   818,   819,
     822,   823,   831,   839,   847,   857,   865,   866,   869,   871,
     872,   873,   876,   879,   880,   881,   884,   885,   888,   889,
     890,   891,   891,   894,   895,   896,   897
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 3370;
  const int parser::yynnts_ = 138;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 207;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 138;

  const unsigned int parser::yyuser_token_number_max_ = 382;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 22 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 4237 "/home/cai/projects/basic/compiler/parser.cpp"
