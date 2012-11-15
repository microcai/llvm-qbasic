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

extern	StatementsAST * program;


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
#line 196 "parser.ypp"
    {
			program = (yysemantic_stack_[(2) - (1)].statement_list);
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

  case 26:
/* Line 661 of lalr1.cc  */
#line 247 "parser.ypp"
    { }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 248 "parser.ypp"
    { }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 249 "parser.ypp"
    {if (function_type==ftNONE) debug("declaring variables \"local\" outside of a function has no effect"); }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 250 "parser.ypp"
    {if (function_type==ftNONE) debug("declaring variables \"static\" outside of a function has no effect"); }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 251 "parser.ypp"
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
#line 259 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 264 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 269 "parser.ypp"
    { until_eol = false; }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 269 "parser.ypp"
    {}
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 270 "parser.ypp"
    { until_eol = true; }
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 270 "parser.ypp"
    {}
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 271 "parser.ypp"
    {
	   
             }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 274 "parser.ypp"
    {

	   
   }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 279 "parser.ypp"
    { }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 280 "parser.ypp"
    {
	   debug("got syntax of \"dim local var\" now\n");

	   (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list);	   
	}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 285 "parser.ypp"
    {
	   
}
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
    {}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 295 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 296 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 299 "parser.ypp"
    {

   }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 302 "parser.ypp"
    {  }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 303 "parser.ypp"
    {
		debug("got label!\n");
   }
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
#line 308 "parser.ypp"
    {  }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 308 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 311 "parser.ypp"
    { }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 311 "parser.ypp"
    {  }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 312 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 328 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 330 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 337 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 338 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 339 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 340 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 343 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 344 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 347 "parser.ypp"
    {
		// 变量赋值
		debug("变量赋值\n");
		(yyval.number_assignment) = new NumberAssigmentAST(VariableRefExprASTPtr((yysemantic_stack_[(3) - (1)].varable_ref)), NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
	}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 352 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 355 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 356 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 358 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 359 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 360 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 366 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 369 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 371 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 373 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 377 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 381 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 382 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 389 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 390 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 414 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 415 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 419 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 420 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 421 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 422 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 425 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {
	   (yyval.number_expression) = (yysemantic_stack_[(2) - (2)].number_expression) ;
   }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 429 "parser.ypp"
    {
	   /*add_command(cNEGATE,NULL);*/
	   ConstNumberExprAST * zero = new ConstNumberExprAST(0);
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr(zero) ,OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression)));
   }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_MUL,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 437 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_DIV,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 440 "parser.ypp"
    {
	   // 减法计算
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 444 "parser.ypp"
    {
	   // 加法计算.
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_ADD,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 448 "parser.ypp"
    { (yyval.number_expression) = (yysemantic_stack_[(3) - (2)].number_expression) ;}
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 449 "parser.ypp"
    {
	   debug("got numsym_s\n");	   
	   (yyval.number_expression) =new NumberExprAST( VariableExprASTPtr((yysemantic_stack_[(1) - (1)].varable_ref)) );
	}
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 453 "parser.ypp"
    {
	   (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));
   }
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 458 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 461 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 464 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 465 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 466 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 467 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 468 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 469 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 470 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 471 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 472 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 473 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 474 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 475 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 476 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 477 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 478 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 479 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 480 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 481 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 482 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 483 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 484 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 487 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 488 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 489 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 491 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 492 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 495 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 496 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 497 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 498 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 499 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 500 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 502 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 503 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 504 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 505 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 205:
/* Line 661 of lalr1.cc  */
#line 505 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 512 "parser.ypp"
    {
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 515 "parser.ypp"
    {
		//TODO int should be 32bit not 64bit
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 522 "parser.ypp"
    {
			debug("as  %s\n",(yysemantic_stack_[(2) - (2)].exprtype)->name.c_str());
			// long varable
			// 构造类型
			(yyval.exprtype) = (yysemantic_stack_[(2) - (2)].exprtype);
		}
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 530 "parser.ypp"
    {
		/*变量定义*/
		// 在 AST 中分配一个变量名称列表.
		std::string name;
		name = (yysemantic_stack_[(2) - (1)].symbol);
		(yyval.dim_list) = new VariableDimAST( name , ExprTypeASTPtr((yysemantic_stack_[(2) - (2)].exprtype)));		
	}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 537 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 538 "parser.ypp"
    {
	  // 	std::string name;
	//	name = $3;
	//	$$ = new VariableDimAST( name , ExprTypeASTPtr($2));
   }
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 543 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 546 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 547 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 550 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 219:
/* Line 661 of lalr1.cc  */
#line 553 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 220:
/* Line 661 of lalr1.cc  */
#line 554 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 557 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 560 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 223:
/* Line 661 of lalr1.cc  */
#line 561 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 568 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 568 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
if (function_type!=ftNONE) {debug("functions cannot be nested");}}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 570 "parser.ypp"
    {
	   
}
    break;

  case 229:
/* Line 661 of lalr1.cc  */
#line 573 "parser.ypp"
    {
	   
}
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 577 "parser.ypp"
    {
	
   }
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 582 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 588 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 591 "parser.ypp"
    {
	//function_type=ftNUMBER;current_function = dotify ($1); $$ = dotify ($1);
	}
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 594 "parser.ypp"
    {/*function_type=ftSTRING;current_function = dotify ($1); $$ = dotify ($1);*/}
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 597 "parser.ypp"
    {
	
                      }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 600 "parser.ypp"
    {
						  
                      }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 603 "parser.ypp"
    {
						  
                      }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 606 "parser.ypp"
    {
						  
                      }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 611 "parser.ypp"
    {
//                    function_type = ftNUMBER;
//                    cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_NUMBER;
//                    current_function = mystrdup ($1);
//                    $$ = mystrdup ($1);
                }
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 617 "parser.ypp"
    {
//         function_type = ftSTRING;
//         cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_STRING;
//         current_function = mystrdup ($1);
//         $$ = mystrdup ($1);
     }
    break;

  case 244:
/* Line 661 of lalr1.cc  */
#line 630 "parser.ypp"
    {
//                          create_require (stNUMBER); create_makelocal (dotify ($1), syNUMBER); add_command (cPOPNUMSYM, dotify ($1));
                      }
    break;

  case 245:
/* Line 661 of lalr1.cc  */
#line 633 "parser.ypp"
    {
//         create_require (stSTRING); create_makelocal (dotify ($1), sySTRING); add_command (cPOPSTRSYM, dotify ($1));
     }
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 636 "parser.ypp"
    {
//         create_require (stNUMBERARRAYREF); create_arraylink (dotify ($1), stNUMBERARRAYREF);
     }
    break;

  case 247:
/* Line 661 of lalr1.cc  */
#line 639 "parser.ypp"
    {
//         create_require (stSTRINGARRAYREF); create_arraylink (dotify ($1), stSTRINGARRAYREF);
     }
    break;

  case 250:
/* Line 661 of lalr1.cc  */
#line 648 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 649 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 252:
/* Line 661 of lalr1.cc  */
#line 650 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 651 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 658 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 659 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 660 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 661 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 669 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 670 "parser.ypp"
    {
	   
}
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 673 "parser.ypp"
    {
	   
}
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 676 "parser.ypp"
    {
	   
}
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 681 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 682 "parser.ypp"
    {
				 
			}
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 686 "parser.ypp"
    {
	 }
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 688 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 690 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 694 "parser.ypp"
    {
		if (unclosed_fors) {
			debug ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 699 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 702 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 703 "parser.ypp"
    {  }
    break;

  case 276:
/* Line 661 of lalr1.cc  */
#line 706 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 710 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 710 "parser.ypp"
    {
	}
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 712 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 712 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 717 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 718 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 726 "parser.ypp"
    {
	   
}
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 729 "parser.ypp"
    {
		   
	}
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 735 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 735 "parser.ypp"
    {

	   
}
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 741 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 741 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 746 "parser.ypp"
    {if (unclosed_dos) { debug ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 747 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 747 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 750 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 750 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 751 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 757 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 758 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 758 "parser.ypp"
    { }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 761 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 761 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 766 "parser.ypp"
    {if (unclosed_repeats) { debug ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 768 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 768 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 771 "parser.ypp"
    {
				/*构造 IF 语句, 填充 条件表达式*/
				NumberExprASTPtr ne = NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression));

								
			}
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 776 "parser.ypp"
    {  /*填充真语句*/ }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 778 "parser.ypp"
    { /*填充假语句*/}
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 782 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 783 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 783 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 785 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 788 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 789 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 792 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 801 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 803 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 807 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 808 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 809 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 810 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 813 "parser.ypp"
    { debug("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 814 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 820 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 822 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 824 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 826 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 828 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 831 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 832 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 833 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 834 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 838 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 841 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 846 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 847 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 848 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 851 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 854 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 855 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 858 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 859 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 863 "parser.ypp"
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

  case 360:
/* Line 661 of lalr1.cc  */
#line 873 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 879 "parser.ypp"
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

  case 362:
/* Line 661 of lalr1.cc  */
#line 889 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 902 "parser.ypp"
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
#line 910 "parser.ypp"
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
#line 918 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 926 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 936 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 944 "parser.ypp"
    {
		debug("变量引用\n");
		(yyval.varable_ref) = new VariableRefExprAST( (yysemantic_stack_[(1) - (1)].symbol) );
	}
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 948 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 951 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 953 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 954 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 955 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 958 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 961 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 962 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 963 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 966 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 967 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 970 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 971 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 972 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 973 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 973 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 976 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 977 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 978 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 979 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2641 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const short int parser::yypact_ninf_ = -607;
  const short int
  parser::yypact_[] =
  {
      3424,   -97,   -53,  -607,  -607,  -607,  2240,    66,   -29,   -22,
    -607,    47,    47,    47,  -607,  -607,  2240,  -607,  -607,  -607,
    -607,  -607,    62,   127,  -607,  -607,    47,    47,   -48,  -607,
     106,  -607,  -607,    47,   232,    47,    10,    54,    60,  1824,
    1824,  1824,  1824,    77,   216,   419,   255,  -607,  -607,  -607,
    -607,  -607,   215,  -607,   280,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  2240,  -607,   -32,     5,   225,   325,
     328,  -607,   283,   287,  -607,  -607,  -607,   254,   291,  2240,
     327,   376,   383,   390,   414,   417,   423,   426,   429,   430,
     431,   432,   434,   435,   436,   438,   439,   440,   442,   445,
     446,   447,   448,   449,   452,   455,   457,   458,   459,   462,
     463,   468,   469,   475,   483,   484,   485,   486,   490,  -607,
    -607,   491,   492,   494,   495,   496,   497,   500,   502,   503,
     504,  2240,  2240,  2240,   248,  -607,  3208,  -607,  -607,  -607,
     319,   358,  -607,  -607,    66,   331,   319,   358,   225,  -607,
    -607,   481,  -607,   397,   397,   397,   525,   525,   248,  3208,
      47,  -607,  -607,  -607,   507,   508,  -607,  -607,     6,   358,
    -607,   -28,   508,   473,   521,   583,   232,   232,   506,   397,
     520,   397,    11,  2240,   522,  -607,   651,  -607,   397,   523,
    -607,     4,    42,   638,   640,   528,   397,   232,   232,   232,
    2240,  3208,   532,  -607,   534,   536,    66,  -607,  -607,  3424,
    -607,  2240,    66,  3063,  2240,   489,   493,   505,    66,  -607,
    -607,   481,  2240,  2240,   592,  2240,  -607,  -607,   510,   510,
    2240,  2240,  2067,  2240,  2240,  2240,  2240,  2240,  2240,    66,
      66,    66,    66,    66,  1824,  1824,  1824,  1824,  2240,  2240,
    2240,  2240,  2240,  2240,  2240,  2240,  2240,  2240,    66,    66,
      66,    66,  2240,    66,    66,   232,    66,   232,    66,    66,
      66,    66,    66,    66,   601,   601,   230,    37,    66,    66,
      66,    66,    66,    66,    66,  -607,  -607,  2240,  2240,  2240,
    2240,  2240,  2240,  2240,  2240,  2240,  2240,  2240,  2240,   -73,
    2240,  2240,  -607,  -607,   533,  -607,   667,  -607,  -607,  -607,
      24,  2240,  3424,  3424,  -607,  -607,   512,   -44,  -607,   516,
     518,  -607,   538,  -607,   541,   358,  -607,  -607,   540,  -607,
     541,   358,  -607,  -607,    47,    47,  -607,  2240,   397,   248,
    3071,   394,    26,  -607,    66,   522,   544,   545,  2240,   672,
     232,    47,    47,    47,    47,    47,   546,   541,  -607,  -607,
     547,   550,  3208,    66,  2240,  2240,   -46,   255,  3424,  3208,
     331,   644,  3424,   672,  3208,   551,   555,   556,   557,   559,
     561,   331,  -607,   533,  -607,    65,  1463,  2934,  2240,  2240,
     562,   563,   543,   565,   567,   225,  -607,   569,   570,  1225,
    1311,  -607,  1332,  1365,  1426,  1480,  1520,  2948,  2962,   -58,
      84,    87,    83,   199,   195,   571,   573,   575,   576,  1828,
    1961,  1974,  2001,  2244,   675,  2360,   808,   916,  2374,   200,
     211,   219,   233,  2386,   247,   238,   -84,   262,   -59,   282,
     259,   264,   265,   288,   321,  -607,  -607,   331,   331,   331,
     331,   331,   331,  -607,  2240,  2240,   375,   172,   488,   166,
     -11,   253,  -607,    75,    75,   601,   601,   601,   248,  3208,
      99,  -607,   139,   572,   527,  -607,  -607,  3208,   290,    48,
     578,   581,  -607,  -607,  -607,   -28,   583,   581,   232,   232,
     397,   397,  2398,    66,  -607,  2240,  -607,  2240,   397,   331,
     232,  -607,   702,   672,   718,   672,   248,  3208,   672,  -607,
      17,  -607,   397,   397,   397,   397,   397,  2240,  2240,  2240,
     322,  3043,  3208,  -607,  -607,  3424,  -607,  3334,   587,   588,
    2240,  2240,   590,   600,   593,  2240,  2240,  2240,   174,   212,
     283,   287,  -607,  -607,   529,  2240,  2240,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  2240,  2240,  2240,  2240,  2240,  -607,
    -607,    66,  -607,    66,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  2240,  -607,  -607,  2240,  -607,    66,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,   510,    66,  -607,   510,
      66,  -607,    66,  -607,  -607,  -607,    66,    66,   592,     1,
    2240,  -607,  -607,   531,  -607,  2240,  3424,  -607,  2240,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
     331,   248,  3085,   232,  2414,   232,  -607,   541,   358,  -607,
    -607,    23,    23,   731,  -607,  -607,  -607,   736,    33,  -607,
      -1,  -607,  2497,  2509,  1022,    66,    66,   255,  -607,  -607,
    -607,  -607,  2240,   234,   316,  -607,  -607,   531,  2521,  2537,
    2551,  -607,  -607,   604,   606,  2634,  2646,  2660,  2674,  2688,
    2771,  1198,   277,    80,  2783,  2797,   183,   340,   281,   341,
     284,   285,   194,   206,  -607,   563,   355,  -607,   610,   225,
    -607,  -607,  3101,    73,  3208,  -607,    66,  -607,  -607,  -607,
    -607,   472,   672,   232,   474,   487,  -607,  -607,  -607,    44,
     731,   684,   686,  2240,   688,   331,   331,   705,   371,  -607,
    -607,   372,  -607,   610,   225,  -607,  -607,  -607,  -607,  -607,
     587,   588,  -607,  -607,  -607,  -607,  -607,  -607,  2240,  -607,
    -607,    66,  -607,  -607,  -607,    66,  -607,    66,  -607,  -607,
      66,  -607,  -607,  -607,  2240,  -607,  2240,  -607,   531,  -607,
     537,  2240,  -607,  -607,  -607,  -607,   331,   232,  -607,   672,
     731,   541,   358,  -607,  -607,  -607,  -607,   744,   683,  -607,
      66,    66,  2811,    66,  2240,   711,  -607,   531,  -607,  2825,
     289,   301,   302,   318,  2908,  2920,  -607,   734,   606,  3186,
    -607,  -607,   731,  2240,  -607,  -607,   331,   331,   696,   331,
    3126,  3424,  -607,  -607,  3424,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,   753,  2240,  -607,  -607,  -607,  -607,    66,  -607,
     255,    59,    72,  -607,  3208,  3424,  3424,   331,  3424,  -607,
    -607,  -607,  -607,  -607,  -607,   255,   255,   255,   108,   705,
    -607,  -607,    47,  -607,  -607,   397
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  parser::yydefact_[] =
  {
         8,   371,   381,    21,    22,   226,    39,     0,     0,     0,
     235,     0,     0,     0,    51,    53,    44,   267,   299,   306,
     293,   323,     0,     0,    28,    30,     0,     0,   350,    35,
       0,   370,   278,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,     9,    10,
      11,    26,     0,    27,     0,    23,    24,    17,    20,    16,
      19,    18,    14,    15,     0,    25,     0,   216,   217,     0,
     219,   220,   373,   383,   227,   160,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    97,    40,   149,   142,    98,
     159,   216,    96,   219,     0,    61,     0,     0,     0,    62,
      64,     0,   371,    57,    58,    59,     0,     0,     0,    45,
       0,   300,   307,   294,   371,   381,    12,    13,     0,   218,
     221,   210,     0,    42,     0,   210,     0,     0,    56,   357,
      55,   355,     0,   334,   341,    37,     0,   279,    66,    68,
      78,     0,     0,     0,     0,    69,    84,     0,     0,     0,
       0,   207,     0,    48,     0,     0,     0,     1,     2,     8,
       6,     0,     0,   316,     0,     0,     0,     0,     0,   377,
     388,     0,     0,     0,   129,     0,   204,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   381,   236,   239,   240,     0,   354,    52,    54,
       0,     0,     8,     8,   373,   383,     0,     0,   212,     0,
       0,   213,    29,   248,   250,   252,   251,   253,    31,   254,
     256,   258,   257,   259,     0,     0,   352,     0,   351,   337,
     335,    32,     0,    36,     0,   341,   359,   361,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,   206,     0,     0,     0,     0,     4,     8,    87,
      93,     0,     0,     0,    86,   372,   382,   375,   385,   379,
     390,    88,   228,   233,   234,     0,     0,     0,     0,     0,
     371,     0,     0,     0,     0,   161,   162,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   158,   144,   146,   148,
     145,   147,   143,   100,     0,     0,   131,   133,   135,   132,
     134,   130,   151,   156,   157,   154,   155,   150,   224,   225,
       0,   222,     0,     0,     0,   372,   268,   301,     0,     0,
     372,   382,   208,   209,   211,   210,   210,     0,     0,     0,
     358,   356,     0,     0,    33,    34,   345,     0,   343,   349,
       0,    38,     0,     0,     0,     0,   285,   284,     0,   282,
       0,    79,    80,    82,    81,    83,    85,     0,     0,     0,
      46,    49,    60,    43,     7,     8,   317,     0,   376,   386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,     0,     0,     0,   177,   178,   179,
     174,   175,   173,   176,     0,     0,     0,     0,     0,   110,
     111,     0,   198,     0,   136,   202,   203,   163,   164,   165,
     166,   167,     0,   168,   170,     0,   171,     0,   106,   109,
     184,   185,   183,   190,   121,   122,     0,     0,   116,     0,
       0,   118,     0,   114,   112,   113,     0,     0,   128,   126,
       0,    63,    65,   241,   382,     0,     8,   309,     0,   308,
     296,   297,   295,   376,   386,   214,   215,   249,   255,   353,
     336,   340,   338,     0,     0,     0,   342,   330,   332,   331,
     333,   370,   370,   286,    75,    77,   283,     0,     0,    70,
       0,    73,     0,     0,     0,     0,     0,   313,   318,   320,
     380,   391,     0,     0,     0,   378,   389,   260,     0,     0,
       0,   205,   124,   372,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,   381,     0,   242,   244,   246,
     245,   247,     0,     0,   310,   298,     0,   346,   347,   344,
     365,   370,     0,     0,   370,   289,    76,    67,    71,     0,
      72,     0,     0,     0,     0,    47,    50,   326,     0,   374,
     384,     0,   261,   263,   265,   264,   266,   191,   192,   193,
       0,     0,   140,   141,   181,   182,   102,   103,     0,   105,
     199,     0,   200,   169,   172,     0,   107,     0,   195,   115,
       0,   197,   117,   137,     0,   186,     0,   188,     0,   237,
       0,     0,   303,   304,   302,   311,   339,     0,   360,     0,
     363,   366,   368,   367,   369,   362,   287,     0,     0,    74,
       0,     0,     0,     0,     0,   324,   387,     0,   229,     0,
       0,     0,     0,     0,     0,     0,   243,     0,   382,   276,
     305,   348,   364,     0,   290,   280,    91,    92,     0,    90,
       0,     8,   314,   262,     8,   104,   201,   108,   194,   196,
     187,   189,     0,     0,   269,   288,   291,   281,     0,   327,
     325,     0,     0,   238,   277,     8,     8,    89,     8,   321,
     322,   315,   232,   231,   230,   270,   292,   328,     0,   326,
     272,   273,   274,   329,   271,   275
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -607,  -607,  -607,  -201,  -607,   391,  -369,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,   122,  -607,    52,
    -607,   413,  -607,   743,   746,    58,   855,  -607,  -607,  1509,
    -607,  -607,   548,  -225,  -607,  -607,     2,  -607,  -170,  -607,
      82,  -607,   184,  -607,  -286,   169,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,     8,
    -607,   286,  -607,   293,  -607,   -17,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -363,   -31,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,   -76,  -607,  -607,  -606,  -607,   441,  -607,  -607,
    -607,  -607,  -607,  -607,   619,  -607,  -607,  -591,  -607,  -607,
     147,  -533,   754,     0,   201,  1034,   403,   642,  -607,  -227
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    44,    45,    46,   368,    47,    48,   176,   177,   184,
     345,   156,   157,   300,   301,   349,   638,   639,   640,   641,
     189,   190,   195,    49,    50,   356,   158,   135,   389,   201,
     455,   454,   392,   393,   137,   388,   202,   484,   318,   173,
     138,    52,   139,    54,   470,   471,    55,    74,   221,   534,
     814,   844,   382,    56,   151,   473,   797,   303,   686,   687,
     322,   323,   328,   329,   721,   722,    57,   160,   605,   835,
     848,   852,   854,   824,    58,   187,   348,   827,   510,   508,
     705,   803,   778,   826,   836,    59,   163,   313,   612,   695,
      60,   161,   311,   606,   764,   800,    61,   162,   312,   609,
     765,    62,   371,   717,   831,    63,   372,   648,   373,   841,
      64,   812,   785,   838,   849,   626,   341,   343,   344,   625,
     623,   767,   500,   183,   308,   180,   178,    65,   503,   505,
     701,   702,   703,   140,   141,    68,   142,   143,   652,    71
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -372;
  const short int
  parser::yytable_[] =
  {
        66,   396,   396,   526,   398,   321,   509,   146,   367,   285,
     527,   153,   154,   155,   336,   472,   152,   697,   317,   699,
     634,   635,   168,   174,   636,   351,   179,   181,   214,   496,
     636,   152,   482,   188,   191,   196,   634,   635,   483,    72,
     700,   700,   203,   204,   205,   285,   286,   634,   635,   292,
     293,   587,   152,   588,   284,   210,   287,   288,   289,   290,
     291,   292,   293,   352,   445,  -218,   214,   164,   165,   284,
      76,     1,     2,   285,   286,   610,   590,   556,   591,   210,
     210,   284,    51,    73,   476,    82,   839,   842,   611,    31,
     182,   523,   287,   288,   289,   290,   291,   292,   293,   843,
     762,   215,   538,   539,   840,  -371,   707,   149,   314,   763,
     700,   478,   479,   700,   150,   294,   295,   296,   297,   298,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   171,   172,   709,   850,   293,   316,   216,   316,
     631,   851,   632,   637,   146,   633,   197,   337,    36,    37,
      38,   304,    94,    95,    96,    97,    98,   306,   649,   637,
     310,   801,   497,   294,   295,   296,   297,   298,   769,   185,
     637,   769,   111,   112,   446,   216,   324,   330,   117,   118,
     119,   120,   338,   122,    53,   124,   346,   126,   127,   128,
     198,   294,   295,   296,   297,   298,   199,   357,   357,   357,
     535,    67,   144,   296,   297,   298,   146,   284,   147,    66,
     284,   284,   146,   206,   284,   741,   207,   742,   146,   557,
     559,   383,   558,   169,   147,   291,   292,   293,   394,   394,
     290,   291,   292,   293,   600,   192,   601,   164,   165,   146,
     146,   146,   146,   146,   653,   654,   415,   416,   417,   418,
     278,   279,   280,   281,   282,   283,   360,   361,   146,   146,
     146,   146,   210,   146,   146,   357,   146,   357,   146,   146,
     146,   146,   146,   146,   600,   211,   602,   710,   146,   146,
     146,   146,   146,   146,   146,   278,   279,   280,   281,   282,
     283,    51,   294,   295,   296,   297,   298,   210,   294,   295,
     296,   297,   298,   278,   279,   280,   281,   282,   283,   600,
     284,   661,    66,    66,   293,   615,   616,   607,   745,   174,
     746,   284,   284,   436,   647,   438,   284,   284,   608,   754,
     561,   755,   562,   284,   490,   491,   560,   580,   284,   770,
     212,   756,   498,   757,   146,   147,   284,   600,   581,   662,
     191,   512,   513,   514,   515,   516,   582,   284,   217,   396,
     284,   677,   396,   146,   679,   284,   718,   445,    66,   600,
     583,   719,    66,   586,   284,   284,   691,   325,   331,   294,
     295,   296,   297,   298,   585,   218,   284,   347,  -221,   284,
     222,   284,   284,    53,    51,    51,   593,   589,   147,   147,
     147,   594,   595,    69,   284,   693,   802,   147,   284,   284,
      67,   284,   284,   147,   740,   284,   284,   592,   749,   147,
     219,   752,   753,   596,   220,    69,   816,   223,   284,   284,
     726,   288,   289,   290,   291,   292,   293,   193,   817,   818,
     147,   147,   147,   147,   147,   284,   208,   209,   284,   284,
      51,   600,   215,   720,    51,   819,   597,   645,   284,   147,
     147,   147,   147,   225,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   747,   750,   748,   751,   147,
     147,   147,   147,   147,   147,   147,   152,   302,   324,   330,
     758,   216,   759,   146,   375,   376,    53,    53,   377,   378,
     627,   294,   295,   296,   297,   298,   600,   787,   786,   788,
     379,   380,   226,    67,    67,   390,   391,   480,   481,   227,
     147,   485,   172,   480,   487,    66,   228,    66,   494,   495,
     306,   691,   475,   604,   663,   664,   390,   685,    31,   768,
      31,   775,   663,   798,   288,   147,   290,   291,   292,   293,
     229,   192,    53,   230,   305,   307,    53,   776,   777,   231,
     726,   146,   232,   146,   147,   233,   234,   235,   236,    67,
     237,   238,   239,    67,   240,   241,   242,   146,   243,   326,
     332,   244,   245,   246,   247,   248,   394,   146,   249,   394,
     146,   250,   146,   251,   252,   253,   146,   146,   254,   255,
     358,   358,   358,   688,   256,   257,    66,    51,   319,    51,
     830,   258,    69,   832,   294,   295,   296,   297,   298,   259,
     260,   261,   262,   627,   384,   627,   263,   264,   265,   317,
     266,   267,   268,   269,   845,   846,   270,   847,   271,   272,
     273,   334,    70,   314,   315,   146,   146,   287,   288,   289,
     290,   291,   292,   293,   320,   335,   164,   723,   350,   353,
     342,   354,   293,   355,   170,   175,   474,   363,   358,   364,
     358,   365,   475,   488,   316,   489,   194,   502,   504,   509,
     542,   517,   518,   285,   286,   519,   525,   528,    51,   325,
     331,   529,   530,   531,   147,   532,   146,   533,   540,   541,
     544,   628,   543,   771,   545,   546,   563,   480,   603,    53,
     564,    53,   565,   566,   613,    69,    69,   614,   294,   295,
     296,   297,   298,   377,   650,   651,    67,   655,    67,   657,
     287,   288,   289,   290,   291,   292,   293,   656,   636,   706,
     730,   146,   731,   760,   780,   146,   781,   146,   783,   784,
     146,   804,   805,   193,   811,   822,   828,   833,   688,   524,
     708,   779,   147,   511,   147,   166,   796,   627,   167,   684,
     813,    69,   825,   853,   617,    69,   309,   397,   147,   704,
     146,   146,   618,   146,     0,   186,   501,   723,   147,     0,
      53,   147,     0,   147,     0,     0,     0,   147,   147,     0,
       0,   294,   295,   296,   297,   298,     0,    67,     0,     0,
     572,    66,   573,     0,    66,     0,   285,   286,   327,   333,
       0,     0,     0,     0,   628,     0,   628,     0,   146,     0,
       0,     0,     0,     0,     0,    66,    66,     0,    66,   359,
     359,   359,     0,     0,     0,     0,   147,   147,     0,     0,
       0,    70,   855,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   145,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   326,   332,    51,     0,     0,    51,   147,     0,     0,
       0,     0,     0,   629,   772,     0,     0,   359,     0,   359,
       0,     0,     0,     0,     0,     0,     0,    51,    51,     0,
      51,     0,     0,     0,   285,   286,     0,     0,    69,     0,
      69,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,   147,   575,     0,   576,   147,     0,   147,     0,
       0,   147,     0,     0,    70,    70,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,   628,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,   147,   147,     0,   147,     0,     0,     0,   276,     0,
       0,     0,   194,     0,     0,    53,     0,     0,    53,   299,
       0,     0,     0,     0,     0,     0,   690,     0,     0,    69,
      70,     0,    67,     0,    70,    67,     0,     0,     0,    53,
      53,     0,    53,     0,     0,     0,   629,     0,   629,   147,
     285,   286,     0,     0,     0,     0,    67,    67,   339,    67,
       0,   148,   294,   295,   296,   297,   298,     0,     0,     0,
       0,   577,     0,   578,     0,     0,     0,     0,     0,     0,
     725,   366,     0,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,   381,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,   410,   411,   412,   413,   414,
       0,     0,     0,     0,     0,     0,   773,     0,     0,     0,
       0,     0,     0,   429,   430,   431,   432,     0,   434,   435,
       0,   437,     0,   439,   440,   441,   442,   443,   444,     0,
     327,   333,     0,   447,   448,   449,   450,   451,   452,   453,
       0,     0,   630,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,     0,     0,   468,   468,   713,     0,   714,
       0,   690,     0,     0,     0,     0,     0,    70,     0,    70,
     629,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,     0,     0,   506,     0,     0,   285,   286,     0,     0,
       0,     0,     0,     0,    69,     0,     0,    69,   520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   285,   286,     0,     0,     0,    69,    69,
     148,    69,     0,   468,   468,     0,   148,     0,    70,     0,
       0,     0,   148,   287,   288,   289,   290,   291,   292,   293,
       0,     0,   395,   395,     0,   630,     0,   630,     0,     0,
       0,     0,     0,   148,   148,   148,   148,   148,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,   148,   148,   148,   148,     0,   148,   148,     0,
     148,     0,   148,   148,   148,   148,   148,   148,     0,     0,
       0,     0,   148,   148,   148,   148,   148,   148,   148,   285,
     286,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   738,     0,   739,     0,     0,     0,     0,
     285,   286,     0,     0,     0,   774,     0,     0,   620,     0,
     621,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,     0,   547,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,   285,   286,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   468,   468,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   630,
       0,     0,     0,     0,     0,     0,   672,     0,   673,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,   676,     0,   285,   286,     0,   294,   295,   296,
     297,   298,   678,     0,     0,   680,     0,   681,   548,     0,
       0,   682,   683,    70,     0,   468,    70,     0,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,     0,   549,
       0,   285,   286,     0,     0,     0,     0,    70,    70,     0,
      70,   287,   288,   289,   290,   291,   292,   293,   285,   286,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     715,   716,   550,     0,     0,     0,     0,   468,     0,     0,
       0,     0,     0,     0,     0,   136,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   159,     0,   148,   285,   286,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   766,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,     0,   551,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   213,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,   224,   294,
     295,   296,   297,   298,     0,   148,   790,   148,   536,     0,
     791,     0,   792,     0,     0,   793,   294,   295,   296,   297,
     298,   148,     0,     0,     0,     0,     0,   552,     0,     0,
     148,   148,     0,   148,   148,     0,   148,     0,     0,     0,
     148,   148,     0,     0,     0,   806,   807,   689,   809,     0,
     274,   275,   277,     0,     0,     0,   294,   295,   296,   297,
     298,     0,     0,     0,     0,     0,     0,   553,   506,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     148,     0,     0,   837,     0,     0,     0,     0,     0,     0,
       0,   724,   340,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   362,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     369,     0,     0,   374,     0,     0,     0,     0,     0,     0,
     148,   385,   386,     0,   387,     0,     0,     0,     0,   399,
     400,   402,   403,   404,   405,   406,   407,   408,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,     0,     0,     0,
       0,   433,     0,     0,     0,   148,     0,     0,     0,   148,
       0,   148,     0,     0,   148,     0,     0,     0,     0,     0,
       0,     0,   689,     0,     0,     0,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,     0,   469,
     469,     0,     0,     0,   148,   148,     0,   148,     0,     0,
     477,   724,     0,     0,     0,     0,     0,    75,    76,     1,
       2,     0,    77,    78,    79,    80,   285,   286,     0,     0,
       0,     0,    81,    82,     0,     0,   492,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   521,   522,    83,    84,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,   469,   469,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     0,   100,     0,   101,
     102,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,     0,     0,   294,   295,   296,   297,   298,     0,
     133,     0,   200,   598,   599,   567,     0,     0,     0,   285,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   622,     0,   624,     0,     0,   285,
     286,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,   642,   643,   644,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,   469,
     469,     0,     0,     0,   658,   659,   660,     0,     0,     0,
       0,     0,     0,     0,   665,   666,   287,   288,   289,   290,
     291,   292,   293,   667,   668,   669,   670,   671,     0,     0,
      75,    76,     1,     2,     0,    77,    78,    79,    80,     0,
       0,   674,     0,     0,   675,    81,    82,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   568,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   469,
       0,   569,     0,     0,   692,     0,     0,   694,    83,    84,
       0,     0,     0,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   570,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
     100,   469,   101,   102,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,   133,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   782,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,     1,     2,   789,    77,    78,
      79,    80,   285,   286,     0,     0,     0,     0,    81,    82,
       0,     0,     0,   794,     0,   795,     0,     0,     0,     0,
     799,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,   810,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,   507,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   834,   100,     0,   101,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   285,   286,
     294,   295,   296,   297,   298,     0,   133,     0,     0,     0,
       0,   571,   285,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   286,     0,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,   285,   286,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   294,   295,   296,   297,
     298,     0,     0,     0,     0,     0,     0,   574,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   579,   294,   295,   296,   297,   298,   285,   286,     0,
       0,     0,     0,   584,   294,   295,   296,   297,   298,   285,
     286,     0,     0,     0,     0,   619,     0,     0,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   698,   287,   288,   289,   290,   291,   292,   293,   285,
     286,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,     0,   711,   294,   295,   296,   297,   298,
       0,     0,   285,   286,     0,     0,   712,   294,   295,   296,
     297,   298,     0,     0,   285,   286,     0,     0,   727,     0,
       0,     0,     0,   294,   295,   296,   297,   298,   285,   286,
       0,     0,     0,     0,   728,     0,     0,   294,   295,   296,
     297,   298,   285,   286,     0,     0,     0,     0,   729,   287,
     288,   289,   290,   291,   292,   293,   285,   286,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,     0,
       0,   732,   294,   295,   296,   297,   298,     0,     0,   285,
     286,     0,     0,   733,     0,     0,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,   734,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   735,     0,     0,   294,   295,   296,   297,   298,   285,
     286,     0,     0,     0,     0,   736,   287,   288,   289,   290,
     291,   292,   293,   285,   286,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   737,   294,
     295,   296,   297,   298,     0,     0,   285,   286,     0,     0,
     743,     0,     0,   294,   295,   296,   297,   298,   285,   286,
       0,     0,     0,     0,   744,     0,     0,   294,   295,   296,
     297,   298,   285,   286,     0,     0,     0,     0,   808,     0,
       0,   294,   295,   296,   297,   298,   285,   286,     0,     0,
       0,     0,   815,   287,   288,   289,   290,   291,   292,   293,
     285,   286,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,     0,   820,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,   821,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   537,
    -319,   285,   286,     0,   294,   295,   296,   297,   298,   285,
     286,     0,     0,   554,     0,     0,     0,     0,   294,   295,
     296,   297,   298,   285,   286,     0,     0,   555,   287,   288,
     289,   290,   291,   292,   293,  -312,     0,     0,     0,   285,
     286,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,   287,   288,   289,   290,
     291,   292,   293,   761,   285,   286,   493,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
     696,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,   829,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   646,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,   294,
     295,   296,   297,   298,   285,   286,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,   295,   296,   297,   298,   285,   286,     0,     0,
     823,     0,     0,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     1,
       2,   636,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,     0,    16,     0,    17,     0,     0,     0,    18,
       0,    19,     0,    20,     0,    21,     0,     0,     0,     0,
       0,    22,    23,    24,    25,     0,     0,    26,    27,     0,
       0,     0,     0,     0,     0,     0,    28,    29,    30,     0,
      31,     0,    32,     0,     0,     0,    33,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,    39,    40,     0,    41,     1,
       2,    42,     0,     0,     0,     0,     3,     4,     5,     0,
       6,     7,     8,     9,    10,    43,    11,    12,    13,    14,
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
         0,   228,   229,   372,   229,   175,     7,     7,   209,     8,
     373,    11,    12,    13,     3,   301,     5,   623,    46,   625,
       3,     4,    22,    23,     7,    21,    26,    27,    60,     3,
       7,     5,    76,    33,    34,    35,     3,     4,    82,   136,
     631,   632,    40,    41,    42,     8,     9,     3,     4,    60,
      61,   135,     5,   137,   127,     7,    55,    56,    57,    58,
      59,    60,    61,    21,   137,    60,    60,     5,     6,   127,
       4,     5,     6,     8,     9,    27,   135,   135,   137,     7,
       7,   127,     0,   136,    60,    19,    27,    15,    40,    66,
     138,   137,    55,    56,    57,    58,    59,    60,    61,    27,
      27,   133,   388,   389,    45,   133,    73,   136,   136,    36,
     701,   312,   313,   704,   136,   126,   127,   128,   129,   130,
      55,    56,    57,    58,    59,    60,    61,   126,   127,   128,
     129,   130,     5,     6,   135,    27,    61,   133,   133,   133,
     503,    33,   505,   126,   144,   508,   136,   136,    86,    87,
      88,   151,    86,    87,    88,    89,    90,   133,   527,   126,
     160,   767,   136,   126,   127,   128,   129,   130,   701,    63,
     126,   704,   106,   107,   137,   133,   176,   177,   112,   113,
     114,   115,   182,   117,     0,   119,   186,   121,   122,   123,
     136,   126,   127,   128,   129,   130,   136,   197,   198,   199,
     135,     0,   136,   128,   129,   130,   206,   127,     7,   209,
     127,   127,   212,   136,   127,   135,     0,   137,   218,   135,
     137,   221,   135,    22,    23,    59,    60,    61,   228,   229,
      58,    59,    60,    61,   135,    34,   137,     5,     6,   239,
     240,   241,   242,   243,   530,   531,   244,   245,   246,   247,
      55,    56,    57,    58,    59,    60,   198,   199,   258,   259,
     260,   261,     7,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   135,    60,   137,   640,   278,   279,
     280,   281,   282,   283,   284,    55,    56,    57,    58,    59,
      60,   209,   126,   127,   128,   129,   130,     7,   126,   127,
     128,   129,   130,    55,    56,    57,    58,    59,    60,   135,
     127,   137,   312,   313,    61,   485,   486,    27,   135,   319,
     137,   127,   127,   265,   525,   267,   127,   127,    38,   135,
     135,   137,   137,   127,   334,   335,   137,   137,   127,   702,
      60,   135,   342,   137,   344,   144,   127,   135,   137,   137,
     350,   351,   352,   353,   354,   355,   137,   127,   133,   586,
     127,   586,   589,   363,   589,   127,   652,   137,   368,   135,
     137,   137,   372,   135,   127,   127,   603,   176,   177,   126,
     127,   128,   129,   130,   137,    60,   127,   186,    60,   127,
     136,   127,   127,   209,   312,   313,   137,   135,   197,   198,
     199,   137,   137,     0,   127,   606,   769,   206,   127,   127,
     209,   127,   127,   212,   137,   127,   127,   135,   137,   218,
     137,   137,   137,   135,   137,    22,   137,   136,   127,   127,
     657,    56,    57,    58,    59,    60,    61,    34,   137,   137,
     239,   240,   241,   242,   243,   127,    27,    28,   127,   127,
     368,   135,   133,   137,   372,   137,   135,   135,   127,   258,
     259,   260,   261,   136,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   135,   135,   137,   137,   278,
     279,   280,   281,   282,   283,   284,     5,     6,   488,   489,
     135,   133,   137,   493,     5,     6,   312,   313,     5,     6,
     500,   126,   127,   128,   129,   130,   135,   135,   137,   137,
       5,     6,   136,   312,   313,     5,     6,     5,     6,   136,
     319,     5,     6,     5,     6,   525,   136,   527,   134,   135,
     133,   758,     5,     6,     5,     6,     5,     6,    66,    67,
      66,    67,     5,     6,    56,   344,    58,    59,    60,    61,
     136,   350,   368,   136,   151,    30,   372,    70,    71,   136,
     787,   561,   136,   563,   363,   136,   136,   136,   136,   368,
     136,   136,   136,   372,   136,   136,   136,   577,   136,   176,
     177,   136,   136,   136,   136,   136,   586,   587,   136,   589,
     590,   136,   592,   136,   136,   136,   596,   597,   136,   136,
     197,   198,   199,   603,   136,   136,   606,   525,   135,   527,
     811,   136,   209,   814,   126,   127,   128,   129,   130,   136,
     136,   136,   136,   623,   221,   625,   136,   136,   136,    46,
     136,   136,   136,   136,   835,   836,   136,   838,   136,   136,
     136,   135,     0,   136,   136,   645,   646,    55,    56,    57,
      58,    59,    60,    61,   133,   135,     5,   657,   135,    21,
     138,    21,    61,   135,    22,    23,   133,   135,   265,   135,
     267,   135,     5,   135,   133,   135,    34,   133,   133,     7,
     137,   135,   135,     8,     9,   135,    42,   136,   606,   488,
     489,   136,   136,   136,   493,   136,   696,   136,   136,   136,
     133,   500,   137,   703,   135,   135,   135,     5,   136,   525,
     137,   527,   137,   137,   136,   312,   313,   136,   126,   127,
     128,   129,   130,     5,   137,   137,   525,   137,   527,   136,
      55,    56,    57,    58,    59,    60,    61,   137,     7,     3,
     136,   741,   136,   133,    60,   745,    60,   747,    60,    44,
     750,     7,    69,   350,    43,    21,    60,     4,   758,   368,
     638,   709,   561,   350,   563,    22,   758,   767,    22,   600,
     787,   368,   803,   849,   488,   372,   157,   229,   577,   632,
     780,   781,   489,   783,    -1,    31,   345,   787,   587,    -1,
     606,   590,    -1,   592,    -1,    -1,    -1,   596,   597,    -1,
      -1,   126,   127,   128,   129,   130,    -1,   606,    -1,    -1,
     135,   811,   137,    -1,   814,    -1,     8,     9,   176,   177,
      -1,    -1,    -1,    -1,   623,    -1,   625,    -1,   828,    -1,
      -1,    -1,    -1,    -1,    -1,   835,   836,    -1,   838,   197,
     198,   199,    -1,    -1,    -1,    -1,   645,   646,    -1,    -1,
      -1,   209,   852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   488,   489,   811,    -1,    -1,   814,   696,    -1,    -1,
      -1,    -1,    -1,   500,   703,    -1,    -1,   265,    -1,   267,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   835,   836,    -1,
     838,    -1,    -1,    -1,     8,     9,    -1,    -1,   525,    -1,
     527,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,    -1,   741,   135,    -1,   137,   745,    -1,   747,    -1,
      -1,   750,    -1,    -1,   312,   313,    -1,    -1,    -1,    -1,
      -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,   780,   781,    -1,   783,    -1,    -1,    -1,   133,    -1,
      -1,    -1,   350,    -1,    -1,   811,    -1,    -1,   814,   144,
      -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,   606,
     368,    -1,   811,    -1,   372,   814,    -1,    -1,    -1,   835,
     836,    -1,   838,    -1,    -1,    -1,   623,    -1,   625,   828,
       8,     9,    -1,    -1,    -1,    -1,   835,   836,   183,   838,
      -1,     7,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,   135,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
     657,   206,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,
      -1,    -1,    -1,   218,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,    -1,    -1,   703,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   259,   260,   261,    -1,   263,   264,
      -1,   266,    -1,   268,   269,   270,   271,   272,   273,    -1,
     488,   489,    -1,   278,   279,   280,   281,   282,   283,   284,
      -1,    -1,   500,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,   300,   301,   135,    -1,   137,
      -1,   758,    -1,    -1,    -1,    -1,    -1,   525,    -1,   527,
     767,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     787,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,
      -1,    -1,    -1,   348,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,   811,    -1,    -1,   814,   363,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,     9,    -1,    -1,    -1,   835,   836,
     206,   838,    -1,   388,   389,    -1,   212,    -1,   606,    -1,
      -1,    -1,   218,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,   228,   229,    -1,   623,    -1,   625,    -1,    -1,
      -1,    -1,    -1,   239,   240,   241,   242,   243,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,   258,   259,   260,   261,    -1,   263,   264,    -1,
     266,    -1,   268,   269,   270,   271,   272,   273,    -1,    -1,
      -1,    -1,   278,   279,   280,   281,   282,   283,   284,     8,
       9,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,   135,    -1,   137,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,   703,    -1,    -1,   493,    -1,
     495,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,     8,     9,    -1,    -1,    -1,   344,    -1,
      -1,    -1,    -1,    -1,    -1,   530,   531,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,   363,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   767,
      -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,   563,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,   577,    -1,     8,     9,    -1,   126,   127,   128,
     129,   130,   587,    -1,    -1,   590,    -1,   592,   137,    -1,
      -1,   596,   597,   811,    -1,   600,   814,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,     8,     9,    -1,    -1,    -1,    -1,   835,   836,    -1,
     838,    55,    56,    57,    58,    59,    60,    61,     8,     9,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     645,   646,   137,    -1,    -1,    -1,    -1,   652,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    16,    -1,   493,     8,     9,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   696,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    79,   126,
     127,   128,   129,   130,    -1,   561,   741,   563,   135,    -1,
     745,    -1,   747,    -1,    -1,   750,   126,   127,   128,   129,
     130,   577,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
     586,   587,    -1,   589,   590,    -1,   592,    -1,    -1,    -1,
     596,   597,    -1,    -1,    -1,   780,   781,   603,   783,    -1,
     131,   132,   133,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   803,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   645,
     646,    -1,    -1,   828,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   657,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,    -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,
     696,   222,   223,    -1,   225,    -1,    -1,    -1,    -1,   230,
     231,   232,   233,   234,   235,   236,   237,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,   741,    -1,    -1,    -1,   745,
      -1,   747,    -1,    -1,   750,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   758,    -1,    -1,    -1,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    -1,   300,
     301,    -1,    -1,    -1,   780,   781,    -1,   783,    -1,    -1,
     311,   787,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,     8,     9,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,   337,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,    -1,   828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   364,   365,    51,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,   389,    -1,
      -1,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    -1,    93,    -1,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    -1,    -1,   126,   127,   128,   129,   130,    -1,
     136,    -1,   138,   454,   455,   137,    -1,    -1,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   495,    -1,   497,    -1,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,   517,   518,   519,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,   530,
     531,    -1,    -1,    -1,   535,   536,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   546,    55,    56,    57,    58,
      59,    60,    61,   554,   555,   556,   557,   558,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,   572,    -1,    -1,   575,    18,    19,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   600,
      -1,   137,    -1,    -1,   605,    -1,    -1,   608,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,   652,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,   137,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,   738,     8,     9,
      10,    11,     8,     9,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,   754,    -1,   756,    -1,    -1,    -1,    -1,
     761,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,   784,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,   803,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   823,    93,    -1,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     8,     9,
     126,   127,   128,   129,   130,    -1,   136,    -1,    -1,    -1,
      -1,   137,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,     8,     9,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
     126,   127,   128,   129,   130,     8,     9,    -1,    -1,    -1,
      -1,   137,   126,   127,   128,   129,   130,     8,     9,    -1,
      -1,    -1,    -1,   137,   126,   127,   128,   129,   130,     8,
       9,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,     8,     9,    -1,    -1,    -1,
      -1,   137,    55,    56,    57,    58,    59,    60,    61,     8,
       9,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   126,   127,   128,   129,   130,
      -1,    -1,     8,     9,    -1,    -1,   137,   126,   127,   128,
     129,   130,    -1,    -1,     8,     9,    -1,    -1,   137,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,     8,     9,
      -1,    -1,    -1,    -1,   137,    -1,    -1,   126,   127,   128,
     129,   130,     8,     9,    -1,    -1,    -1,    -1,   137,    55,
      56,    57,    58,    59,    60,    61,     8,     9,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   126,   127,   128,   129,   130,    -1,    -1,     8,
       9,    -1,    -1,   137,    -1,    -1,   126,   127,   128,   129,
     130,     8,     9,    -1,    -1,    -1,    -1,   137,    -1,    -1,
     126,   127,   128,   129,   130,     8,     9,    -1,    -1,    -1,
      -1,   137,    -1,    -1,   126,   127,   128,   129,   130,     8,
       9,    -1,    -1,    -1,    -1,   137,    55,    56,    57,    58,
      59,    60,    61,     8,     9,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   126,
     127,   128,   129,   130,    -1,    -1,     8,     9,    -1,    -1,
     137,    -1,    -1,   126,   127,   128,   129,   130,     8,     9,
      -1,    -1,    -1,    -1,   137,    -1,    -1,   126,   127,   128,
     129,   130,     8,     9,    -1,    -1,    -1,    -1,   137,    -1,
      -1,   126,   127,   128,   129,   130,     8,     9,    -1,    -1,
      -1,    -1,   137,    55,    56,    57,    58,    59,    60,    61,
       8,     9,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   126,   127,   128,   129,
     130,     8,     9,    -1,    -1,    -1,    -1,   137,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,
       7,     8,     9,    -1,   126,   127,   128,   129,   130,     8,
       9,    -1,    -1,   135,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,     8,     9,    -1,    -1,   135,    55,    56,
      57,    58,    59,    60,    61,    42,    -1,    -1,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    55,    56,    57,    58,
      59,    60,    61,    32,     8,     9,    65,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    42,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,   126,
     127,   128,   129,   130,     8,     9,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,     8,     9,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    35,
      -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    72,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    -1,    -1,    91,    92,    -1,    94,     5,
       6,    97,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,   111,    22,    23,    24,    25,
      26,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    35,
      -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      66,    -1,    68,    -1,    -1,    -1,    72,    -1,    74,    75,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    -1,    -1,    91,    92,    -1,    94,    -1,
      -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111
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
     163,   179,   180,   181,   182,   185,   192,   205,   213,   224,
     229,   235,   240,   244,   249,   266,   272,   273,   274,   275,
     276,   278,   136,   136,   186,     3,     4,     8,     9,    10,
      11,    18,    19,    51,    52,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      93,    95,    96,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   136,   165,   166,   168,   173,   179,   181,
     272,   273,   275,   276,   136,   165,   272,   273,   274,   136,
     136,   193,     5,   272,   272,   272,   150,   151,   165,   168,
     206,   230,   236,   225,     5,     6,   162,   163,   272,   273,
     276,     5,     6,   178,   272,   276,   146,   147,   265,   272,
     264,   272,   138,   262,   148,    63,   271,   214,   272,   159,
     160,   272,   273,   275,   276,   161,   272,   136,   136,   136,
     138,   168,   175,   175,   175,   175,   136,     0,    27,    28,
       7,    60,    60,   168,    60,   133,   133,   133,    60,   137,
     137,   187,   136,   136,   168,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   168,   168,   165,   168,    55,    56,
      57,    58,    59,    60,   127,     8,     9,    55,    56,    57,
      58,    59,    60,    61,   126,   127,   128,   129,   130,   165,
     152,   153,     6,   196,   272,   275,   133,    30,   263,   263,
     272,   231,   237,   226,   136,   136,   133,    46,   177,   135,
     133,   177,   199,   200,   272,   273,   275,   276,   201,   202,
     272,   273,   275,   276,   135,   135,     3,   136,   272,   165,
     168,   255,   138,   256,   257,   149,   272,   273,   215,   154,
     135,    21,    21,    21,    21,   135,   164,   272,   275,   276,
     164,   164,   168,   135,   135,   135,   165,   142,   143,   168,
     165,   241,   245,   247,   168,     5,     6,     5,     6,     5,
       6,   165,   191,   272,   275,   168,   168,   168,   174,   167,
       5,     6,   171,   172,   272,   274,   278,   171,   172,   168,
     168,   137,   168,   168,   168,   168,   168,   168,   168,   165,
     165,   165,   165,   165,   165,   175,   175,   175,   175,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   165,
     165,   165,   165,   168,   165,   165,   164,   165,   164,   165,
     165,   165,   165,   165,   165,   137,   137,   165,   165,   165,
     165,   165,   165,   165,   170,   169,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   165,   168,
     183,   184,   183,   194,   133,     5,    60,   168,   142,   142,
       5,     6,    76,    82,   176,     5,   276,     6,   135,   135,
     272,   272,   168,    65,   134,   135,     3,   136,   272,   165,
     261,   256,   133,   267,   133,   268,   165,   168,   218,     7,
     217,   160,   272,   272,   272,   272,   272,   135,   135,   135,
     165,   168,   168,   137,   144,    42,   145,   217,   136,   136,
     136,   136,   136,   136,   188,   135,   135,   135,   183,   183,
     136,   136,   137,   137,   133,   135,   135,   137,   137,   137,
     137,   137,   137,   137,   135,   135,   135,   135,   135,   137,
     137,   135,   137,   135,   137,   137,   137,   137,   137,   137,
     137,   137,   135,   137,   137,   135,   137,   135,   137,   137,
     137,   137,   137,   137,   137,   137,   135,   135,   137,   135,
     135,   137,   135,   137,   137,   137,   135,   135,   168,   168,
     135,   137,   137,   136,     6,   207,   232,    27,    38,   238,
      27,    40,   227,   136,   136,   177,   177,   200,   202,   137,
     165,   165,   168,   259,   168,   258,   254,   272,   273,   275,
     276,   217,   217,   217,     3,     4,     7,   126,   155,   156,
     157,   158,   168,   168,   168,   135,   135,   142,   246,   145,
     137,   137,   277,   183,   183,   137,   137,   136,   168,   168,
     168,   137,   137,     5,     6,   168,   168,   168,   168,   168,
     168,   168,   165,   165,   168,   168,   165,   172,   165,   172,
     165,   165,   165,   165,   184,     6,   197,   198,   272,   274,
     275,   278,   168,   142,   168,   228,    65,   254,   137,   254,
     266,   269,   270,   271,   269,   219,     3,    73,   156,   135,
     217,   137,   137,   135,   137,   165,   165,   242,   183,   137,
     137,   203,   204,   272,   274,   275,   278,   137,   137,   137,
     136,   136,   137,   137,   137,   137,   137,   137,   135,   137,
     137,   135,   137,   137,   137,   135,   137,   135,   137,   137,
     135,   137,   137,   137,   135,   137,   135,   137,   135,   137,
     133,    32,    27,    36,   233,   239,   165,   260,    67,   270,
     217,   272,   273,   275,   276,    67,    70,    71,   221,   158,
      60,    60,   168,    60,    44,   251,   137,   135,   137,   168,
     165,   165,   165,   165,   168,   168,   198,   195,     6,   168,
     234,   254,   217,   220,     7,    69,   165,   165,   137,   165,
     168,    43,   250,   204,   189,   137,   137,   137,   137,   137,
     137,   137,    21,    34,   212,   218,   222,   216,    60,    42,
     142,   243,   142,     4,   168,   208,   223,   165,   252,    27,
      45,   248,    15,    27,   190,   142,   142,   142,   209,   253,
      27,    33,   210,   251,   211,   272
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
     177,   177,   178,   178,   178,   178,   179,   179,   180,   181,
     181,   182,   183,   183,   184,   184,   186,   187,   188,   189,
     185,   190,   190,   191,   191,   193,   194,   195,   192,   196,
     196,   197,   197,   197,   198,   198,   198,   198,   199,   199,
     200,   200,   200,   200,   201,   201,   202,   202,   202,   202,
     203,   203,   203,   204,   204,   204,   204,   206,   207,   208,
     209,   205,   210,   210,   211,   211,   212,   212,   214,   215,
     216,   213,   217,   217,   218,   218,   219,   220,   219,   221,
     222,   223,   221,   225,   226,   224,   227,   228,   227,   230,
     231,   232,   229,   233,   234,   233,   236,   237,   235,   238,
     239,   238,   241,   242,   243,   240,   245,   246,   244,   247,
     244,   248,   248,   249,   250,   250,   251,   252,   253,   251,
     254,   254,   254,   254,   255,   255,   255,   255,   255,   255,
     255,   257,   256,   258,   256,   259,   256,   260,   256,   261,
     262,   262,   262,   262,   263,   264,   264,   265,   265,   267,
     266,   268,   266,   269,   269,   270,   270,   270,   270,   270,
     271,   272,   272,   273,   273,   273,   273,   274,   274,   274,
     274,   275,   275,   276,   276,   276,   277,   276,   278,   278,
     278,   278
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
       3,     3,     3,     3,     3,     3,     4,     6,     4,     4,
       6,     6,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     2,     2,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       3,     6,     6,     4,     4,     4,     6,     8,     6,     8,
       4,     6,     6,     6,     8,     6,     8,     6,     4,     6,
       6,     8,     4,     4,     0,     5,     2,     1,     1,     1,
       0,     2,     2,     2,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     0,     0,     0,
      11,     1,     1,     1,     1,     0,     0,     0,    10,     1,
       1,     0,     1,     3,     1,     1,     1,     1,     1,     3,
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
  "exprtype", "dim_as_type", "dim_list",
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
       140,     0,    -1,   141,    27,    -1,   142,    -1,   141,    28,
     142,    -1,   144,    -1,    -1,   142,     7,   143,   144,    -1,
      -1,   145,    -1,   162,    -1,   163,    -1,    47,   162,    -1,
      47,   163,    -1,   240,    -1,   244,    -1,   224,    -1,   205,
      -1,   235,    -1,   229,    -1,   213,    -1,    12,    -1,    13,
      -1,   185,    -1,   192,    -1,   266,    -1,   179,    -1,   181,
      -1,    -1,    49,   146,   199,    -1,    -1,    50,   147,   201,
      -1,    62,   262,   255,    -1,    62,   262,   255,   134,    -1,
      62,   262,   255,   135,    -1,    -1,    63,   148,   256,    -1,
      -1,    64,    63,   149,   256,    -1,    16,    -1,    16,   168,
      -1,    16,   165,    -1,    48,   178,    -1,   111,   136,   165,
     137,    -1,    29,    -1,    29,   168,    -1,    91,   175,   135,
     165,    -1,    91,   175,   135,   165,   135,   165,    -1,    92,
     175,    -1,    94,   175,   135,   168,    -1,    94,   175,   135,
     168,   135,   165,    -1,    -1,    25,   150,   263,    -1,    -1,
      26,   151,   263,    -1,    54,   264,    -1,    53,   265,    -1,
      22,   272,    -1,    23,   272,    -1,    24,   272,    -1,    97,
     175,   135,   168,    -1,    17,   165,    -1,    -1,    18,   136,
     152,   183,   137,    -1,    -1,    19,   136,   153,   183,   137,
      -1,    -1,    72,   272,   154,   217,   155,    73,    -1,    74,
     159,    -1,    75,   161,    -1,   156,    -1,   155,   156,    -1,
     157,   217,    -1,   158,    -1,   157,   135,   158,    -1,     3,
      -1,   126,     3,    -1,     4,    -1,   160,    -1,   159,   135,
     160,    -1,   272,    21,   272,    -1,   275,    21,   272,    -1,
     273,    21,   272,    -1,   276,    21,   272,    -1,   272,    -1,
     161,   135,   272,    -1,   272,    60,   168,    -1,   180,    60,
     168,    -1,   275,    60,   165,    -1,    88,   136,   164,   135,
     168,   135,   168,   137,    60,   165,    -1,    88,   136,   164,
     135,   168,   137,    60,   165,    -1,    86,   136,   164,   135,
     168,   137,    60,   165,    -1,    87,   136,   164,   135,   168,
     137,    60,   165,    -1,   182,    60,   165,    -1,   275,    -1,
     276,    -1,   275,    -1,   166,    -1,   181,    -1,     4,    -1,
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
     167,   183,   137,    -1,    -1,   168,     9,   169,   168,    -1,
      -1,   168,     8,   170,   168,    -1,    10,   168,    -1,   168,
      60,   168,    -1,   168,    55,   168,    -1,   168,    58,   168,
      -1,   168,    56,   168,    -1,   168,    59,   168,    -1,   168,
      57,   168,    -1,    93,   136,   175,   137,    -1,   120,   136,
     165,   135,   165,   137,    -1,    51,   136,   171,   137,    -1,
      51,   136,   172,   137,    -1,    52,   136,   171,   135,   168,
     137,    -1,    52,   136,   172,   135,   168,   137,    -1,   179,
      -1,   165,    60,   165,    -1,   165,    55,   165,    -1,   165,
      58,   165,    -1,   165,    56,   165,    -1,   165,    59,   165,
      -1,   165,    57,   165,    -1,   173,    -1,   168,   130,   168,
      -1,   168,    61,   168,    -1,   127,   168,    -1,   126,   168,
      -1,   168,   128,   168,    -1,   168,   129,   168,    -1,   168,
     126,   168,    -1,   168,   127,   168,    -1,   136,   168,   137,
      -1,   272,    -1,     3,    -1,   274,    -1,   278,    -1,    98,
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
      18,   136,   174,   183,   137,    -1,   138,   168,    -1,   168,
      -1,    76,    -1,    82,    -1,    -1,    46,   176,    -1,     5,
     177,    -1,   276,   177,    -1,   178,   135,     5,   177,    -1,
     178,   135,   276,   177,    -1,   273,    -1,   274,    -1,   273,
      -1,   276,    -1,   278,    -1,   276,    -1,   184,    -1,   183,
     135,   184,    -1,   165,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    14,   186,   187,   191,   188,   136,   203,   137,   189,
     142,   190,    -1,    27,    -1,    15,    -1,   272,    -1,   275,
      -1,    -1,    -1,    -1,    20,   193,   196,   194,   136,   197,
     137,   195,    21,     4,    -1,   272,    -1,   275,    -1,    -1,
     198,    -1,   197,   135,   198,    -1,   272,    -1,   275,    -1,
     274,    -1,   278,    -1,   200,    -1,   199,   135,   200,    -1,
     272,    -1,   275,    -1,   273,    -1,   276,    -1,   202,    -1,
     201,   135,   202,    -1,   272,    -1,   275,    -1,   273,    -1,
     276,    -1,    -1,   204,    -1,   203,   135,   204,    -1,   272,
      -1,   275,    -1,   274,    -1,   278,    -1,    -1,    -1,    -1,
      -1,    31,   206,   272,    60,   207,   168,    32,   168,   212,
     208,   142,   209,   210,   211,    -1,    27,    -1,    33,    -1,
      -1,   272,    -1,    -1,    34,   168,    -1,    -1,    -1,    -1,
      68,   214,   215,   218,   217,   219,   221,    69,   216,    -1,
       7,    -1,   217,     7,    -1,   168,    -1,   165,    -1,    -1,
      -1,   219,    70,   220,   218,    -1,    -1,    -1,    -1,    71,
       7,   222,   223,   142,    -1,    -1,    -1,    39,   225,   226,
     142,   227,    -1,    27,    -1,    -1,    40,   228,    -1,    -1,
      -1,    -1,    35,   230,   231,   168,   232,   142,   233,    -1,
      27,    -1,    -1,    36,   234,    -1,    -1,    -1,    37,   236,
     237,   142,   238,    -1,    27,    -1,    -1,    38,   168,   239,
      -1,    -1,    -1,    -1,   249,   168,   241,    42,   142,   242,
     251,   250,   243,   248,    -1,    -1,    -1,   249,   168,   245,
     145,   246,    -1,    -1,   249,   168,   247,   217,   145,    -1,
      27,    -1,    45,    -1,    41,    -1,    -1,    43,   142,    -1,
      -1,    -1,    -1,    44,   168,    42,   252,   142,   253,   251,
      -1,   272,    -1,   275,    -1,   273,    -1,   276,    -1,    -1,
     168,    -1,   168,    65,   165,    -1,   165,    -1,   255,   135,
     168,    -1,   255,   135,   168,    65,   165,    -1,   255,   135,
     165,    -1,    -1,   257,   261,   254,    -1,    -1,   138,   272,
     258,   254,    -1,    -1,   138,     3,   259,   254,    -1,    -1,
     138,   136,   168,   137,   260,   254,    -1,   165,    -1,    -1,
     138,   272,    -1,   138,     3,    -1,   138,   136,   168,   137,
      -1,    30,    -1,   272,    -1,   264,   135,   272,    -1,   272,
      -1,   265,   135,   272,    -1,    -1,    66,   271,   272,   267,
     217,   269,    67,    -1,    -1,    66,   271,   273,   268,   217,
     269,    67,    -1,   270,   217,    -1,   269,   270,   217,    -1,
     266,    -1,   271,   272,    -1,   271,   275,    -1,   271,   273,
      -1,   271,   276,    -1,    -1,     5,    -1,   272,   133,     5,
      -1,     5,   136,    -1,   273,   133,     5,   136,   183,   137,
      -1,   273,   133,     5,    -1,   272,   133,     5,   136,    -1,
       5,   136,   137,    -1,   274,   133,     5,   136,   137,    -1,
     274,   133,     5,    -1,   272,   133,     5,   136,   137,    -1,
       6,    -1,   272,   133,     6,    -1,     6,   136,    -1,   273,
     133,     6,   136,   183,   137,    -1,   273,   133,     6,    -1,
      -1,   272,   133,     6,   136,   277,   183,   137,    -1,     6,
     136,   137,    -1,   274,   133,     6,   136,   137,    -1,   274,
     133,     6,    -1,   272,   133,     6,   136,   137,    -1
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
     469,   473,   477,   481,   485,   489,   493,   498,   505,   510,
     515,   522,   529,   531,   535,   539,   543,   547,   551,   555,
     557,   561,   565,   568,   571,   575,   579,   583,   587,   591,
     593,   595,   597,   599,   604,   609,   614,   619,   624,   629,
     636,   641,   646,   653,   658,   663,   668,   673,   678,   683,
     688,   692,   699,   706,   711,   716,   721,   728,   737,   744,
     753,   758,   765,   772,   779,   788,   795,   804,   811,   816,
     823,   830,   839,   844,   849,   850,   856,   859,   861,   863,
     865,   866,   869,   872,   875,   880,   885,   887,   889,   891,
     893,   895,   897,   899,   903,   905,   907,   908,   909,   910,
     911,   923,   925,   927,   929,   931,   932,   933,   934,   945,
     947,   949,   950,   952,   956,   958,   960,   962,   964,   966,
     970,   972,   974,   976,   978,   980,   984,   986,   988,   990,
     992,   993,   995,   999,  1001,  1003,  1005,  1007,  1008,  1009,
    1010,  1011,  1026,  1028,  1030,  1031,  1033,  1034,  1037,  1038,
    1039,  1040,  1050,  1052,  1055,  1057,  1059,  1060,  1061,  1066,
    1067,  1068,  1069,  1075,  1076,  1077,  1083,  1085,  1086,  1089,
    1090,  1091,  1092,  1100,  1102,  1103,  1106,  1107,  1108,  1114,
    1116,  1117,  1121,  1122,  1123,  1124,  1135,  1136,  1137,  1143,
    1144,  1150,  1152,  1154,  1156,  1157,  1160,  1161,  1162,  1163,
    1171,  1173,  1175,  1177,  1179,  1180,  1182,  1186,  1188,  1192,
    1198,  1202,  1203,  1207,  1208,  1213,  1214,  1219,  1220,  1227,
    1229,  1230,  1233,  1236,  1241,  1243,  1245,  1249,  1251,  1255,
    1256,  1264,  1265,  1273,  1276,  1280,  1282,  1285,  1288,  1291,
    1294,  1295,  1297,  1301,  1304,  1311,  1315,  1320,  1324,  1330,
    1334,  1340,  1342,  1346,  1349,  1356,  1360,  1361,  1369,  1373,
    1379,  1383
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   191,   191,   205,   206,   209,   210,   210,   219,   220,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   238,   244,   245,   246,   247,   248,   249,   249,
     250,   250,   251,   259,   264,   269,   269,   270,   270,   271,
     274,   279,   280,   285,   288,   289,   290,   291,   292,   293,
     294,   295,   295,   296,   296,   297,   298,   299,   302,   303,
     306,   307,   308,   308,   311,   311,   312,   312,   313,   314,
     317,   318,   321,   324,   325,   328,   329,   330,   333,   334,
     337,   338,   339,   340,   343,   344,   347,   352,   355,   356,
     357,   358,   359,   360,   365,   366,   369,   370,   371,   372,
     373,   374,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   398,   401,   401,   402,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   429,   434,   437,   440,   444,   448,   449,
     453,   458,   461,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   505,   508,   509,   512,   515,
     521,   522,   530,   537,   538,   543,   546,   547,   550,   553,
     554,   557,   560,   561,   564,   565,   568,   568,   570,   573,
     568,   582,   588,   591,   594,   597,   600,   603,   597,   611,
     617,   625,   626,   627,   630,   633,   636,   639,   644,   645,
     648,   649,   650,   651,   654,   655,   658,   659,   660,   661,
     664,   665,   666,   669,   670,   673,   676,   681,   682,   686,
     688,   681,   694,   699,   702,   703,   706,   707,   710,   710,
     712,   710,   717,   718,   721,   722,   725,   726,   726,   734,
     735,   735,   735,   741,   741,   741,   746,   747,   747,   750,
     750,   751,   750,   757,   758,   758,   761,   761,   761,   766,
     768,   767,   771,   776,   778,   771,   782,   783,   782,   784,
     784,   788,   789,   792,   795,   796,   799,   801,   803,   800,
     807,   808,   809,   810,   813,   814,   819,   821,   823,   825,
     827,   831,   831,   832,   832,   833,   833,   834,   834,   837,
     841,   846,   847,   848,   851,   854,   855,   858,   859,   863,
     863,   879,   879,   897,   898,   901,   902,   910,   918,   926,
     936,   944,   948,   951,   953,   954,   955,   958,   961,   962,
     963,   966,   967,   970,   971,   972,   973,   973,   976,   977,
     978,   979
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
  const int parser::yylast_ = 3535;
  const int parser::yynnts_ = 140;
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
#line 4379 "/home/cai/projects/basic/compiler/parser.cpp"
