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
#line 156 "parser.ypp"
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
#line 166 "parser.ypp"
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
#line 181 "parser.ypp"
    { (yyval.statement_list) = (yysemantic_stack_[(2) - (1)].statement_list); (yyval.statement_list)->addchild((yysemantic_stack_[(2) - (2)].statement_list)); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 182 "parser.ypp"
    {
		(yyval.statement_list) = new StatementAST;
		(yyval.statement_list)->addchild((yysemantic_stack_[(1) - (1)].statement_list));
	}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 187 "parser.ypp"
    { (yyval.statement_list)=(yysemantic_stack_[(2) - (1)].statement_list) ;}
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 188 "parser.ypp"
    { debug("here==3======\n");exit(1);	}
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 189 "parser.ypp"
    { /*TODO*/debug("here====5====\n"); exit(1);	}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 190 "parser.ypp"
    { (yyval.statement_list)= new EmptyStmtAST();}
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 193 "parser.ypp"
    { /*TODO*/debug("here====2====\n"); exit(1);	}
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 194 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].statement);}
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 195 "parser.ypp"
    {(yyval.statement_list)= (yysemantic_stack_[(1) - (1)].function_definition);}
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 196 "parser.ypp"
    { /*TODO*/debug("here====2====\n"); exit(1);	}
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 197 "parser.ypp"
    { /*TODO*/debug("here====2====\n"); exit(1);	}
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 200 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].printstatement); }
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 201 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].dim_list); }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 202 "parser.ypp"
    {(yyval.statement)= (yysemantic_stack_[(1) - (1)].variable_assignment);}
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 203 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(2) - (2)].variable_assignment);}
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 216 "parser.ypp"
    {
				(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(6) - (2)].id) ); //delete $2;

				(yyval.function_definition)->body = StatementASTPtr((yysemantic_stack_[(6) - (5)].statement_list));
				
				debug("!!SUB %s defined!!\n",(yysemantic_stack_[(6) - (2)].id)->c_str());
			}
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 225 "parser.ypp"
    {
				(yyval.function_definition) = new FunctionDimAST( *(yysemantic_stack_[(7) - (2)].id) ); //delete $2;

				(yyval.function_definition)->body = StatementASTPtr((yysemantic_stack_[(7) - (6)].statement_list));

				debug("!!SUB %s defined with args !!, but not supported yet\n",(yysemantic_stack_[(7) - (2)].id)->c_str());
				exit(0);
			}
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 235 "parser.ypp"
    {
		VariableRefExprAST * varrefast = new VariableRefExprAST( ReferenceASTPtr((yysemantic_stack_[(3) - (1)].varref)) );
		(yyval.variable_assignment) = new AssigmentAST(VariableRefExprASTPtr(varrefast), ExprASTPtr((yysemantic_stack_[(3) - (3)].expression)));
	}
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 240 "parser.ypp"
    {
	(yyval.exprtype) = new NumberTypeAST;
	}
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 243 "parser.ypp"
    {
		debug("define as user type not supported\n");
		exit(1);
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 248 "parser.ypp"
    { debug("define multiple line is not supported yet\n");exit(1);}
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 249 "parser.ypp"
    {
		debug("definning %s is type %p\n",(yysemantic_stack_[(3) - (1)].id)->c_str(), (yysemantic_stack_[(3) - (3)].exprtype));
		(yyval.dim_list) = new VariableDimAST( *(yysemantic_stack_[(3) - (1)].id)  , ExprTypeASTPtr ( (yysemantic_stack_[(3) - (3)].exprtype) ));
	}
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 256 "parser.ypp"
    {

		(yysemantic_stack_[(3) - (3)].expression_list)->Append( new EmptyExprAST );
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(3) - (2)].printinto), (yysemantic_stack_[(3) - (3)].expression_list) );
		
		debug("got print1 done\n");
	}
    break;

  case 29:
/* Line 661 of lalr1.cc  */
#line 263 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 266 "parser.ypp"
    {
		(yyval.printstatement) = new PrintStmtAST( (yysemantic_stack_[(4) - (2)].printinto), (yysemantic_stack_[(4) - (3)].expression_list) );
	}
    break;

  case 31:
