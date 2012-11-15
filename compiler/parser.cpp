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

  case 210:
/* Line 661 of lalr1.cc  */
#line 518 "parser.ypp"
    {
			debug("as  %s\n",(yysemantic_stack_[(2) - (2)].exprtype)->name.c_str());
			// long varable
			// 构造类型
			(yyval.exprtype) = (yysemantic_stack_[(2) - (2)].exprtype);
		}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 526 "parser.ypp"
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
#line 533 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 534 "parser.ypp"
    {
	  // 	std::string name;
	//	name = $3;
	//	$$ = new VariableDimAST( name , ExprTypeASTPtr($2));
   }
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 539 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 542 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 543 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 546 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 549 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 219:
/* Line 661 of lalr1.cc  */
#line 550 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 220:
/* Line 661 of lalr1.cc  */
#line 553 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 556 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 557 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 225:
/* Line 661 of lalr1.cc  */
#line 564 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 564 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
if (function_type!=ftNONE) {debug("functions cannot be nested");}}
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 566 "parser.ypp"
    {
	   
}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 569 "parser.ypp"
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
#line 578 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 584 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 587 "parser.ypp"
    {
	//function_type=ftNUMBER;current_function = dotify ($1); $$ = dotify ($1);
	}
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 590 "parser.ypp"
    {/*function_type=ftSTRING;current_function = dotify ($1); $$ = dotify ($1);*/}
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 593 "parser.ypp"
    {
	
                      }
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 596 "parser.ypp"
    {
						  
                      }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 599 "parser.ypp"
    {
						  
                      }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 602 "parser.ypp"
    {
						  
                      }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 607 "parser.ypp"
    {
//                    function_type = ftNUMBER;
//                    cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_NUMBER;
//                    current_function = mystrdup ($1);
//                    $$ = mystrdup ($1);
                }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 613 "parser.ypp"
    {
//         function_type = ftSTRING;
//         cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_STRING;
//         current_function = mystrdup ($1);
//         $$ = mystrdup ($1);
     }
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 626 "parser.ypp"
    {
//                          create_require (stNUMBER); create_makelocal (dotify ($1), syNUMBER); add_command (cPOPNUMSYM, dotify ($1));
                      }
    break;

  case 244:
/* Line 661 of lalr1.cc  */
#line 629 "parser.ypp"
    {
//         create_require (stSTRING); create_makelocal (dotify ($1), sySTRING); add_command (cPOPSTRSYM, dotify ($1));
     }
    break;

  case 245:
/* Line 661 of lalr1.cc  */
#line 632 "parser.ypp"
    {
//         create_require (stNUMBERARRAYREF); create_arraylink (dotify ($1), stNUMBERARRAYREF);
     }
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 635 "parser.ypp"
    {
//         create_require (stSTRINGARRAYREF); create_arraylink (dotify ($1), stSTRINGARRAYREF);
     }
    break;

  case 249:
/* Line 661 of lalr1.cc  */
#line 644 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 250:
/* Line 661 of lalr1.cc  */
#line 645 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 646 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 252:
/* Line 661 of lalr1.cc  */
#line 647 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 654 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 655 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 656 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 657 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 665 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 666 "parser.ypp"
    {
	   
}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 669 "parser.ypp"
    {
	   
}
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 672 "parser.ypp"
    {
	   
}
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 677 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 678 "parser.ypp"
    {
				 
			}
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 682 "parser.ypp"
    {
	 }
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 684 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 686 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 690 "parser.ypp"
    {
		if (unclosed_fors) {
			debug ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 695 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 698 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 699 "parser.ypp"
    {  }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 702 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 706 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 706 "parser.ypp"
    {
	}
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 708 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 708 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 713 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 714 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 722 "parser.ypp"
    {
	   
}
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 725 "parser.ypp"
    {
		   
	}
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 731 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 731 "parser.ypp"
    {

	   
}
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 737 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 737 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 742 "parser.ypp"
    {if (unclosed_dos) { debug ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 746 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 746 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 747 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 753 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 754 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 754 "parser.ypp"
    { }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 757 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 757 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 762 "parser.ypp"
    {if (unclosed_repeats) { debug ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 764 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 764 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 767 "parser.ypp"
    {/*add_command(cDECIDE,NULL);storelabel();pushlabel();*/}
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 768 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 770 "parser.ypp"
    {/*poplabel();*/}
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 774 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 775 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 775 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 776 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 777 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 780 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 781 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 793 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 795 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 799 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 800 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 801 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 802 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 805 "parser.ypp"
    { debug("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 806 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 812 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 814 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 816 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 818 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 820 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 823 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 824 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 825 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 826 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 830 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 833 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 838 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 839 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 840 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 843 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 846 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 847 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 850 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 851 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 855 "parser.ypp"
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

  case 359:
/* Line 661 of lalr1.cc  */
#line 865 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 360:
/* Line 661 of lalr1.cc  */
#line 871 "parser.ypp"
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

  case 361:
/* Line 661 of lalr1.cc  */
#line 881 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 894 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
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
//         cmd->tag = sySTRING;
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
//         cmd->tag = syNUMBER;
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
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 928 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 936 "parser.ypp"
    {
		debug("变量引用\n");
		(yyval.varable_ref) = new VariableRefExprAST( (yysemantic_stack_[(1) - (1)].symbol) );
	}
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 940 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 943 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 945 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 946 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 947 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 950 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 953 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 954 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 955 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 958 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 959 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 962 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 963 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 964 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 965 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 965 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 968 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 969 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 970 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 971 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2627 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const short int parser::yypact_ninf_ = -650;
  const short int
  parser::yypact_[] =
  {
      3388,   -97,   -84,  -650,  -650,  -650,  2311,   957,   -70,   -64,
    -650,    73,    73,    73,  -650,  -650,  2311,  -650,  -650,  -650,
    -650,  -650,    59,   335,  -650,  -650,    73,    73,   -46,  -650,
      32,  -650,  -650,    73,   470,    73,   -29,   -17,    18,  1896,
    1896,  1896,  1896,    36,   184,   105,   180,  -650,  -650,  -650,
    -650,  -650,   151,  -650,   167,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  2311,  -650,   -24,     7,   123,   229,
     265,  -650,   230,   239,  -650,  -650,  -650,   303,   327,  2311,
     350,   355,   362,   383,   387,   389,   393,   401,   406,   407,
     408,   410,   411,   412,   413,   414,   416,   418,   419,   420,
     421,   422,   425,   427,   429,   430,   431,   435,   436,   438,
     439,   441,   444,   445,   446,   447,   448,   451,   454,  -650,
    -650,   456,   457,   458,   461,   462,   471,   474,   477,   478,
     479,  2311,  2311,  2311,    58,  -650,  3172,  -650,  -650,  -650,
     288,   315,  -650,  -650,   957,   325,   288,   315,   123,  -650,
    -650,   472,  -650,   483,   483,   483,   573,   573,    58,  3172,
      73,  -650,  -650,  -650,   481,   482,  -650,  -650,     8,   315,
    -650,   -28,   482,   485,   486,   558,   470,   470,   490,   483,
     491,   483,    25,  2311,   489,  -650,   616,  -650,   483,   493,
    -650,     4,    16,   608,   609,   496,   483,   470,   470,   470,
    2311,  3172,   497,  -650,   503,   505,   957,  -650,  -650,  3388,
    -650,  2311,   957,  3032,  2311,   484,   500,   502,   957,  -650,
    -650,   472,  2311,  2311,  1594,  2311,  -650,  -650,   504,   504,
    2311,  2311,  2138,  2311,  2311,  2311,  2311,  2311,  2311,   957,
     957,   957,   957,   957,  1896,  1896,  1896,  1896,  2311,  2311,
    2311,  2311,  2311,  2311,  2311,  2311,  2311,  2311,   957,   957,
     957,   957,  2311,   957,   957,   470,   957,   470,   957,   957,
     957,   957,   957,   957,   574,   574,   237,    41,   957,   957,
     957,   957,   957,   957,   957,  -650,  -650,  2311,  2311,  2311,
    2311,  2311,  2311,  2311,  2311,  2311,  2311,  2311,  2311,   -89,
    2311,  2311,  -650,  -650,   509,  -650,   632,  -650,  -650,  -650,
      19,  2311,  3388,  3388,  -650,  -650,   506,   563,  -650,   510,
     512,  -650,   508,  -650,   513,   315,  -650,  -650,   515,  -650,
     513,   315,  -650,  -650,    73,    73,  -650,  2311,   483,    58,
    3020,   140,    26,  -650,   957,   489,   514,   518,  2311,   645,
     470,    73,    73,    73,    73,    73,   519,   513,  -650,  -650,
     520,   523,  3172,   957,  2311,  2311,   -56,   180,  3388,  3172,
     325,   606,  3388,   645,  3172,   517,   521,   524,   525,   529,
     530,   325,  -650,   509,  -650,  1141,  2882,  2896,  2311,  2311,
     532,   534,   536,   537,   538,   123,  -650,   527,   541,  1122,
    1293,  -650,  1336,  1353,  1440,  1499,  1606,  2977,  2991,    54,
      61,    99,   -47,    77,    29,   542,   543,   544,   547,  1622,
    1639,  1729,  1793,  1900,     1,  2032,    65,   674,  2045,   149,
     150,   193,   195,  2072,   200,   127,   -82,   238,   -60,   253,
     206,   209,   211,   282,   310,  -650,  -650,   325,   325,   325,
     325,   325,   325,  -650,  2311,  2311,   374,   172,   367,   177,
     256,   263,  -650,    45,    45,   574,   574,   574,    58,  3172,
     -44,  -650,    20,   549,   516,  -650,  -650,  3172,    56,   176,
     550,   554,  -650,  -650,   -28,   558,   554,   470,   470,   483,
     483,  2315,   957,  -650,  2311,  -650,  2311,   483,   325,   470,
    -650,   654,   645,   667,   645,    58,  3172,   645,  -650,    17,
    -650,   483,   483,   483,   483,   483,  2311,  2311,  2311,   311,
    3005,  3172,  -650,  -650,  3388,  -650,  3298,   555,   557,  2311,
    2311,   559,   560,   562,  2311,  2311,  2311,    85,   153,   230,
     239,  -650,  -650,   522,  2311,  2311,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  2311,  2311,  2311,  2311,  2311,  -650,  -650,
     957,  -650,   957,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  2311,  -650,  -650,  2311,  -650,   957,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,   504,   957,  -650,   504,   957,
    -650,   957,  -650,  -650,  -650,   957,   957,  1594,  1466,  2311,
    -650,  -650,   526,  -650,  2311,  3388,  -650,  2311,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   325,
      58,  3114,   470,  2431,   470,  -650,   513,   315,  -650,  -650,
      69,    69,   671,  -650,  -650,  -650,   676,    37,  -650,    -1,
    -650,  2445,  2457,   807,   957,   957,   180,  -650,  -650,  -650,
    -650,  2311,   173,   174,  -650,  -650,   526,  2469,  2485,  2568,
    -650,  -650,   565,   567,  2580,  2592,  2608,  2622,  2705,  2717,
    1252,   212,    80,  2731,  2745,   120,   285,   233,   312,   242,
     244,   191,   194,  -650,   534,   316,  -650,   566,   123,  -650,
    -650,  3133,   183,  3172,  -650,   957,  -650,  -650,  -650,  -650,
     467,   645,   470,   469,   468,  -650,  -650,  -650,    39,   671,
     631,   644,  2311,   646,   325,   325,   661,   320,  -650,  -650,
     321,  -650,   566,   123,  -650,  -650,  -650,  -650,  -650,   555,
     557,  -650,  -650,  -650,  -650,  -650,  -650,  2311,  -650,  -650,
     957,  -650,  -650,  -650,   957,  -650,   957,  -650,  -650,   957,
    -650,  -650,  -650,  2311,  -650,  2311,  -650,   526,  -650,   535,
    2311,  -650,  -650,  -650,  -650,   325,   470,  -650,   645,   671,
     513,   315,  -650,  -650,  -650,  -650,   700,   639,  -650,   957,
     957,  2759,   957,  2311,   666,  -650,   526,  -650,  2842,   269,
     274,   278,   281,  2854,  2868,  -650,   689,   567,  3143,  -650,
    -650,   671,  2311,  -650,  -650,   325,   325,   651,   325,  3155,
    3388,  -650,  -650,  3388,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,   708,  2311,  -650,  -650,  -650,  -650,   957,  -650,   180,
     -13,   198,  -650,  3172,  3388,  3388,   325,  3388,  -650,  -650,
    -650,  -650,  -650,  -650,   180,   180,   180,   370,   661,  -650,
    -650,    73,  -650,  -650,   483
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  parser::yydefact_[] =
  {
         8,   370,   380,    21,    22,   225,    39,     0,     0,     0,
     234,     0,     0,     0,    51,    53,    44,   266,   298,   305,
     292,   322,     0,     0,    28,    30,     0,     0,   349,    35,
       0,   369,   277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,     9,    10,
      11,    26,     0,    27,     0,    23,    24,    17,    20,    16,
      19,    18,    14,    15,     0,    25,     0,   215,   216,     0,
     218,   219,   372,   382,   226,   160,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    97,    40,   149,   142,    98,
     159,   215,    96,   218,     0,    61,     0,     0,     0,    62,
      64,     0,   370,    57,    58,    59,     0,     0,     0,    45,
       0,   299,   306,   293,   370,   380,    12,    13,     0,   217,
     220,   209,     0,    42,     0,   209,     0,     0,    56,   356,
      55,   354,     0,   333,   340,    37,     0,   278,    66,    68,
      78,     0,     0,     0,     0,    69,    84,     0,     0,     0,
       0,   207,     0,    48,     0,     0,     0,     1,     2,     8,
       6,     0,     0,   315,     0,     0,     0,     0,     0,   376,
     387,     0,     0,     0,   129,     0,   204,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   380,   235,   238,   239,     0,   353,    52,    54,
       0,     0,     8,     8,   372,   382,     0,     0,   211,     0,
       0,   212,    29,   247,   249,   251,   250,   252,    31,   253,
     255,   257,   256,   258,     0,     0,   351,     0,   350,   336,
     334,    32,     0,    36,     0,   340,   358,   360,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,     0,   206,     0,     0,     0,     0,     4,     8,    87,
      93,     0,     0,     0,    86,   371,   381,   374,   384,   378,
     389,    88,   227,   232,   233,     0,     0,     0,     0,     0,
     370,     0,     0,     0,     0,   161,   162,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   158,   144,   146,   148,
     145,   147,   143,   100,     0,     0,   131,   133,   135,   132,
     134,   130,   151,   156,   157,   154,   155,   150,   223,   224,
       0,   221,     0,     0,     0,   371,   267,   300,     0,     0,
     371,   381,   208,   210,   209,   209,     0,     0,     0,   357,
     355,     0,     0,    33,    34,   344,     0,   342,   348,     0,
      38,     0,     0,     0,     0,   284,   283,     0,   281,     0,
      79,    80,    82,    81,    83,    85,     0,     0,     0,    46,
      49,    60,    43,     7,     8,   316,     0,   375,   385,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,     0,     0,     0,   177,   178,   179,   174,
     175,   173,   176,     0,     0,     0,     0,     0,   110,   111,
       0,   198,     0,   136,   202,   203,   163,   164,   165,   166,
     167,     0,   168,   170,     0,   171,     0,   106,   109,   184,
     185,   183,   190,   121,   122,     0,     0,   116,     0,     0,
     118,     0,   114,   112,   113,     0,     0,   128,   126,     0,
      63,    65,   240,   381,     0,     8,   308,     0,   307,   295,
     296,   294,   375,   385,   213,   214,   248,   254,   352,   335,
     339,   337,     0,     0,     0,   341,   329,   331,   330,   332,
     369,   369,   285,    75,    77,   282,     0,     0,    70,     0,
      73,     0,     0,     0,     0,     0,   312,   317,   319,   379,
     390,     0,     0,     0,   377,   388,   259,     0,     0,     0,
     205,   124,   371,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   380,     0,   241,   243,   245,   244,
     246,     0,     0,   309,   297,     0,   345,   346,   343,   364,
     369,     0,     0,   369,   288,    76,    67,    71,     0,    72,
       0,     0,     0,     0,    47,    50,   325,     0,   373,   383,
       0,   260,   262,   264,   263,   265,   191,   192,   193,     0,
       0,   140,   141,   181,   182,   102,   103,     0,   105,   199,
       0,   200,   169,   172,     0,   107,     0,   195,   115,     0,
     197,   117,   137,     0,   186,     0,   188,     0,   236,     0,
       0,   302,   303,   301,   310,   338,     0,   359,     0,   362,
     365,   367,   366,   368,   361,   286,     0,     0,    74,     0,
       0,     0,     0,     0,   323,   386,     0,   228,     0,     0,
       0,     0,     0,     0,     0,   242,     0,   381,   275,   304,
     347,   363,     0,   289,   279,    91,    92,     0,    90,     0,
       8,   313,   261,     8,   104,   201,   108,   194,   196,   187,
     189,     0,     0,   268,   287,   290,   280,     0,   326,   324,
       0,     0,   237,   276,     8,     8,    89,     8,   320,   321,
     314,   231,   230,   229,   269,   291,   327,     0,   325,   271,
     272,   273,   328,   270,   274
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -650,  -650,  -650,  -201,  -650,   345,  -368,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,    79,  -650,     9,
    -650,   368,  -650,   697,   698,   -19,   842,  -650,  -650,  1581,
    -650,  -650,   492,  -226,  -650,  -650,     5,  -650,  -170,  -650,
      44,  -650,    82,  -650,  -285,   124,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,   -35,
    -650,   241,  -650,   236,  -650,   -50,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -354,   -76,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,  -650,
    -650,  -650,  -111,  -650,  -650,  -607,  -650,   394,  -650,  -650,
    -650,  -650,  -650,  -650,   581,  -650,  -650,  -561,  -650,  -650,
     110,  -649,   711,     0,   201,  1014,   402,   641,  -650,  -227
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    44,    45,    46,   368,    47,    48,   176,   177,   184,
     345,   156,   157,   300,   301,   349,   637,   638,   639,   640,
     189,   190,   195,    49,    50,   356,   158,   135,   389,   201,
     455,   454,   392,   393,   137,   388,   202,   483,   318,   173,
     138,    52,   139,    54,   470,   471,    55,    74,   221,   533,
     813,   843,   382,    56,   151,   473,   796,   303,   685,   686,
     322,   323,   328,   329,   720,   721,    57,   160,   604,   834,
     847,   851,   853,   823,    58,   187,   348,   826,   509,   507,
     704,   802,   777,   825,   835,    59,   163,   313,   611,   694,
      60,   161,   311,   605,   763,   799,    61,   162,   312,   608,
     764,    62,   371,   716,   830,    63,   372,   647,   373,   840,
      64,   811,   784,   837,   848,   625,   341,   343,   344,   624,
     622,   766,   499,   183,   308,   180,   178,    65,   502,   504,
     700,   701,   702,   140,   141,    68,   142,   143,   651,    71
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -371;
  const short int
  parser::yytable_[] =
  {
        66,   396,   396,   398,   525,   321,   508,   146,   367,   285,
     286,   153,   154,   155,   838,   696,   472,   698,   317,   526,
     633,   634,   168,   174,   635,   351,   179,   181,   336,   495,
     152,   152,   839,   188,   191,   196,   214,   352,   284,    72,
     633,   634,   633,   634,    51,   203,   204,   205,   445,   285,
     286,   768,    73,   586,   768,   587,   287,   288,   289,   290,
     291,   292,   293,   210,   164,   165,   149,  -217,   214,   699,
     699,   284,   150,   285,   286,   589,   635,   590,   152,   476,
     284,   522,    53,   606,   278,   279,   280,   281,   282,   283,
     558,   599,   182,   600,   607,   185,   287,   288,   289,   290,
     291,   292,   293,   537,   538,  -370,   293,   197,   314,   215,
     706,   478,   479,   278,   279,   280,   281,   282,   283,   198,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   208,   209,   708,    31,   571,   316,   572,   699,
     216,   316,   699,   636,   146,    36,    37,    38,   630,   216,
     631,   304,   306,   632,   199,   599,   284,   601,   648,   800,
     310,   337,   496,   636,   560,   636,   561,   294,   295,   296,
     297,   298,   206,   296,   297,   298,   324,   330,   446,   360,
     361,   284,   338,   210,   207,   284,   346,   210,   284,   555,
     210,   294,   295,   296,   297,   298,   556,   357,   357,   357,
     574,    67,   575,   609,   284,   210,   146,   284,   147,    66,
     761,   211,   146,   841,   559,   740,   610,   741,   146,   762,
     599,   383,   660,   169,   147,   842,   284,   212,   394,   394,
     290,   291,   292,   293,   557,   192,   291,   292,   293,   146,
     146,   146,   146,   146,   652,   653,   436,   284,   438,   415,
     416,   417,   418,    51,   284,   744,   217,   745,   146,   146,
     146,   146,   585,   146,   146,   357,   146,   357,   146,   146,
     146,   146,   146,   146,   493,   494,   284,   284,   146,   146,
     146,   146,   146,   146,   146,   709,   579,   580,   599,   218,
     661,    53,   278,   279,   280,   281,   282,   283,   294,   295,
     296,   297,   298,   294,   295,   296,   297,   298,   599,   599,
     718,   719,    66,    66,   614,   615,   292,   293,   284,   174,
     284,   284,   284,   646,   293,  -220,   753,   284,   754,   755,
     581,   756,   582,   284,   489,   490,   284,   584,   284,   284,
     171,   172,   497,   592,   146,   147,   593,   769,   594,   739,
     191,   511,   512,   513,   514,   515,    51,    51,   396,   676,
     284,   396,   678,   146,   284,   284,   717,   219,    66,   284,
     748,   284,    66,   588,   445,   690,   220,   325,   331,   751,
     284,   752,   294,   295,   296,   297,   298,   347,   591,   294,
     295,   296,   297,   298,    53,    53,   284,   849,   147,   147,
     147,   284,    69,   850,   692,   284,   815,   147,   284,   284,
      67,   816,    51,   147,   801,   817,    51,   595,   818,   147,
     746,   215,   747,   288,    69,   290,   291,   292,   293,   725,
     288,   289,   290,   291,   292,   293,   193,   284,   284,   222,
     147,   147,   147,   147,   147,   596,   644,   749,   216,   750,
      53,   757,   284,   758,    53,   599,   786,   785,   787,   147,
     147,   147,   147,   223,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   164,   165,   152,   302,   147,
     147,   147,   147,   147,   147,   147,   225,   324,   330,   375,
     376,   226,   146,   294,   295,   296,   297,   298,   227,   626,
     294,   295,   296,   297,   298,   377,   378,   379,   380,   390,
     391,   480,   481,    67,    67,   484,   172,   480,   486,   228,
     147,   475,   603,   229,    66,   230,    66,   662,   663,   231,
     690,   390,   684,    31,   767,    31,   774,   232,   775,   776,
     662,   797,   233,   234,   235,   147,   236,   237,   238,   239,
     240,   192,   241,   305,   242,   243,   244,   245,   246,   725,
     146,   247,   146,   248,   147,   249,   250,   251,    51,    67,
      51,   252,   253,    67,   254,   255,   146,   256,   326,   332,
     257,   258,   259,   260,   261,   394,   146,   262,   394,   146,
     263,   146,   264,   265,   266,   146,   146,   267,   268,   358,
     358,   358,   687,   307,   317,    66,    53,   269,    53,   829,
     270,    69,   831,   271,   272,   273,   306,   314,   315,   320,
     319,   164,   626,   384,   626,   334,   335,   342,   350,   353,
     354,   355,   363,   844,   845,   293,   846,   475,   364,   482,
     365,    70,   474,   487,   146,   146,   316,   501,   524,    51,
     488,   503,   508,   527,   516,   517,   722,   528,   518,   480,
     529,   530,   544,   170,   175,   531,   532,   358,   539,   358,
     540,   543,   377,   541,   542,   194,   545,   562,   635,   705,
     563,   564,   285,   286,   565,   602,   612,    53,   325,   331,
     613,   779,   649,   147,   650,   146,   654,   655,   656,   759,
     627,   729,   770,   730,   780,   783,   782,   803,   804,   810,
     821,   827,   832,   523,    69,    69,   707,   778,   510,   166,
     167,   397,   795,   683,   617,    67,   824,    67,   616,   287,
     288,   289,   290,   291,   292,   293,   812,   852,   309,   500,
     146,   703,   186,     0,   146,     0,   146,     0,     0,   146,
       0,     0,   193,     0,     0,     0,     0,   687,     0,     0,
       0,   147,     0,   147,     0,     0,   626,     0,     0,     0,
      69,     0,     0,     0,    69,     0,     0,   147,     0,   146,
     146,     0,   146,     0,     0,     0,   722,   147,     0,     0,
     147,     0,   147,     0,     0,     0,   147,   147,     0,     0,
     294,   295,   296,   297,   298,     0,    67,     0,     0,   576,
      66,   577,     0,    66,     0,   285,   286,   327,   333,     0,
       0,     0,     0,   627,     0,   627,     0,   146,     0,     0,
       0,     0,     0,     0,    66,    66,     0,    66,   359,   359,
     359,     0,     0,     0,     0,   147,   147,     0,   134,   145,
      70,   854,     0,     0,    51,     0,     0,    51,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    51,
       0,    51,     0,     0,     0,     0,     0,     0,     0,   326,
     332,     0,    53,     0,     0,    53,   147,     0,     0,     0,
       0,   628,     0,   771,     0,     0,   359,     0,   359,     0,
       0,     0,     0,     0,     0,     0,    53,    53,     0,    53,
       0,     0,     0,     0,     0,     0,    69,     0,    69,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,   147,   712,     0,   713,   147,     0,   147,     0,     0,
     147,     0,     0,    70,    70,     0,     0,     0,     0,     0,
     485,    76,     1,     2,     0,     0,     0,   627,     0,     0,
       0,     0,     0,     0,     0,   276,    82,     0,     0,     0,
     147,   147,     0,   147,     0,     0,   299,     0,     0,     0,
       0,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   689,     0,     0,    69,     0,    70,
       0,    67,     0,    70,    67,     0,     0,     0,     0,     0,
       0,   148,     0,     0,   628,   339,   628,     0,   147,     0,
       0,     0,     0,     0,     0,    67,    67,     0,    67,     0,
       0,     0,     0,    94,    95,    96,    97,    98,   366,     0,
       0,     0,     0,     0,   370,     0,     0,     0,   724,     0,
     381,     0,     0,   111,   112,     0,     0,     0,     0,   117,
     118,   119,   120,     0,   122,     0,   124,     0,   126,   127,
     128,   409,   410,   411,   412,   413,   414,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     429,   430,   431,   432,   772,   434,   435,     0,   437,     0,
     439,   440,   441,   442,   443,   444,     0,     0,     0,     0,
     447,   448,   449,   450,   451,   452,   453,     0,   327,   333,
     285,   286,     0,     0,     0,     0,     0,     0,     0,     0,
     629,     0,   468,   468,     0,     0,     0,     0,     0,   285,
     286,     0,     0,     0,     0,     0,     0,     0,   148,   689,
       0,     0,     0,     0,     0,    70,     0,    70,   628,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,   498,     0,   724,     0,
     505,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,   519,     0,     0,     0,     0,
       0,     0,    69,     0,     0,    69,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,   148,     0,     0,     0,
     468,   468,   148,     0,     0,     0,    69,    69,     0,    69,
       0,     0,   395,   395,     0,     0,    70,     0,   294,   295,
     296,   297,   298,   148,   148,   148,   148,   148,     0,   546,
     285,   286,     0,   629,     0,   629,     0,   294,   295,   296,
     297,   298,   148,   148,   148,   148,   534,   148,   148,     0,
     148,     0,   148,   148,   148,   148,   148,   148,     0,     0,
       0,     0,   148,   148,   148,   148,   148,   148,   148,     0,
       0,   285,   286,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   619,     0,   620,     0,     0,     0,
       0,     0,     0,   773,   285,   286,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,   148,     0,
       0,   285,   286,     0,     0,     0,     0,     0,     0,     0,
       0,   468,   468,     0,     0,     0,     0,   148,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   737,     0,   738,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,   671,     0,   672,     0,     0,   629,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,   675,   294,
     295,   296,   297,   298,     0,     0,     0,     0,   677,     0,
     547,   679,     0,   680,     0,     0,     0,   681,   682,     0,
       0,   468,     0,     0,     0,     0,     0,     0,   285,   286,
       0,    70,     0,     0,    70,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,     0,   548,   285,    70,    70,     0,    70,   294,
     295,   296,   297,   298,     0,     0,   714,   715,     0,     0,
     549,     0,     0,   468,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,   148,   285,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   765,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,   294,   295,   296,   297,
     298,     0,     0,     0,   148,     0,   148,   550,     0,     0,
       0,     0,   789,     0,     0,     0,   790,   136,   791,     0,
     148,   792,   294,   295,   296,   297,   298,   159,     0,   148,
     148,     0,   148,   148,     0,   148,     0,     0,     0,   148,
     148,     0,     0,     0,   285,   286,   688,     0,     0,     0,
       0,   805,   806,     0,   808,   294,   295,   296,   297,   298,
     285,   286,     0,     0,     0,     0,   551,     0,     0,     0,
       0,     0,     0,     0,   505,   213,     0,   285,   286,   287,
     288,   289,   290,   291,   292,   293,     0,     0,   148,   148,
     224,   287,   288,   289,   290,   291,   292,   293,     0,   836,
     723,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,   274,   275,   277,     0,     0,     0,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,   285,   286,     0,
       0,     0,     0,   552,     0,     0,     0,     0,   294,   295,
     296,   297,   298,     0,   148,     0,     0,     0,   148,   566,
     148,     0,     0,   148,   340,   294,   295,   296,   297,   298,
       0,   688,     0,     0,     0,     0,   567,     0,     0,     0,
       0,   362,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,   369,   148,   148,   374,   148,     0,     0,     0,
     723,   285,   286,   385,   386,     0,   387,     0,     0,     0,
       0,   399,   400,   402,   403,   404,   405,   406,   407,   408,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,     0,
       0,   148,     0,   433,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,     0,     0,     0,   568,     0,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
       0,   469,   469,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   477,     0,     0,     0,     0,     0,     0,    75,
      76,     1,     2,     0,    77,    78,    79,    80,   285,   286,
       0,     0,     0,     0,    81,    82,     0,     0,   491,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,   506,
     569,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   520,   521,    83,    84,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,   469,
     469,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     0,   100,
       0,   101,   102,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,     0,   294,   295,   296,   297,
     298,     0,   133,     0,   200,   597,   598,   570,     0,     0,
     285,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   285,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   621,     0,   623,     0,     0,
     285,   286,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,   641,   642,   643,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
     469,   469,     0,     0,     0,   657,   658,   659,     0,     0,
       0,     0,     0,     0,     0,   664,   665,   287,   288,   289,
     290,   291,   292,   293,   666,   667,   668,   669,   670,     0,
       0,    75,    76,     1,     2,     0,    77,    78,    79,    80,
       0,     0,   673,     0,     0,   674,    81,    82,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,     0,   573,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     469,     0,   578,     0,     0,   691,     0,     0,   693,    83,
      84,     0,     0,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,     0,   583,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,   100,   469,   101,   102,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,   133,   401,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   781,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,     1,     2,   788,    77,
      78,    79,    80,   285,   286,     0,     0,     0,     0,    81,
      82,     0,     0,     0,   793,     0,   794,     0,     0,     0,
       0,   798,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,   809,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,   506,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   833,   100,     0,   101,   102,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   285,
     286,   294,   295,   296,   297,   298,     0,   133,     0,     0,
       0,     0,   618,   285,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,   286,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,   285,   286,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   697,     0,
       0,   294,   295,   296,   297,   298,   285,   286,     0,     0,
       0,     0,   710,   294,   295,   296,   297,   298,   285,   286,
       0,     0,     0,     0,   711,   294,   295,   296,   297,   298,
     285,   286,     0,     0,     0,     0,   726,     0,     0,     0,
       0,   294,   295,   296,   297,   298,   285,   286,     0,     0,
       0,     0,   727,   287,   288,   289,   290,   291,   292,   293,
     285,   286,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,     0,   728,   294,   295,   296,   297,
     298,     0,     0,   285,   286,     0,     0,   731,   294,   295,
     296,   297,   298,     0,     0,   285,   286,     0,     0,   732,
       0,     0,     0,     0,   294,   295,   296,   297,   298,   285,
     286,     0,     0,     0,     0,   733,     0,     0,   294,   295,
     296,   297,   298,   285,   286,     0,     0,     0,     0,   734,
     287,   288,   289,   290,   291,   292,   293,   285,   286,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,     0,   735,   294,   295,   296,   297,   298,     0,     0,
     285,   286,     0,     0,   736,     0,     0,   294,   295,   296,
     297,   298,   285,   286,     0,     0,     0,     0,   742,     0,
       0,   294,   295,   296,   297,   298,   285,   286,     0,     0,
       0,     0,   743,     0,     0,   294,   295,   296,   297,   298,
     285,   286,     0,     0,     0,     0,   807,   287,   288,   289,
     290,   291,   292,   293,   285,   286,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,     0,   814,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   819,     0,     0,   294,   295,   296,   297,   298,   285,
     286,     0,     0,     0,     0,   820,     0,     0,   294,   295,
     296,   297,   298,   285,   286,     0,     0,   535,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,   285,   286,
       0,   536,   287,   288,   289,   290,   291,   292,   293,  -318,
     285,   286,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,  -311,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,   492,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   553,     0,     0,     0,     0,   294,   295,   296,
     297,   298,   285,   286,     0,     0,   554,     0,     0,     0,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     645,   285,   286,     0,     0,     0,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,   285,   286,   760,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,   822,     0,   695,
     285,   286,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,   828,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,     1,     2,   635,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,     0,     0,    16,     0,    17,
       0,     0,     0,    18,     0,    19,     0,    20,     0,    21,
       0,     0,     0,     0,     0,    22,    23,    24,    25,     0,
       0,    26,    27,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,     0,    31,     0,    32,     0,     0,     0,
      33,     0,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,     0,     0,    39,
      40,     0,    41,     1,     2,    42,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     7,     8,     9,    10,    43,
      11,    12,    13,    14,    15,     0,     0,    16,     0,    17,
       0,     0,     0,    18,     0,    19,     0,    20,     0,    21,
       0,     0,     0,     0,     0,    22,    23,    24,    25,     0,
       0,    26,    27,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,     0,    31,     0,    32,     0,     0,     0,
      33,     0,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,     0,     0,    39,
      40,     0,    41,     0,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,   228,   229,   229,   372,   175,     7,     7,   209,     8,
       9,    11,    12,    13,    27,   622,   301,   624,    46,   373,
       3,     4,    22,    23,     7,    21,    26,    27,     3,     3,
       5,     5,    45,    33,    34,    35,    60,    21,   127,   136,
       3,     4,     3,     4,     0,    40,    41,    42,   137,     8,
       9,   700,   136,   135,   703,   137,    55,    56,    57,    58,
      59,    60,    61,     7,     5,     6,   136,    60,    60,   630,
     631,   127,   136,     8,     9,   135,     7,   137,     5,    60,
     127,   137,     0,    27,    55,    56,    57,    58,    59,    60,
     137,   135,   138,   137,    38,    63,    55,    56,    57,    58,
      59,    60,    61,   388,   389,   133,    61,   136,   136,   133,
      73,   312,   313,    55,    56,    57,    58,    59,    60,   136,
      55,    56,    57,    58,    59,    60,    61,   126,   127,   128,
     129,   130,    27,    28,   135,    66,   135,   133,   137,   700,
     133,   133,   703,   126,   144,    86,    87,    88,   502,   133,
     504,   151,   133,   507,   136,   135,   127,   137,   526,   766,
     160,   136,   136,   126,   135,   126,   137,   126,   127,   128,
     129,   130,   136,   128,   129,   130,   176,   177,   137,   198,
     199,   127,   182,     7,     0,   127,   186,     7,   127,   135,
       7,   126,   127,   128,   129,   130,   135,   197,   198,   199,
     135,     0,   137,    27,   127,     7,   206,   127,     7,   209,
      27,    60,   212,    15,   137,   135,    40,   137,   218,    36,
     135,   221,   137,    22,    23,    27,   127,    60,   228,   229,
      58,    59,    60,    61,   135,    34,    59,    60,    61,   239,
     240,   241,   242,   243,   529,   530,   265,   127,   267,   244,
     245,   246,   247,   209,   127,   135,   133,   137,   258,   259,
     260,   261,   135,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   134,   135,   127,   127,   278,   279,
     280,   281,   282,   283,   284,   639,   137,   137,   135,    60,
     137,   209,    55,    56,    57,    58,    59,    60,   126,   127,
     128,   129,   130,   126,   127,   128,   129,   130,   135,   135,
     137,   137,   312,   313,   484,   485,    60,    61,   127,   319,
     127,   127,   127,   524,    61,    60,   135,   127,   137,   135,
     137,   137,   137,   127,   334,   335,   127,   137,   127,   127,
       5,     6,   342,   137,   344,   144,   137,   701,   137,   137,
     350,   351,   352,   353,   354,   355,   312,   313,   585,   585,
     127,   588,   588,   363,   127,   127,   651,   137,   368,   127,
     137,   127,   372,   135,   137,   602,   137,   176,   177,   137,
     127,   137,   126,   127,   128,   129,   130,   186,   135,   126,
     127,   128,   129,   130,   312,   313,   127,    27,   197,   198,
     199,   127,     0,    33,   605,   127,   137,   206,   127,   127,
     209,   137,   368,   212,   768,   137,   372,   135,   137,   218,
     135,   133,   137,    56,    22,    58,    59,    60,    61,   656,
      56,    57,    58,    59,    60,    61,    34,   127,   127,   136,
     239,   240,   241,   242,   243,   135,   135,   135,   133,   137,
     368,   135,   127,   137,   372,   135,   135,   137,   137,   258,
     259,   260,   261,   136,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,     5,     6,     5,     6,   278,
     279,   280,   281,   282,   283,   284,   136,   487,   488,     5,
       6,   136,   492,   126,   127,   128,   129,   130,   136,   499,
     126,   127,   128,   129,   130,     5,     6,     5,     6,     5,
       6,     5,     6,   312,   313,     5,     6,     5,     6,   136,
     319,     5,     6,   136,   524,   136,   526,     5,     6,   136,
     757,     5,     6,    66,    67,    66,    67,   136,    70,    71,
       5,     6,   136,   136,   136,   344,   136,   136,   136,   136,
     136,   350,   136,   151,   136,   136,   136,   136,   136,   786,
     560,   136,   562,   136,   363,   136,   136,   136,   524,   368,
     526,   136,   136,   372,   136,   136,   576,   136,   176,   177,
     136,   136,   136,   136,   136,   585,   586,   136,   588,   589,
     136,   591,   136,   136,   136,   595,   596,   136,   136,   197,
     198,   199,   602,    30,    46,   605,   524,   136,   526,   810,
     136,   209,   813,   136,   136,   136,   133,   136,   136,   133,
     135,     5,   622,   221,   624,   135,   135,   138,   135,    21,
      21,   135,   135,   834,   835,    61,   837,     5,   135,    76,
     135,     0,   133,   135,   644,   645,   133,   133,    42,   605,
     135,   133,     7,   136,   135,   135,   656,   136,   135,     5,
     136,   136,   135,    22,    23,   136,   136,   265,   136,   267,
     136,   133,     5,   137,   137,    34,   135,   135,     7,     3,
     137,   137,     8,     9,   137,   136,   136,   605,   487,   488,
     136,    60,   137,   492,   137,   695,   137,   137,   136,   133,
     499,   136,   702,   136,    60,    44,    60,     7,    69,    43,
      21,    60,     4,   368,   312,   313,   637,   708,   350,    22,
      22,   229,   757,   599,   488,   524,   802,   526,   487,    55,
      56,    57,    58,    59,    60,    61,   786,   848,   157,   345,
     740,   631,    31,    -1,   744,    -1,   746,    -1,    -1,   749,
      -1,    -1,   350,    -1,    -1,    -1,    -1,   757,    -1,    -1,
      -1,   560,    -1,   562,    -1,    -1,   766,    -1,    -1,    -1,
     368,    -1,    -1,    -1,   372,    -1,    -1,   576,    -1,   779,
     780,    -1,   782,    -1,    -1,    -1,   786,   586,    -1,    -1,
     589,    -1,   591,    -1,    -1,    -1,   595,   596,    -1,    -1,
     126,   127,   128,   129,   130,    -1,   605,    -1,    -1,   135,
     810,   137,    -1,   813,    -1,     8,     9,   176,   177,    -1,
      -1,    -1,    -1,   622,    -1,   624,    -1,   827,    -1,    -1,
      -1,    -1,    -1,    -1,   834,   835,    -1,   837,   197,   198,
     199,    -1,    -1,    -1,    -1,   644,   645,    -1,     6,     7,
     209,   851,    -1,    -1,   810,    -1,    -1,   813,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   834,   835,
      -1,   837,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,
     488,    -1,   810,    -1,    -1,   813,   695,    -1,    -1,    -1,
      -1,   499,    -1,   702,    -1,    -1,   265,    -1,   267,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   834,   835,    -1,   837,
      -1,    -1,    -1,    -1,    -1,    -1,   524,    -1,   526,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,   740,   135,    -1,   137,   744,    -1,   746,    -1,    -1,
     749,    -1,    -1,   312,   313,    -1,    -1,    -1,    -1,    -1,
     319,     4,     5,     6,    -1,    -1,    -1,   766,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   133,    19,    -1,    -1,    -1,
     779,   780,    -1,   782,    -1,    -1,   144,    -1,    -1,    -1,
      -1,   350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   602,    -1,    -1,   605,    -1,   368,
      -1,   810,    -1,   372,   813,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,   622,   183,   624,    -1,   827,    -1,
      -1,    -1,    -1,    -1,    -1,   834,   835,    -1,   837,    -1,
      -1,    -1,    -1,    86,    87,    88,    89,    90,   206,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,   656,    -1,
     218,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,    -1,   117,    -1,   119,    -1,   121,   122,
     123,   239,   240,   241,   242,   243,   244,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,
     258,   259,   260,   261,   702,   263,   264,    -1,   266,    -1,
     268,   269,   270,   271,   272,   273,    -1,    -1,    -1,    -1,
     278,   279,   280,   281,   282,   283,   284,    -1,   487,   488,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     499,    -1,   300,   301,    -1,    -1,    -1,    -1,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   757,
      -1,    -1,    -1,    -1,    -1,   524,    -1,   526,   766,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,   344,    -1,   786,    -1,
     348,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,   363,    -1,    -1,    -1,    -1,
      -1,    -1,   810,    -1,    -1,   813,    -1,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,
     388,   389,   218,    -1,    -1,    -1,   834,   835,    -1,   837,
      -1,    -1,   228,   229,    -1,    -1,   605,    -1,   126,   127,
     128,   129,   130,   239,   240,   241,   242,   243,    -1,   137,
       8,     9,    -1,   622,    -1,   624,    -1,   126,   127,   128,
     129,   130,   258,   259,   260,   261,   135,   263,   264,    -1,
     266,    -1,   268,   269,   270,   271,   272,   273,    -1,    -1,
      -1,    -1,   278,   279,   280,   281,   282,   283,   284,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   492,    -1,   494,    -1,    -1,    -1,
      -1,    -1,    -1,   702,     8,     9,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,   344,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   529,   530,    -1,    -1,    -1,    -1,   363,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,   135,    -1,   137,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,   560,    -1,   562,    -1,    -1,   766,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,   576,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,   586,    -1,
     137,   589,    -1,   591,    -1,    -1,    -1,   595,   596,    -1,
      -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,   810,    -1,    -1,   813,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,     8,   834,   835,    -1,   837,   126,
     127,   128,   129,   130,    -1,    -1,   644,   645,    -1,    -1,
     137,    -1,    -1,   651,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,   492,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   695,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
     130,    -1,    -1,    -1,   560,    -1,   562,   137,    -1,    -1,
      -1,    -1,   740,    -1,    -1,    -1,   744,     6,   746,    -1,
     576,   749,   126,   127,   128,   129,   130,    16,    -1,   585,
     586,    -1,   588,   589,    -1,   591,    -1,    -1,    -1,   595,
     596,    -1,    -1,    -1,     8,     9,   602,    -1,    -1,    -1,
      -1,   779,   780,    -1,   782,   126,   127,   128,   129,   130,
       8,     9,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   802,    64,    -1,     8,     9,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,   644,   645,
      79,    55,    56,    57,    58,    59,    60,    61,    -1,   827,
     656,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   695,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,     8,     9,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,   740,    -1,    -1,    -1,   744,   137,
     746,    -1,    -1,   749,   183,   126,   127,   128,   129,   130,
      -1,   757,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,   200,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,   211,   779,   780,   214,   782,    -1,    -1,    -1,
     786,     8,     9,   222,   223,    -1,   225,    -1,    -1,    -1,
      -1,   230,   231,   232,   233,   234,   235,   236,   237,   238,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
      -1,   827,    -1,   262,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,   126,   127,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
      -1,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   311,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,     8,     9,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,   337,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,   348,
     137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   364,   365,    51,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,
     389,    -1,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    -1,    93,
      -1,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    -1,    -1,   126,   127,   128,   129,
     130,    -1,   136,    -1,   138,   454,   455,   137,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   494,    -1,   496,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,   516,   517,   518,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
     529,   530,    -1,    -1,    -1,   534,   535,   536,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   544,   545,    55,    56,    57,
      58,    59,    60,    61,   553,   554,   555,   556,   557,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,   571,    -1,    -1,   574,    18,    19,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     599,    -1,   137,    -1,    -1,   604,    -1,    -1,   607,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      -1,    93,   651,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   712,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,   737,     8,
       9,    10,    11,     8,     9,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    -1,   753,    -1,   755,    -1,    -1,    -1,
      -1,   760,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,   783,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,   802,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   822,    93,    -1,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     8,
       9,   126,   127,   128,   129,   130,    -1,   136,    -1,    -1,
      -1,    -1,   137,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,     8,     9,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,
      -1,   126,   127,   128,   129,   130,     8,     9,    -1,    -1,
      -1,    -1,   137,   126,   127,   128,   129,   130,     8,     9,
      -1,    -1,    -1,    -1,   137,   126,   127,   128,   129,   130,
       8,     9,    -1,    -1,    -1,    -1,   137,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,     8,     9,    -1,    -1,
      -1,    -1,   137,    55,    56,    57,    58,    59,    60,    61,
       8,     9,    -1,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   126,   127,   128,   129,
     130,    -1,    -1,     8,     9,    -1,    -1,   137,   126,   127,
     128,   129,   130,    -1,    -1,     8,     9,    -1,    -1,   137,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,   130,     8,
       9,    -1,    -1,    -1,    -1,   137,    -1,    -1,   126,   127,
     128,   129,   130,     8,     9,    -1,    -1,    -1,    -1,   137,
      55,    56,    57,    58,    59,    60,    61,     8,     9,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,   137,   126,   127,   128,   129,   130,    -1,    -1,
       8,     9,    -1,    -1,   137,    -1,    -1,   126,   127,   128,
     129,   130,     8,     9,    -1,    -1,    -1,    -1,   137,    -1,
      -1,   126,   127,   128,   129,   130,     8,     9,    -1,    -1,
      -1,    -1,   137,    -1,    -1,   126,   127,   128,   129,   130,
       8,     9,    -1,    -1,    -1,    -1,   137,    55,    56,    57,
      58,    59,    60,    61,     8,     9,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,
     126,   127,   128,   129,   130,     8,     9,    -1,    -1,    -1,
      -1,   137,    -1,    -1,   126,   127,   128,   129,   130,     8,
       9,    -1,    -1,    -1,    -1,   137,    -1,    -1,   126,   127,
     128,   129,   130,     8,     9,    -1,    -1,   135,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,   130,    -1,     8,     9,
      -1,   135,    55,    56,    57,    58,    59,    60,    61,     7,
       8,     9,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    65,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,   130,     8,     9,    -1,    -1,   135,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
     135,     8,     9,    -1,    -1,    -1,   126,   127,   128,   129,
     130,     8,     9,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,     8,     9,    32,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,    34,    -1,    65,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    42,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,   130,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      -1,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,    91,
      92,    -1,    94,     5,     6,    97,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,   111,
      22,    23,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      -1,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,    41,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,    -1,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,    91,
      92,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111
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
       5,     6,    76,   176,     5,   276,     6,   135,   135,   272,
     272,   168,    65,   134,   135,     3,   136,   272,   165,   261,
     256,   133,   267,   133,   268,   165,   168,   218,     7,   217,
     160,   272,   272,   272,   272,   272,   135,   135,   135,   165,
     168,   168,   137,   144,    42,   145,   217,   136,   136,   136,
     136,   136,   136,   188,   135,   135,   135,   183,   183,   136,
     136,   137,   137,   133,   135,   135,   137,   137,   137,   137,
     137,   137,   137,   135,   135,   135,   135,   135,   137,   137,
     135,   137,   135,   137,   137,   137,   137,   137,   137,   137,
     137,   135,   137,   137,   135,   137,   135,   137,   137,   137,
     137,   137,   137,   137,   137,   135,   135,   137,   135,   135,
     137,   135,   137,   137,   137,   135,   135,   168,   168,   135,
     137,   137,   136,     6,   207,   232,    27,    38,   238,    27,
      40,   227,   136,   136,   177,   177,   200,   202,   137,   165,
     165,   168,   259,   168,   258,   254,   272,   273,   275,   276,
     217,   217,   217,     3,     4,     7,   126,   155,   156,   157,
     158,   168,   168,   168,   135,   135,   142,   246,   145,   137,
     137,   277,   183,   183,   137,   137,   136,   168,   168,   168,
     137,   137,     5,     6,   168,   168,   168,   168,   168,   168,
     168,   165,   165,   168,   168,   165,   172,   165,   172,   165,
     165,   165,   165,   184,     6,   197,   198,   272,   274,   275,
     278,   168,   142,   168,   228,    65,   254,   137,   254,   266,
     269,   270,   271,   269,   219,     3,    73,   156,   135,   217,
     137,   137,   135,   137,   165,   165,   242,   183,   137,   137,
     203,   204,   272,   274,   275,   278,   137,   137,   137,   136,
     136,   137,   137,   137,   137,   137,   137,   135,   137,   137,
     135,   137,   137,   137,   135,   137,   135,   137,   137,   135,
     137,   137,   137,   135,   137,   135,   137,   135,   137,   133,
      32,    27,    36,   233,   239,   165,   260,    67,   270,   217,
     272,   273,   275,   276,    67,    70,    71,   221,   158,    60,
      60,   168,    60,    44,   251,   137,   135,   137,   168,   165,
     165,   165,   165,   168,   168,   198,   195,     6,   168,   234,
     254,   217,   220,     7,    69,   165,   165,   137,   165,   168,
      43,   250,   204,   189,   137,   137,   137,   137,   137,   137,
     137,    21,    34,   212,   218,   222,   216,    60,    42,   142,
     243,   142,     4,   168,   208,   223,   165,   252,    27,    45,
     248,    15,    27,   190,   142,   142,   142,   209,   253,    27,
      33,   210,   251,   211,   272
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
     173,   173,   173,   173,   174,   173,   175,   175,   176,   177,
     177,   178,   178,   178,   178,   179,   179,   180,   181,   181,
     182,   183,   183,   184,   184,   186,   187,   188,   189,   185,
     190,   190,   191,   191,   193,   194,   195,   192,   196,   196,
     197,   197,   197,   198,   198,   198,   198,   199,   199,   200,
     200,   200,   200,   201,   201,   202,   202,   202,   202,   203,
     203,   203,   204,   204,   204,   204,   206,   207,   208,   209,
     205,   210,   210,   211,   211,   212,   212,   214,   215,   216,
     213,   217,   217,   218,   218,   219,   220,   219,   221,   222,
     223,   221,   225,   226,   224,   227,   228,   227,   230,   231,
     232,   229,   233,   234,   233,   236,   237,   235,   238,   239,
     238,   241,   242,   243,   240,   245,   246,   244,   247,   244,
     248,   248,   249,   250,   250,   251,   252,   253,   251,   254,
     254,   254,   254,   255,   255,   255,   255,   255,   255,   255,
     257,   256,   258,   256,   259,   256,   260,   256,   261,   262,
     262,   262,   262,   263,   264,   264,   265,   265,   267,   266,
     268,   266,   269,   269,   270,   270,   270,   270,   270,   271,
     272,   272,   273,   273,   273,   273,   274,   274,   274,   274,
     275,   275,   276,   276,   276,   277,   276,   278,   278,   278,
     278
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
       6,     8,     4,     4,     0,     5,     2,     1,     1,     0,
       2,     2,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     0,     0,     0,     0,    11,
       1,     1,     1,     1,     0,     0,     0,    10,     1,     1,
       0,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     0,
       1,     3,     1,     1,     1,     1,     0,     0,     0,     0,
      14,     1,     1,     0,     1,     0,     2,     0,     0,     0,
       9,     1,     2,     1,     1,     0,     0,     4,     0,     0,
       0,     5,     0,     0,     5,     1,     0,     2,     0,     0,
       0,     7,     1,     0,     2,     0,     0,     5,     1,     0,
       3,     0,     0,     0,    10,     0,     0,     5,     0,     5,
       1,     1,     1,     0,     2,     0,     0,     0,     7,     1,
       1,     1,     1,     0,     1,     3,     1,     3,     5,     3,
       0,     3,     0,     4,     0,     4,     0,     6,     1,     0,
       2,     2,     4,     1,     1,     3,     1,     3,     0,     7,
       0,     7,     2,     3,     1,     2,     2,     2,     2,     0,
       1,     3,     2,     6,     3,     4,     3,     5,     3,     5,
       1,     3,     2,     6,     3,     0,     7,     3,     5,     3,
       5
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
      -1,    76,    -1,    -1,    46,   176,    -1,     5,   177,    -1,
     276,   177,    -1,   178,   135,     5,   177,    -1,   178,   135,
     276,   177,    -1,   273,    -1,   274,    -1,   273,    -1,   276,
      -1,   278,    -1,   276,    -1,   184,    -1,   183,   135,   184,
      -1,   165,    -1,   168,    -1,    -1,    -1,    -1,    -1,    14,
     186,   187,   191,   188,   136,   203,   137,   189,   142,   190,
      -1,    27,    -1,    15,    -1,   272,    -1,   275,    -1,    -1,
      -1,    -1,    20,   193,   196,   194,   136,   197,   137,   195,
      21,     4,    -1,   272,    -1,   275,    -1,    -1,   198,    -1,
     197,   135,   198,    -1,   272,    -1,   275,    -1,   274,    -1,
     278,    -1,   200,    -1,   199,   135,   200,    -1,   272,    -1,
     275,    -1,   273,    -1,   276,    -1,   202,    -1,   201,   135,
     202,    -1,   272,    -1,   275,    -1,   273,    -1,   276,    -1,
      -1,   204,    -1,   203,   135,   204,    -1,   272,    -1,   275,
      -1,   274,    -1,   278,    -1,    -1,    -1,    -1,    -1,    31,
     206,   272,    60,   207,   168,    32,   168,   212,   208,   142,
     209,   210,   211,    -1,    27,    -1,    33,    -1,    -1,   272,
      -1,    -1,    34,   168,    -1,    -1,    -1,    -1,    68,   214,
     215,   218,   217,   219,   221,    69,   216,    -1,     7,    -1,
     217,     7,    -1,   168,    -1,   165,    -1,    -1,    -1,   219,
      70,   220,   218,    -1,    -1,    -1,    -1,    71,     7,   222,
     223,   142,    -1,    -1,    -1,    39,   225,   226,   142,   227,
      -1,    27,    -1,    -1,    40,   228,    -1,    -1,    -1,    -1,
      35,   230,   231,   168,   232,   142,   233,    -1,    27,    -1,
      -1,    36,   234,    -1,    -1,    -1,    37,   236,   237,   142,
     238,    -1,    27,    -1,    -1,    38,   168,   239,    -1,    -1,
      -1,    -1,   249,   168,   241,    42,   142,   242,   251,   250,
     243,   248,    -1,    -1,    -1,   249,   168,   245,   145,   246,
      -1,    -1,   249,   168,   247,   217,   145,    -1,    27,    -1,
      45,    -1,    41,    -1,    -1,    43,   142,    -1,    -1,    -1,
      -1,    44,   168,    42,   252,   142,   253,   251,    -1,   272,
      -1,   275,    -1,   273,    -1,   276,    -1,    -1,   168,    -1,
     168,    65,   165,    -1,   165,    -1,   255,   135,   168,    -1,
     255,   135,   168,    65,   165,    -1,   255,   135,   165,    -1,
      -1,   257,   261,   254,    -1,    -1,   138,   272,   258,   254,
      -1,    -1,   138,     3,   259,   254,    -1,    -1,   138,   136,
     168,   137,   260,   254,    -1,   165,    -1,    -1,   138,   272,
      -1,   138,     3,    -1,   138,   136,   168,   137,    -1,    30,
      -1,   272,    -1,   264,   135,   272,    -1,   272,    -1,   265,
     135,   272,    -1,    -1,    66,   271,   272,   267,   217,   269,
      67,    -1,    -1,    66,   271,   273,   268,   217,   269,    67,
      -1,   270,   217,    -1,   269,   270,   217,    -1,   266,    -1,
     271,   272,    -1,   271,   275,    -1,   271,   273,    -1,   271,
     276,    -1,    -1,     5,    -1,   272,   133,     5,    -1,     5,
     136,    -1,   273,   133,     5,   136,   183,   137,    -1,   273,
     133,     5,    -1,   272,   133,     5,   136,    -1,     5,   136,
     137,    -1,   274,   133,     5,   136,   137,    -1,   274,   133,
       5,    -1,   272,   133,     5,   136,   137,    -1,     6,    -1,
     272,   133,     6,    -1,     6,   136,    -1,   273,   133,     6,
     136,   183,   137,    -1,   273,   133,     6,    -1,    -1,   272,
     133,     6,   136,   277,   183,   137,    -1,     6,   136,   137,
      -1,   274,   133,     6,   136,   137,    -1,   274,   133,     6,
      -1,   272,   133,     6,   136,   137,    -1
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
     864,   867,   870,   873,   878,   883,   885,   887,   889,   891,
     893,   895,   897,   901,   903,   905,   906,   907,   908,   909,
     921,   923,   925,   927,   929,   930,   931,   932,   943,   945,
     947,   948,   950,   954,   956,   958,   960,   962,   964,   968,
     970,   972,   974,   976,   978,   982,   984,   986,   988,   990,
     991,   993,   997,   999,  1001,  1003,  1005,  1006,  1007,  1008,
    1009,  1024,  1026,  1028,  1029,  1031,  1032,  1035,  1036,  1037,
    1038,  1048,  1050,  1053,  1055,  1057,  1058,  1059,  1064,  1065,
    1066,  1067,  1073,  1074,  1075,  1081,  1083,  1084,  1087,  1088,
    1089,  1090,  1098,  1100,  1101,  1104,  1105,  1106,  1112,  1114,
    1115,  1119,  1120,  1121,  1122,  1133,  1134,  1135,  1141,  1142,
    1148,  1150,  1152,  1154,  1155,  1158,  1159,  1160,  1161,  1169,
    1171,  1173,  1175,  1177,  1178,  1180,  1184,  1186,  1190,  1196,
    1200,  1201,  1205,  1206,  1211,  1212,  1217,  1218,  1225,  1227,
    1228,  1231,  1234,  1239,  1241,  1243,  1247,  1249,  1253,  1254,
    1262,  1263,  1271,  1274,  1278,  1280,  1283,  1286,  1289,  1292,
    1293,  1295,  1299,  1302,  1309,  1313,  1318,  1322,  1328,  1332,
    1338,  1340,  1344,  1347,  1354,  1358,  1359,  1367,  1371,  1377,
    1381
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
     501,   502,   503,   504,   505,   505,   508,   509,   512,   517,
     518,   526,   533,   534,   539,   542,   543,   546,   549,   550,
     553,   556,   557,   560,   561,   564,   564,   566,   569,   564,
     578,   584,   587,   590,   593,   596,   599,   593,   607,   613,
     621,   622,   623,   626,   629,   632,   635,   640,   641,   644,
     645,   646,   647,   650,   651,   654,   655,   656,   657,   660,
     661,   662,   665,   666,   669,   672,   677,   678,   682,   684,
     677,   690,   695,   698,   699,   702,   703,   706,   706,   708,
     706,   713,   714,   717,   718,   721,   722,   722,   730,   731,
     731,   731,   737,   737,   737,   742,   743,   743,   746,   746,
     747,   746,   753,   754,   754,   757,   757,   757,   762,   764,
     763,   767,   768,   770,   767,   774,   775,   774,   776,   776,
     780,   781,   784,   787,   788,   791,   793,   795,   792,   799,
     800,   801,   802,   805,   806,   811,   813,   815,   817,   819,
     823,   823,   824,   824,   825,   825,   826,   826,   829,   833,
     838,   839,   840,   843,   846,   847,   850,   851,   855,   855,
     871,   871,   889,   890,   893,   894,   902,   910,   918,   928,
     936,   940,   943,   945,   946,   947,   950,   953,   954,   955,
     958,   959,   962,   963,   964,   965,   965,   968,   969,   970,
     971
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
  const int parser::yylast_ = 3499;
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
#line 4357 "/home/cai/projects/basic/compiler/parser.cpp"
