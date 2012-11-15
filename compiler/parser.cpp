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
#line 196 "parser.ypp"
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
#line 206 "parser.ypp"
    { (yyval.statement_list) = (yysemantic_stack_[(1) - (1)].statement_list); debug("list_of_statement_lists\n"); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 210 "parser.ypp"
    { (yyval.statement_list) = new StatementsAST(); (yyval.statement_list)->append(StatementASTPtr((yysemantic_stack_[(1) - (1)].statement)));}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 211 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 211 "parser.ypp"
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
#line 220 "parser.ypp"
    { (yyval.statement) = 0 ;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 221 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 235 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { debug ("cannot \"break\" outside of loop"); }
   }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   debug ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 248 "parser.ypp"
    { }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 249 "parser.ypp"
    { }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 250 "parser.ypp"
    {if (function_type==ftNONE) debug("declaring variables \"local\" outside of a function has no effect"); }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 251 "parser.ypp"
    {if (function_type==ftNONE) debug("declaring variables \"static\" outside of a function has no effect"); }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 252 "parser.ypp"
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
#line 260 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 265 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 270 "parser.ypp"
    { until_eol = false; }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 270 "parser.ypp"
    {}
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 271 "parser.ypp"
    { until_eol = true; }
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 271 "parser.ypp"
    {}
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 272 "parser.ypp"
    {
	   
             }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 275 "parser.ypp"
    {

	   
   }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 280 "parser.ypp"
    { }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 281 "parser.ypp"
    {
	   debug("got syntax of \"dim local var\" now\n");

	   (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list);	   
	}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 286 "parser.ypp"
    {
	   
}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    {}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 290 "parser.ypp"
    {}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 291 "parser.ypp"
    {}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    {}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 293 "parser.ypp"
    {}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 294 "parser.ypp"
    {}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 295 "parser.ypp"
    {}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 296 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 297 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 300 "parser.ypp"
    {

   }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 303 "parser.ypp"
    {  }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 304 "parser.ypp"
    {
		debug("got label!\n");
   }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    {  }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 308 "parser.ypp"
    {  }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 309 "parser.ypp"
    {  }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 309 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 312 "parser.ypp"
    { }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 312 "parser.ypp"
    {  }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 313 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 330 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 331 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 338 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 339 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 340 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 341 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 344 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 345 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 348 "parser.ypp"
    {
		// 变量赋值
		debug("变量赋值\n");
		(yyval.number_assignment) = new NumberAssigmentAST(VariableRefExprASTPtr((yysemantic_stack_[(3) - (1)].varable_ref)), NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
	}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 353 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 356 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 358 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 359 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 360 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 361 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 366 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 367 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 370 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 373 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 374 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 381 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 382 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 389 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 390 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 414 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 415 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 419 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 420 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 421 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 422 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 423 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 425 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 427 "parser.ypp"
    {
	   (yyval.number_expression) = (yysemantic_stack_[(2) - (2)].number_expression) ;
   }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 430 "parser.ypp"
    {
	   /*add_command(cNEGATE,NULL);*/
	   ConstNumberExprAST * zero = new ConstNumberExprAST(0);
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr(zero) ,OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression)));
   }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 435 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_MUL,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 438 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_DIV,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 441 "parser.ypp"
    {
	   // 减法计算
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 445 "parser.ypp"
    {
	   // 加法计算.
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_ADD,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 449 "parser.ypp"
    { (yyval.number_expression) = (yysemantic_stack_[(3) - (2)].number_expression) ;}
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 450 "parser.ypp"
    {
	   debug("got numsym_s\n");	   
	   (yyval.number_expression) =new NumberExprAST( VariableExprASTPtr((yysemantic_stack_[(1) - (1)].varable_ref)) );
	}
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 454 "parser.ypp"
    {
	   (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));
   }
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 459 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 462 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 465 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 466 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 467 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 468 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 469 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 470 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 471 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 472 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 473 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 474 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 475 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 476 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 477 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 478 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 479 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 480 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 481 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 482 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 483 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 484 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 487 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 488 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 489 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 491 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 492 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 495 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 496 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 497 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 498 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 499 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 500 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 502 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 503 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 504 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 505 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 506 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 205:
/* Line 661 of lalr1.cc  */
#line 506 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 513 "parser.ypp"
    {
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 516 "parser.ypp"
    {
		//TODO int should be 32bit not 64bit
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 523 "parser.ypp"
    {
			debug("as  %s\n",(yysemantic_stack_[(2) - (2)].exprtype)->name.c_str());
			// long varable
			// 构造类型
			(yyval.exprtype) = (yysemantic_stack_[(2) - (2)].exprtype);
		}
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 531 "parser.ypp"
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
#line 538 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 539 "parser.ypp"
    {
	  // 	std::string name;
	//	name = $3;
	//	$$ = new VariableDimAST( name , ExprTypeASTPtr($2));
   }
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 544 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 547 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 548 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 551 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 219:
/* Line 661 of lalr1.cc  */
#line 554 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 220:
/* Line 661 of lalr1.cc  */
#line 555 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 558 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 561 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 223:
/* Line 661 of lalr1.cc  */
#line 562 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 569 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 569 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
if (function_type!=ftNONE) {debug("functions cannot be nested");}}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 571 "parser.ypp"
    {
	   
}
    break;

  case 229:
/* Line 661 of lalr1.cc  */
#line 574 "parser.ypp"
    {
	   
}
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 578 "parser.ypp"
    {
	
   }
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 583 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 589 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 592 "parser.ypp"
    {
	//function_type=ftNUMBER;current_function = dotify ($1); $$ = dotify ($1);
	}
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 595 "parser.ypp"
    {/*function_type=ftSTRING;current_function = dotify ($1); $$ = dotify ($1);*/}
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 598 "parser.ypp"
    {
	
                      }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 601 "parser.ypp"
    {
						  
                      }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 604 "parser.ypp"
    {
						  
                      }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 607 "parser.ypp"
    {
						  
                      }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 612 "parser.ypp"
    {
//                    function_type = ftNUMBER;
//                    cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_NUMBER;
//                    current_function = mystrdup ($1);
//                    $$ = mystrdup ($1);
                }
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 618 "parser.ypp"
    {
//         function_type = ftSTRING;
//         cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_STRING;
//         current_function = mystrdup ($1);
//         $$ = mystrdup ($1);
     }
    break;

  case 244:
/* Line 661 of lalr1.cc  */
#line 631 "parser.ypp"
    {
//                          create_require (stNUMBER); create_makelocal (dotify ($1), syNUMBER); add_command (cPOPNUMSYM, dotify ($1));
                      }
    break;

  case 245:
/* Line 661 of lalr1.cc  */
#line 634 "parser.ypp"
    {
//         create_require (stSTRING); create_makelocal (dotify ($1), sySTRING); add_command (cPOPSTRSYM, dotify ($1));
     }
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 637 "parser.ypp"
    {
//         create_require (stNUMBERARRAYREF); create_arraylink (dotify ($1), stNUMBERARRAYREF);
     }
    break;

  case 247:
/* Line 661 of lalr1.cc  */
#line 640 "parser.ypp"
    {
//         create_require (stSTRINGARRAYREF); create_arraylink (dotify ($1), stSTRINGARRAYREF);
     }
    break;

  case 250:
/* Line 661 of lalr1.cc  */
#line 649 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 650 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 252:
/* Line 661 of lalr1.cc  */
#line 651 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 652 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 659 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 660 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 661 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 662 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 670 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 671 "parser.ypp"
    {
	   
}
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 674 "parser.ypp"
    {
	   
}
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 677 "parser.ypp"
    {
	   
}
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 682 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 683 "parser.ypp"
    {
				 
			}
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 687 "parser.ypp"
    {
	 }
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 689 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 691 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 695 "parser.ypp"
    {
		if (unclosed_fors) {
			debug ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 700 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 703 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 704 "parser.ypp"
    {  }
    break;

  case 276:
/* Line 661 of lalr1.cc  */
#line 707 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 711 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 711 "parser.ypp"
    {
	}
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 713 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 713 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 718 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 719 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 727 "parser.ypp"
    {
	   
}
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 730 "parser.ypp"
    {
		   
	}
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 736 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 736 "parser.ypp"
    {

	   
}
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 742 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 742 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 747 "parser.ypp"
    {if (unclosed_dos) { debug ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 748 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 748 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 751 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 751 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 752 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 758 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 759 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 759 "parser.ypp"
    { }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 762 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 762 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 767 "parser.ypp"
    {if (unclosed_repeats) { debug ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 769 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 769 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 772 "parser.ypp"
    {
				/*构造 IF 语句, 填充 条件表达式*/
				NumberExprASTPtr ne = NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression));

								
			}
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 777 "parser.ypp"
    {  /*填充真语句*/ }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 779 "parser.ypp"
    { /*填充假语句*/}
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 783 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 785 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 786 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 789 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 790 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 793 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 802 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 804 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 808 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 809 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 810 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 811 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 814 "parser.ypp"
    { debug("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 815 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 821 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 823 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 825 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 827 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 829 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 832 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 833 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 834 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 835 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 839 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 842 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 847 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 848 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 849 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 852 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 855 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 856 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 859 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 860 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 864 "parser.ypp"
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
#line 874 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 880 "parser.ypp"
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
#line 890 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 903 "parser.ypp"
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
#line 911 "parser.ypp"
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
#line 919 "parser.ypp"
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
#line 927 "parser.ypp"
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
#line 937 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 945 "parser.ypp"
    {
		debug("变量引用\n");
		(yyval.varable_ref) = new VariableRefExprAST( (yysemantic_stack_[(1) - (1)].symbol) );
	}
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 949 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 952 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 954 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 955 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 956 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 959 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 962 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 963 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 964 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 967 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 968 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 971 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 972 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 973 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 974 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 974 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 977 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 978 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 979 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 980 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2642 "/home/cai/projects/basic/compiler/parser.cpp"
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
      3445,   -46,   -32,  -607,  -607,  -607,  2263,   966,    -4,    12,
    -607,   134,   134,   134,  -607,  -607,  2263,  -607,  -607,  -607,
    -607,  -607,    19,   158,  -607,  -607,   134,   134,   -84,  -607,
      81,  -607,  -607,   134,   232,   134,    40,    58,    72,  1822,
    1822,  1822,  1822,    84,   213,   300,   168,  -607,  -607,  -607,
    -607,  -607,   195,  -607,   228,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  2263,  -607,    -8,    -7,   190,   278,
     305,  -607,   204,   210,  -607,  -607,  -607,   264,   273,  2263,
     283,   314,   325,   340,   354,   374,   381,   388,   392,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   404,   405,
     412,   415,   417,   419,   420,   421,   424,   427,   428,   429,
     430,   432,   434,   436,   437,   438,   440,   443,   444,  -607,
    -607,   445,   446,   447,   450,   455,   456,   457,   466,   467,
     470,  2263,  2263,  2263,   -10,  -607,  3215,  -607,  -607,  -607,
     247,   282,  -607,  -607,   966,   299,   247,   282,   190,  -607,
    -607,   303,  -607,   322,   322,   322,   509,   509,   -10,  3215,
     134,  -607,  -607,  -607,   473,   482,  -607,  -607,     6,   282,
    -607,   -20,   482,   339,   484,   543,   232,   232,   490,   322,
     491,   322,    11,  2263,   431,  -607,   616,  -607,   322,   492,
    -607,    13,    17,   599,   603,   494,   322,   232,   232,   232,
    2263,  3215,   495,  -607,   496,   499,   966,  -607,  -607,  3445,
    -607,  2263,   966,  3117,  2263,   380,   386,   433,   966,  -607,
    -607,   303,  2263,  2263,  1091,  2263,  -607,  -607,   481,   481,
    2263,  2263,  2065,  2263,  2263,  2263,  2263,  2263,  2263,   966,
     966,   966,   966,   966,  1822,  1822,  1822,  1822,  2263,  2263,
    2263,  2263,  2263,  2263,  2263,  2263,  2263,  2263,   966,   966,
     966,   966,  2263,   966,   966,   232,   966,   232,   966,   966,
     966,   966,   966,   966,   567,   567,   193,  1196,   966,   966,
     966,   966,   966,   966,   966,  -607,  -607,  2263,  2263,  2263,
    2263,  2263,  2263,  2263,  2263,  2263,  2263,  2263,  2263,   -55,
    2263,  2263,  -607,  -607,   504,  -607,   633,  -607,  -607,  -607,
       8,  2263,  3445,  3445,  -607,  -607,   485,   127,  -607,   489,
     493,  -607,   506,  -607,   519,   282,  -607,  -607,   507,  -607,
     519,   282,  -607,  -607,   134,   134,  -607,  2263,   322,   -10,
    3125,   370,    15,  -607,   966,   431,   520,   521,  2263,   634,
     232,   134,   134,   134,   134,   134,   522,   519,  -607,  -607,
     524,   525,  3215,   966,  2263,  2263,    75,   168,  3445,  3215,
     299,   596,  3445,   634,  3215,   528,   529,   531,   533,   534,
     535,   299,  -607,   504,  -607,    37,   916,  2986,  2263,  2263,
     536,   537,   538,   539,   544,   190,  -607,   526,   546,  1330,
    1343,  -607,  1363,  1426,  1520,  1826,  1959,  3000,  3083,   -56,
     -44,   259,   175,   178,    18,   547,   541,   548,   552,  1972,
    1999,  2191,  2277,  2385,    63,  2402,   590,   673,  2414,   182,
     194,   197,   198,  2426,   199,   260,   -70,   272,    97,   275,
     202,   217,   218,   279,   285,  -607,  -607,   299,   299,   299,
     299,   299,   299,  -607,  2263,  2263,   373,   170,   486,   164,
     157,   -42,  -607,    41,    41,   567,   567,   567,   -10,  3215,
     137,  -607,   166,   554,   503,  -607,  -607,  3215,   130,   174,
     555,   557,  -607,  -607,  -607,   -20,   543,   557,   232,   232,
     322,   322,  2441,   966,  -607,  2263,  -607,  2263,   322,   299,
     232,  -607,   653,   634,   655,   634,   -10,  3215,   634,  -607,
      34,  -607,   322,   322,   322,   322,   322,  2263,  2263,  2263,
     286,  3097,  3215,  -607,  -607,  3445,  -607,  3350,   558,   559,
    2263,  2263,   560,   561,   564,  2263,  2263,  2263,   281,   287,
     204,   210,  -607,  -607,   505,  2263,  2263,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  2263,  2263,  2263,  2263,  2263,  -607,
    -607,   966,  -607,   966,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  2263,  -607,  -607,  2263,  -607,   966,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,   481,   966,  -607,   481,
     966,  -607,   966,  -607,  -607,  -607,   966,   966,  1091,     1,
    2263,  -607,  -607,   510,  -607,  2263,  3445,  -607,  2263,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
     299,   -10,  3139,   232,  2527,   232,  -607,   519,   282,  -607,
    -607,    46,    46,   678,  -607,  -607,  -607,   683,    26,  -607,
      -1,  -607,  2539,  2551,   808,   966,   966,   168,  -607,  -607,
    -607,  -607,  2263,   290,   308,  -607,  -607,   510,  2566,  2583,
    2666,  -607,  -607,   566,   568,  2678,  2691,  2708,  2722,  2805,
    2817,  1150,   219,    50,  2833,  2847,    51,   309,   231,   312,
     236,   240,    78,   181,  -607,   537,   316,  -607,   570,   190,
    -607,  -607,  3201,   268,  3215,  -607,   966,  -607,  -607,  -607,
    -607,   449,   634,   232,   453,   451,  -607,  -607,  -607,    28,
     678,   645,   646,  2263,   648,   299,   299,   666,   319,  -607,
    -607,   338,  -607,   570,   190,  -607,  -607,  -607,  -607,  -607,
     558,   559,  -607,  -607,  -607,  -607,  -607,  -607,  2263,  -607,
    -607,   966,  -607,  -607,  -607,   966,  -607,   966,  -607,  -607,
     966,  -607,  -607,  -607,  2263,  -607,  2263,  -607,   510,  -607,
     523,  2263,  -607,  -607,  -607,  -607,   299,   232,  -607,   634,
     678,   519,   282,  -607,  -607,  -607,  -607,   706,   643,  -607,
     966,   966,  2861,   966,  2263,   672,  -607,   510,  -607,  2944,
     242,   244,   245,   251,  2958,  2972,  -607,   700,   568,  3181,
    -607,  -607,   678,  2263,  -607,  -607,   299,   299,   662,   299,
    3222,  3445,  -607,  -607,  3445,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,   721,  2263,  -607,  -607,  -607,  -607,   966,  -607,
     168,    10,    76,  -607,  3215,  3445,  3445,   299,  3445,  -607,
    -607,  -607,  -607,  -607,  -607,   168,   168,   168,   227,   666,
    -607,  -607,   134,  -607,  -607,   322
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
      -607,  -607,  -607,  -201,  -607,   369,  -369,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,   100,  -607,    30,
    -607,   390,  -607,   720,   722,   -82,   855,  -607,  -607,  1509,
    -607,  -607,   514,  -225,  -607,  -607,     2,  -607,  -170,  -607,
      82,  -607,   184,  -607,  -286,   146,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,    -9,
    -607,   263,  -607,   265,  -607,   -39,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -363,   -51,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,  -607,
    -607,  -607,   -94,  -607,  -607,  -606,  -607,   411,  -607,  -607,
    -607,  -607,  -607,  -607,   600,  -607,  -607,  -566,  -607,  -607,
     128,  -591,   728,     0,   201,  1034,   403,   642,  -607,  -227
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
     527,   153,   154,   155,   336,   472,   152,   697,   496,   699,
     152,   293,   168,   174,   164,   165,   179,   181,   317,   634,
     635,   634,   635,   188,   191,   196,   351,   634,   635,   839,
     352,   636,   203,   204,   205,   285,   286,   278,   279,   280,
     281,   282,   283,   636,   214,  -218,   182,   840,   287,   288,
     289,   290,   291,   292,   293,   700,   700,   587,   214,   588,
     476,   285,   286,   284,   284,   278,   279,   280,   281,   282,
     283,   556,    51,   210,   445,   284,   294,   295,   296,   297,
     298,   842,    72,   557,   287,   288,   289,   290,   291,   292,
     293,   707,   538,   539,   293,   843,    73,    36,    37,    38,
     769,   478,   479,   769,    31,  -371,   360,   361,   314,   284,
     287,   288,   289,   290,   291,   292,   293,   215,   216,   294,
     295,   296,   297,   298,   149,   700,   709,   210,   700,   152,
     631,   316,   632,   306,   146,   633,   185,   284,   316,   337,
     150,   304,   216,   497,   637,   561,   637,   562,   649,   607,
     310,   801,   637,   171,   172,   294,   295,   296,   297,   298,
     608,   296,   297,   298,   535,   210,   324,   330,   197,   284,
     284,   210,   338,   436,    53,   438,   346,   741,   745,   742,
     746,   294,   295,   296,   297,   298,   198,   357,   357,   357,
     572,    67,   573,   610,   284,   482,   146,   284,   147,    66,
     199,   483,   146,   207,   523,   754,   611,   755,   146,   292,
     293,   383,   206,   169,   147,   291,   292,   293,   394,   394,
     290,   291,   292,   293,   590,   192,   591,   164,   165,   146,
     146,   146,   146,   146,   653,   654,   415,   416,   417,   418,
     278,   279,   280,   281,   282,   283,   850,   211,   146,   146,
     146,   146,   851,   146,   146,   357,   146,   357,   146,   146,
     146,   146,   146,   146,   600,   210,   601,   710,   146,   146,
     146,   146,   146,   146,   146,   294,   295,   296,   297,   298,
     212,    51,   294,   295,   296,   297,   298,   762,   294,   295,
     296,   297,   298,   600,   284,   602,   763,   284,   152,   302,
     284,   284,    66,    66,   559,   615,   616,   560,   756,   174,
     757,   580,   284,   284,   647,   217,   284,   284,   284,   208,
     209,   284,   445,   581,   490,   491,   582,   583,   585,   770,
     218,   593,   498,   219,   146,   147,   284,   284,   284,   220,
     191,   512,   513,   514,   515,   516,   594,   595,   740,   396,
     284,   677,   396,   146,   679,   284,   718,  -221,    66,   284,
     749,   284,    66,   284,   284,   752,   691,   325,   331,   753,
     284,   816,   215,   817,   818,   375,   376,   347,   284,   284,
     819,   377,   378,    53,    51,    51,   558,   586,   147,   147,
     147,   284,   222,    69,   284,   693,   802,   147,   284,   589,
      67,   223,   592,   147,   284,   284,   596,   216,   600,   147,
     661,   225,   597,   645,   600,    69,   662,   600,   284,   719,
     726,   288,   289,   290,   291,   292,   293,   193,   379,   380,
     147,   147,   147,   147,   147,   600,   747,   720,   748,   750,
      51,   751,   226,   758,    51,   759,   600,   306,   786,   147,
     147,   147,   147,   227,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   787,   319,   788,   228,   147,
     147,   147,   147,   147,   147,   147,   390,   391,   324,   330,
     480,   481,   229,   146,   485,   172,    53,    53,   480,   487,
     627,   294,   295,   296,   297,   298,   494,   495,   475,   604,
     663,   664,   230,    67,    67,   390,   685,    31,   768,   231,
     147,    31,   775,   776,   777,    66,   232,    66,   663,   798,
     233,   691,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   307,   243,   244,   288,   147,   290,   291,   292,   293,
     245,   192,    53,   246,   305,   247,    53,   248,   249,   250,
     726,   146,   251,   146,   147,   252,   253,   254,   255,    67,
     256,   342,   257,    67,   258,   259,   260,   146,   261,   326,
     332,   262,   263,   264,   265,   266,   394,   146,   267,   394,
     146,   317,   146,   268,   269,   270,   146,   146,   285,   286,
     358,   358,   358,   688,   271,   272,    66,    51,   273,    51,
     830,   314,    69,   832,   294,   295,   296,   297,   298,   320,
     315,   164,   353,   627,   384,   627,   354,   334,   335,   350,
     293,   355,   363,   364,   845,   846,   365,   847,   475,   474,
     525,   509,    70,   488,   489,   146,   146,   287,   288,   289,
     290,   291,   292,   293,   316,   502,   504,   723,   480,   517,
     377,   518,   519,   545,   170,   175,   528,   529,   358,   530,
     358,   531,   532,   533,   540,   541,   194,   542,   543,   544,
     564,   285,   286,   546,   563,   636,   706,   565,    51,   325,
     331,   566,   603,   613,   147,   614,   146,   650,   651,   655,
     656,   628,   657,   771,   730,   760,   731,   780,   781,    53,
     783,    53,   784,   804,   805,    69,    69,   811,   294,   295,
     296,   297,   298,   822,   828,   833,    67,   575,    67,   576,
     287,   288,   289,   290,   291,   292,   293,   524,   708,   779,
     511,   146,   166,   397,   167,   146,   684,   146,   813,   796,
     146,   617,   825,   193,   618,   853,   501,   309,   688,   186,
     704,     0,   147,     0,   147,     0,     0,   627,     0,     0,
       0,    69,     0,     0,     0,    69,     0,     0,   147,     0,
     146,   146,     0,   146,     0,     0,     0,   723,   147,     0,
      53,   147,     0,   147,     0,     0,     0,   147,   147,     0,
       0,   294,   295,   296,   297,   298,     0,    67,     0,     0,
     577,    66,   578,     0,    66,     0,   285,   286,   327,   333,
       0,     0,     0,     0,   628,     0,   628,     0,   146,     0,
       0,     0,     0,     0,     0,    66,    66,     0,    66,   359,
     359,   359,     0,     0,     0,     0,   147,   147,     0,     0,
       0,    70,   855,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   145,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   326,   332,    51,     0,     0,    51,   147,     0,     0,
       0,     0,     0,   629,   772,     0,     0,   359,     0,   359,
       0,     0,     0,     0,     0,     0,     0,    51,    51,     0,
      51,     0,     0,     0,   285,   286,     0,     0,    69,     0,
      69,     0,     0,     0,     0,     0,   294,   295,   296,   297,
     298,     0,   147,     0,     0,   713,   147,   714,   147,     0,
       0,   147,     0,     0,    70,    70,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,   628,     0,
      76,     1,     2,   287,   288,   289,   290,   291,   292,   293,
       0,   147,   147,     0,   147,     0,     0,    82,   276,     0,
       0,     0,   194,     0,     0,    53,     0,     0,    53,   299,
       0,     0,     0,     0,     0,     0,   690,     0,     0,    69,
      70,     0,    67,     0,    70,    67,     0,     0,     0,    53,
      53,     0,    53,     0,     0,     0,   629,     0,   629,   147,
       0,     0,     0,     0,     0,     0,    67,    67,   339,    67,
       0,   148,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   536,    94,    95,    96,    97,    98,     0,
     725,   366,     0,     0,     0,     0,     0,   370,     0,     0,
       0,     0,     0,   381,   111,   112,     0,     0,     0,     0,
     117,   118,   119,   120,     0,   122,     0,   124,     0,   126,
     127,   128,     0,     0,   409,   410,   411,   412,   413,   414,
       0,     0,     0,     0,   144,     0,   773,     0,     0,     0,
       0,     0,     0,   429,   430,   431,   432,     0,   434,   435,
       0,   437,     0,   439,   440,   441,   442,   443,   444,     0,
     327,   333,     0,   447,   448,   449,   450,   451,   452,   453,
       0,     0,   630,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   468,   468,     0,   285,   286,
       0,   690,     0,     0,     0,     0,     0,    70,     0,    70,
     629,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,   499,
       0,     0,     0,   506,   285,   286,     0,   287,   288,   289,
     290,   291,   292,   293,    69,     0,     0,    69,   520,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    69,
     148,    69,     0,   468,   468,     0,   148,     0,    70,     0,
       0,     0,   148,   287,   288,   289,   290,   291,   292,   293,
       0,     0,   395,   395,     0,   630,     0,   630,     0,     0,
       0,     0,     0,   148,   148,   148,   148,   148,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   738,     0,   739,
       0,     0,   148,   148,   148,   148,     0,   148,   148,     0,
     148,     0,   148,   148,   148,   148,   148,   148,     0,     0,
       0,     0,   148,   148,   148,   148,   148,   148,   148,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,     0,   446,     0,     0,   285,   286,
       0,     0,     0,     0,     0,   774,     0,     0,   620,     0,
     621,   285,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,   286,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   468,   468,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,   148,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,   630,
       0,     0,     0,     0,     0,     0,   672,     0,   673,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,   676,     0,   285,   286,     0,     0,     0,     0,
       0,     0,   678,     0,     0,   680,     0,   681,     0,     0,
       0,   682,   683,    70,     0,   468,    70,     0,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,     0,   547,
       0,   294,   295,   296,   297,   298,     0,    70,    70,     0,
      70,     0,   548,   287,   288,   289,   290,   291,   292,   293,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     715,   716,   549,     0,     0,     0,     0,   468,     0,     0,
       0,     0,     0,     0,     0,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   159,     0,   148,   285,   286,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   766,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,     0,   550,     0,     0,     0,     0,
       0,     0,     0,   213,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,   224,     0,
       0,     0,     0,     0,     0,   148,   790,   148,     0,     0,
     791,     0,   792,     0,     0,   793,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   148,     0,   148,   148,     0,   148,     0,     0,     0,
     148,   148,     0,     0,     0,   806,   807,   689,   809,     0,
     274,   275,   277,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,   506,   551,
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
     477,   724,     0,     0,     0,    75,    76,     1,     2,     0,
      77,    78,    79,    80,   285,   286,     0,     0,     0,     0,
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
     133,     0,   200,   598,   599,   552,     0,   285,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,   286,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   622,     0,   624,   285,   286,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,   642,   643,   644,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,   469,
     469,     0,     0,     0,   658,   659,   660,     0,     0,     0,
       0,     0,     0,     0,   665,   666,   287,   288,   289,   290,
     291,   292,   293,   667,   668,   669,   670,   671,    75,    76,
       1,     2,     0,    77,    78,    79,    80,     0,     0,     0,
       0,   674,     0,     0,   675,    81,    82,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   553,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,   469,
       0,   567,     0,     0,   692,     0,     0,   694,    83,    84,
       0,     0,     0,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   568,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
     100,   469,   101,   102,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     0,     0,     0,     0,   285,
     286,     0,     0,   133,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   782,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   789,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,   794,     0,   795,    75,    76,     1,     2,
     799,    77,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,   285,   286,     0,     0,     0,
       0,     0,     0,   810,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   507,     0,     0,     0,    83,    84,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
     569,     0,   834,     0,   287,   288,   289,   290,   291,   292,
     293,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,   100,     0,
     101,   102,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   285,   286,     0,     0,     0,     0,     0,
       0,   133,     0,     0,     0,   294,   295,   296,   297,   298,
     285,   286,     0,     0,     0,     0,   570,     0,     0,     0,
       0,     0,   285,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   286,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,   285,
     286,     0,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,     0,   571,     0,     0,     0,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   574,   294,   295,   296,   297,   298,   285,   286,     0,
       0,     0,     0,   579,   294,   295,   296,   297,   298,   285,
     286,     0,     0,     0,     0,   584,     0,     0,     0,   294,
     295,   296,   297,   298,   285,   286,     0,     0,     0,     0,
     619,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,   285,   286,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,     0,   294,   295,   296,   297,   298,
       0,     0,     0,     0,     0,     0,   698,   294,   295,   296,
     297,   298,     0,     0,   285,   286,     0,     0,   711,   294,
     295,   296,   297,   298,     0,     0,   285,   286,     0,     0,
     712,     0,     0,     0,   294,   295,   296,   297,   298,   285,
     286,     0,     0,     0,     0,   727,     0,     0,     0,     0,
       0,   294,   295,   296,   297,   298,   285,   286,     0,     0,
       0,     0,   728,   287,   288,   289,   290,   291,   292,   293,
     285,   286,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,     0,   729,   294,   295,   296,   297,
     298,     0,     0,   285,   286,     0,     0,   732,     0,   294,
     295,   296,   297,   298,     0,   285,   286,     0,     0,     0,
     733,     0,     0,     0,     0,     0,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,   734,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   735,   287,   288,   289,   290,   291,   292,   293,   285,
     286,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,     0,   736,   294,   295,   296,   297,   298,
       0,     0,   285,   286,     0,     0,   737,     0,     0,     0,
       0,   294,   295,   296,   297,   298,   285,   286,     0,     0,
       0,     0,   743,     0,     0,   294,   295,   296,   297,   298,
     285,   286,     0,     0,     0,     0,   744,     0,     0,   294,
     295,   296,   297,   298,   285,   286,     0,     0,     0,     0,
     808,   287,   288,   289,   290,   291,   292,   293,   285,   286,
       0,     0,     0,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,     0,     0,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,     0,   815,     0,     0,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,   820,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,     0,
       0,   821,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   537,  -319,   285,   286,     0,   294,   295,
     296,   297,   298,   285,   286,     0,     0,   554,     0,     0,
     287,   288,   289,   290,   291,   292,   293,   285,   286,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,  -312,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,   287,   288,   289,   290,   291,   292,   293,   285,
     286,     0,   493,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,   696,     0,     0,   285,
     286,   294,   295,   296,   297,   298,     0,   823,     0,     0,
     555,     0,     0,   285,   286,   294,   295,   296,   297,   298,
     285,   286,     0,     0,   646,   761,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
       0,     0,     0,   294,   295,   296,   297,   298,   287,   288,
     289,   290,   291,   292,   293,     0,   829,   294,   295,   296,
     297,   298,   287,   288,   289,   290,   291,   292,   293,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
     294,   295,   296,   297,   298,     1,     2,   636,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     0,     0,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
       0,    16,     0,    17,     0,     0,     0,    18,     0,    19,
       0,    20,     0,    21,     0,     0,     0,     0,     0,    22,
      23,    24,    25,     0,     0,    26,    27,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    30,     0,    31,     0,
      32,     0,     0,     0,    33,     0,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,    39,    40,     0,    41,     0,     0,    42,
       1,     2,     0,     0,     0,     0,     0,     3,     4,     5,
       0,     6,     0,    43,     7,     8,     9,    10,     0,    11,
      12,    13,    14,    15,     0,     0,    16,     0,    17,     0,
       0,     0,    18,     0,    19,     0,    20,     0,    21,     0,
       0,     0,     0,     0,    22,    23,    24,    25,     0,     0,
      26,    27,     0,     0,     0,     0,     0,     0,     0,    28,
      29,    30,     0,    31,     0,    32,     0,     0,     0,    33,
       0,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,    39,    40,
       0,    41,     0,     0,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,   228,   229,   372,   229,   175,     7,     7,   209,     8,
     373,    11,    12,    13,     3,   301,     5,   623,     3,   625,
       5,    63,    22,    23,     5,     6,    26,    27,    48,     3,
       4,     3,     4,    33,    34,    35,    23,     3,     4,    29,
      23,     7,    40,    41,    42,     8,     9,    57,    58,    59,
      60,    61,    62,     7,    62,    62,   140,    47,    57,    58,
      59,    60,    61,    62,    63,   631,   632,   137,    62,   139,
      62,     8,     9,   129,   129,    57,    58,    59,    60,    61,
      62,   137,     0,     7,   139,   129,   128,   129,   130,   131,
     132,    15,   138,   137,    57,    58,    59,    60,    61,    62,
      63,    75,   388,   389,    63,    29,   138,    88,    89,    90,
     701,   312,   313,   704,    68,   135,   198,   199,   138,   129,
      57,    58,    59,    60,    61,    62,    63,   135,   135,   128,
     129,   130,   131,   132,   138,   701,   137,     7,   704,     5,
     503,   135,   505,   135,   144,   508,    65,   129,   135,   138,
     138,   151,   135,   138,   128,   137,   128,   139,   527,    29,
     160,   767,   128,     5,     6,   128,   129,   130,   131,   132,
      40,   130,   131,   132,   137,     7,   176,   177,   138,   129,
     129,     7,   182,   265,     0,   267,   186,   137,   137,   139,
     139,   128,   129,   130,   131,   132,   138,   197,   198,   199,
     137,     0,   139,    29,   129,    78,   206,   129,     7,   209,
     138,    84,   212,     0,   139,   137,    42,   139,   218,    62,
      63,   221,   138,    22,    23,    61,    62,    63,   228,   229,
      60,    61,    62,    63,   137,    34,   139,     5,     6,   239,
     240,   241,   242,   243,   530,   531,   244,   245,   246,   247,
      57,    58,    59,    60,    61,    62,    29,    62,   258,   259,
     260,   261,    35,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   137,     7,   139,   640,   278,   279,
     280,   281,   282,   283,   284,   128,   129,   130,   131,   132,
      62,   209,   128,   129,   130,   131,   132,    29,   128,   129,
     130,   131,   132,   137,   129,   139,    38,   129,     5,     6,
     129,   129,   312,   313,   139,   485,   486,   139,   137,   319,
     139,   139,   129,   129,   525,   135,   129,   129,   129,    29,
      30,   129,   139,   139,   334,   335,   139,   139,   139,   702,
      62,   139,   342,   139,   344,   144,   129,   129,   129,   139,
     350,   351,   352,   353,   354,   355,   139,   139,   139,   586,
     129,   586,   589,   363,   589,   129,   652,    62,   368,   129,
     139,   129,   372,   129,   129,   139,   603,   176,   177,   139,
     129,   139,   135,   139,   139,     5,     6,   186,   129,   129,
     139,     5,     6,   209,   312,   313,   137,   137,   197,   198,
     199,   129,   138,     0,   129,   606,   769,   206,   129,   137,
     209,   138,   137,   212,   129,   129,   137,   135,   137,   218,
     139,   138,   137,   137,   137,    22,   139,   137,   129,   139,
     657,    58,    59,    60,    61,    62,    63,    34,     5,     6,
     239,   240,   241,   242,   243,   137,   137,   139,   139,   137,
     368,   139,   138,   137,   372,   139,   137,   135,   139,   258,
     259,   260,   261,   138,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   137,   137,   139,   138,   278,
     279,   280,   281,   282,   283,   284,     5,     6,   488,   489,
       5,     6,   138,   493,     5,     6,   312,   313,     5,     6,
     500,   128,   129,   130,   131,   132,   136,   137,     5,     6,
       5,     6,   138,   312,   313,     5,     6,    68,    69,   138,
     319,    68,    69,    72,    73,   525,   138,   527,     5,     6,
     138,   758,   138,   138,   138,   138,   138,   138,   138,   138,
     138,    32,   138,   138,    58,   344,    60,    61,    62,    63,
     138,   350,   368,   138,   151,   138,   372,   138,   138,   138,
     787,   561,   138,   563,   363,   138,   138,   138,   138,   368,
     138,   140,   138,   372,   138,   138,   138,   577,   138,   176,
     177,   138,   138,   138,   138,   138,   586,   587,   138,   589,
     590,    48,   592,   138,   138,   138,   596,   597,     8,     9,
     197,   198,   199,   603,   138,   138,   606,   525,   138,   527,
     811,   138,   209,   814,   128,   129,   130,   131,   132,   135,
     138,     5,    23,   623,   221,   625,    23,   137,   137,   137,
      63,   137,   137,   137,   835,   836,   137,   838,     5,   135,
      44,     7,     0,   137,   137,   645,   646,    57,    58,    59,
      60,    61,    62,    63,   135,   135,   135,   657,     5,   137,
       5,   137,   137,   137,    22,    23,   138,   138,   265,   138,
     267,   138,   138,   138,   138,   138,    34,   139,   139,   135,
     139,     8,     9,   137,   137,     7,     3,   139,   606,   488,
     489,   139,   138,   138,   493,   138,   696,   139,   139,   139,
     139,   500,   138,   703,   138,   135,   138,    62,    62,   525,
      62,   527,    46,     7,    71,   312,   313,    45,   128,   129,
     130,   131,   132,    23,    62,     4,   525,   137,   527,   139,
      57,    58,    59,    60,    61,    62,    63,   368,   638,   709,
     350,   741,    22,   229,    22,   745,   600,   747,   787,   758,
     750,   488,   803,   350,   489,   849,   345,   157,   758,    31,
     632,    -1,   561,    -1,   563,    -1,    -1,   767,    -1,    -1,
      -1,   368,    -1,    -1,    -1,   372,    -1,    -1,   577,    -1,
     780,   781,    -1,   783,    -1,    -1,    -1,   787,   587,    -1,
     606,   590,    -1,   592,    -1,    -1,    -1,   596,   597,    -1,
      -1,   128,   129,   130,   131,   132,    -1,   606,    -1,    -1,
     137,   811,   139,    -1,   814,    -1,     8,     9,   176,   177,
      -1,    -1,    -1,    -1,   623,    -1,   625,    -1,   828,    -1,
      -1,    -1,    -1,    -1,    -1,   835,   836,    -1,   838,   197,
     198,   199,    -1,    -1,    -1,    -1,   645,   646,    -1,    -1,
      -1,   209,   852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   488,   489,   811,    -1,    -1,   814,   696,    -1,    -1,
      -1,    -1,    -1,   500,   703,    -1,    -1,   265,    -1,   267,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   835,   836,    -1,
     838,    -1,    -1,    -1,     8,     9,    -1,    -1,   525,    -1,
     527,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,   741,    -1,    -1,   137,   745,   139,   747,    -1,
      -1,   750,    -1,    -1,   312,   313,    -1,    -1,    -1,    -1,
      -1,   319,    -1,    -1,    -1,    -1,    -1,    -1,   767,    -1,
       4,     5,     6,    57,    58,    59,    60,    61,    62,    63,
      -1,   780,   781,    -1,   783,    -1,    -1,    21,   133,    -1,
      -1,    -1,   350,    -1,    -1,   811,    -1,    -1,   814,   144,
      -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,   606,
     368,    -1,   811,    -1,   372,   814,    -1,    -1,    -1,   835,
     836,    -1,   838,    -1,    -1,    -1,   623,    -1,   625,   828,
      -1,    -1,    -1,    -1,    -1,    -1,   835,   836,   183,   838,
      -1,     7,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,    88,    89,    90,    91,    92,    -1,
     657,   206,    -1,    -1,    -1,    -1,    -1,   212,    -1,    -1,
      -1,    -1,    -1,   218,   108,   109,    -1,    -1,    -1,    -1,
     114,   115,   116,   117,    -1,   119,    -1,   121,    -1,   123,
     124,   125,    -1,    -1,   239,   240,   241,   242,   243,   244,
      -1,    -1,    -1,    -1,   138,    -1,   703,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   259,   260,   261,    -1,   263,   264,
      -1,   266,    -1,   268,   269,   270,   271,   272,   273,    -1,
     488,   489,    -1,   278,   279,   280,   281,   282,   283,   284,
      -1,    -1,   500,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,   300,   301,    -1,     8,     9,
      -1,   758,    -1,    -1,    -1,    -1,    -1,   525,    -1,   527,
     767,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     787,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,
      -1,    -1,    -1,   348,     8,     9,    -1,    57,    58,    59,
      60,    61,    62,    63,   811,    -1,    -1,   814,   363,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   835,   836,
     206,   838,    -1,   388,   389,    -1,   212,    -1,   606,    -1,
      -1,    -1,   218,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,   228,   229,    -1,   623,    -1,   625,    -1,    -1,
      -1,    -1,    -1,   239,   240,   241,   242,   243,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,   137,    -1,   139,
      -1,    -1,   258,   259,   260,   261,    -1,   263,   264,    -1,
     266,    -1,   268,   269,   270,   271,   272,   273,    -1,    -1,
      -1,    -1,   278,   279,   280,   281,   282,   283,   284,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,   703,    -1,    -1,   493,    -1,
     495,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,   344,    -1,
      -1,    -1,    -1,    -1,    -1,   530,   531,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,   363,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,   767,
      -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,   563,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,   577,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,   587,    -1,    -1,   590,    -1,   592,    -1,    -1,
      -1,   596,   597,   811,    -1,   600,   814,    -1,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,   128,   129,   130,   131,   132,    -1,   835,   836,    -1,
     838,    -1,   139,    57,    58,    59,    60,    61,    62,    63,
      -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     645,   646,   139,    -1,    -1,    -1,    -1,   652,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,   493,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   696,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    -1,   561,   741,   563,    -1,    -1,
     745,    -1,   747,    -1,    -1,   750,    -1,    -1,    -1,    -1,
      -1,   577,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     586,   587,    -1,   589,   590,    -1,   592,    -1,    -1,    -1,
     596,   597,    -1,    -1,    -1,   780,   781,   603,   783,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,   803,   139,
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
     311,   787,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    -1,    -1,   337,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,    -1,   828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   364,   365,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,   389,    -1,
      -1,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    -1,    97,
      98,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    -1,    -1,   128,   129,   130,   131,   132,    -1,
     138,    -1,   140,   454,   455,   139,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   495,    -1,   497,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,   517,   518,   519,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,   530,
     531,    -1,    -1,    -1,   535,   536,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,   546,    57,    58,    59,    60,
      61,    62,    63,   554,   555,   556,   557,   558,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,   572,    -1,    -1,   575,    20,    21,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   600,
      -1,   139,    -1,    -1,   605,    -1,    -1,   608,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,   652,    97,    98,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,     8,
       9,    -1,    -1,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   713,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   738,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   754,    -1,   756,     3,     4,     5,     6,
     761,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,   784,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   803,    -1,    -1,    -1,    53,    54,    -1,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,   823,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    -1,
      97,    98,    -1,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,   138,    -1,    -1,    -1,   128,   129,   130,   131,   132,
       8,     9,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,     8,     9,    -1,    -1,    -1,
      -1,   139,   128,   129,   130,   131,   132,     8,     9,    -1,
      -1,    -1,    -1,   139,   128,   129,   130,   131,   132,     8,
       9,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   128,
     129,   130,   131,   132,     8,     9,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,     8,     9,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   128,   129,   130,
     131,   132,    -1,    -1,     8,     9,    -1,    -1,   139,   128,
     129,   130,   131,   132,    -1,    -1,     8,     9,    -1,    -1,
     139,    -1,    -1,    -1,   128,   129,   130,   131,   132,     8,
       9,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,     8,     9,    -1,    -1,
      -1,    -1,   139,    57,    58,    59,    60,    61,    62,    63,
       8,     9,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   128,   129,   130,   131,
     132,    -1,    -1,     8,     9,    -1,    -1,   139,    -1,   128,
     129,   130,   131,   132,    -1,     8,     9,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,     8,     9,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     128,   129,   130,   131,   132,     8,     9,    -1,    -1,    -1,
      -1,   139,    57,    58,    59,    60,    61,    62,    63,     8,
       9,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   128,   129,   130,   131,   132,
      -1,    -1,     8,     9,    -1,    -1,   139,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,   132,     8,     9,    -1,    -1,
      -1,    -1,   139,    -1,    -1,   128,   129,   130,   131,   132,
       8,     9,    -1,    -1,    -1,    -1,   139,    -1,    -1,   128,
     129,   130,   131,   132,     8,     9,    -1,    -1,    -1,    -1,
     139,    57,    58,    59,    60,    61,    62,    63,     8,     9,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   128,   129,   130,   131,
     132,     8,     9,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     128,   129,   130,   131,   132,     8,     9,    -1,    -1,    -1,
      -1,   139,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,    -1,    -1,   137,     7,     8,     9,    -1,   128,   129,
     130,   131,   132,     8,     9,    -1,    -1,   137,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,     8,     9,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    57,    58,    59,    60,    61,    62,    63,     8,
       9,    -1,    67,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    67,    -1,    -1,     8,
       9,   128,   129,   130,   131,   132,    -1,    36,    -1,    -1,
     137,    -1,    -1,     8,     9,   128,   129,   130,   131,   132,
       8,     9,    -1,    -1,   137,    34,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,   128,   129,   130,   131,   132,
      -1,    -1,    -1,   128,   129,   130,   131,   132,    57,    58,
      59,    60,    61,    62,    63,    -1,    44,   128,   129,   130,
     131,   132,    57,    58,    59,    60,    61,    62,    63,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,
     128,   129,   130,   131,   132,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    16,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    28,    -1,
      -1,    31,    -1,    33,    -1,    -1,    -1,    37,    -1,    39,
      -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    -1,    -1,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    93,    94,    -1,    96,    -1,    -1,    99,
       5,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    16,    -1,   113,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    28,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    37,    -1,    39,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    -1,    -1,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      65,    66,    -1,    68,    -1,    70,    -1,    -1,    -1,    74,
      -1,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    93,    94,
      -1,    96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  parser::yystos_[] =
  {
         0,     5,     6,    12,    13,    14,    16,    19,    20,    21,
      22,    24,    25,    26,    27,    28,    31,    33,    37,    39,
      41,    43,    49,    50,    51,    52,    55,    56,    64,    65,
      66,    68,    70,    74,    76,    77,    88,    89,    90,    93,
      94,    96,    99,   113,   142,   143,   144,   146,   147,   164,
     165,   181,   182,   183,   184,   187,   194,   207,   215,   226,
     231,   237,   242,   246,   251,   268,   274,   275,   276,   277,
     278,   280,   138,   138,   188,     3,     4,     8,     9,    10,
      11,    20,    21,    53,    54,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      95,    97,    98,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   138,   167,   168,   170,   175,   181,   183,
     274,   275,   277,   278,   138,   167,   274,   275,   276,   138,
     138,   195,     5,   274,   274,   274,   152,   153,   167,   170,
     208,   232,   238,   227,     5,     6,   164,   165,   274,   275,
     278,     5,     6,   180,   274,   278,   148,   149,   267,   274,
     266,   274,   140,   264,   150,    65,   273,   216,   274,   161,
     162,   274,   275,   277,   278,   163,   274,   138,   138,   138,
     140,   170,   177,   177,   177,   177,   138,     0,    29,    30,
       7,    62,    62,   170,    62,   135,   135,   135,    62,   139,
     139,   189,   138,   138,   170,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   170,   170,   167,   170,    57,    58,
      59,    60,    61,    62,   129,     8,     9,    57,    58,    59,
      60,    61,    62,    63,   128,   129,   130,   131,   132,   167,
     154,   155,     6,   198,   274,   277,   135,    32,   265,   265,
     274,   233,   239,   228,   138,   138,   135,    48,   179,   137,
     135,   179,   201,   202,   274,   275,   277,   278,   203,   204,
     274,   275,   277,   278,   137,   137,     3,   138,   274,   167,
     170,   257,   140,   258,   259,   151,   274,   275,   217,   156,
     137,    23,    23,    23,    23,   137,   166,   274,   277,   278,
     166,   166,   170,   137,   137,   137,   167,   144,   145,   170,
     167,   243,   247,   249,   170,     5,     6,     5,     6,     5,
       6,   167,   193,   274,   277,   170,   170,   170,   176,   169,
       5,     6,   173,   174,   274,   276,   280,   173,   174,   170,
     170,   139,   170,   170,   170,   170,   170,   170,   170,   167,
     167,   167,   167,   167,   167,   177,   177,   177,   177,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   167,
     167,   167,   167,   170,   167,   167,   166,   167,   166,   167,
     167,   167,   167,   167,   167,   139,   139,   167,   167,   167,
     167,   167,   167,   167,   172,   171,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   167,   170,
     185,   186,   185,   196,   135,     5,    62,   170,   144,   144,
       5,     6,    78,    84,   178,     5,   278,     6,   137,   137,
     274,   274,   170,    67,   136,   137,     3,   138,   274,   167,
     263,   258,   135,   269,   135,   270,   167,   170,   220,     7,
     219,   162,   274,   274,   274,   274,   274,   137,   137,   137,
     167,   170,   170,   139,   146,    44,   147,   219,   138,   138,
     138,   138,   138,   138,   190,   137,   137,   137,   185,   185,
     138,   138,   139,   139,   135,   137,   137,   139,   139,   139,
     139,   139,   139,   139,   137,   137,   137,   137,   137,   139,
     139,   137,   139,   137,   139,   139,   139,   139,   139,   139,
     139,   139,   137,   139,   139,   137,   139,   137,   139,   139,
     139,   139,   139,   139,   139,   139,   137,   137,   139,   137,
     137,   139,   137,   139,   139,   139,   137,   137,   170,   170,
     137,   139,   139,   138,     6,   209,   234,    29,    40,   240,
      29,    42,   229,   138,   138,   179,   179,   202,   204,   139,
     167,   167,   170,   261,   170,   260,   256,   274,   275,   277,
     278,   219,   219,   219,     3,     4,     7,   128,   157,   158,
     159,   160,   170,   170,   170,   137,   137,   144,   248,   147,
     139,   139,   279,   185,   185,   139,   139,   138,   170,   170,
     170,   139,   139,     5,     6,   170,   170,   170,   170,   170,
     170,   170,   167,   167,   170,   170,   167,   174,   167,   174,
     167,   167,   167,   167,   186,     6,   199,   200,   274,   276,
     277,   280,   170,   144,   170,   230,    67,   256,   139,   256,
     268,   271,   272,   273,   271,   221,     3,    75,   158,   137,
     219,   139,   139,   137,   139,   167,   167,   244,   185,   139,
     139,   205,   206,   274,   276,   277,   280,   139,   139,   139,
     138,   138,   139,   139,   139,   139,   139,   139,   137,   139,
     139,   137,   139,   139,   139,   137,   139,   137,   139,   139,
     137,   139,   139,   139,   137,   139,   137,   139,   137,   139,
     135,    34,    29,    38,   235,   241,   167,   262,    69,   272,
     219,   274,   275,   277,   278,    69,    72,    73,   223,   160,
      62,    62,   170,    62,    46,   253,   139,   137,   139,   170,
     167,   167,   167,   167,   170,   170,   200,   197,     6,   170,
     236,   256,   219,   222,     7,    71,   167,   167,   139,   167,
     170,    45,   252,   206,   191,   139,   139,   139,   139,   139,
     139,   139,    23,    36,   214,   220,   224,   218,    62,    44,
     144,   245,   144,     4,   170,   210,   225,   167,   254,    29,
      47,   250,    15,    29,   192,   144,   144,   144,   211,   255,
      29,    35,   212,   253,   213,   274
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
     147,   147,   147,   147,   147,   147,   147,   147,   148,   147,
     149,   147,   147,   147,   147,   150,   147,   151,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   152,   147,   153,   147,   147,   147,   147,   147,   147,
     147,   147,   154,   147,   155,   147,   156,   147,   147,   147,
     157,   157,   158,   159,   159,   160,   160,   160,   161,   161,
     162,   162,   162,   162,   163,   163,   164,   164,   165,   165,
     165,   165,   165,   165,   166,   166,   167,   167,   167,   167,
     167,   167,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   169,   168,   171,   170,   172,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   173,   174,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   176,   175,   177,   177,   178,   178,
     179,   179,   180,   180,   180,   180,   181,   181,   182,   183,
     183,   184,   185,   185,   186,   186,   188,   189,   190,   191,
     187,   192,   192,   193,   193,   195,   196,   197,   194,   198,
     198,   199,   199,   199,   200,   200,   200,   200,   201,   201,
     202,   202,   202,   202,   203,   203,   204,   204,   204,   204,
     205,   205,   205,   206,   206,   206,   206,   208,   209,   210,
     211,   207,   212,   212,   213,   213,   214,   214,   216,   217,
     218,   215,   219,   219,   220,   220,   221,   222,   221,   223,
     224,   225,   223,   227,   228,   226,   229,   230,   229,   232,
     233,   234,   231,   235,   236,   235,   238,   239,   237,   240,
     241,   240,   243,   244,   245,   242,   247,   248,   246,   249,
     246,   250,   250,   251,   252,   252,   253,   254,   255,   253,
     256,   256,   256,   256,   257,   257,   257,   257,   257,   257,
     257,   259,   258,   260,   258,   261,   258,   262,   258,   263,
     264,   264,   264,   264,   265,   266,   266,   267,   267,   269,
     268,   270,   268,   271,   271,   272,   272,   272,   272,   272,
     273,   274,   274,   275,   275,   275,   275,   276,   276,   276,
     276,   277,   277,   278,   278,   278,   279,   278,   280,   280,
     280,   280
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
       142,     0,    -1,   143,    29,    -1,   144,    -1,   143,    30,
     144,    -1,   146,    -1,    -1,   144,     7,   145,   146,    -1,
      -1,   147,    -1,   164,    -1,   165,    -1,    49,   164,    -1,
      49,   165,    -1,   242,    -1,   246,    -1,   226,    -1,   207,
      -1,   237,    -1,   231,    -1,   215,    -1,    12,    -1,    13,
      -1,   187,    -1,   194,    -1,   268,    -1,   181,    -1,   183,
      -1,    -1,    51,   148,   201,    -1,    -1,    52,   149,   203,
      -1,    64,   264,   257,    -1,    64,   264,   257,   136,    -1,
      64,   264,   257,   137,    -1,    -1,    65,   150,   258,    -1,
      -1,    66,    65,   151,   258,    -1,    16,    -1,    16,   170,
      -1,    16,   167,    -1,    50,   180,    -1,   113,   138,   167,
     139,    -1,    31,    -1,    31,   170,    -1,    93,   177,   137,
     167,    -1,    93,   177,   137,   167,   137,   167,    -1,    94,
     177,    -1,    96,   177,   137,   170,    -1,    96,   177,   137,
     170,   137,   167,    -1,    -1,    27,   152,   265,    -1,    -1,
      28,   153,   265,    -1,    56,   266,    -1,    55,   267,    -1,
      24,   274,    -1,    25,   274,    -1,    26,   274,    -1,    99,
     177,   137,   170,    -1,    19,   167,    -1,    -1,    20,   138,
     154,   185,   139,    -1,    -1,    21,   138,   155,   185,   139,
      -1,    -1,    74,   274,   156,   219,   157,    75,    -1,    76,
     161,    -1,    77,   163,    -1,   158,    -1,   157,   158,    -1,
     159,   219,    -1,   160,    -1,   159,   137,   160,    -1,     3,
      -1,   128,     3,    -1,     4,    -1,   162,    -1,   161,   137,
     162,    -1,   274,    23,   274,    -1,   277,    23,   274,    -1,
     275,    23,   274,    -1,   278,    23,   274,    -1,   274,    -1,
     163,   137,   274,    -1,   274,    62,   170,    -1,   182,    62,
     170,    -1,   277,    62,   167,    -1,    90,   138,   166,   137,
     170,   137,   170,   139,    62,   167,    -1,    90,   138,   166,
     137,   170,   139,    62,   167,    -1,    88,   138,   166,   137,
     170,   139,    62,   167,    -1,    89,   138,   166,   137,   170,
     139,    62,   167,    -1,   184,    62,   167,    -1,   277,    -1,
     278,    -1,   277,    -1,   168,    -1,   183,    -1,     4,    -1,
     167,   129,   167,    -1,   138,   167,   139,    -1,    88,   138,
     167,   137,   170,   139,    -1,    89,   138,   167,   137,   170,
     139,    -1,    90,   138,   167,   137,   170,   137,   170,   139,
      -1,    90,   138,   167,   137,   170,   139,    -1,   108,   138,
     170,   139,    -1,   108,   138,   170,   137,   167,   139,    -1,
     108,   138,   170,   137,   167,   137,   167,   139,    -1,   109,
     138,   170,   139,    -1,    91,   138,   167,   139,    -1,    92,
     138,   167,   139,    -1,   124,   138,   167,   139,    -1,   125,
     138,   167,   139,    -1,   123,   138,   167,   139,    -1,   119,
     138,   166,   137,   167,   139,    -1,   119,   138,   166,   139,
      -1,   121,   138,   166,   137,   167,   139,    -1,   121,   138,
     166,   139,    -1,   117,    -1,   116,    -1,   114,   138,   170,
     139,    -1,   115,   138,   167,   139,    -1,    -1,    21,   138,
     169,   185,   139,    -1,    -1,   170,     9,   171,   170,    -1,
      -1,   170,     8,   172,   170,    -1,    10,   170,    -1,   170,
      62,   170,    -1,   170,    57,   170,    -1,   170,    60,   170,
      -1,   170,    58,   170,    -1,   170,    61,   170,    -1,   170,
      59,   170,    -1,    95,   138,   177,   139,    -1,   122,   138,
     167,   137,   167,   139,    -1,    53,   138,   173,   139,    -1,
      53,   138,   174,   139,    -1,    54,   138,   173,   137,   170,
     139,    -1,    54,   138,   174,   137,   170,   139,    -1,   181,
      -1,   167,    62,   167,    -1,   167,    57,   167,    -1,   167,
      60,   167,    -1,   167,    58,   167,    -1,   167,    61,   167,
      -1,   167,    59,   167,    -1,   175,    -1,   170,   132,   170,
      -1,   170,    63,   170,    -1,   129,   170,    -1,   128,   170,
      -1,   170,   130,   170,    -1,   170,   131,   170,    -1,   170,
     128,   170,    -1,   170,   129,   170,    -1,   138,   170,   139,
      -1,   274,    -1,     3,    -1,   276,    -1,   280,    -1,   100,
     138,   170,   139,    -1,   101,   138,   170,   139,    -1,   102,
     138,   170,   139,    -1,   103,   138,   170,   139,    -1,   104,
     138,   170,   139,    -1,   105,   138,   170,   139,    -1,   105,
     138,   170,   137,   170,   139,    -1,   106,   138,   170,   139,
      -1,   107,   138,   170,   139,    -1,   107,   138,   170,   137,
     170,   139,    -1,    84,   138,   170,   139,    -1,    82,   138,
     170,   139,    -1,    83,   138,   170,   139,    -1,    85,   138,
     170,   139,    -1,    79,   138,   170,   139,    -1,    80,   138,
     170,   139,    -1,    81,   138,   170,   139,    -1,    81,   138,
     139,    -1,    86,   138,   170,   137,   170,   139,    -1,    87,
     138,   170,   137,   170,   139,    -1,   112,   138,   167,   139,
      -1,   110,   138,   167,   139,    -1,   111,   138,   167,   139,
      -1,   126,   138,   167,   137,   167,   139,    -1,   126,   138,
     167,   137,   167,   137,   170,   139,    -1,   127,   138,   167,
     137,   167,   139,    -1,   127,   138,   167,   137,   167,   137,
     170,   139,    -1,   113,   138,   167,   139,    -1,     8,   138,
     170,   137,   170,   139,    -1,     9,   138,   170,   137,   170,
     139,    -1,    11,   138,   170,   137,   170,   139,    -1,   118,
     138,   167,   137,   174,   137,   167,   139,    -1,   118,   138,
     167,   137,   174,   139,    -1,   120,   138,   167,   137,   174,
     137,   167,   139,    -1,   120,   138,   167,   137,   174,   139,
      -1,    93,   138,   167,   139,    -1,    93,   138,   167,   137,
     167,   139,    -1,    93,   138,   177,   137,   167,   139,    -1,
      93,   138,   177,   137,   167,   137,   167,   139,    -1,    97,
     138,   177,   139,    -1,    98,   138,   177,   139,    -1,    -1,
      20,   138,   176,   185,   139,    -1,   140,   170,    -1,   170,
      -1,    78,    -1,    84,    -1,    -1,    48,   178,    -1,     5,
     179,    -1,   278,   179,    -1,   180,   137,     5,   179,    -1,
     180,   137,   278,   179,    -1,   275,    -1,   276,    -1,   275,
      -1,   278,    -1,   280,    -1,   278,    -1,   186,    -1,   185,
     137,   186,    -1,   167,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    14,   188,   189,   193,   190,   138,   205,   139,   191,
     144,   192,    -1,    29,    -1,    15,    -1,   274,    -1,   277,
      -1,    -1,    -1,    -1,    22,   195,   198,   196,   138,   199,
     139,   197,    23,     4,    -1,   274,    -1,   277,    -1,    -1,
     200,    -1,   199,   137,   200,    -1,   274,    -1,   277,    -1,
     276,    -1,   280,    -1,   202,    -1,   201,   137,   202,    -1,
     274,    -1,   277,    -1,   275,    -1,   278,    -1,   204,    -1,
     203,   137,   204,    -1,   274,    -1,   277,    -1,   275,    -1,
     278,    -1,    -1,   206,    -1,   205,   137,   206,    -1,   274,
      -1,   277,    -1,   276,    -1,   280,    -1,    -1,    -1,    -1,
      -1,    33,   208,   274,    62,   209,   170,    34,   170,   214,
     210,   144,   211,   212,   213,    -1,    29,    -1,    35,    -1,
      -1,   274,    -1,    -1,    36,   170,    -1,    -1,    -1,    -1,
      70,   216,   217,   220,   219,   221,   223,    71,   218,    -1,
       7,    -1,   219,     7,    -1,   170,    -1,   167,    -1,    -1,
      -1,   221,    72,   222,   220,    -1,    -1,    -1,    -1,    73,
       7,   224,   225,   144,    -1,    -1,    -1,    41,   227,   228,
     144,   229,    -1,    29,    -1,    -1,    42,   230,    -1,    -1,
      -1,    -1,    37,   232,   233,   170,   234,   144,   235,    -1,
      29,    -1,    -1,    38,   236,    -1,    -1,    -1,    39,   238,
     239,   144,   240,    -1,    29,    -1,    -1,    40,   170,   241,
      -1,    -1,    -1,    -1,   251,   170,   243,    44,   144,   244,
     253,   252,   245,   250,    -1,    -1,    -1,   251,   170,   247,
     147,   248,    -1,    -1,   251,   170,   249,   219,   147,    -1,
      29,    -1,    47,    -1,    43,    -1,    -1,    45,   144,    -1,
      -1,    -1,    -1,    46,   170,    44,   254,   144,   255,   253,
      -1,   274,    -1,   277,    -1,   275,    -1,   278,    -1,    -1,
     170,    -1,   170,    67,   167,    -1,   167,    -1,   257,   137,
     170,    -1,   257,   137,   170,    67,   167,    -1,   257,   137,
     167,    -1,    -1,   259,   263,   256,    -1,    -1,   140,   274,
     260,   256,    -1,    -1,   140,     3,   261,   256,    -1,    -1,
     140,   138,   170,   139,   262,   256,    -1,   167,    -1,    -1,
     140,   274,    -1,   140,     3,    -1,   140,   138,   170,   139,
      -1,    32,    -1,   274,    -1,   266,   137,   274,    -1,   274,
      -1,   267,   137,   274,    -1,    -1,    68,   273,   274,   269,
     219,   271,    69,    -1,    -1,    68,   273,   275,   270,   219,
     271,    69,    -1,   272,   219,    -1,   271,   272,   219,    -1,
     268,    -1,   273,   274,    -1,   273,   277,    -1,   273,   275,
      -1,   273,   278,    -1,    -1,     5,    -1,   274,   135,     5,
      -1,     5,   138,    -1,   275,   135,     5,   138,   185,   139,
      -1,   275,   135,     5,    -1,   274,   135,     5,   138,    -1,
       5,   138,   139,    -1,   276,   135,     5,   138,   139,    -1,
     276,   135,     5,    -1,   274,   135,     5,   138,   139,    -1,
       6,    -1,   274,   135,     6,    -1,     6,   138,    -1,   275,
     135,     6,   138,   185,   139,    -1,   275,   135,     6,    -1,
      -1,   274,   135,     6,   138,   279,   185,   139,    -1,     6,
     138,   139,    -1,   276,   135,     6,   138,   139,    -1,   276,
     135,     6,    -1,   274,   135,     6,   138,   139,    -1
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
         0,   191,   191,   206,   207,   210,   211,   211,   220,   221,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   239,   245,   246,   247,   248,   249,   250,   250,
     251,   251,   252,   260,   265,   270,   270,   271,   271,   272,
     275,   280,   281,   286,   289,   290,   291,   292,   293,   294,
     295,   296,   296,   297,   297,   298,   299,   300,   303,   304,
     307,   308,   309,   309,   312,   312,   313,   313,   314,   315,
     318,   319,   322,   325,   326,   329,   330,   331,   334,   335,
     338,   339,   340,   341,   344,   345,   348,   353,   356,   357,
     358,   359,   360,   361,   366,   367,   370,   371,   372,   373,
     374,   375,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   399,   402,   402,   403,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   430,   435,   438,   441,   445,   449,   450,
     454,   459,   462,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   506,   509,   510,   513,   516,
     522,   523,   531,   538,   539,   544,   547,   548,   551,   554,
     555,   558,   561,   562,   565,   566,   569,   569,   571,   574,
     569,   583,   589,   592,   595,   598,   601,   604,   598,   612,
     618,   626,   627,   628,   631,   634,   637,   640,   645,   646,
     649,   650,   651,   652,   655,   656,   659,   660,   661,   662,
     665,   666,   667,   670,   671,   674,   677,   682,   683,   687,
     689,   682,   695,   700,   703,   704,   707,   708,   711,   711,
     713,   711,   718,   719,   722,   723,   726,   727,   727,   735,
     736,   736,   736,   742,   742,   742,   747,   748,   748,   751,
     751,   752,   751,   758,   759,   759,   762,   762,   762,   767,
     769,   768,   772,   777,   779,   772,   783,   784,   783,   785,
     785,   789,   790,   793,   796,   797,   800,   802,   804,   801,
     808,   809,   810,   811,   814,   815,   820,   822,   824,   826,
     828,   832,   832,   833,   833,   834,   834,   835,   835,   838,
     842,   847,   848,   849,   852,   855,   856,   859,   860,   864,
     864,   880,   880,   898,   899,   902,   903,   911,   919,   927,
     937,   945,   949,   952,   954,   955,   956,   959,   962,   963,
     964,   967,   968,   971,   972,   973,   974,   974,   977,   978,
     979,   980
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
  const int parser::yylast_ = 3558;
  const int parser::yynnts_ = 140;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 207;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 141;

  const unsigned int parser::yyuser_token_number_max_ = 385;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 22 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 4385 "/home/cai/projects/basic/compiler/parser.cpp"