/* Line 661 of lalr1.cc  */
#line 272 "parser.ypp"
    { debug("print has got itger\n") ;}
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 273 "parser.ypp"
    {  debug("empty printinto\n");	}
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 277 "parser.ypp"
    {
		(yyval.expression_list) =  new ExprListAST;
		(yyval.expression_list)->Append((yysemantic_stack_[(1) - (1)].expression));
	}
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 284 "parser.ypp"
    { debug("functioncall with no arg\n");}
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 291 "parser.ypp"
    {
			//TODO the VariableRefExprAST
			(yyval.expression) = new VariableRefExprAST( ReferenceASTPtr((yysemantic_stack_[(1) - (1)].varref)) );
			debug("do we got this?\n");			
		}
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 296 "parser.ypp"
    {
			//常量
			(yyval.expression) = new ConstNumberExprAST( (yysemantic_stack_[(1) - (1)].integer) );
		}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 307 "parser.ypp"
    { debug("ref menber %s . %s , not supported yet\n", (yysemantic_stack_[(3) - (1)].varref)->ID.c_str()  , (yysemantic_stack_[(3) - (3)].id)->c_str() ); 			exit(1); // 逐级传递
	}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 310 "parser.ypp"
    {
		// 变量的引用? 反正是一个标识符的引用,
		// 所以我构建一个标识符引用语句. 这个会被用来构建函数调用和数组语句以及变量.
		(yyval.varref) = new ReferenceAST( (yysemantic_stack_[(1) - (1)].id) );
		debug("idref %s\n", (yysemantic_stack_[(1) - (1)].id)->c_str());
	}
    break;


