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
#include <boost/make_shared.hpp>
#include <boost/concept_check.hpp>

extern	StatementAST * program;


extern int yylex(qb::parser::semantic_type * yylval_param );

//extern int yylex_destroy(void);
//extern void yyerror (char *msg);
extern int yylineno;

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
         debug ("cannot %s inside a loop, \"if\" statement, or \"switch\" construct", what);
      }
      else if (unclosed_dos || unclosed_fors || unclosed_repeats || unclosed_whiles) {
         debug ("cannot %s inside a loop", what);
      }
      else if (unclosed_ifs || unclosed_switches) {
         debug ("cannot %s inside an \"if\" statement or \"switch\" construct", what);
      }
   }

   /* Return. */
   return;
}

void qb::parser::error(const parser::location_type& loc, const std::string& msg)
{
	std::cerr << msg << " at line " << yylineno << std::endl ;
	exit(1);
}



/* Line 278 of lalr1.cc  */
#line 108 "/home/cai/projects/basic/compiler/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */

/* Line 284 of lalr1.cc  */
#line 116 "/home/cai/projects/basic/compiler/parser.cpp"


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
#line 212 "/home/cai/projects/basic/compiler/parser.cpp"

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
#line 188 "parser.ypp"
    {
			program = (yysemantic_stack_[(2) - (1)].statement);
			debug("program ended\n");
			/*add_command (cEOPROG, NULL);*/
			// yylex_destroy ();
			YYACCEPT;
		}
    break;

  case 3:
/* Line 661 of lalr1.cc  */
#line 197 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); debug("list_of_statement_lists\n"); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 201 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement);}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 202 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 202 "parser.ypp"
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
#line 211 "parser.ypp"
    { (yyval.statement) = 0 ;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 212 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 226 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { debug ("cannot \"break\" outside of loop"); }
   }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 230 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   debug ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    { }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 240 "parser.ypp"
    { }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 241 "parser.ypp"
    {if (function_type==ftNONE) debug("declaring variables \"local\" outside of a function has no effect"); }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 242 "parser.ypp"
    {if (function_type==ftNONE) debug("declaring variables \"static\" outside of a function has no effect"); }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 243 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now\n");
	   //TODO 最后一个是 \new line
		(yysemantic_stack_[(3) - (3)].print_list)->additem(boost::make_shared<EmptyExprAST>());
	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(3) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(3) - (3)].print_list)));
   }
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 251 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 256 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 261 "parser.ypp"
    { until_eol = false; }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 261 "parser.ypp"
    {}
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 262 "parser.ypp"
    { until_eol = true; }
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 262 "parser.ypp"
    {}
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 263 "parser.ypp"
    {
	   
             }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 266 "parser.ypp"
    {

	   
   }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 271 "parser.ypp"
    { }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 272 "parser.ypp"
    {
		debug("got syntax of \"dim local var\" now\n");
	}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 275 "parser.ypp"
    {
	   
}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 278 "parser.ypp"
    {}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 279 "parser.ypp"
    {}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 280 "parser.ypp"
    {}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 281 "parser.ypp"
    {}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 282 "parser.ypp"
    {}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 283 "parser.ypp"
    {}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 284 "parser.ypp"
    {}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 285 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 286 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    {

   }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    {  }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 293 "parser.ypp"
    {
		debug("got label!\n");
   }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 296 "parser.ypp"
    {  }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 297 "parser.ypp"
    {  }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 298 "parser.ypp"
    {  }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 298 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 301 "parser.ypp"
    { }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 301 "parser.ypp"
    {  }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 302 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 318 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 319 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 320 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 327 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 328 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 330 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 333 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 334 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 337 "parser.ypp"
    {/*add_command(cPOPNUMSYM,dotify($1));*/}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 338 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 341 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 342 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 343 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 344 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 345 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 346 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 351 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 352 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 355 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 358 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 359 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 363 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 364 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 366 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 367 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 368 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 369 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 370 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 371 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 373 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 374 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 375 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 376 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 377 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 381 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 382 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 389 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 390 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    { (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));  }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify($1));*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*create_numbin('+');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*create_numbin('-');*/}
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    {/*create_numbin('*');*/}
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    {/*create_numbin('/');*/}
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    { /*add_command(cNEGATE,NULL);*/ }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    { /* do nothing */ }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 414 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 415 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 423 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 429 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 430 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 431 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 432 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 433 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 435 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 436 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 437 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 438 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 439 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 440 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 441 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 442 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 443 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 444 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 445 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 446 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 447 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 448 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 449 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 450 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 451 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 452 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 453 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 454 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 455 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 456 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 457 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 458 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 459 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 460 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 461 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 462 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 463 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 464 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 465 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 466 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 467 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 468 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 469 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 470 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 205:
/* Line 661 of lalr1.cc  */
#line 470 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 478 "parser.ypp"
    {
			debug("as  long\n");
			// long varable
			
		}
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    {
		/*变量定义*/
		// 从堆栈分配指定大小
	}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 489 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    {/*create_dim(dotify($3),'N');*/}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 491 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 495 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 498 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 502 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 219:
/* Line 661 of lalr1.cc  */
#line 505 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 220:
/* Line 661 of lalr1.cc  */
#line 508 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 509 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 224:
/* Line 661 of lalr1.cc  */
#line 516 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 225:
/* Line 661 of lalr1.cc  */
#line 516 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
if (function_type!=ftNONE) {debug("functions cannot be nested");}}
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 518 "parser.ypp"
    {
	   
}
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 521 "parser.ypp"
    {
	   
}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 525 "parser.ypp"
    {
	
   }
    break;

  case 229:
/* Line 661 of lalr1.cc  */
#line 530 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 536 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 539 "parser.ypp"
    {
	//function_type=ftNUMBER;current_function = dotify ($1); $$ = dotify ($1);
	}
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 542 "parser.ypp"
    {/*function_type=ftSTRING;current_function = dotify ($1); $$ = dotify ($1);*/}
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 545 "parser.ypp"
    {
	
                      }
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 548 "parser.ypp"
    {
						  
                      }
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 551 "parser.ypp"
    {
						  
                      }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 554 "parser.ypp"
    {
						  
                      }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 559 "parser.ypp"
    {
//                    function_type = ftNUMBER;
//                    cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_NUMBER;
//                    current_function = mystrdup ($1);
//                    $$ = mystrdup ($1);
                }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 565 "parser.ypp"
    {
//         function_type = ftSTRING;
//         cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_STRING;
//         current_function = mystrdup ($1);
//         $$ = mystrdup ($1);
     }
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 578 "parser.ypp"
    {
//                          create_require (stNUMBER); create_makelocal (dotify ($1), syNUMBER); add_command (cPOPNUMSYM, dotify ($1));
                      }
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 581 "parser.ypp"
    {
//         create_require (stSTRING); create_makelocal (dotify ($1), sySTRING); add_command (cPOPSTRSYM, dotify ($1));
     }
    break;

  case 244:
/* Line 661 of lalr1.cc  */
#line 584 "parser.ypp"
    {
//         create_require (stNUMBERARRAYREF); create_arraylink (dotify ($1), stNUMBERARRAYREF);
     }
    break;

  case 245:
/* Line 661 of lalr1.cc  */
#line 587 "parser.ypp"
    {
//         create_require (stSTRINGARRAYREF); create_arraylink (dotify ($1), stSTRINGARRAYREF);
     }
    break;

  case 248:
