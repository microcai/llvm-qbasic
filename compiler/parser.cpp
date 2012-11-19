/* A Bison parser, made by GNU Bison 2.6.5.  */

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
#line 23 "parser.ypp"


/* Include main header file. */
#include "qbc.h"
#include "parser.hpp"
#include <boost/make_shared.hpp>
#include <boost/concept_check.hpp>

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


/* Line 278 of lalr1.cc  */
#line 77 "/home/cai/projects/basic/compiler/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */

/* Line 284 of lalr1.cc  */
#line 85 "/home/cai/projects/basic/compiler/parser.cpp"


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
#line 21 "parser.ypp"
namespace qb {
/* Line 352 of lalr1.cc  */
#line 181 "/home/cai/projects/basic/compiler/parser.cpp"

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
#line 168 "parser.ypp"
    {
			if(useDefautSubMain){
				debug("program ended\n");
				program = new DefaultMainFunctionAST( (yysemantic_stack_[(2) - (1)].codeblocks) );
			}else{
				program = (yysemantic_stack_[(2) - (1)].codeblocks);
				debug("module ended\n");
			}
			YYACCEPT;
		}
    break;

  case 3:
/* Line 661 of lalr1.cc  */
#line 178 "parser.ypp"
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
/* Line 661 of lalr1.cc  */
#line 192 "parser.ypp"
    {
					(yyval.codeblocks) = (yysemantic_stack_[(2) - (1)].codeblocks);
					if(!(yysemantic_stack_[(2) - (1)].codeblocks)){
						(yysemantic_stack_[(2) - (1)].codeblocks) = (yyval.codeblocks) = new CodeBlockAST;
					}
					if((yysemantic_stack_[(2) - (2)].statement_list)){
						debug("addchine1 , %p %p %p\n",(yyval.codeblocks),(yysemantic_stack_[(2) - (1)].codeblocks),(yysemantic_stack_[(2) - (2)].statement_list));
						(yyval.codeblocks)->addchild((yysemantic_stack_[(2) - (2)].statement_list));
					}else{
						debug("addchine1 voided , %p %p %p\n",(yyval.codeblocks),(yysemantic_stack_[(2) - (1)].codeblocks),(yysemantic_stack_[(2) - (2)].statement_list));
					}
	}
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 204 "parser.ypp"
    {
		(yyval.codeblocks) = 0;debug("addchine2\n");
		if((yysemantic_stack_[(1) - (1)].statement_list)){
			debug("addchine2 real\n");
			(yyval.codeblocks) = new CodeBlockAST; 	(yyval.codeblocks)->addchild((yysemantic_stack_[(1) - (1)].statement_list)); 	}
	}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 211 "parser.ypp"
    { (yyval.statement_list)=(yysemantic_stack_[(2) - (1)].statement_list);  }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 212 "parser.ypp"
    {
		if(!(yysemantic_stack_[(2) - (1)].statement)){debug("statement nil\n");}
		(yyval.statement_list) = new StatementsAST ; (yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(2) - (1)].statement)));
	}
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 216 "parser.ypp"
    { debug("空行"); (yyval.statement_list) = 0;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 217 "parser.ypp"
    {
		CallStmtAST * callstmt =  new CallStmtAST( (yysemantic_stack_[(2) - (1)].call_function) );
		(yyval.statement_list) = new StatementsAST ;
		(yyval.statement_list)->push_back( StatementASTPtr(callstmt)  );
	}
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 224 "parser.ypp"
    {  (yyval.statement_list) = (yysemantic_stack_[(3) - (1)].statement_list); (yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (3)].statement))); }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 225 "parser.ypp"
    {
				(yyval.statement_list) = new StatementsAST ;
				(yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (1)].statement)));
				(yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (3)].statement)));
		}
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 232 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].printstatement); }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 233 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_item); }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 234 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].variable_assignment);}
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 235 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].variable_assignment);}
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 236 "parser.ypp"
    { (yyval.statement) = new ReturnAST((yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 237 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].if_clause);}
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 238 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].while_loop);}
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].for_loop);}
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 240 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 241 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 244 "parser.ypp"
    { /*TODO*/debug("here====3====\n"); exit(1);	}
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 248 "parser.ypp"
    {
		VariableExprAST * varref = new VariableExprAST((yysemantic_stack_[(3) - (1)].varref));
		(yyval.variable_assignment) = new AssigmentAST(varref, (yysemantic_stack_[(3) - (3)].expression));
	}
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 253 "parser.ypp"
    {
		(yyval.exprtype) = new std::string("long");
	}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 256 "parser.ypp"
    {
		(yyval.exprtype) = new std::string("string");
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 259 "parser.ypp"
    {
		debug("define as user type not supported\n");
		exit(1);
	}
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 265 "parser.ypp"
    {

		(yysemantic_stack_[(3) - (3)].expression_list)->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(3) - (2)].printinto), (yysemantic_stack_[(3) - (3)].expression_list) );
		
		debug("got print1 done\n");
	}
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 272 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 275 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 278 "parser.ypp"
    {
		ExprListAST * exprList = new ExprListAST;
		exprList->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(2) - (2)].printinto), exprList );
	}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 285 "parser.ypp"
    { debug("print has got itger\n") ;}
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 286 "parser.ypp"
    {  debug("empty printinto\n");	}
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    { (yyval.expression_list) = (yysemantic_stack_[(3) - (1)].expression_list) ; (yyval.expression_list)->Append((yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 290 "parser.ypp"
    {
		(yyval.expression_list) =  new ExprListAST;
		(yyval.expression_list)->Append((yysemantic_stack_[(1) - (1)].expression));
	}
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 298 "parser.ypp"
    { (yyval.call_function) = new CallExprAST((yysemantic_stack_[(3) - (1)].varref)); debug("functioncall %s with no arg\n", (yysemantic_stack_[(3) - (1)].varref)->ID.c_str()); }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 299 "parser.ypp"
    { 	 // 这个可能是函数调用, 也许是数组哦 :)
			 // 现在就当是函数调用了, 在后面的阶段再生成数组访问
			 debug("functioncall %s with  args!!!!\n" , (yysemantic_stack_[(4) - (1)].varref)->ID.c_str() );

			 (yyval.call_function) = new CallExprAST((yysemantic_stack_[(4) - (1)].varref) , (yysemantic_stack_[(4) - (3)].expression_list) );			
		}
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 310 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_ADD , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 311 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_SUB , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 312 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_MUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 313 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_DIV , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 314 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESS , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 315 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESSEQU , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 316 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATER , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 317 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATEREQUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 319 "parser.ypp"
    {
			//TODO the VariableRefExprAST
			(yyval.expression) = new VariableExprAST( (yysemantic_stack_[(1) - (1)].varref) );
			debug("do we got this?\n");			
		}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    {
			//常量
			(yyval.expression) = new ConstNumberExprAST( (yysemantic_stack_[(1) - (1)].integer) );
		}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    { //字符串
			(yyval.expression) = new ConstStringExprAST((yysemantic_stack_[(1) - (1)].string));
		}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 334 "parser.ypp"
    {
		debug("ref menber %s . %s , not supported yet\n", (yysemantic_stack_[(3) - (1)].varref)->ID.c_str()  , (yysemantic_stack_[(3) - (3)].id)->c_str() );
		exit(1); // 逐级传递
	}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 339 "parser.ypp"
    {
		// 变量的引用? 反正是一个标识符的引用,
		// 所以我构建一个标识符引用语句. 这个会被用来构建函数调用和数组语句以及变量.
		(yyval.varref) = new ReferenceAST( (yysemantic_stack_[(1) - (1)].id) );
		debug("idref %s\n", (yysemantic_stack_[(1) - (1)].id)->c_str());
	}
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {
					useDefautSubMain = false;
					(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(10) - (2)].id) , (yysemantic_stack_[(10) - (4)].arg_list), *(yysemantic_stack_[(10) - (7)].exprtype) );

					(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(10) - (9)].codeblocks));
				}
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {
					useDefautSubMain = false;
					(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(8) - (2)].id) , (yysemantic_stack_[(8) - (4)].arg_list) , "long" ) ;

					(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(8) - (7)].codeblocks));
				}
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 375 "parser.ypp"
    {
				useDefautSubMain = false;
				debug("!!SUB %s defined with arg !!\n",(yysemantic_stack_[(7) - (2)].id)->c_str());

				(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(7) - (2)].id),(yysemantic_stack_[(7) - (4)].arg_list)); //delete $2;				
				(yysemantic_stack_[(7) - (6)].codeblocks)->parent = (yysemantic_stack_[(7) - (4)].arg_list);
				(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(7) - (6)].codeblocks));
			}
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    { (yyval.arg_list) = 0; }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {
		(yyval.arg_list) = (yysemantic_stack_[(5) - (1)].arg_list);
		(yyval.arg_list)->addchild( new ArgumentDimAST( *(yysemantic_stack_[(5) - (3)].id)  , * (yysemantic_stack_[(5) - (5)].exprtype) ) );

		debug("definning %s is type %p as arg\n",(yysemantic_stack_[(5) - (3)].id)->c_str(), (yysemantic_stack_[(5) - (5)].exprtype));

		debug("define multiple line is not supported yet\n");
		//exit(1);
	}
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {
		debug("definning %s is type %p as arg\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		
		(yyval.arg_list) = new ArgumentDimsAST ;
		(yyval.arg_list)->addchild(new ArgumentDimAST( *(yysemantic_stack_[(3) - (1)].id)  , * (yysemantic_stack_[(3) - (3)].exprtype) ));
	}
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {
		debug("definning %s is type %p\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(3) - (1)].id)  , * (yysemantic_stack_[(3) - (3)].exprtype) );
	}
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {
		debug("definning %s with no type , default to long\n",(yysemantic_stack_[(1) - (1)].id)->c_str());
		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(1) - (1)].id)  , "long" );
	}
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 419 "parser.ypp"
    {
			// 单行 if then 语句
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(4) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr(new CodeBlockAST((yysemantic_stack_[(4) - (4)].statement)));
	}
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(6) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr((yysemantic_stack_[(6) - (5)].codeblocks));
		}
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(8) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr((yysemantic_stack_[(8) - (5)].codeblocks));
			(yyval.if_clause)->_else = CodeBlockASTPtr((yysemantic_stack_[(8) - (7)].codeblocks));
		}
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 447 "parser.ypp"
    {
			(yyval.while_loop) = new WhileLoopAST( ExprASTPtr((yysemantic_stack_[(5) - (2)].expression)) , (yysemantic_stack_[(5) - (4)].codeblocks));
		}
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 456 "parser.ypp"
    {
				debug("got for loop");
				(yyval.for_loop) = new ForLoopAST(new VariableExprAST((yysemantic_stack_[(10) - (2)].varref)), (yysemantic_stack_[(10) - (4)].expression),(yysemantic_stack_[(10) - (6)].expression), 0 ,(yysemantic_stack_[(10) - (9)].codeblocks));
			}
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 463 "parser.ypp"
    { debug("step");}
    break;


