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


/* Line 278 of lalr1.cc  */
#line 76 "/home/cai/projects/basic/compiler/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */

/* Line 284 of lalr1.cc  */
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
#line 170 "parser.ypp"
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
#line 180 "parser.ypp"
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
#line 194 "parser.ypp"
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
#line 206 "parser.ypp"
    {
		(yyval.codeblocks) = 0;debug("addchine2\n");
		if((yysemantic_stack_[(1) - (1)].statement_list)){
			debug("addchine2 real\n");
			(yyval.codeblocks) = new CodeBlockAST; 	(yyval.codeblocks)->addchild((yysemantic_stack_[(1) - (1)].statement_list)); 	}
	}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 213 "parser.ypp"
    { (yyval.statement_list)=(yysemantic_stack_[(2) - (1)].statement_list);  }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 214 "parser.ypp"
    {
		if(!(yysemantic_stack_[(2) - (1)].statement)){debug("statement nil\n");}
		(yyval.statement_list) = new StatementsAST ; (yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(2) - (1)].statement)));
	}
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 218 "parser.ypp"
    { debug("空行"); (yyval.statement_list) = 0;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 219 "parser.ypp"
    {
			ExprStmtAST * callstmt =  new ExprStmtAST( (yysemantic_stack_[(2) - (1)].expression) );
			(yyval.statement_list) = new StatementsAST ;
			(yyval.statement_list)->push_back( StatementASTPtr(callstmt)  );
	}
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 226 "parser.ypp"
    {  (yyval.statement_list) = (yysemantic_stack_[(3) - (1)].statement_list); (yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (3)].statement))); }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 227 "parser.ypp"
    {
				(yyval.statement_list) = new StatementsAST ;
				(yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (1)].statement)));
				(yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (3)].statement)));
		}
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 234 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].printstatement); }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 235 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].dim_item); }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 236 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].dim_item); }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 237 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].variable_assignment);}
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 238 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].variable_assignment);}
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    { (yyval.statement) = new ReturnAST((yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 240 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].if_clause);}
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 241 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].while_loop);}
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 242 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].for_loop);}
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 243 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 244 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 246 "parser.ypp"
    { /*TODO*/debug("here====3====\n"); exit(1);	}
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 250 "parser.ypp"
    {
		//VariableExprAST * varref = new VariableExprAST($1);
		(yyval.variable_assignment) = new AssigmentAST((yysemantic_stack_[(3) - (1)].varref), (yysemantic_stack_[(3) - (3)].expression));
	}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 255 "parser.ypp"
    {
		(yyval.exprtype) = new ExprType (NumberExprTypeAST::GetNumberExprTypeAST());
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 258 "parser.ypp"
    {
		(yyval.exprtype) = new ExprType (StringExprTypeAST::GetStringExprTypeAST());
	}
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 261 "parser.ypp"
    {
		debug("define as user type not supported\n");
		exit(1);
	}
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 265 "parser.ypp"
    {
		// 数组啊!!
	}
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 271 "parser.ypp"
    {

		(yysemantic_stack_[(3) - (3)].expression_list)->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(3) - (2)].printinto), (yysemantic_stack_[(3) - (3)].expression_list) );
		
		debug("got print1 done\n");
	}
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 278 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 281 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 284 "parser.ypp"
    {
		ExprListAST * exprList = new ExprListAST;
		exprList->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(2) - (2)].printinto), exprList );
	}
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 291 "parser.ypp"
    { debug("print has got itger\n") ;}
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    {  debug("empty printinto\n");	}
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 295 "parser.ypp"
    { (yyval.expression_list) = (yysemantic_stack_[(3) - (1)].expression_list) ; (yyval.expression_list)->Append((yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 296 "parser.ypp"
    {
		(yyval.expression_list) =  new ExprListAST;
		(yyval.expression_list)->Append((yysemantic_stack_[(1) - (1)].expression));
	}
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 304 "parser.ypp"
    {
			(yyval.call_function) = new CallExprAST((yysemantic_stack_[(3) - (1)].varref));
			debug("functioncall %s with no arg\n", (yysemantic_stack_[(3) - (1)].varref)->ID->ID.c_str());
		}
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 308 "parser.ypp"
    { 	 // 这个可能是函数调用, 也许是数组哦 :)
			 // 现在就当是函数调用了, 在后面的阶段再生成数组访问
			 debug("functioncall %s with  args!!!!\n" , (yysemantic_stack_[(4) - (1)].varref)->ID->ID.c_str() );

			 (yyval.call_function) = new CallExprAST((yysemantic_stack_[(4) - (1)].varref) , (yysemantic_stack_[(4) - (3)].expression_list) );			
		}
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 318 "parser.ypp"
    { (yyval.expression) = (yysemantic_stack_[(3) - (2)].expression) ;}
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 319 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_ADD , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 320 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_SUB , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 321 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_MUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 322 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_DIV , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 323 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESS , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESSEQU , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 325 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATER , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 326 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATEREQUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    {
			//常量
			(yyval.expression) = new ConstNumberExprAST( (yysemantic_stack_[(1) - (1)].integer) );
		}
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 334 "parser.ypp"
    { //字符串
			(yyval.expression) = new ConstStringExprAST((yysemantic_stack_[(1) - (1)].string));
		}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 339 "parser.ypp"
    { //没错, 成员引用, 前面可是可以为表达式的 !
		debug("ref menber %s . %s , not supported yet\n" );
		exit(1); // 逐级传递
	}
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 343 "parser.ypp"
    { exit(1); }
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 344 "parser.ypp"
    {
		// 变量的引用? 反正是一个标识符的引用,
		// 所以我构建一个标识符引用语句. 这个会被用来构建函数调用和数组语句以及变量.
		(yyval.varref) = new VariableExprAST(  new ReferenceAST( (yysemantic_stack_[(1) - (1)].id) ));
	}
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {
					useDefautSubMain = false;
					
					(yyval.function_definition) = new FunctionDimAST(*(yysemantic_stack_[(10) - (2)].id),
											ExprTypeASTPtr(new CallableExprTypeAST(*(yysemantic_stack_[(10) - (7)].exprtype))),
											(yysemantic_stack_[(10) - (4)].arg_list));

					(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(10) - (9)].codeblocks));
				}
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 376 "parser.ypp"
    {
					useDefautSubMain = false;
					(yyval.function_definition) = new FunctionDimAST(*(yysemantic_stack_[(8) - (2)].id),
											ExprTypeASTPtr(new CallableExprTypeAST(NumberExprTypeAST::GetNumberExprTypeAST())),
											(yysemantic_stack_[(8) - (4)].arg_list));

					(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(8) - (7)].codeblocks));
				}
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
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

  case 64:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    { (yyval.arg_list) = 0; }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {
		(yyval.arg_list) = (yysemantic_stack_[(5) - (1)].arg_list);
		(yyval.arg_list)->addchild( new ArgumentDimAST( *(yysemantic_stack_[(5) - (3)].id)  , * (yysemantic_stack_[(5) - (5)].exprtype) ) );
	}
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {
		debug("definning %s is type %p as arg\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		
		(yyval.arg_list) = new ArgumentDimsAST ;
		(yyval.arg_list)->addchild(new ArgumentDimAST( *(yysemantic_stack_[(3) - (1)].id)  , * (yysemantic_stack_[(3) - (3)].exprtype) ));
	}
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    {

		debug("definning %s as array\n",(yysemantic_stack_[(4) - (2)].id)->c_str());

		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(4) - (2)].id)  , ArrayExprTypeAST::create(* (yysemantic_stack_[(4) - (4)].exprtype)) );
	}
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 420 "parser.ypp"
    {
		debug("definning %s is type %p\n",(yysemantic_stack_[(4) - (2)].id)->c_str(), (yysemantic_stack_[(4) - (4)].exprtype));
		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(4) - (2)].id)  , * (yysemantic_stack_[(4) - (4)].exprtype) );
	}
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {
		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(2) - (2)].id)  , NumberExprTypeAST::GetNumberExprTypeAST() );
	}
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 429 "parser.ypp"
    {
		
	}
    break;

  case 71:
/* Line 661 of lalr1.cc  */
#line 441 "parser.ypp"
    {
			// 单行 if then 语句
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(4) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr(new CodeBlockAST((yysemantic_stack_[(4) - (4)].statement)));
	}
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 448 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(6) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr((yysemantic_stack_[(6) - (5)].codeblocks));
		}
    break;

  case 73:
/* Line 661 of lalr1.cc  */
#line 456 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(8) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr((yysemantic_stack_[(8) - (5)].codeblocks));
			(yyval.if_clause)->_else = CodeBlockASTPtr((yysemantic_stack_[(8) - (7)].codeblocks));
		}
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 469 "parser.ypp"
    {
			(yyval.while_loop) = new WhileLoopAST( ExprASTPtr((yysemantic_stack_[(5) - (2)].expression)) , (yysemantic_stack_[(5) - (4)].codeblocks));
		}
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 478 "parser.ypp"
    {
				debug("got for loop");
				(yyval.for_loop) = new ForLoopAST((yysemantic_stack_[(10) - (2)].varref), (yysemantic_stack_[(10) - (4)].expression),(yysemantic_stack_[(10) - (6)].expression), 0 ,(yysemantic_stack_[(10) - (9)].codeblocks));
			}
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 485 "parser.ypp"
    { debug("step");}
    break;