/* Line 661 of lalr1.cc  */
#line 731 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const signed char parser::yypact_ninf_ = -67;
  const short int
  parser::yypact_[] =
  {
       137,   -28,    13,    18,    21,    14,   -67,   -67,   -67,   -67,
      60,    19,   -67,    28,   -67,   -67,   -67,   -67,   -67,    58,
      -9,    25,    50,    67,    62,   -67,     2,    70,   161,   -67,
     -67,   -67,     4,   -67,    53,    83,   -12,   161,   161,   161,
     161,   -67,   -67,   161,    76,    79,   150,   -31,    18,    -5,
      85,    86,    52,   177,   -67,   -67,   -67,   163,   163,   -67,
     -67,   177,   -67,   -67,   -67,   148,   137,   159,   162,   -67,
     -67,   -67,   100,   -67,   141,   -67,    93,   161,    91,   137,
      77,    -5,   177,   161,   -67,   104,    -5,   115,   -67,     3,
     -67,   137,   -67,   -67,   126,   -67
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  parser::yydefact_[] =
  {
        35,     0,     0,     0,     0,    32,     9,    49,    43,    44,
       0,    35,     5,    35,    11,    13,    12,    17,    15,     0,
      42,     0,     0,     0,    16,    18,     0,     0,    35,     1,
       2,     4,    35,     6,     0,     0,    42,    35,    35,    35,
      35,     8,    14,    35,     0,     0,    35,     0,     0,     0,
       0,     0,    28,    34,     3,    10,     7,    39,    38,    40,
      41,    23,    48,    47,    36,     0,    35,     0,     0,    24,
      25,    27,     0,    31,    29,    30,     0,    35,    35,    35,
      35,     0,    33,    35,    21,    35,     0,    35,    26,     0,
      22,    35,    20,    37,    35,    19
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
       -67,   -67,   -22,   -10,   125,   113,   -67,   -67,   154,   -66,
     156,   -67,   -67,   118,    -7,     0
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  parser::yydefgoto_[] =
  {
        -1,    10,    11,    12,    13,    14,    15,    16,    17,    71,
      24,    18,    28,    52,    19,    36
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char parser::yytable_ninf_ = -36;
  const signed char
  parser::yytable_[] =
  {
        20,    31,    23,    43,    26,    21,    35,    54,    66,    44,
      45,    20,    44,    45,    43,    88,    37,    38,    39,    40,
      91,    53,    30,    44,    45,    35,    46,    69,    70,    46,
      57,    58,    59,    60,    26,    33,    61,     7,     8,    53,
       9,    34,    93,     1,    78,     2,    22,     3,     4,     5,
       6,    23,     7,     8,     7,     9,    27,    85,    87,    33,
      29,     7,     8,    47,     9,    34,    20,    82,    31,    94,
      82,    37,    38,    39,    40,    31,    89,    31,    20,    20,
      20,     3,     4,     5,    31,    20,     7,    20,    48,    41,
      49,    20,    74,    75,    20,    42,    37,    38,    39,    40,
      86,     1,    50,     2,    51,     3,     4,     5,     6,    62,
       7,     8,    63,     9,    56,     1,    84,     2,    72,     3,
       4,     5,     6,    81,     7,     8,    73,     9,     1,    90,
       2,    83,     3,     4,     5,     6,    32,     7,     8,     1,
       9,     2,    92,     3,     4,     5,     6,    55,     7,     8,
       1,     9,     2,    95,     3,     4,     5,     6,    25,     7,
       8,     1,     9,     2,    65,     3,     4,     5,     6,     0,
       7,     8,     0,     9,     7,     8,     0,     9,    39,    40,
       0,   -35,   -35,     7,     8,     0,     9,    76,    77,    64,
      37,    38,    39,    40,     7,     8,     0,     9,    79,    50,
       0,    80,    50,    67,    68
  };

  /* YYCHECK.  */
  const signed char
  parser::yycheck_[] =
  {
         0,    11,    33,    12,     4,    33,    13,     3,    39,    21,
      22,    11,    21,    22,    12,    81,    13,    14,    15,    16,
      86,    28,     3,    21,    22,    32,    38,    32,    33,    38,
      37,    38,    39,    40,    34,    31,    43,    33,    34,    46,
      36,    37,    39,    24,    66,    26,    33,    28,    29,    30,
      31,    33,    33,    34,    33,    36,    42,    79,    80,    31,
       0,    33,    34,    38,    36,    37,    66,    74,    78,    91,
      77,    13,    14,    15,    16,    85,    83,    87,    78,    79,
      80,    28,    29,    30,    94,    85,    33,    87,    38,    31,
      23,    91,    40,    41,    94,    37,    13,    14,    15,    16,
      23,    24,    40,    26,    34,    28,    29,    30,    31,    33,
      33,    34,    33,    36,    31,    24,    25,    26,    33,    28,
      29,    30,    31,    23,    33,    34,    40,    36,    24,    25,
      26,    38,    28,    29,    30,    31,    11,    33,    34,    24,
      36,    26,    27,    28,    29,    30,    31,    34,    33,    34,
      24,    36,    26,    27,    28,    29,    30,    31,     4,    33,
      34,    24,    36,    26,    46,    28,    29,    30,    31,    -1,
      33,    34,    -1,    36,    33,    34,    -1,    36,    15,    16,
      -1,    40,    41,    33,    34,    -1,    36,    39,    40,    39,
      13,    14,    15,    16,    33,    34,    -1,    36,    39,    40,
      -1,    39,    40,    47,    48
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  parser::yystos_[] =
  {
         0,    24,    26,    28,    29,    30,    31,    33,    34,    36,
      44,    45,    46,    47,    48,    49,    50,    51,    54,    57,
      58,    33,    33,    33,    53,    51,    58,    42,    55,     0,
       3,    46,    47,    31,    37,    57,    58,    13,    14,    15,
      16,    31,    37,    12,    21,    22,    38,    38,    38,    23,
      40,    34,    56,    57,     3,    48,    31,    57,    57,    57,
      57,    57,    33,    33,    39,    56,    39,    53,    53,    32,
      33,    52,    33,    40,    40,    41,    39,    40,    45,    39,
      39,    23,    57,    38,    25,    45,    23,    45,    52,    57,
      25,    52,    27,    39,    45,    27
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
     280,   281,   282,   283,   284,   285,   286,    58,    40,    41,
      44,    59,    35
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  parser::yyr1_[] =
  {
         0,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      47,    47,    47,    47,    47,    48,    48,    48,    48,    49,
      49,    50,    50,    51,    52,    52,    53,    53,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    56,    56,    58,    58,    58
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  parser::yyr2_[] =
  {
         0,     2,     2,     3,     2,     1,     2,     3,     2,     1,
       3,     1,     1,     1,     2,     1,     2,     1,     2,     9,
       7,     6,     7,     3,     1,     1,     5,     3,     3,     4,
       4,     3,     0,     3,     1,     0,     3,     7,     3,     3,
       3,     3,     1,     1,     1,     3,     1,     3,     3,     1
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
  "tNEWLINE", "tLONG", "tID", "tInteger", "tSTRING", "tNUMBER", "':'",
  "'('", "')'", "','", "';'", "'#'", "$accept", "program", "lines", "line",
  "statements", "statement", "function_definition", "subdefine",
  "assigment", "exprtype", "dimlist", "printstatement", "printinto",
  "expression_list", "expression", "varref", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const parser::rhs_number_type
  parser::yyrhs_[] =
  {
        44,     0,    -1,    45,     3,    -1,    45,    47,     3,    -1,
      45,    46,    -1,    46,    -1,    47,    31,    -1,    47,    57,
      31,    -1,    57,    31,    -1,    31,    -1,    47,    37,    48,
      -1,    48,    -1,    50,    -1,    49,    -1,    57,    37,    -1,
      54,    -1,    28,    53,    -1,    51,    -1,    29,    51,    -1,
      26,    33,    38,    53,    39,    23,    52,    45,    27,    -1,
      26,    33,    38,    53,    39,    45,    27,    -1,    24,    33,
      38,    39,    45,    25,    -1,    24,    33,    38,    53,    39,
      45,    25,    -1,    58,    12,    57,    -1,    32,    -1,    33,
      -1,    53,    40,    33,    23,    52,    -1,    33,    23,    52,
      -1,    30,    55,    56,    -1,    30,    55,    56,    40,    -1,
      30,    55,    56,    41,    -1,    42,    34,    40,    -1,    -1,
      56,    40,    57,    -1,    57,    -1,    -1,    58,    38,    39,
      -1,    58,    38,    56,    39,    38,    57,    39,    -1,    57,
      14,    57,    -1,    57,    13,    57,    -1,    57,    15,    57,
      -1,    57,    16,    57,    -1,    58,    -1,    34,    -1,    36,
      -1,    56,    40,    57,    -1,    57,    -1,    58,    22,    33,
      -1,    58,    21,    33,    -1,    33,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  parser::yyprhs_[] =
  {
         0,     0,     3,     6,    10,    13,    15,    18,    22,    25,
      27,    31,    33,    35,    37,    40,    42,    45,    47,    50,
      60,    68,    75,    83,    87,    89,    91,    97,   101,   105,
     110,   115,   119,   120,   124,   126,   127,   131,   139,   143,
     147,   151,   155,   157,   159,   161,   165,   167,   171,   175
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   156,   156,   166,   181,   182,   187,   188,   189,   190,
     193,   194,   195,   196,   197,   200,   201,   202,   203,   206,
     209,   214,   223,   235,   240,   243,   248,   249,   256,   263,
     266,   272,   273,   276,   277,   283,   284,   285,   287,   288,
     289,   290,   291,   296,   300,   303,   304,   307,   309,   310
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
       2,     2,     2,     2,     2,    42,     2,     2,     2,     2,
      38,    39,    15,    14,    40,    13,    22,    16,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    41,
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
      30,    31,    32,    33,    34,    35,    36
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 204;
  const int parser::yynnts_ = 16;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 29;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 43;

  const unsigned int parser::yyuser_token_number_max_ = 286;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 21 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 1231 "/home/cai/projects/basic/compiler/parser.cpp"
