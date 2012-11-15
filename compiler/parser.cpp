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

extern	DimAST * program;


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
#line 195 "parser.ypp"
    {
			program = new DefaultMainFunctionAST( (yysemantic_stack_[(2) - (1)].statement_list) );
			
			debug("program ended\n");
			/*add_command (cEOPROG, NULL);*/
			// yylex_destroy ();
			YYACCEPT;
		}
    break;

  case 3:
/* Line 661 of lalr1.cc  */
#line 205 "parser.ypp"
    { (yyval.statement_list) = (yysemantic_stack_[(1) - (1)].statement_list); debug("list_of_statement_lists\n"); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 209 "parser.ypp"
    { (yyval.statement_list) = new StatementsAST(); (yyval.statement_list)->append(StatementASTPtr((yysemantic_stack_[(1) - (1)].statement)));}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 210 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 210 "parser.ypp"
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
#line 219 "parser.ypp"
    { (yyval.statement) = 0 ;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 220 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 234 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { debug ("cannot \"break\" outside of loop"); }
   }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 238 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   debug ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 246 "parser.ypp"
    { }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 247 "parser.ypp"
    { }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 248 "parser.ypp"
    {if (function_type==ftNONE) debug("declaring variables \"local\" outside of a function has no effect"); }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 249 "parser.ypp"
    {if (function_type==ftNONE) debug("declaring variables \"static\" outside of a function has no effect"); }
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 250 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now\n");
	   //TODO 最后一个是 \new line
		(yysemantic_stack_[(3) - (3)].print_list)->additem(boost::make_shared<EmptyExprAST>());
	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(3) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(3) - (3)].print_list)));
   }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 258 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 263 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 268 "parser.ypp"
    { until_eol = false; }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 268 "parser.ypp"
    {}
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 269 "parser.ypp"
    { until_eol = true; }
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 269 "parser.ypp"
    {}
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 270 "parser.ypp"
    {
	   
             }
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 273 "parser.ypp"
    {

	   
   }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 278 "parser.ypp"
    { }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 279 "parser.ypp"
    {
	   debug("got syntax of \"dim local var\" now\n");

	   (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list);	   
	}
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 284 "parser.ypp"
    {
	   
}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 287 "parser.ypp"
    {}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 288 "parser.ypp"
    {}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    {}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 290 "parser.ypp"
    {}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 291 "parser.ypp"
    {}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    {}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 293 "parser.ypp"
    {}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 294 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 295 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 298 "parser.ypp"
    {

   }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 301 "parser.ypp"
    {  }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 302 "parser.ypp"
    {
		debug("got label!\n");
   }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 305 "parser.ypp"
    {  }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 306 "parser.ypp"
    {  }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    {  }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 310 "parser.ypp"
    { }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 310 "parser.ypp"
    {  }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 311 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 327 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 328 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 79:
/* Line 661 of lalr1.cc  */
#line 336 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 337 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 338 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 339 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 342 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 343 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 346 "parser.ypp"
    {
		// 变量赋值
		debug("变量赋值\n");
		(yyval.number_assignment) = new NumberAssigmentAST(VariableRefExprASTPtr((yysemantic_stack_[(3) - (1)].varable_ref)), NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
	}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 351 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 354 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 355 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 356 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 358 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 359 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 364 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 368 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 370 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 371 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 376 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 377 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 381 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 382 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 389 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 390 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 414 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 415 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 419 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 420 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 421 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 423 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 425 "parser.ypp"
    {
	   (yyval.number_expression) = (yysemantic_stack_[(2) - (2)].number_expression) ;
   }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 428 "parser.ypp"
    {
	   /*add_command(cNEGATE,NULL);*/
	   ConstNumberExprAST * zero = new ConstNumberExprAST(0);
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr(zero) ,OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression)));
   }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 433 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_MUL,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 436 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_DIV,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 439 "parser.ypp"
    {
	   // 减法计算
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 443 "parser.ypp"
    {
	   // 加法计算.
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_ADD,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 447 "parser.ypp"
    { (yyval.number_expression) = (yysemantic_stack_[(3) - (2)].number_expression) ;}
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 448 "parser.ypp"
    {
	   debug("got numsym_s\n");	   
	   (yyval.number_expression) =new NumberExprAST( VariableExprASTPtr((yysemantic_stack_[(1) - (1)].varable_ref)) );
	}
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 452 "parser.ypp"
    {
	   (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));
   }
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 457 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 460 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 463 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 464 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 465 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 466 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 467 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 468 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 469 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 470 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 471 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 472 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 473 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 474 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 475 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 476 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 477 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 478 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 479 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 480 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 481 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 482 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 483 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 484 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 487 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 488 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 489 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 491 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 492 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 495 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 496 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 497 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 498 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 499 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 500 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 502 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 503 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 504 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 504 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 207:
/* Line 661 of lalr1.cc  */
#line 511 "parser.ypp"
    {
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 514 "parser.ypp"
    {
		//TODO int should be 32bit not 64bit
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 521 "parser.ypp"
    {
			debug("as  %s\n",(yysemantic_stack_[(2) - (2)].exprtype)->name.c_str());
			// long varable
			// 构造类型
			(yyval.exprtype) = (yysemantic_stack_[(2) - (2)].exprtype);
		}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 529 "parser.ypp"
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
#line 536 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 537 "parser.ypp"
    {
	  // 	std::string name;
	//	name = $3;
	//	$$ = new VariableDimAST( name , ExprTypeASTPtr($2));
   }
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 542 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 545 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 546 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 549 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 552 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 219:
/* Line 661 of lalr1.cc  */
#line 553 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 220:
/* Line 661 of lalr1.cc  */
#line 556 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 559 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 560 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 225:
/* Line 661 of lalr1.cc  */
#line 567 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 568 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 571 "parser.ypp"
    {
		not_inside_loop_or_conditional ("define a function");
		if (function_type!=ftNONE) {debug("functions cannot be nested");}
	}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 575 "parser.ypp"
    {
		
	}
    break;

  case 229:
/* Line 661 of lalr1.cc  */
#line 578 "parser.ypp"
    {

	}
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 581 "parser.ypp"
    {		}
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 582 "parser.ypp"
    {
		debug("function dim as ...\n");
	   //$$ = $11;
	}
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 586 "parser.ypp"
    {
		/** TODO support for functions*/
   }
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 591 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 597 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 598 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 609 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 610 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 611 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 612 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 619 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 247:
/* Line 661 of lalr1.cc  */
#line 620 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 248:
/* Line 661 of lalr1.cc  */
#line 621 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 249:
/* Line 661 of lalr1.cc  */
#line 622 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 630 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 254:
/* Line 661 of lalr1.cc  */
#line 631 "parser.ypp"
    {
	   
}
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 634 "parser.ypp"
    {
	   
}
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 637 "parser.ypp"
    {
	   
}
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 642 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 643 "parser.ypp"
    {
				 
			}
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 647 "parser.ypp"
    {
	 }
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 649 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 651 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 655 "parser.ypp"
    {
		if (unclosed_fors) {
			debug ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 660 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 663 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 664 "parser.ypp"
    {  }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 667 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 671 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 671 "parser.ypp"
    {
	}
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 673 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 673 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 678 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 679 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 687 "parser.ypp"
    {
	   
}
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 690 "parser.ypp"
    {
		   
	}
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 696 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 696 "parser.ypp"
    {

	   
}
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 702 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 702 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 707 "parser.ypp"
    {if (unclosed_dos) { debug ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 708 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 708 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 711 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 711 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 712 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 718 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 719 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 719 "parser.ypp"
    { }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 727 "parser.ypp"
    {if (unclosed_repeats) { debug ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 729 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 729 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 732 "parser.ypp"
    {
				/*构造 IF 语句, 填充 条件表达式*/
				NumberExprASTPtr ne = NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression));

								
			}
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 737 "parser.ypp"
    {  /*填充真语句*/ }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 739 "parser.ypp"
    { /*填充假语句*/}
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 744 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 744 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 745 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 746 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 749 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 750 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 753 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 762 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 764 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 768 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 769 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 770 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 771 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 774 "parser.ypp"
    { debug("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 775 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 781 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 783 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 785 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 787 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 789 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 792 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 793 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 794 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 795 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 799 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 802 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 807 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 808 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 809 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 812 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 815 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 816 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 819 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 820 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 824 "parser.ypp"
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
#line 834 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 840 "parser.ypp"
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
#line 850 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 863 "parser.ypp"
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
#line 871 "parser.ypp"
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
#line 879 "parser.ypp"
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
#line 887 "parser.ypp"
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
#line 897 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 905 "parser.ypp"
    {
		debug("变量引用\n");
		(yyval.varable_ref) = new VariableRefExprAST( (yysemantic_stack_[(1) - (1)].symbol) );
	}
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 909 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 912 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 914 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 915 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 916 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 919 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 922 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 923 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 924 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 927 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 928 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 931 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 932 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 933 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 934 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 934 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 937 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 938 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 939 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 940 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2571 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const short int parser::yypact_ninf_ = -643;
  const short int
  parser::yypact_[] =
  {
      3372,   -69,   -48,  -643,  -643,  -643,  2367,  -643,  1012,   -36,
      18,   119,   119,   119,  -643,  -643,  2367,  -643,  -643,  -643,
    -643,  -643,    58,   172,  -643,  -643,   119,   119,    -2,  -643,
     111,  -643,  -643,   119,   280,   119,    91,    98,   117,  2071,
    2071,  2071,  2071,   205,   192,   350,   253,  -643,  -643,  -643,
    -643,  -643,   147,  -643,   248,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  2367,  -643,   -32,   -30,   217,   301,
     313,  -643,   245,   260,  -643,  -643,   312,   347,  2367,   354,
     378,   383,   395,   397,   406,   407,   408,   411,   413,   415,
     416,   418,   420,   421,   424,   425,   426,   430,   432,   440,
     441,   447,   449,   450,   451,   454,   456,   459,   462,   463,
     466,   467,   475,   476,   483,   486,   487,   489,  -643,  -643,
     490,   492,   494,   496,   497,   498,   502,   503,   504,   505,
    2367,  2367,  2367,    25,  -643,  3149,  -643,  -643,  -643,   300,
     460,  -643,  -643,  1012,   196,   300,   460,   217,  -643,  -643,
    -643,   471,   471,   471,   387,   387,    25,  3149,   119,  -643,
    -643,  -643,   506,   508,  -643,  -643,   -13,   460,  -643,   -27,
     508,   381,   477,   534,   280,   280,   485,   471,   510,   471,
       2,  2367,   453,  -643,   624,  -643,   471,   511,  -643,   -14,
      -8,   608,   610,   513,   471,   280,   280,   280,  2367,  3149,
     521,  -643,   522,   523,  1012,  -643,  -643,  3372,  -643,  2367,
    1012,   299,  3060,  2367,   439,   468,   470,  1012,  -643,  -643,
    2367,  2367,   186,  2367,  -643,  -643,   472,   472,  2367,  2367,
    2230,  2367,  2367,  2367,  2367,  2367,  2367,  1012,  1012,  1012,
    1012,  1012,  2071,  2071,  2071,  2071,  2367,  2367,  2367,  2367,
    2367,  2367,  2367,  2367,  2367,  2367,  1012,  1012,  1012,  1012,
    2367,  1012,  1012,   280,  1012,   280,  1012,  1012,  1012,  1012,
    1012,  1012,   598,   598,    -4,   873,  1012,  1012,  1012,  1012,
    1012,  1012,  1012,  -643,  -643,  2367,  2367,  2367,  2367,  2367,
    2367,  2367,  2367,  2367,  2367,  2367,  2367,   -62,  2367,  2367,
     657,  -643,  -643,  -643,   -12,  2367,  3372,  3372,  -643,  -643,
     474,    17,  -643,   478,   484,  -643,   527,  -643,   528,   460,
    -643,  -643,   530,  -643,   528,   460,  -643,  -643,   119,   119,
    -643,  2367,   471,    25,  3048,   358,    33,  -643,  1012,   453,
     533,   535,  2367,   662,   280,   119,   119,   119,   119,   119,
     536,   528,  -643,  -643,   537,   538,  3149,  1012,  2367,  2367,
      16,   253,  3372,  3149,   196,  -643,  -643,   542,  -643,   634,
    3372,   662,  3149,   541,   546,   547,   552,   553,   554,   196,
      57,    71,   982,  2367,  2367,   555,   556,   557,   558,   545,
     217,  -643,   544,   562,  1134,  1167,  -643,  1194,  1381,  1444,
    1530,  1547,  1148,  2948,   -77,   274,   275,    43,    77,    13,
     563,   564,   565,   566,  1559,  1586,  1778,  1796,  1824,   380,
    1925,   479,   594,  1981,    86,   144,   198,   201,  2075,   203,
     277,   -61,   279,   -40,   281,   221,   227,   230,   284,   286,
    -643,  -643,   196,   196,   196,   196,   196,   196,  -643,  2367,
    2367,   815,    31,   444,   171,   160,   165,  -643,    37,    37,
     598,   598,   598,    25,  3149,    54,  -643,   114,  -643,  -643,
    3149,    97,    39,   568,   569,  -643,  -643,  -643,   -27,   534,
     569,   280,   280,   471,   471,  2371,  1012,  -643,  2367,  -643,
    2367,   471,   196,   280,  -643,   690,   662,   696,   662,    25,
    3149,   662,  -643,    36,  -643,   471,   471,   471,   471,   471,
    2367,  2367,  2367,   296,  2962,  3149,  -643,  -643,   570,   493,
    3372,  -643,  3277,   572,   574,  2367,  2367,   575,   576,  2367,
    2367,  2367,   135,   187,   245,   260,  -643,  -643,   495,  2367,
    2367,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  2367,  2367,
    2367,  2367,  2367,  -643,  -643,  1012,  -643,  1012,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  2367,  -643,  -643,  2367,
    -643,  1012,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
     472,  1012,  -643,   472,  1012,  -643,  1012,  -643,  -643,  -643,
    1012,  1012,   186,  1500,  2367,  -643,  -643,  2367,  3372,  -643,
    2367,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,   196,    25,  3073,   280,  2489,   280,  -643,   528,
     460,  -643,  -643,    30,    30,   702,  -643,  -643,  -643,   713,
      21,  -643,    -1,  -643,  2503,  2515,   838,  1012,  1012,   509,
    -643,   253,  -643,  -643,  -643,  -643,  2367,   202,   283,  -643,
    -643,  2527,  2545,  2628,  -643,  -643,   581,   582,  2640,  2652,
    2670,  2684,  2767,  2779,  1109,   232,   -78,  2795,  2809,   113,
     287,   238,   297,   239,   243,   182,   183,  -643,  3092,   176,
    3149,  -643,  1012,  -643,  -643,  -643,  -643,   455,   662,   280,
     458,   457,  -643,  -643,  -643,    38,   702,   659,   665,  2367,
     667,   196,   196,   556,   325,  -643,   595,   217,  -643,  -643,
     689,   326,  -643,  -643,  -643,  -643,  -643,   572,   574,  -643,
    -643,  -643,  -643,  -643,  -643,  2367,  -643,  -643,  1012,  -643,
    -643,  -643,  1012,  -643,  1012,  -643,  -643,  1012,  -643,  -643,
    -643,  2367,  -643,  2367,  -643,  2367,  -643,  -643,  -643,  -643,
     196,   280,  -643,   662,   702,   528,   460,  -643,  -643,  -643,
    -643,   729,   670,  -643,  1012,  1012,  2823,  1012,   509,  -643,
     526,  2367,   697,  -643,  2906,   252,   254,   263,   266,  2920,
    2934,  3105,  -643,  -643,   702,  2367,  -643,  -643,   196,   196,
     681,   196,  -643,  3372,   582,  3137,  3372,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  2367,  -643,  -643,  -643,  -643,
    1012,   253,  -643,   253,    15,  3149,  3372,  3372,   196,   534,
    3372,  -643,  -643,  -643,   253,   253,  -643,   253,   122,   269,
     689,  -643,  -643,   119,  -643,  -643,  -643,  -643,  -643,  -643,
     471
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
       0,    89,   252,     8,   372,     0,     8,   304,   103,   200,
     107,   193,   195,   186,   188,     0,   259,   278,   281,   271,
       0,   230,   317,   315,     0,   267,     8,     8,    88,   209,
       8,   311,   312,   305,   260,   282,   231,   318,     0,     0,
     316,   262,   263,   264,   234,   235,   233,   232,   319,   261,
     265
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -643,  -643,  -643,  -197,  -643,   382,  -369,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,   116,  -643,    53,
    -643,   405,  -643,   730,   731,   -84,   817,  -643,  -643,  1521,
    -643,  -643,   531,  -225,  -643,  -643,   -24,  -643,  -170,  -643,
      28,  -643,    47,  -643,  -295,   161,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,   276,  -643,   278,  -643,
      -9,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -357,   -23,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,   -67,  -643,  -643,
    -586,  -643,   427,  -643,  -643,  -643,  -643,  -643,  -643,   614,
    -643,  -643,  -517,  -643,  -643,   146,  -642,   741,     0,   190,
    1208,   491,   543,  -643,  -207
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
        66,   521,   393,   315,   467,   330,   502,   150,   145,   345,
     361,   151,   152,   153,   522,   346,   201,   202,   203,   391,
     391,   311,   166,   172,   626,   627,   177,   179,    51,   683,
     213,   685,  -217,   186,   189,   194,   489,   628,   150,   626,
     627,   626,   627,   628,   821,   753,   208,    53,   753,   213,
     469,   282,   282,   276,   277,   278,   279,   280,   281,   728,
     550,   729,   822,   162,   163,   283,   284,   282,   602,    72,
     276,   277,   278,   279,   280,   281,   581,   440,   582,   283,
     284,   603,   276,   277,   278,   279,   280,   281,   532,   533,
      73,   288,   289,   290,   291,   475,   693,   584,    31,   585,
     291,   476,   148,   214,   208,   215,   686,   686,  -361,   471,
     472,   308,   354,   355,   285,   286,   287,   288,   289,   290,
     291,   310,   310,   300,   150,   282,   599,   215,   285,   286,
     287,   288,   289,   290,   291,   440,   695,   600,   180,   623,
     331,   624,   282,   145,   625,   282,    36,    37,    38,   629,
     555,   831,   556,   643,   282,   516,   149,   832,   304,   292,
     293,   294,   295,   296,   629,   783,   629,   294,   295,   296,
     686,   490,   282,   686,   318,   324,   183,   169,   170,   431,
     332,   433,   553,   208,   340,   292,   293,   294,   295,   296,
      67,   594,   205,   595,   529,   351,   351,   351,   146,   292,
     293,   294,   295,   296,   145,   746,   282,    66,   530,   209,
     145,   367,   167,   146,   747,   282,   554,   145,   410,   411,
     412,   413,   290,   291,   190,   574,   389,   389,   291,   195,
     647,   648,   289,   290,   291,    51,   196,   145,   145,   145,
     145,   145,   282,   285,   286,   287,   288,   289,   290,   291,
     732,   594,   733,   596,    53,   197,   145,   145,   145,   145,
     208,   145,   145,   351,   145,   351,   145,   145,   145,   145,
     145,   145,   594,   282,   654,   696,   145,   145,   145,   145,
     145,   145,   145,   575,   834,   162,   163,   835,   292,   293,
     294,   295,   296,   292,   293,   294,   295,   296,   836,   292,
     293,   294,   295,   296,   150,   365,    66,    66,   607,   608,
     210,   282,   282,   172,   292,   293,   294,   295,   296,   741,
     743,   742,   744,   641,   594,   282,   655,   282,   483,   484,
     282,   754,   282,   146,    51,    51,   491,   576,   145,   594,
     577,   712,   579,   204,   189,   505,   506,   507,   508,   509,
     282,   711,   216,    53,    53,   670,   282,   145,   672,   282,
     587,   282,    66,   217,   319,   325,   588,   282,   282,   589,
      66,   727,   282,   391,   341,  -220,   391,   736,   739,   206,
     207,   282,   740,   282,   218,   146,   146,   146,   283,   284,
      51,   799,   282,   800,   146,   282,   784,    67,    51,   219,
     146,   679,   801,   282,   282,   802,   282,   146,   282,    53,
     282,   551,   552,   282,   580,   282,   583,    53,   586,   301,
     594,   590,   713,   591,   734,   282,   735,   146,   146,   146,
     146,   146,   709,   637,   737,   214,   738,   285,   286,   287,
     288,   289,   290,   291,   373,   374,   146,   146,   146,   146,
     220,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   768,   594,   769,   773,   146,   146,   146,   146,
     146,   146,   146,   375,   376,   377,   378,   385,   386,   473,
     474,   318,   324,   478,   170,   221,   145,   283,   284,   473,
     480,    69,   223,   619,   487,   488,    67,    67,   468,   640,
     656,   657,   286,   146,   288,   289,   290,   291,   292,   293,
     294,   295,   296,    69,   385,   703,   224,   566,   313,   567,
      66,   225,    66,    31,   752,   191,    31,   759,   146,   760,
     761,   656,   794,   226,   190,   227,   285,   286,   287,   288,
     289,   290,   291,    70,   228,   229,   230,   146,    51,   231,
      51,   232,    67,   233,   234,   145,   235,   145,   236,   237,
      67,   709,   238,   239,   240,   168,   173,    53,   241,    53,
     242,   145,   292,   293,   294,   295,   296,   192,   243,   244,
     389,   145,   311,   389,   145,   245,   145,   246,   247,   248,
     145,   145,   249,   336,   250,   215,   811,   251,    66,   813,
     252,   253,   283,   284,   254,   255,   300,   292,   293,   294,
     295,   296,   314,   256,   257,   619,   569,   619,   570,   824,
     825,   258,   328,   827,   259,   260,    51,   261,   262,   162,
     263,   347,   264,   348,   265,   266,   267,   145,   145,   706,
     268,   269,   270,   271,   308,    53,   309,   329,   344,   826,
     349,   285,   286,   287,   288,   289,   290,   291,   357,   358,
     359,   291,   468,   310,   481,   320,   326,   482,   495,   502,
     497,   319,   325,   510,   511,   512,   146,   519,   520,   523,
     538,   539,   145,   620,   524,   525,   352,   352,   352,   755,
     526,   527,   528,   534,   535,   473,   536,   537,    69,   540,
     557,   375,   368,   558,   559,   560,   605,   606,   639,   628,
      67,   644,    67,   645,   649,   650,   692,   321,   327,   717,
     718,   764,   292,   293,   294,   295,   296,   765,   145,   767,
     770,   571,   145,   572,   145,   771,   786,   145,   353,   353,
     353,   787,   796,   810,   517,   146,   694,   146,   763,   504,
      70,   619,   164,   165,   352,   677,   352,   609,   392,   792,
     610,   146,   807,   838,   145,   145,   494,   145,   706,   303,
     690,   146,   184,     0,   146,     0,   146,     0,     0,     0,
     146,   146,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,    66,     0,     0,    66,    69,    69,     0,
       0,     0,     0,     0,     0,   620,   353,   620,   353,     0,
     145,     0,     0,     0,     0,     0,    66,    66,     0,     0,
      66,    51,     0,   133,    51,   144,     0,   146,   146,     0,
       0,     0,     0,   840,     0,   191,     0,     0,     0,     0,
      53,     0,     0,    53,    51,    51,   283,   284,    51,    70,
      70,     0,     0,    69,     0,     0,   479,     0,     0,     0,
       0,    69,     0,    53,    53,     0,     0,    53,     0,     0,
       0,     0,   146,   286,   287,   288,   289,   290,   291,   756,
       0,   283,   284,     0,     0,     0,     0,   192,     0,     0,
       0,     0,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,     0,   146,     0,
       0,     0,   146,     0,   146,     0,     0,   146,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,   620,     0,   292,   293,   294,   295,   296,     0,   274,
       0,     0,     0,     0,   146,   146,     0,   146,     0,     0,
     297,     0,     0,     0,     0,     0,   292,   293,   294,   295,
     296,     0,   320,   326,     0,   699,     0,   700,     0,     0,
       0,     0,     0,    67,   621,     0,    67,     0,     0,     0,
     283,   284,     0,     0,     0,     0,     0,     0,   333,     0,
     146,   292,   293,   294,   295,   296,    67,    67,     0,     0,
      67,    69,   441,    69,     0,     0,    75,     1,     2,     0,
       0,   360,     0,     0,   321,   327,     0,   364,     0,     0,
       0,     0,     0,    81,   379,     0,   622,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,   404,   405,   406,   407,   408,   409,
       0,     0,     0,    70,     0,    70,     0,     0,     0,     0,
       0,     0,     0,   424,   425,   426,   427,     0,   429,   430,
       0,   432,     0,   434,   435,   436,   437,   438,   439,    69,
       0,     0,     0,   442,   443,   444,   445,   446,   447,   448,
      93,    94,    95,    96,    97,     0,   621,     0,   621,     0,
     292,   293,   294,   295,   296,   463,   463,   283,   284,   531,
     110,   111,     0,     0,     0,     0,   116,   117,   118,   119,
     708,   121,     0,   123,     0,   125,   126,   127,     0,     0,
       0,    70,   283,   284,     0,     0,     0,     0,     0,     0,
     143,     0,     0,     0,     0,   492,   283,   284,   622,   499,
     622,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,   513,   283,   284,     0,     0,     0,
     757,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,     0,     0,
     463,   463,   283,   284,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,     0,   758,     0,     0,     0,     0,   292,   293,   294,
     295,   296,   621,     0,     0,     0,   725,     0,   726,     0,
       0,   285,   286,   287,   288,   289,   290,   291,     0,   708,
       0,     0,   292,   293,   294,   295,   296,     0,     0,     0,
       0,     0,     0,   541,     0,     0,   292,   293,   294,   295,
     296,     0,     0,     0,    69,   548,     0,    69,     0,     0,
       0,     0,     0,     0,   622,   292,   293,   294,   295,   296,
       0,     0,     0,   612,     0,   613,   542,    69,    69,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   292,   293,   294,   295,   296,     0,     0,     0,
       0,     0,     0,   543,     0,     0,    70,     0,     0,    70,
       0,     0,   463,   463,     0,     0,     0,     0,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,    70,
      70,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,   665,     0,   666,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   669,   283,
     284,     0,     0,     0,     0,     0,     0,     0,   671,     0,
       0,   673,     0,   674,     0,     0,     0,   675,   676,     0,
       0,   463,   147,     0,     0,     0,     0,     0,   147,     0,
       0,     0,     0,     0,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,   390,   390,     0,     0,   285,   286,
     287,   288,   289,   290,   291,   147,   147,   147,   147,   147,
       0,     0,   283,   284,   701,   702,     0,     0,     0,     0,
       0,     0,     0,   463,   147,   147,   147,   147,     0,   147,
     147,     0,   147,     0,   147,   147,   147,   147,   147,   147,
       0,     0,     0,     0,   147,   147,   147,   147,   147,   147,
     147,     0,     0,     0,     0,     0,     0,     0,     0,   750,
       0,   285,   286,   287,   288,   289,   290,   291,   283,   292,
     293,   294,   295,   296,     0,     0,     0,     0,     0,     0,
     544,     0,     0,     0,     0,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   283,   284,
       0,     0,     0,     0,     0,   775,   147,     0,     0,   776,
       0,   777,     0,     0,   778,   283,   284,   285,   286,   287,
     288,   289,   290,   291,     0,   147,     0,   283,   284,     0,
       0,     0,   292,   293,   294,   295,   296,     0,     0,     0,
       0,   788,   789,   545,   791,   212,     0,   285,   286,   287,
     288,   289,   290,   291,   283,   284,     0,     0,     0,   222,
       0,     0,   499,     0,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,   818,   292,   293,
     294,   295,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   285,   286,   287,   288,   289,   290,   291,
       0,   272,   273,   275,     0,     0,     0,     0,   292,   293,
     294,   295,   296,     0,     0,     0,     0,     0,     0,   546,
       0,     0,     0,     0,     0,   292,   293,   294,   295,   296,
       0,     0,     0,     0,     0,     0,   547,   292,   293,   294,
     295,   296,     0,     0,   147,     0,     0,     0,   561,     0,
       0,     0,   334,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,   356,
       0,     0,     0,     0,     0,   562,     0,     0,     0,     0,
     363,     0,     0,     0,   372,     0,     0,     0,     0,     0,
       0,   380,   381,     0,   382,     0,     0,     0,     0,   394,
     395,   397,   398,   399,   400,   401,   402,   403,     0,     0,
       0,     0,     0,   147,     0,   147,     0,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,     0,     0,   147,
       0,   428,     0,     0,     0,     0,   283,   284,   147,   147,
       0,   147,   147,     0,   147,     0,     0,     0,   147,   147,
       0,     0,     0,     0,   283,   284,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,     0,   464,
     464,     0,     0,     0,     0,     0,   470,     0,     0,     0,
       0,     0,   283,   284,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,   147,   147,   707,     0,     0,
       0,     0,   485,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,   500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   514,
     515,   285,   286,   287,   288,   289,   290,   291,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   464,   292,   293,   294,   295,
     296,     0,     0,     0,     0,     0,     0,   563,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,     0,
       0,     0,     0,   283,   284,   564,   147,     0,     0,     0,
     147,     0,   147,     0,     0,   147,     0,     0,     0,     0,
       0,     0,   292,   293,   294,   295,   296,     0,     0,     0,
       0,     0,     0,   565,     0,     0,     0,     0,     0,     0,
     592,   593,   147,   147,     0,   147,   707,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,   283,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
       0,   616,     0,     0,     0,     0,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   634,   635,   636,     0,     0,     0,     0,   285,   286,
     287,   288,   289,   290,   291,     0,   464,   464,     0,     0,
     651,   652,   653,   292,   293,   294,   295,   296,     0,     0,
     658,   659,     0,     0,   568,     0,     0,     0,     0,   660,
     661,   662,   663,   664,    74,    75,     1,     2,     0,    76,
      77,    78,    79,   283,   284,     0,     0,   667,     0,     0,
     668,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
     293,   294,   295,   296,     0,   464,     0,     0,   678,     0,
     573,   680,     0,     0,    82,    83,     0,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    99,   464,   100,   101,
       0,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,     0,     0,   292,   293,   294,   295,   296,     0,   132,
       0,   198,     0,     0,   578,     0,     0,     0,     0,     0,
     766,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,     1,     2,     0,    76,    77,
      78,    79,     0,     0,     0,     0,   774,     0,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   779,     0,   780,     0,   781,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,     0,     0,     0,     0,     0,
       0,     0,   795,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   500,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,     0,    99,   815,   100,   101,     0,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   396,
      74,    75,     1,     2,     0,    76,    77,    78,    79,   283,
     284,     0,     0,     0,     0,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,     0,     0,     0,     0,     0,     0,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    99,     0,   100,   101,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   283,   284,   292,
     293,   294,   295,   296,     0,   132,     0,     0,     0,     0,
     611,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   283,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,   283,   284,     0,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,     0,   292,   293,   294,
     295,   296,     0,     0,     0,     0,     0,     0,   684,     0,
       0,   292,   293,   294,   295,   296,   283,   284,     0,     0,
       0,     0,   697,   292,   293,   294,   295,   296,   283,   284,
       0,     0,     0,     0,   698,   292,   293,   294,   295,   296,
     283,   284,     0,     0,     0,     0,   714,     0,     0,     0,
       0,     0,     0,   292,   293,   294,   295,   296,   283,   284,
       0,     0,     0,     0,   715,   285,   286,   287,   288,   289,
     290,   291,   283,   284,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,     0,     0,   292,   293,   294,   295,
     296,     0,     0,     0,     0,     0,     0,   716,   292,   293,
     294,   295,   296,     0,     0,   283,   284,     0,     0,   719,
     292,   293,   294,   295,   296,     0,     0,   283,   284,     0,
       0,   720,     0,     0,     0,     0,     0,     0,   292,   293,
     294,   295,   296,   283,   284,     0,     0,     0,     0,   721,
       0,     0,   292,   293,   294,   295,   296,   283,   284,     0,
       0,     0,     0,   722,   285,   286,   287,   288,   289,   290,
     291,   283,   284,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,     0,     0,     0,   292,   293,   294,   295,   296,
       0,     0,     0,     0,     0,     0,   723,   292,   293,   294,
     295,   296,     0,     0,   283,   284,     0,     0,   724,     0,
       0,     0,     0,   292,   293,   294,   295,   296,   283,   284,
       0,     0,     0,     0,   730,     0,     0,   292,   293,   294,
     295,   296,   283,   284,     0,     0,     0,     0,   731,     0,
       0,   292,   293,   294,   295,   296,   283,   284,     0,     0,
       0,     0,   790,   285,   286,   287,   288,   289,   290,   291,
     283,   284,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,     0,
       0,     0,     0,     0,     0,   798,     0,     0,   292,   293,
     294,   295,   296,     0,     0,     0,   283,   284,     0,   803,
       0,     0,   292,   293,   294,   295,   296,  -309,   283,   284,
       0,     0,     0,   804,     0,     0,   292,   293,   294,   295,
     296,   283,   284,     0,     0,   549,     0,     0,     0,     0,
     292,   293,   294,   295,   296,     0,     0,     0,     0,   638,
     283,   284,     0,     0,  -302,   285,   286,   287,   288,   289,
     290,   291,     0,   283,   284,   486,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,   745,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
     682,   805,     0,     0,     0,   283,   284,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,   283,   284,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,   292,   293,   294,   295,
     296,   812,     0,     0,     0,     0,     0,     0,   292,   293,
     294,   295,   296,     0,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,     0,     0,     0,     0,     0,
       0,     0,     0,   292,   293,   294,   295,   296,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   292,   293,   294,   295,   296,
       0,     0,     0,     0,     0,     0,     0,   292,   293,   294,
     295,   296,     1,     2,   628,     0,     0,     0,     0,     3,
       4,     5,     0,     6,     7,     0,     8,     9,    10,     0,
       0,    11,    12,    13,    14,    15,     0,     0,    16,     0,
      17,     0,     0,     0,    18,     0,    19,     0,    20,     0,
      21,     0,     0,     0,     0,     0,    22,    23,    24,    25,
       0,     0,    26,    27,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,     0,    31,     0,    32,     0,     0,
       0,    33,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,    40,     0,    41,     0,     0,    42,     1,     2,     0,
       0,     0,     0,     0,     3,     4,     5,     0,     6,     7,
      43,     8,     9,    10,     0,     0,    11,    12,    13,    14,
      15,     0,     0,    16,     0,    17,     0,     0,     0,    18,
       0,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,    22,    23,    24,    25,     0,     0,    26,    27,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,     0,
      31,     0,    32,     0,     0,     0,    33,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,    39,    40,     0,    41,     0,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    43
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,   370,   227,   173,   299,     3,     7,     5,     8,    23,
     207,    11,    12,    13,   371,    23,    40,    41,    42,   226,
     227,    48,    22,    23,     3,     4,    26,    27,     0,   615,
      62,   617,    62,    33,    34,    35,     3,     7,     5,     3,
       4,     3,     4,     7,    29,   687,     7,     0,   690,    62,
      62,   129,   129,    57,    58,    59,    60,    61,    62,   137,
     137,   139,    47,     5,     6,     8,     9,   129,    29,   138,
      57,    58,    59,    60,    61,    62,   137,   139,   139,     8,
       9,    42,    57,    58,    59,    60,    61,    62,   383,   384,
     138,    60,    61,    62,    63,    78,    75,   137,    68,   139,
      63,    84,   138,   135,     7,   135,   623,   624,   135,   306,
     307,   138,   196,   197,    57,    58,    59,    60,    61,    62,
      63,   135,   135,   135,     5,   129,    29,   135,    57,    58,
      59,    60,    61,    62,    63,   139,   137,    40,   140,   496,
     138,   498,   129,   143,   501,   129,    88,    89,    90,   128,
     137,    29,   139,   522,   129,   139,   138,    35,   158,   128,
     129,   130,   131,   132,   128,   751,   128,   130,   131,   132,
     687,   138,   129,   690,   174,   175,    65,     5,     6,   263,
     180,   265,   139,     7,   184,   128,   129,   130,   131,   132,
       0,   137,     0,   139,   137,   195,   196,   197,     8,   128,
     129,   130,   131,   132,   204,    29,   129,   207,   137,    62,
     210,   211,    22,    23,    38,   129,   139,   217,   242,   243,
     244,   245,    62,    63,    34,   139,   226,   227,    63,   138,
     525,   526,    61,    62,    63,   207,   138,   237,   238,   239,
     240,   241,   129,    57,    58,    59,    60,    61,    62,    63,
     137,   137,   139,   139,   207,   138,   256,   257,   258,   259,
       7,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   137,   129,   139,   632,   276,   277,   278,   279,
     280,   281,   282,   139,    15,     5,     6,    18,   128,   129,
     130,   131,   132,   128,   129,   130,   131,   132,    29,   128,
     129,   130,   131,   132,     5,     6,   306,   307,   478,   479,
      62,   129,   129,   313,   128,   129,   130,   131,   132,   137,
     137,   139,   139,   520,   137,   129,   139,   129,   328,   329,
     129,   688,   129,   143,   306,   307,   336,   139,   338,   137,
     139,   139,   139,   138,   344,   345,   346,   347,   348,   349,
     129,   646,   135,   306,   307,   580,   129,   357,   583,   129,
     139,   129,   362,    62,   174,   175,   139,   129,   129,   139,
     370,   139,   129,   580,   184,    62,   583,   139,   139,    29,
      30,   129,   139,   129,   139,   195,   196,   197,     8,     9,
     362,   139,   129,   139,   204,   129,   753,   207,   370,   139,
     210,   598,   139,   129,   129,   139,   129,   217,   129,   362,
     129,   137,   137,   129,   137,   129,   137,   370,   137,    32,
     137,   137,   139,   137,   137,   129,   139,   237,   238,   239,
     240,   241,   639,   137,   137,   135,   139,    57,    58,    59,
      60,    61,    62,    63,     5,     6,   256,   257,   258,   259,
     138,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   137,   137,   139,   139,   276,   277,   278,   279,
     280,   281,   282,     5,     6,     5,     6,     5,     6,     5,
       6,   481,   482,     5,     6,   138,   486,     8,     9,     5,
       6,     0,   138,   493,   136,   137,   306,   307,     5,     6,
       5,     6,    58,   313,    60,    61,    62,    63,   128,   129,
     130,   131,   132,    22,     5,     6,   138,   137,   137,   139,
     520,   138,   522,    68,    69,    34,    68,    69,   338,    72,
      73,     5,     6,   138,   344,   138,    57,    58,    59,    60,
      61,    62,    63,     0,   138,   138,   138,   357,   520,   138,
     522,   138,   362,   138,   138,   555,   138,   557,   138,   138,
     370,   768,   138,   138,   138,    22,    23,   520,   138,   522,
     138,   571,   128,   129,   130,   131,   132,    34,   138,   138,
     580,   581,    48,   583,   584,   138,   586,   138,   138,   138,
     590,   591,   138,   140,   138,   135,   793,   138,   598,   796,
     138,   138,     8,     9,   138,   138,   135,   128,   129,   130,
     131,   132,   135,   138,   138,   615,   137,   617,   139,   816,
     817,   138,   137,   820,   138,   138,   598,   138,   138,     5,
     138,    23,   138,    23,   138,   138,   138,   637,   638,   639,
     138,   138,   138,   138,   138,   598,   138,   137,   137,   819,
     137,    57,    58,    59,    60,    61,    62,    63,   137,   137,
     137,    63,     5,   135,   137,   174,   175,   137,   135,     7,
     135,   481,   482,   137,   137,   137,   486,   135,    44,   138,
     135,   137,   682,   493,   138,   138,   195,   196,   197,   689,
     138,   138,   138,   138,   138,     5,   139,   139,   207,   137,
     137,     5,   211,   139,   139,   139,   138,   138,   138,     7,
     520,   139,   522,   139,   139,   139,     3,   174,   175,   138,
     138,    62,   128,   129,   130,   131,   132,    62,   728,    62,
     135,   137,   732,   139,   734,    46,     7,   737,   195,   196,
     197,    71,    45,    62,   362,   555,   630,   557,   695,   344,
     207,   751,    22,    22,   263,   594,   265,   481,   227,   768,
     482,   571,   785,   830,   764,   765,   339,   767,   768,   155,
     624,   581,    31,    -1,   584,    -1,   586,    -1,    -1,    -1,
     590,   591,    -1,    -1,    -1,    -1,    -1,    -1,   598,    -1,
      -1,    -1,    -1,   793,    -1,    -1,   796,   306,   307,    -1,
      -1,    -1,    -1,    -1,    -1,   615,   263,   617,   265,    -1,
     810,    -1,    -1,    -1,    -1,    -1,   816,   817,    -1,    -1,
     820,   793,    -1,     6,   796,     8,    -1,   637,   638,    -1,
      -1,    -1,    -1,   833,    -1,   344,    -1,    -1,    -1,    -1,
     793,    -1,    -1,   796,   816,   817,     8,     9,   820,   306,
     307,    -1,    -1,   362,    -1,    -1,   313,    -1,    -1,    -1,
      -1,   370,    -1,   816,   817,    -1,    -1,   820,    -1,    -1,
      -1,    -1,   682,    58,    59,    60,    61,    62,    63,   689,
      -1,     8,     9,    -1,    -1,    -1,    -1,   344,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,   362,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,   728,    -1,
      -1,    -1,   732,    -1,   734,    -1,    -1,   737,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,   751,    -1,   128,   129,   130,   131,   132,    -1,   132,
      -1,    -1,    -1,    -1,   764,   765,    -1,   767,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,   481,   482,    -1,   137,    -1,   139,    -1,    -1,
      -1,    -1,    -1,   793,   493,    -1,   796,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,
     810,   128,   129,   130,   131,   132,   816,   817,    -1,    -1,
     820,   520,   139,   522,    -1,    -1,     4,     5,     6,    -1,
      -1,   204,    -1,    -1,   481,   482,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    21,   217,    -1,   493,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,   520,    -1,   522,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,   261,   262,
      -1,   264,    -1,   266,   267,   268,   269,   270,   271,   598,
      -1,    -1,    -1,   276,   277,   278,   279,   280,   281,   282,
      88,    89,    90,    91,    92,    -1,   615,    -1,   617,    -1,
     128,   129,   130,   131,   132,   298,   299,     8,     9,   137,
     108,   109,    -1,    -1,    -1,    -1,   114,   115,   116,   117,
     639,   119,    -1,   121,    -1,   123,   124,   125,    -1,    -1,
      -1,   598,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,   338,     8,     9,   615,   342,
     617,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,   357,     8,     9,    -1,    -1,    -1,
     689,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
     383,   384,     8,     9,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,   689,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,   751,    -1,    -1,    -1,   137,    -1,   139,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,   768,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,   793,   137,    -1,   796,    -1,    -1,
      -1,    -1,    -1,    -1,   751,   128,   129,   130,   131,   132,
      -1,    -1,    -1,   486,    -1,   488,   139,   816,   817,    -1,
      -1,   820,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   793,    -1,    -1,   796,
      -1,    -1,   525,   526,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   816,
     817,    -1,    -1,   820,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   555,    -1,   557,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   571,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,   584,    -1,   586,    -1,    -1,    -1,   590,   591,    -1,
      -1,   594,   204,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,   227,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,   237,   238,   239,   240,   241,
      -1,    -1,     8,     9,   637,   638,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   646,   256,   257,   258,   259,    -1,   261,
     262,    -1,   264,    -1,   266,   267,   268,   269,   270,   271,
      -1,    -1,    -1,    -1,   276,   277,   278,   279,   280,   281,
     282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   682,
      -1,    57,    58,    59,    60,    61,    62,    63,     8,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,     8,     9,
      -1,    -1,    -1,    -1,    -1,   728,   338,    -1,    -1,   732,
      -1,   734,    -1,    -1,   737,     8,     9,    57,    58,    59,
      60,    61,    62,    63,    -1,   357,    -1,     8,     9,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   764,   765,   139,   767,    64,    -1,    57,    58,    59,
      60,    61,    62,    63,     8,     9,    -1,    -1,    -1,    78,
      -1,    -1,   785,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,   810,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,   130,   131,   132,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   128,   129,   130,
     131,   132,    -1,    -1,   486,    -1,    -1,    -1,   139,    -1,
      -1,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,   198,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
     209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,
      -1,   220,   221,    -1,   223,    -1,    -1,    -1,    -1,   228,
     229,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,    -1,   555,    -1,   557,    -1,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,    -1,    -1,   571,
      -1,   260,    -1,    -1,    -1,    -1,     8,     9,   580,   581,
      -1,   583,   584,    -1,   586,    -1,    -1,    -1,   590,   591,
      -1,    -1,    -1,    -1,     8,     9,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,    -1,   298,
     299,    -1,    -1,    -1,    -1,    -1,   305,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,   637,   638,   639,    -1,    -1,
      -1,    -1,   331,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,
     359,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
     682,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   383,   384,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,     8,     9,   139,   728,    -1,    -1,    -1,
     732,    -1,   734,    -1,    -1,   737,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     449,   450,   764,   765,    -1,   767,   768,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   488,
      -1,   490,    -1,    -1,    -1,    -1,    -1,    -1,   810,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   510,   511,   512,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,   525,   526,    -1,    -1,
     529,   530,   531,   128,   129,   130,   131,   132,    -1,    -1,
     539,   540,    -1,    -1,   139,    -1,    -1,    -1,    -1,   548,
     549,   550,   551,   552,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,     8,     9,    -1,    -1,   566,    -1,    -1,
     569,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,    -1,   594,    -1,    -1,   597,    -1,
     139,   600,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,   646,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    -1,    -1,   128,   129,   130,   131,   132,    -1,   138,
      -1,   140,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
     699,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,   725,    -1,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   741,    -1,   743,    -1,   745,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   785,    -1,    -1,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,   805,    97,    98,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,    -1,    97,    98,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     8,     9,   128,
     129,   130,   131,   132,    -1,   138,    -1,    -1,    -1,    -1,
     139,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,     8,     9,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   128,   129,   130,   131,   132,     8,     9,    -1,    -1,
      -1,    -1,   139,   128,   129,   130,   131,   132,     8,     9,
      -1,    -1,    -1,    -1,   139,   128,   129,   130,   131,   132,
       8,     9,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,     8,     9,
      -1,    -1,    -1,    -1,   139,    57,    58,    59,    60,    61,
      62,    63,     8,     9,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   128,   129,
     130,   131,   132,    -1,    -1,     8,     9,    -1,    -1,   139,
     128,   129,   130,   131,   132,    -1,    -1,     8,     9,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,     8,     9,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   128,   129,   130,   131,   132,     8,     9,    -1,
      -1,    -1,    -1,   139,    57,    58,    59,    60,    61,    62,
      63,     8,     9,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   128,   129,   130,
     131,   132,    -1,    -1,     8,     9,    -1,    -1,   139,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,     8,     9,
      -1,    -1,    -1,    -1,   139,    -1,    -1,   128,   129,   130,
     131,   132,     8,     9,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   128,   129,   130,   131,   132,     8,     9,    -1,    -1,
      -1,    -1,   139,    57,    58,    59,    60,    61,    62,    63,
       8,     9,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,    -1,     8,     9,    -1,   139,
      -1,    -1,   128,   129,   130,   131,   132,     7,     8,     9,
      -1,    -1,    -1,   139,    -1,    -1,   128,   129,   130,   131,
     132,     8,     9,    -1,    -1,   137,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
       8,     9,    -1,    -1,    44,    57,    58,    59,    60,    61,
      62,    63,    -1,     8,     9,    67,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    34,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    36,    -1,    -1,    -1,     8,     9,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,     8,     9,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    44,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    57,    58,    59,    60,    61,    62,
      63,   128,   129,   130,   131,   132,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    16,    17,    -1,    19,    20,    21,    -1,
      -1,    24,    25,    26,    27,    28,    -1,    -1,    31,    -1,
      33,    -1,    -1,    -1,    37,    -1,    39,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,    -1,
      93,    94,    -1,    96,    -1,    -1,    99,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    -1,    16,    17,
     113,    19,    20,    21,    -1,    -1,    24,    25,    26,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    37,
      -1,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    93,    94,    -1,    96,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  parser::yystos_[] =
  {
         0,     5,     6,    12,    13,    14,    16,    17,    19,    20,
      21,    24,    25,    26,    27,    28,    31,    33,    37,    39,
      41,    43,    49,    50,    51,    52,    55,    56,    64,    65,
      66,    68,    70,    74,    76,    77,    88,    89,    90,    93,
      94,    96,    99,   113,   142,   143,   144,   146,   147,   164,
     165,   181,   182,   183,   184,   187,   188,   202,   210,   221,
     226,   232,   237,   241,   246,   263,   269,   270,   271,   272,
     273,   275,   138,   138,     3,     4,     8,     9,    10,    11,
      20,    21,    53,    54,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    95,
      97,    98,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   138,   167,   168,   170,   175,   181,   183,   269,
     270,   272,   273,   138,   167,   269,   270,   271,   138,   138,
       5,   269,   269,   269,   152,   153,   167,   170,   203,   227,
     233,   222,     5,     6,   164,   165,   269,   270,   273,     5,
       6,   180,   269,   273,   148,   149,   262,   269,   261,   269,
     140,   259,   150,    65,   268,   211,   269,   161,   162,   269,
     270,   272,   273,   163,   269,   138,   138,   138,   140,   170,
     177,   177,   177,   177,   138,     0,    29,    30,     7,    62,
      62,   189,   170,    62,   135,   135,   135,    62,   139,   139,
     138,   138,   170,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   170,   170,   167,   170,    57,    58,    59,    60,
      61,    62,   129,     8,     9,    57,    58,    59,    60,    61,
      62,    63,   128,   129,   130,   131,   132,   167,   154,   155,
     135,    32,   260,   260,   269,   228,   234,   223,   138,   138,
     135,    48,   179,   137,   135,   179,   196,   197,   269,   270,
     272,   273,   198,   199,   269,   270,   272,   273,   137,   137,
       3,   138,   269,   167,   170,   252,   140,   253,   254,   151,
     269,   270,   212,   156,   137,    23,    23,    23,    23,   137,
     166,   269,   272,   273,   166,   166,   170,   137,   137,   137,
     167,   144,   145,   170,   167,     6,   195,   269,   272,   238,
     242,   244,   170,     5,     6,     5,     6,     5,     6,   167,
     170,   170,   170,   176,   169,     5,     6,   173,   174,   269,
     271,   275,   173,   174,   170,   170,   139,   170,   170,   170,
     170,   170,   170,   170,   167,   167,   167,   167,   167,   167,
     177,   177,   177,   177,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   167,   167,   167,   167,   170,   167,
     167,   166,   167,   166,   167,   167,   167,   167,   167,   167,
     139,   139,   167,   167,   167,   167,   167,   167,   167,   172,
     171,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   167,   170,   185,   186,   185,     5,    62,
     170,   144,   144,     5,     6,    78,    84,   178,     5,   273,
       6,   137,   137,   269,   269,   170,    67,   136,   137,     3,
     138,   269,   167,   258,   253,   135,   264,   135,   265,   167,
     170,   215,     7,   214,   162,   269,   269,   269,   269,   269,
     137,   137,   137,   167,   170,   170,   139,   146,   190,   135,
      44,   147,   214,   138,   138,   138,   138,   138,   138,   137,
     137,   137,   185,   185,   138,   138,   139,   139,   135,   137,
     137,   139,   139,   139,   139,   139,   139,   139,   137,   137,
     137,   137,   137,   139,   139,   137,   139,   137,   139,   139,
     139,   139,   139,   139,   139,   139,   137,   139,   139,   137,
     139,   137,   139,   139,   139,   139,   139,   139,   139,   139,
     137,   137,   139,   137,   137,   139,   137,   139,   139,   139,
     137,   137,   170,   170,   137,   139,   139,   204,   229,    29,
      40,   235,    29,    42,   224,   138,   138,   179,   179,   197,
     199,   139,   167,   167,   170,   256,   170,   255,   251,   269,
     270,   272,   273,   214,   214,   214,     3,     4,     7,   128,
     157,   158,   159,   160,   170,   170,   170,   137,   137,   138,
       6,   144,   243,   147,   139,   139,   274,   185,   185,   139,
     139,   170,   170,   170,   139,   139,     5,     6,   170,   170,
     170,   170,   170,   170,   170,   167,   167,   170,   170,   167,
     174,   167,   174,   167,   167,   167,   167,   186,   170,   144,
     170,   225,    67,   251,   139,   251,   263,   266,   267,   268,
     266,   216,     3,    75,   158,   137,   214,   139,   139,   137,
     139,   167,   167,     6,   200,   201,   269,   271,   272,   275,
     239,   185,   139,   139,   139,   139,   139,   138,   138,   139,
     139,   139,   139,   139,   139,   137,   139,   139,   137,   139,
     139,   139,   137,   139,   137,   139,   139,   137,   139,   139,
     139,   137,   139,   137,   139,    34,    29,    38,   230,   236,
     167,   257,    69,   267,   214,   269,   270,   272,   273,    69,
      72,    73,   218,   160,    62,    62,   170,    62,   137,   139,
     135,    46,   248,   139,   170,   167,   167,   167,   167,   170,
     170,   170,   231,   251,   214,   217,     7,    71,   167,   167,
     139,   167,   201,   191,     6,   170,    45,   247,   139,   139,
     139,   139,   139,   139,   139,    36,   209,   215,   219,   213,
      62,   144,    44,   144,   240,   170,   205,   220,   167,   192,
     249,    29,    47,   245,   144,   144,   179,   144,   206,   193,
     250,    29,    35,   207,    15,    18,    29,   194,   248,   208,
     269
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
     375,   376,   377,   378,   379,   380,   381,   382,    45,    43,
      42,    47,   383,   384,   385,    46,    59,    44,    40,    41,
      35
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  parser::yyr1_[] =
  {
         0,   141,   142,   143,   143,   144,   145,   144,   146,   146,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   148,   147,   149,
     147,   147,   147,   147,   150,   147,   151,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     152,   147,   153,   147,   147,   147,   147,   147,   147,   147,
     147,   154,   147,   155,   147,   156,   147,   147,   147,   157,
     157,   158,   159,   159,   160,   160,   160,   161,   161,   162,
     162,   162,   162,   163,   163,   164,   164,   165,   165,   165,
     165,   165,   165,   166,   166,   167,   167,   167,   167,   167,
     167,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   169,   168,   171,   170,   172,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     173,   174,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   176,   175,   177,   177,   178,   178,   179,
     179,   180,   180,   180,   180,   181,   181,   182,   183,   183,
     184,   185,   185,   186,   186,   187,   187,   189,   190,   191,
     192,   193,   188,   194,   194,   194,   195,   195,   196,   196,
     197,   197,   197,   197,   198,   198,   199,   199,   199,   199,
     200,   200,   200,   201,   201,   201,   201,   203,   204,   205,
     206,   202,   207,   207,   208,   208,   209,   209,   211,   212,
     213,   210,   214,   214,   215,   215,   216,   217,   216,   218,
     219,   220,   218,   222,   223,   221,   224,   225,   224,   227,
     228,   229,   226,   230,   231,   230,   233,   234,   232,   235,
     236,   235,   238,   239,   240,   237,   242,   243,   241,   244,
     241,   245,   245,   246,   247,   247,   248,   249,   250,   248,
     251,   251,   251,   251,   252,   252,   252,   252,   252,   252,
     252,   254,   253,   255,   253,   256,   253,   257,   253,   258,
     259,   259,   259,   259,   260,   261,   261,   262,   262,   264,
     263,   265,   263,   266,   266,   267,   267,   267,   267,   267,
     268,   269,   269,   270,   270,   270,   270,   271,   271,   271,
     271,   272,   272,   273,   273,   273,   274,   273,   275,   275,
     275,   275
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
  "tSTRSYM", "tSEPARATOR", "tAND", "tOR", "tNOT", "tEOR", "tBREAK",
  "tCONTINUE", "tSUB", "tENDSUB", "tRETURN", "tFUNCTION", "tENDFUNCTION",
  "tCOMPILE", "tEXECUTERETURNNUMBER", "tEXECUTERETURNSTRING", "tCSUB",
  "tFROM", "tGOTO", "tGOSUB", "tLABEL", "tENABLE", "tDISABLE", "tEOPROG",
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
  "exprtype", "dim_as_type", "dim_list",
  "number_function_or_array_any_params",
  "number_function_or_array_with_params",
  "string_function_or_array_any_params",
  "string_function_or_array_with_params", "call_list", "call_item",
  "begin_sub", "function_definition", "$@15", "$@16", "$@17", "$@18",
  "$@19", "endsub", "function_name", "local_list", "local_item",
  "static_list", "static_item", "param_list", "param_item", "for_loop",
  "$@20", "$@21", "$@22", "$@23", "next", "next_symbol", "step_part",
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
       142,     0,    -1,   143,    29,    -1,   144,    -1,   143,    30,
     144,    -1,   146,    -1,    -1,   144,     7,   145,   146,    -1,
      -1,   147,    -1,   164,    -1,   165,    -1,    49,   164,    -1,
      49,   165,    -1,   237,    -1,   241,    -1,   221,    -1,   202,
      -1,   232,    -1,   226,    -1,   210,    -1,    12,    -1,    13,
      -1,   188,    -1,   263,    -1,   181,    -1,   183,    -1,    -1,
      51,   148,   196,    -1,    -1,    52,   149,   198,    -1,    64,
     259,   252,    -1,    64,   259,   252,   136,    -1,    64,   259,
     252,   137,    -1,    -1,    65,   150,   253,    -1,    -1,    66,
      65,   151,   253,    -1,    16,    -1,    16,   170,    -1,    16,
     167,    -1,    50,   180,    -1,   113,   138,   167,   139,    -1,
      31,    -1,    31,   170,    -1,    93,   177,   137,   167,    -1,
      93,   177,   137,   167,   137,   167,    -1,    94,   177,    -1,
      96,   177,   137,   170,    -1,    96,   177,   137,   170,   137,
     167,    -1,    -1,    27,   152,   260,    -1,    -1,    28,   153,
     260,    -1,    56,   261,    -1,    55,   262,    -1,    24,   269,
      -1,    25,   269,    -1,    26,   269,    -1,    99,   177,   137,
     170,    -1,    19,   167,    -1,    -1,    20,   138,   154,   185,
     139,    -1,    -1,    21,   138,   155,   185,   139,    -1,    -1,
      74,   269,   156,   214,   157,    75,    -1,    76,   161,    -1,
      77,   163,    -1,   158,    -1,   157,   158,    -1,   159,   214,
      -1,   160,    -1,   159,   137,   160,    -1,     3,    -1,   128,
       3,    -1,     4,    -1,   162,    -1,   161,   137,   162,    -1,
     269,    23,   269,    -1,   272,    23,   269,    -1,   270,    23,
     269,    -1,   273,    23,   269,    -1,   269,    -1,   163,   137,
     269,    -1,   269,    62,   170,    -1,   182,    62,   170,    -1,
     272,    62,   167,    -1,    90,   138,   166,   137,   170,   137,
     170,   139,    62,   167,    -1,    90,   138,   166,   137,   170,
     139,    62,   167,    -1,    88,   138,   166,   137,   170,   139,
      62,   167,    -1,    89,   138,   166,   137,   170,   139,    62,
     167,    -1,   184,    62,   167,    -1,   272,    -1,   273,    -1,
     272,    -1,   168,    -1,   183,    -1,     4,    -1,   167,   129,
     167,    -1,   138,   167,   139,    -1,    88,   138,   167,   137,
     170,   139,    -1,    89,   138,   167,   137,   170,   139,    -1,
      90,   138,   167,   137,   170,   137,   170,   139,    -1,    90,
     138,   167,   137,   170,   139,    -1,   108,   138,   170,   139,
      -1,   108,   138,   170,   137,   167,   139,    -1,   108,   138,
     170,   137,   167,   137,   167,   139,    -1,   109,   138,   170,
     139,    -1,    91,   138,   167,   139,    -1,    92,   138,   167,
     139,    -1,   124,   138,   167,   139,    -1,   125,   138,   167,
     139,    -1,   123,   138,   167,   139,    -1,   119,   138,   166,
     137,   167,   139,    -1,   119,   138,   166,   139,    -1,   121,
     138,   166,   137,   167,   139,    -1,   121,   138,   166,   139,
      -1,   117,    -1,   116,    -1,   114,   138,   170,   139,    -1,
     115,   138,   167,   139,    -1,    -1,    21,   138,   169,   185,
     139,    -1,    -1,   170,     9,   171,   170,    -1,    -1,   170,
       8,   172,   170,    -1,    10,   170,    -1,   170,    62,   170,
      -1,   170,    57,   170,    -1,   170,    60,   170,    -1,   170,
      58,   170,    -1,   170,    61,   170,    -1,   170,    59,   170,
      -1,    95,   138,   177,   139,    -1,   122,   138,   167,   137,
     167,   139,    -1,    53,   138,   173,   139,    -1,    53,   138,
     174,   139,    -1,    54,   138,   173,   137,   170,   139,    -1,
      54,   138,   174,   137,   170,   139,    -1,   181,    -1,   167,
      62,   167,    -1,   167,    57,   167,    -1,   167,    60,   167,
      -1,   167,    58,   167,    -1,   167,    61,   167,    -1,   167,
      59,   167,    -1,   175,    -1,   170,   132,   170,    -1,   170,
      63,   170,    -1,   129,   170,    -1,   128,   170,    -1,   170,
     130,   170,    -1,   170,   131,   170,    -1,   170,   128,   170,
      -1,   170,   129,   170,    -1,   138,   170,   139,    -1,   269,
      -1,     3,    -1,   271,    -1,   275,    -1,   100,   138,   170,
     139,    -1,   101,   138,   170,   139,    -1,   102,   138,   170,
     139,    -1,   103,   138,   170,   139,    -1,   104,   138,   170,
     139,    -1,   105,   138,   170,   139,    -1,   105,   138,   170,
     137,   170,   139,    -1,   106,   138,   170,   139,    -1,   107,
     138,   170,   139,    -1,   107,   138,   170,   137,   170,   139,
      -1,    84,   138,   170,   139,    -1,    82,   138,   170,   139,
      -1,    83,   138,   170,   139,    -1,    85,   138,   170,   139,
      -1,    79,   138,   170,   139,    -1,    80,   138,   170,   139,
      -1,    81,   138,   170,   139,    -1,    81,   138,   139,    -1,
      86,   138,   170,   137,   170,   139,    -1,    87,   138,   170,
     137,   170,   139,    -1,   112,   138,   167,   139,    -1,   110,
     138,   167,   139,    -1,   111,   138,   167,   139,    -1,   126,
     138,   167,   137,   167,   139,    -1,   126,   138,   167,   137,
     167,   137,   170,   139,    -1,   127,   138,   167,   137,   167,
     139,    -1,   127,   138,   167,   137,   167,   137,   170,   139,
      -1,   113,   138,   167,   139,    -1,     8,   138,   170,   137,
     170,   139,    -1,     9,   138,   170,   137,   170,   139,    -1,
      11,   138,   170,   137,   170,   139,    -1,   118,   138,   167,
     137,   174,   137,   167,   139,    -1,   118,   138,   167,   137,
     174,   139,    -1,   120,   138,   167,   137,   174,   137,   167,
     139,    -1,   120,   138,   167,   137,   174,   139,    -1,    93,
     138,   167,   139,    -1,    93,   138,   167,   137,   167,   139,
      -1,    93,   138,   177,   137,   167,   139,    -1,    93,   138,
     177,   137,   167,   137,   167,   139,    -1,    97,   138,   177,
     139,    -1,    98,   138,   177,   139,    -1,    -1,    20,   138,
     176,   185,   139,    -1,   140,   170,    -1,   170,    -1,    78,
      -1,    84,    -1,    -1,    48,   178,    -1,     5,   179,    -1,
     273,   179,    -1,   180,   137,     5,   179,    -1,   180,   137,
     273,   179,    -1,   270,    -1,   271,    -1,   270,    -1,   273,
      -1,   275,    -1,   273,    -1,   186,    -1,   185,   137,   186,
      -1,   167,    -1,   170,    -1,    14,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   189,   195,   190,   138,   200,
     139,   191,   144,   192,   179,   193,   194,    -1,    29,    -1,
      15,    -1,    18,    -1,   269,    -1,   272,    -1,   197,    -1,
     196,   137,   197,    -1,   269,    -1,   272,    -1,   270,    -1,
     273,    -1,   199,    -1,   198,   137,   199,    -1,   269,    -1,
     272,    -1,   270,    -1,   273,    -1,    -1,   201,    -1,   200,
     137,   201,    -1,   269,    -1,   272,    -1,   271,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    33,   203,   269,    62,   204,
     170,    34,   170,   209,   205,   144,   206,   207,   208,    -1,
      29,    -1,    35,    -1,    -1,   269,    -1,    -1,    36,   170,
      -1,    -1,    -1,    -1,    70,   211,   212,   215,   214,   216,
     218,    71,   213,    -1,     7,    -1,   214,     7,    -1,   170,
      -1,   167,    -1,    -1,    -1,   216,    72,   217,   215,    -1,
      -1,    -1,    -1,    73,     7,   219,   220,   144,    -1,    -1,
      -1,    41,   222,   223,   144,   224,    -1,    29,    -1,    -1,
      42,   225,    -1,    -1,    -1,    -1,    37,   227,   228,   170,
     229,   144,   230,    -1,    29,    -1,    -1,    38,   231,    -1,
      -1,    -1,    39,   233,   234,   144,   235,    -1,    29,    -1,
      -1,    40,   170,   236,    -1,    -1,    -1,    -1,   246,   170,
     238,    44,   144,   239,   248,   247,   240,   245,    -1,    -1,
      -1,   246,   170,   242,   147,   243,    -1,    -1,   246,   170,
     244,   214,   147,    -1,    29,    -1,    47,    -1,    43,    -1,
      -1,    45,   144,    -1,    -1,    -1,    -1,    46,   170,    44,
     249,   144,   250,   248,    -1,   269,    -1,   272,    -1,   270,
      -1,   273,    -1,    -1,   170,    -1,   170,    67,   167,    -1,
     167,    -1,   252,   137,   170,    -1,   252,   137,   170,    67,
     167,    -1,   252,   137,   167,    -1,    -1,   254,   258,   251,
      -1,    -1,   140,   269,   255,   251,    -1,    -1,   140,     3,
     256,   251,    -1,    -1,   140,   138,   170,   139,   257,   251,
      -1,   167,    -1,    -1,   140,   269,    -1,   140,     3,    -1,
     140,   138,   170,   139,    -1,    32,    -1,   269,    -1,   261,
     137,   269,    -1,   269,    -1,   262,   137,   269,    -1,    -1,
      68,   268,   269,   264,   214,   266,    69,    -1,    -1,    68,
     268,   270,   265,   214,   266,    69,    -1,   267,   214,    -1,
     266,   267,   214,    -1,   263,    -1,   268,   269,    -1,   268,
     272,    -1,   268,   270,    -1,   268,   273,    -1,    -1,     5,
      -1,   269,   135,     5,    -1,     5,   138,    -1,   270,   135,
       5,   138,   185,   139,    -1,   270,   135,     5,    -1,   269,
     135,     5,   138,    -1,     5,   138,   139,    -1,   271,   135,
       5,   138,   139,    -1,   271,   135,     5,    -1,   269,   135,
       5,   138,   139,    -1,     6,    -1,   269,   135,     6,    -1,
       6,   138,    -1,   270,   135,     6,   138,   185,   139,    -1,
     270,   135,     6,    -1,    -1,   269,   135,     6,   138,   274,
     185,   139,    -1,     6,   138,   139,    -1,   271,   135,     6,
     138,   139,    -1,   271,   135,     6,    -1,   269,   135,     6,
     138,   139,    -1
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
         0,   190,   190,   205,   206,   209,   210,   210,   219,   220,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   238,   244,   245,   246,   247,   248,   248,   249,
     249,   250,   258,   263,   268,   268,   269,   269,   270,   273,
     278,   279,   284,   287,   288,   289,   290,   291,   292,   293,
     294,   294,   295,   295,   296,   297,   298,   301,   302,   305,
     306,   307,   307,   310,   310,   311,   311,   312,   313,   316,
     317,   320,   323,   324,   327,   328,   329,   332,   333,   336,
     337,   338,   339,   342,   343,   346,   351,   354,   355,   356,
     357,   358,   359,   364,   365,   368,   369,   370,   371,   372,
     373,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   397,   400,   400,   401,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   428,   433,   436,   439,   443,   447,   448,   452,
     457,   460,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   504,   507,   508,   511,   514,   520,
     521,   529,   536,   537,   542,   545,   546,   549,   552,   553,
     556,   559,   560,   563,   564,   567,   568,   571,   575,   578,
     581,   582,   571,   591,   597,   598,   601,   602,   605,   606,
     609,   610,   611,   612,   615,   616,   619,   620,   621,   622,
     625,   626,   627,   630,   631,   634,   637,   642,   643,   647,
     649,   642,   655,   660,   663,   664,   667,   668,   671,   671,
     673,   671,   678,   679,   682,   683,   686,   687,   687,   695,
     696,   696,   696,   702,   702,   702,   707,   708,   708,   711,
     711,   712,   711,   718,   719,   719,   722,   722,   722,   727,
     729,   728,   732,   737,   739,   732,   743,   744,   743,   745,
     745,   749,   750,   753,   756,   757,   760,   762,   764,   761,
     768,   769,   770,   771,   774,   775,   780,   782,   784,   786,
     788,   792,   792,   793,   793,   794,   794,   795,   795,   798,
     802,   807,   808,   809,   812,   815,   816,   819,   820,   824,
     824,   840,   840,   858,   859,   862,   863,   871,   879,   887,
     897,   905,   909,   912,   914,   915,   916,   919,   922,   923,
     924,   927,   928,   931,   932,   933,   934,   934,   937,   938,
     939,   940
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
       2,     2,     2,     2,     2,   140,     2,     2,     2,     2,
     138,   139,   130,   129,   137,   128,   135,   131,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   136,
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
     125,   126,   127,   132,   133,   134
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 3485;
  const int parser::yynnts_ = 135;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 205;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 141;

  const unsigned int parser::yyuser_token_number_max_ = 385;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 22 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 4289 "/home/cai/projects/basic/compiler/parser.cpp"
