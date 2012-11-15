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
#line 197 "parser.ypp"
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
#line 210 "parser.ypp"
    { (yyval.statement_list) = (yysemantic_stack_[(1) - (1)].statement_list); debug("list_of_statement_lists\n"); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 214 "parser.ypp"
    { (yyval.statement_list) = new StatementsAST(); (yyval.statement_list)->append(StatementASTPtr((yysemantic_stack_[(1) - (1)].statement)));}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 215 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 215 "parser.ypp"
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
#line 224 "parser.ypp"
    { (yyval.statement) = 0 ;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 225 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { debug ("cannot \"break\" outside of loop"); }
   }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 243 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   debug ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 251 "parser.ypp"
    { }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 252 "parser.ypp"
    { }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 253 "parser.ypp"
    { }
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 254 "parser.ypp"
    { }
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 255 "parser.ypp"
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
#line 267 "parser.ypp"
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
#line 274 "parser.ypp"
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
#line 281 "parser.ypp"
    { until_eol = false; }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 281 "parser.ypp"
    {}
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 282 "parser.ypp"
    { until_eol = true; }
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 282 "parser.ypp"
    {}
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 283 "parser.ypp"
    {
	   
             }
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 286 "parser.ypp"
    {

	   
   }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 291 "parser.ypp"
    { }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    {
	   debug("got syntax of \"dim local var\" now\n");

	   (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list);	   
	}
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 297 "parser.ypp"
    {
	   
}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 300 "parser.ypp"
    {}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 301 "parser.ypp"
    {}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 302 "parser.ypp"
    {}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 303 "parser.ypp"
    {}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 304 "parser.ypp"
    {}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 305 "parser.ypp"
    {}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 306 "parser.ypp"
    {}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 308 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 311 "parser.ypp"
    {

   }
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 314 "parser.ypp"
    {  }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 315 "parser.ypp"
    {
		debug("got label!\n");
   }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 318 "parser.ypp"
    {  }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 319 "parser.ypp"
    {  }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 320 "parser.ypp"
    {  }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 320 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 323 "parser.ypp"
    { }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 323 "parser.ypp"
    {  }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 340 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 341 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 342 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 79:
/* Line 661 of lalr1.cc  */
#line 349 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 350 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 351 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 352 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 355 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 356 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 359 "parser.ypp"
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
#line 366 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 369 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 370 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 371 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 373 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 374 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 415 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 415 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 417 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 418 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 419 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 420 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 421 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 422 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 423 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 425 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 427 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 428 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 429 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 430 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 431 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 432 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 433 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 435 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 436 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 438 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 439 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 440 "parser.ypp"
    {
	   (yyval.number_expression) = (yysemantic_stack_[(2) - (2)].number_expression) ;
   }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 443 "parser.ypp"
    {
	   /*add_command(cNEGATE,NULL);*/
	   ConstNumberExprAST * zero = new ConstNumberExprAST(0);
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr(zero) ,OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression)));
   }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 448 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_MUL,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 451 "parser.ypp"
    {
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_DIV,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 454 "parser.ypp"
    {
	   // 减法计算
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_SUB,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 458 "parser.ypp"
    {
	   // 加法计算.
	   (yyval.number_expression) = new NumberCalcExprAST( NumberExprASTPtr((yysemantic_stack_[(3) - (1)].number_expression)),OPERATOR_ADD,NumberExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression)));
   }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 462 "parser.ypp"
    { (yyval.number_expression) = (yysemantic_stack_[(3) - (2)].number_expression) ;}
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 463 "parser.ypp"
    {
	   debug("got numsym_s\n");	   
	   (yyval.number_expression) =new NumberExprAST( VariableExprASTPtr((yysemantic_stack_[(1) - (1)].varable_ref)) );
	}
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 467 "parser.ypp"
    {
	   (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));
   }
    break;

  case 160:
/* Line 661 of lalr1.cc  */
#line 472 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 475 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 478 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 479 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 480 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 481 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 482 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 483 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 484 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 487 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 488 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 489 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 491 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 492 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 495 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 496 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 497 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 498 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 499 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 500 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 502 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 503 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 504 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 505 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 506 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 507 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 508 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 509 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 510 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 511 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 512 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 513 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 514 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 515 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 516 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 517 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 518 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 519 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 519 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 207:
/* Line 661 of lalr1.cc  */
#line 526 "parser.ypp"
    {
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 529 "parser.ypp"
    {
		//TODO int should be 32bit not 64bit
		(yyval.exprtype) = new NumberTypeAST();
	}
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 536 "parser.ypp"
    {
			debug("as  %s\n",(yysemantic_stack_[(2) - (2)].exprtype)->name.c_str());
			// long varable
			// 构造类型
			(yyval.exprtype) = (yysemantic_stack_[(2) - (2)].exprtype);
		}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 544 "parser.ypp"
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
#line 551 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 552 "parser.ypp"
    {
	  // 	std::string name;
	//	name = $3;
	//	$$ = new VariableDimAST( name , ExprTypeASTPtr($2));
   }
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 557 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 560 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 561 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 564 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 567 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 219:
/* Line 661 of lalr1.cc  */
#line 568 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 220:
/* Line 661 of lalr1.cc  */
#line 571 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 221:
/* Line 661 of lalr1.cc  */
#line 574 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 575 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 225:
/* Line 661 of lalr1.cc  */
#line 582 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 583 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 587 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
	}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 588 "parser.ypp"
    { current_function = (yysemantic_stack_[(3) - (3)].symbol); }
    break;

  case 229:
/* Line 661 of lalr1.cc  */
#line 589 "parser.ypp"
    {	}
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 590 "parser.ypp"
    {
						debug("function dim as ... %p\n", (yysemantic_stack_[(9) - (9)].exprtype) );
						//$<exprtype>$ = $9;
						(yyval.function_definition) = new FunctionDimAST( (yysemantic_stack_[(9) - (3)].symbol), ExprTypeASTPtr((yysemantic_stack_[(9) - (9)].exprtype)) );
			// 到这里可以算是函数定义成功了.
	}
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 595 "parser.ypp"
    {
		(yyval.statement_list) = (yysemantic_stack_[(11) - (11)].statement_list);
	}
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 598 "parser.ypp"
    {
		current_function.clear();
		/** TODO support for functions*/
	}
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 604 "parser.ypp"
    {
		if (unclosed_subs)
		{
			debug ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 610 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 611 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 622 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 623 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 624 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 625 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 632 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 247:
/* Line 661 of lalr1.cc  */
#line 633 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 248:
/* Line 661 of lalr1.cc  */
#line 634 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 249:
/* Line 661 of lalr1.cc  */
#line 635 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 643 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 254:
/* Line 661 of lalr1.cc  */
#line 644 "parser.ypp"
    {
	   
}
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 647 "parser.ypp"
    {
	   
}
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 650 "parser.ypp"
    {
	   
}
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 655 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 656 "parser.ypp"
    {
				 
			}
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 660 "parser.ypp"
    {
	 }
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 662 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 664 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 668 "parser.ypp"
    {
		if (unclosed_fors) {
			debug ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 673 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 676 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 677 "parser.ypp"
    {  }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 680 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 684 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 684 "parser.ypp"
    {
	}
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 686 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 686 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 691 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 692 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 700 "parser.ypp"
    {
	   
}
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 703 "parser.ypp"
    {
		   
	}
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 709 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 709 "parser.ypp"
    {

	   
}
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 715 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 715 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 720 "parser.ypp"
    {if (unclosed_dos) { debug ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 721 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 721 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 724 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 724 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 725 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 731 "parser.ypp"
    {if (unclosed_whiles) { debug ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 732 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 732 "parser.ypp"
    { }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 735 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 735 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 740 "parser.ypp"
    {if (unclosed_repeats) { debug ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 742 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 742 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 745 "parser.ypp"
    {
				/*构造 IF 语句, 填充 条件表达式*/
				NumberExprASTPtr ne = NumberExprASTPtr((yysemantic_stack_[(2) - (2)].number_expression));

								
			}
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 750 "parser.ypp"
    {  /*填充真语句*/ }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 752 "parser.ypp"
    { /*填充假语句*/}
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 756 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 757 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 757 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 758 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 759 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 762 "parser.ypp"
    {if (unclosed_ifs) { debug ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 763 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 766 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 775 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 777 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 781 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 782 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 783 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 787 "parser.ypp"
    { debug("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 788 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 794 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 796 "parser.ypp"
    { debug("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 798 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 800 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 802 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 805 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 806 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 807 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 808 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 812 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 815 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 820 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 821 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 822 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 825 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 828 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 829 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 832 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 833 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 837 "parser.ypp"
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
#line 847 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 853 "parser.ypp"
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
#line 863 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 876 "parser.ypp"
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
#line 884 "parser.ypp"
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
#line 892 "parser.ypp"
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
#line 900 "parser.ypp"
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
#line 910 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 918 "parser.ypp"
    {
		debug("变量引用\n");
		(yyval.varable_ref) = new VariableRefExprAST( (yysemantic_stack_[(1) - (1)].symbol) );
	}
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 922 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 925 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 927 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 928 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 929 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 932 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 935 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 936 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 937 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 940 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 941 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 944 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 945 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 946 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 947 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 947 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 950 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 951 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 952 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 953 "parser.ypp"
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
  const short int parser::yypact_ninf_ = -587;
  const short int
  parser::yypact_[] =
  {
      3393,   -60,   -36,  -587,  -587,  -587,  2207,  -587,  1122,   -17,
      87,   133,   133,   133,  -587,  -587,  2207,  -587,  -587,  -587,
    -587,  -587,    58,   101,  -587,  -587,   133,   133,    69,  -587,
      91,  -587,  -587,   133,   167,   133,   117,   134,   155,  1805,
    1805,  1805,  1805,   205,   229,    16,   291,  -587,  -587,  -587,
    -587,  -587,   288,  -587,   294,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  2207,  -587,   -30,   -25,   170,   320,
     330,  -587,   185,   256,  -587,  -587,   277,   283,  2207,   298,
     312,   347,   349,   352,   354,   360,   361,   362,   363,   376,
     377,   378,   383,   385,   386,   388,   389,   391,   392,   393,
     394,   395,   397,   398,   399,   400,   401,   402,   403,   404,
     406,   407,   408,   421,   423,   424,   425,   426,  -587,  -587,
     430,   432,   440,   441,   447,   449,   450,   451,   454,   455,
    2207,  2207,  2207,     8,  -587,  3170,  -587,  -587,  -587,   419,
     459,  -587,  -587,  1122,   453,   419,   459,   170,  -587,  -587,
    -587,   460,   460,   460,   486,   486,     8,  3170,   133,  -587,
    -587,  -587,   458,   461,  -587,  -587,   -19,   459,  -587,   -23,
     461,   412,   462,   505,   167,   167,   465,   460,   466,   460,
       2,  2207,   464,  -587,   551,  -587,   460,   469,  -587,    -8,
       7,   535,   582,   473,   460,   167,   167,   167,  2207,  3170,
     474,  -587,   475,   476,  1122,  -587,  -587,  3393,  -587,  2207,
    1122,   372,  1610,  2207,   414,   418,   420,  1122,  -587,  -587,
    2207,  2207,  1191,  2207,  -587,  -587,   427,   427,  2207,  2207,
    2048,  2207,  2207,  2207,  2207,  2207,  2207,  1122,  1122,  1122,
    1122,  1122,  1805,  1805,  1805,  1805,  2207,  2207,  2207,  2207,
    2207,  2207,  2207,  2207,  2207,  2207,  1122,  1122,  1122,  1122,
    2207,  1122,  1122,   167,  1122,   167,  1122,  1122,  1122,  1122,
    1122,  1122,   544,   544,    -4,   849,  1122,  1122,  1122,  1122,
    1122,  1122,  1122,  -587,  -587,  2207,  2207,  2207,  2207,  2207,
    2207,  2207,  2207,  2207,  2207,  2207,  2207,   -78,  2207,  2207,
     604,  -587,  -587,  -587,   -18,  2207,  3393,  3393,  -587,  -587,
     429,    -3,  -587,   439,   457,  -587,   477,  -587,   481,   459,
    -587,  -587,   482,  -587,   481,   459,  -587,  -587,   133,   133,
    -587,  2207,   460,     8,  3066,   328,    33,  -587,  1122,   464,
     483,   485,  2207,   614,   167,   133,   133,   133,   133,   133,
     487,   481,  -587,  -587,   488,   490,  3170,  1122,  2207,  2207,
     -77,   291,  3393,  3170,   453,  -587,  -587,   495,  -587,   578,
    3393,   614,  3170,   496,   497,   498,   502,   503,   504,   453,
      71,   833,  2941,  2207,  2207,   506,   508,   494,   509,   512,
     170,  -587,   519,   520,  1255,  1318,  -587,  1357,  1462,  1640,
    1704,  1810,  3024,  3038,    99,   230,   231,   -52,   -26,    39,
     521,   522,   523,   524,  1942,  1954,  1982,  2329,  2341,   380,
    2353,   592,   981,  2365,    53,    76,   113,   121,  2385,   144,
     232,   -63,   242,    18,   243,   145,   156,   157,   244,   246,
    -587,  -587,   453,   453,   453,   453,   453,   453,  -587,  2207,
    2207,   815,    31,   444,   171,   160,    57,  -587,    19,    19,
     544,   544,   544,     8,  3170,   114,  -587,   202,  -587,  -587,
    3170,    43,    42,   526,   529,  -587,  -587,  -587,   -23,   505,
     529,   167,   167,   460,   460,  2468,  1122,  -587,  2207,  -587,
    2207,   460,   453,   167,  -587,   638,   614,   654,   614,     8,
    3170,   614,  -587,    17,  -587,   460,   460,   460,   460,   460,
    2207,  2207,  2207,   247,  3052,  3170,  -587,  -587,   530,   468,
    3393,  -587,  3298,   531,   534,  2207,  2207,   536,   538,  2207,
    2207,  2207,   254,   262,   185,   256,  -587,  -587,   470,  2207,
    2207,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  2207,  2207,
    2207,  2207,  2207,  -587,  -587,  1122,  -587,  1122,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  2207,  -587,  -587,  2207,
    -587,  1122,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
     427,  1122,  -587,   427,  1122,  -587,  1122,  -587,  -587,  -587,
    1122,  1122,  1191,   186,  2207,  -587,  -587,  2207,  3393,  -587,
    2207,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,   453,     8,  3080,   167,  2480,   167,  -587,   481,
     459,  -587,  -587,    41,    41,   653,  -587,  -587,  -587,   666,
      36,  -587,    -1,  -587,  2492,  2510,  1161,  1122,  1122,   472,
    -587,   291,  -587,  -587,  -587,  -587,  2207,   265,   266,  -587,
    -587,  2524,  2607,  2619,  -587,  -587,   540,   541,  2635,  2649,
    2663,  2746,  2760,  2774,  1217,   158,   -15,  2788,  2802,    40,
     269,   165,   274,   181,   182,    54,    77,  -587,  3142,    66,
    3170,  -587,  1122,  -587,  -587,  -587,  -587,   411,   614,   167,
     415,   416,  -587,  -587,  -587,    38,   653,   612,   618,  2207,
     619,   453,   453,   508,   275,  -587,   549,   170,  -587,  -587,
     639,   279,  -587,  -587,  -587,  -587,  -587,   531,   534,  -587,
    -587,  -587,  -587,  -587,  -587,  2207,  -587,  -587,  1122,  -587,
    -587,  -587,  1122,  -587,  1122,  -587,  -587,  1122,  -587,  -587,
    -587,  2207,  -587,  2207,  -587,  2207,  -587,  -587,  -587,  -587,
     453,   167,  -587,   614,   653,   481,   459,  -587,  -587,  -587,
    -587,   683,   620,  -587,  1122,  1122,  2885,  1122,   472,  -587,
     489,  2207,   647,  -587,  2899,   183,   198,   201,   213,  2913,
    2927,  3156,  -587,  -587,   653,  2207,  -587,  -587,   453,   453,
     631,   453,  -587,   505,   541,  3163,  3393,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  2207,  -587,  -587,  -587,  -587,
    1122,  -587,  -587,   291,    61,  3170,  3393,  3393,   453,  3393,
    3393,  -587,  -587,  -587,   291,   291,   291,   291,   290,   152,
     639,  -587,  -587,   133,  -587,  -587,  -587,  -587,  -587,  -587,
     460
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
      -587,  -587,  -587,  -188,  -587,   332,  -369,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,    65,  -587,     1,
    -587,   353,  -587,   677,   678,  -111,   817,  -587,  -587,  1498,
    -587,  -587,   478,  -225,  -587,  -587,   -24,  -587,  -170,  -587,
      28,  -587,    47,  -587,  -295,   107,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,   222,  -587,   224,  -587,
     -64,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -357,   -76,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,  -587,
    -587,  -587,  -587,  -587,  -587,  -587,  -587,  -123,  -587,  -587,
    -586,  -587,   369,  -587,  -587,  -587,  -587,  -587,  -587,   556,
    -587,  -587,  -564,  -587,  -587,    89,  -364,   684,     0,   190,
     927,   491,   543,  -587,  -217
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
        66,   521,   393,   315,   467,   330,   502,   150,   145,   391,
     391,   151,   152,   153,   522,   345,   201,   202,   203,   361,
     626,   627,   166,   172,   628,   311,   177,   179,    51,   683,
     346,   685,   213,   186,   189,   194,   489,  -217,   150,   626,
     627,   626,   627,   213,   469,   206,   207,    53,   628,   208,
     208,   282,   282,   276,   277,   278,   279,   280,   281,   686,
     686,   440,   516,   162,   163,   276,   277,   278,   279,   280,
     281,   602,   599,   208,   581,   475,   582,   282,    72,   283,
     284,   476,   291,   600,   603,   354,   355,   553,   532,   533,
     821,   288,   289,   290,   291,   746,   276,   277,   278,   279,
     280,   281,    73,   282,   747,   214,   169,   170,   822,    31,
     215,   693,  -361,   554,   282,   308,   310,   300,   471,   472,
     291,   148,   728,   686,   729,   282,   686,   310,   285,   286,
     287,   288,   289,   290,   291,   440,   695,   282,   150,   623,
     331,   624,   215,   145,   625,   629,    36,    37,    38,   294,
     295,   296,   431,   643,   433,   584,   183,   585,   304,   292,
     293,   294,   295,   296,   629,   783,   629,   834,   282,   282,
     835,   490,   162,   163,   318,   324,   555,   732,   556,   733,
     332,   836,   282,   282,   340,   292,   293,   294,   295,   296,
      67,   741,   574,   742,   283,   351,   351,   351,   146,   292,
     293,   294,   295,   296,   145,   282,   282,    66,   529,   180,
     145,   367,   167,   146,   743,   575,   744,   145,   410,   411,
     412,   413,   290,   291,   190,   149,   389,   389,   282,   205,
     647,   648,   289,   290,   291,    51,   550,   145,   145,   145,
     145,   145,   282,   285,   286,   287,   288,   289,   290,   291,
     282,   594,   576,   595,    53,   195,   145,   145,   145,   145,
     577,   145,   145,   351,   145,   351,   145,   145,   145,   145,
     145,   145,   196,   282,   282,   696,   145,   145,   145,   145,
     145,   145,   145,   579,   587,   282,   282,   282,   292,   293,
     294,   295,   296,   197,   282,   588,   589,   727,   208,   292,
     293,   294,   295,   296,   736,   216,    66,    66,   607,   608,
     282,   282,   282,   172,   292,   293,   294,   295,   296,   831,
     739,   740,   799,   753,   218,   832,   753,   282,   483,   484,
     282,   754,   641,   146,    51,    51,   491,   800,   145,   594,
     801,   596,   282,   204,   189,   505,   506,   507,   508,   509,
     209,   711,   802,    53,    53,   670,   210,   145,   672,   282,
     282,   282,    66,   391,   319,   325,   391,   551,   552,   580,
      66,   282,   282,   282,   341,   282,   282,   150,   365,   583,
     586,   590,   217,   591,   637,   146,   146,   146,   283,   284,
      51,   594,  -220,   654,   146,   219,   784,    67,    51,   594,
     146,   655,   594,   594,   712,   713,   734,   146,   735,    53,
     679,   737,   768,   738,   769,   220,   594,    53,   773,   373,
     374,   221,   709,   375,   376,   377,   378,   146,   146,   146,
     146,   146,   385,   386,   473,   474,   223,   285,   286,   287,
     288,   289,   290,   291,   478,   170,   146,   146,   146,   146,
     224,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   473,   480,   487,   488,   146,   146,   146,   146,
     146,   146,   146,   468,   640,   656,   657,   385,   703,    31,
     752,   318,   324,    31,   759,   225,   145,   226,   760,   761,
     227,    69,   228,   619,   656,   794,    67,    67,   229,   230,
     231,   232,   286,   146,   288,   289,   290,   291,   292,   293,
     294,   295,   296,    69,   233,   234,   235,   566,   301,   567,
      66,   236,    66,   237,   238,   191,   239,   240,   146,   241,
     242,   243,   244,   245,   190,   246,   247,   248,   249,   250,
     251,   252,   253,    70,   254,   255,   256,   146,    51,   313,
      51,   709,    67,   311,   214,   145,   162,   145,   347,   257,
      67,   258,   259,   260,   261,   168,   173,    53,   262,    53,
     263,   145,   292,   293,   294,   295,   296,   192,   264,   265,
     389,   145,   282,   389,   145,   266,   145,   267,   268,   269,
     145,   145,   270,   271,   215,   300,   308,   314,    66,   309,
     283,   284,   328,   329,   336,   348,   344,   291,   813,   468,
     349,   357,   358,   359,   481,   619,   310,   619,   495,   482,
     497,   502,   520,   811,   510,   511,    51,   512,   824,   825,
     519,   826,   827,   536,   523,   524,   525,   145,   145,   706,
     526,   527,   528,   473,   534,    53,   535,   538,   537,   285,
     286,   287,   288,   289,   290,   291,   539,   540,   557,   375,
     628,   558,   559,   560,   605,   320,   326,   606,   639,   692,
     644,   319,   325,   645,   764,   649,   146,   650,   717,   718,
     765,   767,   145,   620,   770,   771,   352,   352,   352,   755,
     786,   787,   796,   810,   517,   694,   763,   504,    69,   164,
     165,   677,   368,   609,   792,   392,   610,   838,   494,   807,
      67,   303,    67,   690,     0,   184,     0,   321,   327,     0,
     292,   293,   294,   295,   296,     0,     0,     0,   145,   569,
       0,   570,   145,     0,   145,     0,     0,   145,   353,   353,
     353,     0,     0,     0,     0,   146,     0,   146,     0,     0,
      70,   619,     0,     0,   352,     0,   352,     0,     0,     0,
       0,   146,     0,     0,   145,   145,     0,   145,   706,     0,
       0,   146,     0,     0,   146,     0,   146,     0,     0,     0,
     146,   146,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,     0,     0,     0,    66,    69,    69,     0,
       0,     0,     0,     0,     0,   620,   353,   620,   353,     0,
     145,     0,     0,     0,     0,     0,    66,    66,     0,    66,
      66,     0,     0,   133,    51,   144,     0,   146,   146,     0,
       0,     0,     0,   840,     0,   191,     0,     0,     0,     0,
       0,   283,   284,    53,    51,    51,     0,    51,    51,    70,
      70,     0,     0,    69,     0,     0,   479,   283,   284,     0,
       0,    69,     0,    53,    53,     0,    53,    53,     0,     0,
       0,     0,   146,   286,   287,   288,   289,   290,   291,   756,
       0,     0,     0,     0,     0,     0,     0,   192,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,     0,     0,     0,    70,   285,   286,   287,   288,
     289,   290,   291,    70,     0,     0,     0,     0,   146,     0,
       0,     0,   146,     0,   146,     0,     0,   146,     0,     0,
       0,     0,     0,     0,     0,   147,     0,     0,     0,     0,
       0,   620,     0,   292,   293,   294,   295,   296,     0,   274,
       0,     0,     0,     0,   146,   146,     0,   146,     0,     0,
     297,   292,   293,   294,   295,   296,     0,     0,     0,     0,
     530,     0,   320,   326,     0,     0,     0,   292,   293,   294,
     295,   296,     0,     0,   621,     0,    67,     0,   441,   283,
     284,     0,     0,     0,     0,     0,     0,     0,   333,     0,
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
       0,     0,     0,     0,     0,     0,   621,     0,   621,   292,
     293,   294,   295,   296,     0,   463,   463,     0,   571,     0,
     572,     0,     0,     0,     0,     0,    75,     1,     2,     0,
     708,   147,     0,     0,     0,     0,     0,   147,     0,     0,
       0,    70,     0,    81,   147,     0,     0,     0,     0,     0,
       0,     0,     0,   390,   390,   492,     0,     0,   622,   499,
     622,     0,     0,     0,   147,   147,   147,   147,   147,   283,
     284,     0,     0,     0,   513,     0,     0,     0,     0,     0,
     757,     0,     0,   147,   147,   147,   147,     0,   147,   147,
       0,   147,     0,   147,   147,   147,   147,   147,   147,     0,
     463,   463,     0,   147,   147,   147,   147,   147,   147,   147,
      93,    94,    95,    96,    97,     0,     0,     0,   285,   286,
     287,   288,   289,   290,   291,   283,   284,     0,     0,     0,
     110,   111,   758,     0,     0,     0,   116,   117,   118,   119,
       0,   121,   621,   123,     0,   125,   126,   127,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,   708,
     143,     0,     0,   283,   284,   147,     0,     0,     0,     0,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,   147,     0,     0,    69,     0,   292,
     293,   294,   295,   296,   622,     0,     0,     0,   699,     0,
     700,     0,     0,   612,     0,   613,     0,    69,    69,     0,
      69,    69,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,     0,     0,   283,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,   463,   463,     0,   292,   293,   294,   295,   296,
       0,     0,     0,     0,   725,     0,   726,     0,     0,    70,
      70,     0,    70,    70,     0,   283,   284,     0,     0,     0,
       0,     0,   665,     0,   666,   285,   286,   287,   288,   289,
     290,   291,     0,   292,   293,   294,   295,   296,   669,     0,
       0,     0,     0,     0,   541,     0,     0,     0,   671,     0,
       0,   673,     0,   674,     0,     0,     0,   675,   676,     0,
       0,   463,     0,   147,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,   293,   294,   295,
     296,     0,     0,     0,   701,   702,     0,   542,     0,     0,
       0,     0,     0,   463,     0,     0,     0,     0,     0,     0,
     283,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,     0,   147,   292,   293,   294,   295,   296,
       0,     0,     0,     0,     0,     0,   543,     0,   147,   750,
       0,     0,     0,     0,   135,     0,     0,   147,   147,     0,
     147,   147,     0,   147,   157,     0,     0,   147,   147,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   775,     0,     0,     0,   776,
       0,   777,     0,     0,   778,     0,     0,     0,     0,     0,
       0,     0,   212,     0,   147,   147,   707,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,     0,     0,
       0,   788,   789,     0,   791,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,     0,     0,     0,     0,     0,
       0,   544,   499,     0,     0,     0,     0,     0,     0,   147,
       0,     0,     0,     0,     0,     0,     0,  -309,   283,   284,
       0,     0,     0,     0,     0,     0,     0,   818,   272,   273,
     275,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   283,   284,
       0,     0,     0,     0,  -302,   147,     0,     0,     0,   147,
       0,   147,     0,     0,   147,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,   147,     0,   147,   707,   356,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,   363,     0,     0,
       0,   372,   283,   284,     0,     0,     0,     0,   380,   381,
       0,   382,     0,     0,     0,     0,   394,   395,   397,   398,
     399,   400,   401,   402,   403,     0,     0,   147,   292,   293,
     294,   295,   296,     0,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,     0,     0,     0,     0,   428,     0,
       0,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,     0,     0,     0,     0,     0,     0,   545,
       0,     0,     0,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,     0,   464,   464,     0,     0,
       0,     0,     0,   470,     0,     0,     0,     0,    74,    75,
       1,     2,     0,    76,    77,    78,    79,     0,   283,   284,
       0,     0,     0,     0,     0,    80,    81,     0,     0,   485,
       0,     0,   292,   293,   294,   295,   296,     0,     0,     0,
     500,     0,     0,   546,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   514,   515,    82,    83,
       0,     0,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
       0,   464,   464,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,     0,   100,   101,     0,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,     0,     0,   292,   293,
     294,   295,   296,   132,     0,   198,     0,   592,   593,   547,
     283,   284,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,   284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,     0,   616,     0,
     283,   284,     0,     0,     0,     0,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,   634,   635,
     636,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,   464,   464,     0,     0,   651,   652,   653,
       0,     0,     0,     0,     0,     0,     0,   658,   659,   285,
     286,   287,   288,   289,   290,   291,   660,   661,   662,   663,
     664,    74,    75,     1,     2,     0,    76,    77,    78,    79,
       0,     0,     0,     0,   667,     0,     0,   668,    80,    81,
     292,   293,   294,   295,   296,     0,     0,     0,     0,     0,
       0,   561,   292,   293,   294,   295,   296,     0,     0,     0,
       0,     0,   464,   562,     0,   678,     0,     0,   680,     0,
       0,    82,    83,     0,     0,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,     0,     0,     0,     0,     0,
       0,   563,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,     0,    99,   464,   100,   101,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   396,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   766,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,     1,     2,     0,    76,    77,    78,    79,     0,
       0,     0,     0,   774,     0,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   779,
       0,   780,     0,   781,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,     0,     0,     0,     0,     0,     0,     0,   795,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   500,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    99,   815,   100,   101,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   283,   284,     0,
       0,     0,     0,     0,     0,   132,     0,     0,     0,   283,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   283,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   283,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,   283,   284,     0,     0,     0,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,     0,   292,   293,   294,
     295,   296,     0,     0,     0,     0,     0,     0,   564,   292,
     293,   294,   295,   296,     0,     0,   283,   284,     0,     0,
     565,   292,   293,   294,   295,   296,     0,     0,   283,   284,
       0,     0,   568,   292,   293,   294,   295,   296,     0,     0,
     283,   284,     0,     0,   573,     0,     0,     0,     0,     0,
       0,     0,     0,   292,   293,   294,   295,   296,   283,   284,
       0,     0,     0,     0,   578,   285,   286,   287,   288,   289,
     290,   291,   283,   284,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,     0,     0,   292,   293,   294,   295,
     296,     0,     0,     0,     0,     0,     0,   611,   292,   293,
     294,   295,   296,     0,     0,   283,   284,     0,     0,   684,
     292,   293,   294,   295,   296,     0,     0,   283,   284,     0,
       0,   697,     0,     0,     0,     0,     0,     0,   292,   293,
     294,   295,   296,   283,   284,     0,     0,     0,     0,   698,
       0,     0,   292,   293,   294,   295,   296,   283,   284,     0,
       0,     0,     0,   714,   285,   286,   287,   288,   289,   290,
     291,   283,   284,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   285,   286,   287,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,     0,     0,     0,   292,   293,   294,   295,   296,
       0,     0,     0,     0,     0,     0,   715,   292,   293,   294,
     295,   296,     0,     0,   283,   284,     0,     0,   716,     0,
       0,     0,     0,   292,   293,   294,   295,   296,   283,   284,
       0,     0,     0,     0,   719,     0,     0,   292,   293,   294,
     295,   296,   283,   284,     0,     0,     0,     0,   720,     0,
       0,   292,   293,   294,   295,   296,   283,   284,     0,     0,
       0,     0,   721,   285,   286,   287,   288,   289,   290,   291,
     283,   284,     0,     0,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
       0,   285,   286,   287,   288,   289,   290,   291,     0,     0,
       0,     0,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,     0,
       0,     0,     0,     0,     0,   722,     0,     0,   292,   293,
     294,   295,   296,   283,   284,     0,     0,     0,     0,   723,
       0,     0,   292,   293,   294,   295,   296,   283,   284,     0,
       0,     0,     0,   724,     0,     0,   292,   293,   294,   295,
     296,   283,   284,     0,     0,     0,     0,   730,     0,     0,
     292,   293,   294,   295,   296,   283,   284,     0,     0,     0,
       0,   731,   285,   286,   287,   288,   289,   290,   291,   283,
     284,     0,     0,     0,     0,     0,   285,   286,   287,   288,
     289,   290,   291,     0,     0,     0,     0,     0,     0,     0,
     285,   286,   287,   288,   289,   290,   291,     0,     0,     0,
       0,     0,     0,     0,   285,   286,   287,   288,   289,   290,
     291,     0,     0,     0,     0,     0,     0,     0,   285,   286,
     287,   288,   289,   290,   291,     0,     0,     0,     0,     0,
       0,     0,     0,   292,   293,   294,   295,   296,     0,     0,
       0,     0,     0,     0,   790,     0,     0,   292,   293,   294,
     295,   296,   283,   284,     0,     0,     0,     0,   798,     0,
       0,   292,   293,   294,   295,   296,   283,   284,     0,     0,
       0,     0,   803,     0,     0,   292,   293,   294,   295,   296,
     283,   284,     0,     0,     0,     0,   804,     0,     0,   292,
     293,   294,   295,   296,   283,   284,     0,     0,   531,     0,
       0,   285,   286,   287,   288,   289,   290,   291,   283,   284,
       0,     0,     0,     0,     0,   285,   286,   287,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,     0,   285,
     286,   287,   288,   289,   290,   291,     0,     0,     0,     0,
       0,     0,     0,   285,   286,   287,   288,   289,   290,   291,
       0,     0,     0,   486,     0,     0,     0,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,   682,     0,     0,
     283,   284,   292,   293,   294,   295,   296,     0,     0,     0,
       0,   548,     0,     0,   283,   284,   292,   293,   294,   295,
     296,   283,   284,     0,     0,   549,   745,     0,   283,   284,
     292,   293,   294,   295,   296,     0,     0,     0,     0,   638,
       0,     0,   805,     0,   292,   293,   294,   295,   296,   285,
     286,   287,   288,   289,   290,   291,     0,   812,   292,   293,
     294,   295,   296,   285,   286,   287,   288,   289,   290,   291,
     285,   286,   287,   288,   289,   290,   291,   285,   286,   287,
     288,   289,   290,   291,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     292,   293,   294,   295,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   293,   294,   295,   296,     0,
       0,   292,   293,   294,   295,   296,     0,     0,   292,   293,
     294,   295,   296,     1,     2,   628,     0,     0,     0,     0,
       3,     4,     5,     0,     6,     7,     0,     8,     9,    10,
       0,     0,    11,    12,    13,    14,    15,     0,     0,    16,
       0,    17,     0,     0,     0,    18,     0,    19,     0,    20,
       0,    21,     0,     0,     0,     0,     0,    22,    23,    24,
      25,     0,     0,    26,    27,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,     0,    31,     0,    32,     0,
       0,     0,    33,     0,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,     0,
       0,    39,    40,     0,    41,     0,     0,    42,     1,     2,
       0,     0,     0,     0,     0,     3,     4,     5,     0,     6,
       7,    43,     8,     9,    10,     0,     0,    11,    12,    13,
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
         0,   370,   227,   173,   299,     3,     7,     5,     8,   226,
     227,    11,    12,    13,   371,    23,    40,    41,    42,   207,
       3,     4,    22,    23,     7,    48,    26,    27,     0,   615,
      23,   617,    62,    33,    34,    35,     3,    62,     5,     3,
       4,     3,     4,    62,    62,    29,    30,     0,     7,     7,
       7,   129,   129,    57,    58,    59,    60,    61,    62,   623,
     624,   139,   139,     5,     6,    57,    58,    59,    60,    61,
      62,    29,    29,     7,   137,    78,   139,   129,   138,     8,
       9,    84,    63,    40,    42,   196,   197,   139,   383,   384,
      29,    60,    61,    62,    63,    29,    57,    58,    59,    60,
      61,    62,   138,   129,    38,   135,     5,     6,    47,    68,
     135,    75,   135,   139,   129,   138,   135,   135,   306,   307,
      63,   138,   137,   687,   139,   129,   690,   135,    57,    58,
      59,    60,    61,    62,    63,   139,   137,   129,     5,   496,
     138,   498,   135,   143,   501,   128,    88,    89,    90,   130,
     131,   132,   263,   522,   265,   137,    65,   139,   158,   128,
     129,   130,   131,   132,   128,   751,   128,    15,   129,   129,
      18,   138,     5,     6,   174,   175,   137,   137,   139,   139,
     180,    29,   129,   129,   184,   128,   129,   130,   131,   132,
       0,   137,   139,   139,     8,   195,   196,   197,     8,   128,
     129,   130,   131,   132,   204,   129,   129,   207,   137,   140,
     210,   211,    22,    23,   137,   139,   139,   217,   242,   243,
     244,   245,    62,    63,    34,   138,   226,   227,   129,     0,
     525,   526,    61,    62,    63,   207,   137,   237,   238,   239,
     240,   241,   129,    57,    58,    59,    60,    61,    62,    63,
     129,   137,   139,   139,   207,   138,   256,   257,   258,   259,
     139,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   138,   129,   129,   632,   276,   277,   278,   279,
     280,   281,   282,   139,   139,   129,   129,   129,   128,   129,
     130,   131,   132,   138,   129,   139,   139,   139,     7,   128,
     129,   130,   131,   132,   139,   135,   306,   307,   478,   479,
     129,   129,   129,   313,   128,   129,   130,   131,   132,    29,
     139,   139,   139,   687,   139,    35,   690,   129,   328,   329,
     129,   688,   520,   143,   306,   307,   336,   139,   338,   137,
     139,   139,   129,   138,   344,   345,   346,   347,   348,   349,
      62,   646,   139,   306,   307,   580,    62,   357,   583,   129,
     129,   129,   362,   580,   174,   175,   583,   137,   137,   137,
     370,   129,   129,   129,   184,   129,   129,     5,     6,   137,
     137,   137,    62,   137,   137,   195,   196,   197,     8,     9,
     362,   137,    62,   139,   204,   139,   753,   207,   370,   137,
     210,   139,   137,   137,   139,   139,   137,   217,   139,   362,
     598,   137,   137,   139,   139,   138,   137,   370,   139,     5,
       6,   138,   639,     5,     6,     5,     6,   237,   238,   239,
     240,   241,     5,     6,     5,     6,   138,    57,    58,    59,
      60,    61,    62,    63,     5,     6,   256,   257,   258,   259,
     138,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,     5,     6,   136,   137,   276,   277,   278,   279,
     280,   281,   282,     5,     6,     5,     6,     5,     6,    68,
      69,   481,   482,    68,    69,   138,   486,   138,    72,    73,
     138,     0,   138,   493,     5,     6,   306,   307,   138,   138,
     138,   138,    58,   313,    60,    61,    62,    63,   128,   129,
     130,   131,   132,    22,   138,   138,   138,   137,    32,   139,
     520,   138,   522,   138,   138,    34,   138,   138,   338,   138,
     138,   138,   138,   138,   344,   138,   138,   138,   138,   138,
     138,   138,   138,     0,   138,   138,   138,   357,   520,   137,
     522,   768,   362,    48,   135,   555,     5,   557,    23,   138,
     370,   138,   138,   138,   138,    22,    23,   520,   138,   522,
     138,   571,   128,   129,   130,   131,   132,    34,   138,   138,
     580,   581,   129,   583,   584,   138,   586,   138,   138,   138,
     590,   591,   138,   138,   135,   135,   138,   135,   598,   138,
       8,     9,   137,   137,   140,    23,   137,    63,   796,     5,
     137,   137,   137,   137,   137,   615,   135,   617,   135,   137,
     135,     7,    44,   793,   137,   137,   598,   137,   816,   817,
     135,   819,   820,   139,   138,   138,   138,   637,   638,   639,
     138,   138,   138,     5,   138,   598,   138,   135,   139,    57,
      58,    59,    60,    61,    62,    63,   137,   137,   137,     5,
       7,   139,   139,   139,   138,   174,   175,   138,   138,     3,
     139,   481,   482,   139,    62,   139,   486,   139,   138,   138,
      62,    62,   682,   493,   135,    46,   195,   196,   197,   689,
       7,    71,    45,    62,   362,   630,   695,   344,   207,    22,
      22,   594,   211,   481,   768,   227,   482,   830,   339,   785,
     520,   155,   522,   624,    -1,    31,    -1,   174,   175,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,   728,   137,
      -1,   139,   732,    -1,   734,    -1,    -1,   737,   195,   196,
     197,    -1,    -1,    -1,    -1,   555,    -1,   557,    -1,    -1,
     207,   751,    -1,    -1,   263,    -1,   265,    -1,    -1,    -1,
      -1,   571,    -1,    -1,   764,   765,    -1,   767,   768,    -1,
      -1,   581,    -1,    -1,   584,    -1,   586,    -1,    -1,    -1,
     590,   591,    -1,    -1,    -1,    -1,    -1,    -1,   598,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   796,   306,   307,    -1,
      -1,    -1,    -1,    -1,    -1,   615,   263,   617,   265,    -1,
     810,    -1,    -1,    -1,    -1,    -1,   816,   817,    -1,   819,
     820,    -1,    -1,     6,   796,     8,    -1,   637,   638,    -1,
      -1,    -1,    -1,   833,    -1,   344,    -1,    -1,    -1,    -1,
      -1,     8,     9,   796,   816,   817,    -1,   819,   820,   306,
     307,    -1,    -1,   362,    -1,    -1,   313,     8,     9,    -1,
      -1,   370,    -1,   816,   817,    -1,   819,   820,    -1,    -1,
      -1,    -1,   682,    58,    59,    60,    61,    62,    63,   689,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   344,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   362,    57,    58,    59,    60,
      61,    62,    63,   370,    -1,    -1,    -1,    -1,   728,    -1,
      -1,    -1,   732,    -1,   734,    -1,    -1,   737,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,    -1,
      -1,   751,    -1,   128,   129,   130,   131,   132,    -1,   132,
      -1,    -1,    -1,    -1,   764,   765,    -1,   767,    -1,    -1,
     143,   128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,
     137,    -1,   481,   482,    -1,    -1,    -1,   128,   129,   130,
     131,   132,    -1,    -1,   493,    -1,   796,    -1,   139,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,
     810,    -1,    -1,    -1,    -1,    -1,   816,   817,    -1,   819,
     820,   520,    -1,   522,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,    -1,   481,   482,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,    -1,   493,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   237,   238,   239,   240,   241,   242,
      -1,    -1,    -1,   520,    -1,   522,    -1,    -1,    -1,    -1,
     143,    -1,    -1,   256,   257,   258,   259,    -1,   261,   262,
      -1,   264,    -1,   266,   267,   268,   269,   270,   271,   598,
      -1,    -1,    -1,   276,   277,   278,   279,   280,   281,   282,
      -1,    -1,    -1,    -1,    -1,    -1,   615,    -1,   617,   128,
     129,   130,   131,   132,    -1,   298,   299,    -1,   137,    -1,
     139,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,
     639,   204,    -1,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,   598,    -1,    21,   217,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,   338,    -1,    -1,   615,   342,
     617,    -1,    -1,    -1,   237,   238,   239,   240,   241,     8,
       9,    -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,
     689,    -1,    -1,   256,   257,   258,   259,    -1,   261,   262,
      -1,   264,    -1,   266,   267,   268,   269,   270,   271,    -1,
     383,   384,    -1,   276,   277,   278,   279,   280,   281,   282,
      88,    89,    90,    91,    92,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,     8,     9,    -1,    -1,    -1,
     108,   109,   689,    -1,    -1,    -1,   114,   115,   116,   117,
      -1,   119,   751,   121,    -1,   123,   124,   125,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,   768,
     138,    -1,    -1,     8,     9,   338,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,   357,    -1,    -1,   796,    -1,   128,
     129,   130,   131,   132,   751,    -1,    -1,    -1,   137,    -1,
     139,    -1,    -1,   486,    -1,   488,    -1,   816,   817,    -1,
     819,   820,    57,    58,    59,    60,    61,    62,    63,   128,
     129,   130,   131,   132,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   796,
      -1,    -1,   525,   526,    -1,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,   137,    -1,   139,    -1,    -1,   816,
     817,    -1,   819,   820,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,   555,    -1,   557,    57,    58,    59,    60,    61,
      62,    63,    -1,   128,   129,   130,   131,   132,   571,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,   581,    -1,
      -1,   584,    -1,   586,    -1,    -1,    -1,   590,   591,    -1,
      -1,   594,    -1,   486,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
     132,    -1,    -1,    -1,   637,   638,    -1,   139,    -1,    -1,
      -1,    -1,    -1,   646,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   555,    -1,   557,   128,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,   571,   682,
      -1,    -1,    -1,    -1,     6,    -1,    -1,   580,   581,    -1,
     583,   584,    -1,   586,    16,    -1,    -1,   590,   591,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   728,    -1,    -1,    -1,   732,
      -1,   734,    -1,    -1,   737,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,   637,   638,   639,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,   764,   765,    -1,   767,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   785,    -1,    -1,    -1,    -1,    -1,    -1,   682,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   810,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,
      -1,    -1,    -1,    -1,    44,   728,    -1,    -1,    -1,   732,
      -1,   734,    -1,    -1,   737,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   764,   765,    -1,   767,   768,   198,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,   209,    -1,    -1,
      -1,   213,     8,     9,    -1,    -1,    -1,    -1,   220,   221,
      -1,   223,    -1,    -1,    -1,    -1,   228,   229,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,   810,   128,   129,
     130,   131,   132,    -1,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,    -1,    -1,    -1,    -1,   260,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,   128,   129,
     130,   131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,
      -1,    -1,    -1,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,    -1,   298,   299,    -1,    -1,
      -1,    -1,    -1,   305,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,   331,
      -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,    -1,
     342,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   358,   359,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   383,   384,    -1,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    -1,    97,    98,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    -1,    -1,    -1,   128,   129,
     130,   131,   132,   138,    -1,   140,    -1,   449,   450,   139,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   488,    -1,   490,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,   510,   511,
     512,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,   525,   526,    -1,    -1,   529,   530,   531,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,   540,    57,
      58,    59,    60,    61,    62,    63,   548,   549,   550,   551,
     552,     3,     4,     5,     6,    -1,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,   566,    -1,    -1,   569,    20,    21,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,    -1,   594,   139,    -1,   597,    -1,    -1,   600,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,   646,    97,    98,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   699,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,   725,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   741,
      -1,   743,    -1,   745,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   771,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   785,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    95,   805,    97,    98,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,     8,     9,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,   132,    -1,    -1,    -1,    -1,    -1,    -1,   139,   128,
     129,   130,   131,   132,    -1,    -1,     8,     9,    -1,    -1,
     139,   128,   129,   130,   131,   132,    -1,    -1,     8,     9,
      -1,    -1,   139,   128,   129,   130,   131,   132,    -1,    -1,
       8,     9,    -1,    -1,   139,    -1,    -1,    -1,    -1,    -1,
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
     130,   131,   132,     8,     9,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   128,   129,   130,   131,   132,     8,     9,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   128,   129,   130,   131,
     132,     8,     9,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     128,   129,   130,   131,   132,     8,     9,    -1,    -1,    -1,
      -1,   139,    57,    58,    59,    60,    61,    62,    63,     8,
       9,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,    -1,    -1,   128,   129,   130,
     131,   132,     8,     9,    -1,    -1,    -1,    -1,   139,    -1,
      -1,   128,   129,   130,   131,   132,     8,     9,    -1,    -1,
      -1,    -1,   139,    -1,    -1,   128,   129,   130,   131,   132,
       8,     9,    -1,    -1,    -1,    -1,   139,    -1,    -1,   128,
     129,   130,   131,   132,     8,     9,    -1,    -1,   137,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,     8,     9,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    67,    -1,    -1,
       8,     9,   128,   129,   130,   131,   132,    -1,    -1,    -1,
      -1,   137,    -1,    -1,     8,     9,   128,   129,   130,   131,
     132,     8,     9,    -1,    -1,   137,    34,    -1,     8,     9,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,   137,
      -1,    -1,    36,    -1,   128,   129,   130,   131,   132,    57,
      58,    59,    60,    61,    62,    63,    -1,    44,   128,   129,
     130,   131,   132,    57,    58,    59,    60,    61,    62,    63,
      57,    58,    59,    60,    61,    62,    63,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,   132,    -1,
      -1,   128,   129,   130,   131,   132,    -1,    -1,   128,   129,
     130,   131,   132,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    -1,    16,    17,    -1,    19,    20,    21,
      -1,    -1,    24,    25,    26,    27,    28,    -1,    -1,    31,
      -1,    33,    -1,    -1,    -1,    37,    -1,    39,    -1,    41,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    68,    -1,    70,    -1,
      -1,    -1,    74,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    93,    94,    -1,    96,    -1,    -1,    99,     5,     6,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,    16,
      17,   113,    19,    20,    21,    -1,    -1,    24,    25,    26,
      27,    28,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      37,    -1,    39,    -1,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    -1,    -1,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      -1,    68,    -1,    70,    -1,    -1,    -1,    74,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    93,    94,    -1,    96,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113
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
      62,   179,    44,   144,   240,   170,   205,   220,   167,   192,
     249,    29,    47,   245,   144,   144,   144,   144,   206,   193,
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
     139,   191,   179,   192,   144,   193,   194,    -1,    29,    -1,
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
         0,   192,   192,   210,   211,   214,   215,   215,   224,   225,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   243,   249,   250,   251,   252,   253,   253,   254,
     254,   255,   267,   274,   281,   281,   282,   282,   283,   286,
     291,   292,   297,   300,   301,   302,   303,   304,   305,   306,
     307,   307,   308,   308,   309,   310,   311,   314,   315,   318,
     319,   320,   320,   323,   323,   324,   324,   325,   326,   329,
     330,   333,   336,   337,   340,   341,   342,   345,   346,   349,
     350,   351,   352,   355,   356,   359,   366,   369,   370,   371,
     372,   373,   374,   379,   380,   383,   384,   385,   386,   387,
     388,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   412,   415,   415,   416,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   443,   448,   451,   454,   458,   462,   463,   467,
     472,   475,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   519,   522,   523,   526,   529,   535,
     536,   544,   551,   552,   557,   560,   561,   564,   567,   568,
     571,   574,   575,   578,   579,   582,   583,   587,   588,   589,
     590,   595,   587,   604,   610,   611,   614,   615,   618,   619,
     622,   623,   624,   625,   628,   629,   632,   633,   634,   635,
     638,   639,   640,   643,   644,   647,   650,   655,   656,   660,
     662,   655,   668,   673,   676,   677,   680,   681,   684,   684,
     686,   684,   691,   692,   695,   696,   699,   700,   700,   708,
     709,   709,   709,   715,   715,   715,   720,   721,   721,   724,
     724,   725,   724,   731,   732,   732,   735,   735,   735,   740,
     742,   741,   745,   750,   752,   745,   756,   757,   756,   758,
     758,   762,   763,   766,   769,   770,   773,   775,   777,   774,
     781,   782,   783,   784,   787,   788,   793,   795,   797,   799,
     801,   805,   805,   806,   806,   807,   807,   808,   808,   811,
     815,   820,   821,   822,   825,   828,   829,   832,   833,   837,
     837,   853,   853,   871,   872,   875,   876,   884,   892,   900,
     910,   918,   922,   925,   927,   928,   929,   932,   935,   936,
     937,   940,   941,   944,   945,   946,   947,   947,   950,   951,
     952,   953
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
  const int parser::yylast_ = 3506;
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
#line 4304 "/home/cai/projects/basic/compiler/parser.cpp"