/* Line 661 of lalr1.cc  */
#line 1001 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const signed char parser::yypact_ninf_ = -44;
  const short int
  parser::yypact_[] =
  {
       511,   -44,   -37,   -33,    97,    97,   -34,     0,     2,     5,
      97,    97,    97,   -44,   -44,   -44,   -44,    97,    14,   128,
     -44,    -6,     8,   -44,   -44,    -9,   174,    -8,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -21,   -10,   601,    20,   -44,
     601,   -14,    97,    51,    57,   -24,   557,   190,    -7,   225,
     -44,   -44,   -44,    16,   -44,   -44,   -44,   555,   -44,   555,
      97,    97,    97,    97,    97,    97,    97,    97,    45,    52,
     -44,   -44,    97,   602,    58,    58,    53,   -30,   601,   -19,
     -19,    75,   262,   -44,   -44,   511,    97,   -44,   -44,   -44,
     206,   -44,   615,   628,   152,   229,    55,    55,    -1,    -1,
     -44,   -44,   601,   -44,   -13,    87,    37,    43,   -44,    97,
     -44,   -44,   -44,   -44,    60,    60,   -44,   -44,   511,   325,
     259,   -44,    97,   -19,   511,    65,    80,   601,    63,   294,
     -44,    97,    60,   356,    95,   511,   -19,    66,   -44,   511,
     244,   -44,   -19,   387,    -5,   -44,   418,    97,    99,    60,
     -44,   511,   -44,   601,   511,   449,   480,   -44,   -44
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,     8,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,    55,    50,    52,    51,     0,     0,     0,
       5,     0,     0,    15,    12,    39,     0,    49,    22,    21,
      14,    13,    18,    19,    20,     0,     0,    17,    49,    16,
       0,     0,    32,     0,    69,     0,     0,     0,    49,     0,
       1,     2,     4,     0,     6,    58,    57,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    23,     0,     0,    64,    64,     0,    29,    36,     0,
       0,     0,     0,    59,    60,     0,     0,    40,     3,    10,
       0,    11,    48,    46,    45,    47,    42,    41,    43,    44,
      54,    53,    24,    37,     0,     0,     0,     0,    33,    30,
      31,    25,    26,    27,    67,    68,    70,    71,     0,     0,
       0,    38,     0,     0,     0,     0,     0,    35,     0,     0,
      74,     0,    66,     0,     0,     0,     0,     0,    72,     0,
      76,    63,     0,     0,     0,    28,     0,     0,     0,    65,
      62,     0,    73,    77,     0,     0,     0,    61,    75
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  parser::yypgoto_[] =
  {
       -44,   -44,   -18,   -17,   104,   -35,   119,   -43,   -44,   -44,
      61,   -44,    -4,    23,   -11,    46,   -44,   -44,    50,   -44,
      85,   -44,   -44,   -44,   -44
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    18,    19,    20,    21,    22,    23,   114,    24,    42,
      77,    25,    26,    27,    57,    85,    28,    29,   106,    30,
      31,    32,    33,    34,   148
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -57;
  const short int
  parser::yytable_[] =
  {
        37,    40,    52,   -56,    72,    86,    46,    47,    40,     8,
       9,    59,    35,    49,    50,    71,    36,    54,   151,    88,
      68,    69,    89,    41,    91,   109,   110,    38,   111,   112,
     113,    58,    74,    38,    38,    48,    76,   115,    78,    54,
      38,   121,   122,    75,   -56,    73,    73,   117,   128,    43,
      55,    44,    56,    90,    45,    90,    92,    93,    94,    95,
      96,    97,    98,    99,    55,    38,    56,   119,   102,    78,
      66,    67,    55,    73,    56,    79,    68,    69,    90,    71,
     132,    80,   120,    38,    38,    38,    38,    38,    38,    38,
      38,   124,   125,   144,   100,    38,    38,   126,   125,   149,
     129,   101,    52,   135,   136,   127,   133,   105,   108,    38,
     116,   123,    52,   128,   134,   137,    52,   143,   127,   142,
     145,   146,   154,    53,    39,   107,    52,   140,   118,    52,
      81,    51,    38,   155,   104,     0,   156,     0,    52,    52,
       0,     0,     0,   153,     0,    38,    13,    14,    15,    16,
      17,     1,     0,     2,    38,     3,     0,     4,     5,     6,
       7,     8,     9,    63,    10,    64,    65,    66,    67,    11,
      38,    12,     0,    68,    69,     0,     0,    13,    14,    15,
      16,    17,    60,    61,    62,    63,     0,    64,    65,    66,
      67,     0,     0,     0,     0,    68,    69,    70,    60,    61,
      62,    63,     0,    64,    65,    66,    67,     0,     0,     0,
       0,    68,    69,    83,    60,    61,    62,    63,     0,    64,
      65,    66,    67,     0,     0,     0,     0,    68,    69,     0,
      55,     0,    56,    60,    61,    62,    63,     0,    64,    65,
      66,    67,    64,    65,    66,    67,    68,    69,    84,     0,
      68,    69,    60,    61,    62,    63,     0,    64,    65,    66,
      67,     0,    55,     0,    56,    68,    69,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,     0,    87,
      68,    69,     0,     0,     0,    83,     0,     2,     0,     3,
     147,     4,     5,     6,     7,     8,     9,     0,    10,     0,
       0,     0,     0,    11,   131,    12,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    17,     0,     1,     0,     2,
      84,     3,     0,     4,     5,     6,     7,     8,     9,     0,
      10,     0,   138,   139,     0,    11,     0,    12,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,     1,     0,
       2,     0,     3,     0,     4,     5,     6,     7,     8,     9,
       0,    10,     0,     0,     0,     0,    11,   130,    12,     0,
       0,     0,     0,     0,    13,    14,    15,    16,    17,     1,
       0,     2,   141,     3,     0,     4,     5,     6,     7,     8,
       9,     0,    10,     0,     0,     0,     0,    11,     0,    12,
       0,     0,     0,     0,     0,    13,    14,    15,    16,    17,
       1,     0,     2,     0,     3,   150,     4,     5,     6,     7,
       8,     9,     0,    10,     0,     0,     0,     0,    11,     0,
      12,     0,     0,     0,     0,     0,    13,    14,    15,    16,
      17,     1,     0,     2,     0,     3,     0,     4,     5,     6,
       7,     8,     9,     0,    10,     0,   152,     0,     0,    11,
       0,    12,     0,     0,     0,     0,     0,    13,    14,    15,
      16,    17,     1,     0,     2,     0,     3,   157,     4,     5,
       6,     7,     8,     9,     0,    10,     0,     0,     0,     0,
      11,     0,    12,     0,     0,     0,     0,     0,    13,    14,
      15,    16,    17,     1,     0,     2,     0,     3,     0,     4,
       5,     6,     7,     8,     9,     0,    10,     0,     0,     0,
       0,    11,     0,    12,   158,     0,     0,     0,     0,    13,
      14,    15,    16,    17,     1,     0,     2,     0,     3,     0,
       4,     5,     6,     7,     8,     9,     0,    10,     0,     0,
       0,     0,    11,     0,    12,     0,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    60,    61,    62,    63,     0,
      64,    65,    66,    67,     0,     0,     0,     0,    68,    69,
       2,     0,     3,     0,     4,     5,     6,     7,     8,     9,
       0,    10,     0,     0,    82,     0,    11,     0,    12,     0,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,     0,
       0,     0,    68,    69,    61,    62,    63,     0,    64,    65,
      66,    67,     0,     0,     0,     0,    68,    69,    62,    63,
       0,    64,    65,    66,    67,     0,     0,     0,     0,    68,
      69,    13,    14,    15,    16,    17,   103
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         4,     5,    19,    12,    12,    12,    10,    11,    12,    33,
      34,    22,    49,    17,     0,    26,    49,    23,    23,     3,
      21,    22,    57,    57,    59,    55,    56,     4,    47,    48,
      49,    23,    53,    10,    11,    12,    50,    80,    42,    23,
      17,    54,    55,    53,    53,    53,    53,    82,    53,    49,
      56,    49,    58,    57,    49,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    56,    42,    58,    85,    72,    73,
      15,    16,    56,    53,    58,    24,    21,    22,    82,    90,
     123,    24,    86,    60,    61,    62,    63,    64,    65,    66,
      67,    54,    55,   136,    49,    72,    73,    54,    55,   142,
     118,    49,   119,    23,    24,   109,   124,    49,    55,    86,
      35,    24,   129,    53,    49,    52,   133,   135,   122,    24,
      54,   139,    23,    19,     5,    75,   143,   131,    82,   146,
      45,     3,   109,   151,    73,    -1,   154,    -1,   155,   156,
      -1,    -1,    -1,   147,    -1,   122,    49,    50,    51,    52,
      53,    23,    -1,    25,   131,    27,    -1,    29,    30,    31,
      32,    33,    34,    11,    36,    13,    14,    15,    16,    41,
     147,    43,    -1,    21,    22,    -1,    -1,    49,    50,    51,
      52,    53,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,     8,     9,
      10,    11,    -1,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    21,    22,    23,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,    -1,
      56,    -1,    58,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    13,    14,    15,    16,    21,    22,    58,    -1,
      21,    22,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    -1,    56,    -1,    58,    21,    22,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    54,
      21,    22,    -1,    -1,    -1,    23,    -1,    25,    -1,    27,
      46,    29,    30,    31,    32,    33,    34,    -1,    36,    -1,
      -1,    -1,    -1,    41,    45,    43,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    23,    -1,    25,
      58,    27,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    -1,    38,    39,    -1,    41,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    23,    -1,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    -1,    -1,    -1,    -1,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    23,
      -1,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    -1,    -1,    -1,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      23,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    23,    -1,    25,    -1,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    36,    -1,    38,    -1,    -1,    41,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    23,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    23,    -1,    25,    -1,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    36,    -1,    -1,    -1,
      -1,    41,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    23,    -1,    25,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    -1,    36,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,    22,
      25,    -1,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    -1,    -1,    37,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    21,    22,     9,    10,    11,    -1,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    21,    22,    10,    11,
      -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
      22,    49,    50,    51,    52,    53,    54
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    23,    25,    27,    29,    30,    31,    32,    33,    34,
      36,    41,    43,    49,    50,    51,    52,    53,    60,    61,
      62,    63,    64,    65,    67,    70,    71,    72,    75,    76,
      78,    79,    80,    81,    82,    49,    49,    71,    72,    65,
      71,    57,    68,    49,    49,    49,    71,    71,    72,    71,
       0,     3,    62,    63,    23,    56,    58,    73,    23,    73,
       8,     9,    10,    11,    13,    14,    15,    16,    21,    22,
      23,    73,    12,    53,    53,    53,    50,    69,    71,    24,
      24,    79,    37,    23,    58,    74,    12,    54,     3,    64,
      71,    64,    71,    71,    71,    71,    71,    71,    71,    71,
      49,    49,    71,    54,    69,    49,    77,    77,    55,    55,
      56,    47,    48,    49,    66,    66,    35,    64,    74,    61,
      71,    54,    55,    24,    54,    55,    54,    71,    53,    61,
      42,    45,    66,    61,    49,    23,    24,    52,    38,    39,
      71,    26,    24,    61,    66,    54,    61,    46,    83,    66,
      28,    23,    38,    71,    23,    61,    61,    28,    44
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
     300,   301,   302,    40,    41,    44,    59,    35,    58
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    65,    66,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    77,    77,    77,    78,    79,    79,
      79,    80,    80,    80,    81,    82,    83,    83
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     3,     2,     1,     2,     2,     1,     2,
       3,     3,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     2,     3,     1,     1,     1,     4,     3,
       4,     4,     2,     3,     0,     3,     1,     3,     4,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,    10,     8,     7,     0,     5,     3,     4,     4,     2,
       4,     4,     6,     8,     5,    10,     0,     2
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
  "tNUMBER", "'('", "')'", "','", "';'", "'#'", "':'", "$accept",
  "program", "lines", "line", "statements", "statement", "assigment",
  "exprtype", "printstatement", "printinto", "expression_list",
  "call_function", "expression", "varref", "comma_or_colon", "seperator",
  "function_definition", "sub_definition", "arg_list", "array_dim",
  "dim_item", "if_clause", "while_loop", "for_loop", "optstep", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        60,     0,    -1,    61,     3,    -1,    61,    63,     3,    -1,
      61,    62,    -1,    62,    -1,    63,    23,    -1,    64,    23,
      -1,    23,    -1,    71,    23,    -1,    63,    73,    64,    -1,
      64,    73,    64,    -1,    67,    -1,    79,    -1,    78,    -1,
      65,    -1,    30,    65,    -1,    29,    71,    -1,    80,    -1,
      81,    -1,    82,    -1,    76,    -1,    75,    -1,    71,    73,
      -1,    72,    12,    71,    -1,    47,    -1,    48,    -1,    49,
      -1,    66,    53,    52,    54,    -1,    31,    68,    69,    -1,
      31,    68,    69,    55,    -1,    31,    68,    69,    56,    -1,
      31,    68,    -1,    57,    50,    55,    -1,    -1,    69,    55,
      71,    -1,    71,    -1,    72,    53,    54,    -1,    72,    53,
      69,    54,    -1,    70,    -1,    53,    71,    54,    -1,    71,
      14,    71,    -1,    71,    13,    71,    -1,    71,    15,    71,
      -1,    71,    16,    71,    -1,    71,    10,    71,    -1,    71,
       9,    71,    -1,    71,    11,    71,    -1,    71,     8,    71,
      -1,    72,    -1,    50,    -1,    52,    -1,    51,    -1,    71,
      22,    49,    -1,    71,    21,    49,    -1,    49,    -1,    70,
      -1,    58,    -1,    56,    -1,    23,    -1,    58,    -1,    27,
      49,    53,    77,    54,    24,    66,    23,    61,    28,    -1,
      27,    49,    53,    77,    54,    23,    61,    28,    -1,    25,
      49,    53,    77,    54,    61,    26,    -1,    -1,    77,    55,
      49,    24,    66,    -1,    49,    24,    66,    -1,    32,    49,
      24,    66,    -1,    33,    49,    24,    66,    -1,    33,    49,
      -1,    34,    49,    79,    35,    -1,    36,    71,    37,    64,
      -1,    36,    71,    37,    74,    61,    38,    -1,    36,    71,
      37,    74,    61,    39,    61,    38,    -1,    41,    71,    74,
      61,    42,    -1,    43,    72,    12,    71,    45,    71,    83,
      23,    61,    44,    -1,    -1,    46,    71,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    13,    15,    18,    21,    23,
      26,    30,    34,    36,    38,    40,    42,    45,    48,    50,
      52,    54,    56,    58,    61,    65,    67,    69,    71,    76,
      80,    85,    90,    93,    97,    98,   102,   104,   108,   113,
     115,   119,   123,   127,   131,   135,   139,   143,   147,   151,
     153,   155,   157,   159,   163,   167,   169,   171,   173,   175,
     177,   179,   190,   199,   207,   208,   214,   218,   223,   228,
     231,   236,   241,   248,   257,   263,   274,   275
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   170,   170,   180,   194,   206,   213,   214,   218,   219,
     226,   227,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   246,   250,   255,   258,   261,   265,   271,
     278,   281,   284,   291,   292,   295,   296,   304,   308,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   328,
     329,   333,   334,   339,   343,   344,   349,   352,   352,   355,
     356,   363,   374,   386,   400,   401,   405,   413,   420,   424,
     427,   441,   446,   452,   467,   476,   484,   485
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
       2,     2,     2,     2,     2,    57,     2,     2,     2,     2,
      53,    54,    15,    14,    55,    13,    22,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    56,
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
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 656;
  const int parser::yynnts_ = 25;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 50;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 59;

  const unsigned int parser::yyuser_token_number_max_ = 302;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 21 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 1640 "/home/cai/projects/basic/compiler/parser.cpp"
