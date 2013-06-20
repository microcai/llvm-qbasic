/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2013 Free Software Foundation, Inc.
   
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
/* Line 283 of lalr1.cc  */
#line 23 "parser.ypp"


/* Include main header file. */
#include "qbc.h"
#include "ast.hpp"
#include "parser.hpp"

extern	StatementAST * program;

extern int yylex(qb::parser::semantic_type * yylval_param );

extern int yylineno;

#define debug printf

/* Global variables. */
bool useDefautSubMain = true;	/* shall we treat the while file as an sub main ? */

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

void qb::parser::error(const parser::location_type& loc, const std::string& msg)
{
	std::cerr << msg << " at line " << yylineno << std::endl ;
	exit(1);
}


/* Line 283 of lalr1.cc  */
#line 76 "/home/cai/projects/basic/compiler/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */

/* Line 289 of lalr1.cc  */
#line 84 "/home/cai/projects/basic/compiler/parser.cpp"


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
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

/* Line 357 of lalr1.cc  */
#line 21 "parser.ypp"
namespace qb {
/* Line 357 of lalr1.cc  */
#line 180 "/home/cai/projects/basic/compiler/parser.cpp"

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
    YYUSE (yytype);
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

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    YYUSE (yytype);
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

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_.clear ();
    yysemantic_stack_.clear ();
    yylocation_stack_.clear ();
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

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 664 of lalr1.cc  */
#line 175 "parser.ypp"
    {
			if(useDefautSubMain){
				debug("program ended , no main()\n");
				program = new DefaultMainFunctionAST( (yysemantic_stack_[(2) - (1)].codeblocks) );
			}else{
				program = (yysemantic_stack_[(2) - (1)].codeblocks);
				debug("module ended\n");
			}
			YYACCEPT;
		}
    break;

  case 3:
/* Line 664 of lalr1.cc  */
#line 185 "parser.ypp"
    {

			debug("!!!no new line at the end of file!!!\n"); exit(1);
			if(useDefautSubMain){
				debug("program ended\n");
				program = new DefaultMainFunctionAST( (yysemantic_stack_[(3) - (1)].codeblocks) );
			}else{
				program = (yysemantic_stack_[(3) - (1)].codeblocks);
				debug("module ended\n");
			}
			YYACCEPT;			
		}
    break;

  case 4:
/* Line 664 of lalr1.cc  */
#line 199 "parser.ypp"
    {
					(yyval.codeblocks) = (yysemantic_stack_[(2) - (1)].codeblocks);
					if(!(yysemantic_stack_[(2) - (1)].codeblocks)){
						(yysemantic_stack_[(2) - (1)].codeblocks) = (yyval.codeblocks) = new CodeBlockAST;
					}
					if((yysemantic_stack_[(2) - (2)].statement_list)){
						(yyval.codeblocks)->addchild((yysemantic_stack_[(2) - (2)].statement_list));
					}else{
					}
	}
    break;

  case 5:
/* Line 664 of lalr1.cc  */
#line 209 "parser.ypp"
    {
		(yyval.codeblocks) = 0;
		if((yysemantic_stack_[(1) - (1)].statement_list)){
			(yyval.codeblocks) = new CodeBlockAST; 	(yyval.codeblocks)->addchild((yysemantic_stack_[(1) - (1)].statement_list));
		}
	}
    break;

  case 6:
/* Line 664 of lalr1.cc  */
#line 216 "parser.ypp"
    { (yyval.statement_list)=(yysemantic_stack_[(2) - (1)].statement_list);  }
    break;

  case 7:
/* Line 664 of lalr1.cc  */
#line 217 "parser.ypp"
    {
		if(!(yysemantic_stack_[(2) - (1)].statement)){debug("statement nil\n");}
		(yyval.statement_list) = new StatementsAST ; (yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(2) - (1)].statement)));
	}
    break;

  case 8:
/* Line 664 of lalr1.cc  */
#line 221 "parser.ypp"
    { (yyval.statement_list) = 0;}
    break;

  case 9:
/* Line 664 of lalr1.cc  */
#line 222 "parser.ypp"
    {
			ExprStmtAST * callstmt =  new ExprStmtAST( (yysemantic_stack_[(2) - (1)].expression) );
			(yyval.statement_list) = new StatementsAST ;
			(yyval.statement_list)->push_back( StatementASTPtr(callstmt)  );
	}
    break;

  case 10:
/* Line 664 of lalr1.cc  */
#line 229 "parser.ypp"
    {  (yyval.statement_list) = (yysemantic_stack_[(3) - (1)].statement_list); (yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (3)].statement))); }
    break;

  case 11:
/* Line 664 of lalr1.cc  */
#line 230 "parser.ypp"
    {
				(yyval.statement_list) = new StatementsAST ;
				(yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (1)].statement)));
				(yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (3)].statement)));
		}
    break;

  case 12:
/* Line 664 of lalr1.cc  */
#line 237 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].printstatement); }
    break;

  case 13:
/* Line 664 of lalr1.cc  */
#line 238 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].dim_item); }
    break;

  case 14:
/* Line 664 of lalr1.cc  */
#line 239 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].dim_item); }
    break;

  case 15:
/* Line 664 of lalr1.cc  */
#line 240 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].variable_assignment);}
    break;

  case 16:
/* Line 664 of lalr1.cc  */
#line 241 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].variable_assignment);}
    break;

  case 17:
/* Line 664 of lalr1.cc  */
#line 242 "parser.ypp"
    { (yyval.statement) = new ReturnAST((yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 18:
/* Line 664 of lalr1.cc  */
#line 243 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].if_clause);}
    break;

  case 19:
/* Line 664 of lalr1.cc  */
#line 244 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].while_loop);}
    break;

  case 20:
/* Line 664 of lalr1.cc  */
#line 245 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].for_loop);}
    break;

  case 21:
/* Line 664 of lalr1.cc  */
#line 246 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 22:
/* Line 664 of lalr1.cc  */
#line 247 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 23:
/* Line 664 of lalr1.cc  */
#line 249 "parser.ypp"
    { /*TODO*/debug("here====3====\n"); exit(1);	}
    break;

  case 24:
/* Line 664 of lalr1.cc  */
#line 252 "parser.ypp"
    {
		(yyval.exprtype) = new ExprType (NumberExprTypeAST::GetNumberExprTypeAST());
	}
    break;

  case 25:
/* Line 664 of lalr1.cc  */
#line 255 "parser.ypp"
    {
		(yyval.exprtype) = new ExprType (StringExprTypeAST::GetStringExprTypeAST());
	}
    break;

  case 26:
/* Line 664 of lalr1.cc  */
#line 258 "parser.ypp"
    {
		debug("define as user type not supported\n");
		exit(1);
	}
    break;

  case 27:
/* Line 664 of lalr1.cc  */
#line 265 "parser.ypp"
    {

		(yysemantic_stack_[(3) - (3)].expression_list)->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(3) - (2)].printinto), (yysemantic_stack_[(3) - (3)].expression_list) );
		
		debug("got print1 done\n");
	}
    break;

  case 28:
/* Line 664 of lalr1.cc  */
#line 272 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 29:
/* Line 664 of lalr1.cc  */
#line 275 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 30:
/* Line 664 of lalr1.cc  */
#line 278 "parser.ypp"
    {
		ExprListAST * exprList = new ExprListAST;
		exprList->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(2) - (2)].printinto), exprList );
	}
    break;

  case 31:
/* Line 664 of lalr1.cc  */
#line 285 "parser.ypp"
    { debug("print has got itger\n") ;}
    break;

  case 32:
/* Line 664 of lalr1.cc  */
#line 286 "parser.ypp"
    { (yyval.printinto) = 0;}
    break;

  case 33:
