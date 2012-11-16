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
#line 23 "parser.ypp"


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
extern StatementAST * program;

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
bool useDefautSubMain = false;	/* shall we treat the while file as an sub main ? */

void qb::parser::error(const parser::location_type& loc, const std::string& msg)
{
	std::cerr << msg << " at line " << yylineno << std::endl ;
	exit(1);
}


/* Line 278 of lalr1.cc  */
#line 80 "/home/cai/projects/basic/compiler/parser.cpp"


#include "parser.hpp"

/* User implementation prologue.  */

/* Line 284 of lalr1.cc  */
#line 88 "/home/cai/projects/basic/compiler/parser.cpp"


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
#line 184 "/home/cai/projects/basic/compiler/parser.cpp"

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
#line 160 "parser.ypp"
    {
			if(useDefautSubMain){
				debug("program ended\n");
				//program = new DefaultMainFunctionAST( $1 );
			}else{
				program = (yysemantic_stack_[(2) - (1)].statement_list);
				debug("module ended\n");
			}
			YYACCEPT;
		}
    break;

  case 3:
/* Line 661 of lalr1.cc  */
#line 170 "parser.ypp"
    {

			debug("!!!no new line at the end of file!!!\n"); exit(1);
			if(useDefautSubMain){
				debug("program ended\n");
				//program = new DefaultMainFunctionAST( $1 );
			}else{
				//program = $1;
				debug("module ended\n");
			}
			YYACCEPT;
			
		}
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 185 "parser.ypp"
    { (yyval.statement_list) = (yysemantic_stack_[(2) - (1)].statement_list); (yyval.statement_list)->addchild((yysemantic_stack_[(2) - (2)].statement_list)); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 186 "parser.ypp"
    {
		(yyval.statement_list) = new StatementAST;
		(yyval.statement_list)->addchild((yysemantic_stack_[(1) - (1)].statement_list));
	}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 191 "parser.ypp"
    { (yyval.statement_list)=(yysemantic_stack_[(2) - (1)].statement_list) ;}
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 192 "parser.ypp"
    { debug("here==3======\n");exit(1);	}
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 193 "parser.ypp"
    { /*TODO*/debug("here====5====\n"); exit(1);	}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 194 "parser.ypp"
    { (yyval.statement_list)= new EmptyStmtAST();}
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 197 "parser.ypp"
    { /*TODO*/debug("here====2====\n"); exit(1);	}
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 198 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].statement);}
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 201 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 202 "parser.ypp"
    { /*TODO*/debug("here====2====\n"); exit(1);	}
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 203 "parser.ypp"
    { /*TODO*/debug("here====2====\n"); exit(1);	}
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 206 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].printstatement); }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 207 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list); }
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 208 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].variable_assignment);}
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 209 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].variable_assignment);}
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 222 "parser.ypp"
    {
				(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(6) - (2)].id) ); //delete $2;

				(yyval.function_definition)->body = StatementASTPtr((yysemantic_stack_[(6) - (5)].statement_list));
				
				debug("!!SUB %s defined!!\n",(yysemantic_stack_[(6) - (2)].id)->c_str());
			}
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 231 "parser.ypp"
    {
				(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(7) - (2)].id) ); //delete $2;

				(yyval.function_definition)->body = StatementASTPtr((yysemantic_stack_[(7) - (6)].statement_list));

				debug("!!SUB %s defined with args !!, but not supported yet\n",(yysemantic_stack_[(7) - (2)].id)->c_str());
				exit(0);
			}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 241 "parser.ypp"
    {
		VariableRefExprAST * varrefast = new VariableRefExprAST( ReferenceASTPtr((yysemantic_stack_[(3) - (1)].varref)) );
		(yyval.variable_assignment) = new AssigmentAST(VariableRefExprASTPtr(varrefast), ExprASTPtr((yysemantic_stack_[(3) - (3)].expression)));
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 246 "parser.ypp"
    {
	(yyval.exprtype) = new NumberTypeAST;
	}
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 249 "parser.ypp"
    {
		debug("define as user type not supported\n");
		exit(1);
	}
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 254 "parser.ypp"
    { debug("define multiple line is not supported yet\n");exit(1);}
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 255 "parser.ypp"
    {
		debug("definning %s is type %p\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		(yyval.dim_list) = new VariableDimAST( *(yysemantic_stack_[(3) - (1)].id)  , ExprTypeASTPtr ( (yysemantic_stack_[(3) - (3)].exprtype) ));
	}
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 262 "parser.ypp"
    {

		(yysemantic_stack_[(3) - (3)].expression_list)->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(3) - (2)].printinto), (yysemantic_stack_[(3) - (3)].expression_list) );
		
		debug("got print1 done\n");
	}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 269 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 272 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 278 "parser.ypp"
    { debug("print has got itger\n") ;}
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 279 "parser.ypp"
    {  debug("empty printinto\n");	}
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 283 "parser.ypp"
    {
		(yyval.expression_list) =  new ExprListAST;
		(yyval.expression_list)->Append((yysemantic_stack_[(1) - (1)].expression));
	}
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 290 "parser.ypp"
    { debug("functioncall with no arg\n");}
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 293 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_ADD , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 294 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_SUB , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 295 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_MUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 296 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_DIV , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 297 "parser.ypp"
    {
			//TODO the VariableRefExprAST
			(yyval.expression) = new VariableRefExprAST( ReferenceASTPtr((yysemantic_stack_[(1) - (1)].varref)) );
			debug("do we got this?\n");			
		}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 302 "parser.ypp"
    {
			//常量
			(yyval.expression) = new ConstNumberExprAST( (yysemantic_stack_[(1) - (1)].integer) );
		}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 313 "parser.ypp"
    { debug("ref menber %s . %s , not supported yet\n", (yysemantic_stack_[(3) - (1)].varref)->ID.c_str()  , (yysemantic_stack_[(3) - (3)].id)->c_str() ); 			exit(1); // 逐级传递
	}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 316 "parser.ypp"
    {
		// 变量的引用? 反正是一个标识符的引用,
		// 所以我构建一个标识符引用语句. 这个会被用来构建函数调用和数组语句以及变量.
		(yyval.varref) = new ReferenceAST( (yysemantic_stack_[(1) - (1)].id) );
		debug("idref %s\n", (yysemantic_stack_[(1) - (1)].id)->c_str());
	}
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 333 "parser.ypp"
    {
			// 单行 if then 语句
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(4) - (2)].expression)));
			(yyval.if_clause)->_then = StatementASTPtr((yysemantic_stack_[(4) - (4)].statement));
			(yysemantic_stack_[(4) - (4)].statement)->parent = (yyval.if_clause);
	}
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 341 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(6) - (2)].expression)));
			(yyval.if_clause)->_then = StatementASTPtr((yysemantic_stack_[(6) - (5)].statement_list));
			(yysemantic_stack_[(6) - (5)].statement_list)->parent = (yyval.if_clause);
		}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 350 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(8) - (2)].expression)));
			(yyval.if_clause)->_then = StatementASTPtr((yysemantic_stack_[(8) - (5)].statement_list));
			(yysemantic_stack_[(8) - (5)].statement_list)->parent = (yyval.if_clause);
			(yyval.if_clause)->_else = StatementASTPtr((yysemantic_stack_[(8) - (7)].statement_list));
			(yysemantic_stack_[(8) - (7)].statement_list)->parent = (yyval.if_clause);
		}
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {
			(yyval.while_loop) = new WhileLoopAST( ExprASTPtr((yysemantic_stack_[(5) - (2)].expression)) , StatementASTPtr((yysemantic_stack_[(5) - (4)].statement_list)));
			(yysemantic_stack_[(5) - (4)].statement_list)->parent = (yyval.while_loop);
		}
    break;


