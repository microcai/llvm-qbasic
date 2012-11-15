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
#line 198 "parser.ypp"
    {
			if(useDefautSubMain){
				program = new DefaultMainFunctionAST( (yysemantic_stack_[(2) - (1)].statement_list) );
			}else{
				program = (yysemantic_stack_[(2) - (1)].statement_list);
			}
			debug("program ended\n");
			/*add_command (cEOPROG, NULL);*/
			// yylex_destroy ();
			YYACCEPT;
		}
    break;

  case 3:
/* Line 661 of lalr1.cc  */
#line 211 "parser.ypp"
    { (yyval.statement_list) = (yysemantic_stack_[(1) - (1)].statement_list); debug("list_of_statement_lists\n"); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 215 "parser.ypp"
    { (yyval.statement_list) = new StatementsAST(); (yyval.statement_list)->append(StatementASTPtr((yysemantic_stack_[(1) - (1)].statement)));}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 216 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 216 "parser.ypp"
    {
		if((yysemantic_stack_[(4) - (4)].statement)){
			debug("got statement_list now %p\n",(yysemantic_stack_[(4) - (4)].statement));
			(yyval.statement_list) = (yysemantic_stack_[(4) - (1)].statement_list);
			(yysemantic_stack_[(4) - (1)].statement_list)->append(StatementASTPtr((yysemantic_stack_[(4) - (4)].statement)));
		}
	}
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 225 "parser.ypp"
    { (yyval.statement) = 0 ;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 226 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 240 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { debug ("cannot \"break\" outside of loop"); }
   }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 244 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   debug ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 252 "parser.ypp"
    { }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 253 "parser.ypp"
    { }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 254 "parser.ypp"
    { }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 255 "parser.ypp"
    { }
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 256 "parser.ypp"
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

  case 32:
/* Line 661 of lalr1.cc  */
#line 268 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
	   if(current_function.empty())
			useDefautSubMain = true;
   }
    break;

  case 33:
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

  case 34:
/* Line 661 of lalr1.cc  */
#line 282 "parser.ypp"
    { until_eol = false; }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 282 "parser.ypp"
    {}
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 283 "parser.ypp"
    { until_eol = true; }
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 283 "parser.ypp"
    {}
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 284 "parser.ypp"
    {
	   
             }
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 287 "parser.ypp"
    {

	   
   }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    { }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 293 "parser.ypp"
    {
	   debug("got syntax of \"dim local var\" now\n");

	   (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list);	   
	}
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 298 "parser.ypp"
    {
	   
}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 301 "parser.ypp"
    {}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 302 "parser.ypp"
    {}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 303 "parser.ypp"
    {}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 304 "parser.ypp"
    {}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 305 "parser.ypp"
    {}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 306 "parser.ypp"
    {}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    {}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 308 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 309 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 312 "parser.ypp"
    {

   }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 315 "parser.ypp"
    {  }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 316 "parser.ypp"
    {
		debug("got label!\n");
   }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 319 "parser.ypp"
    {  }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 320 "parser.ypp"
    {  }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 321 "parser.ypp"
    {  }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 321 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    { }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    {  }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 325 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 341 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 342 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 343 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 79:
/* Line 661 of lalr1.cc  */
#line 350 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 351 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 352 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 353 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 356 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 360 "parser.ypp"
    {
		// 变量赋值
		debug("变量赋值\n");
		(yyval.number_assignment) = new NumberAssigmentAST(VariableRefExprASTPtr((yysemantic_stack_[(3) - (1)].varable_ref)), NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
		if(current_function.empty())
			useDefautSubMain = true;
	}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 367 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 370 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 371 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 373 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 374 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 375 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 381 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 419 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 420 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 421 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 422 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 423 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 425 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 427 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 428 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 429 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 430 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 431 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 432 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 433 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 435 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 436 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 437 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 439 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 440 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 441 "parser.ypp"
    {
	   (yyval.number_expression) = (yysemantic_stack_[(2) - (2)].number_expression) ;
   }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 444 "parser.ypp"
    {
	   /*add_command(cNEGATE,NULL);*/
	   ConstNumberExprAST * zero = new ConstNumberExprAST(0);
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr(zero) ,OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression)));
   }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 449 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_MUL,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 452 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_DIV,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 455 "parser.ypp"
    {
	   // 减法计算
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 459 "parser.ypp"
    {
	   // 加法计算.
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_ADD,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 463 "parser.ypp"
    { (yyval.number_expression) = (yysemantic_stack_[(3) - (2)].number_expression) ;}
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 464 "parser.ypp"
    {
	   debug("got numsym_s\n");	   
	   (yyval.number_expression) =new NumberExprAST( VariableExprASTPtr((yysemantic_stack_[(1) - (1)].varable_ref)) );
	}
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 468 "parser.ypp"
    {
	   (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));
   }
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 473 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 476 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 479 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 480 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 481 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 482 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 483 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 484 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 487 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 488 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 489 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 491 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 492 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 495 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 496 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 497 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 498 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 499 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 500 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 502 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 503 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 504 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 505 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 506 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 507 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 508 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 509 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 510 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 511 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 512 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 513 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 514 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 515 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 516 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 517 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 518 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 519 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 520 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 520 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 207:
/* Line 661 of lalr1.cc  */
#line 527 "parser.ypp"
    {
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 530 "parser.ypp"
    {
		//TODO int should be 32bit not 64bit
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 537 "parser.ypp"
    {
			debug("as  %s\n",(yysemantic_stack_[(2) - (2)].exprtype)->name.c_str());
			// long varable
			// 构造类型
			(yyval.exprtype) = (yysemantic_stack_[(2) - (2)].exprtype);
		}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 545 "parser.ypp"
    {
		/*变量定义*/
		// 在 AST 中分配一个变量名称列表.
		std::string name;
		name = (yysemantic_stack_[(2) - (1)].symbol);
		(yyval.dim_list) = new VariableDimAST( name , ExprTypeASTPtr((yysemantic_stack_[(2) - (2)].exprtype)));		
	}
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 552 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 553 "parser.ypp"
    {
	  // 	std::string name;
	//	name = $3;
	//	$$ = new VariableDimAST( name , ExprTypeASTPtr($2));
   }
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 558 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 561 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 562 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 565 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 568 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 219:
/* Line 661 of lalr1.cc  */
#line 569 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 220:
/* Line 661 of lalr1.cc  */
#line 572 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 575 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 576 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 225:
/* Line 661 of lalr1.cc  */
#line 583 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 584 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 588 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
	}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 589 "parser.ypp"
    { current_function = (yysemantic_stack_[(3) - (3)].symbol); }
    break;

  case 229:
/* Line 661 of lalr1.cc  */
#line 590 "parser.ypp"
    {	}
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 591 "parser.ypp"
    {
						debug("function dim as ... %p\n", (yysemantic_stack_[(9) - (9)].exprtype) );
						//$<exprtype>$ = $9;
						(yyval.function_definition) = new FunctionDimAST( (yysemantic_stack_[(9) - (3)].symbol), ExprTypeASTPtr((yysemantic_stack_[(9) - (9)].exprtype)) );
			// 到这里可以算是函数定义成功了.
	}
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 596 "parser.ypp"
    {
		(yyval.statement_list) = (yysemantic_stack_[(11) - (11)].statement_list);
	}
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 599 "parser.ypp"
    {
		current_function.clear();
		/** TODO support for functions*/
	}
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 605 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 611 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 612 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 623 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 624 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 625 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 626 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 633 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 247:
/* Line 661 of lalr1.cc  */
#line 634 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 248:
/* Line 661 of lalr1.cc  */
#line 635 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 249:
/* Line 661 of lalr1.cc  */
#line 636 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 644 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 254:
/* Line 661 of lalr1.cc  */
#line 645 "parser.ypp"
    {
	   
}
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 648 "parser.ypp"
    {
	   
}
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 651 "parser.ypp"
    {
	   
}
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 656 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 657 "parser.ypp"
    {
				 
			}
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 661 "parser.ypp"
    {
	 }
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 663 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 665 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 669 "parser.ypp"
    {
		if (unclosed_fors) {
			debug ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 674 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 677 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 678 "parser.ypp"
    {  }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 681 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 685 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 685 "parser.ypp"
    {
	}
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 687 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 687 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 692 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 693 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 701 "parser.ypp"
    {
	   
}
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 704 "parser.ypp"
    {
		   
	}
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 710 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 710 "parser.ypp"
    {

	   
}
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 716 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 716 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 721 "parser.ypp"
    {if (unclosed_dos) { debug ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 725 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 725 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 726 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 732 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 733 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 733 "parser.ypp"
    { }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 736 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 736 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 741 "parser.ypp"
    {if (unclosed_repeats) { debug ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 746 "parser.ypp"
    {
				/*构造 IF 语句, 填充 条件表达式*/
				NumberExprASTPtr ne = NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression));

								
			}
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 751 "parser.ypp"
    {  /*填充真语句*/ }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 753 "parser.ypp"
    { /*填充假语句*/}
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 757 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 758 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 758 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 759 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 760 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 763 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 764 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 767 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 776 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 778 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 782 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 783 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 785 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 788 "parser.ypp"
    { debug("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 789 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 795 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 797 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 799 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 801 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 803 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 806 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 807 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 808 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 809 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 813 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 816 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 821 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 822 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 823 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 826 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 829 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 830 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 833 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 834 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 838 "parser.ypp"
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

  case 350:
/* Line 661 of lalr1.cc  */
#line 848 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 854 "parser.ypp"
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

  case 352:
/* Line 661 of lalr1.cc  */
#line 864 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 877 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 885 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 893 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 901 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 360:
/* Line 661 of lalr1.cc  */
#line 911 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 919 "parser.ypp"
    {
		debug("变量引用\n");
		(yyval.varable_ref) = new VariableRefExprAST( (yysemantic_stack_[(1) - (1)].symbol) );
	}
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 923 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 926 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 928 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 929 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 930 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 933 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 936 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 937 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 938 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 941 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 942 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 945 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 946 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 947 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 948 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 948 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 951 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 952 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 953 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 954 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2582 "/home/cai/projects/basic/compiler/parser.cpp"
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
      3252,    -8,     8,  -610,  -610,  -610,  2208,  -610,  1121,    18,
      39,   107,   107,   107,  -610,  -610,  2208,  -610,  -610,  -610,
    -610,  -610,    44,   111,  -610,  -610,   107,   107,    53,  -610,
     119,  -610,  -610,   107,   299,   107,    60,    86,    90,  1804,
    1804,  1804,  1804,    97,   142,   371,   202,  -610,  -610,  -610,
    -610,  -610,   125,  -610,   151,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  2208,  -610,   -26,   -23,   136,   192,
     223,  -610,   158,   179,  -610,  -610,   204,   217,  2208,   240,
     266,   311,   346,   353,   363,   365,   373,   380,   382,   384,
     385,   387,   388,   390,   391,   392,   393,   400,   401,   402,
     403,   405,   406,   407,   410,   414,   415,   417,   419,   420,
     422,   423,   424,   425,   440,   443,   446,   448,  -610,  -610,
     449,   450,   453,   454,   455,   456,   458,   460,   461,   462,
    2208,  2208,  2208,    62,  -610,  3042,  -610,  -610,  -610,   253,
     279,  -610,  -610,  1121,   312,   253,   279,   136,  -610,  -610,
    -610,   379,   379,   379,   535,   535,    62,  3042,   107,  -610,
    -610,  -610,   463,   473,  -610,  -610,   -22,   279,  -610,   -10,
     473,   432,   442,   527,   299,   299,   475,   379,   476,   379,
      26,  2208,   477,  -610,   591,  -610,   379,   481,  -610,    -9,
       1,   587,   592,   483,   379,   299,   299,   299,  2208,  3042,
     486,  -610,   487,   492,  1121,  -610,  -610,  3252,  -610,  2208,
    1121,   427,    38,  2208,   439,   457,   459,  1121,  -610,  -610,
    2208,  2208,  1806,  2208,  -610,  -610,   468,   468,  2208,  2208,
    2065,  2208,  2208,  2208,  2208,  2208,  2208,  1121,  1121,  1121,
    1121,  1121,  1804,  1804,  1804,  1804,  2208,  2208,  2208,  2208,
    2208,  2208,  2208,  2208,  2208,  2208,  1121,  1121,  1121,  1121,
    2208,  1121,  1121,   299,  1121,   299,  1121,  1121,  1121,  1121,
    1121,  1121,   556,   556,    46,  1087,  1121,  1121,  1121,  1121,
    1121,  1121,  1121,  -610,  -610,  2208,  2208,  2208,  2208,  2208,
    2208,  2208,  2208,  2208,  2208,  2208,  2208,   -77,  2208,  2208,
     617,  -610,  -610,  -610,   -21,  2208,  3252,  3252,  -610,  -610,
     470,   -20,  -610,   472,   478,  -610,   495,  -610,   498,   279,
    -610,  -610,   497,  -610,   498,   279,  -610,  -610,   107,   107,
    -610,  2208,   379,    62,  1411,   342,    27,  -610,  1121,   477,
     500,   510,  2208,   620,   299,   107,   107,   107,   107,   107,
     509,   498,  -610,  -610,   520,   521,  3042,  1121,  2208,  2208,
      63,   202,  3252,  3042,   312,  -610,  -610,   513,  -610,   603,
    3252,   620,  3042,   522,   523,   524,   525,   528,   529,   312,
     778,  2816,  2897,  2208,  2208,   530,   531,   533,   534,   514,
     136,  -610,   537,   539,  1217,  1237,  -610,  1254,  1362,  1398,
    1461,  1553,  2909,  2922,   -27,    70,   243,    75,    76,    10,
     540,   541,   544,   545,  1583,  1640,  1981,  1995,  2323,   185,
    2335,   376,   593,  2347,   112,   120,   143,   144,  2359,   180,
     245,   113,   246,   147,   250,   181,   182,   197,   261,   265,
    -610,  -610,   312,   312,   312,   312,   312,   312,  -610,  2208,
    2208,    31,   511,   474,   170,   159,   164,  -610,    23,    23,
     556,   556,   556,    62,  3042,   186,  -610,   201,  -610,  -610,
    3042,    36,    37,   551,   552,  -610,  -610,  -610,   -10,   527,
     552,   299,   299,   379,   379,  2372,  1121,  -610,  2208,  -610,
    2208,   379,   312,   299,  -610,   655,   620,   674,   620,    62,
    3042,   620,  -610,    17,  -610,   379,   379,   379,   379,   379,
    2208,  2208,  2208,   274,  2934,  3042,  -610,  -610,   553,   482,
    3252,  -610,  3156,   554,   555,  2208,  2208,   557,   559,  2208,
    2208,  2208,   268,   273,   158,   179,  -610,  -610,   484,  2208,
    2208,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  2208,  2208,
    2208,  2208,  2208,  -610,  -610,  1121,  -610,  1121,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  2208,  -610,  -610,  2208,
    -610,  1121,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
     468,  1121,  -610,   468,  1121,  -610,  1121,  -610,  -610,  -610,
    1121,  1121,  1806,  1701,  2208,  -610,  -610,  2208,  3252,  -610,
    2208,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,   312,    62,  1609,   299,  2384,   299,  -610,   498,
     279,  -610,  -610,    69,    69,   673,  -610,  -610,  -610,   690,
       3,  -610,    -2,  -610,  2467,  2479,   838,  1121,  1121,   489,
    -610,   202,  -610,  -610,  -610,  -610,  2208,   276,   280,  -610,
    -610,  2491,  2503,  2516,  -610,  -610,   561,   562,  2528,  2611,
    2623,  2635,  2647,  2660,   980,   200,   -82,  2672,  2755,   -56,
     281,   212,   285,   220,   229,    43,    49,  -610,  1943,   152,
    3042,  -610,  1121,  -610,  -610,  -610,  -610,   429,   620,   299,
     431,   437,  -610,  -610,  -610,    48,   673,   633,   640,  2208,
     641,   312,   312,   531,   286,  -610,   569,   136,  -610,  -610,
     659,   303,  -610,  -610,  -610,  -610,  -610,   554,   555,  -610,
    -610,  -610,  -610,  -610,  -610,  2208,  -610,  -610,  1121,  -610,
    -610,  -610,  1121,  -610,  1121,  -610,  -610,  1121,  -610,  -610,
    -610,  2208,  -610,  2208,  -610,  2208,  -610,  -610,  -610,  -610,
     312,   299,  -610,   620,   673,   498,   279,  -610,  -610,  -610,
    -610,   700,   636,  -610,  1121,  1121,  2767,  1121,   489,  -610,
     512,  2208,   663,  -610,  2779,   231,   237,   238,   242,  2791,
    2804,  3020,  -610,  -610,   673,  2208,  -610,  -610,   312,   312,
     648,   312,  -610,   527,   562,  2958,  3252,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  2208,  -610,  -610,  -610,  -610,
    1121,  -610,  -610,   202,    16,  3042,  3252,  3252,   312,  3252,
    3252,  -610,  -610,  -610,   202,   202,   202,   202,   115,    45,
     659,  -610,  -610,   107,  -610,  -610,  -610,  -610,  -610,  -610,
     379
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  parser::yydefact_[] =
  {
         8,   361,   371,    21,    22,   225,    38,   226,     0,     0,
       0,     0,     0,     0,    50,    52,    43,   257,   289,   296,
     283,   313,     0,     0,    27,    29,     0,     0,   340,    34,
       0,   360,   268,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,     9,    10,
      11,    25,     0,    26,     0,   227,    23,    17,    20,    16,
      19,    18,    14,    15,     0,    24,     0,   215,   216,     0,
     218,   219,   363,   373,   159,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    96,    39,   148,   141,    97,   158,
     215,    95,   218,     0,    60,     0,     0,     0,    61,    63,
     361,    56,    57,    58,     0,     0,     0,    44,     0,   290,
     297,   284,   361,   371,    12,    13,     0,   217,   220,   209,
       0,    41,     0,   209,     0,     0,    55,   347,    54,   345,
       0,   324,   331,    36,     0,   269,    65,    67,    77,     0,
       0,     0,     0,    68,    83,     0,     0,     0,     0,   206,
       0,    47,     0,     0,     0,     1,     2,     8,     6,     0,
       0,     0,   306,     0,     0,     0,     0,     0,   367,   378,
       0,     0,   128,     0,   203,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   151,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   344,    51,    53,     0,     0,     8,     8,   363,   373,
       0,     0,   211,     0,     0,   212,    28,   238,   240,   242,
     241,   243,    30,   244,   246,   248,   247,   249,     0,     0,
     342,     0,   341,   327,   325,    31,     0,    35,     0,   331,
     349,   351,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,     0,     0,   205,     0,     0,     0,
       0,     4,     8,    86,    92,   371,   228,   236,   237,     0,
       0,     0,    85,   362,   372,   365,   375,   369,   380,    87,
       0,     0,     0,     0,     0,   361,     0,     0,     0,     0,
     160,   161,     0,     0,     0,     0,   179,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   157,   143,   145,   147,   144,   146,   142,    99,     0,
       0,   130,   132,   134,   131,   133,   129,   150,   155,   156,
     153,   154,   149,   223,   224,     0,   221,     0,   362,   258,
     291,     0,     0,   362,   372,   207,   208,   210,   209,   209,
       0,     0,     0,   348,   346,     0,     0,    32,    33,   335,
       0,   333,   339,     0,    37,     0,     0,     0,     0,   275,
     274,     0,   272,     0,    78,    79,    81,    80,    82,    84,
       0,     0,     0,    45,    48,    59,    42,     7,     0,     0,
       8,   307,     0,   366,   376,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,     0,     0,
       0,   176,   177,   178,   173,   174,   172,   175,     0,     0,
       0,     0,     0,   109,   110,     0,   197,     0,   135,   201,
     202,   162,   163,   164,   165,   166,     0,   167,   169,     0,
     170,     0,   105,   108,   183,   184,   182,   189,   120,   121,
       0,     0,   115,     0,     0,   117,     0,   113,   111,   112,
       0,     0,   127,   125,     0,    62,    64,     0,     8,   299,
       0,   298,   286,   287,   285,   366,   376,   213,   214,   239,
     245,   343,   326,   330,   328,     0,     0,     0,   332,   320,
     322,   321,   323,   360,   360,   276,    74,    76,   273,     0,
       0,    69,     0,    72,     0,     0,     0,     0,     0,   250,
     372,   303,   308,   310,   370,   381,     0,     0,     0,   368,
     379,     0,     0,     0,   204,   123,   362,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,     0,     0,
     300,   288,     0,   336,   337,   334,   355,   360,     0,     0,
     360,   279,    75,    66,    70,     0,    71,     0,     0,     0,
       0,    46,    49,   371,     0,   251,   253,   255,   254,   256,
     316,     0,   364,   374,   190,   191,   192,     0,     0,   139,
     140,   180,   181,   101,   102,     0,   104,   198,     0,   199,
     168,   171,     0,   106,     0,   194,   114,     0,   196,   116,
     136,     0,   185,     0,   187,     0,   293,   294,   292,   301,
     329,     0,   350,     0,   353,   356,   358,   357,   359,   352,
     277,     0,     0,    73,     0,     0,     0,     0,     0,   229,
       0,     0,   314,   377,     0,     0,     0,     0,     0,     0,
       0,   266,   295,   338,   354,     0,   280,   270,    90,    91,
       0,    89,   252,   209,   372,     0,     8,   304,   103,   200,
     107,   193,   195,   186,   188,     0,   259,   278,   281,   271,
       0,   230,   317,   315,     0,   267,     8,     8,    88,     8,
       8,   311,   312,   305,   260,   282,   231,   318,     0,     0,
     316,   262,   263,   264,   234,   235,   233,   232,   319,   261,
     265
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -610,  -610,  -610,  -188,  -610,   351,  -369,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,    84,  -610,    20,
    -610,   372,  -610,   697,   698,  -135,   817,  -610,  -610,  1498,
    -610,  -610,   494,  -225,  -610,  -610,   -24,  -610,  -170,  -610,
      28,  -610,    47,  -610,  -295,   133,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,   248,  -610,   254,  -610,
     -38,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -357,   -50,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,  -610,
    -610,  -610,  -610,  -610,  -610,  -610,  -610,   -89,  -610,  -610,
    -579,  -610,   404,  -610,  -610,  -610,  -610,  -610,  -610,   589,
    -610,  -610,  -538,  -610,  -610,   118,  -609,   715,     0,   190,
     927,   491,   543,  -610,  -217
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    44,    45,    46,   362,    47,    48,   174,   175,   182,
     339,   154,   155,   298,   299,   343,   630,   631,   632,   633,
     187,   188,   193,    49,    50,   350,   156,   134,   384,   199,
     450,   449,   387,   388,   136,   383,   200,   477,   312,   171,
     137,    52,   138,    54,   465,   466,    55,    56,   211,   518,
     793,   819,   829,   837,   366,   316,   317,   322,   323,   704,
     705,    57,   158,   597,   816,   828,   833,   839,   806,    58,
     185,   342,   809,   503,   501,   691,   785,   762,   808,   817,
      59,   161,   307,   604,   681,    60,   159,   305,   598,   748,
     782,    61,   160,   306,   601,   749,    62,   369,   710,   814,
      63,   370,   642,   371,   823,    64,   797,   772,   820,   830,
     618,   335,   337,   338,   617,   615,   751,   493,   181,   302,
     178,   176,    65,   496,   498,   687,   688,   689,   139,   140,
      68,   141,   142,   646,    71
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -362;
  const short int
  parser::yytable_[] =
  {
        66,   521,   393,   315,   467,   502,   626,   627,   145,   391,
     391,   151,   152,   153,   522,   345,   201,   202,   203,   361,
     626,   627,   166,   172,   628,   346,   177,   179,    51,   330,
     489,   150,   150,   186,   189,   194,   683,   213,   685,   311,
    -217,   213,   469,   208,   208,  -309,   821,    53,   282,   162,
     163,   626,   627,   282,   283,   284,   728,   834,   729,   475,
     835,   354,   355,   440,   822,   476,   599,   602,   276,   277,
     278,   279,   280,   281,   282,   836,   628,   600,   753,   693,
     603,   753,   732,  -302,   733,   686,   686,   291,   532,   533,
     286,   287,   288,   289,   290,   291,   285,   286,   287,   288,
     289,   290,   291,   282,   276,   277,   278,   279,   280,   281,
     214,   550,   150,   215,   310,   300,   169,   170,   471,   472,
     276,   277,   278,   279,   280,   281,  -361,   310,   431,   308,
     433,    72,   629,    36,    37,    38,   695,   215,    31,   623,
     282,   624,   205,   145,   625,   831,   629,    73,   555,   686,
     556,   832,   686,   643,   294,   295,   296,   148,   304,   208,
     292,   293,   294,   295,   296,   331,   490,   292,   293,   294,
     295,   296,   783,   282,   318,   324,   282,   629,   149,   282,
     332,   741,   746,   742,   340,   183,   440,   743,   209,   744,
      67,   747,   282,   282,   180,   351,   351,   351,   146,   195,
     282,   283,   284,   516,   145,   282,   282,    66,   551,   208,
     145,   367,   167,   146,   210,   553,   554,   145,   410,   411,
     412,   413,   290,   291,   190,   196,   389,   389,   291,   197,
     647,   648,   289,   290,   291,    51,   204,   145,   145,   145,
     145,   145,   282,   285,   286,   287,   288,   289,   290,   291,
     282,   581,   574,   582,    53,   217,   145,   145,   145,   145,
     575,   145,   145,   351,   145,   351,   145,   145,   145,   145,
     145,   145,   216,   282,   282,   696,   145,   145,   145,   145,
     145,   145,   145,   576,   577,   584,  -220,   585,   292,   293,
     294,   295,   296,   292,   293,   294,   295,   296,   218,   292,
     293,   294,   295,   296,   162,   163,    66,    66,   607,   608,
     282,   282,   282,   172,   292,   293,   294,   295,   296,   219,
     579,   587,   588,   566,   594,   567,   595,   282,   483,   484,
     282,   754,   641,   146,    51,    51,   491,   589,   145,   594,
     727,   596,   282,   220,   189,   505,   506,   507,   508,   509,
     282,   711,   736,    53,    53,   670,   221,   145,   672,   282,
     739,   282,    66,   391,   319,   325,   391,   282,   282,   740,
      66,   799,   282,   282,   341,   282,   282,   800,   801,   223,
     282,   552,   802,   580,   583,   146,   146,   146,   586,   214,
      51,   282,   283,   284,   146,   282,   784,    67,    51,   590,
     146,   206,   207,   591,   282,   224,   594,   146,   654,    53,
     679,   594,   637,   655,   594,   215,   712,    53,   594,   734,
     713,   735,   709,   737,   768,   738,   769,   146,   146,   146,
     146,   146,   150,   365,   285,   286,   287,   288,   289,   290,
     291,   594,   282,   773,   373,   374,   146,   146,   146,   146,
     225,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   375,   376,   377,   378,   146,   146,   146,   146,
     146,   146,   146,   385,   386,   473,   474,   478,   170,   487,
     488,   318,   324,   473,   480,   226,   145,   468,   640,   656,
     657,    69,   227,   619,   385,   703,    67,    67,    31,   752,
      31,   759,   228,   146,   229,   292,   293,   294,   295,   296,
     760,   761,   230,    69,   569,   300,   570,   656,   794,   231,
      66,   232,    66,   233,   234,   191,   235,   236,   146,   237,
     238,   239,   240,   286,   190,   288,   289,   290,   291,   241,
     242,   243,   244,    70,   245,   246,   247,   146,    51,   248,
      51,   709,    67,   249,   250,   145,   251,   145,   252,   253,
      67,   254,   255,   256,   257,   168,   173,    53,   301,    53,
     313,   145,   288,   289,   290,   291,   311,   192,   314,   258,
     389,   145,   259,   389,   145,   260,   145,   261,   262,   263,
     145,   145,   264,   265,   266,   267,   162,   268,    66,   269,
     270,   271,   308,   292,   293,   294,   295,   296,   813,   283,
     284,   347,   309,   328,   329,   619,   348,   619,   336,   344,
     291,   349,   468,   811,   357,   358,    51,   502,   824,   825,
     359,   826,   827,   481,   310,   482,   495,   145,   145,   706,
     292,   293,   294,   295,   296,    53,   497,   510,   520,   519,
     538,   285,   286,   287,   288,   289,   290,   291,   511,   512,
     473,   523,   524,   525,   526,   320,   326,   527,   528,   534,
     535,   319,   325,   536,   537,   539,   146,   540,   557,   375,
     628,   558,   145,   620,   559,   560,   352,   352,   352,   755,
     605,   606,   639,   692,   644,   645,   764,   649,    69,   650,
     717,   718,   368,   765,   767,   770,   771,   786,   787,   796,
      67,   810,    67,   517,   694,   763,   504,   321,   327,   164,
     165,   392,   292,   293,   294,   295,   296,   677,   145,   609,
     792,   571,   145,   572,   145,   807,   610,   145,   353,   353,
     353,   838,   690,   494,   303,   146,   184,   146,     0,     0,
      70,   619,     0,     0,   352,     0,   352,     0,     0,     0,
       0,   146,     0,     0,   145,   145,     0,   145,   706,     0,
       0,   146,     0,     0,   146,     0,   146,     0,     0,     0,
     146,   146,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,     0,   283,   284,    66,    69,    69,     0,
       0,     0,     0,     0,     0,   620,   353,   620,   353,     0,
     145,     0,     0,     0,     0,     0,    66,    66,     0,    66,
      66,     0,     0,   133,    51,   144,     0,   146,   146,     0,
       0,     0,     0,   840,     0,   191,   285,   286,   287,   288,
     289,   290,   291,    53,    51,    51,     0,    51,    51,    70,
      70,     0,     0,    69,   283,   284,   479,     0,     0,     0,
       0,    69,     0,    53,    53,     0,    53,    53,     0,     0,
       0,     0,   146,     0,     0,     0,     0,     0,     0,   756,
       0,     0,     0,     0,     0,     0,     0,   192,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,    70,     0,   292,   293,   294,
     295,   296,     0,    70,     0,     0,   529,     0,   146,     0,
       0,     0,   146,     0,   146,     0,     0,   146,     0,     0,
       0,     0,     0,     0,     0,   147,     0,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,   274,
       0,     0,     0,     0,   146,   146,     0,   146,     0,     0,
     297,     0,     0,     0,     0,     0,     0,   292,   293,   294,
     295,   296,   320,   326,     0,     0,   699,     0,   700,     0,
       0,     0,     0,     0,   621,     0,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   284,   333,     0,
     146,     0,     0,     0,     0,     0,    67,    67,     0,    67,
      67,    69,     0,    69,     0,     0,     0,     0,     0,     0,
       0,   360,     0,     0,   321,   327,     0,   364,     0,     0,
       0,     0,     0,     0,   379,     0,   622,     0,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   405,   406,   407,   408,   409,
       0,     0,     0,    70,     0,    70,     0,     0,     0,     0,
     147,     0,     0,   424,   425,   426,   427,     0,   429,   430,
       0,   432,     0,   434,   435,   436,   437,   438,   439,    69,
       0,     0,     0,   442,   443,   444,   445,   446,   447,   448,
       0,     0,     0,   283,   284,     0,   621,     0,   621,   292,
     293,   294,   295,   296,     0,   463,   463,     0,   725,     0,
     726,     0,     0,     0,     0,    75,     1,     2,     0,     0,
     708,   147,     0,     0,     0,     0,     0,   147,     0,     0,
       0,    70,     0,    81,   147,   285,   286,   287,   288,   289,
     290,   291,     0,   390,   390,   492,     0,     0,   622,   499,
     622,     0,     0,     0,   147,   147,   147,   147,   147,     0,
       0,     0,     0,     0,   513,     0,     0,     0,     0,     0,
     757,     0,     0,   147,   147,   147,   147,     0,   147,   147,
       0,   147,     0,   147,   147,   147,   147,   147,   147,     0,
     463,   463,     0,   147,   147,   147,   147,   147,   147,   147,
      93,    94,    95,    96,    97,     0,   292,   293,   294,   295,
     296,     0,     0,     0,     0,     0,     0,   441,     0,     0,
     110,   111,   758,   283,   284,     0,   116,   117,   118,   119,
       0,   121,   621,   123,     0,   125,   126,   127,     0,     0,
       0,     0,     0,   283,   284,     0,     0,     0,     0,   708,
     143,     0,     0,     0,     0,   147,     0,     0,     0,     0,
     283,   284,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,   147,     0,     0,    69,     0,     0,
       0,     0,     0,     0,   622,   285,   286,   287,   288,   289,
     290,   291,     0,   612,     0,   613,     0,    69,    69,     0,
      69,    69,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,   463,   463,     0,     0,   292,   293,   294,   295,
     296,     0,     0,     0,     0,     0,     0,   541,     0,    70,
      70,     0,    70,    70,     0,     0,   292,   293,   294,   295,
     296,     0,   665,     0,   666,     0,     0,   542,   283,   284,
       0,     0,     0,   292,   293,   294,   295,   296,   669,     0,
       0,     0,     0,     0,   543,     0,     0,     0,   671,     0,
       0,   673,     0,   674,     0,     0,     0,   675,   676,     0,
       0,   463,     0,   147,   283,   284,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,   283,   284,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   701,   702,   285,   286,   287,   288,
     289,   290,   291,   463,     0,     0,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,   283,   284,   486,
       0,     0,   147,     0,   147,     0,     0,     0,     0,     0,
       0,   292,   293,   294,   295,   296,     0,     0,   147,   750,
       0,     0,   544,     0,   135,     0,     0,   147,   147,     0,
     147,   147,     0,   147,   157,     0,     0,   147,   147,   285,
     286,   287,   288,   289,   290,   291,     0,   292,   293,   294,
     295,   296,     0,     0,     0,     0,     0,     0,   545,     0,
     292,   293,   294,   295,   296,   775,     0,     0,     0,   776,
       0,   777,     0,     0,   778,     0,     0,     0,     0,     0,
       0,     0,   212,     0,   147,   147,   707,     0,     0,   283,
     284,     0,     0,     0,     0,     0,   222,     0,     0,     0,
       0,   788,   789,     0,   791,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,     0,     0,     0,     0,   283,
     284,   546,   499,     0,     0,     0,     0,     0,     0,   147,
       0,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,     0,   283,   284,   818,   272,   273,
     275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,     0,   147,   283,   284,     0,   147,
       0,   147,     0,     0,   147,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,   682,     0,   334,
       0,     0,   292,   293,   294,   295,   296,     0,     0,     0,
       0,   147,   147,   547,   147,   707,   356,     0,   285,   286,
     287,   288,   289,   290,   291,     0,     0,   363,     0,     0,
       0,   372,   292,   293,   294,   295,   296,   283,   380,   381,
       0,   382,     0,   561,     0,     0,   394,   395,   397,   398,
     399,   400,   401,   402,   403,     0,     0,   147,   292,   293,
     294,   295,   296,     0,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   428,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,   292,
     293,   294,   295,   296,     0,     0,     0,     0,     0,     0,
     562,     0,     0,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,     0,   464,   464,     0,     0,
       0,     0,     0,   470,     0,     0,     0,    74,    75,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    78,    79,     0,    80,    81,     0,     0,   485,
     292,   293,   294,   295,   296,     0,     0,     0,     0,     0,
     500,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   514,   515,    82,    83,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   464,   464,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,     0,   100,   101,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   292,   293,   294,   295,   296,
       0,     0,     0,   132,     0,   198,     0,   592,   593,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   283,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   745,     0,
       0,     0,     0,     0,     0,     0,   614,     0,   616,     0,
       0,     0,     0,     0,     0,     0,     0,   283,   284,     0,
       0,   285,   286,   287,   288,   289,   290,   291,   634,   635,
     636,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   464,   464,     0,     0,   651,   652,   653,
       0,     0,     0,     0,     0,     0,     0,   658,   659,   285,
     286,   287,   288,   289,   290,   291,   660,   661,   662,   663,
     664,     0,     0,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,   667,     0,     0,   668,    74,    75,
       1,     2,   292,   293,   294,   295,   296,     0,     0,     0,
       0,    76,    77,    78,    79,     0,    80,    81,     0,     0,
       0,     0,   464,     0,     0,   678,     0,     0,   680,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,     0,     0,     0,     0,    82,
      83,   563,     0,     0,   292,   293,   294,   295,   296,     0,
       0,     0,     0,     0,     0,   564,     0,     0,     0,     0,
       0,     0,     0,     0,   464,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,    99,     0,   100,   101,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,     0,   766,     0,     0,
       0,     0,     0,     0,   132,   396,     0,     0,     0,     0,
       0,    74,    75,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     0,   774,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,   779,
       0,   780,     0,   781,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    83,     0,     0,     0,     0,     0,   795,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   500,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   815,    99,     0,   100,   101,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   283,
     284,     0,     0,     0,     0,     0,     0,   132,     0,     0,
       0,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   283,   284,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,   283,   284,
       0,     0,     0,   285,   286,   287,   288,   289,   290,   291,
     283,   284,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,   292,   293,   294,   295,   296,     0,     0,     0,
       0,     0,     0,   565,   292,   293,   294,   295,   296,     0,
       0,     0,     0,     0,     0,   568,   292,   293,   294,   295,
     296,     0,     0,   283,   284,     0,     0,   573,   292,   293,
     294,   295,   296,     0,     0,   283,   284,     0,     0,   578,
       0,   292,   293,   294,   295,   296,     0,   283,   284,     0,
       0,     0,   611,   292,   293,   294,   295,   296,     0,   283,
     284,     0,     0,     0,   684,   285,   286,   287,   288,   289,
     290,   291,   283,   284,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,   283,   284,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,   292,   293,   294,   295,
     296,     0,     0,     0,     0,     0,     0,   697,   292,   293,
     294,   295,   296,     0,     0,     0,     0,     0,     0,   698,
     292,   293,   294,   295,   296,     0,     0,   283,   284,     0,
       0,   714,   292,   293,   294,   295,   296,     0,     0,   283,
     284,     0,     0,   715,     0,   292,   293,   294,   295,   296,
       0,   283,   284,     0,     0,     0,   716,   292,   293,   294,
     295,   296,     0,   283,   284,     0,     0,     0,   719,   285,
     286,   287,   288,   289,   290,   291,   283,   284,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,   283,   284,
       0,     0,     0,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
     292,   293,   294,   295,   296,     0,     0,     0,     0,     0,
       0,   720,   292,   293,   294,   295,   296,     0,     0,     0,
       0,     0,     0,   721,   292,   293,   294,   295,   296,     0,
       0,   283,   284,     0,     0,   722,   292,   293,   294,   295,
     296,     0,     0,   283,   284,     0,     0,   723,     0,   292,
     293,   294,   295,   296,     0,   283,   284,     0,     0,     0,
     724,   292,   293,   294,   295,   296,     0,   283,   284,     0,
       0,     0,   730,   285,   286,   287,   288,   289,   290,   291,
     283,   284,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,   283,   284,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,   292,   293,   294,   295,   296,     0,
       0,     0,     0,     0,     0,   731,   292,   293,   294,   295,
     296,     0,     0,     0,     0,     0,     0,   790,   292,   293,
     294,   295,   296,   283,   284,     0,     0,     0,     0,   798,
     292,   293,   294,   295,   296,   283,   284,     0,     0,     0,
       0,   803,     0,   292,   293,   294,   295,   296,   283,   284,
       0,     0,     0,     0,   804,   292,   293,   294,   295,   296,
     283,   284,     0,     0,   530,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,   283,   284,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,   812,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,   292,   293,   294,   295,
     296,     0,     0,     0,     0,   531,   283,   284,   292,   293,
     294,   295,   296,     0,     0,     0,     0,   548,     0,     0,
       0,   292,   293,   294,   295,   296,     0,   805,   283,   284,
     549,     0,     0,   292,   293,   294,   295,   296,     0,     0,
       0,     0,   638,     0,     0,     0,     0,     0,   285,   286,
     287,   288,   289,   290,   291,     0,     0,   292,   293,   294,
     295,   296,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
     293,   294,   295,   296,     0,     0,     0,     0,     0,     0,
       0,     1,     2,   628,     0,     3,     4,     5,     0,     6,
       7,   292,   293,   294,   295,   296,     8,     9,    10,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,     0,
      17,     0,     0,     0,    18,     0,    19,     0,    20,     0,
      21,     0,     0,     0,     0,     0,    22,    23,    24,    25,
       0,     0,    26,    27,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,     0,    31,     0,    32,     0,     0,
       0,    33,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,    40,     0,    41,     0,     0,    42,     1,     2,     0,
       0,     3,     4,     5,     0,     6,     7,     0,     0,     0,
      43,     0,     8,     9,    10,     0,     0,    11,    12,    13,
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
         0,   370,   227,   173,   299,     7,     3,     4,     8,   226,
     227,    11,    12,    13,   371,    24,    40,    41,    42,   207,
       3,     4,    22,    23,     7,    24,    26,    27,     0,     3,
       3,     5,     5,    33,    34,    35,   615,    63,   617,    49,
      63,    63,    63,     7,     7,     7,    30,     0,   130,     5,
       6,     3,     4,   130,    16,    17,   138,    12,   140,    79,
      15,   196,   197,   140,    48,    85,    30,    30,    58,    59,
      60,    61,    62,    63,   130,    30,     7,    41,   687,    76,
      43,   690,   138,    45,   140,   623,   624,    64,   383,   384,
      59,    60,    61,    62,    63,    64,    58,    59,    60,    61,
      62,    63,    64,   130,    58,    59,    60,    61,    62,    63,
     136,   138,     5,   136,   136,   136,     5,     6,   306,   307,
      58,    59,    60,    61,    62,    63,   136,   136,   263,   139,
     265,   139,   129,    89,    90,    91,   138,   136,    69,   496,
     130,   498,     0,   143,   501,    30,   129,   139,   138,   687,
     140,    36,   690,   522,   131,   132,   133,   139,   158,     7,
     129,   130,   131,   132,   133,   139,   139,   129,   130,   131,
     132,   133,   751,   130,   174,   175,   130,   129,   139,   130,
     180,   138,    30,   140,   184,    66,   140,   138,    63,   140,
       0,    39,   130,   130,   141,   195,   196,   197,     8,   139,
     130,    16,    17,   140,   204,   130,   130,   207,   138,     7,
     210,   211,    22,    23,    63,   140,   140,   217,   242,   243,
     244,   245,    63,    64,    34,   139,   226,   227,    64,   139,
     525,   526,    62,    63,    64,   207,   139,   237,   238,   239,
     240,   241,   130,    58,    59,    60,    61,    62,    63,    64,
     130,   138,   140,   140,   207,    63,   256,   257,   258,   259,
     140,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   136,   130,   130,   632,   276,   277,   278,   279,
     280,   281,   282,   140,   140,   138,    63,   140,   129,   130,
     131,   132,   133,   129,   130,   131,   132,   133,   140,   129,
     130,   131,   132,   133,     5,     6,   306,   307,   478,   479,
     130,   130,   130,   313,   129,   130,   131,   132,   133,   140,
     140,   140,   140,   138,   138,   140,   140,   130,   328,   329,
     130,   688,   520,   143,   306,   307,   336,   140,   338,   138,
     140,   140,   130,   139,   344,   345,   346,   347,   348,   349,
     130,   646,   140,   306,   307,   580,   139,   357,   583,   130,
     140,   130,   362,   580,   174,   175,   583,   130,   130,   140,
     370,   140,   130,   130,   184,   130,   130,   140,   140,   139,
     130,   138,   140,   138,   138,   195,   196,   197,   138,   136,
     362,   130,    16,    17,   204,   130,   753,   207,   370,   138,
     210,    30,    31,   138,   130,   139,   138,   217,   140,   362,
     598,   138,   138,   140,   138,   136,   140,   370,   138,   138,
     140,   140,   639,   138,   138,   140,   140,   237,   238,   239,
     240,   241,     5,     6,    58,    59,    60,    61,    62,    63,
      64,   138,   130,   140,     5,     6,   256,   257,   258,   259,
     139,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,     5,     6,     5,     6,   276,   277,   278,   279,
     280,   281,   282,     5,     6,     5,     6,     5,     6,   137,
     138,   481,   482,     5,     6,   139,   486,     5,     6,     5,
       6,     0,   139,   493,     5,     6,   306,   307,    69,    70,
      69,    70,   139,   313,   139,   129,   130,   131,   132,   133,
      73,    74,   139,    22,   138,   136,   140,     5,     6,   139,
     520,   139,   522,   139,   139,    34,   139,   139,   338,   139,
     139,   139,   139,    59,   344,    61,    62,    63,    64,   139,
     139,   139,   139,     0,   139,   139,   139,   357,   520,   139,
     522,   768,   362,   139,   139,   555,   139,   557,   139,   139,
     370,   139,   139,   139,   139,    22,    23,   520,    33,   522,
     138,   571,    61,    62,    63,    64,    49,    34,   136,   139,
     580,   581,   139,   583,   584,   139,   586,   139,   139,   139,
     590,   591,   139,   139,   139,   139,     5,   139,   598,   139,
     139,   139,   139,   129,   130,   131,   132,   133,   796,    16,
      17,    24,   139,   138,   138,   615,    24,   617,   141,   138,
      64,   138,     5,   793,   138,   138,   598,     7,   816,   817,
     138,   819,   820,   138,   136,   138,   136,   637,   638,   639,
     129,   130,   131,   132,   133,   598,   136,   138,    45,   136,
     136,    58,    59,    60,    61,    62,    63,    64,   138,   138,
       5,   139,   139,   139,   139,   174,   175,   139,   139,   139,
     139,   481,   482,   140,   140,   138,   486,   138,   138,     5,
       7,   140,   682,   493,   140,   140,   195,   196,   197,   689,
     139,   139,   139,     3,   140,   140,    63,   140,   207,   140,
     139,   139,   211,    63,    63,   136,    47,     7,    72,    46,
     520,    63,   522,   362,   630,   695,   344,   174,   175,    22,
      22,   227,   129,   130,   131,   132,   133,   594,   728,   481,
     768,   138,   732,   140,   734,   785,   482,   737,   195,   196,
     197,   830,   624,   339,   155,   555,    31,   557,    -1,    -1,
     207,   751,    -1,    -1,   263,    -1,   265,    -1,    -1,    -1,
      -1,   571,    -1,    -1,   764,   765,    -1,   767,   768,    -1,
      -1,   581,    -1,    -1,   584,    -1,   586,    -1,    -1,    -1,
     590,   591,    -1,    -1,    -1,    -1,    -1,    -1,   598,    -1,
      -1,    -1,    -1,    -1,    16,    17,   796,   306,   307,    -1,
      -1,    -1,    -1,    -1,    -1,   615,   263,   617,   265,    -1,
     810,    -1,    -1,    -1,    -1,    -1,   816,   817,    -1,   819,
     820,    -1,    -1,     6,   796,     8,    -1,   637,   638,    -1,
      -1,    -1,    -1,   833,    -1,   344,    58,    59,    60,    61,
      62,    63,    64,   796,   816,   817,    -1,   819,   820,   306,
     307,    -1,    -1,   362,    16,    17,   313,    -1,    -1,    -1,
      -1,   370,    -1,   816,   817,    -1,   819,   820,    -1,    -1,
      -1,    -1,   682,    -1,    -1,    -1,    -1,    -1,    -1,   689,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,   362,    -1,   129,   130,   131,
     132,   133,    -1,   370,    -1,    -1,   138,    -1,   728,    -1,
      -1,    -1,   732,    -1,   734,    -1,    -1,   737,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,   751,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,   764,   765,    -1,   767,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   481,   482,    -1,    -1,   138,    -1,   140,    -1,
      -1,    -1,    -1,    -1,   493,    -1,   796,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,   181,    -1,
     810,    -1,    -1,    -1,    -1,    -1,   816,   817,    -1,   819,
     820,   520,    -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,   481,   482,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,    -1,   493,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,   520,    -1,   522,    -1,    -1,    -1,    -1,
     143,    -1,    -1,   256,   257,   258,   259,    -1,   261,   262,
      -1,   264,    -1,   266,   267,   268,   269,   270,   271,   598,
      -1,    -1,    -1,   276,   277,   278,   279,   280,   281,   282,
      -1,    -1,    -1,    16,    17,    -1,   615,    -1,   617,   129,
     130,   131,   132,   133,    -1,   298,   299,    -1,   138,    -1,
     140,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
     639,   204,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   598,    -1,    22,   217,    58,    59,    60,    61,    62,
      63,    64,    -1,   226,   227,   338,    -1,    -1,   615,   342,
     617,    -1,    -1,    -1,   237,   238,   239,   240,   241,    -1,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,
     689,    -1,    -1,   256,   257,   258,   259,    -1,   261,   262,
      -1,   264,    -1,   266,   267,   268,   269,   270,   271,    -1,
     383,   384,    -1,   276,   277,   278,   279,   280,   281,   282,
      89,    90,    91,    92,    93,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
     109,   110,   689,    16,    17,    -1,   115,   116,   117,   118,
      -1,   120,   751,   122,    -1,   124,   125,   126,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,   768,
     139,    -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,   357,    -1,    -1,   796,    -1,    -1,
      -1,    -1,    -1,    -1,   751,    58,    59,    60,    61,    62,
      63,    64,    -1,   486,    -1,   488,    -1,   816,   817,    -1,
     819,   820,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   796,
      -1,    -1,   525,   526,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,   816,
     817,    -1,   819,   820,    -1,    -1,   129,   130,   131,   132,
     133,    -1,   555,    -1,   557,    -1,    -1,   140,    16,    17,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   571,    -1,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   581,    -1,
      -1,   584,    -1,   586,    -1,    -1,    -1,   590,   591,    -1,
      -1,   594,    -1,   486,    16,    17,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   637,   638,    58,    59,    60,    61,
      62,    63,    64,   646,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    16,    17,    68,
      -1,    -1,   555,    -1,   557,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    -1,   571,   682,
      -1,    -1,   140,    -1,     6,    -1,    -1,   580,   581,    -1,
     583,   584,    -1,   586,    16,    -1,    -1,   590,   591,    58,
      59,    60,    61,    62,    63,    64,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
     129,   130,   131,   132,   133,   728,    -1,    -1,    -1,   732,
      -1,   734,    -1,    -1,   737,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,   637,   638,   639,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,   764,   765,    -1,   767,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    16,
      17,   140,   785,    -1,    -1,    -1,    -1,    -1,    -1,   682,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,   810,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   728,    16,    17,    -1,   732,
      -1,   734,    -1,    -1,   737,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    68,    -1,   181,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,   764,   765,   140,   767,   768,   198,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,   209,    -1,    -1,
      -1,   213,   129,   130,   131,   132,   133,    16,   220,   221,
      -1,   223,    -1,   140,    -1,    -1,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,   810,   129,   130,
     131,   132,   133,    -1,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,    -1,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,    -1,   298,   299,    -1,    -1,
      -1,    -1,    -1,   305,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    -1,    21,    22,    -1,    -1,   331,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
     342,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   358,   359,    54,    55,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,   384,    -1,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    -1,    98,    99,    -1,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   129,   130,   131,   132,   133,
      -1,    -1,    -1,   139,    -1,   141,    -1,   449,   450,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   488,    -1,   490,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,   510,   511,
     512,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   525,   526,    -1,    -1,   529,   530,   531,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,   540,    58,
      59,    60,    61,    62,    63,    64,   548,   549,   550,   551,
     552,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,   566,    -1,    -1,   569,     3,     4,
       5,     6,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      -1,    -1,   594,    -1,    -1,   597,    -1,    -1,   600,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    54,
      55,   140,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   646,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    -1,    98,    99,    -1,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,   699,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   725,    16,    17,    18,    19,    -1,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   741,
      -1,   743,    -1,   745,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,   771,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   785,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,   805,    96,    -1,    98,    99,    -1,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    16,    17,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      16,    17,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   129,   130,   131,   132,
     133,    -1,    -1,    16,    17,    -1,    -1,   140,   129,   130,
     131,   132,   133,    -1,    -1,    16,    17,    -1,    -1,   140,
      -1,   129,   130,   131,   132,   133,    -1,    16,    17,    -1,
      -1,    -1,   140,   129,   130,   131,   132,   133,    -1,    16,
      17,    -1,    -1,    -1,   140,    58,    59,    60,    61,    62,
      63,    64,    16,    17,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    16,    17,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     129,   130,   131,   132,   133,    -1,    -1,    16,    17,    -1,
      -1,   140,   129,   130,   131,   132,   133,    -1,    -1,    16,
      17,    -1,    -1,   140,    -1,   129,   130,   131,   132,   133,
      -1,    16,    17,    -1,    -1,    -1,   140,   129,   130,   131,
     132,   133,    -1,    16,    17,    -1,    -1,    -1,   140,    58,
      59,    60,    61,    62,    63,    64,    16,    17,    -1,    -1,
      -1,    58,    59,    60,    61,    62,    63,    64,    16,    17,
      -1,    -1,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
     129,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,   140,   129,   130,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   129,   130,   131,   132,   133,    -1,
      -1,    16,    17,    -1,    -1,   140,   129,   130,   131,   132,
     133,    -1,    -1,    16,    17,    -1,    -1,   140,    -1,   129,
     130,   131,   132,   133,    -1,    16,    17,    -1,    -1,    -1,
     140,   129,   130,   131,   132,   133,    -1,    16,    17,    -1,
      -1,    -1,   140,    58,    59,    60,    61,    62,    63,    64,
      16,    17,    -1,    -1,    -1,    58,    59,    60,    61,    62,
      63,    64,    16,    17,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,   129,   130,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   129,   130,
     131,   132,   133,    16,    17,    -1,    -1,    -1,    -1,   140,
     129,   130,   131,   132,   133,    16,    17,    -1,    -1,    -1,
      -1,   140,    -1,   129,   130,   131,   132,   133,    16,    17,
      -1,    -1,    -1,    -1,   140,   129,   130,   131,   132,   133,
      16,    17,    -1,    -1,   138,    58,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,
      61,    62,    63,    64,    16,    17,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,   129,   130,   131,   132,
     133,    -1,    -1,    -1,    -1,   138,    16,    17,   129,   130,
     131,   132,   133,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,   129,   130,   131,   132,   133,    -1,    37,    16,    17,
     138,    -1,    -1,   129,   130,   131,   132,   133,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    58,    59,
      60,    61,    62,    63,    64,    -1,    -1,   129,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,     7,    -1,     9,    10,    11,    -1,    13,
      14,   129,   130,   131,   132,   133,    20,    21,    22,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    32,    -1,
      34,    -1,    -1,    -1,    38,    -1,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    -1,    69,    -1,    71,    -1,    -1,
      -1,    75,    -1,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,    -1,
      94,    95,    -1,    97,    -1,    -1,   100,     5,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    -1,    -1,    -1,
     114,    -1,    20,    21,    22,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    32,    -1,    34,    -1,    -1,    -1,
      38,    -1,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    -1,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    -1,    -1,    94,    95,    -1,    97,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   114
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  parser::yystos_[] =
  {
         0,     5,     6,     9,    10,    11,    13,    14,    20,    21,
      22,    25,    26,    27,    28,    29,    32,    34,    38,    40,
      42,    44,    50,    51,    52,    53,    56,    57,    65,    66,
      67,    69,    71,    75,    77,    78,    89,    90,    91,    94,
      95,    97,   100,   114,   143,   144,   145,   147,   148,   165,
     166,   182,   183,   184,   185,   188,   189,   203,   211,   222,
     227,   233,   238,   242,   247,   264,   270,   271,   272,   273,
     274,   276,   139,   139,     3,     4,    16,    17,    18,    19,
      21,    22,    54,    55,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    96,
      98,    99,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   139,   168,   169,   171,   176,   182,   184,   270,
     271,   273,   274,   139,   168,   270,   271,   272,   139,   139,
       5,   270,   270,   270,   153,   154,   168,   171,   204,   228,
     234,   223,     5,     6,   165,   166,   270,   271,   274,     5,
       6,   181,   270,   274,   149,   150,   263,   270,   262,   270,
     141,   260,   151,    66,   269,   212,   270,   162,   163,   270,
     271,   273,   274,   164,   270,   139,   139,   139,   141,   171,
     178,   178,   178,   178,   139,     0,    30,    31,     7,    63,
      63,   190,   171,    63,   136,   136,   136,    63,   140,   140,
     139,   139,   171,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   171,   171,   168,   171,    58,    59,    60,    61,
      62,    63,   130,    16,    17,    58,    59,    60,    61,    62,
      63,    64,   129,   130,   131,   132,   133,   168,   155,   156,
     136,    33,   261,   261,   270,   229,   235,   224,   139,   139,
     136,    49,   180,   138,   136,   180,   197,   198,   270,   271,
     273,   274,   199,   200,   270,   271,   273,   274,   138,   138,
       3,   139,   270,   168,   171,   253,   141,   254,   255,   152,
     270,   271,   213,   157,   138,    24,    24,    24,    24,   138,
     167,   270,   273,   274,   167,   167,   171,   138,   138,   138,
     168,   145,   146,   171,   168,     6,   196,   270,   273,   239,
     243,   245,   171,     5,     6,     5,     6,     5,     6,   168,
     171,   171,   171,   177,   170,     5,     6,   174,   175,   270,
     272,   276,   174,   175,   171,   171,   140,   171,   171,   171,
     171,   171,   171,   171,   168,   168,   168,   168,   168,   168,
     178,   178,   178,   178,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   168,   168,   168,   168,   171,   168,
     168,   167,   168,   167,   168,   168,   168,   168,   168,   168,
     140,   140,   168,   168,   168,   168,   168,   168,   168,   173,
     172,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   168,   171,   186,   187,   186,     5,    63,
     171,   145,   145,     5,     6,    79,    85,   179,     5,   274,
       6,   138,   138,   270,   270,   171,    68,   137,   138,     3,
     139,   270,   168,   259,   254,   136,   265,   136,   266,   168,
     171,   216,     7,   215,   163,   270,   270,   270,   270,   270,
     138,   138,   138,   168,   171,   171,   140,   147,   191,   136,
      45,   148,   215,   139,   139,   139,   139,   139,   139,   138,
     138,   138,   186,   186,   139,   139,   140,   140,   136,   138,
     138,   140,   140,   140,   140,   140,   140,   140,   138,   138,
     138,   138,   138,   140,   140,   138,   140,   138,   140,   140,
     140,   140,   140,   140,   140,   140,   138,   140,   140,   138,
     140,   138,   140,   140,   140,   140,   140,   140,   140,   140,
     138,   138,   140,   138,   138,   140,   138,   140,   140,   140,
     138,   138,   171,   171,   138,   140,   140,   205,   230,    30,
      41,   236,    30,    43,   225,   139,   139,   180,   180,   198,
     200,   140,   168,   168,   171,   257,   171,   256,   252,   270,
     271,   273,   274,   215,   215,   215,     3,     4,     7,   129,
     158,   159,   160,   161,   171,   171,   171,   138,   138,   139,
       6,   145,   244,   148,   140,   140,   275,   186,   186,   140,
     140,   171,   171,   171,   140,   140,     5,     6,   171,   171,
     171,   171,   171,   171,   171,   168,   168,   171,   171,   168,
     175,   168,   175,   168,   168,   168,   168,   187,   171,   145,
     171,   226,    68,   252,   140,   252,   264,   267,   268,   269,
     267,   217,     3,    76,   159,   138,   215,   140,   140,   138,
     140,   168,   168,     6,   201,   202,   270,   272,   273,   276,
     240,   186,   140,   140,   140,   140,   140,   139,   139,   140,
     140,   140,   140,   140,   140,   138,   140,   140,   138,   140,
     140,   140,   138,   140,   138,   140,   140,   138,   140,   140,
     140,   138,   140,   138,   140,    35,    30,    39,   231,   237,
     168,   258,    70,   268,   215,   270,   271,   273,   274,    70,
      73,    74,   219,   161,    63,    63,   171,    63,   138,   140,
     136,    47,   249,   140,   171,   168,   168,   168,   168,   171,
     171,   171,   232,   252,   215,   218,     7,    72,   168,   168,
     140,   168,   202,   192,     6,   171,    46,   248,   140,   140,
     140,   140,   140,   140,   140,    37,   210,   216,   220,   214,
      63,   180,    45,   145,   241,   171,   206,   221,   168,   193,
     250,    30,    48,   246,   145,   145,   145,   145,   207,   194,
     251,    30,    36,   208,    12,    15,    30,   195,   249,   209,
     270
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
         0,   142,   143,   144,   144,   145,   146,   145,   147,   147,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   149,   148,   150,
     148,   148,   148,   148,   151,   148,   152,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     153,   148,   154,   148,   148,   148,   148,   148,   148,   148,
     148,   155,   148,   156,   148,   157,   148,   148,   148,   158,
     158,   159,   160,   160,   161,   161,   161,   162,   162,   163,
     163,   163,   163,   164,   164,   165,   165,   166,   166,   166,
     166,   166,   166,   167,   167,   168,   168,   168,   168,   168,
     168,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   170,   169,   172,   171,   173,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     174,   175,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   176,   177,   176,   178,   178,   179,   179,   180,
     180,   181,   181,   181,   181,   182,   182,   183,   184,   184,
     185,   186,   186,   187,   187,   188,   188,   190,   191,   192,
     193,   194,   189,   195,   195,   195,   196,   196,   197,   197,
     198,   198,   198,   198,   199,   199,   200,   200,   200,   200,
     201,   201,   201,   202,   202,   202,   202,   204,   205,   206,
     207,   203,   208,   208,   209,   209,   210,   210,   212,   213,
     214,   211,   215,   215,   216,   216,   217,   218,   217,   219,
     220,   221,   219,   223,   224,   222,   225,   226,   225,   228,
     229,   230,   227,   231,   232,   231,   234,   235,   233,   236,
     237,   236,   239,   240,   241,   238,   243,   244,   242,   245,
     242,   246,   246,   247,   248,   248,   249,   250,   251,   249,
     252,   252,   252,   252,   253,   253,   253,   253,   253,   253,
     253,   255,   254,   256,   254,   257,   254,   258,   254,   259,
     260,   260,   260,   260,   261,   262,   262,   263,   263,   265,
     264,   266,   264,   267,   267,   268,   268,   268,   268,   268,
     269,   270,   270,   271,   271,   271,   271,   272,   272,   272,
     272,   273,   273,   274,   274,   274,   275,   274,   276,   276,
     276,   276
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     1,     3,     1,     0,     4,     0,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     0,
       3,     3,     4,     4,     0,     3,     0,     4,     1,     2,
       2,     2,     4,     1,     2,     4,     6,     2,     4,     6,
       0,     3,     0,     3,     2,     2,     2,     2,     2,     4,
       2,     0,     5,     0,     5,     0,     6,     2,     2,     1,
       2,     2,     1,     3,     1,     2,     1,     1,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,    10,     8,
       8,     8,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     6,     6,     8,     6,     4,     6,     8,     4,     4,
       4,     4,     4,     4,     6,     4,     6,     4,     1,     1,
       4,     4,     0,     5,     0,     4,     0,     4,     2,     3,
       3,     3,     3,     3,     3,     4,     6,     4,     4,     6,
       6,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     2,     2,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     3,
       6,     6,     4,     4,     4,     6,     8,     6,     8,     4,
       6,     6,     6,     8,     6,     8,     6,     4,     6,     6,
       8,     4,     4,     0,     5,     2,     1,     1,     1,     0,
       2,     2,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     0,     0,     0,
       0,     0,    13,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       0,     1,     3,     1,     1,     1,     1,     0,     0,     0,
       0,    14,     1,     1,     0,     1,     0,     2,     0,     0,
       0,     9,     1,     2,     1,     1,     0,     0,     4,     0,
       0,     0,     5,     0,     0,     5,     1,     0,     2,     0,
       0,     0,     7,     1,     0,     2,     0,     0,     5,     1,
       0,     3,     0,     0,     0,    10,     0,     0,     5,     0,
       5,     1,     1,     1,     0,     2,     0,     0,     0,     7,
       1,     1,     1,     1,     0,     1,     3,     1,     3,     5,
       3,     0,     3,     0,     4,     0,     4,     0,     6,     1,
       0,     2,     2,     4,     1,     1,     3,     1,     3,     0,
       7,     0,     7,     2,     3,     1,     2,     2,     2,     2,
       0,     1,     3,     2,     6,     3,     4,     3,     5,     3,
       5,     1,     3,     2,     6,     3,     0,     7,     3,     5,
       3,     5
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
  "$@9", "$@10", "data_list", "data_row", "data_row_items", "data_item",
  "read_list", "read_item", "restore_list", "number_assignment",
  "string_assignment", "string_scalar_or_array", "string_expression",
  "string_function", "$@11", "number_expression", "$@12", "$@13",
  "number_arrayref", "string_arrayref", "number_function", "$@14",
  "hashed_number", "exprtype", "dim_as_type", "dim_list",
  "number_function_or_array_any_params",
  "number_function_or_array_with_params",
  "string_function_or_array_any_params",
  "string_function_or_array_with_params", "call_list", "call_item",
  "begin_sub", "function_definition", "$@15", "$@16", "$@17", "@18", "@19",
  "endsub", "function_name", "local_list", "local_item", "static_list",
  "static_item", "param_list", "param_item", "for_loop", "$@20", "$@21",
  "$@22", "$@23", "next", "next_symbol", "step_part",
  "switch_number_or_string", "$@24", "$@25", "$@26", "separator_list",
  "number_or_string", "case_list", "$@27", "default", "$@28", "$@29",
  "do_loop", "$@30", "$@31", "loop", "$@32", "while_loop", "$@33", "$@34",
  "$@35", "wend", "$@36", "repeat_loop", "$@37", "$@38", "until", "$@39",
  "if_clause", "$@40", "$@41", "$@42", "short_if", "$@43", "$@44", "$@45",
  "endif", "if_part", "else_part", "elseif_part", "$@46", "$@47", "input",
  "print_list", "input_body", "$@48", "$@49", "$@50", "$@51", "prompt",
  "print_intro", "option", "dec_list", "inc_list", "structure_definition",
  "$@52", "$@53", "structure_definition_parts",
  "structure_definition_variable", "new_cli", "numsym_s", "numsym_a",
  "numsym_a_no_calls", "strsym_s", "strsym_a", "$@54", "strsym_a_no_calls", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
       143,     0,    -1,   144,    30,    -1,   145,    -1,   144,    31,
     145,    -1,   147,    -1,    -1,   145,     7,   146,   147,    -1,
      -1,   148,    -1,   165,    -1,   166,    -1,    50,   165,    -1,
      50,   166,    -1,   238,    -1,   242,    -1,   222,    -1,   203,
      -1,   233,    -1,   227,    -1,   211,    -1,     9,    -1,    10,
      -1,   189,    -1,   264,    -1,   182,    -1,   184,    -1,    -1,
      52,   149,   197,    -1,    -1,    53,   150,   199,    -1,    65,
     260,   253,    -1,    65,   260,   253,   137,    -1,    65,   260,
     253,   138,    -1,    -1,    66,   151,   254,    -1,    -1,    67,
      66,   152,   254,    -1,    13,    -1,    13,   171,    -1,    13,
     168,    -1,    51,   181,    -1,   114,   139,   168,   140,    -1,
      32,    -1,    32,   171,    -1,    94,   178,   138,   168,    -1,
      94,   178,   138,   168,   138,   168,    -1,    95,   178,    -1,
      97,   178,   138,   171,    -1,    97,   178,   138,   171,   138,
     168,    -1,    -1,    28,   153,   261,    -1,    -1,    29,   154,
     261,    -1,    57,   262,    -1,    56,   263,    -1,    25,   270,
      -1,    26,   270,    -1,    27,   270,    -1,   100,   178,   138,
     171,    -1,    20,   168,    -1,    -1,    21,   139,   155,   186,
     140,    -1,    -1,    22,   139,   156,   186,   140,    -1,    -1,
      75,   270,   157,   215,   158,    76,    -1,    77,   162,    -1,
      78,   164,    -1,   159,    -1,   158,   159,    -1,   160,   215,
      -1,   161,    -1,   160,   138,   161,    -1,     3,    -1,   129,
       3,    -1,     4,    -1,   163,    -1,   162,   138,   163,    -1,
     270,    24,   270,    -1,   273,    24,   270,    -1,   271,    24,
     270,    -1,   274,    24,   270,    -1,   270,    -1,   164,   138,
     270,    -1,   270,    63,   171,    -1,   183,    63,   171,    -1,
     273,    63,   168,    -1,    91,   139,   167,   138,   171,   138,
     171,   140,    63,   168,    -1,    91,   139,   167,   138,   171,
     140,    63,   168,    -1,    89,   139,   167,   138,   171,   140,
      63,   168,    -1,    90,   139,   167,   138,   171,   140,    63,
     168,    -1,   185,    63,   168,    -1,   273,    -1,   274,    -1,
     273,    -1,   169,    -1,   184,    -1,     4,    -1,   168,   130,
     168,    -1,   139,   168,   140,    -1,    89,   139,   168,   138,
     171,   140,    -1,    90,   139,   168,   138,   171,   140,    -1,
      91,   139,   168,   138,   171,   138,   171,   140,    -1,    91,
     139,   168,   138,   171,   140,    -1,   109,   139,   171,   140,
      -1,   109,   139,   171,   138,   168,   140,    -1,   109,   139,
     171,   138,   168,   138,   168,   140,    -1,   110,   139,   171,
     140,    -1,    92,   139,   168,   140,    -1,    93,   139,   168,
     140,    -1,   125,   139,   168,   140,    -1,   126,   139,   168,
     140,    -1,   124,   139,   168,   140,    -1,   120,   139,   167,
     138,   168,   140,    -1,   120,   139,   167,   140,    -1,   122,
     139,   167,   138,   168,   140,    -1,   122,   139,   167,   140,
      -1,   118,    -1,   117,    -1,   115,   139,   171,   140,    -1,
     116,   139,   168,   140,    -1,    -1,    22,   139,   170,   186,
     140,    -1,    -1,   171,    17,   172,   171,    -1,    -1,   171,
      16,   173,   171,    -1,    18,   171,    -1,   171,    63,   171,
      -1,   171,    58,   171,    -1,   171,    61,   171,    -1,   171,
      59,   171,    -1,   171,    62,   171,    -1,   171,    60,   171,
      -1,    96,   139,   178,   140,    -1,   123,   139,   168,   138,
     168,   140,    -1,    54,   139,   174,   140,    -1,    54,   139,
     175,   140,    -1,    55,   139,   174,   138,   171,   140,    -1,
      55,   139,   175,   138,   171,   140,    -1,   182,    -1,   168,
      63,   168,    -1,   168,    58,   168,    -1,   168,    61,   168,
      -1,   168,    59,   168,    -1,   168,    62,   168,    -1,   168,
      60,   168,    -1,   176,    -1,   171,   133,   171,    -1,   171,
      64,   171,    -1,   130,   171,    -1,   129,   171,    -1,   171,
     131,   171,    -1,   171,   132,   171,    -1,   171,   129,   171,
      -1,   171,   130,   171,    -1,   139,   171,   140,    -1,   270,
      -1,     3,    -1,   272,    -1,   276,    -1,   101,   139,   171,
     140,    -1,   102,   139,   171,   140,    -1,   103,   139,   171,
     140,    -1,   104,   139,   171,   140,    -1,   105,   139,   171,
     140,    -1,   106,   139,   171,   140,    -1,   106,   139,   171,
     138,   171,   140,    -1,   107,   139,   171,   140,    -1,   108,
     139,   171,   140,    -1,   108,   139,   171,   138,   171,   140,
      -1,    85,   139,   171,   140,    -1,    83,   139,   171,   140,
      -1,    84,   139,   171,   140,    -1,    86,   139,   171,   140,
      -1,    80,   139,   171,   140,    -1,    81,   139,   171,   140,
      -1,    82,   139,   171,   140,    -1,    82,   139,   140,    -1,
      87,   139,   171,   138,   171,   140,    -1,    88,   139,   171,
     138,   171,   140,    -1,   113,   139,   168,   140,    -1,   111,
     139,   168,   140,    -1,   112,   139,   168,   140,    -1,   127,
     139,   168,   138,   168,   140,    -1,   127,   139,   168,   138,
     168,   138,   171,   140,    -1,   128,   139,   168,   138,   168,
     140,    -1,   128,   139,   168,   138,   168,   138,   171,   140,
      -1,   114,   139,   168,   140,    -1,    16,   139,   171,   138,
     171,   140,    -1,    17,   139,   171,   138,   171,   140,    -1,
      19,   139,   171,   138,   171,   140,    -1,   119,   139,   168,
     138,   175,   138,   168,   140,    -1,   119,   139,   168,   138,
     175,   140,    -1,   121,   139,   168,   138,   175,   138,   168,
     140,    -1,   121,   139,   168,   138,   175,   140,    -1,    94,
     139,   168,   140,    -1,    94,   139,   168,   138,   168,   140,
      -1,    94,   139,   178,   138,   168,   140,    -1,    94,   139,
     178,   138,   168,   138,   168,   140,    -1,    98,   139,   178,
     140,    -1,    99,   139,   178,   140,    -1,    -1,    21,   139,
     177,   186,   140,    -1,   141,   171,    -1,   171,    -1,    79,
      -1,    85,    -1,    -1,    49,   179,    -1,     5,   180,    -1,
     274,   180,    -1,   181,   138,     5,   180,    -1,   181,   138,
     274,   180,    -1,   271,    -1,   272,    -1,   271,    -1,   274,
      -1,   276,    -1,   274,    -1,   187,    -1,   186,   138,   187,
      -1,   168,    -1,   171,    -1,    11,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,   188,   190,   196,   191,   139,   201,
     140,   192,   180,   193,   145,   194,   195,    -1,    30,    -1,
      12,    -1,    15,    -1,   270,    -1,   273,    -1,   198,    -1,
     197,   138,   198,    -1,   270,    -1,   273,    -1,   271,    -1,
     274,    -1,   200,    -1,   199,   138,   200,    -1,   270,    -1,
     273,    -1,   271,    -1,   274,    -1,    -1,   202,    -1,   201,
     138,   202,    -1,   270,    -1,   273,    -1,   272,    -1,   276,
      -1,    -1,    -1,    -1,    -1,    34,   204,   270,    63,   205,
     171,    35,   171,   210,   206,   145,   207,   208,   209,    -1,
      30,    -1,    36,    -1,    -1,   270,    -1,    -1,    37,   171,
      -1,    -1,    -1,    -1,    71,   212,   213,   216,   215,   217,
     219,    72,   214,    -1,     7,    -1,   215,     7,    -1,   171,
      -1,   168,    -1,    -1,    -1,   217,    73,   218,   216,    -1,
      -1,    -1,    -1,    74,     7,   220,   221,   145,    -1,    -1,
      -1,    42,   223,   224,   145,   225,    -1,    30,    -1,    -1,
      43,   226,    -1,    -1,    -1,    -1,    38,   228,   229,   171,
     230,   145,   231,    -1,    30,    -1,    -1,    39,   232,    -1,
      -1,    -1,    40,   234,   235,   145,   236,    -1,    30,    -1,
      -1,    41,   171,   237,    -1,    -1,    -1,    -1,   247,   171,
     239,    45,   145,   240,   249,   248,   241,   246,    -1,    -1,
      -1,   247,   171,   243,   148,   244,    -1,    -1,   247,   171,
     245,   215,   148,    -1,    30,    -1,    48,    -1,    44,    -1,
      -1,    46,   145,    -1,    -1,    -1,    -1,    47,   171,    45,
     250,   145,   251,   249,    -1,   270,    -1,   273,    -1,   271,
      -1,   274,    -1,    -1,   171,    -1,   171,    68,   168,    -1,
     168,    -1,   253,   138,   171,    -1,   253,   138,   171,    68,
     168,    -1,   253,   138,   168,    -1,    -1,   255,   259,   252,
      -1,    -1,   141,   270,   256,   252,    -1,    -1,   141,     3,
     257,   252,    -1,    -1,   141,   139,   171,   140,   258,   252,
      -1,   168,    -1,    -1,   141,   270,    -1,   141,     3,    -1,
     141,   139,   171,   140,    -1,    33,    -1,   270,    -1,   262,
     138,   270,    -1,   270,    -1,   263,   138,   270,    -1,    -1,
      69,   269,   270,   265,   215,   267,    70,    -1,    -1,    69,
     269,   271,   266,   215,   267,    70,    -1,   268,   215,    -1,
     267,   268,   215,    -1,   264,    -1,   269,   270,    -1,   269,
     273,    -1,   269,   271,    -1,   269,   274,    -1,    -1,     5,
      -1,   270,   136,     5,    -1,     5,   139,    -1,   271,   136,
       5,   139,   186,   140,    -1,   271,   136,     5,    -1,   270,
     136,     5,   139,    -1,     5,   139,   140,    -1,   272,   136,
       5,   139,   140,    -1,   272,   136,     5,    -1,   270,   136,
       5,   139,   140,    -1,     6,    -1,   270,   136,     6,    -1,
       6,   139,    -1,   271,   136,     6,   139,   186,   140,    -1,
     271,   136,     6,    -1,    -1,   270,   136,     6,   139,   275,
     186,   140,    -1,     6,   139,   140,    -1,   272,   136,     6,
     139,   140,    -1,   272,   136,     6,    -1,   270,   136,     6,
     139,   140,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,     8,    12,    14,    15,    20,    21,
      23,    25,    27,    30,    33,    35,    37,    39,    41,    43,
      45,    47,    49,    51,    53,    55,    57,    59,    60,    64,
      65,    69,    73,    78,    83,    84,    88,    89,    94,    96,
      99,   102,   105,   110,   112,   115,   120,   127,   130,   135,
     142,   143,   147,   148,   152,   155,   158,   161,   164,   167,
     172,   175,   176,   182,   183,   189,   190,   197,   200,   203,
     205,   208,   211,   213,   217,   219,   222,   224,   226,   230,
     234,   238,   242,   246,   248,   252,   256,   260,   264,   275,
     284,   293,   302,   306,   308,   310,   312,   314,   316,   318,
     322,   326,   333,   340,   349,   356,   361,   368,   377,   382,
     387,   392,   397,   402,   407,   414,   419,   426,   431,   433,
     435,   440,   445,   446,   452,   453,   458,   459,   464,   467,
     471,   475,   479,   483,   487,   491,   496,   503,   508,   513,
     520,   527,   529,   533,   537,   541,   545,   549,   553,   555,
     559,   563,   566,   569,   573,   577,   581,   585,   589,   591,
     593,   595,   597,   602,   607,   612,   617,   622,   627,   634,
     639,   644,   651,   656,   661,   666,   671,   676,   681,   686,
     690,   697,   704,   709,   714,   719,   726,   735,   742,   751,
     756,   763,   770,   777,   786,   793,   802,   809,   814,   821,
     828,   837,   842,   847,   848,   854,   857,   859,   861,   863,
     864,   867,   870,   873,   878,   883,   885,   887,   889,   891,
     893,   895,   897,   901,   903,   905,   907,   909,   910,   911,
     912,   913,   914,   928,   930,   932,   934,   936,   938,   940,
     944,   946,   948,   950,   952,   954,   958,   960,   962,   964,
     966,   967,   969,   973,   975,   977,   979,   981,   982,   983,
     984,   985,  1000,  1002,  1004,  1005,  1007,  1008,  1011,  1012,
    1013,  1014,  1024,  1026,  1029,  1031,  1033,  1034,  1035,  1040,
    1041,  1042,  1043,  1049,  1050,  1051,  1057,  1059,  1060,  1063,
    1064,  1065,  1066,  1074,  1076,  1077,  1080,  1081,  1082,  1088,
    1090,  1091,  1095,  1096,  1097,  1098,  1109,  1110,  1111,  1117,
    1118,  1124,  1126,  1128,  1130,  1131,  1134,  1135,  1136,  1137,
    1145,  1147,  1149,  1151,  1153,  1154,  1156,  1160,  1162,  1166,
    1172,  1176,  1177,  1181,  1182,  1187,  1188,  1193,  1194,  1201,
    1203,  1204,  1207,  1210,  1215,  1217,  1219,  1223,  1225,  1229,
    1230,  1238,  1239,  1247,  1250,  1254,  1256,  1259,  1262,  1265,
    1268,  1269,  1271,  1275,  1278,  1285,  1289,  1294,  1298,  1304,
    1308,  1314,  1316,  1320,  1323,  1330,  1334,  1335,  1343,  1347,
    1353,  1357
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   193,   193,   211,   212,   215,   216,   216,   225,   226,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   244,   250,   251,   252,   253,   254,   254,   255,
     255,   256,   268,   275,   282,   282,   283,   283,   284,   287,
     292,   293,   298,   301,   302,   303,   304,   305,   306,   307,
     308,   308,   309,   309,   310,   311,   312,   315,   316,   319,
     320,   321,   321,   324,   324,   325,   325,   326,   327,   330,
     331,   334,   337,   338,   341,   342,   343,   346,   347,   350,
     351,   352,   353,   356,   357,   360,   367,   370,   371,   372,
     373,   374,   375,   380,   381,   384,   385,   386,   387,   388,
     389,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   413,   416,   416,   417,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   444,   449,   452,   455,   459,   463,   464,   468,
     473,   476,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   520,   523,   524,   527,   530,   536,
     537,   545,   552,   553,   558,   561,   562,   565,   568,   569,
     572,   575,   576,   579,   580,   583,   584,   588,   589,   590,
     591,   596,   588,   605,   611,   612,   615,   616,   619,   620,
     623,   624,   625,   626,   629,   630,   633,   634,   635,   636,
     639,   640,   641,   644,   645,   648,   651,   656,   657,   661,
     663,   656,   669,   674,   677,   678,   681,   682,   685,   685,
     687,   685,   692,   693,   696,   697,   700,   701,   701,   709,
     710,   710,   710,   716,   716,   716,   721,   722,   722,   725,
     725,   726,   725,   732,   733,   733,   736,   736,   736,   741,
     743,   742,   746,   751,   753,   746,   757,   758,   757,   759,
     759,   763,   764,   767,   770,   771,   774,   776,   778,   775,
     782,   783,   784,   785,   788,   789,   794,   796,   798,   800,
     802,   806,   806,   807,   807,   808,   808,   809,   809,   812,
     816,   821,   822,   823,   826,   829,   830,   833,   834,   838,
     838,   854,   854,   872,   873,   876,   877,   885,   893,   901,
     911,   919,   923,   926,   928,   929,   930,   933,   936,   937,
     938,   941,   942,   945,   946,   947,   948,   948,   951,   952,
     953,   954
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
  const int parser::yylast_ = 3366;
  const int parser::yynnts_ = 135;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 205;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 142;

  const unsigned int parser::yyuser_token_number_max_ = 386;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 22 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 4276 "/home/cai/projects/basic/compiler/parser.cpp"