/* Line 664 of lalr1.cc  */
#line 289 "parser.ypp"
    { (yyval.expression_list) = (yysemantic_stack_[(3) - (1)].expression_list) ; (yyval.expression_list)->Append((yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 34:
/* Line 664 of lalr1.cc  */
#line 290 "parser.ypp"
    {
		(yyval.expression_list) =  new ExprListAST;
		(yyval.expression_list)->Append((yysemantic_stack_[(1) - (1)].expression));
	}
    break;

  case 36:
/* Line 664 of lalr1.cc  */
#line 297 "parser.ypp"
    { (yyval.expression) = (yysemantic_stack_[(3) - (2)].expression) ;}
    break;

  case 37:
/* Line 664 of lalr1.cc  */
#line 298 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_ADD , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 38:
/* Line 664 of lalr1.cc  */
#line 299 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_SUB , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 39:
/* Line 664 of lalr1.cc  */
#line 300 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_MUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 40:
/* Line 664 of lalr1.cc  */
#line 301 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_DIV , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 41:
/* Line 664 of lalr1.cc  */
#line 302 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESS , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 42:
/* Line 664 of lalr1.cc  */
#line 303 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESSEQU , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 43:
/* Line 664 of lalr1.cc  */
#line 304 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATER , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 44:
/* Line 664 of lalr1.cc  */
#line 305 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATEREQUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 45:
/* Line 664 of lalr1.cc  */
#line 306 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_EQUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 46:
/* Line 664 of lalr1.cc  */
#line 307 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_EQUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 48:
/* Line 664 of lalr1.cc  */
#line 310 "parser.ypp"
    {
			(yyval.expression) = new ConstNumberExprAST( (yysemantic_stack_[(1) - (1)].integer) );
		}
    break;

  case 49:
/* Line 664 of lalr1.cc  */
#line 313 "parser.ypp"
    {
			(yyval.expression) = new ConstStringExprAST((yysemantic_stack_[(1) - (1)].string));
		}
    break;

  case 50:
/* Line 664 of lalr1.cc  */
#line 316 "parser.ypp"
    { 
			ExprAST* zero = new ConstNumberExprAST(0);
			(yyval.expression) = new CalcExprAST(zero, OPERATOR_SUB, (yysemantic_stack_[(2) - (2)].expression)); 
		}
    break;

  case 51:
/* Line 664 of lalr1.cc  */
#line 322 "parser.ypp"
    {
		//VariableExprAST * varref = new VariableExprAST($1);
		(yyval.variable_assignment) = new AssigmentAST((yysemantic_stack_[(3) - (1)].varref), (yysemantic_stack_[(3) - (3)].expression));
	}
    break;

  case 52:
/* Line 664 of lalr1.cc  */
#line 328 "parser.ypp"
    {
			(yyval.call_function) = new CallExprAST((yysemantic_stack_[(3) - (1)].varref));
			debug("functioncall %s with no arg\n", (yysemantic_stack_[(3) - (1)].varref)->ID->ID.c_str());
		}
    break;

  case 53:
/* Line 664 of lalr1.cc  */
#line 332 "parser.ypp"
    {
			 (yyval.call_function) = new CallExprAST((yysemantic_stack_[(4) - (1)].varref) , (yysemantic_stack_[(4) - (3)].expression_list) );
		}
    break;

  case 54:
/* Line 664 of lalr1.cc  */
#line 336 "parser.ypp"
    {
		debug("ref menber %s . %s , not supported yet\n" );
		exit(1); 
	}
    break;

  case 55:
/* Line 664 of lalr1.cc  */
#line 340 "parser.ypp"
    { exit(1); }
    break;

  case 56:
/* Line 664 of lalr1.cc  */
#line 341 "parser.ypp"
    {
		(yyval.varref) = new VariableExprAST(  new ReferenceAST( (yysemantic_stack_[(1) - (1)].id) ));
	}
    break;

  case 62:
/* Line 664 of lalr1.cc  */
#line 354 "parser.ypp"
    {

		debug("definning %s as array\n",(yysemantic_stack_[(4) - (2)].id)->c_str());

		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(4) - (2)].id)  , ArrayExprTypeAST::create(* (yysemantic_stack_[(4) - (4)].exprtype)) );
	}
    break;

  case 63:
/* Line 664 of lalr1.cc  */
#line 372 "parser.ypp"
    {
		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(4) - (2)].id)  , * (yysemantic_stack_[(4) - (4)].exprtype) );
	}
    break;

  case 64:
/* Line 664 of lalr1.cc  */
#line 375 "parser.ypp"
    {
		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(2) - (2)].id)  , NumberExprTypeAST::GetNumberExprTypeAST() );
	}
    break;

  case 65:
/* Line 664 of lalr1.cc  */
#line 392 "parser.ypp"
    {
					useDefautSubMain = false;
					
					(yyval.function_definition) = new FunctionDimAST(*(yysemantic_stack_[(10) - (2)].id),
											ExprTypeASTPtr(new CallableExprTypeAST(*(yysemantic_stack_[(10) - (7)].exprtype))),
											(yysemantic_stack_[(10) - (4)].arg_list));

					(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(10) - (9)].codeblocks));
				}
    break;

  case 66:
/* Line 664 of lalr1.cc  */
#line 403 "parser.ypp"
    {
					useDefautSubMain = false;
					(yyval.function_definition) = new FunctionDimAST(*(yysemantic_stack_[(8) - (2)].id),
											ExprTypeASTPtr(new CallableExprTypeAST(NumberExprTypeAST::GetNumberExprTypeAST())),
											(yysemantic_stack_[(8) - (4)].arg_list));

					(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(8) - (7)].codeblocks));
				}
    break;

  case 67:
/* Line 664 of lalr1.cc  */
#line 415 "parser.ypp"
    {
				useDefautSubMain = false;
				debug("!!SUB %s defined with arg !!\n",(yysemantic_stack_[(7) - (2)].id)->c_str());

				(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(7) - (2)].id),
										 ExprTypeASTPtr(new CallableExprTypeAST(VoidExprTypeAST::GetVoidExprTypeAST())),
										 (yysemantic_stack_[(7) - (4)].arg_list)); //delete $2;
				(yysemantic_stack_[(7) - (6)].codeblocks)->parent = (yysemantic_stack_[(7) - (4)].arg_list);
				(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(7) - (6)].codeblocks));
			}
    break;

  case 68:
/* Line 664 of lalr1.cc  */
#line 427 "parser.ypp"
    { (yyval.arg_list) = 0; }
    break;

  case 69:
/* Line 664 of lalr1.cc  */
#line 428 "parser.ypp"
    {
		(yyval.arg_list) = (yysemantic_stack_[(5) - (1)].arg_list);
		(yyval.arg_list)->addchild( new ArgumentDimAST( *(yysemantic_stack_[(5) - (3)].id)  , * (yysemantic_stack_[(5) - (5)].exprtype) ) );
	}
    break;

  case 70:
/* Line 664 of lalr1.cc  */
#line 432 "parser.ypp"
    {
		debug("definning %s is type %p as arg\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		(yyval.arg_list) = new ArgumentDimsAST ;
		(yyval.arg_list)->addchild(new ArgumentDimAST( *(yysemantic_stack_[(3) - (1)].id)  , * (yysemantic_stack_[(3) - (3)].exprtype) ));
	}
    break;

  case 71:
/* Line 664 of lalr1.cc  */
#line 447 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(4) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr(new CodeBlockAST((yysemantic_stack_[(4) - (4)].statement)));
	}
    break;

  case 72:
/* Line 664 of lalr1.cc  */
#line 453 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(6) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr((yysemantic_stack_[(6) - (5)].codeblocks));
		}
    break;

  case 73:
/* Line 664 of lalr1.cc  */
#line 461 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(8) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr((yysemantic_stack_[(8) - (5)].codeblocks));
			(yyval.if_clause)->_else = CodeBlockASTPtr((yysemantic_stack_[(8) - (7)].codeblocks));
		}
    break;

  case 74:
/* Line 664 of lalr1.cc  */
#line 474 "parser.ypp"
    {
			(yyval.while_loop) = new WhileLoopAST( ExprASTPtr((yysemantic_stack_[(5) - (2)].expression)) , (yysemantic_stack_[(5) - (4)].codeblocks));
		}
    break;

  case 75:
/* Line 664 of lalr1.cc  */
#line 483 "parser.ypp"
    {
				debug("got for loop");
				(yyval.for_loop) = new ForLoopAST((yysemantic_stack_[(10) - (2)].varref), (yysemantic_stack_[(10) - (4)].expression),(yysemantic_stack_[(10) - (6)].expression), 0 ,(yysemantic_stack_[(10) - (9)].codeblocks));
			}
    break;

  case 77:
/* Line 664 of lalr1.cc  */
#line 490 "parser.ypp"
    { debug("step");}
    break;