/* Line 661 of lalr1.cc  */
#line 964 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const signed char parser::yypact_ninf_ = -78;
  const short int
  parser::yypact_[] =
  {
       447,   -78,   -38,   -32,    65,   -19,    -6,   -10,    65,    65,
      -6,   -78,   -78,   -78,   -78,    65,    49,    55,   -78,   -14,
      -8,   -78,   -78,    37,    20,    -9,   -78,   -78,   -78,   -78,
     -78,    17,    24,   -78,   514,    -3,    57,   -78,   -78,    42,
      36,    65,   505,   180,    47,   158,   -78,   -78,   -78,     1,
     -78,   -78,   -78,   459,   -78,   459,   -78,    65,    65,    65,
      65,    65,    65,    65,    65,   -78,    65,    43,    61,   217,
      69,    69,    28,    67,    16,   514,   229,   -78,   -78,   447,
      65,   -78,   -78,   -78,   -78,   522,   530,    83,   186,    76,
      76,   -78,   -78,   514,   -78,   -78,   -78,   -49,    96,   -43,
     -34,   -78,   -78,   -78,   -78,   -78,    65,   -78,   -78,   447,
     283,   232,    65,   -78,    28,    75,   447,    82,   514,   256,
     -78,    65,   -78,    99,   312,   447,    28,   -78,   447,   212,
      28,   -78,   339,   106,   366,    65,   112,   -78,   -78,   447,
     -78,   514,   447,   393,   420,   -78,   -78
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,     8,     0,     0,     0,     0,     0,    32,     0,     0,
       0,    53,    48,    50,    49,     0,     0,     0,     5,     0,
       0,    14,    12,    37,     0,    47,    21,    20,    17,    18,
      19,     0,     0,    37,    16,    47,    65,    13,    15,     0,
       0,    30,     0,     0,     0,     0,     1,     2,     4,     0,
       6,    55,    54,     0,     7,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
      61,    61,     0,     0,    27,    34,     0,    56,    57,     0,
       0,    38,     3,    10,    11,    46,    44,    43,    45,    40,
      39,    41,    42,    23,    52,    51,    35,     0,     0,     0,
       0,    24,    25,    26,    64,    31,    28,    29,    66,     0,
       0,     0,     0,    36,     0,     0,     0,     0,    33,     0,
      69,     0,    63,     0,     0,     0,     0,    67,     0,    71,
       0,    60,     0,     0,     0,     0,     0,    62,    59,     0,
      68,    72,     0,     0,     0,    58,    70
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
       -78,   -78,   -77,    73,   119,   -30,   132,   -69,   -78,   -78,
      72,    21,   118,     0,     2,    71,   -78,   -78,    77,   -78,
     -78,   -78,   -78,   -78
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    16,    17,    18,    19,    20,    21,   104,    22,    41,
      74,    33,    24,    35,    53,    79,    26,    27,    99,    37,
      28,    29,    30,   136
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -1;
  const unsigned char
  parser::yytable_[] =
  {
        25,   112,   110,    66,    82,   113,    39,   115,    31,    50,
      44,   116,    67,    68,    32,    54,   115,    25,    67,    68,
     117,    23,    55,    83,    50,    84,    65,    36,    57,    58,
      59,    60,   119,    61,    62,    63,    64,    51,    23,   124,
      11,    52,    40,    51,    69,   122,   108,    52,   132,    46,
      69,   134,    51,    25,    66,    25,    52,   133,    47,    80,
      56,   137,   143,    67,    68,   144,   106,   107,    67,    68,
      70,    51,   101,   102,   103,    52,    25,    71,     1,    25,
       2,    72,     3,    73,     4,     5,     6,     7,     8,    94,
      48,    63,    64,     9,    60,    10,    61,    62,    63,    64,
      23,    11,    12,    13,    14,   125,   126,    95,    15,    25,
      25,    11,    12,    13,    14,    98,    25,   105,    15,    25,
     114,   123,    34,   130,    25,    25,    42,    43,    25,   139,
      23,    23,    25,    45,    25,   142,    49,    23,    38,    25,
      23,    97,    25,    25,    25,    23,    23,   109,   100,    23,
       0,     0,     0,    23,     0,    23,     0,     0,     0,    75,
      23,     0,     0,    23,    23,    23,    57,    58,    59,    60,
       0,    61,    62,    63,    64,    85,    86,    87,    88,    89,
      90,    91,    92,    48,    93,     0,     0,    75,    57,    58,
      59,    60,    48,    61,    62,    63,    64,    48,   111,    61,
      62,    63,    64,    77,     0,    48,     0,    48,     0,     0,
       0,     0,    81,     0,     0,     0,    48,    48,     0,     0,
      57,    58,    59,    60,   118,    61,    62,    63,    64,     0,
     118,     0,     0,     0,     0,    78,     0,     0,     0,   129,
      57,    58,    59,    60,     0,    61,    62,    63,    64,     0,
       0,     0,    77,   141,     2,   135,     3,     0,     4,     5,
       6,     7,     8,    11,    12,    13,    14,     9,     0,    10,
      15,    96,     0,     0,   121,    11,    12,    13,    14,     1,
       0,     2,    15,     3,    78,     4,     5,     6,     7,     8,
       0,   127,   128,     0,     9,     0,    10,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     1,     0,     2,    15,
       3,     0,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,   120,    10,     0,     0,     0,     0,     0,    11,
      12,    13,    14,     0,     0,     1,    15,     2,   131,     3,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,    11,    12,
      13,    14,     1,     0,     2,    15,     3,   138,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     9,     0,    10,
       0,     0,     0,     0,     0,    11,    12,    13,    14,     1,
       0,     2,    15,     3,     0,     4,     5,     6,     7,     8,
       0,   140,     0,     0,     9,     0,    10,     0,     0,     0,
       0,     0,    11,    12,    13,    14,     1,     0,     2,    15,
       3,   145,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,    10,     0,     0,     0,     0,     0,    11,
      12,    13,    14,     1,     0,     2,    15,     3,     0,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
      10,   146,     0,     0,     0,     0,    11,    12,    13,    14,
       1,     0,     2,    15,     3,     0,     4,     5,     6,     7,
       8,     0,     0,     0,     2,     9,     3,    10,     4,     5,
       6,     7,     8,    11,    12,    13,    14,     9,     0,    10,
      15,     0,     0,     0,     0,    11,    12,    13,    14,     0,
       0,     0,    15,    57,    58,    59,    60,     0,    61,    62,
      63,    64,    57,    58,    59,    60,     0,    61,    62,    63,
      64,    58,    59,    60,     0,    61,    62,    63,    64,    76,
      59,    60,     0,    61,    62,    63,    64
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,    50,    79,    12,     3,    54,     6,    50,    46,    23,
      10,    54,    21,    22,    46,    23,    50,    17,    21,    22,
      54,     0,    20,    53,    23,    55,    24,    46,     8,     9,
      10,    11,   109,    13,    14,    15,    16,    51,    17,   116,
      46,    55,    52,    51,    53,   114,    76,    55,   125,     0,
      53,   128,    51,    53,    12,    55,    55,   126,     3,    12,
      23,   130,   139,    21,    22,   142,    50,    51,    21,    22,
      53,    51,    44,    45,    46,    55,    76,    53,    23,    79,
      25,    24,    27,    47,    29,    30,    31,    32,    33,    46,
      17,    15,    16,    38,    11,    40,    13,    14,    15,    16,
      79,    46,    47,    48,    49,    23,    24,    46,    53,   109,
     110,    46,    47,    48,    49,    46,   116,    50,    53,   119,
      24,    46,     4,    24,   124,   125,     8,     9,   128,    23,
     109,   110,   132,    15,   134,    23,    17,   116,     6,   139,
     119,    69,   142,   143,   144,   124,   125,    76,    71,   128,
      -1,    -1,    -1,   132,    -1,   134,    -1,    -1,    -1,    41,
     139,    -1,    -1,   142,   143,   144,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    57,    58,    59,    60,    61,
      62,    63,    64,   110,    66,    -1,    -1,    69,     8,     9,
      10,    11,   119,    13,    14,    15,    16,   124,    80,    13,
      14,    15,    16,    23,    -1,   132,    -1,   134,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,   143,   144,    -1,    -1,
       8,     9,    10,    11,   106,    13,    14,    15,    16,    -1,
     112,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,   121,
       8,     9,    10,    11,    -1,    13,    14,    15,    16,    -1,
      -1,    -1,    23,   135,    25,    43,    27,    -1,    29,    30,
      31,    32,    33,    46,    47,    48,    49,    38,    -1,    40,
      53,    54,    -1,    -1,    42,    46,    47,    48,    49,    23,
      -1,    25,    53,    27,    55,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    23,    -1,    25,    53,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    -1,    -1,    23,    53,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    23,    -1,    25,    53,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    23,
      -1,    25,    53,    27,    -1,    29,    30,    31,    32,    33,
      -1,    35,    -1,    -1,    38,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    23,    -1,    25,    53,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    23,    -1,    25,    53,    27,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      40,    41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      23,    -1,    25,    53,    27,    -1,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    25,    38,    27,    40,    29,    30,
      31,    32,    33,    46,    47,    48,    49,    38,    -1,    40,
      53,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,     9,    10,    11,    -1,    13,    14,    15,    16,    34,
      10,    11,    -1,    13,    14,    15,    16
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    23,    25,    27,    29,    30,    31,    32,    33,    38,
      40,    46,    47,    48,    49,    53,    57,    58,    59,    60,
      61,    62,    64,    67,    68,    69,    72,    73,    76,    77,
      78,    46,    46,    67,    68,    69,    46,    75,    62,    69,
      52,    65,    68,    68,    69,    68,     0,     3,    59,    60,
      23,    51,    55,    70,    23,    70,    23,     8,     9,    10,
      11,    13,    14,    15,    16,    70,    12,    21,    22,    53,
      53,    53,    24,    47,    66,    68,    34,    23,    55,    71,
      12,    54,     3,    61,    61,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    46,    46,    54,    66,    46,    74,
      74,    44,    45,    46,    63,    50,    50,    51,    61,    71,
      58,    68,    50,    54,    24,    50,    54,    54,    68,    58,
      39,    42,    63,    46,    58,    23,    24,    35,    36,    68,
      24,    26,    58,    63,    58,    43,    79,    63,    28,    23,
      35,    68,    23,    58,    58,    28,    41
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
      44,    59,    35,    40,    41,    58
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    74,    74,    74,    75,    75,    76,    76,    76,    77,
      78,    79,    79
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     3,     2,     1,     2,     2,     1,     2,
       3,     3,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     2,     3,     1,     1,     1,     3,     4,     4,
       2,     3,     0,     3,     1,     3,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     1,    10,     8,
       7,     0,     5,     3,     3,     1,     4,     6,     8,     5,
      10,     0,     2
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
  "tSUB", "tSUBEND", "tFUNCTION", "tFUNCTIONEND", "tRETURN", "tDIM",
  "tLET", "tPRINT", "tIF", "tTHEN", "tENDIF", "tELSE", "tELSEIF", "tWHILE",
  "tENDWHILE", "tFOR", "tENDFOR", "tTO", "tSTEP", "tLONG", "tSTR", "tID",
  "tInteger", "tSTRING", "tNUMBER", "','", "';'", "'#'", "'('", "')'",
  "':'", "$accept", "program", "lines", "line", "statements", "statement",
  "assigment", "exprtype", "printstatement", "printinto",
  "expression_list", "call_function_or_array", "expression", "varref",
  "comma_or_colon", "seperator", "function_definition", "sub_definition",
  "arg_list", "dim_item", "if_clause", "while_loop", "for_loop", "optstep", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        57,     0,    -1,    58,     3,    -1,    58,    60,     3,    -1,
      58,    59,    -1,    59,    -1,    60,    23,    -1,    61,    23,
      -1,    23,    -1,    67,    23,    -1,    60,    70,    61,    -1,
      61,    70,    61,    -1,    64,    -1,    30,    75,    -1,    62,
      -1,    31,    62,    -1,    29,    68,    -1,    76,    -1,    77,
      -1,    78,    -1,    73,    -1,    72,    -1,    68,    70,    -1,
      69,    12,    68,    -1,    44,    -1,    45,    -1,    46,    -1,
      32,    65,    66,    -1,    32,    65,    66,    50,    -1,    32,
      65,    66,    51,    -1,    32,    65,    -1,    52,    47,    50,
      -1,    -1,    66,    50,    68,    -1,    68,    -1,    69,    53,
      54,    -1,    69,    53,    66,    54,    -1,    67,    -1,    53,
      68,    54,    -1,    68,    14,    68,    -1,    68,    13,    68,
      -1,    68,    15,    68,    -1,    68,    16,    68,    -1,    68,
      10,    68,    -1,    68,     9,    68,    -1,    68,    11,    68,
      -1,    68,     8,    68,    -1,    69,    -1,    47,    -1,    49,
      -1,    48,    -1,    69,    22,    46,    -1,    69,    21,    46,
      -1,    46,    -1,    55,    -1,    51,    -1,    23,    -1,    55,
      -1,    27,    46,    53,    74,    54,    24,    63,    23,    58,
      28,    -1,    27,    46,    53,    74,    54,    23,    58,    28,
      -1,    25,    46,    53,    74,    54,    58,    26,    -1,    -1,
      74,    50,    46,    24,    63,    -1,    46,    24,    63,    -1,
      46,    24,    63,    -1,    46,    -1,    33,    68,    34,    61,
      -1,    33,    68,    34,    71,    58,    35,    -1,    33,    68,
      34,    71,    58,    36,    58,    35,    -1,    38,    68,    71,
      58,    39,    -1,    40,    69,    12,    68,    42,    68,    79,
      23,    58,    41,    -1,    -1,    43,    68,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    13,    15,    18,    21,    23,
      26,    30,    34,    36,    39,    41,    44,    47,    49,    51,
      53,    55,    57,    60,    64,    66,    68,    70,    74,    79,
      84,    87,    91,    92,    96,    98,   102,   107,   109,   113,
     117,   121,   125,   129,   133,   137,   141,   145,   147,   149,
     151,   153,   157,   161,   163,   165,   167,   169,   171,   182,
     191,   199,   200,   206,   210,   214,   216,   221,   228,   237,
     243,   254,   255
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   168,   168,   178,   192,   204,   211,   212,   216,   217,
     224,   225,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   244,   248,   253,   256,   259,   265,   272,   275,
     278,   285,   286,   289,   290,   298,   299,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   319,   324,   328,
     329,   334,   338,   339,   347,   347,   349,   349,   355,   363,
     373,   385,   386,   395,   403,   406,   419,   424,   430,   445,
     454,   462,   463
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
       2,     2,     2,     2,     2,    52,     2,     2,     2,     2,
      53,    54,    15,    14,    50,    13,    22,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    51,
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
       5,     6,     7,     8,     9,    10,    11,    12,    17,    18,
      19,    20,    21,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 546;
  const int parser::yynnts_ = 24;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 46;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 56;

  const unsigned int parser::yyuser_token_number_max_ = 299;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 21 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 1574 "/home/cai/projects/basic/compiler/parser.cpp"