/* Line 661 of lalr1.cc  */
#line 797 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const signed char parser::yypact_ninf_ = -84;
  const short int
  parser::yypact_[] =
  {
       259,   -37,   -24,   -11,    -8,   -22,   -84,   111,   111,   -84,
     -84,   -84,    53,    81,   -84,   266,   -84,   -84,   -84,   -84,
     -84,    88,     0,   -84,   -84,    24,    29,    54,    47,   -84,
      64,    67,   111,    57,    -7,   112,   -84,   -84,   -84,    23,
     -84,    51,   207,   111,   111,   111,   111,   -84,   -84,   111,
      77,    80,    52,   -21,   -11,    -4,    83,    82,     4,   261,
     264,   -84,   -84,   259,   -84,   -84,   -84,    41,    41,   -84,
     -84,   261,   -84,   -84,   -84,    69,   259,    94,    99,   -84,
     -84,   -84,   119,   -84,   271,   -84,   -84,   259,   147,    89,
     111,   167,   259,   107,    -4,   261,   129,   -84,   111,   -84,
     187,    -4,   205,   -84,   -84,   259,    -6,   -84,   259,   -84,
     223,   -84,   241,   -84,   -84
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
        37,     0,     0,     0,     0,    34,     9,    37,    37,    51,
      45,    46,     0,    37,     5,    37,    11,    15,    14,    19,
      17,     0,    44,    12,    13,     0,     0,     0,    18,    20,
       0,     0,    37,     0,    44,     0,     1,     2,     4,    37,
       6,     0,     0,    37,    37,    37,    37,     8,    16,    37,
       0,     0,    37,     0,     0,     0,     0,     0,    30,    36,
       0,    52,    53,    37,     3,    10,     7,    41,    40,    42,
      43,    25,    50,    49,    38,     0,    37,     0,     0,    26,
      27,    29,     0,    33,    31,    32,    54,    37,    37,     0,
      37,    37,    37,    37,     0,    35,    37,    57,    37,    23,
      37,     0,    37,    28,    55,    37,     0,    24,    37,    22,
      37,    39,    37,    56,    21
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
       -84,   -84,   -59,   -13,   136,   -40,   -84,   -84,   158,   -83,
     114,   -84,   -84,   113,    16,    -2,   120,   -84,   -84
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,    12,    13,    14,    15,    16,    17,    18,    19,    81,
      28,    20,    32,    58,    21,    22,    63,    23,    24
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -38;
  const signed char
  parser::yytable_[] =
  {
        38,    65,    30,    25,    88,    34,    34,    43,    44,    45,
      46,   103,    49,    34,    50,    51,    26,    91,   108,    27,
      86,    50,    51,    33,    35,    76,    64,    31,    96,    27,
      34,    42,     9,   100,   102,    79,    80,    34,    52,    30,
     111,    34,    34,    34,    34,    52,   110,    34,    59,   112,
      34,    84,    85,    36,    40,    42,    45,    46,    30,    67,
      68,    69,    70,     9,    10,    71,    11,    41,    59,    53,
      43,    44,    45,    46,    54,    38,    49,    55,    38,     3,
       4,     5,    34,    38,    37,    50,    51,    38,    34,    38,
      60,     9,     9,    10,    56,    11,    34,    38,    74,    38,
      95,    43,    44,    45,    46,     1,    95,     2,    57,     3,
       4,     5,     6,     7,   106,    89,    90,    72,     8,    47,
      73,     9,    10,    82,    11,    43,    44,    45,    46,    83,
     101,     1,    48,     2,    98,     3,     4,     5,     6,     7,
      92,    56,    94,    61,     8,    93,    56,     9,    10,    39,
      11,     9,    10,     1,    11,     2,    62,     3,     4,     5,
       6,     7,    29,   104,   105,    75,     8,    77,    78,     9,
      10,     1,    11,     2,     0,     3,     4,     5,     6,     7,
      87,     0,     0,     0,     8,    97,     0,     9,    10,     0,
      11,     1,    99,     2,     0,     3,     4,     5,     6,     7,
       0,     0,     0,     0,     8,     0,     0,     9,    10,     0,
      11,     1,   107,     2,     0,     3,     4,     5,     6,     7,
      43,    44,    45,    46,     8,     0,     0,     9,    10,     1,
      11,     2,   109,     3,     4,     5,     6,     7,    66,     0,
       0,     0,     8,     0,     0,     9,    10,     1,    11,     2,
       0,     3,     4,     5,     6,     7,     0,   113,     0,     0,
       8,     0,     0,     9,    10,     1,    11,     2,   114,     3,
       4,     5,     6,     7,    43,    44,    45,    46,     8,     0,
       0,     9,    10,     1,    11,     2,     0,     3,     4,     5,
       6,     7,     3,     4,     5,    61,     8,    40,     0,     9,
      10,     0,    11,     0,     9,     0,     9,    10,    62,    11,
      41,     9,    10,     0,    11,     0,     0,     0,   -37,   -37
  };

  /* YYCHECK.  */
  const signed char
  parser::yycheck_[] =
  {
        13,    41,     4,    40,    63,     7,     8,    13,    14,    15,
      16,    94,    12,    15,    21,    22,    40,    76,   101,    40,
      60,    21,    22,     7,     8,    46,     3,    49,    87,    40,
      32,    15,    40,    92,    93,    39,    40,    39,    45,    41,
      46,    43,    44,    45,    46,    45,   105,    49,    32,   108,
      52,    47,    48,     0,    31,    39,    15,    16,    60,    43,
      44,    45,    46,    40,    41,    49,    43,    44,    52,    45,
      13,    14,    15,    16,    45,    88,    12,    23,    91,    28,
      29,    30,    84,    96,     3,    21,    22,   100,    90,   102,
      33,    40,    40,    41,    47,    43,    98,   110,    46,   112,
      84,    13,    14,    15,    16,    24,    90,    26,    41,    28,
      29,    30,    31,    32,    98,    46,    47,    40,    37,    31,
      40,    40,    41,    40,    43,    13,    14,    15,    16,    47,
      23,    24,    44,    26,    45,    28,    29,    30,    31,    32,
      46,    47,    23,    31,    37,    46,    47,    40,    41,    13,
      43,    40,    41,    24,    43,    26,    44,    28,    29,    30,
      31,    32,     4,    34,    35,    52,    37,    53,    54,    40,
      41,    24,    43,    26,    -1,    28,    29,    30,    31,    32,
      60,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    -1,
      43,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    40,    41,    -1,
      43,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      13,    14,    15,    16,    37,    -1,    -1,    40,    41,    24,
      43,    26,    27,    28,    29,    30,    31,    32,    31,    -1,
      -1,    -1,    37,    -1,    -1,    40,    41,    24,    43,    26,
      -1,    28,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,    24,    43,    26,    27,    28,
      29,    30,    31,    32,    13,    14,    15,    16,    37,    -1,
      -1,    40,    41,    24,    43,    26,    -1,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    37,    31,    -1,    40,
      41,    -1,    43,    -1,    40,    -1,    40,    41,    44,    43,
      44,    40,    41,    -1,    43,    -1,    -1,    -1,    47,    48
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    24,    26,    28,    29,    30,    31,    32,    37,    40,
      41,    43,    51,    52,    53,    54,    55,    56,    57,    58,
      61,    64,    65,    67,    68,    40,    40,    40,    60,    58,
      65,    49,    62,    64,    65,    64,     0,     3,    53,    54,
      31,    44,    64,    13,    14,    15,    16,    31,    44,    12,
      21,    22,    45,    45,    45,    23,    47,    41,    63,    64,
      33,    31,    44,    66,     3,    55,    31,    64,    64,    64,
      64,    64,    40,    40,    46,    63,    46,    60,    60,    39,
      40,    59,    40,    47,    47,    48,    55,    66,    52,    46,
      47,    52,    46,    46,    23,    64,    52,    38,    45,    25,
      52,    23,    52,    59,    34,    35,    64,    25,    59,    27,
      52,    46,    52,    34,    27
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
     290,   291,   292,   293,    58,    40,    41,    44,    59,    35
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    55,
      55,    56,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    63,    63,    65,
      65,    65,    66,    66,    67,    67,    67,    68
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     3,     2,     1,     2,     3,     2,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       2,     9,     7,     6,     7,     3,     1,     1,     5,     3,
       3,     4,     4,     3,     0,     3,     1,     0,     3,     7,
       3,     3,     3,     3,     1,     1,     1,     3,     1,     3,
       3,     1,     1,     1,     4,     6,     8,     5
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const parser::yytname_[] =
  {
    "$end", "error", "$undefined", "tEOPROG", "tOR", "tAND", "tNOT", "tNEQ",
  "tGEQ", "tLEQ", "tLTN", "tGTN", "tEQU", "'-'", "'+'", "'*'", "'/'",
  "tMOD", "UPLUS", "UMINUS", "tPOW", "tDREF", "'.'", "tAS", "tSUB",
  "tSUBEND", "tFUNCTION", "tFUNCTIONEND", "tDIM", "tLET", "tPRINT",
  "tNEWLINE", "tIF", "tTHEN", "tENDIF", "tELSE", "tELSEIF", "tWHILE",
  "tENDWHILE", "tLONG", "tID", "tInteger", "tSTRING", "tNUMBER", "':'",
  "'('", "')'", "','", "';'", "'#'", "$accept", "program", "lines", "line",
  "statements", "statement", "function_definition", "subdefine",
  "assigment", "exprtype", "dimlist", "printstatement", "printinto",
  "expression_list", "expression", "varref", "seperator", "if_clause",
  "while_loop", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        51,     0,    -1,    52,     3,    -1,    52,    54,     3,    -1,
      52,    53,    -1,    53,    -1,    54,    31,    -1,    54,    64,
      31,    -1,    64,    31,    -1,    31,    -1,    54,    44,    55,
      -1,    55,    -1,    67,    -1,    68,    -1,    57,    -1,    56,
      -1,    64,    44,    -1,    61,    -1,    28,    60,    -1,    58,
      -1,    29,    58,    -1,    26,    40,    45,    60,    46,    23,
      59,    52,    27,    -1,    26,    40,    45,    60,    46,    52,
      27,    -1,    24,    40,    45,    46,    52,    25,    -1,    24,
      40,    45,    60,    46,    52,    25,    -1,    65,    12,    64,
      -1,    39,    -1,    40,    -1,    60,    47,    40,    23,    59,
      -1,    40,    23,    59,    -1,    30,    62,    63,    -1,    30,
      62,    63,    47,    -1,    30,    62,    63,    48,    -1,    49,
      41,    47,    -1,    -1,    63,    47,    64,    -1,    64,    -1,
      -1,    65,    45,    46,    -1,    65,    45,    63,    46,    45,
      64,    46,    -1,    64,    14,    64,    -1,    64,    13,    64,
      -1,    64,    15,    64,    -1,    64,    16,    64,    -1,    65,
      -1,    41,    -1,    43,    -1,    63,    47,    64,    -1,    64,
      -1,    65,    22,    40,    -1,    65,    21,    40,    -1,    40,
      -1,    31,    -1,    44,    -1,    32,    64,    33,    55,    -1,
      32,    64,    33,    66,    52,    34,    -1,    32,    64,    33,
      66,    52,    35,    52,    34,    -1,    37,    64,    66,    52,
      38,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    13,    15,    18,    22,    25,
      27,    31,    33,    35,    37,    39,    41,    44,    46,    49,
      51,    54,    64,    72,    79,    87,    91,    93,    95,   101,
     105,   109,   114,   119,   123,   124,   128,   130,   131,   135,
     143,   147,   151,   155,   159,   161,   163,   165,   169,   171,
     175,   179,   181,   183,   185,   190,   197,   206
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   160,   160,   170,   185,   186,   191,   192,   193,   194,
     197,   198,   199,   200,   201,   202,   203,   206,   207,   208,
     209,   212,   215,   220,   229,   241,   246,   249,   254,   255,
     262,   269,   272,   278,   279,   282,   283,   289,   290,   291,
     293,   294,   295,   296,   297,   302,   306,   309,   310,   313,
     315,   316,   324,   324,   333,   339,   346,   363
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
       2,     2,     2,     2,     2,    49,     2,     2,     2,     2,
      45,    46,    15,    14,    47,    13,    22,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    48,
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
      40,    41,    42,    43
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 319;
  const int parser::yynnts_ = 19;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 36;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 50;

  const unsigned int parser::yyuser_token_number_max_ = 293;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 21 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 1336 "/home/cai/projects/basic/compiler/parser.cpp"
