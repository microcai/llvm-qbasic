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
std::string current_function;  /* name of currently parsed function */
int in_loop = 0;                /* in loop? */

/* Local variables. */
int continue_corrections = 0;   /* continue corrections */
int unclosed_dos = 0;           /* unclosed "if" count */
int unclosed_fors = 0;          /* unclosed "for" count */
int unclosed_ifs = 0;           /* unclosed "if" count */
int unclosed_repeats = 0;       /* unclosed "repeat" count */
int unclosed_subs = 0;          /* unclosed subroutine count */
int unclosed_switches = 0;      /* unclosed "switch" count */
int unclosed_whiles = 0;        /* unclosed "while" count */
bool until_eol = false;          /* read to end of line? */
bool useDefautSubMain = false;	/* shall we treat the while file as an sub main ? */

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
#line 199 "parser.ypp"
    {
			if(useDefautSubMain){
				debug("program ended\n");
				program = new DefaultMainFunctionAST( (yysemantic_stack_[(2) - (1)].statement_list) );
			}else{
				program = (yysemantic_stack_[(2) - (1)].statement_list);
				debug("module ended\n");
			}
			
			/*add_command (cEOPROG, NULL);*/
			// yylex_destroy ();
			YYACCEPT;
		}
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 216 "parser.ypp"
    { (yyval.statement_list) = new StatementAST(); (yyval.statement_list)->addchild(StatementASTPtr((yysemantic_stack_[(1) - (1)].statement)));
			debug("statement_list %p app %p  now\n", (yyval.statement_list) , (yysemantic_stack_[(1) - (1)].statement));
}
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 219 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 219 "parser.ypp"
    {
			(yyval.statement_list) = (yysemantic_stack_[(4) - (1)].statement_list);
			debug("statement_list %p app %p  now\n", (yyval.statement_list) , (yysemantic_stack_[(4) - (4)].statement));
			(yyval.statement_list)->addchild( StatementASTPtr((yysemantic_stack_[(4) - (4)].statement)) );
	}
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 226 "parser.ypp"
    { (yyval.statement) = new EmptyStmtAST(); debug("got empty statement %p\n" , (yyval.statement)); }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 227 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); debug( "got non_empty_statement %p\n", (yyval.statement) ); }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 235 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { debug ("cannot \"break\" outside of loop"); }
   }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   debug ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 245 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].function_definition) ; debug ("got function %p as statement\n", (yyval.statement)) ;  }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 246 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now\n");
	   //TODO 最后一个是 \new line
		(yysemantic_stack_[(3) - (3)].print_list)->additem(boost::make_shared<EmptyExprAST>());
	   
		(yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(3) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(3) - (3)].print_list)));

		if(current_function.empty())
			useDefautSubMain = true;

   }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 258 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
	   if(current_function.empty())
			useDefautSubMain = true;
   }
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 265 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
	   if(current_function.empty())
			useDefautSubMain = true;
   }
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 272 "parser.ypp"
    {}
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 273 "parser.ypp"
    {	   
   }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 276 "parser.ypp"
    { }
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 277 "parser.ypp"
    { }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 278 "parser.ypp"
    {}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 279 "parser.ypp"
    {}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 280 "parser.ypp"
    {}
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 281 "parser.ypp"
    {}
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 282 "parser.ypp"
    {}
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 283 "parser.ypp"
    {}
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 284 "parser.ypp"
    {}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 285 "parser.ypp"
    {
   }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 287 "parser.ypp"
    {  }
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 288 "parser.ypp"
    {
		debug("got label!\n");
   }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 291 "parser.ypp"
    {  }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    {  (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list); 	}
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 295 "parser.ypp"
    {
		// 变量赋值
		debug("变量赋值\n");
		(yyval.number_assignment) = new NumberAssigmentAST(VariableRefExprASTPtr((yysemantic_stack_[(3) - (1)].varable_ref)), NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
		if(current_function.empty())
			useDefautSubMain = true;
	}
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 305 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 306 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 310 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 311 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 312 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 313 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 314 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 315 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 316 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 317 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 318 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 319 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 320 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 321 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 322 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 323 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 325 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 326 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 330 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 330 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 331 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 332 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 333 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 334 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 335 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 336 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 337 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 338 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 339 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 71:
/* Line 661 of lalr1.cc  */
#line 340 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 341 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 73:
/* Line 661 of lalr1.cc  */
#line 342 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 343 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 344 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 345 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 78:
/* Line 661 of lalr1.cc  */
#line 347 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 79:
/* Line 661 of lalr1.cc  */
#line 348 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 349 "parser.ypp"
    {
	   (yyval.number_expression) = (yysemantic_stack_[(2) - (2)].number_expression) ;
   }
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 352 "parser.ypp"
    {
	   /*add_command(cNEGATE,NULL);*/
	   ConstNumberExprAST * zero = new ConstNumberExprAST(0);
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr(zero) ,OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression)));
   }
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_MUL,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 360 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_DIV,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 363 "parser.ypp"
    {
	   // 减法计算
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 367 "parser.ypp"
    {
	   // 加法计算.
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_ADD,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 371 "parser.ypp"
    { (yyval.number_expression) = (yysemantic_stack_[(3) - (2)].number_expression) ;}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {
	   debug("got numsym_s\n");	   
	   (yyval.number_expression) =new NumberExprAST( VariableExprASTPtr((yysemantic_stack_[(1) - (1)].varable_ref)) );
	}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 376 "parser.ypp"
    {
	   (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));
   }
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 381 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 382 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 389 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 390 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 414 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 415 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 427 "parser.ypp"
    {
		//TODO int should be 32bit not 64bit
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {
			debug("as  %s\n",(yysemantic_stack_[(2) - (2)].exprtype)->name.c_str());
			// long varable
			// 构造类型
			(yyval.exprtype) = (yysemantic_stack_[(2) - (2)].exprtype);
		}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 442 "parser.ypp"
    {
		/*变量定义*/
		// 在 AST 中分配一个变量名称列表.
		std::string name;
		name = (yysemantic_stack_[(2) - (1)].symbol);
		(yyval.dim_list) = new VariableDimAST( name , ExprTypeASTPtr((yysemantic_stack_[(2) - (2)].exprtype)));		
	}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 449 "parser.ypp"
    {
	  // 	std::string name;
	//	name = $3;
	//	$$ = new VariableDimAST( name , ExprTypeASTPtr($2));
   }
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 457 "parser.ypp"
    { debug("then part %p\n" , (yysemantic_stack_[(4) - (4)].statement_list));}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 458 "parser.ypp"
    {
				//TODO
				debug("syntax not supported yet\n");
			}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 462 "parser.ypp"
    {
				debug("else part %p\n" , (yysemantic_stack_[(8) - (8)].statement_list));
			}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 465 "parser.ypp"
    {

				(yyval.if_clause) = new IFStmtAST( NumberExprASTPtr( (yysemantic_stack_[(10) - (2)].number_expression)));
				(yyval.if_clause)->_then = StatementASTPtr((yysemantic_stack_[(10) - (4)].statement_list));

				if((yysemantic_stack_[(10) - (4)].statement_list))
					(yysemantic_stack_[(10) - (4)].statement_list)->parent = (yyval.if_clause);

				(yyval.if_clause)->_else = StatementASTPtr((yysemantic_stack_[(10) - (8)].statement_list));
				if((yysemantic_stack_[(10) - (8)].statement_list))
					(yysemantic_stack_[(10) - (8)].statement_list)->parent = (yyval.if_clause);

			}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 480 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 481 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 481 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 482 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 483 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 487 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    { (yyval.statement_list) = 0; }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    {	(yyval.statement_list) = (yysemantic_stack_[(2) - (2)].statement_list);}
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 499 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 505 "parser.ypp"
    { unclosed_whiles++; debug("while ...\n"); }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 507 "parser.ypp"
    {
		//TODO 添加 while 循环
		(yyval.while_loop) = new WhileLoopAST( NumberExprASTPtr((yysemantic_stack_[(5) - (3)].number_expression)) , StatementASTPtr((yysemantic_stack_[(5) - (4)].statement_list)) );
		(yysemantic_stack_[(5) - (4)].statement_list)->parent = (yyval.while_loop);
	}
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 513 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 514 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 514 "parser.ypp"
    { }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 517 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 518 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 522 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
	}
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 523 "parser.ypp"
    {
		(yyval.cppstring) = new std::string((yysemantic_stack_[(3) - (3)].symbol));
		debug("====begin function %s====\n",(yysemantic_stack_[(3) - (3)].symbol));
		current_function = (yysemantic_stack_[(3) - (3)].symbol);
	}
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 529 "parser.ypp"
    {
		(yyval.function_definition) = new FunctionDimAST(current_function, ExprTypeASTPtr((yysemantic_stack_[(10) - (8)].exprtype)) );
		(yyval.function_definition)->body = StatementASTPtr((yysemantic_stack_[(10) - (9)].statement_list));
		debug("====end function %s==== %p , body = %p\n",((yysemantic_stack_[(10) - (4)].cppstring))->c_str(),(yyval.function_definition) , (yysemantic_stack_[(10) - (9)].statement_list));
		delete (yysemantic_stack_[(10) - (4)].cppstring);
		current_function.clear();
	}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 538 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 544 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 545 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 548 "parser.ypp"
    {
		(yyval.print_list) = new PrintListAST();
	}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 551 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 557 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 559 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 561 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 563 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 565 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 568 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 573 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 574 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 575 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 585 "parser.ypp"
    {
               debug("变量引用\n");
               (yyval.varable_ref) = new VariableRefExprAST( (yysemantic_stack_[(1) - (1)].symbol) );
       }
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 590 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 591 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;


/* Line 661 of lalr1.cc  */
#line 1601 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const short int parser::yypact_ninf_ = -267;
  const short int
  parser::yypact_[] =
  {
      1857,  -267,  -267,  -267,  -267,   750,  -267,     1,     1,     1,
     750,  -267,  -267,     1,    33,     3,   524,   524,   524,   524,
     -85,   112,   135,   156,  -267,  -267,  -267,  -267,  -267,   750,
    -267,  -267,  -267,   105,  -267,  -267,    42,    43,   750,    44,
      45,    84,    87,   108,   109,   128,   132,   133,   134,   154,
     157,   160,   169,   186,   187,   200,   201,   203,   213,   224,
     237,   238,   239,   240,   241,   243,   244,   251,   252,   253,
     259,   269,   272,   273,  -267,  -267,   274,   275,   276,   277,
     281,   283,   750,   750,   750,    -2,  -267,  1710,  -267,  -267,
    -267,  -267,  -267,    -2,  1710,   750,  -267,   219,   285,     7,
     750,   750,  1710,   286,  -267,   287,   288,   140,  -267,  -267,
    -267,    19,   329,   750,   750,   750,   111,   750,   750,   750,
     637,   750,   750,   750,   750,   750,   750,   140,   140,   140,
     140,   140,   524,   524,   524,   524,   750,   750,   750,   750,
     750,   750,   750,   750,   750,   750,   140,   140,   140,   140,
     750,   140,   140,   140,   140,   140,   140,   140,   317,   317,
     -27,   754,   140,   140,   140,   140,   140,   140,   140,  -267,
    -267,   750,   750,   750,   750,   750,   750,   750,   750,   750,
     750,   750,   750,   426,   -16,  -267,   420,  -267,   750,  -267,
      -2,  1607,    26,  1710,   140,   750,   750,   140,  -100,  1857,
    1857,  1857,   419,  -267,  1710,   255,  1480,  1561,   850,   862,
    -267,   876,   896,   908,   991,  1003,  1571,  1583,   -93,   -62,
      -5,   -87,   -56,   -11,   292,   291,   293,   295,  1015,  1027,
    1039,  1051,  1134,    47,  1146,   342,   435,  1158,   -26,    76,
      94,    95,  1170,    97,   116,    98,   121,   122,   162,   197,
    -267,  -267,   302,   302,   302,   302,   302,   302,  -267,   750,
     750,   158,   -44,   242,   -39,   151,   214,  -267,   -36,   -36,
     317,   317,   317,    32,  -267,  -267,  -267,   219,  1182,   140,
    -267,   750,   198,  1595,  1710,   123,  -267,  -267,   156,  -267,
    -267,  1767,   297,   750,   750,   750,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,   750,   750,   750,   750,   750,  -267,  -267,
     140,  -267,   140,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,   750,  -267,  -267,   750,  -267,   140,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,   140,  -267,  -267,  -267,   140,
     140,   111,   888,  -267,  -267,  -267,  -267,  -267,   302,    -2,
    1618,   140,   140,   390,  -267,  -267,  -267,     1,  1194,  1277,
    1289,  1301,  1313,  1325,  1337,   649,   129,   -65,  1420,  1432,
     -14,   130,    70,    71,  -267,   140,   302,   302,   750,  -267,
     -68,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
     750,  -267,  -267,   140,  -267,  -267,  -267,   140,  -267,  -267,
     750,  -267,   750,  -267,   302,  1698,   395,     1,   219,  1444,
     155,   167,  1456,  1468,  -267,  1857,  -267,  -267,  1857,  -267,
    -267,  -267,  -267,  -267,  1857,   156,    -4,   379,   156,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,   390,  -267
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         7,   180,    14,    15,   157,    20,   158,     0,     0,     0,
      24,   152,   145,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     8,     9,    11,    12,     0,
      13,   159,    16,     0,    88,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    37,    21,    77,    87,
      31,    32,    33,     0,    25,     0,    10,   130,    35,     0,
     165,     0,   127,     0,    28,     0,     0,     0,     1,     2,
       5,   138,     0,     0,     0,     0,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,   132,     0,   174,     0,   173,
     168,   166,    17,   126,     0,     0,     0,     0,     0,     7,
       7,     0,     0,   160,    36,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    86,    72,    74,    76,    73,    75,    71,    39,     0,
       0,    64,    66,    68,    65,    67,    63,    79,    84,    85,
      82,    83,    78,     0,   128,   129,   131,   130,     0,     0,
      18,    19,    26,    29,    34,     0,    23,     6,   134,   139,
     181,     0,     0,     0,     0,     0,   103,   104,   105,   100,
     101,    99,   102,     0,     0,     0,     0,     0,    49,    50,
       0,   120,     0,    69,   124,   125,    89,    90,    91,    92,
      93,     0,    94,    96,     0,    97,     0,    45,    48,   110,
     111,   109,   116,    56,    57,     0,    53,    51,    52,     0,
       0,    61,    59,   154,   155,   153,   133,   175,   167,   171,
     169,     0,     0,   148,   140,   182,   142,   176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   156,     0,    27,    30,     0,   135,
       0,   177,   179,   117,   118,   119,   107,   108,    41,    42,
       0,    44,   121,     0,   122,    95,    98,     0,    46,    70,
       0,   112,     0,   114,   170,     0,   146,     0,   130,     0,
       0,     0,     0,     0,   149,     7,   136,   178,     7,    43,
     123,    47,   113,   115,     7,   147,     0,     0,   150,   143,
     144,   137,   163,   164,   162,   161,   148,   151
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -267,  -267,  -267,  -182,  -267,   245,  -196,   428,   199,  -267,
      14,  -267,  -267,  -267,   -15,  -267,  -266,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,     9,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,    39,     0,  -267
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    21,    22,    23,   199,    24,    25,    26,    93,    86,
     102,   260,   259,    88,   103,   276,   185,    98,    27,   353,
     406,   426,    28,   201,   354,   202,   431,    29,   416,   379,
     424,   436,    30,    95,   345,   374,    31,    32,   112,   292,
     435,   192,   100,   380,   381,    89,   291
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -142;
  const short int
  parser::yytable_[] =
  {
        33,   273,   104,   105,   106,   289,     1,    90,    91,    92,
     187,   346,     1,    33,   174,   175,   176,   177,   288,    87,
     175,   176,   177,   429,    94,   177,  -141,   168,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   286,    97,   110,
     168,   430,   305,   111,   162,   163,   164,   165,   166,   167,
     308,   107,   116,   162,   163,   164,   165,   166,   167,   343,
     274,   200,   168,   169,   170,   168,   275,   407,   344,   408,
     393,   168,   394,   306,   171,   172,   173,   174,   175,   176,
     177,   309,   178,   179,   180,   181,   182,   178,   179,   180,
     181,   182,   180,   181,   182,   356,   158,   159,   161,   189,
     168,   168,   171,   172,   173,   174,   175,   176,   177,   183,
     250,   329,   108,   168,   191,   193,   168,   224,   225,   226,
     227,   397,   168,   398,   310,   168,   311,   204,   205,   206,
     307,   207,   208,   209,   211,   212,   213,   214,   215,   216,
     217,    99,   418,   188,    35,   178,   179,   180,   181,   182,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     280,   281,   109,   110,   242,   113,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   114,   115,
     117,   118,   321,    33,   322,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   168,   168,    33,
      33,    33,   278,   168,    85,   400,   402,   401,   403,   283,
     284,   176,   177,   330,   172,   173,   174,   175,   176,   177,
     119,   168,   168,   120,   168,   168,    49,    50,    51,    52,
      53,   331,   332,   425,   334,   336,   427,   178,   179,   180,
     181,   182,   428,   168,   121,   122,    66,    67,   168,   168,
     168,   335,    72,    73,    74,    75,   168,   168,   337,   338,
     250,    77,    78,    79,   123,   184,   392,   399,   124,   125,
     126,   169,   170,   341,   342,   177,   197,   178,   179,   180,
     181,   182,   168,   160,   178,   179,   180,   181,   182,   168,
     127,    33,   420,   128,   168,   350,   129,   339,   172,   190,
     174,   175,   176,   177,   421,   130,   198,   358,   359,   360,
     171,   172,   173,   174,   175,   176,   177,   361,   362,   363,
     364,   365,   131,   132,   168,   168,   218,   219,   220,   221,
     222,   223,   340,   351,   203,   368,   133,   134,   369,   135,
     178,   179,   180,   181,   182,   238,   239,   240,   241,   136,
     243,   244,   245,   246,   247,   248,   249,   382,   169,   170,
     137,   252,   253,   254,   255,   256,   257,   258,   178,   179,
     180,   181,   182,   138,   139,   140,   141,   142,   177,   143,
     144,   178,   179,   180,   181,   182,   110,   145,   146,   147,
     293,   432,   405,   282,   433,   148,   285,   171,   172,   173,
     174,   175,   176,   177,   409,   149,   434,   382,   150,   151,
     152,   153,   154,   155,   412,    33,   413,   156,    33,   157,
     186,   194,   195,   196,    33,   277,   290,   312,   313,   168,
     314,     1,   315,   357,   378,     2,     3,     4,   415,     5,
       6,    96,   169,   170,   287,   437,   417,     0,     7,     8,
       9,   169,   170,     0,     0,    10,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,    12,   178,   179,
     180,   181,   182,    13,    14,     0,     0,   324,   348,   325,
     349,   171,   172,   173,   174,   175,   176,   177,    15,     0,
     171,   172,   173,   174,   175,   176,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   366,
       0,   367,     0,     0,     0,     0,     0,    16,    17,     0,
      18,     0,     0,    19,     0,   370,     0,    34,    35,     1,
       0,     0,     0,     0,   371,     0,     0,    20,   372,   373,
      36,    37,    38,    39,     0,     0,     0,     0,     0,     0,
     376,   377,   178,   179,   180,   181,   182,     0,     0,     0,
       0,   178,   179,   180,   181,   182,     0,     0,     0,     0,
     326,     0,   327,     0,   404,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   410,     0,     0,     0,   411,     0,     0,     0,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     0,    55,     0,    56,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      34,    35,     1,     0,    76,    77,    78,    79,    80,    81,
      82,    83,     0,    36,    37,    38,    39,     0,     0,     0,
      84,     0,   101,     0,     0,   169,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   173,   174,   175,   176,
     177,     0,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,     0,
      55,     0,    56,    57,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    34,    35,     1,     0,    76,    77,    78,
      79,    80,    81,    82,    83,     0,    36,    37,    38,    39,
     169,   170,     0,    84,   210,   178,   179,   180,   181,   182,
       0,     0,     0,     0,   390,     0,   391,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     0,    55,     0,    56,    57,     0,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,   169,   170,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,   169,   170,
     178,   179,   180,   181,   182,     0,    84,     0,     0,     0,
       0,   251,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   171,   172,   173,   174,   175,
     176,   177,   169,   170,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   169,   170,     0,     0,     0,     0,
       0,   171,   172,   173,   174,   175,   176,   177,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
       0,   171,   172,   173,   174,   175,   176,   177,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,     0,   178,   179,   180,   181,
     182,     0,     0,     0,     0,     0,     0,   296,   178,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,   297,
       0,     0,   178,   179,   180,   181,   182,   169,   170,     0,
       0,     0,     0,   298,   178,   179,   180,   181,   182,   169,
     170,     0,   178,   179,   180,   181,   182,     0,     0,     0,
       0,   169,   170,   299,   178,   179,   180,   181,   182,     0,
       0,     0,     0,   169,   170,   300,   171,   172,   173,   174,
     175,   176,   177,     0,     0,   169,   170,     0,   171,   172,
     173,   174,   175,   176,   177,     0,     0,   169,   170,     0,
     171,   172,   173,   174,   175,   176,   177,     0,     0,     0,
       0,     0,   171,   172,   173,   174,   175,   176,   177,     0,
       0,     0,     0,     0,   171,   172,   173,   174,   175,   176,
     177,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,     0,     0,     0,     0,   178,   179,   180,
     181,   182,     0,     0,     0,     0,     0,     0,   301,   178,
     179,   180,   181,   182,     0,     0,     0,     0,     0,     0,
     302,   178,   179,   180,   181,   182,     0,     0,     0,     0,
     169,   170,   316,   178,   179,   180,   181,   182,     0,     0,
       0,     0,   169,   170,   317,   178,   179,   180,   181,   182,
       0,     0,     0,     0,   169,   170,   318,   178,   179,   180,
     181,   182,     0,     0,     0,     0,   169,   170,   319,   171,
     172,   173,   174,   175,   176,   177,     0,     0,   169,   170,
       0,   171,   172,   173,   174,   175,   176,   177,     0,     0,
     169,   170,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,   171,   172,   173,   174,   175,
     176,   177,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,     0,     0,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
     178,   179,   180,   181,   182,     0,     0,     0,     0,     0,
       0,   320,   178,   179,   180,   181,   182,     0,     0,     0,
       0,     0,     0,   323,   178,   179,   180,   181,   182,     0,
       0,     0,     0,   169,   170,   328,   178,   179,   180,   181,
     182,     0,     0,     0,     0,   169,   170,   333,   178,   179,
     180,   181,   182,     0,     0,     0,     0,   169,   170,   347,
     178,   179,   180,   181,   182,     0,     0,     0,     0,   169,
     170,   383,   171,   172,   173,   174,   175,   176,   177,     0,
       0,   169,   170,     0,   171,   172,   173,   174,   175,   176,
     177,     0,     0,   169,   170,     0,   171,   172,   173,   174,
     175,   176,   177,     0,     0,     0,     0,     0,   171,   172,
     173,   174,   175,   176,   177,     0,     0,     0,     0,     0,
     171,   172,   173,   174,   175,   176,   177,     0,     0,     0,
       0,     0,   171,   172,   173,   174,   175,   176,   177,     0,
       0,     0,     0,   178,   179,   180,   181,   182,     0,     0,
       0,     0,     0,     0,   384,   178,   179,   180,   181,   182,
       0,     0,     0,     0,     0,     0,   385,   178,   179,   180,
     181,   182,     0,     0,     0,     0,   169,   170,   386,   178,
     179,   180,   181,   182,     0,     0,     0,     0,   169,   170,
     387,   178,   179,   180,   181,   182,     0,     0,     0,     0,
     169,   170,   388,   178,   179,   180,   181,   182,     0,     0,
       0,     0,   169,   170,   389,   171,   172,   173,   174,   175,
     176,   177,     0,     0,   169,   170,     0,   171,   172,   173,
     174,   175,   176,   177,     0,     0,   169,   170,     0,   171,
     172,   173,   174,   175,   176,   177,     0,     0,     0,     0,
       0,   171,   172,   173,   174,   175,   176,   177,     0,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,   171,   172,   173,   174,   175,
     176,   177,     0,     0,     0,     0,   178,   179,   180,   181,
     182,     0,     0,     0,     0,     0,     0,   395,   178,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,   396,
     178,   179,   180,   181,   182,     0,     0,   169,   170,     0,
       0,   419,   178,   179,   180,   181,   182,   169,   170,     0,
       0,     0,     0,   422,   178,   179,   180,   181,   182,   169,
     170,     0,     0,     0,     0,   423,   178,   179,   180,   181,
     182,   169,   170,     0,     0,   294,   171,   172,   173,   174,
     175,   176,   177,   169,   170,     0,   171,   172,   173,   174,
     175,   176,   177,     0,   169,   170,     0,     0,   171,   172,
     173,   174,   175,   176,   177,     0,     0,     0,     0,     0,
     171,   172,   173,   174,   175,   176,   177,     0,     0,     0,
       0,     0,   171,   172,   173,   174,   175,   176,   177,     0,
       0,     0,   279,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,   375,     0,     0,     0,   178,   179,   180,
     181,   182,     0,     0,     0,     0,   295,   178,   179,   180,
     181,   182,     0,     0,     0,     0,   303,     0,     0,   178,
     179,   180,   181,   182,   169,   170,     0,     0,   304,     0,
       0,   178,   179,   180,   181,   182,   169,   170,     0,     0,
     352,     0,     0,   178,   179,   180,   181,   182,     0,     0,
     414,     0,     0,     0,   178,   179,   180,   181,   182,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
       0,     0,     0,     0,     0,   171,   172,   173,   174,   175,
     176,   177,     1,     0,   355,     0,     2,     3,     4,     0,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,   178,   179,   180,   181,   182,    15,
       0,     0,     0,     0,     0,     0,   178,   179,   180,   181,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    18,     1,     0,    19,     0,     2,     3,     4,     0,
       5,     6,     0,     0,     0,     0,     0,     0,    20,     7,
       8,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    18,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,   183,    17,    18,    19,   201,     5,     7,     8,     9,
       3,   277,     5,    13,    58,    59,    60,    61,   200,     5,
      59,    60,    61,    27,    10,    61,     7,   127,    55,    56,
      57,    58,    59,    60,   127,    16,    17,   137,     5,     7,
     127,    45,   135,    29,    55,    56,    57,    58,    59,    60,
     137,   136,    38,    55,    56,    57,    58,    59,    60,    27,
      76,    42,   127,    16,    17,   127,    82,   135,    36,   137,
     135,   127,   137,   135,    55,    56,    57,    58,    59,    60,
      61,   137,   126,   127,   128,   129,   130,   126,   127,   128,
     129,   130,   128,   129,   130,   291,    82,    83,    84,    99,
     127,   127,    55,    56,    57,    58,    59,    60,    61,    95,
     137,   137,     0,   127,   100,   101,   127,   132,   133,   134,
     135,   135,   127,   137,   135,   127,   137,   113,   114,   115,
     135,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   138,   408,   136,     4,   126,   127,   128,   129,   130,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     134,   135,    27,     7,   150,    60,    55,    56,    57,    58,
      59,    60,    61,   126,   127,   128,   129,   130,   136,   136,
     136,   136,   135,   183,   137,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   127,   127,   199,
     200,   201,   188,   127,     5,   135,   135,   137,   137,   195,
     196,    60,    61,   137,    56,    57,    58,    59,    60,    61,
     136,   127,   127,   136,   127,   127,    86,    87,    88,    89,
      90,   137,   137,   415,   137,   137,   418,   126,   127,   128,
     129,   130,   424,   127,   136,   136,   106,   107,   127,   127,
     127,   135,   112,   113,   114,   115,   127,   127,   137,   137,
     137,   121,   122,   123,   136,    46,   137,   137,   136,   136,
     136,    16,    17,   259,   260,    61,   136,   126,   127,   128,
     129,   130,   127,    84,   126,   127,   128,   129,   130,   127,
     136,   291,   137,   136,   127,   281,   136,   135,    56,   100,
      58,    59,    60,    61,   137,   136,   107,   293,   294,   295,
      55,    56,    57,    58,    59,    60,    61,   303,   304,   305,
     306,   307,   136,   136,   127,   127,   127,   128,   129,   130,
     131,   132,   135,   135,     5,   321,   136,   136,   324,   136,
     126,   127,   128,   129,   130,   146,   147,   148,   149,   136,
     151,   152,   153,   154,   155,   156,   157,   357,    16,    17,
     136,   162,   163,   164,   165,   166,   167,   168,   126,   127,
     128,   129,   130,   136,   136,   136,   136,   136,    61,   136,
     136,   126,   127,   128,   129,   130,     7,   136,   136,   136,
     135,    12,   378,   194,    15,   136,   197,    55,    56,    57,
      58,    59,    60,    61,   390,   136,    27,   407,   136,   136,
     136,   136,   136,   136,   400,   415,   402,   136,   418,   136,
     135,   135,   135,   135,   424,     5,     7,   135,   137,   127,
     137,     5,   137,   136,    44,     9,    10,    11,    43,    13,
      14,    13,    16,    17,   199,   436,   407,    -1,    22,    23,
      24,    16,    17,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    41,   126,   127,
     128,   129,   130,    47,    48,    -1,    -1,   135,   279,   137,
     281,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
      -1,   312,    -1,    -1,    -1,    -1,    -1,    91,    92,    -1,
      94,    -1,    -1,    97,    -1,   326,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,   335,    -1,    -1,   111,   339,   340,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
     351,   352,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,    -1,   137,    -1,   375,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   393,    -1,    -1,    -1,   397,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    -1,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       3,     4,     5,    -1,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    16,    17,    18,    19,    -1,    -1,    -1,
     136,    -1,   138,    -1,    -1,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    -1,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     3,     4,     5,    -1,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    16,    17,    18,    19,
      16,    17,    -1,   136,   137,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,   135,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    93,    -1,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    16,    17,    -1,    -1,
     120,   121,   122,   123,   124,   125,   126,   127,    16,    17,
     126,   127,   128,   129,   130,    -1,   136,    -1,    -1,    -1,
      -1,   137,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    55,    56,    57,    58,    59,
      60,    61,    16,    17,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    16,    17,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,   126,   127,   128,   129,   130,    16,    17,    -1,
      -1,    -1,    -1,   137,   126,   127,   128,   129,   130,    16,
      17,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    16,    17,   137,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    16,    17,   137,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    16,    17,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    16,    17,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      16,    17,   137,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    16,    17,   137,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    16,    17,   137,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    16,    17,   137,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    16,    17,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      16,    17,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    16,    17,   137,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    16,    17,   137,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    16,    17,   137,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    16,
      17,   137,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    16,    17,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    16,    17,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    16,    17,   137,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    16,    17,
     137,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      16,    17,   137,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    16,    17,   137,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    16,    17,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    16,    17,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     126,   127,   128,   129,   130,    -1,    -1,    16,    17,    -1,
      -1,   137,   126,   127,   128,   129,   130,    16,    17,    -1,
      -1,    -1,    -1,   137,   126,   127,   128,   129,   130,    16,
      17,    -1,    -1,    -1,    -1,   137,   126,   127,   128,   129,
     130,    16,    17,    -1,    -1,   135,    55,    56,    57,    58,
      59,    60,    61,    16,    17,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    16,    17,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    65,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    65,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,   135,    -1,    -1,   126,
     127,   128,   129,   130,    16,    17,    -1,    -1,   135,    -1,
      -1,   126,   127,   128,   129,   130,    16,    17,    -1,    -1,
     135,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      42,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,     5,    -1,     7,    -1,     9,    10,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    62,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      -1,    94,     5,    -1,    97,    -1,     9,    10,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,   111,    22,
      23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,     5,     9,    10,    11,    13,    14,    22,    23,    24,
      29,    35,    41,    47,    48,    62,    91,    92,    94,    97,
     111,   140,   141,   142,   144,   145,   146,   157,   161,   166,
     171,   175,   176,   184,     3,     4,    16,    17,    18,    19,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    93,    95,    96,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   120,   121,   122,   123,
     124,   125,   126,   127,   136,   147,   148,   149,   152,   184,
     184,   184,   184,   147,   149,   172,   146,     5,   156,   138,
     181,   138,   149,   153,   153,   153,   153,   136,     0,    27,
       7,   149,   177,    60,   136,   136,   149,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   149,   149,
     147,   149,    55,    56,    57,    58,    59,    60,   127,    16,
      17,    55,    56,    57,    58,    59,    60,    61,   126,   127,
     128,   129,   130,   149,    46,   155,   135,     3,   136,   184,
     147,   149,   180,   149,   135,   135,   135,   136,   147,   143,
      42,   162,   164,     5,   149,   149,   149,   149,   149,   149,
     137,   149,   149,   149,   149,   149,   149,   149,   147,   147,
     147,   147,   147,   147,   153,   153,   153,   153,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   147,   147,
     147,   147,   149,   147,   147,   147,   147,   147,   147,   147,
     137,   137,   147,   147,   147,   147,   147,   147,   147,   151,
     150,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   142,    76,    82,   154,     5,   149,    65,
     134,   135,   147,   149,   149,   147,   137,   144,   142,   145,
       7,   185,   178,   135,   135,   135,   137,   137,   137,   137,
     137,   137,   137,   135,   135,   135,   135,   135,   137,   137,
     135,   137,   135,   137,   137,   137,   137,   137,   137,   137,
     137,   135,   137,   137,   135,   137,   135,   137,   137,   137,
     137,   137,   137,   137,   137,   135,   137,   137,   137,   135,
     135,   149,   149,    27,    36,   173,   155,   137,   147,   147,
     149,   135,   135,   158,   163,     7,   145,   136,   149,   149,
     149,   149,   149,   149,   149,   149,   147,   147,   149,   149,
     147,   147,   147,   147,   174,    65,   147,   147,    44,   168,
     182,   183,   184,   137,   137,   137,   137,   137,   137,   137,
     135,   137,   137,   135,   137,   137,   137,   135,   137,   137,
     135,   137,   135,   137,   147,   149,   159,   135,   137,   149,
     147,   147,   149,   149,    42,    43,   167,   183,   155,   137,
     137,   137,   137,   137,   169,   142,   160,   142,   142,    27,
      45,   165,    12,    15,    27,   179,   170,   168
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
  const unsigned char
  parser::yyr1_[] =
  {
         0,   139,   140,   141,   142,   143,   142,   144,   144,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   146,   147,   147,   147,
     147,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   150,   149,
     151,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   153,   153,   154,   154,
     155,   155,   156,   156,   158,   159,   160,   157,   162,   163,
     161,   164,   161,   165,   165,   166,   167,   167,   168,   169,
     170,   168,   172,   171,   173,   174,   173,   175,   175,   177,
     178,   176,   179,   179,   179,   180,   180,   180,   180,   180,
     180,   180,   181,   181,   181,   181,   182,   182,   182,   183,
     184,   185,   185
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     0,     4,     0,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     4,
       1,     2,     2,     4,     1,     2,     4,     6,     2,     4,
       6,     2,     2,     2,     4,     2,     3,     1,     1,     3,
       3,     6,     6,     8,     6,     4,     6,     8,     4,     4,
       4,     4,     4,     4,     1,     1,     4,     4,     0,     4,
       0,     4,     2,     3,     3,     3,     3,     3,     3,     4,
       6,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       2,     2,     3,     3,     3,     3,     3,     1,     1,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     3,     6,     6,     4,
       4,     4,     6,     8,     6,     8,     4,     6,     6,     6,
       4,     6,     6,     8,     4,     4,     2,     1,     1,     1,
       0,     2,     2,     4,     0,     0,     0,    10,     0,     0,
       5,     0,     5,     1,     1,     1,     0,     2,     0,     0,
       0,     7,     0,     5,     1,     0,     2,     1,     1,     0,
       0,    10,     1,     1,     1,     0,     1,     3,     1,     3,
       5,     3,     0,     2,     2,     4,     0,     1,     3,     1,
       1,     1,     2
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "$end", "error", "$undefined", "tNUMBER", "tSTRING", "tNUMSYM",
  "tSTRSYM", "tSEPARATOR", "tCALL", "tBREAK", "tCONTINUE", "tSUB",
  "tENDSUB", "tRETURN", "tFUNCTION", "tENDFUNCTION", "tAND", "tOR", "tNOT",
  "tEOR", "tCSUB", "tFROM", "tGOTO", "tGOSUB", "tLABEL", "tENABLE",
  "tDISABLE", "tEOPROG", "tNEWFILE", "tEXIT", "tEXPLICIT", "tFOR", "tTO",
  "tNEXT", "tSTEP", "tWHILE", "tWEND", "tREPEAT", "tUNTIL", "tDO", "tLOOP",
  "tIF", "tTHEN", "tELSE", "tELSEIF", "tENDIF", "tAS", "tLET", "tDIM",
  "tLOCAL", "tSTATIC", "tARDIM", "tARSIZE", "tINC", "tDEC", "tNEQ", "tLEQ",
  "tGEQ", "tLTN", "tGTN", "tEQU", "tPOW", "tPRINT", "tINPUT", "tLINE",
  "tUSING", "tSTRUCT", "tENDSTRUCT", "tSWITCH", "tSEND", "tCASE",
  "tDEFAULT", "tDATA", "tENDDATA", "tREAD", "tRESTORE", "tLONG", "tABS",
  "tSIG", "tRAN", "tSQR", "tSQRT", "tINT", "tFRAC", "tMIN", "tMAX",
  "tLEFT", "tRIGHT", "tMID", "tUPPER", "tLOWER", "tOPEN", "tCLOSE", "tEOF",
  "tSEEK", "tTELL", "tPEEK", "tPOKE", "tSIN", "tASIN", "tCOS", "tACOS",
  "tTAN", "tATAN", "tEXP", "tLOG", "tSTR", "tCHR", "tVAL", "tASC", "tLEN",
  "tSYSTEM", "tARG", "tENV", "tTIME", "tDATE", "tTOKEN", "tTOKENALT",
  "tSPLIT", "tSPLITALT", "tGLOB", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR",
  "tRINSTR", "'-'", "'+'", "'*'", "'/'", "tMOD", "UPLUS", "UMINUS", "'.'",
  "';'", "','", "'('", "')'", "'#'", "$accept", "program",
  "list_of_statement_lists", "statement_list", "$@1", "statement",
  "non_empty_statement", "number_assignment", "string_expression",
  "string_function", "number_expression", "$@2", "$@3", "number_function",
  "hashed_number", "exprtype", "dim_as_type", "dim_list", "if_clause",
  "$@4", "$@5", "$@6", "short_if", "$@7", "$@8", "$@9", "endif", "if_part",
  "else_part", "elseif_part", "$@10", "$@11", "while_loop", "$@12", "wend",
  "$@13", "begin_sub", "function_definition", "$@14", "@15", "endsub",
  "print_list", "print_intro", "param_list", "param_item", "numsym_s",
  "separator_list", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
       140,     0,    -1,   141,    27,    -1,   142,    -1,   144,    -1,
      -1,   142,     7,   143,   144,    -1,    -1,   145,    -1,   146,
      -1,    47,   146,    -1,   157,    -1,   161,    -1,   171,    -1,
       9,    -1,    10,    -1,   176,    -1,    62,   181,   180,    -1,
      62,   181,   180,   134,    -1,    62,   181,   180,   135,    -1,
      13,    -1,    13,   149,    -1,    13,   147,    -1,   111,   136,
     147,   137,    -1,    29,    -1,    29,   149,    -1,    91,   153,
     135,   147,    -1,    91,   153,   135,   147,   135,   147,    -1,
      92,   153,    -1,    94,   153,   135,   149,    -1,    94,   153,
     135,   149,   135,   147,    -1,    22,   184,    -1,    23,   184,
      -1,    24,   184,    -1,    97,   153,   135,   149,    -1,    48,
     156,    -1,   184,    60,   149,    -1,   148,    -1,     4,    -1,
     147,   127,   147,    -1,   136,   147,   137,    -1,    86,   136,
     147,   135,   149,   137,    -1,    87,   136,   147,   135,   149,
     137,    -1,    88,   136,   147,   135,   149,   135,   149,   137,
      -1,    88,   136,   147,   135,   149,   137,    -1,   106,   136,
     149,   137,    -1,   106,   136,   149,   135,   147,   137,    -1,
     106,   136,   149,   135,   147,   135,   147,   137,    -1,   107,
     136,   149,   137,    -1,    89,   136,   147,   137,    -1,    90,
     136,   147,   137,    -1,   122,   136,   147,   137,    -1,   123,
     136,   147,   137,    -1,   121,   136,   147,   137,    -1,   115,
      -1,   114,    -1,   112,   136,   149,   137,    -1,   113,   136,
     147,   137,    -1,    -1,   149,    17,   150,   149,    -1,    -1,
     149,    16,   151,   149,    -1,    18,   149,    -1,   149,    60,
     149,    -1,   149,    55,   149,    -1,   149,    58,   149,    -1,
     149,    56,   149,    -1,   149,    59,   149,    -1,   149,    57,
     149,    -1,    93,   136,   153,   137,    -1,   120,   136,   147,
     135,   147,   137,    -1,   147,    60,   147,    -1,   147,    55,
     147,    -1,   147,    58,   147,    -1,   147,    56,   147,    -1,
     147,    59,   147,    -1,   147,    57,   147,    -1,   152,    -1,
     149,   130,   149,    -1,   149,    61,   149,    -1,   127,   149,
      -1,   126,   149,    -1,   149,   128,   149,    -1,   149,   129,
     149,    -1,   149,   126,   149,    -1,   149,   127,   149,    -1,
     136,   149,   137,    -1,   184,    -1,     3,    -1,    98,   136,
     149,   137,    -1,    99,   136,   149,   137,    -1,   100,   136,
     149,   137,    -1,   101,   136,   149,   137,    -1,   102,   136,
     149,   137,    -1,   103,   136,   149,   137,    -1,   103,   136,
     149,   135,   149,   137,    -1,   104,   136,   149,   137,    -1,
     105,   136,   149,   137,    -1,   105,   136,   149,   135,   149,
     137,    -1,    82,   136,   149,   137,    -1,    80,   136,   149,
     137,    -1,    81,   136,   149,   137,    -1,    83,   136,   149,
     137,    -1,    77,   136,   149,   137,    -1,    78,   136,   149,
     137,    -1,    79,   136,   149,   137,    -1,    79,   136,   137,
      -1,    84,   136,   149,   135,   149,   137,    -1,    85,   136,
     149,   135,   149,   137,    -1,   110,   136,   147,   137,    -1,
     108,   136,   147,   137,    -1,   109,   136,   147,   137,    -1,
     124,   136,   147,   135,   147,   137,    -1,   124,   136,   147,
     135,   147,   135,   149,   137,    -1,   125,   136,   147,   135,
     147,   137,    -1,   125,   136,   147,   135,   147,   135,   149,
     137,    -1,   111,   136,   147,   137,    -1,    16,   136,   149,
     135,   149,   137,    -1,    17,   136,   149,   135,   149,   137,
      -1,    19,   136,   149,   135,   149,   137,    -1,    91,   136,
     147,   137,    -1,    91,   136,   147,   135,   147,   137,    -1,
      91,   136,   153,   135,   147,   137,    -1,    91,   136,   153,
     135,   147,   135,   147,   137,    -1,    95,   136,   153,   137,
      -1,    96,   136,   153,   137,    -1,   138,   149,    -1,   149,
      -1,    76,    -1,    82,    -1,    -1,    46,   154,    -1,     5,
     155,    -1,   156,   135,     5,   155,    -1,    -1,    -1,    -1,
     166,   149,    42,   142,   158,   168,   159,   167,   160,   165,
      -1,    -1,    -1,   166,   149,   162,   145,   163,    -1,    -1,
     166,   149,   164,   185,   145,    -1,    27,    -1,    45,    -1,
      41,    -1,    -1,    43,   142,    -1,    -1,    -1,    -1,    44,
     149,    42,   169,   142,   170,   168,    -1,    -1,    35,   172,
     149,   142,   173,    -1,    27,    -1,    -1,    36,   174,    -1,
      11,    -1,    14,    -1,    -1,    -1,   175,   177,     5,   178,
     136,   182,   137,   155,   142,   179,    -1,    27,    -1,    12,
      -1,    15,    -1,    -1,   149,    -1,   149,    65,   147,    -1,
     147,    -1,   180,   135,   149,    -1,   180,   135,   149,    65,
     147,    -1,   180,   135,   147,    -1,    -1,   138,   184,    -1,
     138,     3,    -1,   138,   136,   149,   137,    -1,    -1,   183,
      -1,   182,   135,   183,    -1,   184,    -1,     5,    -1,     7,
      -1,   185,     7,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    11,    16,    17,    19,
      21,    24,    26,    28,    30,    32,    34,    36,    40,    45,
      50,    52,    55,    58,    63,    65,    68,    73,    80,    83,
      88,    95,    98,   101,   104,   109,   112,   116,   118,   120,
     124,   128,   135,   142,   151,   158,   163,   170,   179,   184,
     189,   194,   199,   204,   209,   211,   213,   218,   223,   224,
     229,   230,   235,   238,   242,   246,   250,   254,   258,   262,
     267,   274,   278,   282,   286,   290,   294,   298,   300,   304,
     308,   311,   314,   318,   322,   326,   330,   334,   336,   338,
     343,   348,   353,   358,   363,   368,   375,   380,   385,   392,
     397,   402,   407,   412,   417,   422,   427,   431,   438,   445,
     450,   455,   460,   467,   476,   483,   492,   497,   504,   511,
     518,   523,   530,   537,   546,   551,   556,   559,   561,   563,
     565,   566,   569,   572,   577,   578,   579,   580,   591,   592,
     593,   599,   600,   606,   608,   610,   612,   613,   616,   617,
     618,   619,   627,   628,   634,   636,   637,   640,   642,   644,
     645,   646,   657,   659,   661,   663,   664,   666,   670,   672,
     676,   682,   686,   687,   690,   693,   698,   699,   701,   705,
     707,   709,   711
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   194,   194,   214,   216,   219,   219,   226,   227,   230,
     231,   232,   233,   234,   235,   239,   245,   246,   258,   265,
     272,   273,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   287,   288,   291,   292,   295,   304,   305,   306,
     307,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   329,   329,
     330,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   352,   357,   360,   363,   367,   371,   372,   376,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   420,   421,   424,   427,
     433,   434,   442,   449,   457,   458,   462,   456,   480,   481,
     480,   482,   482,   486,   487,   490,   493,   494,   497,   499,
     501,   498,   505,   505,   513,   514,   514,   517,   518,   522,
     523,   522,   538,   544,   545,   548,   551,   556,   558,   560,
     562,   564,   568,   573,   574,   575,   578,   579,   580,   583,
     585,   590,   591
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
  const int parser::yylast_ = 1968;
  const int parser::yynnts_ = 47;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 108;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 139;

  const unsigned int parser::yyuser_token_number_max_ = 383;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 22 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 2709 "/home/cai/projects/basic/compiler/parser.cpp"
