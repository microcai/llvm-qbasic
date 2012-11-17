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
#line 164 "parser.ypp"
    {
			if(useDefautSubMain){
				debug("program ended\n");
				program = new DefaultMainFunctionAST( (yysemantic_stack_[(2) - (1)].statement_list) );
			}else{
				program = (yysemantic_stack_[(2) - (1)].statement_list);
				debug("module ended\n");
			}
			YYACCEPT;
		}
    break;

  case 3:
/* Line 661 of lalr1.cc  */
#line 174 "parser.ypp"
    {

			debug("!!!no new line at the end of file!!!\n"); exit(1);
			if(useDefautSubMain){
				debug("program ended\n");
				program = new DefaultMainFunctionAST( (yysemantic_stack_[(3) - (1)].statement_list) );
			}else{
				program = (yysemantic_stack_[(3) - (1)].statement_list);
				debug("module ended\n");
			}
			YYACCEPT;			
		}
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 188 "parser.ypp"
    { (yyval.statement_list) = (yysemantic_stack_[(2) - (1)].statement_list); (yyval.statement_list)->addchild((yysemantic_stack_[(2) - (2)].statement_list)); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 189 "parser.ypp"
    {
		(yyval.statement_list) = new StatementAST;
		(yyval.statement_list)->addchild((yysemantic_stack_[(1) - (1)].statement_list));
	}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 194 "parser.ypp"
    { (yyval.statement_list)=(yysemantic_stack_[(2) - (1)].statement_list);  }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 196 "parser.ypp"
    { (yyval.statement_list) = new CallStmtAST((yysemantic_stack_[(2) - (1)].call_function)); }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 197 "parser.ypp"
    { (yyval.statement_list)= new EmptyStmtAST();}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 200 "parser.ypp"
    { /*TODO*/debug("here====1====\n"); exit(1);	}
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 201 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].statement);}
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 202 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].if_clause);}
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 203 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].while_loop);}
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 204 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 205 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 206 "parser.ypp"
    { /*TODO*/debug("here====3====\n"); exit(1);	}
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 209 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].printstatement); }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 210 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_item); }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 211 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].variable_assignment);}
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 212 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].variable_assignment);}
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 213 "parser.ypp"
    {	debug("return not implemented yet\n");exit(1);}
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 216 "parser.ypp"
    {
		VariableRefExprAST * varrefast = new VariableRefExprAST( ReferenceASTPtr((yysemantic_stack_[(3) - (1)].varref)) );
		(yyval.variable_assignment) = new AssigmentAST(VariableRefExprASTPtr(varrefast), ExprASTPtr((yysemantic_stack_[(3) - (3)].expression)));
	}
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 221 "parser.ypp"
    {
	(yyval.exprtype) = new NumberTypeAST;
	}
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 224 "parser.ypp"
    {
		debug("define as user type not supported\n");
		exit(1);
	}
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 230 "parser.ypp"
    {

		(yysemantic_stack_[(3) - (3)].expression_list)->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(3) - (2)].printinto), (yysemantic_stack_[(3) - (3)].expression_list) );
		
		debug("got print1 done\n");
	}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 237 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 240 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 246 "parser.ypp"
    { debug("print has got itger\n") ;}
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 247 "parser.ypp"
    {  debug("empty printinto\n");	}
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 250 "parser.ypp"
    { (yyval.expression_list) = (yysemantic_stack_[(3) - (1)].expression_list) ; (yyval.expression_list)->Append((yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 251 "parser.ypp"
    {
		(yyval.expression_list) =  new ExprListAST;
		(yyval.expression_list)->Append((yysemantic_stack_[(1) - (1)].expression));
	}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 259 "parser.ypp"
    { (yyval.call_function) = new CallExprAST((yysemantic_stack_[(3) - (1)].varref)); debug("functioncall %s with no arg\n", (yysemantic_stack_[(3) - (1)].varref)->ID.c_str()); }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 260 "parser.ypp"
    { 	 // 这个可能是函数调用, 也许是数组哦 :)
			 // 现在就当是函数调用了, 在后面的阶段再生成数组访问
			 debug("functioncall %s with  args!!!!\n" , (yysemantic_stack_[(4) - (1)].varref)->ID.c_str() );

			 (yyval.call_function) = new CallExprAST((yysemantic_stack_[(4) - (1)].varref) , (yysemantic_stack_[(4) - (3)].expression_list) );			
		}
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 271 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_ADD , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 272 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_SUB , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 273 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_MUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 274 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_DIV , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 275 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESS , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 276 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESSEQU , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 277 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATER , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 278 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATEREQUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 280 "parser.ypp"
    {
			//TODO the VariableRefExprAST
			(yyval.expression) = new VariableRefExprAST( ReferenceASTPtr((yysemantic_stack_[(1) - (1)].varref)) );
			debug("do we got this?\n");			
		}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 285 "parser.ypp"
    {
			//常量
			(yyval.expression) = new ConstNumberExprAST( (yysemantic_stack_[(1) - (1)].integer) );
		}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    {
		debug("ref menber %s . %s , not supported yet\n", (yysemantic_stack_[(3) - (1)].varref)->ID.c_str()  , (yysemantic_stack_[(3) - (3)].id)->c_str() );
		exit(1); // 逐级传递
	}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 297 "parser.ypp"
    {
		// 变量的引用? 反正是一个标识符的引用,
		// 所以我构建一个标识符引用语句. 这个会被用来构建函数调用和数组语句以及变量.
		(yyval.varref) = new ReferenceAST( (yysemantic_stack_[(1) - (1)].id) );
		debug("idref %s\n", (yysemantic_stack_[(1) - (1)].id)->c_str());
	}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 313 "parser.ypp"
    {
					useDefautSubMain = false;
					(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(9) - (2)].id) , (yysemantic_stack_[(9) - (4)].dim_list), ExprTypeASTPtr((yysemantic_stack_[(9) - (7)].exprtype)) );

					(yysemantic_stack_[(9) - (8)].statement_list)->parent = (yysemantic_stack_[(9) - (4)].dim_list);
					(yyval.function_definition)->body = StatementASTPtr((yysemantic_stack_[(9) - (8)].statement_list));
				}
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 322 "parser.ypp"
    {
					useDefautSubMain = false;
					(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(7) - (2)].id) , (yysemantic_stack_[(7) - (4)].dim_list) , ExprTypeASTPtr( new NumberTypeAST()) );

					(yysemantic_stack_[(7) - (6)].statement_list)->parent = (yysemantic_stack_[(7) - (4)].dim_list);
					(yyval.function_definition)->body = StatementASTPtr((yysemantic_stack_[(7) - (6)].statement_list));
				}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 333 "parser.ypp"
    {
				useDefautSubMain = false;
				debug("!!SUB %s defined with arg !!\n",(yysemantic_stack_[(7) - (2)].id)->c_str());

				(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(7) - (2)].id),(yysemantic_stack_[(7) - (4)].dim_list)); //delete $2;				
				(yysemantic_stack_[(7) - (6)].statement_list)->parent = (yysemantic_stack_[(7) - (4)].dim_list);
				(yyval.function_definition)->body = StatementASTPtr((yysemantic_stack_[(7) - (6)].statement_list));
			}
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 343 "parser.ypp"
    {
		(yyval.dim_list) = (yysemantic_stack_[(3) - (1)].dim_list);
		(yyval.dim_list)->addchild((yysemantic_stack_[(3) - (3)].dim_item));

		debug("define multiple line is not supported yet\n");
		//exit(1);
	}
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 350 "parser.ypp"
    {
		(yyval.dim_list) = new VariableDimsAST ;
		(yyval.dim_list)->addchild((yysemantic_stack_[(1) - (1)].dim_item));
	}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 354 "parser.ypp"
    {(yyval.dim_list) = 0;}
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 357 "parser.ypp"
    {
		debug("definning %s is type %p\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(3) - (1)].id)  , ExprTypeASTPtr ( (yysemantic_stack_[(3) - (3)].exprtype) ));
	}
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 370 "parser.ypp"
    {
			// 单行 if then 语句
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(4) - (2)].expression)));
			(yyval.if_clause)->_then = StatementASTPtr((yysemantic_stack_[(4) - (4)].statement));
			(yysemantic_stack_[(4) - (4)].statement)->parent = (yyval.if_clause);
	}
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(6) - (2)].expression)));
			(yyval.if_clause)->_then = StatementASTPtr((yysemantic_stack_[(6) - (5)].statement_list));
			(yysemantic_stack_[(6) - (5)].statement_list)->parent = (yyval.if_clause);
		}
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(8) - (2)].expression)));
			(yyval.if_clause)->_then = StatementASTPtr((yysemantic_stack_[(8) - (5)].statement_list));
			(yysemantic_stack_[(8) - (5)].statement_list)->parent = (yyval.if_clause);
			(yyval.if_clause)->_else = StatementASTPtr((yysemantic_stack_[(8) - (7)].statement_list));
			(yysemantic_stack_[(8) - (7)].statement_list)->parent = (yyval.if_clause);
		}
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {
			(yyval.while_loop) = new WhileLoopAST( ExprASTPtr((yysemantic_stack_[(5) - (2)].expression)) , StatementASTPtr((yysemantic_stack_[(5) - (4)].statement_list)));
			(yysemantic_stack_[(5) - (4)].statement_list)->parent = (yyval.while_loop);
		}
    break;