/* Line 664 of lalr1.cc  */
#line 994 "/home/cai/projects/basic/compiler/parser.cpp"
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
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char parser::yypact_ninf_ = -80;
  const short int
  parser::yypact_[] =
  {
       641,    38,   -80,   -26,    -1,    38,    38,     8,    41,    51,
      38,    38,    38,   -80,   -80,   -80,    38,   105,   154,   -80,
      39,    56,   -80,   203,   -80,    55,    46,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,    -8,    57,    58,    62,   327,   327,
     -80,    66,    38,    98,    99,    22,   219,    -7,   271,   -80,
     -80,   -80,     1,   -80,   -80,   -80,   673,   -80,   673,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    75,    79,
     -80,    38,   -80,   -10,    38,    81,    81,    78,   -44,   327,
      60,    60,   365,   -80,   -80,   641,    38,   -80,   -80,   -80,
     237,   -80,   342,   150,   354,   413,   178,    -8,    -8,     6,
       6,   -80,   -80,   327,   -80,   -28,   327,   109,    42,    44,
     -80,    38,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   641,
     449,   289,    38,   -80,    60,    90,   641,    30,   327,   417,
     -80,    38,   -80,   119,   481,   641,    60,   -80,   641,   304,
      60,   -80,   513,   122,   545,    38,   123,   -80,   -80,   641,
     -80,   327,   641,   577,   609,   -80,   -80
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,     0,     8,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,    56,    48,    49,     0,     0,     0,     5,
       0,     0,    12,     0,    15,    35,    47,    14,    13,    22,
      21,    18,    19,    20,    50,    47,     0,     0,    17,     0,
      16,     0,    30,     0,    64,     0,     0,    47,     0,     1,
       2,     4,     0,     6,    59,    58,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    23,     0,     0,    68,    68,     0,    27,    34,
       0,     0,     0,    60,    61,     0,     0,    36,     3,    10,
       0,    11,    44,    42,    41,    43,    45,    38,    37,    39,
      40,    55,    54,    46,    52,     0,    51,     0,     0,     0,
      31,    28,    29,    24,    25,    26,    62,    63,    71,     0,
       0,     0,     0,    53,     0,     0,     0,     0,    33,     0,
      74,     0,    70,     0,     0,     0,     0,    72,     0,    76,
       0,    67,     0,     0,     0,     0,     0,    69,    66,     0,
      73,    77,     0,     0,     0,    65,    75
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
       -80,   -80,    21,   -17,   130,     9,   -79,   -80,   -80,    77,
      10,   145,   -80,     0,    -4,    76,   -80,   -80,   -80,   -80,
      92,   -80,   -80,   -80,   -80
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    17,    18,    19,    20,    21,   116,    22,    42,    78,
      23,    24,    25,    35,    56,    85,    27,    28,    29,    30,
     108,    31,    32,    33,   146
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -58;
  const short int
  parser::yytable_[] =
  {
        26,    51,   117,     1,    88,    86,    26,    66,    67,   111,
     112,    34,    47,    68,    69,    38,    39,    58,    26,    72,
      45,    46,    39,    36,    53,   122,    48,    68,    69,   123,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    13,
      14,    15,    84,    68,    69,   132,    16,   104,    37,    73,
      71,     1,    79,   135,   136,    54,    26,   143,    26,    82,
      55,   147,    53,    41,    71,    89,    90,    91,    90,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    84,    57,
      71,   103,    26,    79,   106,    26,    72,    13,    14,    15,
      43,   118,    90,    54,    16,   125,   121,   125,    55,   126,
      44,   127,    73,    51,    74,    49,   120,   113,   114,   115,
      54,   -57,    51,    73,    75,    55,    77,    51,    76,    26,
      26,   128,    80,    81,   101,    51,    26,    51,   102,    26,
     107,   110,   128,   124,    26,    26,    51,    51,    26,   133,
     129,   139,    26,   140,    26,   149,   152,   134,    52,    26,
     105,    40,    26,    26,    26,   151,   142,    50,   119,   144,
      61,    62,    63,    64,    65,    66,    67,     1,   109,     0,
     153,    68,    69,   154,     0,     0,     0,     2,     0,     3,
       0,     4,     0,     5,     6,     7,     8,     9,     0,     0,
      10,    64,    65,    66,    67,    11,     0,    12,     0,    68,
      69,     0,     0,    13,    14,    15,     0,     0,    71,     0,
      16,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,     0,     0,     0,    68,    69,    70,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    71,     0,     0,     0,
      68,    69,    83,     0,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,     0,     0,    54,    68,    69,
       0,    71,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,    71,    55,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
       0,    54,    68,    69,     0,    71,    55,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,     0,     0,     0,
      68,    69,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,     0,     0,     0,    68,    69,     0,    87,    71,
       0,     0,     0,     0,   131,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,     0,     0,    71,    68,    69,
     145,    60,    61,    62,    63,    64,    65,    66,    67,     0,
       0,     0,    71,    68,    69,    62,    63,    64,    65,    66,
      67,     0,     0,     0,     0,    68,    69,     0,     1,     0,
       0,     0,     0,     0,     0,    71,     0,     0,    83,     0,
       3,     0,     4,     0,     5,     6,     7,     8,     9,     0,
      71,    10,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,    71,     0,    13,    14,    15,     0,     0,    54,
       0,    16,     0,     0,    55,    63,    64,    65,    66,    67,
       1,     0,     0,     0,    68,    69,     0,     0,     0,     0,
       2,     0,     3,     0,     4,     0,     5,     6,     7,     8,
       9,     0,     0,    10,     0,   137,   138,     0,    11,     0,
      12,     0,     1,     0,     0,     0,    13,    14,    15,     0,
       0,    71,     2,    16,     3,     0,     4,     0,     5,     6,
       7,     8,     9,     0,     0,    10,     0,     0,     0,     0,
      11,   130,    12,     0,     1,     0,     0,     0,    13,    14,
      15,     0,     0,     0,     2,    16,     3,   141,     4,     0,
       5,     6,     7,     8,     9,     0,     0,    10,     0,     0,
       0,     0,    11,     0,    12,     0,     1,     0,     0,     0,
      13,    14,    15,     0,     0,     0,     2,    16,     3,     0,
       4,   148,     5,     6,     7,     8,     9,     0,     0,    10,
       0,     0,     0,     0,    11,     0,    12,     0,     1,     0,
       0,     0,    13,    14,    15,     0,     0,     0,     2,    16,
       3,     0,     4,     0,     5,     6,     7,     8,     9,     0,
       0,    10,     0,   150,     0,     0,    11,     0,    12,     0,
       1,     0,     0,     0,    13,    14,    15,     0,     0,     0,
       2,    16,     3,     0,     4,   155,     5,     6,     7,     8,
       9,     0,     0,    10,     0,     0,     0,     0,    11,     0,
      12,     0,     1,     0,     0,     0,    13,    14,    15,     0,
       0,     0,     2,    16,     3,     0,     4,     0,     5,     6,
       7,     8,     9,     0,     0,    10,     0,     0,     0,     0,
      11,     0,    12,   156,     1,     0,     0,     0,    13,    14,
      15,     0,     0,     0,     2,    16,     3,     0,     4,     0,
       5,     6,     7,     8,     9,     0,     0,    10,     0,     0,
       0,     0,    11,     0,    12,     0,     1,     0,     0,     0,
      13,    14,    15,     0,     0,     0,     0,    16,     3,     0,
       4,     0,     5,     6,     7,     8,     9,     0,     0,    10,
       0,     0,     0,     0,    11,     0,    12,     0,     0,     0,
       0,     0,    13,    14,    15,     0,     0,     0,     0,    16
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,    18,    81,    13,     3,    12,     6,    15,    16,    53,
      54,     1,    12,    21,    22,     5,     6,    21,    18,    23,
      10,    11,    12,    49,    23,    53,    16,    21,    22,    57,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    49,
      50,    51,    46,    21,    22,   124,    56,    57,    49,    56,
      58,    13,    42,    23,    24,    54,    56,   136,    58,    37,
      59,   140,    23,    55,    58,    56,    56,    58,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    82,    23,
      58,    71,    82,    73,    74,    85,    90,    49,    50,    51,
      49,    82,    82,    54,    56,    53,    86,    53,    59,    57,
      49,    57,    56,   120,    58,     0,    85,    47,    48,    49,
      54,    56,   129,    56,    56,    59,    50,   134,    56,   119,
     120,   111,    24,    24,    49,   142,   126,   144,    49,   129,
      49,    53,   122,    24,   134,   135,   153,   154,   138,    49,
     119,   131,   142,    24,   144,    23,    23,   126,    18,   149,
      73,     6,   152,   153,   154,   145,   135,     3,    82,   138,
      10,    11,    12,    13,    14,    15,    16,    13,    76,    -1,
     149,    21,    22,   152,    -1,    -1,    -1,    23,    -1,    25,
      -1,    27,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      36,    13,    14,    15,    16,    41,    -1,    43,    -1,    21,
      22,    -1,    -1,    49,    50,    51,    -1,    -1,    58,    -1,
      56,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    21,    22,    23,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    58,    -1,    -1,    -1,
      21,    22,    23,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    54,    21,    22,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    59,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    54,    21,    22,    -1,    58,    59,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      21,    22,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    21,    22,    -1,    57,    58,
      -1,    -1,    -1,    -1,    45,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    58,    21,    22,
      46,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    58,    21,    22,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    21,    22,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    23,    -1,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    -1,
      58,    36,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      -1,    -1,    58,    -1,    49,    50,    51,    -1,    -1,    54,
      -1,    56,    -1,    -1,    59,    12,    13,    14,    15,    16,
      13,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    27,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    36,    -1,    38,    39,    -1,    41,    -1,
      43,    -1,    13,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    58,    23,    56,    25,    -1,    27,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      41,    42,    43,    -1,    13,    -1,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    23,    56,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    13,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    23,    56,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    13,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    23,    56,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    36,    -1,    38,    -1,    -1,    41,    -1,    43,    -1,
      13,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,    -1,
      23,    56,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    36,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    13,    -1,    -1,    -1,    49,    50,    51,    -1,
      -1,    -1,    23,    56,    25,    -1,    27,    -1,    29,    30,
      31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    43,    44,    13,    -1,    -1,    -1,    49,    50,
      51,    -1,    -1,    -1,    23,    56,    25,    -1,    27,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    13,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    56,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    56
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    13,    23,    25,    27,    29,    30,    31,    32,    33,
      36,    41,    43,    49,    50,    51,    56,    61,    62,    63,
      64,    65,    67,    70,    71,    72,    73,    76,    77,    78,
      79,    81,    82,    83,    70,    73,    49,    49,    70,    70,
      71,    55,    68,    49,    49,    70,    70,    73,    70,     0,
       3,    63,    64,    23,    54,    59,    74,    23,    74,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    21,    22,
      23,    58,    74,    56,    58,    56,    56,    50,    69,    70,
      24,    24,    37,    23,    74,    75,    12,    57,     3,    65,
      70,    65,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    49,    49,    70,    57,    69,    70,    49,    80,    80,
      53,    53,    54,    47,    48,    49,    66,    66,    65,    75,
      62,    70,    53,    57,    24,    53,    57,    57,    70,    62,
      42,    45,    66,    49,    62,    23,    24,    38,    39,    70,
      24,    26,    62,    66,    62,    46,    84,    66,    28,    23,
      38,    70,    23,    62,    62,    28,    44
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    45,    43,    42,    47,   268,   269,   270,
     271,   272,    46,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,    44,    59,    35,    40,    41,    61,    58
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    72,    72,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    77,    77,    78,    78,    79,    80,    80,
      80,    81,    81,    81,    82,    83,    84,    84
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     3,     2,     1,     2,     2,     1,     2,
       3,     3,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     3,     4,     4,
       2,     3,     0,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       2,     3,     3,     4,     3,     3,     1,     1,     1,     1,
       1,     1,     4,     4,     2,    10,     8,     7,     0,     5,
       3,     4,     6,     8,     5,    10,     0,     2
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "$end", "error", "$undefined", "tEOPROG", "tOR", "tAND", "tNOT", "tNEQ",
  "tGEQ", "tLEQ", "tLTN", "tGTN", "tEQU", "'-'", "'+'", "'*'", "'/'",
  "tMOD", "UPLUS", "UMINUS", "tPOW", "tDREF", "'.'", "tNEWLINE", "tAS",
  "tSUB", "tSUBEND", "tFUNCTION", "tFUNCTIONEND", "tRETURN", "tLET",
  "tPRINT", "tARRAYDIM", "tDIM", "tSTRUCTDIM", "tENDSTRUCDIM", "tIF",
  "tTHEN", "tENDIF", "tELSE", "tELSEIF", "tWHILE", "tENDWHILE", "tFOR",
  "tENDFOR", "tTO", "tSTEP", "tLONG", "tSTR", "tID", "tInteger", "tSTRING",
  "tNUMBER", "','", "';'", "'#'", "'('", "')'", "'='", "':'", "$accept",
  "program", "lines", "line", "statements", "statement", "exprtype",
  "printstatement", "printinto", "expression_list", "expression",
  "assigment", "call_function", "varref", "comma_or_colon", "seperator",
  "array_dim", "dim_item", "function_definition", "sub_definition",
  "arg_list", "if_clause", "while_loop", "for_loop", "optstep", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        61,     0,    -1,    62,     3,    -1,    62,    64,     3,    -1,
      62,    63,    -1,    63,    -1,    64,    23,    -1,    65,    23,
      -1,    23,    -1,    70,    23,    -1,    64,    74,    65,    -1,
      65,    74,    65,    -1,    67,    -1,    77,    -1,    76,    -1,
      71,    -1,    30,    71,    -1,    29,    70,    -1,    81,    -1,
      82,    -1,    83,    -1,    79,    -1,    78,    -1,    70,    74,
      -1,    47,    -1,    48,    -1,    49,    -1,    31,    68,    69,
      -1,    31,    68,    69,    53,    -1,    31,    68,    69,    54,
      -1,    31,    68,    -1,    55,    50,    53,    -1,    -1,    69,
      53,    70,    -1,    70,    -1,    72,    -1,    56,    70,    57,
      -1,    70,    14,    70,    -1,    70,    13,    70,    -1,    70,
      15,    70,    -1,    70,    16,    70,    -1,    70,    10,    70,
      -1,    70,     9,    70,    -1,    70,    11,    70,    -1,    70,
       8,    70,    -1,    70,    12,    70,    -1,    70,    58,    70,
      -1,    73,    -1,    50,    -1,    51,    -1,    13,    70,    -1,
      73,    58,    70,    -1,    73,    56,    57,    -1,    73,    56,
      69,    57,    -1,    70,    22,    49,    -1,    70,    21,    49,
      -1,    49,    -1,    72,    -1,    59,    -1,    54,    -1,    23,
      -1,    74,    -1,    32,    49,    24,    66,    -1,    33,    49,
      24,    66,    -1,    33,    49,    -1,    27,    49,    56,    80,
      57,    24,    66,    23,    62,    28,    -1,    27,    49,    56,
      80,    57,    23,    62,    28,    -1,    25,    49,    56,    80,
      57,    62,    26,    -1,    -1,    80,    53,    49,    24,    66,
      -1,    49,    24,    66,    -1,    36,    70,    37,    65,    -1,
      36,    70,    37,    75,    62,    38,    -1,    36,    70,    37,
      75,    62,    39,    62,    38,    -1,    41,    70,    75,    62,
      42,    -1,    43,    73,    12,    70,    45,    70,    84,    23,
      62,    44,    -1,    -1,    46,    70,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    13,    15,    18,    21,    23,
      26,    30,    34,    36,    38,    40,    42,    45,    48,    50,
      52,    54,    56,    58,    61,    63,    65,    67,    71,    76,
      81,    84,    88,    89,    93,    95,    97,   101,   105,   109,
     113,   117,   121,   125,   129,   133,   137,   141,   143,   145,
     147,   150,   154,   158,   163,   167,   171,   173,   175,   177,
     179,   181,   183,   188,   193,   196,   207,   216,   224,   225,
     231,   235,   240,   247,   256,   262,   273,   274
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   175,   175,   185,   199,   209,   216,   217,   221,   222,
     229,   230,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   249,   252,   255,   258,   265,   272,   275,
     278,   285,   286,   289,   290,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   309,   310,   313,
     316,   322,   328,   332,   336,   340,   341,   344,   347,   347,
     350,   351,   354,   372,   375,   390,   401,   413,   427,   428,
     432,   447,   451,   457,   472,   481,   489,   490
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
       2,     2,     2,     2,     2,    55,     2,     2,     2,     2,
      56,    57,    15,    14,    53,    13,    22,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    54,
       2,    58,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    17,    18,
      19,    20,    21,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 729;
  const int parser::yynnts_ = 25;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 49;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 60;

  const unsigned int parser::yyuser_token_number_max_ = 302;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1135 of lalr1.cc  */
#line 21 "parser.ypp"
} // qb
/* Line 1135 of lalr1.cc  */
#line 1673 "/home/cai/projects/basic/compiler/parser.cpp"
