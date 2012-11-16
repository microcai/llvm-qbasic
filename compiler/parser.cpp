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
#line 107 "/home/cai/projects/basic/compiler/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */

/* Line 284 of lalr1.cc  */
#line 115 "/home/cai/projects/basic/compiler/parser.cpp"


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
#line 211 "/home/cai/projects/basic/compiler/parser.cpp"

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
#line 205 "parser.ypp"
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
#line 222 "parser.ypp"
    { (yyval.statement_list) = new StatementsAST((yysemantic_stack_[(1) - (1)].statement));
			debug("statement_list %p app %p  now\n", (yyval.statement_list) , (yysemantic_stack_[(1) - (1)].statement));
}
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 225 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 225 "parser.ypp"
    {
			(yyval.statement_list) = (yysemantic_stack_[(4) - (1)].statement_list);
			debug("statement_list %p app %p  now\n", (yyval.statement_list) , (yysemantic_stack_[(4) - (4)].statement));
			(yyval.statement_list)->append( StatementASTPtr((yysemantic_stack_[(4) - (4)].statement)) );
	}
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 232 "parser.ypp"
    { (yyval.statement) = new EmptyStmtAST(); debug("got empty statement %p\n" , (yyval.statement)); }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 233 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement);
	   debug( "got non_empty_statement %p\n", (yyval.statement) );
}
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 249 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { debug ("cannot \"break\" outside of loop"); }
   }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 253 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   debug ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 259 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].function_definition) ; debug ("got function %p as statement\n", (yyval.statement)) ;  }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 261 "parser.ypp"
    { }
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 262 "parser.ypp"
    { }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 263 "parser.ypp"
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

  case 27:
/* Line 661 of lalr1.cc  */
#line 275 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
	   if(current_function.empty())
			useDefautSubMain = true;
   }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 282 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
	   if(current_function.empty())
			useDefautSubMain = true;
   }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    { until_eol = false; }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    {}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 290 "parser.ypp"
    { until_eol = true; }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 290 "parser.ypp"
    {}
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 291 "parser.ypp"
    {
	   
             }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 294 "parser.ypp"
    {

	   
   }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 299 "parser.ypp"
    { }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 300 "parser.ypp"
    {
	   debug("got syntax of \"dim local var\" now\n");

	   (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list);	   
	}
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 305 "parser.ypp"
    { }
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 306 "parser.ypp"
    {}
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    {}
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 308 "parser.ypp"
    {}
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 309 "parser.ypp"
    {}
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 310 "parser.ypp"
    {}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 311 "parser.ypp"
    {}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 312 "parser.ypp"
    {}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 313 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 314 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 317 "parser.ypp"
    {

   }
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 320 "parser.ypp"
    {  }
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 321 "parser.ypp"
    {
		debug("got label!\n");
   }
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    {  }
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 325 "parser.ypp"
    {  }
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 326 "parser.ypp"
    {  }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 326 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    { }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    {  }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 330 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 346 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 347 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 71:
/* Line 661 of lalr1.cc  */
#line 348 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 355 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 356 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 358 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 78:
/* Line 661 of lalr1.cc  */
#line 361 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 79:
/* Line 661 of lalr1.cc  */
#line 362 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {
		// 变量赋值
		debug("变量赋值\n");
		(yyval.number_assignment) = new NumberAssigmentAST(VariableRefExprASTPtr((yysemantic_stack_[(3) - (1)].varable_ref)), NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
		if(current_function.empty())
			useDefautSubMain = true;
	}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 375 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 376 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 377 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 389 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 414 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 415 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 421 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 421 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 422 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 422 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 423 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 425 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 427 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 428 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 429 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 430 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 431 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 432 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 433 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 435 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 436 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 437 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 438 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 439 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 440 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 441 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 442 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 444 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 445 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 446 "parser.ypp"
    {
	   (yyval.number_expression) = (yysemantic_stack_[(2) - (2)].number_expression) ;
   }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 449 "parser.ypp"
    {
	   /*add_command(cNEGATE,NULL);*/
	   ConstNumberExprAST * zero = new ConstNumberExprAST(0);
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr(zero) ,OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression)));
   }
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 454 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_MUL,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 457 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_DIV,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 460 "parser.ypp"
    {
	   // 减法计算
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 464 "parser.ypp"
    {
	   // 加法计算.
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_ADD,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 468 "parser.ypp"
    { (yyval.number_expression) = (yysemantic_stack_[(3) - (2)].number_expression) ;}
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 469 "parser.ypp"
    {
	   debug("got numsym_s\n");	   
	   (yyval.number_expression) =new NumberExprAST( VariableExprASTPtr((yysemantic_stack_[(1) - (1)].varable_ref)) );
	}
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 473 "parser.ypp"
    {
	   (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));
   }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 478 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 481 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 484 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 487 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 488 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 489 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 491 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 492 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 495 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 496 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 497 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 498 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 499 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 500 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 502 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 503 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 504 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 505 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 506 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 507 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 508 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 509 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 510 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 511 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 512 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 513 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 514 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 515 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 516 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 517 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 518 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 519 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 520 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 521 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 522 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 523 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 524 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 525 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 525 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 532 "parser.ypp"
    {
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 535 "parser.ypp"
    {
		//TODO int should be 32bit not 64bit
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 205:
/* Line 661 of lalr1.cc  */
#line 542 "parser.ypp"
    {
			debug("as  %s\n",(yysemantic_stack_[(2) - (2)].exprtype)->name.c_str());
			// long varable
			// 构造类型
			(yyval.exprtype) = (yysemantic_stack_[(2) - (2)].exprtype);
		}
    break;

  case 206:
/* Line 661 of lalr1.cc  */
#line 550 "parser.ypp"
    {
		/*变量定义*/
		// 在 AST 中分配一个变量名称列表.
		std::string name;
		name = (yysemantic_stack_[(2) - (1)].symbol);
		(yyval.dim_list) = new VariableDimAST( name , ExprTypeASTPtr((yysemantic_stack_[(2) - (2)].exprtype)));		
	}
    break;

  case 207:
/* Line 661 of lalr1.cc  */
#line 557 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 558 "parser.ypp"
    {
	  // 	std::string name;
	//	name = $3;
	//	$$ = new VariableDimAST( name , ExprTypeASTPtr($2));
   }
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 563 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 566 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 567 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 570 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 573 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 574 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 577 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 580 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 581 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 220:
/* Line 661 of lalr1.cc  */
#line 588 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 589 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 593 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
	}
    break;

  case 223:
/* Line 661 of lalr1.cc  */
#line 594 "parser.ypp"
    {
		(yyval.cppstring) = new std::string((yysemantic_stack_[(3) - (3)].symbol));
		debug("====begin function %s====\n",(yysemantic_stack_[(3) - (3)].symbol));
		current_function = (yysemantic_stack_[(3) - (3)].symbol);
	}
    break;

  case 224:
/* Line 661 of lalr1.cc  */
#line 600 "parser.ypp"
    {
		(yyval.function_definition) = new FunctionDimAST(current_function, ExprTypeASTPtr((yysemantic_stack_[(10) - (8)].exprtype)) );
		(yyval.function_definition)->body = StatementsASTPtr((yysemantic_stack_[(10) - (9)].statement_list));
		debug("====end function %s==== %p , body = %p\n",((yysemantic_stack_[(10) - (4)].cppstring))->c_str(),(yyval.function_definition) , (yysemantic_stack_[(10) - (9)].statement_list));
		delete (yysemantic_stack_[(10) - (4)].cppstring);
		current_function.clear();
	}
    break;

  case 225:
/* Line 661 of lalr1.cc  */
#line 609 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 615 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 616 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 644 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 645 "parser.ypp"
    {
	   
}
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 648 "parser.ypp"
    {
	   
}
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 651 "parser.ypp"
    {
	   
}
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 656 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 657 "parser.ypp"
    {
				 
			}
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 661 "parser.ypp"
    {
	 }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 663 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 665 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 669 "parser.ypp"
    {
		if (unclosed_fors) {
			debug ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 674 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 677 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 678 "parser.ypp"
    {  }
    break;

  case 244:
/* Line 661 of lalr1.cc  */
#line 681 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 685 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 247:
/* Line 661 of lalr1.cc  */
#line 685 "parser.ypp"
    {
	}
    break;

  case 248:
/* Line 661 of lalr1.cc  */
#line 687 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 249:
/* Line 661 of lalr1.cc  */
#line 687 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 250:
/* Line 661 of lalr1.cc  */
#line 692 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 693 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 701 "parser.ypp"
    {
	   
}
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 704 "parser.ypp"
    {
		   
	}
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 710 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 710 "parser.ypp"
    {

	   
}
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 716 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 716 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 721 "parser.ypp"
    {if (unclosed_dos) { debug ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 725 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 725 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 726 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 732 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 733 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 733 "parser.ypp"
    { }
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 736 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 736 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 741 "parser.ypp"
    {if (unclosed_repeats) { debug ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 747 "parser.ypp"
    { debug("then part %p\n" , (yysemantic_stack_[(4) - (4)].statement_list));}
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 748 "parser.ypp"
    {
				//TODO 
				debug("syntax not supported yet\n");
			}
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 752 "parser.ypp"
    {
				debug("else part %p\n" , (yysemantic_stack_[(8) - (8)].statement_list));
			}
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 755 "parser.ypp"
    {
				
				(yyval.if_clause) = new IFStmtAST( NumberExprASTPtr( (yysemantic_stack_[(10) - (2)].number_expression)));
				(yyval.if_clause)->_then = StatementsASTPtr((yysemantic_stack_[(10) - (4)].statement_list));
				(yyval.if_clause)->_else = StatementsASTPtr((yysemantic_stack_[(10) - (8)].statement_list));
			}
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 763 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 764 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 764 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 765 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 766 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 769 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 770 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 773 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 776 "parser.ypp"
    { (yyval.statement_list) = 0; }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 777 "parser.ypp"
    {	(yyval.statement_list) = (yysemantic_stack_[(2) - (2)].statement_list);}
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 782 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 788 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 789 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 790 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 791 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 794 "parser.ypp"
    { debug("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 795 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 801 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 803 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 805 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 807 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 809 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 812 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 813 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 814 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 815 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 819 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 822 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 827 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 828 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 829 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 832 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 835 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 836 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 839 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 840 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 844 "parser.ypp"
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

  case 328:
/* Line 661 of lalr1.cc  */
#line 854 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 860 "parser.ypp"
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

  case 330:
/* Line 661 of lalr1.cc  */
#line 870 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 883 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 891 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 899 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 907 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 917 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 925 "parser.ypp"
    {
		debug("变量引用\n");
		(yyval.varable_ref) = new VariableRefExprAST( (yysemantic_stack_[(1) - (1)].symbol) );
	}
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 929 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 932 "parser.ypp"
    {
		//该决定是否为函数还是数组了
	}
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 935 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 936 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 937 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 940 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 943 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 944 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 945 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 948 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 949 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 952 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 953 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 954 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 955 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 955 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 958 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 959 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 960 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 961 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2530 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const short int parser::yypact_ninf_ = -569;
  const short int
  parser::yypact_[] =
  {
      3205,   -91,   -77,  -569,  -569,  -569,  2373,  -569,   532,   -72,
     -63,    91,    91,    91,  -569,  -569,  2373,  -569,  -569,  -569,
    -569,  -569,    46,   134,    91,    91,   -37,  -569,   124,  -569,
    -569,    91,   218,    91,   -21,    60,    72,  2117,  2117,  2117,
    2117,    81,   204,   225,   260,  -569,  -569,  -569,  -569,  -569,
     207,  -569,   233,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  2373,  -569,   -42,   -34,   149,   273,   278,  -569,
     216,   221,  -569,  -569,   255,   282,  2373,   294,   297,   309,
     327,   330,   334,   347,   358,   360,   366,   368,   374,   387,
     388,   390,   393,   396,   400,   401,   402,   403,   404,   405,
     406,   416,   419,   424,   426,   436,   437,   440,   441,   442,
     443,   444,   445,   446,   447,   448,  -569,  -569,   449,   454,
     462,   463,   465,   467,   468,   469,   475,   476,  2373,  2373,
    2373,    -5,  -569,  2980,  -569,  -569,  -569,   344,   394,  -569,
    -569,   532,   284,   344,   394,   149,  -569,  -569,  -569,   428,
     428,   428,   354,   354,    -5,  2980,    91,  -569,  -569,  -569,
     488,   489,  -569,  -569,   -33,   394,  -569,   -15,   489,   271,
     473,   528,   452,   428,   492,   428,    11,  2373,   464,  -569,
     573,  -569,   428,   494,  -569,    -9,    -6,   568,   602,   495,
     428,   218,   218,   218,  2373,  2980,   500,  -569,   501,   502,
     532,  -569,  -569,  -569,  2373,   532,   629,    52,  2373,   369,
     451,   453,   532,  -569,  -569,  2373,  2373,   391,  2373,  -569,
    -569,   456,   456,  2373,  2373,  2245,  2373,  2373,  2373,  2373,
    2373,  2373,   532,   532,   532,   532,   532,  2117,  2117,  2117,
    2117,  2373,  2373,  2373,  2373,  2373,  2373,  2373,  2373,  2373,
    2373,   532,   532,   532,   532,  2373,   532,   532,   218,   532,
     218,   532,   532,   532,   532,   532,   532,   579,   579,    12,
    1042,   532,   532,   532,   532,   532,   532,   532,  -569,  -569,
    2373,  2373,  2373,  2373,  2373,  2373,  2373,  2373,  2373,  2373,
    2373,  2373,   -41,  2373,  2373,   639,  -569,  -569,  -569,   -14,
    2373,  3205,  3205,  -569,  -569,   459,    75,  -569,   466,   470,
    -569,    91,    91,  -569,  2373,   428,    -5,  2920,   341,    32,
    -569,   532,   464,   509,   510,  2373,   644,   218,    91,    91,
      91,    91,    91,   515,   523,  -569,  -569,   522,   525,  2980,
     532,  2373,  2373,   -11,  3205,  2980,   284,  -569,  3205,  3205,
     644,  2980,   531,   533,   534,   545,   546,   547,   284,   185,
    2790,  2801,  2373,  2373,   557,   559,   521,   535,   564,   149,
    -569,   563,   565,  1178,  1212,  -569,  1230,  1367,  1382,  1403,
    1486,  2813,  2827,   -88,    -7,    65,    38,    39,    23,   566,
     569,   570,   572,  1513,  1638,  1676,  1690,  1725,   536,  1739,
     752,   853,  1774,    67,    78,   101,   138,  1823,   139,   112,
     -47,   168,    35,   175,   160,   163,   203,   217,   238,  -569,
    -569,   284,   284,   284,   284,   284,   284,  -569,  2373,  2373,
     631,   439,   487,   151,    16,   -24,  -569,    26,    26,   579,
     579,   579,    -5,  2980,   182,  -569,   248,  -569,  -569,  2980,
      57,    58,   575,   576,  -569,  -569,  -569,   -15,   528,   576,
     428,   428,  1907,   532,  -569,  2373,  -569,  2373,   428,   284,
     218,  -569,   700,   644,   711,   644,    -5,  2980,   644,  -569,
       3,  -569,   428,   428,   428,   428,   428,  2373,  2373,  2373,
     251,  2839,  2980,  -569,  -569,   578,   260,  -569,  3109,   580,
     581,  2373,  2373,   587,   589,  2373,  2373,  2373,   252,   257,
     216,   221,  -569,  -569,   478,  2373,  2373,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  2373,  2373,  2373,  2373,  2373,  -569,
    -569,   532,  -569,   532,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  2373,  -569,  -569,  2373,  -569,   532,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,   456,   532,  -569,   456,
     532,  -569,   532,  -569,  -569,  -569,   532,   532,   391,   619,
    2373,  -569,  -569,  2373,  3205,  -569,  2373,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,   284,    -5,  2931,   218,
    1925,   218,  -569,   523,   394,  -569,  -569,    31,    31,   712,
    -569,  -569,  -569,   715,    41,  -569,    -4,  -569,  1956,  2011,
     993,   532,   532,   484,   683,  -569,  -569,  -569,  -569,  2373,
     265,   266,  -569,  -569,  2050,  2384,  2488,  -569,  -569,   592,
     595,  2502,  2514,  2526,  2538,  2551,  2634,  1082,   205,    56,
    2646,  2658,    99,   270,   222,   275,   223,   230,   100,   159,
    -569,  2950,   180,  2980,  -569,   532,  -569,  -569,  -569,  -569,
     422,   644,   218,   425,   438,  -569,  -569,  -569,    43,   712,
     672,   673,  2373,   674,   284,   284,   559,   306,  -569,   607,
     149,  -569,  -569,  2373,  -569,   307,  -569,  -569,  -569,  -569,
    -569,   580,   581,  -569,  -569,  -569,  -569,  -569,  -569,  2373,
    -569,  -569,   532,  -569,  -569,  -569,   532,  -569,   532,  -569,
    -569,   532,  -569,  -569,  -569,  2373,  -569,  2373,  -569,  2373,
    -569,  -569,  -569,  -569,   284,   218,  -569,   644,   712,   523,
     394,  -569,  -569,  -569,  -569,   737,   675,  -569,   532,   532,
    2670,   532,   484,   528,   511,  2957,   699,  -569,  2683,   237,
     239,   242,   243,  2695,  2778,  2970,  -569,  -569,   712,  2373,
    -569,  -569,   284,   284,   690,   284,  -569,  3205,   595,  -569,
    3205,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  2373,
    -569,  -569,  -569,  -569,   532,   279,  3205,   260,    90,  2980,
    3205,  3205,   284,  -569,  -569,  -569,  -569,   260,  -569,  -569,
    -569,   260,   260,   683,   274,  -569,  -569,  -569,    91,  -569,
     428
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  parser::yydefact_[] =
  {
         7,   339,   349,    20,    21,   220,    33,   221,     0,     0,
       0,     0,     0,     0,    45,    47,    38,   235,   267,   274,
     261,   291,     0,     0,     0,     0,   318,    29,     0,   338,
     246,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     8,     9,    10,    24,
       0,    25,     0,   222,    22,    16,    19,    15,    18,    17,
      13,    14,     0,    23,     0,   210,   211,     0,   213,   214,
     341,   351,   154,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    91,    34,   143,   136,    92,   153,   210,    90,
     213,     0,    55,     0,     0,     0,    56,    58,   339,    51,
      52,    53,     0,     0,     0,    39,     0,   268,   275,   262,
     339,   349,    11,    12,     0,   212,   215,   204,     0,    36,
       0,   204,    50,   325,    49,   323,     0,   302,   309,    31,
       0,   247,    60,    62,    72,     0,     0,     0,     0,    63,
      78,     0,     0,     0,     0,   201,     0,    42,     0,     0,
       0,     1,     2,     5,     0,     0,     0,   284,     0,     0,
       0,     0,     0,   345,   356,     0,     0,   123,     0,   198,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   322,    46,    48,     0,
       0,     7,     7,   341,   351,     0,     0,   206,     0,     0,
     207,     0,     0,   320,     0,   319,   305,   303,    26,     0,
      30,     0,   309,   327,   329,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,     0,     0,   200,
       0,     0,     0,     0,     7,    81,    87,   223,     7,     0,
       0,    80,   340,   350,   343,   353,   347,   358,    82,     0,
       0,     0,     0,     0,   339,     0,     0,     0,     0,   155,
     156,     0,     0,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
     152,   138,   140,   142,   139,   141,   137,    94,     0,     0,
     125,   127,   129,   126,   128,   124,   145,   150,   151,   148,
     149,   144,   218,   219,     0,   216,     0,   340,   236,   269,
       0,     0,   340,   350,   202,   203,   205,   204,   204,     0,
     326,   324,     0,     0,    27,    28,   313,     0,   311,   317,
       0,    32,     0,     0,     0,     0,   253,   252,     0,   250,
       0,    73,    74,    76,    75,    77,    79,     0,     0,     0,
      40,    43,    54,    37,     6,     0,   280,   285,     0,   344,
     354,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,   133,     0,     0,     0,   171,   172,   173,
     168,   169,   167,   170,     0,     0,     0,     0,     0,   104,
     105,     0,   192,     0,   130,   196,   197,   157,   158,   159,
     160,   161,     0,   162,   164,     0,   165,     0,   100,   103,
     178,   179,   177,   184,   115,   116,     0,     0,   110,     0,
       0,   112,     0,   108,   106,   107,     0,     0,   122,   120,
       0,    57,    59,     0,     7,   277,     0,   276,   264,   265,
     263,   344,   354,   208,   209,   321,   304,   308,   306,     0,
       0,     0,   310,   298,   300,   299,   301,   338,   338,   254,
      69,    71,   251,     0,     0,    64,     0,    67,     0,     0,
       0,     0,     0,   228,   294,   286,   288,   348,   359,     0,
       0,     0,   346,   357,     0,     0,     0,   199,   118,   340,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     217,     0,     0,   278,   266,     0,   314,   315,   312,   333,
     338,     0,     0,   338,   257,    70,    61,    65,     0,    66,
       0,     0,     0,     0,    41,    44,   349,     0,   229,   231,
     233,   232,   234,     0,   281,     0,   342,   352,   185,   186,
     187,     0,     0,   134,   135,   175,   176,    96,    97,     0,
      99,   193,     0,   194,   163,   166,     0,   101,     0,   189,
     109,     0,   191,   111,   131,     0,   180,     0,   182,     0,
     271,   272,   270,   279,   307,     0,   328,     0,   331,   334,
     336,   335,   337,   330,   255,     0,     0,    68,     0,     0,
       0,     0,     0,   204,     0,     0,   292,   355,     0,     0,
       0,     0,     0,     0,     0,   244,   273,   316,   332,     0,
     258,   248,    85,    86,     0,    84,   230,     7,   350,   295,
       7,   282,    98,   195,   102,   188,   190,   181,   183,     0,
     237,   256,   259,   249,     0,     0,     7,   293,     0,   245,
       7,     7,    83,   226,   227,   225,   224,   296,   289,   290,
     283,   238,   260,   294,     0,   297,   240,   241,   242,   239,
     243
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -569,  -569,  -569,  -282,  -569,   414,  -347,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,   155,  -569,    97,  -569,   455,
    -569,   744,   749,  -132,   767,  -569,  -569,  1433,  -569,  -569,
     550,  -205,  -569,  -569,   -12,  -569,  -170,  -569,    36,  -569,
      63,  -569,  -285,   206,  -569,  -569,  -569,  -569,  -569,  -569,
      37,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  -569,  -311,    15,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,  -569,
    -569,  -569,  -569,  -569,  -569,  -569,  -569,   -23,  -569,  -569,
    -548,  -569,   461,  -569,  -569,  -569,  -569,  -569,  -569,   628,
    -569,  -569,  -454,  -569,  -569,   187,  -568,   758,     0,   166,
     927,   133,   496,  -569,  -217
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    42,    43,    44,   344,    45,    46,   178,   322,   152,
     153,   293,   294,   326,   604,   605,   606,   607,   183,   184,
     189,    47,    48,   333,   154,   132,   363,   195,   429,   428,
     366,   367,   134,   362,   196,   456,   307,   169,   135,    50,
     136,    52,   444,   445,    53,    54,   206,   495,   796,   677,
     678,    55,   156,   573,   790,   804,   808,   809,   780,    56,
     181,   325,   783,   480,   478,   664,   759,   736,   782,   791,
      57,   159,   302,   580,   654,    58,   157,   300,   574,   722,
     756,    59,   158,   301,   577,   723,    60,   614,   746,   788,
      61,   349,   615,   350,   800,    62,   771,   684,   786,   803,
     592,   318,   320,   321,   591,   589,   725,   470,   177,   297,
     174,   172,    63,   473,   475,   660,   661,   662,   137,   138,
      66,   139,   140,   619,    69
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -340;
  const short int
  parser::yytable_[] =
  {
        64,   310,   497,   479,   370,   370,   600,   601,   143,   446,
     602,   149,   150,   151,   313,   328,   148,   372,   329,   450,
     451,   208,   164,   170,   173,   175,   197,   198,   199,  -212,
     208,   182,   185,   190,   306,   466,    49,   148,   602,   498,
     286,   656,   277,   658,   600,   601,   600,   601,    70,   448,
     526,   160,   161,   271,   272,   273,   274,   275,   276,  -287,
     337,   338,    71,    51,   203,   203,   496,   146,   278,   279,
     271,   272,   273,   274,   275,   276,   147,   508,   509,   285,
     286,   271,   272,   273,   274,   275,   276,   575,   578,   277,
     286,   557,   727,   558,   209,   727,   148,   348,   576,   419,
      29,   579,   210,   305,   176,   287,   288,   289,   290,   291,
     280,   281,   282,   283,   284,   285,   286,   666,   191,   277,
     798,  -339,   295,   277,   303,   277,   410,   305,   412,   493,
     210,   527,   603,    67,   668,    34,    35,    36,   799,   167,
     168,   143,   277,   659,   659,   287,   288,   289,   290,   291,
     314,   616,   419,   277,   454,    67,   299,   289,   290,   291,
     455,   531,   597,   532,   598,   187,    65,   599,   277,   277,
     603,   467,   603,   560,   144,   561,   315,   757,   529,   530,
     323,   287,   288,   289,   290,   291,   277,   203,   165,   144,
     179,   334,   334,   334,   702,   277,   703,   277,   186,   192,
     143,   278,   279,   528,   201,   143,   659,   550,   277,   659,
     720,   193,   143,   284,   285,   286,   620,   621,   551,   721,
     200,   368,   368,   160,   161,   389,   390,   391,   392,   277,
     277,   277,   143,   143,   143,   143,   143,   706,   715,   707,
     716,   552,   277,   280,   281,   282,   283,   284,   285,   286,
     556,   143,   143,   143,   143,   202,   143,   143,   334,   143,
     334,   143,   143,   143,   143,   143,   143,   203,   277,   277,
     204,   143,   143,   143,   143,   143,   143,   143,   553,   555,
     287,   288,   289,   290,   291,   211,   203,   583,   584,   277,
     277,   793,   652,   277,   794,   669,   205,   717,   277,   718,
     563,    64,    64,   564,   806,   277,   559,   144,   170,   795,
     807,   460,   461,   562,   287,   288,   289,   290,   291,   468,
     570,   143,   571,   505,   335,   335,   335,   185,   482,   483,
     484,   485,   486,   277,   685,   277,   212,    49,    49,   370,
     143,  -215,   370,   565,    64,   701,   324,   277,    64,    64,
     728,   643,   277,   277,   645,   566,   213,   144,   144,   144,
     277,   214,   710,   713,    51,    51,   144,   277,   277,   277,
     714,   144,   277,   277,   352,   353,   567,   773,   144,   774,
      49,   277,   775,   776,    49,    49,   570,   296,   572,   611,
     570,   335,   627,   335,   215,   570,   682,   628,   144,   144,
     144,   144,   144,   570,   570,   686,   687,    51,   708,   308,
     709,    51,    51,   711,   277,   712,   758,   144,   144,   144,
     144,   216,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   218,    67,    67,   219,   144,   144,   144,
     144,   144,   144,   144,   742,   570,   743,   747,   220,   280,
     281,   282,   283,   284,   285,   286,   354,   355,   356,   357,
     187,   364,   365,   143,   452,   453,   221,    65,    65,   222,
     593,   457,   168,   223,   144,   452,   459,    67,   464,   465,
     209,    67,    67,   629,   630,   785,   224,   144,   787,   364,
     676,    29,   726,   186,    29,   733,    68,   225,    64,   226,
     283,   284,   285,   286,   797,   227,   144,   228,   801,   802,
      65,   734,   735,   229,    65,    65,   629,   768,   166,   171,
     287,   288,   289,   290,   291,   682,   230,   231,   188,   232,
     210,   143,   233,   143,    49,   234,    73,     1,     2,   235,
     236,   237,   238,   239,   240,   241,   281,   143,   283,   284,
     285,   286,   278,   279,    79,   242,   368,   143,   243,   368,
     143,    51,   143,   244,   295,   245,   143,   143,   287,   288,
     289,   290,   291,   767,    64,   246,   247,   306,   160,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   593,
     311,   593,   330,   258,   280,   281,   282,   283,   284,   285,
     286,   259,   260,   595,   261,   319,   262,   263,   264,   309,
      49,   143,   143,   679,   265,   266,   287,   288,   289,   290,
     291,    91,    92,    93,    94,    95,   331,   303,   304,   144,
     312,    67,   327,   332,   347,   278,   594,    51,   340,   341,
     342,   108,   109,   286,   447,   472,   474,   114,   115,   116,
     117,   479,   119,   487,   121,   143,   123,   124,   125,   305,
     488,   512,   729,   489,    65,   287,   288,   289,   290,   291,
     499,   141,   500,   501,   542,   513,   543,   280,   281,   282,
     283,   284,   285,   286,   502,   503,   504,   336,   336,   336,
     281,   282,   283,   284,   285,   286,   510,   144,   511,   144,
     514,   515,   143,   516,   533,   452,   143,    67,   143,   534,
     535,   143,   536,   144,   581,   582,   354,   613,   665,   602,
     617,   618,   595,   144,   595,   593,   144,   622,   144,   623,
     683,   691,   144,   144,   692,   738,   739,   741,   143,   143,
      65,   143,   679,   744,   760,   770,   681,   761,   287,   288,
     289,   290,   291,   784,   336,   594,   336,   594,   494,   667,
     287,   288,   289,   290,   291,   737,   162,    64,   278,   279,
      64,   163,   371,   131,   781,   142,   650,   144,   144,   766,
     805,   298,   481,   471,   143,   663,    64,   180,     0,     0,
      64,    64,     0,     0,     0,   731,     0,    68,    68,     0,
       0,     0,     0,    49,   458,     0,    49,     0,   810,     0,
     280,   281,   282,   283,   284,   285,   286,     0,     0,     0,
       0,   144,    49,   188,     0,     0,    49,    49,   730,     0,
      51,     0,     0,    51,     0,     0,     0,     0,     0,     0,
      68,     0,     0,     0,    68,    68,     0,     0,     0,    51,
       0,     0,     0,    51,    51,     0,     0,     0,   595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   144,   278,
     279,     0,   144,     0,   144,   681,     0,   144,     0,     0,
       0,   287,   288,   289,   290,   291,     0,     0,     0,     0,
     545,   594,   546,     0,     0,     0,     0,   269,     0,     0,
      67,     0,     0,    67,   144,   144,     0,   144,   292,     0,
       0,   280,   281,   282,   283,   284,   285,   286,     0,    67,
       0,     0,     0,    67,    67,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,   145,    65,     0,     0,     0,
       0,     0,     0,     0,   316,     0,     0,     0,     0,     0,
     144,     0,    65,     0,     0,     0,    65,    65,     0,     0,
       0,     0,     0,     0,     0,     0,   596,   343,     0,     0,
       0,     0,   346,     0,     0,     0,     0,     0,     0,   358,
       0,     0,   287,   288,   289,   290,   291,     0,     0,     0,
       0,   547,     0,   548,    68,     0,     0,     0,     0,   383,
     384,   385,   386,   387,   388,     0,     0,     0,     0,   278,
     279,     0,     0,     0,     0,     0,     0,     0,   403,   404,
     405,   406,     0,   408,   409,     0,   411,     0,   413,   414,
     415,   416,   417,   418,     0,     0,     0,     0,   421,   422,
     423,   424,   425,   426,   427,     0,     0,     0,     0,     0,
       0,   280,   281,   282,   283,   284,   285,   286,   278,   279,
     442,   442,     0,     0,     0,     0,     0,     0,   145,     0,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   596,     0,   596,   469,     0,
       0,     0,   476,     0,     0,     0,     0,     0,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   490,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   145,     0,   442,
     442,   672,   145,   673,     0,     0,     0,     0,     0,   145,
     280,   281,   282,   283,   284,   285,   286,     0,   369,   369,
       0,     0,     0,     0,     0,     0,     0,     0,   732,   145,
     145,   145,   145,   145,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,     0,     0,   145,   145,
     145,   145,   420,   145,   145,     0,   145,     0,   145,   145,
     145,   145,   145,   145,   278,   279,     0,     0,   145,   145,
     145,   145,   145,   145,   145,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,     0,     0,     0,     0,
     699,   596,   700,     0,     0,     0,     0,     0,   278,   279,
     586,     0,   587,     0,     0,     0,   280,   281,   282,   283,
     284,   285,   286,     0,     0,     0,   278,   279,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    68,     0,     0,    68,   145,   442,   442,
     280,   281,   282,   283,   284,   285,   286,     0,     0,     0,
       0,     0,    68,     0,     0,     0,    68,    68,   280,   281,
     282,   283,   284,   285,   286,     0,     0,     0,   638,     0,
     639,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,     0,     0,   642,     0,     0,     0,   517,     0,
       0,     0,     0,     0,   644,     0,     0,   646,     0,   647,
       0,     0,     0,   648,   649,     0,     0,   442,     0,     0,
       0,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,   518,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
     519,     0,     0,     0,     0,     0,     0,     0,   674,   675,
       0,     0,     0,   278,   279,     0,   442,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,   278,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     279,     0,   724,     0,     0,   280,   281,   282,   283,   284,
     285,   286,     0,     0,     0,     0,     0,     0,     0,   133,
     280,   281,   282,   283,   284,   285,   286,     0,     0,   155,
       0,     0,     0,     0,     0,     0,     0,     0,   145,     0,
     145,   280,   281,   282,   283,   284,   285,   286,     0,   749,
       0,     0,     0,   750,   145,   751,     0,     0,   752,     0,
       0,     0,     0,   145,   145,     0,   145,   145,     0,   145,
       0,     0,     0,   145,   145,   207,   287,   288,   289,   290,
     291,     0,   278,   279,     0,   762,   763,   520,   765,   217,
       0,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,   521,     0,     0,     0,   476,     0,     0,   278,
     279,     0,   287,   288,   289,   290,   291,     0,   145,   145,
     680,     0,     0,   522,   280,   281,   282,   283,   284,   285,
     286,   792,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   267,   268,   270,     0,     0,     0,     0,     0,     0,
       0,   280,   281,   282,   283,   284,   285,   286,     0,     0,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     317,     0,     0,     0,     0,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,     0,   523,   339,     0,   145,
       0,     0,     0,   145,     0,   145,     0,   345,   145,     0,
       0,   351,   287,   288,   289,   290,   291,     0,   359,   360,
       0,   361,     0,   537,   278,   279,   373,   374,   376,   377,
     378,   379,   380,   381,   382,   145,   145,     0,   145,   680,
       0,     0,     0,     0,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,     0,     0,     0,     0,   407,     0,
       0,     0,   278,   279,     0,     0,   280,   281,   282,   283,
     284,   285,   286,     0,     0,     0,   278,   279,     0,     0,
       0,   145,     0,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,     0,   443,   443,     0,     0,
       0,     0,     0,   449,   280,   281,   282,   283,   284,   285,
     286,   278,   279,     0,     0,     0,     0,   462,   280,   281,
     282,   283,   284,   285,   286,   278,   279,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,     0,     0,   491,   492,     0,     0,   538,     0,
       0,     0,     0,   280,   281,   282,   283,   284,   285,   286,
     278,   279,     0,     0,     0,   443,   443,   280,   281,   282,
     283,   284,   285,   286,     0,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,     0,   539,     0,     0,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
     540,     0,   280,   281,   282,   283,   284,   285,   286,   278,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,     0,
       0,   568,   569,     0,     0,   541,     0,     0,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,     0,   544,
       0,   280,   281,   282,   283,   284,   285,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   588,     0,
     590,     0,     0,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,   549,     0,     0,     0,     0,     0,
     608,   609,   610,   278,   279,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   443,   443,     0,     0,   624,   625,
     626,   278,   279,     0,     0,     0,     0,     0,   631,   632,
       0,     0,   287,   288,   289,   290,   291,   633,   634,   635,
     636,   637,     0,   554,     0,   280,   281,   282,   283,   284,
     285,   286,   278,   279,     0,   640,     0,     0,   641,     0,
       0,     0,     0,   280,   281,   282,   283,   284,   285,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   443,     0,     0,   651,     0,     0,   653,
       0,     0,     0,     0,   280,   281,   282,   283,   284,   285,
     286,     0,     0,     0,     0,     0,     0,   278,   279,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,     0,   585,     0,     0,
       0,     0,   443,     0,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,   657,   278,   279,     0,   280,
     281,   282,   283,   284,   285,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,     0,   670,     0,     0,     0,
       0,     0,     0,     0,     0,   740,     0,     0,   280,   281,
     282,   283,   284,   285,   286,     0,   745,     0,     0,     0,
      72,    73,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     0,   748,    74,    75,    76,    77,     0,    78,    79,
     287,   288,   289,   290,   291,     0,     0,     0,   753,     0,
     754,   671,   755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
     688,     0,   477,     0,     0,     0,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   789,    97,     0,    98,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    72,    73,
       1,     2,     0,     0,     0,     0,   130,     0,   194,     0,
       0,    74,    75,    76,    77,     0,    78,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,    97,     0,    98,    99,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    72,    73,     1,     2,
       0,     0,     0,     0,   130,   375,     0,     0,     0,    74,
      75,    76,    77,     0,    78,    79,     0,     0,     0,     0,
     278,   279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   280,   281,   282,   283,   284,   285,   286,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     0,    97,
       0,    98,    99,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   278,   279,     0,     0,     0,     0,
       0,     0,   130,   287,   288,   289,   290,   291,   278,   279,
       0,     0,     0,     0,   689,     0,     0,     0,     0,     0,
     278,   279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   279,     0,     0,   280,   281,   282,   283,
     284,   285,   286,     0,   278,   279,     0,     0,     0,     0,
     280,   281,   282,   283,   284,   285,   286,   278,   279,     0,
       0,     0,   280,   281,   282,   283,   284,   285,   286,     0,
       0,     0,     0,     0,   280,   281,   282,   283,   284,   285,
     286,     0,     0,     0,     0,     0,   280,   281,   282,   283,
     284,   285,   286,     0,     0,     0,     0,     0,     0,   280,
     281,   282,   283,   284,   285,   286,     0,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,   690,     0,
       0,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,   693,   287,   288,   289,   290,   291,     0,     0,
     278,   279,     0,     0,   694,   287,   288,   289,   290,   291,
       0,     0,   278,   279,     0,     0,   695,   287,   288,   289,
     290,   291,     0,     0,   278,   279,     0,     0,   696,     0,
     287,   288,   289,   290,   291,     0,   278,   279,     0,     0,
       0,   697,   280,   281,   282,   283,   284,   285,   286,   278,
     279,     0,     0,     0,   280,   281,   282,   283,   284,   285,
     286,   278,   279,     0,     0,     0,   280,   281,   282,   283,
     284,   285,   286,     0,     0,     0,     0,     0,   280,   281,
     282,   283,   284,   285,   286,     0,     0,     0,     0,     0,
       0,   280,   281,   282,   283,   284,   285,   286,     0,     0,
       0,     0,     0,   280,   281,   282,   283,   284,   285,   286,
       0,     0,     0,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,   698,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,     0,   704,   287,   288,   289,
     290,   291,     0,     0,   278,   279,     0,     0,   705,   287,
     288,   289,   290,   291,     0,     0,   278,   279,     0,     0,
     764,     0,   287,   288,   289,   290,   291,   278,   279,     0,
       0,     0,     0,   772,   287,   288,   289,   290,   291,   278,
     279,     0,     0,     0,     0,   777,   280,   281,   282,   283,
     284,   285,   286,   278,   279,     0,     0,     0,   280,   281,
     282,   283,   284,   285,   286,   278,   279,     0,     0,   280,
     281,   282,   283,   284,   285,   286,     0,     0,     0,     0,
       0,   280,   281,   282,   283,   284,   285,   286,     0,     0,
       0,     0,     0,     0,     0,   280,   281,   282,   283,   284,
     285,   286,     0,     0,     0,     0,     0,   280,   281,   282,
     283,   284,   285,   286,     0,     0,     0,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,   778,   287,
     288,   289,   290,   291,     0,     0,     0,     0,   506,     0,
     287,   288,   289,   290,   291,     0,   278,   279,     0,   507,
       0,     0,   287,   288,   289,   290,   291,   278,   279,     0,
       0,   524,     0,     0,     0,     0,   287,   288,   289,   290,
     291,     0,     0,     0,     0,   525,   278,   279,   287,   288,
     289,   290,   291,   278,   279,     0,     0,   612,   280,   281,
     282,   283,   284,   285,   286,   719,   278,   279,   463,   280,
     281,   282,   283,   284,   285,   286,   278,   279,     0,   655,
       0,     0,   769,     0,     0,     0,     0,   779,   280,   281,
     282,   283,   284,   285,   286,   280,   281,   282,   283,   284,
     285,   286,     0,     0,     0,     0,     0,     0,   280,   281,
     282,   283,   284,   285,   286,     0,     0,     0,   280,   281,
     282,   283,   284,   285,   286,     0,     0,     0,     0,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,     0,     0,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,     1,     2,   602,     0,     3,     4,
       5,     0,     6,     7,     0,     0,     0,     0,     0,     8,
       9,    10,     0,     0,    11,    12,    13,    14,    15,     0,
       0,    16,     0,    17,     0,     0,     0,    18,     0,    19,
       0,    20,     0,    21,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,     0,     0,    26,    27,    28,     0,    29,     0,
      30,     0,     0,     0,    31,     0,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    35,
      36,     0,     0,    37,    38,     0,    39,     0,     0,    40,
       1,     2,     0,     0,     3,     4,     5,     0,     6,     7,
       0,     0,     0,    41,     0,     8,     9,    10,     0,     0,
      11,    12,    13,    14,    15,     0,     0,    16,     0,    17,
       0,     0,     0,    18,     0,    19,     0,    20,     0,    21,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,    24,    25,     0,     0,     0,     0,     0,     0,     0,
      26,    27,    28,     0,    29,     0,    30,     0,     0,     0,
      31,     0,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,    37,
      38,     0,    39,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,   171,   349,     7,   221,   222,     3,     4,     8,   294,
       7,    11,    12,    13,     3,    24,     5,   222,    24,   301,
     302,    63,    22,    23,    24,    25,    38,    39,    40,    63,
      63,    31,    32,    33,    49,     3,     0,     5,     7,   350,
      64,   589,   130,   591,     3,     4,     3,     4,   139,    63,
     138,     5,     6,    58,    59,    60,    61,    62,    63,     7,
     192,   193,   139,     0,     7,     7,   348,   139,    16,    17,
      58,    59,    60,    61,    62,    63,   139,   362,   363,    63,
      64,    58,    59,    60,    61,    62,    63,    30,    30,   130,
      64,   138,   660,   140,   136,   663,     5,    45,    41,   140,
      69,    43,   136,   136,   141,   129,   130,   131,   132,   133,
      58,    59,    60,    61,    62,    63,    64,    76,   139,   130,
      30,   136,   136,   130,   139,   130,   258,   136,   260,   140,
     136,   138,   129,     0,   138,    89,    90,    91,    48,     5,
       6,   141,   130,   597,   598,   129,   130,   131,   132,   133,
     139,   498,   140,   130,    79,    22,   156,   131,   132,   133,
      85,   138,   473,   140,   475,    32,     0,   478,   130,   130,
     129,   139,   129,   138,     8,   140,   176,   725,   140,   140,
     180,   129,   130,   131,   132,   133,   130,     7,    22,    23,
      66,   191,   192,   193,   138,   130,   140,   130,    32,   139,
     200,    16,    17,   138,     0,   205,   660,   140,   130,   663,
      30,   139,   212,    62,    63,    64,   501,   502,   140,    39,
     139,   221,   222,     5,     6,   237,   238,   239,   240,   130,
     130,   130,   232,   233,   234,   235,   236,   138,   138,   140,
     140,   140,   130,    58,    59,    60,    61,    62,    63,    64,
     138,   251,   252,   253,   254,    30,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,     7,   130,   130,
      63,   271,   272,   273,   274,   275,   276,   277,   140,   140,
     129,   130,   131,   132,   133,   136,     7,   457,   458,   130,
     130,    12,   574,   130,    15,   606,    63,   138,   130,   140,
     140,   301,   302,   140,    30,   130,   138,   141,   308,    30,
      36,   311,   312,   138,   129,   130,   131,   132,   133,   319,
     138,   321,   140,   138,   191,   192,   193,   327,   328,   329,
     330,   331,   332,   130,   619,   130,    63,   301,   302,   556,
     340,    63,   559,   140,   344,   140,   180,   130,   348,   349,
     661,   556,   130,   130,   559,   138,   140,   191,   192,   193,
     130,   140,   140,   140,   301,   302,   200,   130,   130,   130,
     140,   205,   130,   130,     5,     6,   138,   140,   212,   140,
     344,   130,   140,   140,   348,   349,   138,    33,   140,   138,
     138,   258,   140,   260,   139,   138,   613,   140,   232,   233,
     234,   235,   236,   138,   138,   140,   140,   344,   138,   138,
     140,   348,   349,   138,   130,   140,   727,   251,   252,   253,
     254,   139,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   139,   301,   302,   139,   271,   272,   273,
     274,   275,   276,   277,   138,   138,   140,   140,   139,    58,
      59,    60,    61,    62,    63,    64,     5,     6,     5,     6,
     327,     5,     6,   463,     5,     6,   139,   301,   302,   139,
     470,     5,     6,   139,   308,     5,     6,   344,   137,   138,
     136,   348,   349,     5,     6,   767,   139,   321,   770,     5,
       6,    69,    70,   327,    69,    70,     0,   139,   498,   139,
      61,    62,    63,    64,   786,   139,   340,   139,   790,   791,
     344,    73,    74,   139,   348,   349,     5,     6,    22,    23,
     129,   130,   131,   132,   133,   742,   139,   139,    32,   139,
     136,   531,   139,   533,   498,   139,     4,     5,     6,   139,
     139,   139,   139,   139,   139,   139,    59,   547,    61,    62,
      63,    64,    16,    17,    22,   139,   556,   557,   139,   559,
     560,   498,   562,   139,   136,   139,   566,   567,   129,   130,
     131,   132,   133,   743,   574,   139,   139,    49,     5,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   589,
     138,   591,    24,   139,    58,    59,    60,    61,    62,    63,
      64,   139,   139,   470,   139,   141,   139,   139,   139,   136,
     574,   611,   612,   613,   139,   139,   129,   130,   131,   132,
     133,    89,    90,    91,    92,    93,    24,   139,   139,   463,
     138,   498,   138,   138,     5,    16,   470,   574,   138,   138,
     138,   109,   110,    64,     5,   136,   136,   115,   116,   117,
     118,     7,   120,   138,   122,   655,   124,   125,   126,   136,
     138,   140,   662,   138,   498,   129,   130,   131,   132,   133,
     139,   139,   139,   139,   138,   140,   140,    58,    59,    60,
      61,    62,    63,    64,   139,   139,   139,   191,   192,   193,
      59,    60,    61,    62,    63,    64,   139,   531,   139,   533,
     136,   138,   702,   138,   138,     5,   706,   574,   708,   140,
     140,   711,   140,   547,   139,   139,     5,   139,     3,     7,
     140,   140,   589,   557,   591,   725,   560,   140,   562,   140,
      47,   139,   566,   567,   139,    63,    63,    63,   738,   739,
     574,   741,   742,   136,     7,    46,   613,    72,   129,   130,
     131,   132,   133,    63,   258,   589,   260,   591,   344,   604,
     129,   130,   131,   132,   133,   668,    22,   767,    16,    17,
     770,    22,   222,     6,   759,     8,   570,   611,   612,   742,
     803,   153,   327,   322,   784,   598,   786,    29,    -1,    -1,
     790,   791,    -1,    -1,    -1,   662,    -1,   301,   302,    -1,
      -1,    -1,    -1,   767,   308,    -1,   770,    -1,   808,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,   655,   786,   327,    -1,    -1,   790,   791,   662,    -1,
     767,    -1,    -1,   770,    -1,    -1,    -1,    -1,    -1,    -1,
     344,    -1,    -1,    -1,   348,   349,    -1,    -1,    -1,   786,
      -1,    -1,    -1,   790,   791,    -1,    -1,    -1,   725,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   702,    16,
      17,    -1,   706,    -1,   708,   742,    -1,   711,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,   725,   140,    -1,    -1,    -1,    -1,   130,    -1,    -1,
     767,    -1,    -1,   770,   738,   739,    -1,   741,   141,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,   786,
      -1,    -1,    -1,   790,   791,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   767,    -1,     8,   770,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
     784,    -1,   786,    -1,    -1,    -1,   790,   791,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   470,   200,    -1,    -1,
      -1,    -1,   205,    -1,    -1,    -1,    -1,    -1,    -1,   212,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   138,    -1,   140,   498,    -1,    -1,    -1,    -1,   232,
     233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,   252,
     253,   254,    -1,   256,   257,    -1,   259,    -1,   261,   262,
     263,   264,   265,   266,    -1,    -1,    -1,    -1,   271,   272,
     273,   274,   275,   276,   277,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    16,    17,
     293,   294,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,
     574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   589,    -1,   591,   321,    -1,
      -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,    16,    17,
      58,    59,    60,    61,    62,    63,    64,   340,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,   131,   132,   133,   200,    -1,   362,
     363,   138,   205,   140,    -1,    -1,    -1,    -1,    -1,   212,
      58,    59,    60,    61,    62,    63,    64,    -1,   221,   222,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   662,   232,
     233,   234,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,   251,   252,
     253,   254,   140,   256,   257,    -1,   259,    -1,   261,   262,
     263,   264,   265,   266,    16,    17,    -1,    -1,   271,   272,
     273,   274,   275,   276,   277,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
     138,   725,   140,    -1,    -1,    -1,    -1,    -1,    16,    17,
     463,    -1,   465,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    16,    17,   321,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   767,    -1,    -1,   770,   340,   501,   502,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,   786,    -1,    -1,    -1,   790,   791,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,   531,    -1,
     533,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,   547,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    -1,   557,    -1,    -1,   560,    -1,   562,
      -1,    -1,    -1,   566,   567,    -1,    -1,   570,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   611,   612,
      -1,    -1,    -1,    16,    17,    -1,   619,    -1,    -1,    -1,
     463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,   655,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   531,    -1,
     533,    58,    59,    60,    61,    62,    63,    64,    -1,   702,
      -1,    -1,    -1,   706,   547,   708,    -1,    -1,   711,    -1,
      -1,    -1,    -1,   556,   557,    -1,   559,   560,    -1,   562,
      -1,    -1,    -1,   566,   567,    62,   129,   130,   131,   132,
     133,    -1,    16,    17,    -1,   738,   739,   140,   741,    76,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    -1,   759,    -1,    -1,    16,
      17,    -1,   129,   130,   131,   132,   133,    -1,   611,   612,
     613,    -1,    -1,   140,    58,    59,    60,    61,    62,    63,
      64,   784,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,   655,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   194,    -1,   702,
      -1,    -1,    -1,   706,    -1,   708,    -1,   204,   711,    -1,
      -1,   208,   129,   130,   131,   132,   133,    -1,   215,   216,
      -1,   218,    -1,   140,    16,    17,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   738,   739,    -1,   741,   742,
      -1,    -1,    -1,    -1,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,    -1,    -1,    -1,   255,    -1,
      -1,    -1,    16,    17,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    16,    17,    -1,    -1,
      -1,   784,    -1,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,    -1,   293,   294,    -1,    -1,
      -1,    -1,    -1,   300,    58,    59,    60,    61,    62,    63,
      64,    16,    17,    -1,    -1,    -1,    -1,   314,    58,    59,
      60,    61,    62,    63,    64,    16,    17,    -1,   325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,   341,   342,    -1,    -1,   140,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      16,    17,    -1,    -1,    -1,   362,   363,    58,    59,    60,
      61,    62,    63,    64,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    58,    59,    60,    61,    62,    63,    64,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,   428,   429,    -1,    -1,   140,    -1,    -1,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,
     467,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
     487,   488,   489,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   501,   502,    -1,    -1,   505,   506,
     507,    16,    17,    -1,    -1,    -1,    -1,    -1,   515,   516,
      -1,    -1,   129,   130,   131,   132,   133,   524,   525,   526,
     527,   528,    -1,   140,    -1,    58,    59,    60,    61,    62,
      63,    64,    16,    17,    -1,   542,    -1,    -1,   545,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   570,    -1,    -1,   573,    -1,    -1,   576,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
      -1,    -1,   619,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    16,    17,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   672,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,   683,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   699,    16,    17,    18,    19,    -1,    21,    22,
     129,   130,   131,   132,   133,    -1,    -1,    -1,   715,    -1,
     717,   140,   719,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,   759,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   779,    96,    -1,    98,    99,    -1,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,   139,    -1,   141,    -1,
      -1,    16,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    -1,    98,    99,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    16,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      -1,    98,    99,    -1,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,   139,   129,   130,   131,   132,   133,    16,    17,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    16,    17,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    16,    17,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,
      -1,    -1,   140,   129,   130,   131,   132,   133,    -1,    -1,
      16,    17,    -1,    -1,   140,   129,   130,   131,   132,   133,
      -1,    -1,    16,    17,    -1,    -1,   140,   129,   130,   131,
     132,   133,    -1,    -1,    16,    17,    -1,    -1,   140,    -1,
     129,   130,   131,   132,   133,    -1,    16,    17,    -1,    -1,
      -1,   140,    58,    59,    60,    61,    62,    63,    64,    16,
      17,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    16,    17,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,    -1,    -1,   140,   129,   130,   131,   132,   133,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   129,   130,   131,
     132,   133,    -1,    -1,    16,    17,    -1,    -1,   140,   129,
     130,   131,   132,   133,    -1,    -1,    16,    17,    -1,    -1,
     140,    -1,   129,   130,   131,   132,   133,    16,    17,    -1,
      -1,    -1,    -1,   140,   129,   130,   131,   132,   133,    16,
      17,    -1,    -1,    -1,    -1,   140,    58,    59,    60,    61,
      62,    63,    64,    16,    17,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    16,    17,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,
     129,   130,   131,   132,   133,    -1,    16,    17,    -1,   138,
      -1,    -1,   129,   130,   131,   132,   133,    16,    17,    -1,
      -1,   138,    -1,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    16,    17,   129,   130,
     131,   132,   133,    16,    17,    -1,    -1,   138,    58,    59,
      60,    61,    62,    63,    64,    35,    16,    17,    68,    58,
      59,    60,    61,    62,    63,    64,    16,    17,    -1,    68,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    37,    58,    59,
      60,    61,    62,    63,    64,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,     5,     6,     7,    -1,     9,    10,
      11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      -1,    32,    -1,    34,    -1,    -1,    -1,    38,    -1,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    -1,    69,    -1,
      71,    -1,    -1,    -1,    75,    -1,    77,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    -1,    -1,    94,    95,    -1,    97,    -1,    -1,   100,
       5,     6,    -1,    -1,     9,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,   114,    -1,    20,    21,    22,    -1,    -1,
      25,    26,    27,    28,    29,    -1,    -1,    32,    -1,    34,
      -1,    -1,    -1,    38,    -1,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    -1,    69,    -1,    71,    -1,    -1,    -1,
      75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    -1,    -1,    94,
      95,    -1,    97,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  parser::yystos_[] =
  {
         0,     5,     6,     9,    10,    11,    13,    14,    20,    21,
      22,    25,    26,    27,    28,    29,    32,    34,    38,    40,
      42,    44,    50,    51,    56,    57,    65,    66,    67,    69,
      71,    75,    77,    78,    89,    90,    91,    94,    95,    97,
     100,   114,   143,   144,   145,   147,   148,   163,   164,   180,
     181,   182,   183,   186,   187,   193,   201,   212,   217,   223,
     228,   232,   237,   254,   260,   261,   262,   263,   264,   266,
     139,   139,     3,     4,    16,    17,    18,    19,    21,    22,
      54,    55,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    96,    98,    99,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     139,   166,   167,   169,   174,   180,   182,   260,   261,   263,
     264,   139,   166,   260,   261,   262,   139,   139,     5,   260,
     260,   260,   151,   152,   166,   169,   194,   218,   224,   213,
       5,     6,   163,   164,   260,   261,   264,     5,     6,   179,
     260,   264,   253,   260,   252,   260,   141,   250,   149,    66,
     259,   202,   260,   160,   161,   260,   261,   263,   264,   162,
     260,   139,   139,   139,   141,   169,   176,   176,   176,   176,
     139,     0,    30,     7,    63,    63,   188,   169,    63,   136,
     136,   136,    63,   140,   140,   139,   139,   169,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   169,   169,   166,
     169,    58,    59,    60,    61,    62,    63,   130,    16,    17,
      58,    59,    60,    61,    62,    63,    64,   129,   130,   131,
     132,   133,   166,   153,   154,   136,    33,   251,   251,   260,
     219,   225,   214,   139,   139,   136,    49,   178,   138,   136,
     178,   138,   138,     3,   139,   260,   166,   169,   243,   141,
     244,   245,   150,   260,   261,   203,   155,   138,    24,    24,
      24,    24,   138,   165,   260,   263,   264,   165,   165,   169,
     138,   138,   138,   166,   146,   169,   166,     5,    45,   233,
     235,   169,     5,     6,     5,     6,     5,     6,   166,   169,
     169,   169,   175,   168,     5,     6,   172,   173,   260,   262,
     266,   172,   173,   169,   169,   140,   169,   169,   169,   169,
     169,   169,   169,   166,   166,   166,   166,   166,   166,   176,
     176,   176,   176,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   166,   166,   166,   166,   169,   166,   166,
     165,   166,   165,   166,   166,   166,   166,   166,   166,   140,
     140,   166,   166,   166,   166,   166,   166,   166,   171,   170,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   166,   169,   184,   185,   184,     5,    63,   169,
     145,   145,     5,     6,    79,    85,   177,     5,   264,     6,
     260,   260,   169,    68,   137,   138,     3,   139,   260,   166,
     249,   244,   136,   255,   136,   256,   166,   169,   206,     7,
     205,   161,   260,   260,   260,   260,   260,   138,   138,   138,
     166,   169,   169,   140,   147,   189,   145,   148,   205,   139,
     139,   139,   139,   139,   139,   138,   138,   138,   184,   184,
     139,   139,   140,   140,   136,   138,   138,   140,   140,   140,
     140,   140,   140,   140,   138,   138,   138,   138,   138,   140,
     140,   138,   140,   138,   140,   140,   140,   140,   140,   140,
     140,   140,   138,   140,   140,   138,   140,   138,   140,   140,
     140,   140,   140,   140,   140,   140,   138,   138,   140,   138,
     138,   140,   138,   140,   140,   140,   138,   138,   169,   169,
     138,   140,   140,   195,   220,    30,    41,   226,    30,    43,
     215,   139,   139,   178,   178,   140,   166,   166,   169,   247,
     169,   246,   242,   260,   261,   263,   264,   205,   205,   205,
       3,     4,     7,   129,   156,   157,   158,   159,   169,   169,
     169,   138,   138,   139,   229,   234,   148,   140,   140,   265,
     184,   184,   140,   140,   169,   169,   169,   140,   140,     5,
       6,   169,   169,   169,   169,   169,   169,   169,   166,   166,
     169,   169,   166,   173,   166,   173,   166,   166,   166,   166,
     185,   169,   145,   169,   216,    68,   242,   140,   242,   254,
     257,   258,   259,   257,   207,     3,    76,   157,   138,   205,
     140,   140,   138,   140,   166,   166,     6,   191,   192,   260,
     262,   263,   266,    47,   239,   184,   140,   140,   140,   140,
     140,   139,   139,   140,   140,   140,   140,   140,   140,   138,
     140,   140,   138,   140,   140,   140,   138,   140,   138,   140,
     140,   138,   140,   140,   140,   138,   140,   138,   140,    35,
      30,    39,   221,   227,   166,   248,    70,   258,   205,   260,
     261,   263,   264,    70,    73,    74,   209,   159,    63,    63,
     169,    63,   138,   140,   136,   169,   230,   140,   169,   166,
     166,   166,   166,   169,   169,   169,   222,   242,   205,   208,
       7,    72,   166,   166,   140,   166,   192,   178,     6,    45,
      46,   238,   140,   140,   140,   140,   140,   140,   140,    37,
     200,   206,   210,   204,    63,   145,   240,   145,   231,   169,
     196,   211,   166,    12,    15,    30,   190,   145,    30,    48,
     236,   145,   145,   241,   197,   239,    30,    36,   198,   199,
     260
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
     375,   376,   377,   378,   379,   380,   381,   382,   383,    45,
      43,    42,    47,   384,   385,   386,    46,    59,    44,    40,
      41,    35
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  parser::yyr1_[] =
  {
         0,   142,   143,   144,   145,   146,   145,   147,   147,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   149,
     148,   150,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   151,   148,   152,   148,   148,
     148,   148,   148,   148,   148,   148,   153,   148,   154,   148,
     155,   148,   148,   148,   156,   156,   157,   158,   158,   159,
     159,   159,   160,   160,   161,   161,   161,   161,   162,   162,
     163,   163,   164,   164,   164,   164,   164,   164,   165,   165,
     166,   166,   166,   166,   166,   166,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   168,   167,   170,
     169,   171,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   172,   173,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   175,   174,
     176,   176,   177,   177,   178,   178,   179,   179,   179,   179,
     180,   180,   181,   182,   182,   183,   184,   184,   185,   185,
     186,   186,   188,   189,   187,   190,   190,   190,   191,   191,
     191,   192,   192,   192,   192,   194,   195,   196,   197,   193,
     198,   198,   199,   199,   200,   200,   202,   203,   204,   201,
     205,   205,   206,   206,   207,   208,   207,   209,   210,   211,
     209,   213,   214,   212,   215,   216,   215,   218,   219,   220,
     217,   221,   222,   221,   224,   225,   223,   226,   227,   226,
     229,   230,   231,   228,   233,   234,   232,   235,   232,   236,
     236,   237,   238,   238,   239,   240,   241,   239,   242,   242,
     242,   242,   243,   243,   243,   243,   243,   243,   243,   245,
     244,   246,   244,   247,   244,   248,   244,   249,   250,   250,
     250,   250,   251,   252,   252,   253,   253,   255,   254,   256,
     254,   257,   257,   258,   258,   258,   258,   258,   259,   260,
     260,   261,   261,   261,   261,   262,   262,   262,   262,   263,
     263,   264,   264,   264,   265,   264,   266,   266,   266,   266
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     1,     1,     0,     4,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     4,     0,
       3,     0,     4,     1,     2,     2,     2,     4,     1,     2,
       4,     6,     2,     4,     6,     0,     3,     0,     3,     2,
       2,     2,     2,     2,     4,     2,     0,     5,     0,     5,
       0,     6,     2,     2,     1,     2,     2,     1,     3,     1,
       2,     1,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,    10,     8,     8,     8,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     4,     4,     4,     4,     4,     4,     6,
       4,     6,     4,     1,     1,     4,     4,     0,     5,     0,
       4,     0,     4,     2,     3,     3,     3,     3,     3,     3,
       4,     6,     4,     4,     6,     6,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     2,     2,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     3,     6,     6,     4,     4,     4,
       6,     8,     6,     8,     4,     6,     6,     6,     8,     6,
       8,     6,     4,     6,     6,     8,     4,     4,     0,     5,
       2,     1,     1,     1,     0,     2,     2,     2,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     0,     0,    10,     1,     1,     1,     0,     1,
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
  "tSTRSYM", "tSEPARATOR", "tCALL", "tBREAK", "tCONTINUE", "tSUB",
  "tENDSUB", "tRETURN", "tFUNCTION", "tENDFUNCTION", "tAND", "tOR", "tNOT",
  "tEOR", "tCOMPILE", "tEXECUTERETURNNUMBER", "tEXECUTERETURNSTRING",
  "tCSUB", "tFROM", "tGOTO", "tGOSUB", "tLABEL", "tENABLE", "tDISABLE",
  "tEOPROG", "tNEWFILE", "tEXIT", "tEXPLICIT", "tFOR", "tTO", "tNEXT",
  "tSTEP", "tWHILE", "tWEND", "tREPEAT", "tUNTIL", "tDO", "tLOOP", "tIF",
  "tTHEN", "tELSE", "tELSEIF", "tENDIF", "tAS", "tLET", "tDIM", "tLOCAL",
  "tSTATIC", "tARDIM", "tARSIZE", "tINC", "tDEC", "tNEQ", "tLEQ", "tGEQ",
  "tLTN", "tGTN", "tEQU", "tPOW", "tPRINT", "tINPUT", "tLINE", "tUSING",
  "tSTRUCT", "tENDSTRUCT", "tSWITCH", "tSEND", "tCASE", "tDEFAULT",
  "tDATA", "tENDDATA", "tREAD", "tRESTORE", "tLONG", "tABS", "tSIG",
  "tRAN", "tSQR", "tSQRT", "tINT", "tFRAC", "tMIN", "tMAX", "tLEFT",
  "tRIGHT", "tMID", "tUPPER", "tLOWER", "tOPEN", "tCLOSE", "tEOF", "tSEEK",
  "tTELL", "tPEEK", "tPOKE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN",
  "tATAN", "tEXP", "tLOG", "tSTR", "tCHR", "tVAL", "tASC", "tLEN",
  "tSYSTEM", "tARG", "tENV", "tTIME", "tDATE", "tTOKEN", "tTOKENALT",
  "tSPLIT", "tSPLITALT", "tGLOB", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR",
  "tRINSTR", "'-'", "'+'", "'*'", "'/'", "tMOD", "UPLUS", "UMINUS", "'.'",
  "';'", "','", "'('", "')'", "'#'", "$accept", "program",
  "list_of_statement_lists", "statement_list", "$@1", "statement",
  "non_empty_statement", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "data_list", "data_row", "data_row_items", "data_item", "read_list",
  "read_item", "restore_list", "number_assignment", "string_assignment",
  "string_scalar_or_array", "string_expression", "string_function", "$@9",
  "number_expression", "$@10", "$@11", "number_arrayref",
  "string_arrayref", "number_function", "$@12", "hashed_number",
  "exprtype", "dim_as_type", "dim_list",
  "number_function_or_array_any_params",
  "number_function_or_array_with_params",
  "string_function_or_array_any_params",
  "string_function_or_array_with_params", "call_list", "call_item",
  "begin_sub", "function_definition", "$@13", "@14", "endsub",
  "param_list", "param_item", "for_loop", "$@15", "$@16", "$@17", "$@18",
  "next", "next_symbol", "step_part", "switch_number_or_string", "$@19",
  "$@20", "$@21", "separator_list", "number_or_string", "case_list",
  "$@22", "default", "$@23", "$@24", "do_loop", "$@25", "$@26", "loop",
  "$@27", "while_loop", "$@28", "$@29", "$@30", "wend", "$@31",
  "repeat_loop", "$@32", "$@33", "until", "$@34", "if_clause", "$@35",
  "$@36", "$@37", "short_if", "$@38", "$@39", "$@40", "endif", "if_part",
  "else_part", "elseif_part", "$@41", "$@42", "input", "print_list",
  "input_body", "$@43", "$@44", "$@45", "$@46", "prompt", "print_intro",
  "option", "dec_list", "inc_list", "structure_definition", "$@47", "$@48",
  "structure_definition_parts", "structure_definition_variable", "new_cli",
  "numsym_s", "numsym_a", "numsym_a_no_calls", "strsym_s", "strsym_a",
  "$@49", "strsym_a_no_calls", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
       143,     0,    -1,   144,    30,    -1,   145,    -1,   147,    -1,
      -1,   145,     7,   146,   147,    -1,    -1,   148,    -1,   163,
      -1,   164,    -1,    50,   163,    -1,    50,   164,    -1,   228,
      -1,   232,    -1,   212,    -1,   193,    -1,   223,    -1,   217,
      -1,   201,    -1,     9,    -1,    10,    -1,   187,    -1,   254,
      -1,   180,    -1,   182,    -1,    65,   250,   243,    -1,    65,
     250,   243,   137,    -1,    65,   250,   243,   138,    -1,    -1,
      66,   149,   244,    -1,    -1,    67,    66,   150,   244,    -1,
      13,    -1,    13,   169,    -1,    13,   166,    -1,    51,   179,
      -1,   114,   139,   166,   140,    -1,    32,    -1,    32,   169,
      -1,    94,   176,   138,   166,    -1,    94,   176,   138,   166,
     138,   166,    -1,    95,   176,    -1,    97,   176,   138,   169,
      -1,    97,   176,   138,   169,   138,   166,    -1,    -1,    28,
     151,   251,    -1,    -1,    29,   152,   251,    -1,    57,   252,
      -1,    56,   253,    -1,    25,   260,    -1,    26,   260,    -1,
      27,   260,    -1,   100,   176,   138,   169,    -1,    20,   166,
      -1,    -1,    21,   139,   153,   184,   140,    -1,    -1,    22,
     139,   154,   184,   140,    -1,    -1,    75,   260,   155,   205,
     156,    76,    -1,    77,   160,    -1,    78,   162,    -1,   157,
      -1,   156,   157,    -1,   158,   205,    -1,   159,    -1,   158,
     138,   159,    -1,     3,    -1,   129,     3,    -1,     4,    -1,
     161,    -1,   160,   138,   161,    -1,   260,    24,   260,    -1,
     263,    24,   260,    -1,   261,    24,   260,    -1,   264,    24,
     260,    -1,   260,    -1,   162,   138,   260,    -1,   260,    63,
     169,    -1,   181,    63,   169,    -1,   263,    63,   166,    -1,
      91,   139,   165,   138,   169,   138,   169,   140,    63,   166,
      -1,    91,   139,   165,   138,   169,   140,    63,   166,    -1,
      89,   139,   165,   138,   169,   140,    63,   166,    -1,    90,
     139,   165,   138,   169,   140,    63,   166,    -1,   183,    63,
     166,    -1,   263,    -1,   264,    -1,   263,    -1,   167,    -1,
     182,    -1,     4,    -1,   166,   130,   166,    -1,   139,   166,
     140,    -1,    89,   139,   166,   138,   169,   140,    -1,    90,
     139,   166,   138,   169,   140,    -1,    91,   139,   166,   138,
     169,   138,   169,   140,    -1,    91,   139,   166,   138,   169,
     140,    -1,   109,   139,   169,   140,    -1,   109,   139,   169,
     138,   166,   140,    -1,   109,   139,   169,   138,   166,   138,
     166,   140,    -1,   110,   139,   169,   140,    -1,    92,   139,
     166,   140,    -1,    93,   139,   166,   140,    -1,   125,   139,
     166,   140,    -1,   126,   139,   166,   140,    -1,   124,   139,
     166,   140,    -1,   120,   139,   165,   138,   166,   140,    -1,
     120,   139,   165,   140,    -1,   122,   139,   165,   138,   166,
     140,    -1,   122,   139,   165,   140,    -1,   118,    -1,   117,
      -1,   115,   139,   169,   140,    -1,   116,   139,   166,   140,
      -1,    -1,    22,   139,   168,   184,   140,    -1,    -1,   169,
      17,   170,   169,    -1,    -1,   169,    16,   171,   169,    -1,
      18,   169,    -1,   169,    63,   169,    -1,   169,    58,   169,
      -1,   169,    61,   169,    -1,   169,    59,   169,    -1,   169,
      62,   169,    -1,   169,    60,   169,    -1,    96,   139,   176,
     140,    -1,   123,   139,   166,   138,   166,   140,    -1,    54,
     139,   172,   140,    -1,    54,   139,   173,   140,    -1,    55,
     139,   172,   138,   169,   140,    -1,    55,   139,   173,   138,
     169,   140,    -1,   180,    -1,   166,    63,   166,    -1,   166,
      58,   166,    -1,   166,    61,   166,    -1,   166,    59,   166,
      -1,   166,    62,   166,    -1,   166,    60,   166,    -1,   174,
      -1,   169,   133,   169,    -1,   169,    64,   169,    -1,   130,
     169,    -1,   129,   169,    -1,   169,   131,   169,    -1,   169,
     132,   169,    -1,   169,   129,   169,    -1,   169,   130,   169,
      -1,   139,   169,   140,    -1,   260,    -1,     3,    -1,   262,
      -1,   266,    -1,   101,   139,   169,   140,    -1,   102,   139,
     169,   140,    -1,   103,   139,   169,   140,    -1,   104,   139,
     169,   140,    -1,   105,   139,   169,   140,    -1,   106,   139,
     169,   140,    -1,   106,   139,   169,   138,   169,   140,    -1,
     107,   139,   169,   140,    -1,   108,   139,   169,   140,    -1,
     108,   139,   169,   138,   169,   140,    -1,    85,   139,   169,
     140,    -1,    83,   139,   169,   140,    -1,    84,   139,   169,
     140,    -1,    86,   139,   169,   140,    -1,    80,   139,   169,
     140,    -1,    81,   139,   169,   140,    -1,    82,   139,   169,
     140,    -1,    82,   139,   140,    -1,    87,   139,   169,   138,
     169,   140,    -1,    88,   139,   169,   138,   169,   140,    -1,
     113,   139,   166,   140,    -1,   111,   139,   166,   140,    -1,
     112,   139,   166,   140,    -1,   127,   139,   166,   138,   166,
     140,    -1,   127,   139,   166,   138,   166,   138,   169,   140,
      -1,   128,   139,   166,   138,   166,   140,    -1,   128,   139,
     166,   138,   166,   138,   169,   140,    -1,   114,   139,   166,
     140,    -1,    16,   139,   169,   138,   169,   140,    -1,    17,
     139,   169,   138,   169,   140,    -1,    19,   139,   169,   138,
     169,   140,    -1,   119,   139,   166,   138,   173,   138,   166,
     140,    -1,   119,   139,   166,   138,   173,   140,    -1,   121,
     139,   166,   138,   173,   138,   166,   140,    -1,   121,   139,
     166,   138,   173,   140,    -1,    94,   139,   166,   140,    -1,
      94,   139,   166,   138,   166,   140,    -1,    94,   139,   176,
     138,   166,   140,    -1,    94,   139,   176,   138,   166,   138,
     166,   140,    -1,    98,   139,   176,   140,    -1,    99,   139,
     176,   140,    -1,    -1,    21,   139,   175,   184,   140,    -1,
     141,   169,    -1,   169,    -1,    79,    -1,    85,    -1,    -1,
      49,   177,    -1,     5,   178,    -1,   264,   178,    -1,   179,
     138,     5,   178,    -1,   179,   138,   264,   178,    -1,   261,
      -1,   262,    -1,   261,    -1,   264,    -1,   266,    -1,   264,
      -1,   185,    -1,   184,   138,   185,    -1,   166,    -1,   169,
      -1,    11,    -1,    14,    -1,    -1,    -1,   186,   188,     5,
     189,   139,   191,   140,   178,   145,   190,    -1,    30,    -1,
      12,    -1,    15,    -1,    -1,   192,    -1,   191,   138,   192,
      -1,   260,    -1,   263,    -1,   262,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    34,   194,   260,    63,   195,   169,    35,
     169,   200,   196,   145,   197,   198,   199,    -1,    30,    -1,
      36,    -1,    -1,   260,    -1,    -1,    37,   169,    -1,    -1,
      -1,    -1,    71,   202,   203,   206,   205,   207,   209,    72,
     204,    -1,     7,    -1,   205,     7,    -1,   169,    -1,   166,
      -1,    -1,    -1,   207,    73,   208,   206,    -1,    -1,    -1,
      -1,    74,     7,   210,   211,   145,    -1,    -1,    -1,    42,
     213,   214,   145,   215,    -1,    30,    -1,    -1,    43,   216,
      -1,    -1,    -1,    -1,    38,   218,   219,   169,   220,   145,
     221,    -1,    30,    -1,    -1,    39,   222,    -1,    -1,    -1,
      40,   224,   225,   145,   226,    -1,    30,    -1,    -1,    41,
     169,   227,    -1,    -1,    -1,    -1,   237,   169,    45,   145,
     229,   239,   230,   238,   231,   236,    -1,    -1,    -1,   237,
     169,   233,   148,   234,    -1,    -1,   237,   169,   235,   205,
     148,    -1,    30,    -1,    48,    -1,    44,    -1,    -1,    46,
     145,    -1,    -1,    -1,    -1,    47,   169,    45,   240,   145,
     241,   239,    -1,   260,    -1,   263,    -1,   261,    -1,   264,
      -1,    -1,   169,    -1,   169,    68,   166,    -1,   166,    -1,
     243,   138,   169,    -1,   243,   138,   169,    68,   166,    -1,
     243,   138,   166,    -1,    -1,   245,   249,   242,    -1,    -1,
     141,   260,   246,   242,    -1,    -1,   141,     3,   247,   242,
      -1,    -1,   141,   139,   169,   140,   248,   242,    -1,   166,
      -1,    -1,   141,   260,    -1,   141,     3,    -1,   141,   139,
     169,   140,    -1,    33,    -1,   260,    -1,   252,   138,   260,
      -1,   260,    -1,   253,   138,   260,    -1,    -1,    69,   259,
     260,   255,   205,   257,    70,    -1,    -1,    69,   259,   261,
     256,   205,   257,    70,    -1,   258,   205,    -1,   257,   258,
     205,    -1,   254,    -1,   259,   260,    -1,   259,   263,    -1,
     259,   261,    -1,   259,   264,    -1,    -1,     5,    -1,   260,
     136,     5,    -1,     5,   139,    -1,   261,   136,     5,   139,
     184,   140,    -1,   261,   136,     5,    -1,   260,   136,     5,
     139,    -1,     5,   139,   140,    -1,   262,   136,     5,   139,
     140,    -1,   262,   136,     5,    -1,   260,   136,     5,   139,
     140,    -1,     6,    -1,   260,   136,     6,    -1,     6,   139,
      -1,   261,   136,     6,   139,   184,   140,    -1,   261,   136,
       6,    -1,    -1,   260,   136,     6,   139,   265,   184,   140,
      -1,     6,   139,   140,    -1,   262,   136,     6,   139,   140,
      -1,   262,   136,     6,    -1,   260,   136,     6,   139,   140,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    10,    11,    16,    17,    19,
      21,    23,    26,    29,    31,    33,    35,    37,    39,    41,
      43,    45,    47,    49,    51,    53,    55,    59,    64,    69,
      70,    74,    75,    80,    82,    85,    88,    91,    96,    98,
     101,   106,   113,   116,   121,   128,   129,   133,   134,   138,
     141,   144,   147,   150,   153,   158,   161,   162,   168,   169,
     175,   176,   183,   186,   189,   191,   194,   197,   199,   203,
     205,   208,   210,   212,   216,   220,   224,   228,   232,   234,
     238,   242,   246,   250,   261,   270,   279,   288,   292,   294,
     296,   298,   300,   302,   304,   308,   312,   319,   326,   335,
     342,   347,   354,   363,   368,   373,   378,   383,   388,   393,
     400,   405,   412,   417,   419,   421,   426,   431,   432,   438,
     439,   444,   445,   450,   453,   457,   461,   465,   469,   473,
     477,   482,   489,   494,   499,   506,   513,   515,   519,   523,
     527,   531,   535,   539,   541,   545,   549,   552,   555,   559,
     563,   567,   571,   575,   577,   579,   581,   583,   588,   593,
     598,   603,   608,   613,   620,   625,   630,   637,   642,   647,
     652,   657,   662,   667,   672,   676,   683,   690,   695,   700,
     705,   712,   721,   728,   737,   742,   749,   756,   763,   772,
     779,   788,   795,   800,   807,   814,   823,   828,   833,   834,
     840,   843,   845,   847,   849,   850,   853,   856,   859,   864,
     869,   871,   873,   875,   877,   879,   881,   883,   887,   889,
     891,   893,   895,   896,   897,   908,   910,   912,   914,   915,
     917,   921,   923,   925,   927,   929,   930,   931,   932,   933,
     948,   950,   952,   953,   955,   956,   959,   960,   961,   962,
     972,   974,   977,   979,   981,   982,   983,   988,   989,   990,
     991,   997,   998,   999,  1005,  1007,  1008,  1011,  1012,  1013,
    1014,  1022,  1024,  1025,  1028,  1029,  1030,  1036,  1038,  1039,
    1043,  1044,  1045,  1046,  1057,  1058,  1059,  1065,  1066,  1072,
    1074,  1076,  1078,  1079,  1082,  1083,  1084,  1085,  1093,  1095,
    1097,  1099,  1101,  1102,  1104,  1108,  1110,  1114,  1120,  1124,
    1125,  1129,  1130,  1135,  1136,  1141,  1142,  1149,  1151,  1152,
    1155,  1158,  1163,  1165,  1167,  1171,  1173,  1177,  1178,  1186,
    1187,  1195,  1198,  1202,  1204,  1207,  1210,  1213,  1216,  1217,
    1219,  1223,  1226,  1233,  1237,  1242,  1246,  1252,  1256,  1262,
    1264,  1268,  1271,  1278,  1282,  1283,  1291,  1295,  1301,  1305
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   200,   200,   220,   222,   225,   225,   232,   233,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   253,   259,   260,   261,   262,   263,   275,   282,   289,
     289,   290,   290,   291,   294,   299,   300,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   313,   314,   314,   315,
     316,   317,   320,   321,   324,   325,   326,   326,   329,   329,
     330,   330,   331,   332,   335,   336,   339,   342,   343,   346,
     347,   348,   351,   352,   355,   356,   357,   358,   361,   362,
     365,   372,   375,   376,   377,   378,   379,   380,   385,   386,
     389,   390,   391,   392,   393,   394,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   418,   418,   421,
     421,   422,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   449,   454,   457,
     460,   464,   468,   469,   473,   478,   481,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   525,
     528,   529,   532,   535,   541,   542,   550,   557,   558,   563,
     566,   567,   570,   573,   574,   577,   580,   581,   584,   585,
     588,   589,   593,   594,   593,   609,   615,   616,   639,   640,
     641,   644,   645,   648,   651,   656,   657,   661,   663,   656,
     669,   674,   677,   678,   681,   682,   685,   685,   687,   685,
     692,   693,   696,   697,   700,   701,   701,   709,   710,   710,
     710,   716,   716,   716,   721,   722,   722,   725,   725,   726,
     725,   732,   733,   733,   736,   736,   736,   741,   743,   742,
     747,   748,   752,   746,   763,   764,   763,   765,   765,   769,
     770,   773,   776,   777,   780,   782,   784,   781,   788,   789,
     790,   791,   794,   795,   800,   802,   804,   806,   808,   812,
     812,   813,   813,   814,   814,   815,   815,   818,   822,   827,
     828,   829,   832,   835,   836,   839,   840,   844,   844,   860,
     860,   878,   879,   882,   883,   891,   899,   907,   917,   925,
     929,   932,   935,   936,   937,   940,   943,   944,   945,   948,
     949,   952,   953,   954,   955,   955,   958,   959,   960,   961
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
       2,     2,     2,     2,     2,   141,     2,     2,     2,     2,
     139,   140,   131,   130,   138,   129,   136,   132,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   137,
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
     125,   126,   127,   128,   133,   134,   135
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 3319;
  const int parser::yynnts_ = 125;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 201;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 142;

  const unsigned int parser::yyuser_token_number_max_ = 386;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 22 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 4185 "/home/cai/projects/basic/compiler/parser.cpp"