/* Line 661 of lalr1.cc  */
#line 881 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const signed char parser::yypact_ninf_ = -54;
  const short int
  parser::yypact_[] =
  {
       313,   -54,   -33,   -28,    45,   -16,   -14,    15,    45,    45,
     -54,   -54,   -54,    45,    76,    -1,   -54,   -22,   -54,   -54,
     -54,   -12,   156,    -5,   -54,   -54,   -54,   -54,    36,    48,
     -54,   382,    46,    78,   -54,   -54,   100,    63,    45,   350,
     145,    64,   -54,   -54,   -54,    43,   -54,    52,   -54,   -54,
     -54,    45,    45,    45,    45,    45,    45,    45,    45,   -54,
      45,    69,    75,   328,   -16,   -16,   -21,    77,    44,   382,
     344,   313,   -54,   -54,   -54,   390,   397,   133,   194,    92,
      92,   -54,   -54,   382,   -54,   -54,   -54,    -8,    19,   -54,
      85,   -54,   -54,   -54,   -54,    45,   -54,   -54,   313,   173,
      45,   -54,   -16,   313,   196,   382,   150,   -54,   -54,   221,
     -21,   244,   -54,   313,   -54,   313,   -54,   267,   290,   -54,
     -54
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,     8,     0,     0,     0,     0,     0,    28,     0,     0,
      48,    44,    45,     0,     0,     0,     5,     0,    10,    18,
      16,    33,     0,    43,    14,    13,    11,    12,     0,     0,
      33,    20,    43,     0,    17,    19,     0,     0,     0,     0,
       0,     0,     1,     2,     4,     0,     6,     0,    49,    50,
       7,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,    56,    56,     0,     0,    24,    30,
       0,     0,    34,     3,     9,    42,    40,    39,    41,    36,
      35,    37,    38,    21,    47,    46,    31,     0,     0,    55,
       0,    22,    23,    57,    27,    25,    26,    58,     0,     0,
       0,    32,     0,     0,     0,    29,     0,    61,    54,     0,
       0,     0,    59,     0,    53,     0,    52,     0,     0,    60,
      51
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  parser::yypgoto_[] =
  {
       -54,   -54,   -53,    34,   111,   -35,   122,    27,   -54,   -54,
      66,    21,     1,     0,   -36,   -54,   -54,    97,    -2,   -54,
     -54
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,    14,    15,    16,    17,    18,    19,    93,    20,    38,
      68,    30,    22,    32,    50,    24,    25,    88,    89,    26,
      27
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -1;
  const unsigned char
  parser::yytable_[] =
  {
        23,    46,    43,    34,    71,    31,    36,    60,    28,    39,
      40,    48,    74,    29,    41,    23,    61,    62,    99,    91,
      92,    21,     1,    47,     2,    33,     3,    10,     4,     5,
       6,     7,     8,    49,    98,    97,    21,     9,   100,    69,
      10,    11,   101,    12,    63,   106,    73,    36,    13,    44,
     109,   111,    75,    76,    77,    78,    79,    80,    81,    82,
     117,    83,   118,    37,    69,   102,    46,    61,    62,   103,
      36,    23,    51,    52,    53,    54,    42,    55,    56,    57,
      58,     4,     5,     6,     7,    64,    10,    11,    47,    12,
      95,    96,    21,    10,    13,    63,   105,    65,    23,    23,
     108,   105,    66,    23,    23,    67,    23,    57,    58,    23,
      84,    23,    60,    23,    72,    23,    85,    23,    23,    21,
      21,    61,    62,    94,    21,    21,    45,    21,    35,    87,
      21,   102,    21,    44,    21,   104,    21,   115,    21,    21,
      44,     0,     0,    44,    54,    44,    55,    56,    57,    58,
       0,    44,    44,    51,    52,    53,    54,     0,    55,    56,
      57,    58,    90,     0,    51,    52,    53,    54,    48,    55,
      56,    57,    58,     1,     0,     2,     0,     3,     0,     4,
       5,     6,     7,     8,     0,   112,   113,     0,     9,     0,
      49,    10,    11,     0,    12,     0,     1,     0,     2,    13,
       3,    59,     4,     5,     6,     7,     8,    55,    56,    57,
      58,     9,   107,     0,    10,    11,     0,    12,     0,     1,
     110,     2,    13,     3,     0,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,    10,    11,     0,
      12,     0,     0,     0,     1,    13,     2,   114,     3,     0,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     9,
       0,     0,    10,    11,     0,    12,     0,     1,     0,     2,
      13,     3,   116,     4,     5,     6,     7,     8,     0,     0,
       0,     0,     9,     0,     0,    10,    11,     0,    12,     0,
       1,     0,     2,    13,     3,     0,     4,     5,     6,     7,
       8,     0,   119,     0,     0,     9,     0,     0,    10,    11,
       0,    12,     0,     1,     0,     2,    13,     3,   120,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,    10,    11,     0,    12,     0,     1,     0,     2,    13,
       3,     0,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    10,    11,     0,    12,    51,    52,
      53,    54,    13,    55,    56,    57,    58,    48,     0,    10,
      11,     0,    12,     4,     5,     6,     7,    13,    86,     0,
       0,     0,     0,     0,    70,    10,     0,     0,     0,    49,
      51,    52,    53,    54,     0,    55,    56,    57,    58,    52,
      53,    54,     0,    55,    56,    57,    58,    53,    54,     0,
      55,    56,    57,    58
  };

  /* YYCHECK.  */
  const signed char
  parser::yycheck_[] =
  {
         0,    23,     3,     5,    40,     4,     6,    12,    41,     8,
       9,    23,    47,    41,    13,    15,    21,    22,    71,    40,
      41,     0,    23,    45,    25,    41,    27,    41,    29,    30,
      31,    32,    33,    45,    70,    70,    15,    38,    46,    38,
      41,    42,    50,    44,    49,    98,     3,    47,    49,    15,
     103,   104,    51,    52,    53,    54,    55,    56,    57,    58,
     113,    60,   115,    48,    63,    46,    23,    21,    22,    50,
      70,    71,     8,     9,    10,    11,     0,    13,    14,    15,
      16,    29,    30,    31,    32,    49,    41,    42,    45,    44,
      46,    47,    71,    41,    49,    49,    95,    49,    98,    99,
     102,   100,    24,   103,   104,    42,   106,    15,    16,   109,
      41,   111,    12,   113,    50,   115,    41,   117,   118,    98,
      99,    21,    22,    46,   103,   104,    15,   106,     6,    63,
     109,    46,   111,    99,   113,    50,   115,   110,   117,   118,
     106,    -1,    -1,   109,    11,   111,    13,    14,    15,    16,
      -1,   117,   118,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    65,    -1,     8,     9,    10,    11,    23,    13,
      14,    15,    16,    23,    -1,    25,    -1,    27,    -1,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    38,    -1,
      45,    41,    42,    -1,    44,    -1,    23,    -1,    25,    49,
      27,    45,    29,    30,    31,    32,    33,    13,    14,    15,
      16,    38,    39,    -1,    41,    42,    -1,    44,    -1,    23,
      24,    25,    49,    27,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,
      44,    -1,    -1,    -1,    23,    49,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    41,    42,    -1,    44,    -1,    23,    -1,    25,
      49,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    44,    -1,
      23,    -1,    25,    49,    27,    -1,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    41,    42,
      -1,    44,    -1,    23,    -1,    25,    49,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    44,    -1,    23,    -1,    25,    49,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    -1,    44,     8,     9,
      10,    11,    49,    13,    14,    15,    16,    23,    -1,    41,
      42,    -1,    44,    29,    30,    31,    32,    49,    50,    -1,
      -1,    -1,    -1,    -1,    34,    41,    -1,    -1,    -1,    45,
       8,     9,    10,    11,    -1,    13,    14,    15,    16,     9,
      10,    11,    -1,    13,    14,    15,    16,    10,    11,    -1,
      13,    14,    15,    16
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    23,    25,    27,    29,    30,    31,    32,    33,    38,
      41,    42,    44,    49,    52,    53,    54,    55,    56,    57,
      59,    62,    63,    64,    66,    67,    70,    71,    41,    41,
      62,    63,    64,    41,    69,    57,    64,    48,    60,    63,
      63,    63,     0,     3,    54,    55,    23,    45,    23,    45,
      65,     8,     9,    10,    11,    13,    14,    15,    16,    45,
      12,    21,    22,    49,    49,    49,    24,    42,    61,    63,
      34,    65,    50,     3,    56,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    41,    41,    50,    61,    68,    69,
      68,    40,    41,    58,    46,    46,    47,    56,    65,    53,
      46,    50,    46,    50,    50,    63,    53,    39,    69,    53,
      24,    53,    35,    36,    26,    58,    28,    53,    53,    35,
      28
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
     290,   291,   292,   293,   294,    58,    44,    59,    35,    40,
      41
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    51,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    57,    58,    58,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    65,
      65,    66,    66,    67,    68,    68,    68,    69,    70,    70,
      70,    71
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     3,     2,     1,     2,     2,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       2,     3,     1,     1,     3,     4,     4,     3,     0,     3,
       1,     3,     4,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     3,     3,     1,     1,
       1,     9,     7,     7,     3,     1,     0,     3,     4,     6,
       8,     5
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
  "tENDWHILE", "tLONG", "tID", "tInteger", "tSTRING", "tNUMBER", "':'",
  "','", "';'", "'#'", "'('", "')'", "$accept", "program", "lines", "line",
  "statements", "statement", "assigment", "exprtype", "printstatement",
  "printinto", "expression_list", "call_function_or_array", "expression",
  "varref", "seperator", "function_definition", "sub_definition",
  "dim_list", "dim_item", "if_clause", "while_loop", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        52,     0,    -1,    53,     3,    -1,    53,    55,     3,    -1,
      53,    54,    -1,    54,    -1,    55,    23,    -1,    62,    65,
      -1,    23,    -1,    55,    45,    56,    -1,    56,    -1,    70,
      -1,    71,    -1,    67,    -1,    66,    -1,    63,    45,    -1,
      59,    -1,    30,    69,    -1,    57,    -1,    31,    57,    -1,
      29,    63,    -1,    64,    12,    63,    -1,    40,    -1,    41,
      -1,    32,    60,    61,    -1,    32,    60,    61,    46,    -1,
      32,    60,    61,    47,    -1,    48,    42,    46,    -1,    -1,
      61,    46,    63,    -1,    63,    -1,    64,    49,    50,    -1,
      64,    49,    61,    50,    -1,    62,    -1,    49,    63,    50,
      -1,    63,    14,    63,    -1,    63,    13,    63,    -1,    63,
      15,    63,    -1,    63,    16,    63,    -1,    63,    10,    63,
      -1,    63,     9,    63,    -1,    63,    11,    63,    -1,    63,
       8,    63,    -1,    64,    -1,    42,    -1,    44,    -1,    64,
      22,    41,    -1,    64,    21,    41,    -1,    41,    -1,    23,
      -1,    45,    -1,    27,    41,    49,    68,    50,    24,    58,
      53,    28,    -1,    27,    41,    49,    68,    50,    53,    28,
      -1,    25,    41,    49,    68,    50,    53,    26,    -1,    68,
      46,    69,    -1,    69,    -1,    -1,    41,    24,    58,    -1,
      33,    63,    34,    56,    -1,    33,    63,    34,    65,    53,
      35,    -1,    33,    63,    34,    65,    53,    36,    53,    35,
      -1,    38,    63,    65,    53,    39,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    13,    15,    18,    21,    23,
      27,    29,    31,    33,    35,    37,    40,    42,    45,    47,
      50,    53,    57,    59,    61,    65,    70,    75,    79,    80,
      84,    86,    90,    95,    97,   101,   105,   109,   113,   117,
     121,   125,   129,   133,   135,   137,   139,   143,   147,   149,
     151,   153,   163,   171,   179,   183,   185,   186,   190,   195,
     202,   211
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   164,   164,   174,   188,   189,   194,   195,   197,   200,
     201,   202,   203,   204,   205,   206,   209,   210,   211,   212,
     213,   216,   221,   224,   230,   237,   240,   246,   247,   250,
     251,   259,   260,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   280,   285,   289,   292,   296,   297,   305,
     305,   311,   320,   331,   343,   350,   354,   357,   370,   376,
     383,   400
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
       2,     2,     2,     2,     2,    48,     2,     2,     2,     2,
      49,    50,    15,    14,    46,    13,    22,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    47,
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
      40,    41,    42,    43,    44
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 413;
  const int parser::yynnts_ = 21;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 42;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 51;

  const unsigned int parser::yyuser_token_number_max_ = 294;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 21 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 1450 "/home/cai/projects/basic/compiler/parser.cpp"