/* Line 661 of lalr1.cc  */
#line 596 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 249:
/* Line 661 of lalr1.cc  */
#line 597 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 250:
/* Line 661 of lalr1.cc  */
#line 598 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 599 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 254:
/* Line 661 of lalr1.cc  */
#line 606 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 607 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 608 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 609 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 617 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 618 "parser.ypp"
    {
	   
}
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 621 "parser.ypp"
    {
	   
}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 624 "parser.ypp"
    {
	   
}
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 629 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 630 "parser.ypp"
    {
				 
			}
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 634 "parser.ypp"
    {
	 }
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 636 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 638 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 642 "parser.ypp"
    {
		if (unclosed_fors) {
			debug ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 647 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 650 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 651 "parser.ypp"
    {  }
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 654 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 276:
/* Line 661 of lalr1.cc  */
#line 658 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 658 "parser.ypp"
    {
	}
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 660 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 660 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 665 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 666 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 674 "parser.ypp"
    {
	   
}
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 677 "parser.ypp"
    {
		   
	}
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 683 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 683 "parser.ypp"
    {

	   
}
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 689 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 689 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 694 "parser.ypp"
    {if (unclosed_dos) { debug ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 695 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 695 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 698 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 698 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 699 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 705 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 706 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 706 "parser.ypp"
    { }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 709 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 709 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 714 "parser.ypp"
    {if (unclosed_repeats) { debug ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 716 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 716 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 719 "parser.ypp"
    {/*add_command(cDECIDE,NULL);storelabel();pushlabel();*/}
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 720 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    {/*poplabel();*/}
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 726 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 727 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 727 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 728 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 729 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 732 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 733 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 736 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 745 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 747 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 751 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 752 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 753 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 754 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 757 "parser.ypp"
    { debug("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 758 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 764 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 766 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 768 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 770 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 772 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 775 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 776 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 777 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 778 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 782 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 785 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 790 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 791 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 792 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 795 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 798 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 799 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 802 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 803 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 807 "parser.ypp"
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

  case 358:
/* Line 661 of lalr1.cc  */
#line 817 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 823 "parser.ypp"
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

  case 360:
/* Line 661 of lalr1.cc  */
#line 833 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 846 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 854 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 862 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 870 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 880 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 888 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 889 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 892 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 894 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 895 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 896 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 899 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 902 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 903 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 904 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 907 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 908 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 911 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 912 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 913 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 914 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 914 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 917 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 918 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 919 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 920 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2575 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const short int parser::yypact_ninf_ = -622;
  const short int
  parser::yypact_[] =
  {
      3425,  -119,   -58,  -622,  -622,  -622,  2406,   388,   -23,   -21,
    -622,    91,    91,    91,  -622,  -622,  2406,  -622,  -622,  -622,
    -622,  -622,    87,   156,  -622,  -622,    91,    91,   -57,  -622,
      71,  -622,  -622,    91,   456,    91,    13,    54,    69,  1999,
    1999,  1999,  1999,    78,   140,   387,   139,  -622,  -622,  -622,
    -622,  -622,   121,  -622,   159,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  2406,  -622,   -24,   -15,    93,   178,
     228,  -622,   113,   137,  -622,  -622,  -622,   179,   185,  2406,
     224,   229,   268,   273,   294,   306,   317,   327,   352,   354,
     363,   368,   370,   372,   380,   386,   398,   404,   406,   413,
     430,   432,   438,   444,   450,   453,   455,   457,   460,   461,
     462,   463,   466,   469,   470,   471,   472,   475,   476,  -622,
    -622,   479,   480,   482,   484,   490,   492,   493,   494,   495,
     496,  2406,  2406,  2406,   248,  -622,  3209,  -622,  -622,  -622,
     162,   177,  -622,  -622,   388,   218,   162,   177,    93,  -622,
    -622,   467,  -622,   245,   245,   245,   405,   405,   248,  3209,
      91,  -622,  -622,  -622,   497,   501,  -622,  -622,    15,   177,
    -622,   -22,   501,   392,   412,   511,   456,   456,   425,   245,
     503,   245,    11,  2406,   454,  -622,   635,  -622,   245,   512,
    -622,     4,    10,   623,   624,   515,   245,   456,   456,   456,
    2406,  3209,   517,  -622,   519,   528,   388,  -622,  -622,  3425,
    -622,  2406,   388,  3106,  2406,   487,   491,   507,   388,  -622,
    -622,   467,  2406,  2406,  1247,  2406,  -622,  -622,   509,   509,
    2406,  2406,  2235,  2406,  2406,  2406,  2406,  2406,  2406,   388,
     388,   388,   388,   388,  1999,  1999,  1999,  1999,  2406,  2406,
    2406,  2406,  2406,  2406,  2406,  2406,  2406,  2406,   388,   388,
     388,   388,  2406,   388,   388,   456,   388,   456,   388,   388,
     388,   388,   388,   388,   603,   603,     8,   601,   388,   388,
     388,   388,   388,   388,   388,  -622,  -622,  2406,  2406,  2406,
    2406,  2406,  2406,  2406,  2406,  2406,  2406,  2406,  2406,   -55,
    2406,  2406,  -622,  -622,   532,  -622,   661,  -622,  -622,  -622,
      20,  2406,  3425,  3425,  -622,  -622,   525,   591,  -622,   527,
     542,  -622,   533,  -622,   536,   177,  -622,  -622,   535,  -622,
     536,   177,  -622,  -622,    91,    91,  -622,  2406,   245,   248,
     424,   421,    16,  -622,   388,   454,   538,   539,  2406,   666,
     456,    91,    91,    91,    91,    91,   540,   536,  -622,  -622,
     546,   547,  3209,   388,  2406,  2406,   -33,   139,  3425,  3209,
     218,   632,  3425,   666,  3209,   548,   549,   550,   551,   552,
     553,   218,  -622,   532,  -622,  2949,  2963,  2977,  2406,  2406,
     554,   555,   556,   574,   561,    93,  -622,   578,   579,   811,
     847,  -622,   991,  1025,  1129,  1148,  1275,  2991,  3072,   -80,
     110,   205,   125,   148,    43,   589,   575,   588,   595,  1423,
    1487,  1523,  1577,  1660,     1,  1723,    29,    65,  1743,   149,
     150,   174,   190,  2130,   191,   214,   -83,   231,   -40,   242,
     202,   206,   209,   275,   276,  -622,  -622,   218,   218,   218,
     218,   218,   218,  -622,  2406,  2406,   829,   196,   164,   328,
     170,   253,  -622,    55,    55,   603,   603,   603,   248,  3209,
      73,  -622,   114,   590,   557,  -622,  -622,  3209,   282,   161,
     597,   598,  -622,   177,  -622,   598,   456,   456,   245,   245,
    2142,   388,  -622,  2406,  -622,  2406,   245,   218,   456,  -622,
     678,   666,   730,   666,   248,  3209,   666,  -622,    39,  -622,
     245,   245,   245,   245,   245,  2406,  2406,  2406,   278,  3086,
    3209,  -622,  -622,  3425,  -622,  3335,   599,   602,  2406,  2406,
     605,   607,   604,  2406,  2406,  2406,   284,   285,   113,   137,
    -622,  -622,   559,  2406,  2406,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  2406,  2406,  2406,  2406,  2406,  -622,  -622,   388,
    -622,   388,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    2406,  -622,  -622,  2406,  -622,   388,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,   509,   388,  -622,   509,   388,  -622,
     388,  -622,  -622,  -622,   388,   388,  1247,  1442,  2406,  -622,
    -622,   565,  -622,  2406,  3425,  -622,  2406,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,   218,   248,  3114,   456,
    2169,   456,  -622,   536,   177,  -622,  -622,    25,    25,   738,
    -622,  -622,  -622,   744,    37,  -622,    -2,  -622,  2410,  2526,
     391,   388,   388,   139,  -622,  -622,  -622,  -622,  2406,   288,
     289,  -622,  -622,   565,  2540,  2552,  2564,  -622,  -622,   615,
     616,  2580,  2663,  2675,  2687,  2703,  2717,   409,   210,    52,
    2800,  2812,    76,   292,   211,   299,   234,   247,    80,   109,
    -622,   555,   303,  -622,   620,    93,  -622,  -622,  3126,   105,
    3209,  -622,   388,  -622,  -622,  -622,  -622,   506,   666,   456,
     510,   508,  -622,  -622,  -622,    45,   738,   695,   697,  2406,
     698,   218,   218,   715,   304,  -622,  -622,   308,  -622,   620,
      93,  -622,  -622,  -622,  -622,  -622,   599,   602,  -622,  -622,
    -622,  -622,  -622,  -622,  2406,  -622,  -622,   388,  -622,  -622,
    -622,   388,  -622,   388,  -622,  -622,   388,  -622,  -622,  -622,
    2406,  -622,  2406,  -622,   565,  -622,   577,  2406,  -622,  -622,
    -622,  -622,   218,   456,  -622,   666,   738,   536,   177,  -622,
    -622,  -622,  -622,   753,   692,  -622,   388,   388,  2826,   388,
    2406,   719,  -622,   565,  -622,  2840,   258,   264,   269,   271,
    2854,  2937,  -622,   743,   616,   714,  -622,  -622,   738,  2406,
    -622,  -622,   218,   218,   705,   218,  3168,  3425,  -622,  -622,
    3425,  -622,  -622,  -622,  -622,  -622,  -622,  -622,   762,  2406,
    -622,  -622,  -622,  -622,   388,  -622,   139,    26,   189,  -622,
    3209,  3425,  3425,   218,  3425,  -622,  -622,  -622,  -622,  -622,
    -622,   139,   139,   139,    50,   715,  -622,  -622,    91,  -622,
    -622,   245
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  parser::yydefact_[] =
  {
         8,   369,   379,    21,    22,   224,    39,     0,     0,     0,
     233,     0,     0,     0,    51,    53,    44,   265,   297,   304,
     291,   321,     0,     0,    28,    30,     0,     0,   348,    35,
       0,   368,   276,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,     9,    10,
      11,    26,     0,    27,     0,    23,    24,    17,    20,    16,
      19,    18,    14,    15,     0,    25,     0,   214,   215,     0,
     217,   218,   371,   381,   225,   138,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    97,    40,   159,   143,    98,
     144,   214,    96,   217,     0,    61,     0,     0,     0,    62,
      64,     0,   369,    57,    58,    59,     0,     0,     0,    45,
       0,   298,   305,   292,   369,   379,    12,    13,     0,   216,
     219,   208,     0,    42,     0,   208,     0,     0,    56,   355,
      55,   353,     0,   332,   339,    37,     0,   277,    66,    68,
      78,     0,     0,     0,     0,    69,    84,     0,     0,     0,
       0,   207,     0,    48,     0,     0,     0,     1,     2,     8,
       6,     0,     0,   314,     0,     0,     0,     0,     0,   375,
     386,     0,     0,     0,   129,     0,   204,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   379,   234,   237,   238,     0,   352,    52,    54,
       0,     0,     8,     8,   371,   381,     0,     0,   210,     0,
       0,   211,    29,   246,   248,   250,   249,   251,    31,   252,
     254,   256,   255,   257,     0,     0,   350,     0,   349,   335,
     333,    32,     0,    36,     0,   339,   357,   359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,   206,     0,     0,     0,     0,     4,     8,    87,
      93,     0,     0,     0,    86,   370,   380,   373,   383,   377,
     388,    88,   226,   231,   232,     0,     0,     0,     0,     0,
     369,     0,     0,     0,     0,   161,   162,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   160,   154,   156,   158,
     155,   157,   153,   100,     0,     0,   131,   133,   135,   132,
     134,   130,   150,   146,   145,   147,   148,   149,   222,   223,
       0,   220,     0,     0,     0,   370,   266,   299,     0,     0,
     370,   380,   209,   212,   213,     0,     0,     0,   356,   354,
       0,     0,    33,    34,   343,     0,   341,   347,     0,    38,
       0,     0,     0,     0,   283,   282,     0,   280,     0,    79,
      80,    82,    81,    83,    85,     0,     0,     0,    46,    49,
      60,    43,     7,     8,   315,     0,   374,   384,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     139,   140,     0,     0,     0,   177,   178,   179,   174,   175,
     173,   176,     0,     0,     0,     0,     0,   110,   111,     0,
     198,     0,   136,   202,   203,   163,   164,   165,   166,   167,
       0,   168,   170,     0,   171,     0,   106,   109,   184,   185,
     183,   190,   121,   122,     0,     0,   116,     0,     0,   118,
       0,   114,   112,   113,     0,     0,   128,   126,     0,    63,
      65,   239,   380,     0,     8,   307,     0,   306,   294,   295,
     293,   374,   384,   247,   253,   351,   334,   338,   336,     0,
       0,     0,   340,   328,   330,   329,   331,   368,   368,   284,
      75,    77,   281,     0,     0,    70,     0,    73,     0,     0,
       0,     0,     0,   311,   316,   318,   378,   389,     0,     0,
       0,   376,   387,   258,     0,     0,     0,   205,   124,   370,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,   379,     0,   240,   242,   244,   243,   245,     0,     0,
     308,   296,     0,   344,   345,   342,   363,   368,     0,     0,
     368,   287,    76,    67,    71,     0,    72,     0,     0,     0,
       0,    47,    50,   324,     0,   372,   382,     0,   259,   261,
     263,   262,   264,   191,   192,   193,     0,     0,   141,   142,
     181,   182,   102,   103,     0,   105,   199,     0,   200,   169,
     172,     0,   107,     0,   195,   115,     0,   197,   117,   137,
       0,   186,     0,   188,     0,   235,     0,     0,   301,   302,
     300,   309,   337,     0,   358,     0,   361,   364,   366,   365,
     367,   360,   285,     0,     0,    74,     0,     0,     0,     0,
       0,   322,   385,     0,   227,     0,     0,     0,     0,     0,
       0,     0,   241,     0,   380,   274,   303,   346,   362,     0,
     288,   278,    91,    92,     0,    90,     0,     8,   312,   260,
       8,   104,   201,   108,   194,   196,   187,   189,     0,     0,
     267,   286,   289,   279,     0,   325,   323,     0,     0,   236,
     275,     8,     8,    89,     8,   319,   320,   313,   230,   229,
     228,   268,   290,   326,     0,   324,   270,   271,   272,   327,
     269,   273
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -622,  -622,  -622,  -207,  -622,   399,  -371,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,   144,  -622,    75,
    -622,   434,  -622,   760,   763,  -148,  1082,  -622,  -622,  1679,
    -622,  -622,   560,  -214,  -622,  -622,   -12,   611,  -622,    18,
    -622,    44,  -622,  -281,   192,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,    34,  -622,
     305,  -622,   309,  -622,     9,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -334,    -1,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,   -48,  -622,  -622,  -613,  -622,   458,  -622,  -622,  -622,
    -622,  -622,  -622,   642,  -622,  -622,  -558,  -622,  -622,   173,
    -621,   771,     0,   437,  1246,   617,   795,  -622,  -225
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    44,    45,    46,   368,    47,    48,   176,   177,   184,
     345,   156,   157,   300,   301,   349,   634,   635,   636,   637,
     189,   190,   195,    49,    50,   356,   158,   135,   389,   201,
     455,   454,   392,   393,   137,   388,   202,   318,   173,   138,
      52,   139,    54,   470,   471,    55,    74,   221,   532,   810,
     840,   382,    56,   151,   473,   793,   303,   682,   683,   322,
     323,   328,   329,   717,   718,    57,   160,   603,   831,   844,
     848,   850,   820,    58,   187,   348,   823,   508,   506,   701,
     799,   774,   822,   832,    59,   163,   313,   610,   691,    60,
     161,   311,   604,   760,   796,    61,   162,   312,   607,   761,
      62,   371,   713,   827,    63,   372,   644,   373,   837,    64,
     808,   781,   834,   845,   622,   341,   343,   344,   621,   619,
     763,   498,   183,   308,   180,   178,    65,   501,   503,   697,
     698,   699,   140,   141,    68,   142,   143,   648,    71
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -370;
  const short int
  parser::yytable_[] =
  {
        66,   524,   367,   396,   396,   507,   693,   146,   695,   285,
     286,   153,   154,   155,   336,   398,   152,    72,    51,   494,
     472,   152,   168,   174,   317,   351,   179,   181,   203,   204,
     205,   352,   632,   188,   191,   196,   214,   285,   286,   525,
     630,   631,   630,   631,    53,  -216,   632,   284,   630,   631,
     360,   361,   585,   835,   586,   554,   287,   288,   289,   290,
     291,   292,   293,   278,   279,   280,   281,   282,   283,   696,
     696,   836,   284,   285,   286,   214,   765,   846,    73,   765,
     476,   182,   445,   847,   287,   288,   289,   290,   291,   292,
     293,    31,   164,   165,   284,   588,   152,   589,   278,   279,
     280,   281,   282,   283,   521,   478,   479,   536,   537,   215,
     703,  -369,   210,   149,   314,   150,   293,   436,   216,   438,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   758,   705,   185,   284,   570,   316,   571,   696,
     207,   759,   696,   216,   146,   445,   210,   337,   316,   197,
     797,   304,   495,   306,   645,   294,   295,   296,   297,   298,
     310,   171,   172,   633,   573,   633,   574,   627,   210,   628,
     284,   633,   629,    36,    37,    38,   324,   330,   559,   284,
     560,   211,   338,   296,   297,   298,   346,   737,   608,   738,
     198,   294,   295,   296,   297,   298,   210,   357,   357,   357,
     575,   609,   576,   284,   838,   199,   146,   284,   598,    66,
     599,   741,   146,   742,   206,   750,   839,   751,   146,   212,
     288,   383,   290,   291,   292,   293,   217,    51,   394,   394,
     292,   293,   415,   416,   417,   418,   284,   284,   218,   146,
     146,   146,   146,   146,   752,   555,   753,   649,   650,   598,
     219,   600,   284,    53,   290,   291,   292,   293,   146,   146,
     146,   146,   557,   146,   146,   357,   146,   357,   146,   146,
     146,   146,   146,   146,   220,   284,   284,   284,   146,   146,
     146,   146,   146,   146,   146,   558,   578,   579,  -219,   210,
     294,   295,   296,   297,   298,   215,   294,   295,   296,   297,
     298,   284,   706,   278,   279,   280,   281,   282,   283,   605,
     216,   580,    66,    66,   293,   222,   643,   284,   284,   174,
     606,   223,   294,   295,   296,   297,   298,   581,   583,   284,
      51,    51,   284,   284,   488,   489,   284,   284,   284,   591,
     556,   284,   496,   592,   146,   284,   593,   736,   745,   584,
     191,   510,   511,   512,   513,   514,    53,    53,   284,   396,
     225,   284,   396,   146,   766,   226,   587,   714,    66,   284,
     673,   748,    66,   675,   284,   284,   687,   590,   306,   294,
     295,   296,   297,   298,   749,   284,    51,   291,   292,   293,
      51,   284,    76,     1,     2,   812,   284,   689,   284,   285,
     286,   813,   284,   284,   227,   284,   814,    82,   815,   228,
     594,   595,    53,   641,   208,   209,    53,   285,   286,   598,
     598,   657,   658,   598,   598,   715,   716,   743,   722,   744,
     229,   798,   285,   286,   746,   307,   747,    67,   754,   598,
     755,   782,   230,   783,   147,   784,   287,   288,   289,   290,
     291,   292,   293,   231,   294,   295,   296,   297,   298,   169,
     147,   164,   165,   232,   287,   288,   289,   290,   291,   292,
     293,   192,   152,   302,    94,    95,    96,    97,    98,   287,
     288,   289,   290,   291,   292,   293,   324,   330,   233,   491,
     234,   146,   375,   376,   111,   112,   377,   378,   623,   235,
     117,   118,   119,   120,   236,   122,   237,   124,   238,   126,
     127,   128,   379,   380,   390,   391,   239,   294,   295,   296,
     297,   298,   240,    66,   144,    66,   709,   319,   710,   687,
     480,   481,   164,   172,   241,   294,   295,   296,   297,   298,
     242,    51,   243,    51,   734,   320,   735,   480,   485,   244,
     294,   295,   296,   297,   298,   492,   493,   317,   722,   146,
     334,   146,   475,   602,   659,   660,   245,    53,   246,    53,
     390,   681,    31,   764,   247,   146,    31,   771,   772,   773,
     248,   147,   659,   794,   394,   146,   249,   394,   146,   250,
     146,   251,   342,   252,   146,   146,   253,   254,   255,   256,
     826,   684,   257,   828,    66,   258,   259,   260,   261,   285,
     286,   262,   263,   325,   331,   264,   265,    69,   266,   623,
     267,   623,    51,   347,   841,   842,   268,   843,   269,   270,
     271,   272,   273,   314,   147,   147,   147,   315,   335,    69,
     164,   146,   146,   147,   353,   354,    67,   350,    53,   147,
     355,   193,   363,   719,   364,   147,   287,   288,   289,   290,
     291,   292,   293,   365,   293,   474,   475,   482,   486,   316,
     487,   500,   502,   507,   523,   515,   147,   147,   147,   147,
     147,   516,   517,   480,   526,   527,   528,   529,   530,   531,
     538,   539,   146,   540,   542,   147,   147,   147,   147,   767,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   541,   562,   543,   544,   147,   147,   147,   147,   147,
     147,   147,   285,   286,   561,   563,   601,   294,   295,   296,
     297,   298,   564,   611,   612,   377,   646,   146,   446,   647,
     653,   146,   651,   146,   652,   632,   146,   702,   819,    67,
      67,   726,   727,   756,   684,   776,   483,   777,   779,   780,
     800,   801,   807,   623,   818,   824,   829,   522,   305,   287,
     288,   289,   290,   291,   292,   293,   146,   146,   704,   146,
     775,   147,   166,   719,   509,   167,   321,   192,   792,   397,
     680,   613,   809,   326,   332,    70,   614,   849,   821,   309,
     147,   700,   186,   499,     0,    67,     0,    66,     0,    67,
      66,     0,     0,     0,   358,   358,   358,   170,   175,   285,
     286,     0,     0,     0,   146,    51,    69,     0,    51,   194,
       0,    66,    66,     0,    66,     0,     0,     0,   384,     0,
     294,   295,   296,   297,   298,     0,     0,     0,   851,    51,
      51,    53,    51,     0,    53,   285,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,    53,    53,     0,    53,     0,
       0,     0,   358,     0,   358,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   325,   331,     0,     0,     0,   147,    69,
      69,     0,     0,     0,     0,   624,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   545,     0,
       0,     0,     0,     0,     0,   294,   295,   296,   297,   298,
      67,     0,    67,     0,     0,     0,     0,   193,     0,     0,
       0,   327,   333,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,     0,   546,    69,     0,     0,     0,    69,
       0,     0,   359,   359,   359,     0,   147,     0,   147,   285,
     286,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,     0,     0,   147,     0,   147,     0,     0,
       0,   147,   147,   285,   286,     0,     0,     0,     0,     0,
       0,    67,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,   624,     0,   624,     0,
     359,     0,   359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   147,
     287,   288,   289,   290,   291,   292,   293,     0,   134,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   326,   332,     0,     0,    70,    70,     0,
       0,     0,     0,     0,   484,   625,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   547,   147,
       0,     0,     0,     0,     0,     0,   768,   285,   286,     0,
      69,     0,    69,     0,     0,   194,     0,     0,     0,     0,
       0,   294,   295,   296,   297,   298,   285,   286,     0,     0,
       0,     0,   548,    70,     0,     0,     0,    70,     0,     0,
       0,     0,     0,     0,   147,     0,     0,     0,   147,     0,
     147,     0,     0,   147,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     624,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,   147,   147,   276,   147,     0,   686,     0,
       0,    69,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   625,     0,   625,     0,
       0,     0,     0,     0,    67,     0,     0,    67,     0,     0,
       0,     0,     0,   148,     0,   294,   295,   296,   297,   298,
       0,   147,     0,     0,     0,   339,   549,     0,    67,    67,
     721,    67,     0,     0,   294,   295,   296,   297,   298,     0,
       0,   327,   333,   285,   286,   550,     0,     0,   366,     0,
       0,     0,     0,   626,   370,     0,     0,     0,     0,     0,
     381,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,   769,     0,    70,     0,
      70,   409,   410,   411,   412,   413,   414,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
     429,   430,   431,   432,     0,   434,   435,     0,   437,     0,
     439,   440,   441,   442,   443,   444,     0,     0,     0,     0,
     447,   448,   449,   450,   451,   452,   453,     0,     0,     0,
       0,   686,     0,   294,   295,   296,   297,   298,     0,     0,
     625,     0,   468,   468,     0,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     721,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,     0,   551,     0,   626,     0,   626,     0,     0,     0,
       0,     0,     0,     0,    69,     0,   497,    69,     0,     0,
     504,   285,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   518,     0,     0,    69,    69,
     285,    69,   148,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
     468,   468,     0,     0,   395,   395,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   148,   148,   148,   148,   148,
       0,     0,     0,     0,   770,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   148,   148,   148,   148,     0,   148,
     148,     0,   148,     0,   148,   148,   148,   148,   148,   148,
       0,     0,     0,     0,   148,   148,   148,   148,   148,   148,
     148,   285,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   626,     0,
     565,     0,     0,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,   616,     0,   617,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   285,   286,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,    70,     0,     0,     0,   148,
     468,   468,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,     0,   566,     0,    70,    70,     0,    70,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,   668,     0,   669,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,   672,     0,     0,
     567,     0,     0,     0,     0,     0,     0,   674,   285,   286,
     676,     0,   677,     0,     0,     0,   678,   679,     0,     0,
     468,     0,     0,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,     0,   568,   287,   288,   289,   290,   291,
     292,   293,     0,   711,   712,     0,     0,     0,     0,     0,
     468,   285,   286,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,   213,     0,     0,     0,     0,     0,     0,
       0,   285,   286,     0,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   762,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,   294,   295,   296,   297,
     298,     0,     0,     0,     0,     0,     0,   569,   287,   288,
     289,   290,   291,   292,   293,   148,     0,   148,     0,     0,
     274,   275,   277,     0,     0,     0,     0,     0,     0,   786,
       0,   148,     0,   787,     0,   788,     0,     0,   789,     0,
     148,   148,     0,   148,   148,     0,   148,     0,     0,     0,
     148,   148,     0,     0,     0,     0,     0,   685,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   802,   803,
     572,   805,   340,     0,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,   362,
     577,   504,     0,     0,     0,     0,     0,   148,   148,     0,
     369,     0,     0,   374,     0,     0,     0,     0,     0,   720,
       0,   385,   386,     0,   387,     0,   833,     0,     0,   399,
     400,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,     0,   148,     0,
       0,   433,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,     0,   469,
     469,     0,     0,   148,     0,     0,     0,   148,     0,   148,
     477,     0,   148,     0,     0,     0,     0,     0,     0,     0,
     685,     0,    75,    76,     1,     2,     0,    77,    78,    79,
      80,     0,     0,     0,     0,     0,   490,    81,    82,     0,
       0,     0,   148,   148,     0,   148,     0,   505,     0,   720,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,   520,     0,     0,     0,     0,     0,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   469,   469,     0,
     148,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   100,     0,   101,   102,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,     0,
       0,     0,     0,   596,   597,   133,     0,   200,   285,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   618,     0,   620,     0,     0,   285,   286,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,   638,   639,   640,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,   469,   469,     0,
       0,     0,   654,   655,   656,     0,     0,     0,     0,     0,
       0,     0,   661,   662,   287,   288,   289,   290,   291,   292,
     293,   663,   664,   665,   666,   667,     0,     0,    75,    76,
       1,     2,     0,    77,    78,    79,    80,     0,     0,   670,
       0,     0,   671,    81,    82,     0,   294,   295,   296,   297,
     298,     0,     0,     0,     0,     0,     0,   582,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   469,     0,   615,
       0,     0,   688,     0,     0,   690,    83,    84,     0,     0,
       0,     0,     0,     0,     0,   294,   295,   296,   297,   298,
       0,     0,     0,     0,     0,     0,   694,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   469,   100,     0,
     101,   102,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,     0,     0,     0,     0,     0,     0,
       0,   133,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   778,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     1,     2,   785,    77,    78,    79,    80,   285,   286,
       0,     0,     0,     0,    81,    82,     0,     0,     0,   790,
       0,   791,     0,     0,     0,     0,   795,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,   806,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,   505,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   830,   100,
       0,   101,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   285,   286,   294,   295,   296,   297,
     298,     0,   133,     0,     0,     0,     0,   707,   285,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   286,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,   285,   286,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,     0,   708,     0,     0,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,   723,   294,   295,
     296,   297,   298,   285,   286,     0,     0,     0,     0,   724,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   725,     0,     0,     0,     0,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,   728,   287,   288,
     289,   290,   291,   292,   293,   285,   286,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
     729,   294,   295,   296,   297,   298,     0,     0,   285,   286,
       0,     0,   730,   294,   295,   296,   297,   298,     0,     0,
     285,   286,     0,     0,   731,     0,     0,     0,     0,   294,
     295,   296,   297,   298,   285,   286,     0,     0,     0,     0,
     732,     0,     0,   294,   295,   296,   297,   298,   285,   286,
       0,     0,     0,     0,   733,   287,   288,   289,   290,   291,
     292,   293,   285,   286,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,   295,   296,   297,
     298,     0,     0,     0,     0,     0,     0,   739,   294,   295,
     296,   297,   298,     0,     0,   285,   286,     0,     0,   740,
       0,     0,   294,   295,   296,   297,   298,   285,   286,     0,
       0,     0,     0,   804,     0,     0,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,   811,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   816,   287,   288,   289,   290,   291,   292,   293,   285,
     286,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,     0,   817,   294,   295,   296,   297,   298,
     285,   286,     0,     0,   533,     0,     0,     0,     0,   294,
     295,   296,   297,   298,   285,   286,     0,     0,   534,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   535,  -317,   285,   286,     0,   294,   295,   296,
     297,   298,   285,   286,     0,     0,   552,   287,   288,   289,
     290,   291,   292,   293,   285,   286,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,  -310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   757,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,   287,
     288,   289,   290,   291,   292,   293,   285,   286,     0,   692,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   553,     0,     0,
     825,     0,   294,   295,   296,   297,   298,   285,   286,     0,
       0,   642,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,   294,   295,   296,   297,   298,     0,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,   295,   296,   297,   298,
       1,     2,   632,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    15,     0,     0,    16,     0,    17,     0,     0,     0,
      18,     0,    19,     0,    20,     0,    21,     0,     0,     0,
       0,     0,    22,    23,    24,    25,     0,     0,    26,    27,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
       0,    31,     0,    32,     0,     0,     0,    33,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     0,     0,    39,    40,     0,    41,
       1,     2,    42,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     7,     8,     9,    10,    43,    11,    12,    13,
      14,    15,     0,     0,    16,     0,    17,     0,     0,     0,
      18,     0,    19,     0,    20,     0,    21,     0,     0,     0,
       0,     0,    22,    23,    24,    25,     0,     0,    26,    27,
       0,     0,     0,     0,     0,     0,     0,    28,    29,    30,
       0,    31,     0,    32,     0,     0,     0,    33,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     0,     0,    39,    40,     0,    41,
       0,     0,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,   372,   209,   228,   229,     7,   619,     7,   621,     8,
       9,    11,    12,    13,     3,   229,     5,   136,     0,     3,
     301,     5,    22,    23,    46,    21,    26,    27,    40,    41,
      42,    21,     7,    33,    34,    35,    60,     8,     9,   373,
       3,     4,     3,     4,     0,    60,     7,   127,     3,     4,
     198,   199,   135,    27,   137,   135,    55,    56,    57,    58,
      59,    60,    61,    55,    56,    57,    58,    59,    60,   627,
     628,    45,   127,     8,     9,    60,   697,    27,   136,   700,
      60,   138,   137,    33,    55,    56,    57,    58,    59,    60,
      61,    66,     5,     6,   127,   135,     5,   137,    55,    56,
      57,    58,    59,    60,   137,   312,   313,   388,   389,   133,
      73,   133,     7,   136,   136,   136,    61,   265,   133,   267,
      55,    56,    57,    58,    59,    60,    61,   126,   127,   128,
     129,   130,    27,   135,    63,   127,   135,   133,   137,   697,
       0,    36,   700,   133,   144,   137,     7,   136,   133,   136,
     763,   151,   136,   133,   525,   126,   127,   128,   129,   130,
     160,     5,     6,   126,   135,   126,   137,   501,     7,   503,
     127,   126,   506,    86,    87,    88,   176,   177,   135,   127,
     137,    60,   182,   128,   129,   130,   186,   135,    27,   137,
     136,   126,   127,   128,   129,   130,     7,   197,   198,   199,
     135,    40,   137,   127,    15,   136,   206,   127,   135,   209,
     137,   135,   212,   137,   136,   135,    27,   137,   218,    60,
      56,   221,    58,    59,    60,    61,   133,   209,   228,   229,
      60,    61,   244,   245,   246,   247,   127,   127,    60,   239,
     240,   241,   242,   243,   135,   135,   137,   528,   529,   135,
     137,   137,   127,   209,    58,    59,    60,    61,   258,   259,
     260,   261,   137,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   137,   127,   127,   127,   278,   279,
     280,   281,   282,   283,   284,   137,   137,   137,    60,     7,
     126,   127,   128,   129,   130,   133,   126,   127,   128,   129,
     130,   127,   636,    55,    56,    57,    58,    59,    60,    27,
     133,   137,   312,   313,    61,   136,   523,   127,   127,   319,
      38,   136,   126,   127,   128,   129,   130,   137,   137,   127,
     312,   313,   127,   127,   334,   335,   127,   127,   127,   137,
     135,   127,   342,   137,   344,   127,   137,   137,   137,   135,
     350,   351,   352,   353,   354,   355,   312,   313,   127,   584,
     136,   127,   587,   363,   698,   136,   135,   648,   368,   127,
     584,   137,   372,   587,   127,   127,   601,   135,   133,   126,
     127,   128,   129,   130,   137,   127,   368,    59,    60,    61,
     372,   127,     4,     5,     6,   137,   127,   604,   127,     8,
       9,   137,   127,   127,   136,   127,   137,    19,   137,   136,
     135,   135,   368,   135,    27,    28,   372,     8,     9,   135,
     135,   137,   137,   135,   135,   137,   137,   135,   653,   137,
     136,   765,     8,     9,   135,    30,   137,     0,   135,   135,
     137,   137,   136,   135,     7,   137,    55,    56,    57,    58,
      59,    60,    61,   136,   126,   127,   128,   129,   130,    22,
      23,     5,     6,   136,    55,    56,    57,    58,    59,    60,
      61,    34,     5,     6,    86,    87,    88,    89,    90,    55,
      56,    57,    58,    59,    60,    61,   486,   487,   136,    65,
     136,   491,     5,     6,   106,   107,     5,     6,   498,   136,
     112,   113,   114,   115,   136,   117,   136,   119,   136,   121,
     122,   123,     5,     6,     5,     6,   136,   126,   127,   128,
     129,   130,   136,   523,   136,   525,   135,   135,   137,   754,
       5,     6,     5,     6,   136,   126,   127,   128,   129,   130,
     136,   523,   136,   525,   135,   133,   137,     5,     6,   136,
     126,   127,   128,   129,   130,   134,   135,    46,   783,   559,
     135,   561,     5,     6,     5,     6,   136,   523,   136,   525,
       5,     6,    66,    67,   136,   575,    66,    67,    70,    71,
     136,   144,     5,     6,   584,   585,   136,   587,   588,   136,
     590,   136,   138,   136,   594,   595,   136,   136,   136,   136,
     807,   601,   136,   810,   604,   136,   136,   136,   136,     8,
       9,   136,   136,   176,   177,   136,   136,     0,   136,   619,
     136,   621,   604,   186,   831,   832,   136,   834,   136,   136,
     136,   136,   136,   136,   197,   198,   199,   136,   135,    22,
       5,   641,   642,   206,    21,    21,   209,   135,   604,   212,
     135,    34,   135,   653,   135,   218,    55,    56,    57,    58,
      59,    60,    61,   135,    61,   133,     5,    76,   135,   133,
     135,   133,   133,     7,    42,   135,   239,   240,   241,   242,
     243,   135,   135,     5,   136,   136,   136,   136,   136,   136,
     136,   136,   692,   137,   133,   258,   259,   260,   261,   699,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   137,   137,   135,   135,   278,   279,   280,   281,   282,
     283,   284,     8,     9,   135,   137,   136,   126,   127,   128,
     129,   130,   137,   136,   136,     5,   137,   737,   137,   137,
     136,   741,   137,   743,   137,     7,   746,     3,    34,   312,
     313,   136,   136,   133,   754,    60,   319,    60,    60,    44,
       7,    69,    43,   763,    21,    60,     4,   368,   151,    55,
      56,    57,    58,    59,    60,    61,   776,   777,   634,   779,
     705,   344,    22,   783,   350,    22,   175,   350,   754,   229,
     598,   486,   783,   176,   177,     0,   487,   845,   799,   157,
     363,   628,    31,   345,    -1,   368,    -1,   807,    -1,   372,
     810,    -1,    -1,    -1,   197,   198,   199,    22,    23,     8,
       9,    -1,    -1,    -1,   824,   807,   209,    -1,   810,    34,
      -1,   831,   832,    -1,   834,    -1,    -1,    -1,   221,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,   848,   831,
     832,   807,   834,    -1,   810,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,   831,   832,    -1,   834,    -1,
      -1,    -1,   265,    -1,   267,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   486,   487,    -1,    -1,    -1,   491,   312,
     313,    -1,    -1,    -1,    -1,   498,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
     523,    -1,   525,    -1,    -1,    -1,    -1,   350,    -1,    -1,
      -1,   176,   177,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   368,    -1,    -1,    -1,   372,
      -1,    -1,   197,   198,   199,    -1,   559,    -1,   561,     8,
       9,    -1,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   575,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,   588,    -1,   590,    -1,    -1,
      -1,   594,   595,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,   604,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,   619,    -1,   621,    -1,
     265,    -1,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,   642,
      55,    56,    57,    58,    59,    60,    61,    -1,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   486,   487,    -1,    -1,   312,   313,    -1,
      -1,    -1,    -1,    -1,   319,   498,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   692,
      -1,    -1,    -1,    -1,    -1,    -1,   699,     8,     9,    -1,
     523,    -1,   525,    -1,    -1,   350,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,     8,     9,    -1,    -1,
      -1,    -1,   137,   368,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,    -1,    -1,   737,    -1,    -1,    -1,   741,    -1,
     743,    -1,    -1,   746,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     763,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,   776,   777,   133,   779,    -1,   601,    -1,
      -1,   604,    -1,    -1,    -1,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,   621,    -1,
      -1,    -1,    -1,    -1,   807,    -1,    -1,   810,    -1,    -1,
      -1,    -1,    -1,     7,    -1,   126,   127,   128,   129,   130,
      -1,   824,    -1,    -1,    -1,   183,   137,    -1,   831,   832,
     653,   834,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,   486,   487,     8,     9,   137,    -1,    -1,   206,    -1,
      -1,    -1,    -1,   498,   212,    -1,    -1,    -1,    -1,    -1,
     218,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   699,    -1,   523,    -1,
     525,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
     258,   259,   260,   261,    -1,   263,   264,    -1,   266,    -1,
     268,   269,   270,   271,   272,   273,    -1,    -1,    -1,    -1,
     278,   279,   280,   281,   282,   283,   284,    -1,    -1,    -1,
      -1,   754,    -1,   126,   127,   128,   129,   130,    -1,    -1,
     763,    -1,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,
     783,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,   619,    -1,   621,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   807,    -1,   344,   810,    -1,    -1,
     348,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,   831,   832,
       8,   834,   206,    -1,    -1,    -1,    -1,    -1,   212,    -1,
      -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,    -1,
     388,   389,    -1,    -1,   228,   229,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,   699,     8,     9,    55,    56,    57,
      58,    59,    60,    61,   258,   259,   260,   261,    -1,   263,
     264,    -1,   266,    -1,   268,   269,   270,   271,   272,   273,
      -1,    -1,    -1,    -1,   278,   279,   280,   281,   282,   283,
     284,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   763,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,   491,    -1,   493,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,     8,     9,    -1,    -1,    -1,
     344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   807,    -1,    -1,   810,    -1,    -1,    -1,   363,
     528,   529,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    -1,   831,   832,    -1,   834,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,   559,    -1,   561,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,   575,    -1,    -1,
     137,    -1,    -1,    -1,    -1,    -1,    -1,   585,     8,     9,
     588,    -1,   590,    -1,    -1,    -1,   594,   595,    -1,    -1,
     598,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,    55,    56,    57,    58,    59,
      60,    61,    -1,   641,   642,    -1,    -1,    -1,    -1,    -1,
     648,     8,     9,    -1,    -1,    -1,    -1,   491,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   692,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,    55,    56,
      57,    58,    59,    60,    61,   559,    -1,   561,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   737,
      -1,   575,    -1,   741,    -1,   743,    -1,    -1,   746,    -1,
     584,   585,    -1,   587,   588,    -1,   590,    -1,    -1,    -1,
     594,   595,    -1,    -1,    -1,    -1,    -1,   601,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   776,   777,
     137,   779,   183,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,   200,
     137,   799,    -1,    -1,    -1,    -1,    -1,   641,   642,    -1,
     211,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,   653,
      -1,   222,   223,    -1,   225,    -1,   824,    -1,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   692,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
     301,    -1,    -1,   737,    -1,    -1,    -1,   741,    -1,   743,
     311,    -1,   746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     754,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,   337,    18,    19,    -1,
      -1,    -1,   776,   777,    -1,   779,    -1,   348,    -1,   783,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   364,   365,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,   389,    -1,
     824,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,    93,    -1,    95,    96,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,   454,   455,   136,    -1,   138,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   493,    -1,   495,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,   515,   516,   517,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,   528,   529,    -1,
      -1,    -1,   533,   534,   535,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,   544,    55,    56,    57,    58,    59,    60,
      61,   552,   553,   554,   555,   556,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,   570,
      -1,    -1,   573,    18,    19,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   598,    -1,   137,
      -1,    -1,   603,    -1,    -1,   606,    51,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,   648,    93,    -1,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   709,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,   734,     8,     9,    10,    11,     8,     9,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,   750,
      -1,   752,    -1,    -1,    -1,    -1,   757,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,   780,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,   799,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   819,    93,
      -1,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     8,     9,   126,   127,   128,   129,
     130,    -1,   136,    -1,    -1,    -1,    -1,   137,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,     8,     9,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,    -1,   126,   127,   128,   129,
     130,     8,     9,    -1,    -1,    -1,    -1,   137,   126,   127,
     128,   129,   130,     8,     9,    -1,    -1,    -1,    -1,   137,
     126,   127,   128,   129,   130,     8,     9,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,     8,     9,    -1,    -1,    -1,    -1,   137,    55,    56,
      57,    58,    59,    60,    61,     8,     9,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   126,   127,   128,   129,   130,    -1,    -1,     8,     9,
      -1,    -1,   137,   126,   127,   128,   129,   130,    -1,    -1,
       8,     9,    -1,    -1,   137,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,     8,     9,    -1,    -1,    -1,    -1,
     137,    -1,    -1,   126,   127,   128,   129,   130,     8,     9,
      -1,    -1,    -1,    -1,   137,    55,    56,    57,    58,    59,
      60,    61,     8,     9,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   126,   127,
     128,   129,   130,    -1,    -1,     8,     9,    -1,    -1,   137,
      -1,    -1,   126,   127,   128,   129,   130,     8,     9,    -1,
      -1,    -1,    -1,   137,    -1,    -1,   126,   127,   128,   129,
     130,     8,     9,    -1,    -1,    -1,    -1,   137,    -1,    -1,
     126,   127,   128,   129,   130,     8,     9,    -1,    -1,    -1,
      -1,   137,    55,    56,    57,    58,    59,    60,    61,     8,
       9,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   126,   127,   128,   129,   130,
       8,     9,    -1,    -1,   135,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,     8,     9,    -1,    -1,   135,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,     7,     8,     9,    -1,   126,   127,   128,
     129,   130,     8,     9,    -1,    -1,   135,    55,    56,    57,
      58,    59,    60,    61,     8,     9,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    55,
      56,    57,    58,    59,    60,    61,     8,     9,    -1,    65,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      42,    -1,   126,   127,   128,   129,   130,     8,     9,    -1,
      -1,   135,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      35,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    66,    -1,    68,    -1,    -1,    -1,    72,    -1,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    -1,    -1,    91,    92,    -1,    94,
       5,     6,    97,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    16,    17,    18,    19,    20,   111,    22,    23,    24,
      25,    26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      35,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    47,    48,    49,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      -1,    66,    -1,    68,    -1,    -1,    -1,    72,    -1,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,    88,    -1,    -1,    91,    92,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  parser::yystos_[] =
  {
         0,     5,     6,    12,    13,    14,    16,    17,    18,    19,
      20,    22,    23,    24,    25,    26,    29,    31,    35,    37,
      39,    41,    47,    48,    49,    50,    53,    54,    62,    63,
      64,    66,    68,    72,    74,    75,    86,    87,    88,    91,
      92,    94,    97,   111,   140,   141,   142,   144,   145,   162,
     163,   178,   179,   180,   181,   184,   191,   204,   212,   223,
     228,   234,   239,   243,   248,   265,   271,   272,   273,   274,
     275,   277,   136,   136,   185,     3,     4,     8,     9,    10,
      11,    18,    19,    51,    52,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   136,   165,   166,   168,   173,   178,   180,
     271,   272,   274,   275,   136,   165,   271,   272,   273,   136,
     136,   192,     5,   271,   271,   271,   150,   151,   165,   168,
     205,   229,   235,   224,     5,     6,   162,   163,   271,   272,
     275,     5,     6,   177,   271,   275,   146,   147,   264,   271,
     263,   271,   138,   261,   148,    63,   270,   213,   271,   159,
     160,   271,   272,   274,   275,   161,   271,   136,   136,   136,
     138,   168,   175,   175,   175,   175,   136,     0,    27,    28,
       7,    60,    60,   168,    60,   133,   133,   133,    60,   137,
     137,   186,   136,   136,   168,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   168,   168,   165,   168,    55,    56,
      57,    58,    59,    60,   127,     8,     9,    55,    56,    57,
      58,    59,    60,    61,   126,   127,   128,   129,   130,   165,
     152,   153,     6,   195,   271,   274,   133,    30,   262,   262,
     271,   230,   236,   225,   136,   136,   133,    46,   176,   135,
     133,   176,   198,   199,   271,   272,   274,   275,   200,   201,
     271,   272,   274,   275,   135,   135,     3,   136,   271,   165,
     168,   254,   138,   255,   256,   149,   271,   272,   214,   154,
     135,    21,    21,    21,    21,   135,   164,   271,   274,   275,
     164,   164,   168,   135,   135,   135,   165,   142,   143,   168,
     165,   240,   244,   246,   168,     5,     6,     5,     6,     5,
       6,   165,   190,   271,   274,   168,   168,   168,   174,   167,
       5,     6,   171,   172,   271,   273,   277,   171,   172,   168,
     168,   137,   168,   168,   168,   168,   168,   168,   168,   165,
     165,   165,   165,   165,   165,   175,   175,   175,   175,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   165,
     165,   165,   165,   168,   165,   165,   164,   165,   164,   165,
     165,   165,   165,   165,   165,   137,   137,   165,   165,   165,
     165,   165,   165,   165,   170,   169,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   165,   168,
     182,   183,   182,   193,   133,     5,    60,   168,   142,   142,
       5,     6,    76,   272,   275,     6,   135,   135,   271,   271,
     168,    65,   134,   135,     3,   136,   271,   165,   260,   255,
     133,   266,   133,   267,   165,   168,   217,     7,   216,   160,
     271,   271,   271,   271,   271,   135,   135,   135,   165,   168,
     168,   137,   144,    42,   145,   216,   136,   136,   136,   136,
     136,   136,   187,   135,   135,   135,   182,   182,   136,   136,
     137,   137,   133,   135,   135,   137,   137,   137,   137,   137,
     137,   137,   135,   135,   135,   135,   135,   137,   137,   135,
     137,   135,   137,   137,   137,   137,   137,   137,   137,   137,
     135,   137,   137,   135,   137,   135,   137,   137,   137,   137,
     137,   137,   137,   137,   135,   135,   137,   135,   135,   137,
     135,   137,   137,   137,   135,   135,   168,   168,   135,   137,
     137,   136,     6,   206,   231,    27,    38,   237,    27,    40,
     226,   136,   136,   199,   201,   137,   165,   165,   168,   258,
     168,   257,   253,   271,   272,   274,   275,   216,   216,   216,
       3,     4,     7,   126,   155,   156,   157,   158,   168,   168,
     168,   135,   135,   142,   245,   145,   137,   137,   276,   182,
     182,   137,   137,   136,   168,   168,   168,   137,   137,     5,
       6,   168,   168,   168,   168,   168,   168,   168,   165,   165,
     168,   168,   165,   172,   165,   172,   165,   165,   165,   165,
     183,     6,   196,   197,   271,   273,   274,   277,   168,   142,
     168,   227,    65,   253,   137,   253,   265,   268,   269,   270,
     268,   218,     3,    73,   156,   135,   216,   137,   137,   135,
     137,   165,   165,   241,   182,   137,   137,   202,   203,   271,
     273,   274,   277,   137,   137,   137,   136,   136,   137,   137,
     137,   137,   137,   137,   135,   137,   137,   135,   137,   137,
     137,   135,   137,   135,   137,   137,   135,   137,   137,   137,
     135,   137,   135,   137,   135,   137,   133,    32,    27,    36,
     232,   238,   165,   259,    67,   269,   216,   271,   272,   274,
     275,    67,    70,    71,   220,   158,    60,    60,   168,    60,
      44,   250,   137,   135,   137,   168,   165,   165,   165,   165,
     168,   168,   197,   194,     6,   168,   233,   253,   216,   219,
       7,    69,   165,   165,   137,   165,   168,    43,   249,   203,
     188,   137,   137,   137,   137,   137,   137,   137,    21,    34,
     211,   217,   221,   215,    60,    42,   142,   242,   142,     4,
     168,   207,   222,   165,   251,    27,    45,   247,    15,    27,
     189,   142,   142,   142,   208,   252,    27,    33,   209,   250,
     210,   271
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
     375,   376,   377,   378,   379,   380,    45,    43,    42,    47,
     381,   382,   383,    46,    59,    44,    40,    41,    35
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  parser::yyr1_[] =
  {
         0,   139,   140,   141,   141,   142,   143,   142,   144,   144,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   146,   145,
     147,   145,   145,   145,   145,   148,   145,   149,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   150,   145,   151,   145,   145,   145,   145,   145,   145,
     145,   145,   152,   145,   153,   145,   154,   145,   145,   145,
     155,   155,   156,   157,   157,   158,   158,   158,   159,   159,
     160,   160,   160,   160,   161,   161,   162,   162,   163,   163,
     163,   163,   163,   163,   164,   164,   165,   165,   165,   165,
     165,   165,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   166,   169,   168,   170,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   171,   172,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   174,   173,   175,   175,   176,   176,
     177,   177,   177,   177,   178,   178,   179,   180,   180,   181,
     182,   182,   183,   183,   185,   186,   187,   188,   184,   189,
     189,   190,   190,   192,   193,   194,   191,   195,   195,   196,
     196,   196,   197,   197,   197,   197,   198,   198,   199,   199,
     199,   199,   200,   200,   201,   201,   201,   201,   202,   202,
     202,   203,   203,   203,   203,   205,   206,   207,   208,   204,
     209,   209,   210,   210,   211,   211,   213,   214,   215,   212,
     216,   216,   217,   217,   218,   219,   218,   220,   221,   222,
     220,   224,   225,   223,   226,   227,   226,   229,   230,   231,
     228,   232,   233,   232,   235,   236,   234,   237,   238,   237,
     240,   241,   242,   239,   244,   245,   243,   246,   243,   247,
     247,   248,   249,   249,   250,   251,   252,   250,   253,   253,
     253,   253,   254,   254,   254,   254,   254,   254,   254,   256,
     255,   257,   255,   258,   255,   259,   255,   260,   261,   261,
     261,   261,   262,   263,   263,   264,   264,   266,   265,   267,
     265,   268,   268,   269,   269,   269,   269,   269,   270,   271,
     271,   272,   272,   272,   272,   273,   273,   273,   273,   274,
     274,   275,   275,   275,   276,   275,   277,   277,   277,   277
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     1,     3,     1,     0,     4,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       0,     3,     3,     4,     4,     0,     3,     0,     4,     1,
       2,     2,     2,     4,     1,     2,     4,     6,     2,     4,
       6,     0,     3,     0,     3,     2,     2,     2,     2,     2,
       4,     2,     0,     5,     0,     5,     0,     6,     2,     2,
       1,     2,     2,     1,     3,     1,     2,     1,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,    10,
       8,     8,     8,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     6,     6,     8,     6,     4,     6,     8,     4,
       4,     4,     4,     4,     4,     6,     4,     6,     4,     1,
       1,     4,     4,     0,     5,     0,     4,     0,     4,     2,
       3,     3,     3,     3,     3,     3,     4,     6,     1,     4,
       4,     6,     6,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       3,     6,     6,     4,     4,     4,     6,     8,     6,     8,
       4,     6,     6,     6,     8,     6,     8,     6,     4,     6,
       6,     8,     4,     4,     0,     5,     2,     1,     0,     2,
       2,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     0,     0,     0,     0,    11,     1,
       1,     1,     1,     0,     0,     0,    10,     1,     1,     0,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     0,     1,
       3,     1,     1,     1,     1,     0,     0,     0,     0,    14,
       1,     1,     0,     1,     0,     2,     0,     0,     0,     9,
       1,     2,     1,     1,     0,     0,     4,     0,     0,     0,
       5,     0,     0,     5,     1,     0,     2,     0,     0,     0,
       7,     1,     0,     2,     0,     0,     5,     1,     0,     3,
       0,     0,     0,    10,     0,     0,     5,     0,     5,     1,
       1,     1,     0,     2,     0,     0,     0,     7,     1,     1,
       1,     1,     0,     1,     3,     1,     3,     5,     3,     0,
       3,     0,     4,     0,     4,     0,     6,     1,     0,     2,
       2,     4,     1,     1,     3,     1,     3,     0,     7,     0,
       7,     2,     3,     1,     2,     2,     2,     2,     0,     1,
       3,     2,     6,     3,     4,     3,     5,     3,     5,     1,
       3,     2,     6,     3,     0,     7,     3,     5,     3,     5
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
  "tENDDATA", "tREAD", "tRESTORE", "tLONG", "tABS", "tSIG", "tRAN", "tSQR",
  "tSQRT", "tINT", "tFRAC", "tMIN", "tMAX", "tLEFT", "tRIGHT", "tMID",
  "tUPPER", "tLOWER", "tOPEN", "tCLOSE", "tEOF", "tSEEK", "tTELL", "tPEEK",
  "tPOKE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP",
  "tLOG", "tSTR", "tCHR", "tVAL", "tASC", "tLEN", "tSYSTEM", "tARG",
  "tENV", "tTIME", "tDATE", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT",
  "tGLOB", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "'-'", "'+'",
  "'*'", "'/'", "tMOD", "UPLUS", "UMINUS", "'.'", "';'", "','", "'('",
  "')'", "'#'", "$accept", "program", "list_of_statement_lists",
  "statement_list", "$@1", "statement", "non_empty_statement", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "data_list",
  "data_row", "data_row_items", "data_item", "read_list", "read_item",
  "restore_list", "number_assignment", "string_assignment",
  "string_scalar_or_array", "string_expression", "string_function", "$@11",
  "number_expression", "$@12", "$@13", "number_arrayref",
  "string_arrayref", "number_function", "$@14", "hashed_number",
  "dim_as_type", "dim_list", "number_function_or_array_any_params",
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
       140,     0,    -1,   141,    27,    -1,   142,    -1,   141,    28,
     142,    -1,   144,    -1,    -1,   142,     7,   143,   144,    -1,
      -1,   145,    -1,   162,    -1,   163,    -1,    47,   162,    -1,
      47,   163,    -1,   239,    -1,   243,    -1,   223,    -1,   204,
      -1,   234,    -1,   228,    -1,   212,    -1,    12,    -1,    13,
      -1,   184,    -1,   191,    -1,   265,    -1,   178,    -1,   180,
      -1,    -1,    49,   146,   198,    -1,    -1,    50,   147,   200,
      -1,    62,   261,   254,    -1,    62,   261,   254,   134,    -1,
      62,   261,   254,   135,    -1,    -1,    63,   148,   255,    -1,
      -1,    64,    63,   149,   255,    -1,    16,    -1,    16,   168,
      -1,    16,   165,    -1,    48,   177,    -1,   111,   136,   165,
     137,    -1,    29,    -1,    29,   168,    -1,    91,   175,   135,
     165,    -1,    91,   175,   135,   165,   135,   165,    -1,    92,
     175,    -1,    94,   175,   135,   168,    -1,    94,   175,   135,
     168,   135,   165,    -1,    -1,    25,   150,   262,    -1,    -1,
      26,   151,   262,    -1,    54,   263,    -1,    53,   264,    -1,
      22,   271,    -1,    23,   271,    -1,    24,   271,    -1,    97,
     175,   135,   168,    -1,    17,   165,    -1,    -1,    18,   136,
     152,   182,   137,    -1,    -1,    19,   136,   153,   182,   137,
      -1,    -1,    72,   271,   154,   216,   155,    73,    -1,    74,
     159,    -1,    75,   161,    -1,   156,    -1,   155,   156,    -1,
     157,   216,    -1,   158,    -1,   157,   135,   158,    -1,     3,
      -1,   126,     3,    -1,     4,    -1,   160,    -1,   159,   135,
     160,    -1,   271,    21,   271,    -1,   274,    21,   271,    -1,
     272,    21,   271,    -1,   275,    21,   271,    -1,   271,    -1,
     161,   135,   271,    -1,   271,    60,   168,    -1,   179,    60,
     168,    -1,   274,    60,   165,    -1,    88,   136,   164,   135,
     168,   135,   168,   137,    60,   165,    -1,    88,   136,   164,
     135,   168,   137,    60,   165,    -1,    86,   136,   164,   135,
     168,   137,    60,   165,    -1,    87,   136,   164,   135,   168,
     137,    60,   165,    -1,   181,    60,   165,    -1,   274,    -1,
     275,    -1,   274,    -1,   166,    -1,   180,    -1,     4,    -1,
     165,   127,   165,    -1,   136,   165,   137,    -1,    86,   136,
     165,   135,   168,   137,    -1,    87,   136,   165,   135,   168,
     137,    -1,    88,   136,   165,   135,   168,   135,   168,   137,
      -1,    88,   136,   165,   135,   168,   137,    -1,   106,   136,
     168,   137,    -1,   106,   136,   168,   135,   165,   137,    -1,
     106,   136,   168,   135,   165,   135,   165,   137,    -1,   107,
     136,   168,   137,    -1,    89,   136,   165,   137,    -1,    90,
     136,   165,   137,    -1,   122,   136,   165,   137,    -1,   123,
     136,   165,   137,    -1,   121,   136,   165,   137,    -1,   117,
     136,   164,   135,   165,   137,    -1,   117,   136,   164,   137,
      -1,   119,   136,   164,   135,   165,   137,    -1,   119,   136,
     164,   137,    -1,   115,    -1,   114,    -1,   112,   136,   168,
     137,    -1,   113,   136,   165,   137,    -1,    -1,    19,   136,
     167,   182,   137,    -1,    -1,   168,     9,   169,   168,    -1,
      -1,   168,     8,   170,   168,    -1,    10,   168,    -1,   168,
      60,   168,    -1,   168,    55,   168,    -1,   168,    58,   168,
      -1,   168,    56,   168,    -1,   168,    59,   168,    -1,   168,
      57,   168,    -1,    93,   136,   175,   137,    -1,   120,   136,
     165,   135,   165,   137,    -1,     3,    -1,    51,   136,   171,
     137,    -1,    51,   136,   172,   137,    -1,    52,   136,   171,
     135,   168,   137,    -1,    52,   136,   172,   135,   168,   137,
      -1,   178,    -1,   271,    -1,   168,   127,   168,    -1,   168,
     126,   168,    -1,   168,   128,   168,    -1,   168,   129,   168,
      -1,   168,   130,   168,    -1,   168,    61,   168,    -1,   126,
     168,    -1,   127,   168,    -1,   165,    60,   165,    -1,   165,
      55,   165,    -1,   165,    58,   165,    -1,   165,    56,   165,
      -1,   165,    59,   165,    -1,   165,    57,   165,    -1,   173,
      -1,   136,   168,   137,    -1,   273,    -1,   277,    -1,    98,
     136,   168,   137,    -1,    99,   136,   168,   137,    -1,   100,
     136,   168,   137,    -1,   101,   136,   168,   137,    -1,   102,
     136,   168,   137,    -1,   103,   136,   168,   137,    -1,   103,
     136,   168,   135,   168,   137,    -1,   104,   136,   168,   137,
      -1,   105,   136,   168,   137,    -1,   105,   136,   168,   135,
     168,   137,    -1,    82,   136,   168,   137,    -1,    80,   136,
     168,   137,    -1,    81,   136,   168,   137,    -1,    83,   136,
     168,   137,    -1,    77,   136,   168,   137,    -1,    78,   136,
     168,   137,    -1,    79,   136,   168,   137,    -1,    79,   136,
     137,    -1,    84,   136,   168,   135,   168,   137,    -1,    85,
     136,   168,   135,   168,   137,    -1,   110,   136,   165,   137,
      -1,   108,   136,   165,   137,    -1,   109,   136,   165,   137,
      -1,   124,   136,   165,   135,   165,   137,    -1,   124,   136,
     165,   135,   165,   135,   168,   137,    -1,   125,   136,   165,
     135,   165,   137,    -1,   125,   136,   165,   135,   165,   135,
     168,   137,    -1,   111,   136,   165,   137,    -1,     8,   136,
     168,   135,   168,   137,    -1,     9,   136,   168,   135,   168,
     137,    -1,    11,   136,   168,   135,   168,   137,    -1,   116,
     136,   165,   135,   172,   135,   165,   137,    -1,   116,   136,
     165,   135,   172,   137,    -1,   118,   136,   165,   135,   172,
     135,   165,   137,    -1,   118,   136,   165,   135,   172,   137,
      -1,    91,   136,   165,   137,    -1,    91,   136,   165,   135,
     165,   137,    -1,    91,   136,   175,   135,   165,   137,    -1,
      91,   136,   175,   135,   165,   135,   165,   137,    -1,    95,
     136,   175,   137,    -1,    96,   136,   175,   137,    -1,    -1,
      18,   136,   174,   182,   137,    -1,   138,   168,    -1,   168,
      -1,    -1,    46,    76,    -1,     5,   176,    -1,   275,   176,
      -1,   177,   135,   272,    -1,   177,   135,   275,    -1,   272,
      -1,   273,    -1,   272,    -1,   275,    -1,   277,    -1,   275,
      -1,   183,    -1,   182,   135,   183,    -1,   165,    -1,   168,
      -1,    -1,    -1,    -1,    -1,    14,   185,   186,   190,   187,
     136,   202,   137,   188,   142,   189,    -1,    27,    -1,    15,
      -1,   271,    -1,   274,    -1,    -1,    -1,    -1,    20,   192,
     195,   193,   136,   196,   137,   194,    21,     4,    -1,   271,
      -1,   274,    -1,    -1,   197,    -1,   196,   135,   197,    -1,
     271,    -1,   274,    -1,   273,    -1,   277,    -1,   199,    -1,
     198,   135,   199,    -1,   271,    -1,   274,    -1,   272,    -1,
     275,    -1,   201,    -1,   200,   135,   201,    -1,   271,    -1,
     274,    -1,   272,    -1,   275,    -1,    -1,   203,    -1,   202,
     135,   203,    -1,   271,    -1,   274,    -1,   273,    -1,   277,
      -1,    -1,    -1,    -1,    -1,    31,   205,   271,    60,   206,
     168,    32,   168,   211,   207,   142,   208,   209,   210,    -1,
      27,    -1,    33,    -1,    -1,   271,    -1,    -1,    34,   168,
      -1,    -1,    -1,    -1,    68,   213,   214,   217,   216,   218,
     220,    69,   215,    -1,     7,    -1,   216,     7,    -1,   168,
      -1,   165,    -1,    -1,    -1,   218,    70,   219,   217,    -1,
      -1,    -1,    -1,    71,     7,   221,   222,   142,    -1,    -1,
      -1,    39,   224,   225,   142,   226,    -1,    27,    -1,    -1,
      40,   227,    -1,    -1,    -1,    -1,    35,   229,   230,   168,
     231,   142,   232,    -1,    27,    -1,    -1,    36,   233,    -1,
      -1,    -1,    37,   235,   236,   142,   237,    -1,    27,    -1,
      -1,    38,   168,   238,    -1,    -1,    -1,    -1,   248,   168,
     240,    42,   142,   241,   250,   249,   242,   247,    -1,    -1,
      -1,   248,   168,   244,   145,   245,    -1,    -1,   248,   168,
     246,   216,   145,    -1,    27,    -1,    45,    -1,    41,    -1,
      -1,    43,   142,    -1,    -1,    -1,    -1,    44,   168,    42,
     251,   142,   252,   250,    -1,   271,    -1,   274,    -1,   272,
      -1,   275,    -1,    -1,   168,    -1,   168,    65,   165,    -1,
     165,    -1,   254,   135,   168,    -1,   254,   135,   168,    65,
     165,    -1,   254,   135,   165,    -1,    -1,   256,   260,   253,
      -1,    -1,   138,   271,   257,   253,    -1,    -1,   138,     3,
     258,   253,    -1,    -1,   138,   136,   168,   137,   259,   253,
      -1,   165,    -1,    -1,   138,   271,    -1,   138,     3,    -1,
     138,   136,   168,   137,    -1,    30,    -1,   271,    -1,   263,
     135,   271,    -1,   271,    -1,   264,   135,   271,    -1,    -1,
      66,   270,   271,   266,   216,   268,    67,    -1,    -1,    66,
     270,   272,   267,   216,   268,    67,    -1,   269,   216,    -1,
     268,   269,   216,    -1,   265,    -1,   270,   271,    -1,   270,
     274,    -1,   270,   272,    -1,   270,   275,    -1,    -1,     5,
      -1,   271,   133,     5,    -1,     5,   136,    -1,   272,   133,
       5,   136,   182,   137,    -1,   272,   133,     5,    -1,   271,
     133,     5,   136,    -1,     5,   136,   137,    -1,   273,   133,
       5,   136,   137,    -1,   273,   133,     5,    -1,   271,   133,
       5,   136,   137,    -1,     6,    -1,   271,   133,     6,    -1,
       6,   136,    -1,   272,   133,     6,   136,   182,   137,    -1,
     272,   133,     6,    -1,    -1,   271,   133,     6,   136,   276,
     182,   137,    -1,     6,   136,   137,    -1,   273,   133,     6,
     136,   137,    -1,   273,   133,     6,    -1,   271,   133,     6,
     136,   137,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    12,    14,    15,    20,    21,
      23,    25,    27,    30,    33,    35,    37,    39,    41,    43,
      45,    47,    49,    51,    53,    55,    57,    59,    61,    62,
      66,    67,    71,    75,    80,    85,    86,    90,    91,    96,
      98,   101,   104,   107,   112,   114,   117,   122,   129,   132,
     137,   144,   145,   149,   150,   154,   157,   160,   163,   166,
     169,   174,   177,   178,   184,   185,   191,   192,   199,   202,
     205,   207,   210,   213,   215,   219,   221,   224,   226,   228,
     232,   236,   240,   244,   248,   250,   254,   258,   262,   266,
     277,   286,   295,   304,   308,   310,   312,   314,   316,   318,
     320,   324,   328,   335,   342,   351,   358,   363,   370,   379,
     384,   389,   394,   399,   404,   409,   416,   421,   428,   433,
     435,   437,   442,   447,   448,   454,   455,   460,   461,   466,
     469,   473,   477,   481,   485,   489,   493,   498,   505,   507,
     512,   517,   524,   531,   533,   535,   539,   543,   547,   551,
     555,   559,   562,   565,   569,   573,   577,   581,   585,   589,
     591,   595,   597,   599,   604,   609,   614,   619,   624,   629,
     636,   641,   646,   653,   658,   663,   668,   673,   678,   683,
     688,   692,   699,   706,   711,   716,   721,   728,   737,   744,
     753,   758,   765,   772,   779,   788,   795,   804,   811,   816,
     823,   830,   839,   844,   849,   850,   856,   859,   861,   862,
     865,   868,   871,   875,   879,   881,   883,   885,   887,   889,
     891,   893,   897,   899,   901,   902,   903,   904,   905,   917,
     919,   921,   923,   925,   926,   927,   928,   939,   941,   943,
     944,   946,   950,   952,   954,   956,   958,   960,   964,   966,
     968,   970,   972,   974,   978,   980,   982,   984,   986,   987,
     989,   993,   995,   997,   999,  1001,  1002,  1003,  1004,  1005,
    1020,  1022,  1024,  1025,  1027,  1028,  1031,  1032,  1033,  1034,
    1044,  1046,  1049,  1051,  1053,  1054,  1055,  1060,  1061,  1062,
    1063,  1069,  1070,  1071,  1077,  1079,  1080,  1083,  1084,  1085,
    1086,  1094,  1096,  1097,  1100,  1101,  1102,  1108,  1110,  1111,
    1115,  1116,  1117,  1118,  1129,  1130,  1131,  1137,  1138,  1144,
    1146,  1148,  1150,  1151,  1154,  1155,  1156,  1157,  1165,  1167,
    1169,  1171,  1173,  1174,  1176,  1180,  1182,  1186,  1192,  1196,
    1197,  1201,  1202,  1207,  1208,  1213,  1214,  1221,  1223,  1224,
    1227,  1230,  1235,  1237,  1239,  1243,  1245,  1249,  1250,  1258,
    1259,  1267,  1270,  1274,  1276,  1279,  1282,  1285,  1288,  1289,
    1291,  1295,  1298,  1305,  1309,  1314,  1318,  1324,  1328,  1334,
    1336,  1340,  1343,  1350,  1354,  1355,  1363,  1367,  1373,  1377
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   183,   183,   197,   198,   201,   202,   202,   211,   212,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   230,   236,   237,   238,   239,   240,   241,   241,
     242,   242,   243,   251,   256,   261,   261,   262,   262,   263,
     266,   271,   272,   275,   278,   279,   280,   281,   282,   283,
     284,   285,   285,   286,   286,   287,   288,   289,   292,   293,
     296,   297,   298,   298,   301,   301,   302,   302,   303,   304,
     307,   308,   311,   314,   315,   318,   319,   320,   323,   324,
     327,   328,   329,   330,   333,   334,   337,   338,   341,   342,
     343,   344,   345,   346,   351,   352,   355,   356,   357,   358,
     359,   360,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   384,   387,   387,   388,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   423,   426,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   470,   473,   474,   477,   478,
     485,   489,   490,   491,   494,   495,   498,   501,   502,   505,
     508,   509,   512,   513,   516,   516,   518,   521,   516,   530,
     536,   539,   542,   545,   548,   551,   545,   559,   565,   573,
     574,   575,   578,   581,   584,   587,   592,   593,   596,   597,
     598,   599,   602,   603,   606,   607,   608,   609,   612,   613,
     614,   617,   618,   621,   624,   629,   630,   634,   636,   629,
     642,   647,   650,   651,   654,   655,   658,   658,   660,   658,
     665,   666,   669,   670,   673,   674,   674,   682,   683,   683,
     683,   689,   689,   689,   694,   695,   695,   698,   698,   699,
     698,   705,   706,   706,   709,   709,   709,   714,   716,   715,
     719,   720,   722,   719,   726,   727,   726,   728,   728,   732,
     733,   736,   739,   740,   743,   745,   747,   744,   751,   752,
     753,   754,   757,   758,   763,   765,   767,   769,   771,   775,
     775,   776,   776,   777,   777,   778,   778,   781,   785,   790,
     791,   792,   795,   798,   799,   802,   803,   807,   807,   823,
     823,   841,   842,   845,   846,   854,   862,   870,   880,   888,
     889,   892,   894,   895,   896,   899,   902,   903,   904,   907,
     908,   911,   912,   913,   914,   914,   917,   918,   919,   920
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
       2,     2,     2,     2,     2,   138,     2,     2,     2,     2,
     136,   137,   128,   127,   135,   126,   133,   129,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   134,
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
     125,   130,   131,   132
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 3536;
  const int parser::yynnts_ = 139;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 207;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 139;

  const unsigned int parser::yyuser_token_number_max_ = 383;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 22 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 4308 "/home/cai/projects/basic/compiler/parser.cpp"
