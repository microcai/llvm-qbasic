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
#line 174 "parser.ypp"
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
#line 188 "parser.ypp"
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
#line 200 "parser.ypp"
    {
		(yyval.codeblocks) = 0;debug("addchine2\n");
		if((yysemantic_stack_[(1) - (1)].statement_list)){
			debug("addchine2 real\n");
			(yyval.codeblocks) = new CodeBlockAST; 	(yyval.codeblocks)->addchild((yysemantic_stack_[(1) - (1)].statement_list)); 	}
	}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 207 "parser.ypp"
    { (yyval.statement_list)=(yysemantic_stack_[(2) - (1)].statement_list);  }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 208 "parser.ypp"
    {
		if(!(yysemantic_stack_[(2) - (1)].statement)){debug("statement nil\n");}
		(yyval.statement_list) = new StatementsAST ; (yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(2) - (1)].statement)));
	}
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 212 "parser.ypp"
    { debug("空行"); (yyval.statement_list) = 0;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 213 "parser.ypp"
    {
		CallStmtAST * callstmt =  new CallStmtAST( (yysemantic_stack_[(2) - (1)].call_function) );
		(yyval.statement_list) = new StatementsAST ;
		(yyval.statement_list)->push_back( StatementASTPtr(callstmt)  );
	}
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 220 "parser.ypp"
    {  (yyval.statement_list) = (yysemantic_stack_[(3) - (1)].statement_list); (yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (3)].statement))); }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 221 "parser.ypp"
    {
				(yyval.statement_list) = new StatementsAST ;
				(yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (1)].statement)));
				(yyval.statement_list)->push_back(StatementASTPtr((yysemantic_stack_[(3) - (3)].statement)));
		}
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 228 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].printstatement); }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 229 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_item); }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 230 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].variable_assignment);}
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 231 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].variable_assignment);}
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 232 "parser.ypp"
    { (yyval.statement) = new ReturnAST((yysemantic_stack_[(2) - (2)].expression));}
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 233 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].if_clause);}
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 234 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].while_loop);}
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 235 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 236 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    { /*TODO*/debug("here====3====\n"); exit(1);	}
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 243 "parser.ypp"
    {
		VariableExprAST * varref = new VariableExprAST((yysemantic_stack_[(3) - (1)].varref));
		(yyval.variable_assignment) = new AssigmentAST(varref, (yysemantic_stack_[(3) - (3)].expression));
	}
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 248 "parser.ypp"
    {
		(yyval.exprtype) = new std::string("long");
	}
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 251 "parser.ypp"
    {
		(yyval.exprtype) = new std::string("string");
	}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 254 "parser.ypp"
    {
		debug("define as user type not supported\n");
		exit(1);
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 260 "parser.ypp"
    {

		(yysemantic_stack_[(3) - (3)].expression_list)->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(3) - (2)].printinto), (yysemantic_stack_[(3) - (3)].expression_list) );
		
		debug("got print1 done\n");
	}
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 267 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 270 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 273 "parser.ypp"
    {
		ExprListAST * exprList = new ExprListAST;
		exprList->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(2) - (2)].printinto), exprList );
	}
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 280 "parser.ypp"
    { debug("print has got itger\n") ;}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 281 "parser.ypp"
    {  debug("empty printinto\n");	}
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 284 "parser.ypp"
    { (yyval.expression_list) = (yysemantic_stack_[(3) - (1)].expression_list) ; (yyval.expression_list)->Append((yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 33:
/* Line 661 of lalr1.cc  */
#line 285 "parser.ypp"
    {
		(yyval.expression_list) =  new ExprListAST;
		(yyval.expression_list)->Append((yysemantic_stack_[(1) - (1)].expression));
	}
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 293 "parser.ypp"
    { (yyval.call_function) = new CallExprAST((yysemantic_stack_[(3) - (1)].varref)); debug("functioncall %s with no arg\n", (yysemantic_stack_[(3) - (1)].varref)->ID.c_str()); }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 294 "parser.ypp"
    { 	 // 这个可能是函数调用, 也许是数组哦 :)
			 // 现在就当是函数调用了, 在后面的阶段再生成数组访问
			 debug("functioncall %s with  args!!!!\n" , (yysemantic_stack_[(4) - (1)].varref)->ID.c_str() );

			 (yyval.call_function) = new CallExprAST((yysemantic_stack_[(4) - (1)].varref) , (yysemantic_stack_[(4) - (3)].expression_list) );			
		}
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 305 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_ADD , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 306 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_SUB , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_MUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 308 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_DIV , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 309 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESS , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 310 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_LESSEQU , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 311 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATER , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 312 "parser.ypp"
    {   (yyval.expression) = new CalcExprAST( (yysemantic_stack_[(3) - (1)].expression), OPERATOR_GREATEREQUL , (yysemantic_stack_[(3) - (3)].expression) );  }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 314 "parser.ypp"
    {
			//TODO the VariableRefExprAST
			(yyval.expression) = new VariableExprAST( (yysemantic_stack_[(1) - (1)].varref) );
			debug("do we got this?\n");			
		}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 319 "parser.ypp"
    {
			//常量
			(yyval.expression) = new ConstNumberExprAST( (yysemantic_stack_[(1) - (1)].integer) );
		}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    { //字符串
			(yyval.expression) = new ConstStringExprAST((yysemantic_stack_[(1) - (1)].string));
		}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    {
		debug("ref menber %s . %s , not supported yet\n", (yysemantic_stack_[(3) - (1)].varref)->ID.c_str()  , (yysemantic_stack_[(3) - (3)].id)->c_str() );
		exit(1); // 逐级传递
	}
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 334 "parser.ypp"
    {
		// 变量的引用? 反正是一个标识符的引用,
		// 所以我构建一个标识符引用语句. 这个会被用来构建函数调用和数组语句以及变量.
		(yyval.varref) = new ReferenceAST( (yysemantic_stack_[(1) - (1)].id) );
		debug("idref %s\n", (yysemantic_stack_[(1) - (1)].id)->c_str());
	}
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 350 "parser.ypp"
    {
					useDefautSubMain = false;
					(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(10) - (2)].id) , (yysemantic_stack_[(10) - (4)].arg_list), *(yysemantic_stack_[(10) - (7)].exprtype) );

					(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(10) - (9)].codeblocks));
				}
    break;

  case 56:
/* Line 661 of lalr1.cc  */
#line 358 "parser.ypp"
    {
					useDefautSubMain = false;
					(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(8) - (2)].id) , (yysemantic_stack_[(8) - (4)].arg_list) , "long" ) ;

					(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(8) - (7)].codeblocks));
				}
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 368 "parser.ypp"
    {
				useDefautSubMain = false;
				debug("!!SUB %s defined with arg !!\n",(yysemantic_stack_[(7) - (2)].id)->c_str());

				(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(7) - (2)].id),(yysemantic_stack_[(7) - (4)].arg_list)); //delete $2;				
				(yysemantic_stack_[(7) - (6)].codeblocks)->parent = (yysemantic_stack_[(7) - (4)].arg_list);
				(yyval.function_definition)->body = CodeBlockASTPtr((yysemantic_stack_[(7) - (6)].codeblocks));
			}
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    { (yyval.arg_list) = 0; }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    {
		(yyval.arg_list) = (yysemantic_stack_[(5) - (1)].arg_list);
		(yyval.arg_list)->addchild( new ArgumentDimAST( *(yysemantic_stack_[(5) - (3)].id)  , * (yysemantic_stack_[(5) - (5)].exprtype) ) );

		debug("definning %s is type %p as arg\n",(yysemantic_stack_[(5) - (3)].id)->c_str(), (yysemantic_stack_[(5) - (5)].exprtype));

		debug("define multiple line is not supported yet\n");
		//exit(1);
	}
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {
		debug("definning %s is type %p as arg\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		
		(yyval.arg_list) = new ArgumentDimsAST ;
		(yyval.arg_list)->addchild(new ArgumentDimAST( *(yysemantic_stack_[(3) - (1)].id)  , * (yysemantic_stack_[(3) - (3)].exprtype) ));
	}
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    {
		debug("definning %s is type %p\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		(yyval.dim_item) = new VariableDimAST( *(yysemantic_stack_[(3) - (1)].id)  , * (yysemantic_stack_[(3) - (3)].exprtype) );
	}
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {
			// 单行 if then 语句
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(4) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr(new CodeBlockAST((yysemantic_stack_[(4) - (4)].statement)));
	}
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 416 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(6) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr((yysemantic_stack_[(6) - (5)].codeblocks));
		}
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 424 "parser.ypp"
    {
			(yyval.if_clause) = new IFStmtAST( ExprASTPtr((yysemantic_stack_[(8) - (2)].expression)));
			(yyval.if_clause)->_then = CodeBlockASTPtr((yysemantic_stack_[(8) - (5)].codeblocks));
			(yyval.if_clause)->_else = CodeBlockASTPtr((yysemantic_stack_[(8) - (7)].codeblocks));
		}
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 437 "parser.ypp"
    {
			(yyval.while_loop) = new WhileLoopAST( ExprASTPtr((yysemantic_stack_[(5) - (2)].expression)) , (yysemantic_stack_[(5) - (4)].codeblocks));
		}
    break;


/* Line 661 of lalr1.cc  */
#line 934 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const signed char parser::yypact_ninf_ = -79;
  const short int
  parser::yypact_[] =
  {
       332,   -79,   -34,   -31,    50,   -19,    -3,   -36,    50,    50,
     -79,   -79,   -79,   -79,    50,    28,   110,   -79,   -21,    -4,
     -79,   -79,    -2,   168,     5,   -79,   -79,   -79,   -79,    37,
      40,   -79,   411,   -16,    24,   -79,   -79,    32,    13,    50,
     370,   157,   148,   -79,   -79,   -79,     1,   -79,   363,   -79,
     363,   -79,    50,    50,    50,    50,    50,    50,    50,    50,
     -79,    50,    54,    57,   367,    63,    63,    10,    60,    21,
     411,   186,   -79,   -79,   332,   -79,   -79,   -79,   -79,    62,
     418,   424,   131,   103,   103,   -79,   -79,   411,   -79,   -79,
     -79,   -29,    90,   -14,    51,   -79,   -79,   -79,   -79,   -79,
      50,   -79,   -79,   332,   210,    50,   -79,    10,    82,   332,
      98,   411,   162,   -79,   -79,   102,   236,   332,    10,   -79,
     332,    10,   -79,   260,   106,   284,   -79,   -79,   332,   -79,
     308,   -79
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
         0,     8,     0,     0,     0,     0,     0,    31,     0,     0,
      52,    47,    49,    48,     0,     0,     0,     5,     0,     0,
      14,    12,    36,     0,    46,    20,    19,    17,    18,     0,
       0,    36,    16,    46,     0,    13,    15,     0,     0,    29,
       0,     0,     0,     1,     2,     4,     0,     6,     0,     7,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,    58,    58,     0,     0,    26,
      33,     0,    53,    54,     0,    37,     3,    10,    11,    45,
      43,    42,    44,    39,    38,    40,    41,    22,    51,    50,
      34,     0,     0,     0,     0,    23,    24,    25,    61,    30,
      27,    28,    62,     0,     0,     0,    35,     0,     0,     0,
       0,    32,     0,    65,    60,     0,     0,     0,     0,    63,
       0,     0,    57,     0,     0,     0,    59,    56,     0,    64,
       0,    55
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
       -79,   -79,   -71,   -15,   115,   -41,   128,   -78,   -79,   -79,
      72,     0,    27,     6,    67,   -79,   -79,    83,   -79,   -79,
     -79
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,    15,    16,    17,    18,    19,    20,    98,    21,    39,
      69,    31,    23,    24,    74,    25,    26,    93,    35,    27,
      28
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -1;
  const unsigned char
  parser::yytable_[] =
  {
        22,    45,    47,   104,    76,    62,    63,    77,    29,    78,
      33,    30,    37,    38,    33,    33,    22,    61,   105,    49,
      33,    51,   106,    34,    47,    48,    62,    63,    43,   114,
     102,    32,   112,   108,    64,    40,    41,   109,   116,    10,
     124,    42,    50,   126,    61,    33,   123,    48,    67,   125,
      95,    96,    97,    62,    63,    64,    68,   130,    33,    33,
      33,    33,    33,    33,    33,    33,    70,    33,   100,   101,
      33,    53,    54,    55,    22,    56,    57,    58,    59,    79,
      80,    81,    82,    83,    84,    85,    86,    65,    87,    45,
      66,    70,    10,    11,    12,    13,    88,    45,   108,    89,
      14,    45,   110,    22,    22,    92,    33,    99,    45,    22,
      45,    33,    22,    44,   107,    45,    22,    22,    58,    59,
      22,   117,   118,    22,   115,    22,   121,   111,    22,   128,
      22,    46,   111,     1,    36,     2,    91,     3,   103,     4,
       5,     6,     7,     8,    56,    57,    58,    59,     9,    94,
       0,     0,    10,    11,    12,    13,    52,    53,    54,    55,
      14,    56,    57,    58,    59,    52,    53,    54,    55,     0,
      56,    57,    58,    59,     0,     0,    52,    53,    54,    55,
      72,    56,    57,    58,    59,     1,     0,     2,     0,     3,
       0,     4,     5,     6,     7,     8,     0,   119,   120,    75,
       9,     0,     0,    73,    10,    11,    12,    13,     0,    72,
       0,     2,    14,     3,    60,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,     0,    10,    11,
      12,    13,    73,     1,     0,     2,    14,     3,     0,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,   113,
       0,     0,    10,    11,    12,    13,     0,     0,     0,     1,
      14,     2,   122,     3,     0,     4,     5,     6,     7,     8,
       0,     0,     0,     0,     9,     0,     0,     0,    10,    11,
      12,    13,     0,     1,     0,     2,    14,     3,   127,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,     0,    10,    11,    12,    13,     0,     1,     0,     2,
      14,     3,     0,     4,     5,     6,     7,     8,     0,   129,
       0,     0,     9,     0,     0,     0,    10,    11,    12,    13,
       0,     1,     0,     2,    14,     3,   131,     4,     5,     6,
       7,     8,     0,     0,     0,     0,     9,     0,     0,     0,
      10,    11,    12,    13,     0,     1,     0,     2,    14,     3,
       0,     4,     5,     6,     7,     8,     0,     0,     0,     0,
       9,     0,     0,     0,    10,    11,    12,    13,    52,    53,
      54,    55,    14,    56,    57,    58,    59,     0,     2,     0,
       3,     0,     4,     5,     6,     7,     8,     0,     0,     0,
       0,     9,     0,     0,    71,    10,    11,    12,    13,    10,
      11,    12,    13,    14,     0,     0,     0,    14,    90,    52,
      53,    54,    55,     0,    56,    57,    58,    59,    54,    55,
       0,    56,    57,    58,    59,    55,     0,    56,    57,    58,
      59
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,    16,    23,    74,     3,    21,    22,    48,    42,    50,
       4,    42,     6,    49,     8,     9,    16,    12,    47,    23,
      14,    23,    51,    42,    23,    46,    21,    22,     0,   107,
      71,     4,   103,    47,    50,     8,     9,    51,   109,    42,
     118,    14,    46,   121,    12,    39,   117,    46,    24,   120,
      40,    41,    42,    21,    22,    50,    43,   128,    52,    53,
      54,    55,    56,    57,    58,    59,    39,    61,    47,    48,
      64,     9,    10,    11,    74,    13,    14,    15,    16,    52,
      53,    54,    55,    56,    57,    58,    59,    50,    61,   104,
      50,    64,    42,    43,    44,    45,    42,   112,    47,    42,
      50,   116,    51,   103,   104,    42,   100,    47,   123,   109,
     125,   105,   112,     3,    24,   130,   116,   117,    15,    16,
     120,    23,    24,   123,    42,   125,    24,   100,   128,    23,
     130,    16,   105,    23,     6,    25,    64,    27,    71,    29,
      30,    31,    32,    33,    13,    14,    15,    16,    38,    66,
      -1,    -1,    42,    43,    44,    45,     8,     9,    10,    11,
      50,    13,    14,    15,    16,     8,     9,    10,    11,    -1,
      13,    14,    15,    16,    -1,    -1,     8,     9,    10,    11,
      23,    13,    14,    15,    16,    23,    -1,    25,    -1,    27,
      -1,    29,    30,    31,    32,    33,    -1,    35,    36,    51,
      38,    -1,    -1,    46,    42,    43,    44,    45,    -1,    23,
      -1,    25,    50,    27,    46,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    23,    -1,    25,    50,    27,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    23,
      50,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    43,
      44,    45,    -1,    23,    -1,    25,    50,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    42,    43,    44,    45,    -1,    23,    -1,    25,
      50,    27,    -1,    29,    30,    31,    32,    33,    -1,    35,
      -1,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      -1,    23,    -1,    25,    50,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      42,    43,    44,    45,    -1,    23,    -1,    25,    50,    27,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    42,    43,    44,    45,     8,     9,
      10,    11,    50,    13,    14,    15,    16,    -1,    25,    -1,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    34,    42,    43,    44,    45,    42,
      43,    44,    45,    50,    -1,    -1,    -1,    50,    51,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    10,    11,
      -1,    13,    14,    15,    16,    11,    -1,    13,    14,    15,
      16
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    23,    25,    27,    29,    30,    31,    32,    33,    38,
      42,    43,    44,    45,    50,    53,    54,    55,    56,    57,
      58,    60,    63,    64,    65,    67,    68,    71,    72,    42,
      42,    63,    64,    65,    42,    70,    58,    65,    49,    61,
      64,    64,    64,     0,     3,    55,    56,    23,    46,    23,
      46,    23,     8,     9,    10,    11,    13,    14,    15,    16,
      46,    12,    21,    22,    50,    50,    50,    24,    43,    62,
      64,    34,    23,    46,    66,    51,     3,    57,    57,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    42,    42,
      51,    62,    42,    69,    69,    40,    41,    42,    59,    47,
      47,    48,    57,    66,    54,    47,    51,    24,    47,    51,
      51,    64,    54,    39,    59,    42,    54,    23,    24,    35,
      36,    24,    26,    54,    59,    54,    59,    28,    23,    35,
      54,    28
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
     290,   291,   292,   293,   294,   295,    58,    44,    59,    35,
      40,    41
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    52,    53,    53,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    59,    59,    59,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    68,    69,    69,
      69,    70,    71,    71,    71,    72
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     3,     2,     1,     2,     2,     1,     2,
       3,     3,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     2,     3,     1,     1,     1,     3,     4,     4,     2,
       3,     0,     3,     1,     3,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     3,     1,     1,     1,    10,     8,     7,     0,     5,
       3,     3,     4,     6,     8,     5
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
  "tENDWHILE", "tLONG", "tSTR", "tID", "tInteger", "tSTRING", "tNUMBER",
  "':'", "','", "';'", "'#'", "'('", "')'", "$accept", "program", "lines",
  "line", "statements", "statement", "assigment", "exprtype",
  "printstatement", "printinto", "expression_list",
  "call_function_or_array", "expression", "varref", "seperator",
  "function_definition", "sub_definition", "arg_list", "dim_item",
  "if_clause", "while_loop", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        53,     0,    -1,    54,     3,    -1,    54,    56,     3,    -1,
      54,    55,    -1,    55,    -1,    56,    23,    -1,    57,    23,
      -1,    23,    -1,    63,    23,    -1,    56,    46,    57,    -1,
      57,    46,    57,    -1,    60,    -1,    30,    70,    -1,    58,
      -1,    31,    58,    -1,    29,    64,    -1,    71,    -1,    72,
      -1,    68,    -1,    67,    -1,    64,    46,    -1,    65,    12,
      64,    -1,    40,    -1,    41,    -1,    42,    -1,    32,    61,
      62,    -1,    32,    61,    62,    47,    -1,    32,    61,    62,
      48,    -1,    32,    61,    -1,    49,    43,    47,    -1,    -1,
      62,    47,    64,    -1,    64,    -1,    65,    50,    51,    -1,
      65,    50,    62,    51,    -1,    63,    -1,    50,    64,    51,
      -1,    64,    14,    64,    -1,    64,    13,    64,    -1,    64,
      15,    64,    -1,    64,    16,    64,    -1,    64,    10,    64,
      -1,    64,     9,    64,    -1,    64,    11,    64,    -1,    64,
       8,    64,    -1,    65,    -1,    43,    -1,    45,    -1,    44,
      -1,    65,    22,    42,    -1,    65,    21,    42,    -1,    42,
      -1,    23,    -1,    46,    -1,    27,    42,    50,    69,    51,
      24,    59,    23,    54,    28,    -1,    27,    42,    50,    69,
      51,    23,    54,    28,    -1,    25,    42,    50,    69,    51,
      54,    26,    -1,    -1,    69,    47,    42,    24,    59,    -1,
      42,    24,    59,    -1,    42,    24,    59,    -1,    33,    64,
      34,    57,    -1,    33,    64,    34,    66,    54,    35,    -1,
      33,    64,    34,    66,    54,    36,    54,    35,    -1,    38,
      64,    66,    54,    39,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    13,    15,    18,    21,    23,
      26,    30,    34,    36,    39,    41,    44,    47,    49,    51,
      53,    55,    58,    62,    64,    66,    68,    72,    77,    82,
      85,    89,    90,    94,    96,   100,   105,   107,   111,   115,
     119,   123,   127,   131,   135,   139,   143,   145,   147,   149,
     151,   155,   159,   161,   163,   165,   176,   185,   193,   194,
     200,   204,   208,   213,   220,   229
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   164,   164,   174,   188,   200,   207,   208,   212,   213,
     220,   221,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   239,   243,   248,   251,   254,   260,   267,   270,   273,
     280,   281,   284,   285,   293,   294,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   314,   319,   323,   324,
     329,   333,   334,   342,   342,   348,   356,   366,   378,   379,
     388,   396,   409,   414,   420,   435
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
      50,    51,    15,    14,    47,    13,    22,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    48,
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
      40,    41,    42,    43,    44,    45
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 440;
  const int parser::yynnts_ = 21;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 43;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 52;

  const unsigned int parser::yyuser_token_number_max_ = 295;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 21 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 1515 "/home/cai/projects/basic/compiler/parser.cpp"
