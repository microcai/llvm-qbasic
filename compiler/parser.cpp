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

extern	StatementAST * program;


extern int yylex(qb::parser::semantic_type * yylval_param );

//extern int yylex_destroy(void);
//extern void yyerror (char *msg);
extern int yylineno;
//#define error printf
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
         printf ("cannot %s inside a loop, \"if\" statement, or \"switch\" construct", what);
      }
      else if (unclosed_dos || unclosed_fors || unclosed_repeats || unclosed_whiles) {
         printf ("cannot %s inside a loop", what);
      }
      else if (unclosed_ifs || unclosed_switches) {
         printf ("cannot %s inside an \"if\" statement or \"switch\" construct", what);
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
#line 186 "parser.ypp"
    {
			program = (yysemantic_stack_[(2) - (1)].statement);
			debug("program ended\n");
			/*add_command (cEOPROG, NULL);*/
			// yylex_destroy ();
			YYACCEPT;
		}
    break;

  case 3:
/* Line 661 of lalr1.cc  */
#line 195 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); debug("list_of_statement_lists\n"); }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 199 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement);}
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 200 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 200 "parser.ypp"
    {
		if((yysemantic_stack_[(4) - (4)].statement)){
			debug("got statement_list now %p\n",(yysemantic_stack_[(4) - (4)].statement));
			(yyval.statement) = (yysemantic_stack_[(4) - (1)].statement);
			(yysemantic_stack_[(4) - (1)].statement)->append((yysemantic_stack_[(4) - (4)].statement));
		}
	}
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 209 "parser.ypp"
    { (yyval.statement) = 0 ;}
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 210 "parser.ypp"
    { (yyval.statement) = (yysemantic_stack_[(1) - (1)].statement); }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 224 "parser.ypp"
    {
	   /*add_command (cBREAK, NULL); */
	   if (! (in_loop)) { printf ("cannot \"break\" outside of loop"); }
   }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 228 "parser.ypp"
    {
	   /*add_command (cCONTINUE, NULL)->tag = continue_corrections;*/
	   if (! (in_loop)) {
		   printf ("cannot \"continue\" outside of loop");
	   }
	}
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 237 "parser.ypp"
    { }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 238 "parser.ypp"
    { }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 239 "parser.ypp"
    {if (function_type==ftNONE) printf("declaring variables \"local\" outside of a function has no effect"); }
    break;

  case 30:
/* Line 661 of lalr1.cc  */
#line 240 "parser.ypp"
    {if (function_type==ftNONE) printf("declaring variables \"static\" outside of a function has no effect"); }
    break;

  case 32:
/* Line 661 of lalr1.cc  */
#line 241 "parser.ypp"
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
#line 249 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");	   
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 34:
/* Line 661 of lalr1.cc  */
#line 254 "parser.ypp"
    {
	   // 构造打印语句
	   debug("got PRINT now with ; \n");
	   (yyval.statement) = new PrintStmtAST(PrintIntroASTPtr((yysemantic_stack_[(4) - (2)].print_intro)),PrintListASTPtr((yysemantic_stack_[(4) - (3)].print_list)));
   }
    break;

  case 35:
/* Line 661 of lalr1.cc  */
#line 259 "parser.ypp"
    { until_eol = false; }
    break;

  case 36:
/* Line 661 of lalr1.cc  */
#line 259 "parser.ypp"
    {}
    break;

  case 37:
/* Line 661 of lalr1.cc  */
#line 260 "parser.ypp"
    { until_eol = true; }
    break;

  case 38:
/* Line 661 of lalr1.cc  */
#line 260 "parser.ypp"
    {}
    break;

  case 39:
/* Line 661 of lalr1.cc  */
#line 261 "parser.ypp"
    {
	   
             }
    break;

  case 40:
/* Line 661 of lalr1.cc  */
#line 264 "parser.ypp"
    {

	   
   }
    break;

  case 41:
/* Line 661 of lalr1.cc  */
#line 269 "parser.ypp"
    { }
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 271 "parser.ypp"
    {
	   
}
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 274 "parser.ypp"
    {}
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 275 "parser.ypp"
    {}
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 276 "parser.ypp"
    {}
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 277 "parser.ypp"
    {}
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 278 "parser.ypp"
    {}
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 279 "parser.ypp"
    {}
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 280 "parser.ypp"
    {}
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 281 "parser.ypp"
    { /*create_pushnum (TRUE); */}
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 282 "parser.ypp"
    { /*create_pushnum (FALSE); */}
    break;

  case 57:
/* Line 661 of lalr1.cc  */
#line 285 "parser.ypp"
    {

   }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 288 "parser.ypp"
    {  }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 289 "parser.ypp"
    {

   }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 292 "parser.ypp"
    {  }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 293 "parser.ypp"
    {  }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 294 "parser.ypp"
    {  }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 294 "parser.ypp"
    {
	 //  create_execute (ftNUMBER); add_command (cPOP, NULL); add_command (cPOP, NULL);
   }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 297 "parser.ypp"
    { }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 297 "parser.ypp"
    {  }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 298 "parser.ypp"
    { /*data = create_data (dotify ($2));*/ }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 314 "parser.ypp"
    { /*data_add (data, 'n')->number_value = $1; */}
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 315 "parser.ypp"
    { /*data_add (data, 'n')->number_value = -$2;*/ }
    break;

  case 77:
/* Line 661 of lalr1.cc  */
#line 316 "parser.ypp"
    { /*data_add (data, 's')->string_value = $1; */}
    break;

  case 80:
/* Line 661 of lalr1.cc  */
#line 323 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 81:
/* Line 661 of lalr1.cc  */
#line 324 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; add_command (cPOPSTRSYM, dotify ($1)); */}
    break;

  case 82:
/* Line 661 of lalr1.cc  */
#line 325 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 'n'; create_doarray (dotify ($1), ASSIGNNUMBERARRAY);*/ }
    break;

  case 83:
/* Line 661 of lalr1.cc  */
#line 326 "parser.ypp"
    { /*add_command (cDATAREAD, dotify ($3))->tag = 's'; create_doarray (dotify ($1), ASSIGNSTRINGARRAY);*/ }
    break;

  case 84:
/* Line 661 of lalr1.cc  */
#line 329 "parser.ypp"
    { /*add_command (cDATARESTORE, dotify ($1)); */}
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 330 "parser.ypp"
    {/* add_command (cDATARESTORE, dotify ($3)); */}
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 333 "parser.ypp"
    {/*add_command(cPOPNUMSYM,dotify($1));*/}
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 334 "parser.ypp"
    {/*create_doarray($1,ASSIGNNUMBERARRAY);*/}
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 337 "parser.ypp"
    {/*add_command(cPOPSTRSYM,dotify($1));*/}
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 338 "parser.ypp"
    {/*create_changestring(fMID);*/}
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 339 "parser.ypp"
    {/*create_changestring(fMID2);*/}
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 340 "parser.ypp"
    {/*create_changestring(fLEFT);*/}
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 341 "parser.ypp"
    {/*create_changestring(fRIGHT);*/}
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 342 "parser.ypp"
    {
	   //create_doarray($1,ASSIGNSTRINGARRAY);
   }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 347 "parser.ypp"
    {/*add_command(cPUSHSTRPTR,dotify($1));*/}
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 348 "parser.ypp"
    {/*create_doarray(dotify($1),GETSTRINGPOINTER);*/}
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 351 "parser.ypp"
    {		/*add_command(cPUSHSTRSYM,dotify($1));*/	}
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 353 "parser.ypp"
    {/*add_command(cSTRING_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 354 "parser.ypp"
    {/*create_pushstr($1);*/}
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 355 "parser.ypp"
    {/*add_command(cCONCAT,NULL);*/}
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 359 "parser.ypp"
    {/*create_function(fLEFT);*/}
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 360 "parser.ypp"
    {/*create_function(fRIGHT);*/}
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 361 "parser.ypp"
    {/*create_function(fMID);*/}
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 362 "parser.ypp"
    {/*create_function(fMID2);*/}
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 363 "parser.ypp"
    {/*create_function(fSTR);*/}
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 364 "parser.ypp"
    {/*create_function(fSTR2);*/}
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 365 "parser.ypp"
    {/*create_function(fSTR3);*/}
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 366 "parser.ypp"
    {/*create_function(fCHR);*/}
    break;

  case 110:
/* Line 661 of lalr1.cc  */
#line 367 "parser.ypp"
    {/*create_function(fUPPER);*/}
    break;

  case 111:
/* Line 661 of lalr1.cc  */
#line 368 "parser.ypp"
    {/*create_function(fLOWER);*/}
    break;

  case 112:
/* Line 661 of lalr1.cc  */
#line 369 "parser.ypp"
    {/*create_function(fLTRIM);*/}
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 370 "parser.ypp"
    {/*create_function(fRTRIM);*/}
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 371 "parser.ypp"
    {/*create_function(fTRIM);*/}
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 372 "parser.ypp"
    {/*add_command(cTOKENALT2,NULL);*/}
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 373 "parser.ypp"
    {/*add_command(cTOKENALT,NULL);*/}
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 374 "parser.ypp"
    {/*add_command(cSPLITALT2,NULL);*/}
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 375 "parser.ypp"
    {/*add_command(cSPLITALT,NULL);*/}
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 376 "parser.ypp"
    {/*create_function(fDATE);*/}
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 377 "parser.ypp"
    {/*create_function(fTIME);*/}
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 378 "parser.ypp"
    { /*create_function (fARG); */}
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 379 "parser.ypp"
    { /*create_function (fENV); */}
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 380 "parser.ypp"
    { /*create_execute (ftSTRING); add_command (cSWAP, NULL); add_command (cPOP, NULL); */}
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    {/*add_command(cORSHORT,NULL);pushlabel();*/}
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 383 "parser.ypp"
    {/*poplabel();create_boole('|');*/}
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    {/*add_command(cANDSHORT,NULL);pushlabel();*/}
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 384 "parser.ypp"
    {/*poplabel();create_boole('&');*/}
    break;

  case 129:
/* Line 661 of lalr1.cc  */
#line 385 "parser.ypp"
    {/*create_boole('!');*/}
    break;

  case 130:
/* Line 661 of lalr1.cc  */
#line 386 "parser.ypp"
    {/*create_numrelop('=');*/}
    break;

  case 131:
/* Line 661 of lalr1.cc  */
#line 387 "parser.ypp"
    {/*create_numrelop('!');*/}
    break;

  case 132:
/* Line 661 of lalr1.cc  */
#line 388 "parser.ypp"
    {/*create_numrelop('<');*/}
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 389 "parser.ypp"
    {/*create_numrelop('{');*/}
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 390 "parser.ypp"
    {/*create_numrelop('>');*/}
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 391 "parser.ypp"
    {/*create_numrelop('}');*/}
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 392 "parser.ypp"
    {/*add_command(cTESTEOF,NULL);*/}
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 393 "parser.ypp"
    {/*add_command(cGLOB,NULL);*/}
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 394 "parser.ypp"
    { (yyval.number_expression) = new ConstNumberExprAST((yysemantic_stack_[(1) - (1)].number));  }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 395 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 396 "parser.ypp"
    {/*add_command(cARDIM,"");*/}
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 397 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 398 "parser.ypp"
    {/*add_command(cARSIZE,"");*/}
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 399 "parser.ypp"
    {/*add_command(cNUMBER_FUNCTION_OR_ARRAY,$1);*/}
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 400 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify($1));*/}
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 401 "parser.ypp"
    {/*create_numbin('+');*/}
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 402 "parser.ypp"
    {/*create_numbin('-');*/}
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 403 "parser.ypp"
    {/*create_numbin('*');*/}
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 404 "parser.ypp"
    {/*create_numbin('/');*/}
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 405 "parser.ypp"
    {/*create_numbin('%');*/}
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 406 "parser.ypp"
    {/*create_numbin('^');*/}
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 407 "parser.ypp"
    { /*add_command(cNEGATE,NULL);*/ }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 408 "parser.ypp"
    { /* do nothing */ }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 409 "parser.ypp"
    {/*create_strrelop('=');*/}
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 410 "parser.ypp"
    {/*create_strrelop('!');*/}
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 411 "parser.ypp"
    {/*create_strrelop('<');*/}
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 412 "parser.ypp"
    {/*create_strrelop('{');*/}
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 413 "parser.ypp"
    {/*create_strrelop('>');*/}
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 414 "parser.ypp"
    {/*create_strrelop('}');*/}
    break;

  case 161:
/* Line 661 of lalr1.cc  */
#line 419 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stNUMBERARRAYREF);*/}
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 422 "parser.ypp"
    {/*create_pusharrayref(dotify($1),stSTRINGARRAYREF);*/}
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 425 "parser.ypp"
    {/*create_function(fSIN);*/}
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 426 "parser.ypp"
    {/*create_function(fASIN);*/}
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 427 "parser.ypp"
    {/*create_function(fCOS);*/}
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 428 "parser.ypp"
    {/*create_function(fACOS)*/;}
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 429 "parser.ypp"
    {/*create_function(fTAN);*/}
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 430 "parser.ypp"
    {/*create_function(fATAN);*/}
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 431 "parser.ypp"
    {/*create_function(fATAN2);*/}
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 432 "parser.ypp"
    {/*create_function(fEXP);*/}
    break;

  case 171:
/* Line 661 of lalr1.cc  */
#line 433 "parser.ypp"
    {/*create_function(fLOG);*/}
    break;

  case 172:
/* Line 661 of lalr1.cc  */
#line 434 "parser.ypp"
    {/*create_function(fLOG2);*/}
    break;

  case 173:
/* Line 661 of lalr1.cc  */
#line 435 "parser.ypp"
    {/*create_function(fINT);*/}
    break;

  case 174:
/* Line 661 of lalr1.cc  */
#line 436 "parser.ypp"
    {/*create_function(fSQR);*/}
    break;

  case 175:
/* Line 661 of lalr1.cc  */
#line 437 "parser.ypp"
    {/*create_function(fSQRT);*/}
    break;

  case 176:
/* Line 661 of lalr1.cc  */
#line 438 "parser.ypp"
    {/*create_function(fFRAC);*/}
    break;

  case 177:
/* Line 661 of lalr1.cc  */
#line 439 "parser.ypp"
    {/*create_function(fABS);*/}
    break;

  case 178:
/* Line 661 of lalr1.cc  */
#line 440 "parser.ypp"
    {/*create_function(fSIG);*/}
    break;

  case 179:
/* Line 661 of lalr1.cc  */
#line 441 "parser.ypp"
    {/*create_function(fRAN);*/}
    break;

  case 180:
/* Line 661 of lalr1.cc  */
#line 442 "parser.ypp"
    {/*create_function(fRAN2);*/}
    break;

  case 181:
/* Line 661 of lalr1.cc  */
#line 443 "parser.ypp"
    {/*create_function(fMIN);*/}
    break;

  case 182:
/* Line 661 of lalr1.cc  */
#line 444 "parser.ypp"
    {/*create_function(fMAX);*/}
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 445 "parser.ypp"
    {/*create_function(fLEN);*/}
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 446 "parser.ypp"
    {/*create_function(fVAL);*/}
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 447 "parser.ypp"
    {/*create_function(fASC);*/}
    break;

  case 186:
/* Line 661 of lalr1.cc  */
#line 448 "parser.ypp"
    {/*create_function(fINSTR);*/}
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 449 "parser.ypp"
    {/*create_function(fINSTR2);*/}
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 450 "parser.ypp"
    {/*create_function(fRINSTR);*/}
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 451 "parser.ypp"
    {/*create_function(fRINSTR2);*/}
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 452 "parser.ypp"
    {/*create_function(fSYSTEM);*/}
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 453 "parser.ypp"
    {/*create_function(fAND);*/}
    break;

  case 192:
/* Line 661 of lalr1.cc  */
#line 454 "parser.ypp"
    {/*create_function(fOR);*/}
    break;

  case 193:
/* Line 661 of lalr1.cc  */
#line 455 "parser.ypp"
    {/*create_function(fEOR);*/}
    break;

  case 194:
/* Line 661 of lalr1.cc  */
#line 456 "parser.ypp"
    {/*add_command(cTOKEN2,NULL);*/}
    break;

  case 195:
/* Line 661 of lalr1.cc  */
#line 457 "parser.ypp"
    {/*add_command(cTOKEN,NULL);*/}
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 458 "parser.ypp"
    {/*add_command(cSPLIT2,NULL);*/}
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 459 "parser.ypp"
    {/*add_command(cSPLIT,NULL);*/}
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 460 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION);*/}
    break;

  case 199:
/* Line 661 of lalr1.cc  */
#line 461 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_MODE);*/}
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 462 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM);*/}
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 463 "parser.ypp"
    {/*create_myopen (OPEN_FUNCTION + OPEN_HAS_STREAM + OPEN_HAS_MODE);*/}
    break;

  case 202:
/* Line 661 of lalr1.cc  */
#line 464 "parser.ypp"
    { /*create_function (fTELL); */}
    break;

  case 203:
/* Line 661 of lalr1.cc  */
#line 465 "parser.ypp"
    { /*create_function (fPEEKFILE);*/ }
    break;

  case 204:
/* Line 661 of lalr1.cc  */
#line 466 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL);*/ }
    break;

  case 205:
/* Line 661 of lalr1.cc  */
#line 466 "parser.ypp"
    { /*create_execute (ftNUMBER); add_command (cSWAP, NULL); add_command (cPOP, NULL);*/ }
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 473 "parser.ypp"
    {/*create_dim(dotify($1),'N');*/}
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 474 "parser.ypp"
    {/*create_dim(dotify($1),'S');*/}
    break;

  case 210:
/* Line 661 of lalr1.cc  */
#line 475 "parser.ypp"
    {/*create_dim(dotify($3),'N');*/}
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 476 "parser.ypp"
    {/*create_dim(dotify($3),'S');*/}
    break;

  case 212:
/* Line 661 of lalr1.cc  */
#line 479 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 213:
/* Line 661 of lalr1.cc  */
#line 480 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 214:
/* Line 661 of lalr1.cc  */
#line 483 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 215:
/* Line 661 of lalr1.cc  */
#line 486 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 216:
/* Line 661 of lalr1.cc  */
#line 487 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL); $$ = dotify ($1); */}
    break;

  case 217:
/* Line 661 of lalr1.cc  */
#line 490 "parser.ypp"
    {/*$$ = dotify ($1);*/}
    break;

  case 218:
/* Line 661 of lalr1.cc  */
#line 493 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 219:
/* Line 661 of lalr1.cc  */
#line 494 "parser.ypp"
    { /*if (cli != NULL) { cli->items++; }*/ }
    break;

  case 222:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    { unclosed_subs++; }
    break;

  case 223:
/* Line 661 of lalr1.cc  */
#line 501 "parser.ypp"
    { not_inside_loop_or_conditional ("define a function");
if (function_type!=ftNONE) {printf("functions cannot be nested");}}
    break;

  case 224:
/* Line 661 of lalr1.cc  */
#line 503 "parser.ypp"
    {
	   
}
    break;

  case 225:
/* Line 661 of lalr1.cc  */
#line 506 "parser.ypp"
    {
	   
}
    break;

  case 226:
/* Line 661 of lalr1.cc  */
#line 510 "parser.ypp"
    {
	
   }
    break;

  case 227:
/* Line 661 of lalr1.cc  */
#line 515 "parser.ypp"
    {
		if (unclosed_subs)
		{
			printf ("%d subroutine%s not closed", unclosed_subs, (unclosed_subs > 1) ? "s" : "");
		}
	}
    break;

  case 228:
/* Line 661 of lalr1.cc  */
#line 521 "parser.ypp"
    {unclosed_subs--;}
    break;

  case 229:
/* Line 661 of lalr1.cc  */
#line 524 "parser.ypp"
    {
	//function_type=ftNUMBER;current_function = dotify ($1); $$ = dotify ($1);
	}
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 527 "parser.ypp"
    {/*function_type=ftSTRING;current_function = dotify ($1); $$ = dotify ($1);*/}
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 530 "parser.ypp"
    {
	
                      }
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 533 "parser.ypp"
    {
						  
                      }
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 536 "parser.ypp"
    {
						  
                      }
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 539 "parser.ypp"
    {
						  
                      }
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 544 "parser.ypp"
    {
//                    function_type = ftNUMBER;
//                    cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_NUMBER;
//                    current_function = mystrdup ($1);
//                    $$ = mystrdup ($1);
                }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 550 "parser.ypp"
    {
//         function_type = ftSTRING;
//         cfunction_type = YABMOD_INTERFACE_TYPE_SCALAR_STRING;
//         current_function = mystrdup ($1);
//         $$ = mystrdup ($1);
     }
    break;

  case 240:
/* Line 661 of lalr1.cc  */
#line 563 "parser.ypp"
    {
//                          create_require (stNUMBER); create_makelocal (dotify ($1), syNUMBER); add_command (cPOPNUMSYM, dotify ($1));
                      }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 566 "parser.ypp"
    {
//         create_require (stSTRING); create_makelocal (dotify ($1), sySTRING); add_command (cPOPSTRSYM, dotify ($1));
     }
    break;

  case 242:
/* Line 661 of lalr1.cc  */
#line 569 "parser.ypp"
    {
//         create_require (stNUMBERARRAYREF); create_arraylink (dotify ($1), stNUMBERARRAYREF);
     }
    break;

  case 243:
/* Line 661 of lalr1.cc  */
#line 572 "parser.ypp"
    {
//         create_require (stSTRINGARRAYREF); create_arraylink (dotify ($1), stSTRINGARRAYREF);
     }
    break;

  case 246:
/* Line 661 of lalr1.cc  */
#line 581 "parser.ypp"
    {/* create_makelocal (dotify ($1), syNUMBER);*/ }
    break;

  case 247:
/* Line 661 of lalr1.cc  */
#line 582 "parser.ypp"
    {/* create_makelocal (dotify ($1), sySTRING); */}
    break;

  case 248:
/* Line 661 of lalr1.cc  */
#line 583 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 'n'); */}
    break;

  case 249:
/* Line 661 of lalr1.cc  */
#line 584 "parser.ypp"
    { /*create_makelocal (dotify ($1), syARRAY); create_dim (dotify ($1), 's'); */}
    break;

  case 252:
/* Line 661 of lalr1.cc  */
#line 591 "parser.ypp"
    { /*create_makestatic (dotify ($1), syNUMBER);*/ }
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 592 "parser.ypp"
    { /*create_makestatic (dotify ($1), sySTRING);*/ }
    break;

  case 254:
/* Line 661 of lalr1.cc  */
#line 593 "parser.ypp"
    { /*create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'N'); */}
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 594 "parser.ypp"
    {/* create_makestatic (dotify ($1), syARRAY); create_dim (dotify ($1), 'S'); */}
    break;

  case 259:
/* Line 661 of lalr1.cc  */
#line 602 "parser.ypp"
    {/*create_require(stNUMBER);create_makelocal(dotify ($1),syNUMBER);add_command(cPOPNUMSYM,dotify ($1));*/}
    break;

  case 260:
/* Line 661 of lalr1.cc  */
#line 603 "parser.ypp"
    {
	   
}
    break;

  case 261:
/* Line 661 of lalr1.cc  */
#line 606 "parser.ypp"
    {
	   
}
    break;

  case 262:
/* Line 661 of lalr1.cc  */
#line 609 "parser.ypp"
    {
	   
}
    break;

  case 263:
/* Line 661 of lalr1.cc  */
#line 614 "parser.ypp"
    { unclosed_fors++; }
    break;

  case 264:
/* Line 661 of lalr1.cc  */
#line 615 "parser.ypp"
    {
				 
			}
    break;

  case 265:
/* Line 661 of lalr1.cc  */
#line 619 "parser.ypp"
    {
	 }
    break;

  case 266:
/* Line 661 of lalr1.cc  */
#line 621 "parser.ypp"
    {/*
              swap();popgoto();poplabel();*/}
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 623 "parser.ypp"
    {/*create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/
		}
    break;

  case 268:
/* Line 661 of lalr1.cc  */
#line 627 "parser.ypp"
    {
		if (unclosed_fors) {
			printf ("%d \"for\" loop%s not closed", unclosed_fors, (unclosed_fors > 1) ? "s" : "");
		}
	}
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 632 "parser.ypp"
    {unclosed_fors--;}
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 635 "parser.ypp"
    {/* pop (stSTRING);*/ }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 636 "parser.ypp"
    {  }
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 639 "parser.ypp"
    {/*create_pushnum(1);*/}
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 643 "parser.ypp"
    { unclosed_switches ++; }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 643 "parser.ypp"
    {
	}
    break;

  case 276:
/* Line 661 of lalr1.cc  */
#line 645 "parser.ypp"
    { unclosed_switches --; }
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 645 "parser.ypp"
    {continue_corrections --;
					 
				}
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 650 "parser.ypp"
    { yylineno += (yysemantic_stack_[(1) - (1)].separator); }
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 651 "parser.ypp"
    { yylineno += (yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 659 "parser.ypp"
    {
	   
}
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 662 "parser.ypp"
    {
		   
	}
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 668 "parser.ypp"
    { yylineno+=(yysemantic_stack_[(2) - (2)].separator); }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 668 "parser.ypp"
    {

	   
}
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 674 "parser.ypp"
    { unclosed_dos++; }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 674 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 679 "parser.ypp"
    {if (unclosed_dos) { printf ("%d \"do\" loop%s not closed", unclosed_dos, (unclosed_dos > 1) ? "s" : ""); } }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 680 "parser.ypp"
    {unclosed_dos--;}
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 680 "parser.ypp"
    {/*popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 683 "parser.ypp"
    { unclosed_whiles++; }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 683 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto()*/}
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 684 "parser.ypp"
    {/*add_command(cDECIDE,NULL);
         pushlabel();*/}
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 690 "parser.ypp"
    {if (unclosed_whiles) { printf ("%d \"while\" loop%s not closed", unclosed_whiles, (unclosed_whiles > 1) ? "s" : ""); } }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 691 "parser.ypp"
    {unclosed_whiles--;}
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 691 "parser.ypp"
    { }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 694 "parser.ypp"
    { unclosed_repeats++; }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 694 "parser.ypp"
    {/*add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);pushgoto();*/}
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 699 "parser.ypp"
    {if (unclosed_repeats) { printf ("%d \"repeat\" loop%s not closed", unclosed_repeats, (unclosed_repeats > 1) ? "s" : ""); } }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 701 "parser.ypp"
    {unclosed_repeats--;}
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 701 "parser.ypp"
    {/*add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);*/}
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 704 "parser.ypp"
    {/*add_command(cDECIDE,NULL);storelabel();pushlabel();*/}
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 705 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 707 "parser.ypp"
    {/*poplabel();*/}
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 711 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 712 "parser.ypp"
    { unclosed_ifs--; }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 712 "parser.ypp"
    {/* swap (); matchgoto (); swap (); poplabel (); poplabel (); */}
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 713 "parser.ypp"
    { /*add_command (cDECIDE, NULL); storelabel (); pushlabel ();*/ }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 714 "parser.ypp"
    {/* unclosed_ifs--; } { swap (); matchgoto (); swap (); poplabel (); poplabel ();*/ }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 717 "parser.ypp"
    {if (unclosed_ifs) { printf ("%d \"if\" statement%s not closed", unclosed_ifs, (unclosed_ifs > 1) ? "s" : ""); } }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 718 "parser.ypp"
    {unclosed_ifs--;}
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 721 "parser.ypp"
    { unclosed_ifs ++; }
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 730 "parser.ypp"
    {/*add_command(cDECIDE,NULL);pushlabel();*/}
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 732 "parser.ypp"
    {/*swap();matchgoto();swap();poplabel();*/}
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 736 "parser.ypp"
    {/*create_myread ('n', until_eol); add_command (cPOPNUMSYM, dotify ($1)); */}
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 737 "parser.ypp"
    {/*create_myread('s',until_eol);add_command(cPOPSTRSYM, dotify ($1));*/}
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 738 "parser.ypp"
    {/*create_myread('n',until_eol);create_doarray(dotify ($1),ASSIGNNUMBERARRAY);*/}
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 739 "parser.ypp"
    {/*create_myread('s',until_eol);create_doarray(dotify ($1),ASSIGNSTRINGARRAY);*/}
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 742 "parser.ypp"
    { printf("ERROR: print with no arg not supprted yet\n"); exit(1); }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 743 "parser.ypp"
    {
		debug("got first print argument as number\n");
		(yyval.print_list) = new PrintListAST();
		(yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(1) - (1)].number_expression)));
   }
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 749 "parser.ypp"
    { printf("ERROR: print syntax not supprted yet\n"); exit(1);}
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 751 "parser.ypp"
    { printf("ERROR: print syntax not supprted yet\n"); exit(1); }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 753 "parser.ypp"
    { (yyval.print_list) = (yysemantic_stack_[(3) - (1)].print_list) ; (yyval.print_list)->additem(ExprASTPtr((yysemantic_stack_[(3) - (3)].number_expression))) ; }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 755 "parser.ypp"
    {/* create_print ('b'); create_print ('u'); */}
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 757 "parser.ypp"
    { /*create_print ('b'); create_print ('s');*/ }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 760 "parser.ypp"
    {/*create_pushnum(STDIO_STREAM);create_pps(cPUSHSTREAM,1);*/}
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 761 "parser.ypp"
    {/*add_command(cPUSHNUMSYM,dotify ($2));create_pps(cPUSHSTREAM,1);*/}
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 762 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,1);*/}
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 763 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,1);*/}
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 767 "parser.ypp"
    {/* create_print ('s');*/ }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 770 "parser.ypp"
    {
		debug("empty print_intro\n");
		/*构造一个默认的 打印目标*/
		(yyval.print_intro) = new PrintIntroAST(); 
	}
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 775 "parser.ypp"
    {  /* 构造一个使用常数表的打印目标*/ }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 776 "parser.ypp"
    {/*create_pushnum ($2); create_pps(cPUSHSTREAM,0);*/}
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 777 "parser.ypp"
    {/*create_pps(cPUSHSTREAM,0);*/}
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 780 "parser.ypp"
    {/* add_command (cOPTEXPLICIT, NULL); */}
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 783 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 784 "parser.ypp"
    {/* add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('-'); add_command (cPOPNUMSYM, dotify ($3)); */}
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 787 "parser.ypp"
    { /*add_command (cPUSHNUMSYM, dotify ($1)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($1));*/ }
    break;

  case 354:
/* Line 661 of lalr1.cc  */
#line 788 "parser.ypp"
    {
	/*   add_command (cPUSHNUMSYM, dotify ($3)); create_pushnum (1); create_numbin ('+'); add_command (cPOPNUMSYM, dotify ($3));*/ }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 792 "parser.ypp"
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

  case 356:
/* Line 661 of lalr1.cc  */
#line 802 "parser.ypp"
    {
//                          add_command (cENDSTRUCT, NULL)->args = cli->items;
//                          next_cli = cli->next;
//                          xfree (cli);
//                          cli = next_cli;
                      }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 808 "parser.ypp"
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

  case 358:
/* Line 661 of lalr1.cc  */
#line 818 "parser.ypp"
    {
//         add_command (cENDSTRUCT, NULL)->args = cli->items;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 831 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 839 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 847 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = syNUMBER;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 855 "parser.ypp"
    {
//         cmd = add_command (cSTRUCTVAR, $2);
//         cmd->args = cli->items;
//         cmd->tag = sySTRING;
//         next_cli = cli->next;
//         xfree (cli);
//         cli = next_cli;
     }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 865 "parser.ypp"
    {
//             old_cli = cli;
//             cli = xmalloc (sizeof (struct cli));
//             cli->items = 0;
//             cli->next = old_cli;
         }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 873 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 874 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 877 "parser.ypp"
    {
	/*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1); */}
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 879 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 880 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 881 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 884 "parser.ypp"
    {
// 	$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);
 	}
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 887 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 888 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 889 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 892 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 893 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 896 "parser.ypp"
    { /*add_command (cPUSHFREE, NULL); } call_list ')' { $$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 897 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 898 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 899 "parser.ypp"
    {/* add_command (cPUSHFREE, NULL);*/ }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 899 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 902 "parser.ypp"
    { /*$$ = xmalloc ((strlen ($1) + 1) * sizeof (char)); strcpy ($$, $1);*/ }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 903 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 904 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1);*/ }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 905 "parser.ypp"
    { /*$$ = xmalloc (((strlen ($1) + 1 + strlen ($3)) + 1) * sizeof (char)); $$ [1 - 1] = '\0'; strcat ($$, $1); strcat ($$, "."); strcat ($$, $3); xfree ($1); */}
    break;


/* Line 661 of lalr1.cc  */
#line 2553 "/home/cai/projects/basic/compiler/parser.cpp"
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
  const short int parser::yypact_ninf_ = -601;
  const short int
  parser::yypact_[] =
  {
      3389,   -98,   -32,  -601,  -601,  -601,  2484,   290,    15,    32,
    -601,    59,    59,    59,  -601,  -601,  2484,  -601,  -601,  -601,
    -601,  -601,    70,   190,  -601,  -601,    59,    59,   -86,  -601,
     106,  -601,  -601,    59,   245,    59,    39,   103,   205,  2050,
    2050,  2050,  2050,   219,   286,   163,   200,  -601,  -601,  -601,
    -601,  -601,   299,  -601,   334,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  2484,  -601,   -51,     2,   214,   338,
     363,  -601,   226,   283,  -601,  -601,  -601,   291,   342,  2484,
     349,   376,   385,   389,   410,   411,   412,   415,   416,   417,
     418,   421,   423,   424,   425,   426,   427,   429,   431,   432,
     433,   434,   435,   437,   438,   439,   440,   441,   442,   443,
     447,   450,   452,   454,   457,   458,   459,   460,   461,  -601,
    -601,   463,   469,   477,   478,   479,   481,   483,   484,   488,
     489,  2484,  2484,  2484,   242,  -601,  3175,  -601,  -601,  -601,
     356,   364,  -601,  -601,   290,   308,   356,   364,   214,  -601,
    -601,   269,  -601,   375,   375,   375,   518,   518,   242,  3175,
      59,  -601,  -601,  -601,   490,   493,  -601,  -601,    17,   364,
    -601,   493,   445,   471,   364,  -601,   245,   245,   497,   375,
     498,   375,    13,  2484,   305,  -601,   617,  -601,   375,   499,
    -601,     3,    26,   613,   614,   502,   375,   245,   245,   245,
    2484,  3175,   506,  -601,   511,   513,   290,  -601,  -601,  3389,
    -601,  2484,   290,  1856,  2484,   302,   361,   487,   290,  -601,
    -601,   269,  2484,  2484,   856,  2484,  -601,  -601,   504,   504,
    2484,  2484,  2291,  2484,  2484,  2484,  2484,  2484,  2484,   290,
     290,   290,   290,   290,  2050,  2050,  2050,  2050,  2484,  2484,
    2484,  2484,  2484,  2484,  2484,  2484,  2484,  2484,   290,   290,
     290,   290,  2484,   290,   290,   245,   290,   245,   290,   290,
     290,   290,   290,   290,   585,   585,    58,   413,   290,   290,
     290,   290,   290,   290,   290,  -601,  -601,  2484,  2484,  2484,
    2484,  2484,  2484,  2484,  2484,  2484,  2484,  2484,  2484,    78,
    2484,  2484,  -601,  -601,   516,  -601,   646,  -601,  -601,  -601,
      40,  2484,  3389,  3389,  -601,  -601,   512,   190,   517,   520,
    -601,   526,   364,  -601,  -601,   529,  -601,   526,   364,  -601,
    -601,    59,    59,  -601,  2484,   375,   242,  3063,   240,    33,
    -601,   290,   305,   527,   528,  2484,   645,   245,    59,    59,
      59,    59,    59,   530,   526,  -601,  -601,   532,   533,  3175,
     290,  2484,  2484,    84,   200,  3389,  3175,   308,   615,  3389,
     645,  3175,   534,   535,   536,   537,   539,   546,   308,  -601,
     516,  -601,  2915,  2929,  3009,  2484,  2484,   547,   554,   519,
     555,   558,   214,  -601,   559,   560,   737,   832,  -601,   914,
    1009,  1037,  1068,  1170,  3023,  3037,   -84,    -7,    85,    90,
     101,    49,   562,   556,   561,   563,  1202,  1294,  1379,  1397,
    1519,    -3,  1538,    11,    37,  1652,   167,   178,   179,   180,
    1667,   184,    96,   -71,    97,    -6,   110,   207,   227,   264,
     185,   208,  -601,  -601,   308,   308,   308,   308,   308,   308,
    -601,  2484,  2484,   550,   120,   196,   387,   310,   201,  -601,
     -40,   -40,   585,   585,   585,   242,  3175,   156,  -601,   255,
     565,   521,  -601,  -601,  3175,    72,    34,   566,   571,   364,
    -601,   571,   245,   245,   375,   375,  1753,   290,  -601,  2484,
    -601,  2484,   375,   308,   245,  -601,   660,   645,   663,   645,
     242,  3175,   645,  -601,    36,  -601,   375,   375,   375,   375,
     375,  2484,  2484,  2484,   211,  3051,  3175,  -601,  -601,  3389,
    -601,  3300,   582,   583,  2484,  2484,   584,   593,   586,  2484,
    2484,  2484,   280,   281,   226,   283,  -601,  -601,   523,  2484,
    2484,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  2484,  2484,
    2484,  2484,  2484,  -601,  -601,   290,  -601,   290,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  2484,  -601,  -601,  2484,
    -601,   290,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
     504,   290,  -601,   504,   290,  -601,   290,  -601,  -601,  -601,
     290,   290,   856,   821,  2484,  -601,  -601,   525,  -601,  2484,
    3389,  -601,  2484,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,   308,   242,  3138,   245,  2055,   245,  -601,   526,
     364,  -601,  -601,    76,    76,   691,  -601,  -601,  -601,   727,
      28,  -601,    18,  -601,  2186,  2198,   327,   290,   290,   200,
    -601,  -601,  -601,  -601,  2484,   284,   307,  -601,  -601,   525,
    2224,  2414,  2603,  -601,  -601,   596,   597,  2615,  2627,  2639,
    2657,  2739,  2751,   372,   271,    66,  2763,  2779,    67,   323,
     314,   324,   339,   350,    79,   151,  -601,   554,   328,  -601,
     602,   214,  -601,  -601,  3150,   181,  3175,  -601,   290,  -601,
    -601,  -601,  -601,   466,   645,   245,   468,   473,  -601,  -601,
    -601,    45,   691,   675,   676,  2484,   678,   308,   308,   696,
     368,  -601,  -601,   369,  -601,   602,   214,  -601,  -601,  -601,
    -601,  -601,   582,   583,  -601,  -601,  -601,  -601,  -601,  -601,
    2484,  -601,  -601,   290,  -601,  -601,  -601,   290,  -601,   290,
    -601,  -601,   290,  -601,  -601,  -601,  2484,  -601,  2484,  -601,
     525,  -601,   531,  2484,  -601,  -601,  -601,  -601,   308,   245,
    -601,   645,   691,   526,   364,  -601,  -601,  -601,  -601,   734,
     674,  -601,   290,   290,  2793,   290,  2484,   701,  -601,   525,
    -601,  2875,   353,   354,   355,   359,  2887,  2901,  -601,   726,
     597,  3166,  -601,  -601,   691,  2484,  -601,  -601,   308,   308,
     688,   308,  3159,  3389,  -601,  -601,  3389,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,   745,  2484,  -601,  -601,  -601,  -601,
     290,  -601,   200,    46,    75,  -601,  3175,  3389,  3389,   308,
    3389,  -601,  -601,  -601,  -601,  -601,  -601,   200,   200,   200,
      51,   696,  -601,  -601,    59,  -601,  -601,   375
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  parser::yydefact_[] =
  {
         8,   367,   377,    21,    22,   222,    39,     0,     0,     0,
     231,     0,     0,     0,    51,    53,    44,   263,   295,   302,
     289,   319,     0,     0,    28,    30,     0,     0,   346,    35,
       0,   366,   274,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     5,     9,    10,
      11,    26,     0,    27,     0,    23,    24,    17,    20,    16,
      19,    18,    14,    15,     0,    25,     0,   212,   213,     0,
     215,   216,   369,   379,   223,   138,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    97,    40,   159,   143,    98,
     144,   212,    96,   215,     0,    61,     0,     0,     0,    62,
      64,     0,   367,    57,    58,    59,     0,     0,     0,    45,
       0,   296,   303,   290,   367,   377,    12,    13,     0,   214,
     217,     0,    42,     0,   208,   209,     0,     0,    56,   353,
      55,   351,     0,   330,   337,    37,     0,   275,    66,    68,
      78,     0,     0,     0,     0,    69,    84,     0,     0,     0,
       0,   207,     0,    48,     0,     0,     0,     1,     2,     8,
       6,     0,     0,   312,     0,     0,     0,     0,     0,   373,
     384,     0,     0,     0,   129,     0,   204,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   377,   232,   235,   236,     0,   350,    52,    54,
       0,     0,     8,     8,   369,   379,     0,     0,     0,    29,
     244,   246,   248,   247,   249,    31,   250,   252,   254,   253,
     255,     0,     0,   348,     0,   347,   333,   331,    32,     0,
      36,     0,   337,   355,   357,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,   206,
       0,     0,     0,     0,     4,     8,    87,    93,     0,     0,
       0,    86,   368,   378,   371,   381,   375,   386,    88,   224,
     229,   230,     0,     0,     0,     0,     0,   367,     0,     0,
       0,     0,   161,   162,     0,     0,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,   160,   154,   156,   158,   155,   157,   153,
     100,     0,     0,   131,   133,   135,   132,   134,   130,   150,
     146,   145,   147,   148,   149,   220,   221,     0,   218,     0,
       0,     0,   368,   264,   297,     0,     0,   368,   378,   210,
     211,     0,     0,     0,   354,   352,     0,     0,    33,    34,
     341,     0,   339,   345,     0,    38,     0,     0,     0,     0,
     281,   280,     0,   278,     0,    79,    80,    82,    81,    83,
      85,     0,     0,     0,    46,    49,    60,    43,     7,     8,
     313,     0,   372,   382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   139,   140,     0,     0,
       0,   177,   178,   179,   174,   175,   173,   176,     0,     0,
       0,     0,     0,   110,   111,     0,   198,     0,   136,   202,
     203,   163,   164,   165,   166,   167,     0,   168,   170,     0,
     171,     0,   106,   109,   184,   185,   183,   190,   121,   122,
       0,     0,   116,     0,     0,   118,     0,   114,   112,   113,
       0,     0,   128,   126,     0,    63,    65,   237,   378,     0,
       8,   305,     0,   304,   292,   293,   291,   372,   382,   245,
     251,   349,   332,   336,   334,     0,     0,     0,   338,   326,
     328,   327,   329,   366,   366,   282,    75,    77,   279,     0,
       0,    70,     0,    73,     0,     0,     0,     0,     0,   309,
     314,   316,   376,   387,     0,     0,     0,   374,   385,   256,
       0,     0,     0,   205,   124,   368,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   377,     0,   238,
     240,   242,   241,   243,     0,     0,   306,   294,     0,   342,
     343,   340,   361,   366,     0,     0,   366,   285,    76,    67,
      71,     0,    72,     0,     0,     0,     0,    47,    50,   322,
       0,   370,   380,     0,   257,   259,   261,   260,   262,   191,
     192,   193,     0,     0,   141,   142,   181,   182,   102,   103,
       0,   105,   199,     0,   200,   169,   172,     0,   107,     0,
     195,   115,     0,   197,   117,   137,     0,   186,     0,   188,
       0,   233,     0,     0,   299,   300,   298,   307,   335,     0,
     356,     0,   359,   362,   364,   363,   365,   358,   283,     0,
       0,    74,     0,     0,     0,     0,     0,   320,   383,     0,
     225,     0,     0,     0,     0,     0,     0,     0,   239,     0,
     378,   272,   301,   344,   360,     0,   286,   276,    91,    92,
       0,    90,     0,     8,   310,   258,     8,   104,   201,   108,
     194,   196,   187,   189,     0,     0,   265,   284,   287,   277,
       0,   323,   321,     0,     0,   234,   273,     8,     8,    89,
       8,   317,   318,   311,   228,   227,   226,   266,   288,   324,
       0,   322,   268,   269,   270,   325,   267,   271
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  parser::yypgoto_[] =
  {
      -601,  -601,  -601,  -201,  -601,   386,  -367,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,   122,  -601,    52,
    -601,   407,  -601,   733,   736,   -78,  1102,  -601,  -601,  1738,
    -601,  -601,   538,  -219,  -601,  -601,   -12,  -601,    44,  -601,
      80,  -601,  -300,   166,  -601,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,    12,  -601,   282,
    -601,   285,  -601,   -16,  -601,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -356,   -30,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
    -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,  -601,
     -75,  -601,  -601,  -600,  -601,   428,  -601,  -601,  -601,  -601,
    -601,  -601,   612,  -601,  -601,  -564,  -601,  -601,   147,  -405,
     743,     0,   444,  1271,   639,   875,  -601,  -225
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  parser::yydefgoto_[] =
  {
        -1,    44,    45,    46,   365,    47,    48,   176,   177,   184,
     342,   156,   157,   300,   301,   346,   630,   631,   632,   633,
     189,   190,   195,    49,    50,   353,   158,   135,   386,   201,
     452,   451,   389,   390,   137,   385,   202,   172,   138,    52,
     139,    54,   467,   468,    55,    74,   221,   528,   806,   836,
     379,    56,   151,   470,   789,   303,   678,   679,   319,   320,
     325,   326,   713,   714,    57,   160,   599,   827,   840,   844,
     846,   816,    58,   187,   345,   819,   504,   502,   697,   795,
     770,   818,   828,    59,   163,   313,   606,   687,    60,   161,
     311,   600,   756,   792,    61,   162,   312,   603,   757,    62,
     368,   709,   823,    63,   369,   640,   370,   833,    64,   804,
     777,   830,   841,   618,   338,   340,   341,   617,   615,   759,
     494,   183,   308,   180,   178,    65,   497,   499,   693,   694,
     695,   140,   141,    68,   142,   143,   644,    71
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int parser::yytable_ninf_ = -316;
  const short int
  parser::yytable_[] =
  {
        66,   469,   520,   393,   393,   285,   286,   146,   364,   214,
     395,   153,   154,   155,   521,   689,   333,   691,   152,   285,
     286,   293,   168,   173,   348,   503,   179,   181,   203,   204,
     205,   626,   627,   188,   191,   196,   490,    72,   152,   626,
     627,   210,   284,   628,    51,   285,   286,   349,   626,   627,
     550,   182,   287,   288,   289,   290,   291,   292,   293,   692,
     692,   604,  -214,   581,   152,   582,   287,   288,   289,   290,
     291,   292,   293,   831,   605,   164,   165,   214,   842,   210,
      53,   215,   210,   628,   843,   532,   533,   296,   297,   298,
     834,   832,   287,   288,   289,   290,   291,   292,   293,   601,
     473,   699,   835,    73,   278,   279,   280,   281,   282,   283,
     602,   475,   476,   278,   279,   280,   281,   282,   283,   284,
     357,   358,   294,   295,   296,   297,   298,   551,   584,   692,
     585,   566,   692,   567,   216,   316,   294,   295,   296,   297,
     298,   623,    31,   624,   146,   569,   625,   570,   334,   316,
     149,   304,   701,   629,   641,    36,    37,    38,   216,   793,
     310,   629,   294,   295,   296,   297,   298,   150,   491,   185,
     629,   571,   306,   572,   197,   284,   321,   327,   290,   291,
     292,   293,   335,   555,   284,   556,   343,   433,   210,   435,
     208,   209,   284,   284,   442,   164,   171,   354,   354,   354,
     733,   737,   734,   738,   284,   284,   146,   210,   754,    66,
     284,   284,   146,   746,   442,   747,   284,   755,   146,   552,
     517,   380,   284,   284,   645,   646,   553,   284,   391,   391,
     580,   583,   412,   413,   414,   415,   284,   554,   198,   146,
     146,   146,   146,   146,   586,   294,   295,   296,   297,   298,
     164,   165,   288,    51,   290,   291,   292,   293,   146,   146,
     146,   146,   293,   146,   146,   354,   146,   354,   146,   146,
     146,   146,   146,   146,   152,   302,   702,   284,   146,   146,
     146,   146,   146,   146,   146,   748,   207,   749,   761,    53,
     594,   761,   595,   284,    76,     1,     2,   278,   279,   280,
     281,   282,   283,   574,   284,   284,   284,   372,   373,    82,
     284,   284,    66,    66,   575,   576,   577,   173,   639,   590,
     579,   294,   295,   296,   297,   298,   294,   295,   296,   297,
     298,   484,   485,   284,   284,   285,   286,   284,   762,   492,
     199,   146,   591,   587,   710,   637,   217,   191,   506,   507,
     508,   509,   510,   284,   206,   393,    51,    51,   393,   211,
     146,   669,   219,   588,   671,    66,   374,   375,   284,    66,
     292,   293,   683,   488,   489,    94,    95,    96,    97,    98,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   594,
     284,   596,    53,    53,   212,   111,   112,   284,   218,   685,
     589,   117,   118,   119,   120,   794,   122,   732,   124,    51,
     126,   127,   128,    51,   594,   594,   653,   654,   594,   220,
     711,   285,   286,  -217,   718,   144,   222,   287,   288,   289,
     290,   291,   292,   293,   284,   294,   295,   296,   297,   298,
     284,   594,   339,   712,    67,    53,   291,   292,   293,    53,
     741,   147,   294,   295,   296,   297,   298,   739,   742,   740,
     743,   705,   750,   706,   751,   284,   169,   174,   287,   288,
     289,   290,   291,   292,   293,   744,   284,   223,   192,   284,
     284,   284,   321,   327,   225,   284,   745,   146,   215,   808,
     809,   810,   376,   377,   619,   811,   216,   294,   295,   296,
     297,   298,   594,   779,   778,   780,   730,   306,   731,   387,
     388,   226,   294,   295,   296,   297,   298,   477,   478,    66,
     227,    66,   477,   481,   228,   683,   472,   598,   655,   656,
     387,   677,    31,   760,    31,   767,   655,   790,   294,   295,
     296,   297,   298,   768,   769,   229,   230,   231,   307,   443,
     232,   233,   234,   235,   718,   146,   236,   146,   237,   238,
     239,   240,   241,    51,   242,    51,   243,   244,   245,   246,
     247,   146,   248,   249,   250,   251,   252,   253,   254,   317,
     391,   146,   255,   391,   146,   256,   146,   257,   147,   258,
     146,   146,   259,   260,   261,   262,   263,   680,   264,    53,
      66,    53,   822,   318,   265,   824,   288,   289,   290,   291,
     292,   293,   266,   267,   268,   619,   269,   619,   270,   271,
     322,   328,   164,   272,   273,   314,   837,   838,   315,   839,
     344,   331,   332,   347,   350,   351,   352,   146,   146,    69,
     360,   147,   147,   147,    51,   361,   293,   362,   471,   715,
     147,   472,   503,    67,   482,   536,   147,   519,   316,   496,
     498,    69,   147,   483,   511,   477,   512,   513,   374,   522,
     523,   524,   525,   193,   526,   294,   295,   296,   297,   298,
      53,   527,   534,   147,   147,   147,   147,   147,   146,   535,
     538,   537,   558,   539,   540,   763,   557,   559,   628,   560,
     597,   607,   147,   147,   147,   147,   608,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   642,   643,
     647,   649,   147,   147,   147,   147,   147,   147,   147,   648,
     698,   722,   723,   146,   752,   772,   773,   146,   775,   146,
     776,   796,   146,   797,   803,   285,   286,   814,   820,   825,
     680,   518,   700,   771,   505,   166,    67,    67,   167,   619,
     676,   479,   788,   805,   609,   817,   845,   394,   610,   309,
     495,   696,   146,   146,   186,   146,     0,     0,     0,   715,
       0,     0,     0,     0,     0,   147,     0,     0,     0,     0,
     305,   192,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,    66,   147,     0,    66,     0,     0,    67,
       0,     0,     0,    67,     0,   323,   329,     0,     0,     0,
     146,     0,     0,     0,     0,     0,     0,    66,    66,   285,
      66,     0,     0,     0,     0,     0,   355,   355,   355,     0,
     285,   286,     0,     0,   847,     0,     0,    51,    69,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     381,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,    51,    51,   541,    51,    70,   287,   288,   289,   290,
     291,   292,   293,    53,     0,     0,    53,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,   170,   175,     0,
       0,     0,     0,     0,   355,     0,   355,    53,    53,   194,
      53,   287,   288,   289,   290,   291,   292,   293,     0,     0,
       0,     0,   285,   286,     0,     0,   322,   328,     0,     0,
       0,   147,     0,     0,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,     0,     0,   294,   295,   296,   297,
     298,    69,    69,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,    67,     0,    67,     0,     0,   542,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,   294,   295,   296,   297,   298,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   147,
       0,   147,     0,     0,    69,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,   147,     0,   285,   286,     0,
       0,     0,     0,     0,     0,   147,     0,     0,   147,     0,
     147,     0,     0,     0,   147,   147,     0,     0,     0,   294,
     295,   296,   297,   298,    67,   285,   286,     0,     0,     0,
     543,   324,   330,     0,     0,     0,     0,     0,     0,   620,
       0,   620,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,   356,   356,   356,     0,   285,   286,     0,     0,
       0,   147,   147,     0,    70,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   145,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   323,   329,   287,   288,   289,   290,   291,   292,   293,
       0,     0,   147,   621,   294,   295,   296,   297,   298,   764,
     356,     0,   356,     0,     0,   544,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      69,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,     0,   545,     0,     0,     0,   147,   285,   286,
       0,   147,     0,   147,     0,     0,   147,    70,    70,     0,
       0,     0,   480,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,   620,   546,     0,     0,     0,     0,     0,
     285,   286,     0,     0,     0,     0,   147,   147,     0,   147,
       0,     0,   194,     0,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,     0,   276,   682,     0,     0,    69,
      70,     0,     0,     0,    70,     0,   299,    67,     0,     0,
      67,     0,     0,     0,   621,     0,   621,   287,   288,   289,
     290,   291,   292,   293,   147,     0,     0,     0,     0,     0,
       0,    67,    67,     0,    67,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   336,     0,     0,   717,     0,
       0,     0,     0,     0,     0,   294,   295,   296,   297,   298,
       0,     0,   285,   286,     0,     0,   547,     0,   363,     0,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
     378,     0,     0,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,     0,   765,     0,     0,     0,   561,     0,
       0,   406,   407,   408,   409,   410,   411,     0,     0,   287,
     288,   289,   290,   291,   292,   293,     0,   324,   330,     0,
     426,   427,   428,   429,     0,   431,   432,     0,   434,   622,
     436,   437,   438,   439,   440,   441,     0,     0,     0,     0,
     444,   445,   446,   447,   448,   449,   450,   285,   286,   682,
       0,     0,     0,     0,    70,     0,    70,     0,   621,     0,
       0,     0,   465,   465,     0,   285,   286,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,   717,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
     562,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,    69,   493,     0,    69,     0,   500,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,   514,     0,     0,     0,    69,    69,     0,    69,
       0,     0,     0,     0,     0,    70,     0,   148,     0,     0,
       0,     0,     0,   148,     0,     0,     0,   465,   465,   148,
     622,     0,   622,     0,     0,     0,     0,     0,     0,   392,
     392,     0,     0,     0,   294,   295,   296,   297,   298,     0,
     148,   148,   148,   148,   148,   563,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,   285,   286,   148,
     148,   148,   148,   564,   148,   148,     0,   148,     0,   148,
     148,   148,   148,   148,   148,     0,   285,   286,     0,   148,
     148,   148,   148,   148,   148,   148,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     766,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,   612,
       0,   613,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   465,   465,     0,     0,
       0,   148,     0,     0,   622,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,     0,   565,     0,   664,     0,   665,
     285,   286,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,   668,   568,   285,   286,     0,    70,     0,
       0,    70,     0,   670,     0,     0,   672,     0,   673,     0,
       0,     0,   674,   675,     0,     0,   465,     0,     0,     0,
       0,     0,    70,    70,     0,    70,     0,   287,   288,   289,
     290,   291,   292,   293,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   707,
     708,     0,     0,     0,   136,     0,   465,     0,     0,     0,
       0,     0,     0,     0,   159,     0,     0,     0,   148,     0,
       0,   285,   286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   294,   295,   296,
     297,   298,     0,     0,     0,     0,     0,     0,   573,     0,
     758,     0,   294,   295,   296,   297,   298,     0,     0,     0,
       0,     0,   213,   578,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,   224,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,   148,     0,
       0,     0,     0,     0,     0,   782,     0,     0,     0,   783,
       0,   784,   148,     0,   785,     0,     0,     0,     0,     0,
       0,   148,   148,     0,   148,   148,     0,   148,     0,     0,
       0,   148,   148,  -315,   285,   286,     0,     0,   681,   274,
     275,   277,     0,     0,   798,   799,     0,   801,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,     0,   611,
       0,     0,     0,     0,     0,     0,     0,   500,  -308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   148,
       0,   287,   288,   289,   290,   291,   292,   293,     0,     0,
     716,   337,   829,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   366,
       0,     0,   371,     0,     0,     0,     0,     0,     0,   148,
     382,   383,     0,   384,     0,     0,     0,     0,   396,   397,
     399,   400,   401,   402,   403,   404,   405,     0,     0,     0,
       0,   294,   295,   296,   297,   298,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,     0,     0,     0,     0,
     430,     0,     0,     0,   148,     0,     0,     0,   148,     0,
     148,     0,     0,   148,     0,     0,     0,     0,     0,     0,
       0,   681,     0,     0,     0,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,     0,   466,   466,
       0,     0,     0,   148,   148,     0,   148,     0,     0,   474,
     716,     0,     0,    75,    76,     1,     2,     0,    77,    78,
      79,    80,     0,   285,   286,     0,     0,     0,    81,    82,
       0,     0,   486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,     0,     0,     0,     0,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,     0,   515,
     516,    83,    84,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,   466,   466,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   100,     0,   101,   102,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,     0,     0,
     294,   295,   296,   297,   298,   133,     0,   200,     0,   592,
     593,   690,     0,     0,   285,   286,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   285,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   614,     0,   616,
       0,     0,   285,   286,     0,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,   291,   292,   293,     0,   634,
     635,   636,     0,   287,   288,   289,   290,   291,   292,   293,
       0,     0,   466,   466,     0,     0,     0,   650,   651,   652,
       0,     0,     0,     0,     0,     0,     0,   657,   658,   287,
     288,   289,   290,   291,   292,   293,   659,   660,   661,   662,
     663,     0,     0,     0,    75,    76,     1,     2,     0,    77,
      78,    79,    80,     0,   666,     0,     0,   667,     0,    81,
      82,   294,   295,   296,   297,   298,     0,     0,     0,     0,
       0,     0,   703,   294,   295,   296,   297,   298,     0,     0,
       0,     0,   466,     0,   704,     0,     0,   684,     0,     0,
     686,     0,    83,    84,     0,     0,     0,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
     719,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   466,   100,     0,   101,   102,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,     0,
       0,     0,   285,   286,     0,     0,   133,   398,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   774,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   781,   287,
     288,   289,   290,   291,   292,   293,     0,     0,     0,     0,
       0,     0,     0,     0,   786,     0,   787,    75,    76,     1,
       2,   791,    77,    78,    79,    80,     0,     0,     0,     0,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   802,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,     0,    83,    84,     0,     0,   294,
     295,   296,   297,   298,     0,     0,     0,     0,     0,     0,
     720,     0,     0,   826,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100,     0,   101,   102,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   285,   286,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,   285,   286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   285,   286,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   285,   286,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,   285,   286,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   294,   295,
     296,   297,   298,     0,     0,     0,     0,     0,     0,   721,
     294,   295,   296,   297,   298,     0,     0,   285,   286,     0,
       0,   724,   294,   295,   296,   297,   298,     0,     0,   285,
     286,     0,     0,   725,   294,   295,   296,   297,   298,     0,
       0,   285,   286,     0,     0,   726,     0,     0,     0,     0,
       0,     0,   294,   295,   296,   297,   298,   285,   286,     0,
       0,     0,     0,   727,   287,   288,   289,   290,   291,   292,
     293,   285,   286,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,     0,     0,   728,   294,   295,   296,   297,
     298,     0,     0,   285,   286,     0,     0,   729,   294,   295,
     296,   297,   298,     0,     0,   285,   286,     0,     0,   735,
       0,     0,     0,     0,   294,   295,   296,   297,   298,   285,
     286,     0,     0,     0,     0,   736,     0,     0,   294,   295,
     296,   297,   298,   285,   286,     0,     0,     0,     0,   800,
     287,   288,   289,   290,   291,   292,   293,   285,   286,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,   287,   288,   289,   290,   291,   292,
     293,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,   295,   296,   297,   298,     0,     0,     0,     0,     0,
       0,   807,   294,   295,   296,   297,   298,   285,   286,     0,
       0,     0,     0,   812,     0,     0,   294,   295,   296,   297,
     298,   285,   286,     0,     0,     0,     0,   813,     0,     0,
     294,   295,   296,   297,   298,   285,   286,     0,     0,   529,
       0,     0,     0,     0,   294,   295,   296,   297,   298,   285,
     286,     0,     0,   530,   287,   288,   289,   290,   291,   292,
     293,   285,   286,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,     0,     0,
       0,     0,   287,   288,   289,   290,   291,   292,   293,     0,
       0,     0,     0,     0,     0,     0,   287,   288,   289,   290,
     291,   292,   293,     0,     0,     0,     0,     0,   287,   288,
     289,   290,   291,   292,   293,     0,     0,     0,   487,     0,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,     0,     0,   531,     0,     0,   285,   286,   294,   295,
     296,   297,   298,     0,     0,     0,     0,   548,   285,   286,
       0,     0,   294,   295,   296,   297,   298,   285,   286,     0,
       0,   549,     0,     0,   285,   286,   294,   295,   296,   297,
     298,     0,   753,   285,   286,   638,     0,     0,   294,   295,
     296,   297,   298,   287,   288,   289,   290,   291,   292,   293,
     815,   821,     0,   688,     0,   287,   288,   289,   290,   291,
     292,   293,     0,     0,   287,   288,   289,   290,   291,   292,
     293,   287,   288,   289,   290,   291,   292,   293,     0,     0,
     287,   288,   289,   290,   291,   292,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,   298,     0,     0,
       0,     0,     0,     0,     0,   294,   295,   296,   297,   298,
       0,     0,     0,     0,   294,   295,   296,   297,   298,     0,
       0,   294,   295,   296,   297,   298,     0,     0,     0,     0,
     294,   295,   296,   297,   298,     1,     2,   628,     0,     0,
       0,     0,     3,     4,     5,     0,     6,     7,     8,     9,
      10,     0,    11,    12,    13,    14,    15,     0,     0,    16,
       0,    17,     0,     0,     0,    18,     0,    19,     0,    20,
       0,    21,     0,     0,     0,     0,     0,    22,    23,    24,
      25,     0,     0,    26,    27,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,     0,    31,     0,    32,     0,
       0,     0,    33,     0,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,    38,     0,     0,
      39,    40,     0,    41,     1,     2,    42,     0,     0,     0,
       0,     3,     4,     5,     0,     6,     7,     8,     9,    10,
      43,    11,    12,    13,    14,    15,     0,     0,    16,     0,
      17,     0,     0,     0,    18,     0,    19,     0,    20,     0,
      21,     0,     0,     0,     0,     0,    22,    23,    24,    25,
       0,     0,    26,    27,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,     0,    31,     0,    32,     0,     0,
       0,    33,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,     0,     0,    39,
      40,     0,    41,     0,     0,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43
  };

  /* YYCHECK.  */
  const short int
  parser::yycheck_[] =
  {
         0,   301,   369,   228,   229,     8,     9,     7,   209,    60,
     229,    11,    12,    13,   370,   615,     3,   617,     5,     8,
       9,    61,    22,    23,    21,     7,    26,    27,    40,    41,
      42,     3,     4,    33,    34,    35,     3,   135,     5,     3,
       4,     7,   126,     7,     0,     8,     9,    21,     3,     4,
     134,   137,    55,    56,    57,    58,    59,    60,    61,   623,
     624,    27,    60,   134,     5,   136,    55,    56,    57,    58,
      59,    60,    61,    27,    40,     5,     6,    60,    27,     7,
       0,   132,     7,     7,    33,   385,   386,   127,   128,   129,
      15,    45,    55,    56,    57,    58,    59,    60,    61,    27,
      60,    73,    27,   135,    55,    56,    57,    58,    59,    60,
      38,   312,   313,    55,    56,    57,    58,    59,    60,   126,
     198,   199,   125,   126,   127,   128,   129,   134,   134,   693,
     136,   134,   696,   136,   132,   132,   125,   126,   127,   128,
     129,   497,    66,   499,   144,   134,   502,   136,   135,   132,
     135,   151,   134,   125,   521,    85,    86,    87,   132,   759,
     160,   125,   125,   126,   127,   128,   129,   135,   135,    63,
     125,   134,   132,   136,   135,   126,   176,   177,    58,    59,
      60,    61,   182,   134,   126,   136,   186,   265,     7,   267,
      27,    28,   126,   126,   136,     5,     6,   197,   198,   199,
     134,   134,   136,   136,   126,   126,   206,     7,    27,   209,
     126,   126,   212,   134,   136,   136,   126,    36,   218,   134,
     136,   221,   126,   126,   524,   525,   136,   126,   228,   229,
     134,   134,   244,   245,   246,   247,   126,   136,   135,   239,
     240,   241,   242,   243,   134,   125,   126,   127,   128,   129,
       5,     6,    56,   209,    58,    59,    60,    61,   258,   259,
     260,   261,    61,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,     5,     6,   632,   126,   278,   279,
     280,   281,   282,   283,   284,   134,     0,   136,   693,   209,
     134,   696,   136,   126,     4,     5,     6,    55,    56,    57,
      58,    59,    60,   136,   126,   126,   126,     5,     6,    19,
     126,   126,   312,   313,   136,   136,   136,   317,   519,   134,
     136,   125,   126,   127,   128,   129,   125,   126,   127,   128,
     129,   331,   332,   126,   126,     8,     9,   126,   694,   339,
     135,   341,   134,   136,   644,   134,   132,   347,   348,   349,
     350,   351,   352,   126,   135,   580,   312,   313,   583,    60,
     360,   580,   136,   136,   583,   365,     5,     6,   126,   369,
      60,    61,   597,   133,   134,    85,    86,    87,    88,    89,
       8,     9,    55,    56,    57,    58,    59,    60,    61,   134,
     126,   136,   312,   313,    60,   105,   106,   126,    60,   600,
     136,   111,   112,   113,   114,   761,   116,   136,   118,   365,
     120,   121,   122,   369,   134,   134,   136,   136,   134,   136,
     136,     8,     9,    60,   649,   135,   135,    55,    56,    57,
      58,    59,    60,    61,   126,   125,   126,   127,   128,   129,
     126,   134,   137,   136,     0,   365,    59,    60,    61,   369,
     136,     7,   125,   126,   127,   128,   129,   134,   134,   136,
     136,   134,   134,   136,   136,   126,    22,    23,    55,    56,
      57,    58,    59,    60,    61,   136,   126,   135,    34,   126,
     126,   126,   482,   483,   135,   126,   136,   487,   132,   136,
     136,   136,     5,     6,   494,   136,   132,   125,   126,   127,
     128,   129,   134,   134,   136,   136,   134,   132,   136,     5,
       6,   135,   125,   126,   127,   128,   129,     5,     6,   519,
     135,   521,     5,     6,   135,   750,     5,     6,     5,     6,
       5,     6,    66,    67,    66,    67,     5,     6,   125,   126,
     127,   128,   129,    70,    71,   135,   135,   135,    30,   136,
     135,   135,   135,   135,   779,   555,   135,   557,   135,   135,
     135,   135,   135,   519,   135,   521,   135,   135,   135,   135,
     135,   571,   135,   135,   135,   135,   135,   135,   135,   134,
     580,   581,   135,   583,   584,   135,   586,   135,   144,   135,
     590,   591,   135,   135,   135,   135,   135,   597,   135,   519,
     600,   521,   803,   132,   135,   806,    56,    57,    58,    59,
      60,    61,   135,   135,   135,   615,   135,   617,   135,   135,
     176,   177,     5,   135,   135,   135,   827,   828,   135,   830,
     186,   134,   134,   134,    21,    21,   134,   637,   638,     0,
     134,   197,   198,   199,   600,   134,    61,   134,   132,   649,
     206,     5,     7,   209,   134,   136,   212,    42,   132,   132,
     132,    22,   218,   134,   134,     5,   134,   134,     5,   135,
     135,   135,   135,    34,   135,   125,   126,   127,   128,   129,
     600,   135,   135,   239,   240,   241,   242,   243,   688,   135,
     132,   136,   136,   134,   134,   695,   134,   136,     7,   136,
     135,   135,   258,   259,   260,   261,   135,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   136,   136,
     136,   135,   278,   279,   280,   281,   282,   283,   284,   136,
       3,   135,   135,   733,   132,    60,    60,   737,    60,   739,
      44,     7,   742,    69,    43,     8,     9,    21,    60,     4,
     750,   365,   630,   701,   347,    22,   312,   313,    22,   759,
     594,   317,   750,   779,   482,   795,   841,   229,   483,   157,
     342,   624,   772,   773,    31,   775,    -1,    -1,    -1,   779,
      -1,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,
     151,   347,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,   803,   360,    -1,   806,    -1,    -1,   365,
      -1,    -1,    -1,   369,    -1,   176,   177,    -1,    -1,    -1,
     820,    -1,    -1,    -1,    -1,    -1,    -1,   827,   828,     8,
     830,    -1,    -1,    -1,    -1,    -1,   197,   198,   199,    -1,
       8,     9,    -1,    -1,   844,    -1,    -1,   803,   209,    -1,
     806,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,    -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,   827,   828,   136,   830,     0,    55,    56,    57,    58,
      59,    60,    61,   803,    -1,    -1,   806,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    -1,   265,    -1,   267,   827,   828,    34,
     830,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,   482,   483,    -1,    -1,
      -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,   494,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,
     129,   312,   313,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,   519,    -1,   521,    -1,    -1,   136,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,   129,   347,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,
      -1,   557,    -1,    -1,   365,    -1,    -1,    -1,   369,    -1,
      -1,    -1,    -1,    -1,    -1,   571,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,   584,    -1,
     586,    -1,    -1,    -1,   590,   591,    -1,    -1,    -1,   125,
     126,   127,   128,   129,   600,     8,     9,    -1,    -1,    -1,
     136,   176,   177,    -1,    -1,    -1,    -1,    -1,    -1,   615,
      -1,   617,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,   197,   198,   199,    -1,     8,     9,    -1,    -1,
      -1,   637,   638,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   482,   483,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,   688,   494,   125,   126,   127,   128,   129,   695,
     265,    -1,   267,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   519,    -1,
     521,    -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   733,     8,     9,
      -1,   737,    -1,   739,    -1,    -1,   742,   312,   313,    -1,
      -1,    -1,   317,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   759,   136,    -1,    -1,    -1,    -1,    -1,
       8,     9,    -1,    -1,    -1,    -1,   772,   773,    -1,   775,
      -1,    -1,   347,    -1,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,   133,   597,    -1,    -1,   600,
     365,    -1,    -1,    -1,   369,    -1,   144,   803,    -1,    -1,
     806,    -1,    -1,    -1,   615,    -1,   617,    55,    56,    57,
      58,    59,    60,    61,   820,    -1,    -1,    -1,    -1,    -1,
      -1,   827,   828,    -1,   830,    -1,    -1,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,   183,    -1,    -1,   649,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,     8,     9,    -1,    -1,   136,    -1,   206,    -1,
      -1,    -1,    -1,    -1,   212,    -1,    -1,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,   695,    -1,    -1,    -1,   136,    -1,
      -1,   239,   240,   241,   242,   243,   244,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    -1,   482,   483,    -1,
     258,   259,   260,   261,    -1,   263,   264,    -1,   266,   494,
     268,   269,   270,   271,   272,   273,    -1,    -1,    -1,    -1,
     278,   279,   280,   281,   282,   283,   284,     8,     9,   750,
      -1,    -1,    -1,    -1,   519,    -1,   521,    -1,   759,    -1,
      -1,    -1,   300,   301,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,    -1,    -1,   779,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,   803,   341,    -1,   806,    -1,   345,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,   360,    -1,    -1,    -1,   827,   828,    -1,   830,
      -1,    -1,    -1,    -1,    -1,   600,    -1,   206,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,   385,   386,   218,
     615,    -1,   617,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     229,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
     239,   240,   241,   242,   243,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,     8,     9,   258,
     259,   260,   261,   136,   263,   264,    -1,   266,    -1,   268,
     269,   270,   271,   272,   273,    -1,     8,     9,    -1,   278,
     279,   280,   281,   282,   283,   284,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     695,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,
      -1,   489,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   524,   525,    -1,    -1,
      -1,   360,    -1,    -1,   759,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   555,    -1,   557,
       8,     9,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   571,   136,     8,     9,    -1,   803,    -1,
      -1,   806,    -1,   581,    -1,    -1,   584,    -1,   586,    -1,
      -1,    -1,   590,   591,    -1,    -1,   594,    -1,    -1,    -1,
      -1,    -1,   827,   828,    -1,   830,    -1,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   637,
     638,    -1,    -1,    -1,     6,    -1,   644,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,   487,    -1,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     688,    -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,    -1,    64,   136,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   555,    -1,   557,    -1,
      -1,    -1,    -1,    -1,    -1,   733,    -1,    -1,    -1,   737,
      -1,   739,   571,    -1,   742,    -1,    -1,    -1,    -1,    -1,
      -1,   580,   581,    -1,   583,   584,    -1,   586,    -1,    -1,
      -1,   590,   591,     7,     8,     9,    -1,    -1,   597,   131,
     132,   133,    -1,    -1,   772,   773,    -1,   775,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   795,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   637,   638,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
     649,   183,   820,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   211,
      -1,    -1,   214,    -1,    -1,    -1,    -1,    -1,    -1,   688,
     222,   223,    -1,   225,    -1,    -1,    -1,    -1,   230,   231,
     232,   233,   234,   235,   236,   237,   238,    -1,    -1,    -1,
      -1,   125,   126,   127,   128,   129,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
     262,    -1,    -1,    -1,   733,    -1,    -1,    -1,   737,    -1,
     739,    -1,    -1,   742,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   750,    -1,    -1,    -1,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    -1,   300,   301,
      -1,    -1,    -1,   772,   773,    -1,   775,    -1,    -1,   311,
     779,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,     8,     9,    -1,    -1,    -1,    18,    19,
      -1,    -1,   334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   820,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   361,
     362,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,   385,   386,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    -1,    92,    -1,    94,    95,    -1,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    -1,    -1,    -1,
     125,   126,   127,   128,   129,   135,    -1,   137,    -1,   451,
     452,   136,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   489,    -1,   491,
      -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    57,    58,    59,    60,    61,    -1,   511,
     512,   513,    -1,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,   524,   525,    -1,    -1,    -1,   529,   530,   531,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,   540,    55,
      56,    57,    58,    59,    60,    61,   548,   549,   550,   551,
     552,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    -1,   566,    -1,    -1,   569,    -1,    18,
      19,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,   136,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,   594,    -1,   136,    -1,    -1,   599,    -1,    -1,
     602,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,   644,    92,    -1,    94,    95,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    -1,    -1,
      -1,    -1,     8,     9,    -1,    -1,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   705,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   730,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   746,    -1,   748,     3,     4,     5,
       6,   753,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   776,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   795,    -1,    51,    52,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,    -1,   815,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    -1,    92,    -1,    94,    95,
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,   135,
      -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,     8,     9,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,   136,
     125,   126,   127,   128,   129,    -1,    -1,     8,     9,    -1,
      -1,   136,   125,   126,   127,   128,   129,    -1,    -1,     8,
       9,    -1,    -1,   136,   125,   126,   127,   128,   129,    -1,
      -1,     8,     9,    -1,    -1,   136,    -1,    -1,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,     8,     9,    -1,
      -1,    -1,    -1,   136,    55,    56,    57,    58,    59,    60,
      61,     8,     9,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,   136,   125,   126,   127,   128,
     129,    -1,    -1,     8,     9,    -1,    -1,   136,   125,   126,
     127,   128,   129,    -1,    -1,     8,     9,    -1,    -1,   136,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,     8,
       9,    -1,    -1,    -1,    -1,   136,    -1,    -1,   125,   126,
     127,   128,   129,     8,     9,    -1,    -1,    -1,    -1,   136,
      55,    56,    57,    58,    59,    60,    61,     8,     9,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   125,   126,   127,   128,   129,     8,     9,    -1,
      -1,    -1,    -1,   136,    -1,    -1,   125,   126,   127,   128,
     129,     8,     9,    -1,    -1,    -1,    -1,   136,    -1,    -1,
     125,   126,   127,   128,   129,     8,     9,    -1,    -1,   134,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,     8,
       9,    -1,    -1,   134,    55,    56,    57,    58,    59,    60,
      61,     8,     9,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,   134,    -1,    -1,     8,     9,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,   134,     8,     9,
      -1,    -1,   125,   126,   127,   128,   129,     8,     9,    -1,
      -1,   134,    -1,    -1,     8,     9,   125,   126,   127,   128,
     129,    -1,    32,     8,     9,   134,    -1,    -1,   125,   126,
     127,   128,   129,    55,    56,    57,    58,    59,    60,    61,
      34,    42,    -1,    65,    -1,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
     125,   126,   127,   128,   129,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    26,    -1,    -1,    29,
      -1,    31,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    -1,    66,    -1,    68,    -1,
      -1,    -1,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,
      90,    91,    -1,    93,     5,     6,    96,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
     110,    22,    23,    24,    25,    26,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    64,    -1,    66,    -1,    68,    -1,    -1,
      -1,    72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,    90,
      91,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  parser::yystos_[] =
  {
         0,     5,     6,    12,    13,    14,    16,    17,    18,    19,
      20,    22,    23,    24,    25,    26,    29,    31,    35,    37,
      39,    41,    47,    48,    49,    50,    53,    54,    62,    63,
      64,    66,    68,    72,    74,    75,    85,    86,    87,    90,
      91,    93,    96,   110,   139,   140,   141,   143,   144,   161,
     162,   176,   177,   178,   179,   182,   189,   202,   210,   221,
     226,   232,   237,   241,   246,   263,   269,   270,   271,   272,
     273,   275,   135,   135,   183,     3,     4,     8,     9,    10,
      11,    18,    19,    51,    52,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      92,    94,    95,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   135,   164,   165,   167,   172,   176,   178,
     269,   270,   272,   273,   135,   164,   269,   270,   271,   135,
     135,   190,     5,   269,   269,   269,   149,   150,   164,   167,
     203,   227,   233,   222,     5,     6,   161,   162,   269,   270,
     273,     6,   175,   269,   270,   273,   145,   146,   262,   269,
     261,   269,   137,   259,   147,    63,   268,   211,   269,   158,
     159,   269,   270,   272,   273,   160,   269,   135,   135,   135,
     137,   167,   174,   174,   174,   174,   135,     0,    27,    28,
       7,    60,    60,   167,    60,   132,   132,   132,    60,   136,
     136,   184,   135,   135,   167,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   167,   167,   164,   167,    55,    56,
      57,    58,    59,    60,   126,     8,     9,    55,    56,    57,
      58,    59,    60,    61,   125,   126,   127,   128,   129,   164,
     151,   152,     6,   193,   269,   272,   132,    30,   260,   260,
     269,   228,   234,   223,   135,   135,   132,   134,   132,   196,
     197,   269,   270,   272,   273,   198,   199,   269,   270,   272,
     273,   134,   134,     3,   135,   269,   164,   167,   252,   137,
     253,   254,   148,   269,   270,   212,   153,   134,    21,    21,
      21,    21,   134,   163,   269,   272,   273,   163,   163,   167,
     134,   134,   134,   164,   141,   142,   167,   164,   238,   242,
     244,   167,     5,     6,     5,     6,     5,     6,   164,   188,
     269,   272,   167,   167,   167,   173,   166,     5,     6,   170,
     171,   269,   271,   275,   170,   171,   167,   167,   136,   167,
     167,   167,   167,   167,   167,   167,   164,   164,   164,   164,
     164,   164,   174,   174,   174,   174,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   164,   164,   164,   164,
     167,   164,   164,   163,   164,   163,   164,   164,   164,   164,
     164,   164,   136,   136,   164,   164,   164,   164,   164,   164,
     164,   169,   168,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   164,   167,   180,   181,   180,
     191,   132,     5,    60,   167,   141,   141,     5,     6,   270,
     273,     6,   134,   134,   269,   269,   167,    65,   133,   134,
       3,   135,   269,   164,   258,   253,   132,   264,   132,   265,
     164,   167,   215,     7,   214,   159,   269,   269,   269,   269,
     269,   134,   134,   134,   164,   167,   167,   136,   143,    42,
     144,   214,   135,   135,   135,   135,   135,   135,   185,   134,
     134,   134,   180,   180,   135,   135,   136,   136,   132,   134,
     134,   136,   136,   136,   136,   136,   136,   136,   134,   134,
     134,   134,   134,   136,   136,   134,   136,   134,   136,   136,
     136,   136,   136,   136,   136,   136,   134,   136,   136,   134,
     136,   134,   136,   136,   136,   136,   136,   136,   136,   136,
     134,   134,   136,   134,   134,   136,   134,   136,   136,   136,
     134,   134,   167,   167,   134,   136,   136,   135,     6,   204,
     229,    27,    38,   235,    27,    40,   224,   135,   135,   197,
     199,   136,   164,   164,   167,   256,   167,   255,   251,   269,
     270,   272,   273,   214,   214,   214,     3,     4,     7,   125,
     154,   155,   156,   157,   167,   167,   167,   134,   134,   141,
     243,   144,   136,   136,   274,   180,   180,   136,   136,   135,
     167,   167,   167,   136,   136,     5,     6,   167,   167,   167,
     167,   167,   167,   167,   164,   164,   167,   167,   164,   171,
     164,   171,   164,   164,   164,   164,   181,     6,   194,   195,
     269,   271,   272,   275,   167,   141,   167,   225,    65,   251,
     136,   251,   263,   266,   267,   268,   266,   216,     3,    73,
     155,   134,   214,   136,   136,   134,   136,   164,   164,   239,
     180,   136,   136,   200,   201,   269,   271,   272,   275,   136,
     136,   136,   135,   135,   136,   136,   136,   136,   136,   136,
     134,   136,   136,   134,   136,   136,   136,   134,   136,   134,
     136,   136,   134,   136,   136,   136,   134,   136,   134,   136,
     134,   136,   132,    32,    27,    36,   230,   236,   164,   257,
      67,   267,   214,   269,   270,   272,   273,    67,    70,    71,
     218,   157,    60,    60,   167,    60,    44,   248,   136,   134,
     136,   167,   164,   164,   164,   164,   167,   167,   195,   192,
       6,   167,   231,   251,   214,   217,     7,    69,   164,   164,
     136,   164,   167,    43,   247,   201,   186,   136,   136,   136,
     136,   136,   136,   136,    21,    34,   209,   215,   219,   213,
      60,    42,   141,   240,   141,     4,   167,   205,   220,   164,
     249,    27,    45,   245,    15,    27,   187,   141,   141,   141,
     206,   250,    27,    33,   207,   248,   208,   269
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
     375,   376,   377,   378,   379,    45,    43,    42,    47,   380,
     381,   382,    46,    59,    44,    40,    41,    35
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  parser::yyr1_[] =
  {
         0,   138,   139,   140,   140,   141,   142,   141,   143,   143,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   145,   144,
     146,   144,   144,   144,   144,   147,   144,   148,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   149,   144,   150,   144,   144,   144,   144,   144,   144,
     144,   144,   151,   144,   152,   144,   153,   144,   144,   144,
     154,   154,   155,   156,   156,   157,   157,   157,   158,   158,
     159,   159,   159,   159,   160,   160,   161,   161,   162,   162,
     162,   162,   162,   162,   163,   163,   164,   164,   164,   164,
     164,   164,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   166,   165,   168,   167,   169,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   170,   171,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   173,   172,   174,   174,   175,   175,
     175,   175,   176,   176,   177,   178,   178,   179,   180,   180,
     181,   181,   183,   184,   185,   186,   182,   187,   187,   188,
     188,   190,   191,   192,   189,   193,   193,   194,   194,   194,
     195,   195,   195,   195,   196,   196,   197,   197,   197,   197,
     198,   198,   199,   199,   199,   199,   200,   200,   200,   201,
     201,   201,   201,   203,   204,   205,   206,   202,   207,   207,
     208,   208,   209,   209,   211,   212,   213,   210,   214,   214,
     215,   215,   216,   217,   216,   218,   219,   220,   218,   222,
     223,   221,   224,   225,   224,   227,   228,   229,   226,   230,
     231,   230,   233,   234,   232,   235,   236,   235,   238,   239,
     240,   237,   242,   243,   241,   244,   241,   245,   245,   246,
     247,   247,   248,   249,   250,   248,   251,   251,   251,   251,
     252,   252,   252,   252,   252,   252,   252,   254,   253,   255,
     253,   256,   253,   257,   253,   258,   259,   259,   259,   259,
     260,   261,   261,   262,   262,   264,   263,   265,   263,   266,
     266,   267,   267,   267,   267,   267,   268,   269,   269,   270,
     270,   270,   270,   271,   271,   271,   271,   272,   272,   273,
     273,   273,   274,   273,   275,   275,   275,   275
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
       3,     3,     3,     3,     3,     3,     4,     6,     1,     4,
       4,     6,     6,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     1,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       3,     6,     6,     4,     4,     4,     6,     8,     6,     8,
       4,     6,     6,     6,     8,     6,     8,     6,     4,     6,
       6,     8,     4,     4,     0,     5,     2,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     0,     0,     0,     0,    11,     1,     1,     1,
       1,     0,     0,     0,    10,     1,     1,     0,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     0,     1,     3,     1,
       1,     1,     1,     0,     0,     0,     0,    14,     1,     1,
       0,     1,     0,     2,     0,     0,     0,     9,     1,     2,
       1,     1,     0,     0,     4,     0,     0,     0,     5,     0,
       0,     5,     1,     0,     2,     0,     0,     0,     7,     1,
       0,     2,     0,     0,     5,     1,     0,     3,     0,     0,
       0,    10,     0,     0,     5,     0,     5,     1,     1,     1,
       0,     2,     0,     0,     0,     7,     1,     1,     1,     1,
       0,     1,     3,     1,     3,     5,     3,     0,     3,     0,
       4,     0,     4,     0,     6,     1,     0,     2,     2,     4,
       1,     1,     3,     1,     3,     0,     7,     0,     7,     2,
       3,     1,     2,     2,     2,     2,     0,     1,     3,     2,
       6,     3,     4,     3,     5,     3,     5,     1,     3,     2,
       6,     3,     0,     7,     3,     5,     3,     5
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
  "tENDDATA", "tREAD", "tRESTORE", "tABS", "tSIG", "tRAN", "tSQR", "tSQRT",
  "tINT", "tFRAC", "tMIN", "tMAX", "tLEFT", "tRIGHT", "tMID", "tUPPER",
  "tLOWER", "tOPEN", "tCLOSE", "tEOF", "tSEEK", "tTELL", "tPEEK", "tPOKE",
  "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG",
  "tSTR", "tCHR", "tVAL", "tASC", "tLEN", "tSYSTEM", "tARG", "tENV",
  "tTIME", "tDATE", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB",
  "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR", "'-'", "'+'", "'*'",
  "'/'", "tMOD", "UPLUS", "UMINUS", "'.'", "';'", "','", "'('", "')'",
  "'#'", "$accept", "program", "list_of_statement_lists", "statement_list",
  "$@1", "statement", "non_empty_statement", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "data_list", "data_row",
  "data_row_items", "data_item", "read_list", "read_item", "restore_list",
  "number_assignment", "string_assignment", "string_scalar_or_array",
  "string_expression", "string_function", "$@11", "number_expression",
  "$@12", "$@13", "number_arrayref", "string_arrayref", "number_function",
  "$@14", "hashed_number", "dim_list",
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
       139,     0,    -1,   140,    27,    -1,   141,    -1,   140,    28,
     141,    -1,   143,    -1,    -1,   141,     7,   142,   143,    -1,
      -1,   144,    -1,   161,    -1,   162,    -1,    47,   161,    -1,
      47,   162,    -1,   237,    -1,   241,    -1,   221,    -1,   202,
      -1,   232,    -1,   226,    -1,   210,    -1,    12,    -1,    13,
      -1,   182,    -1,   189,    -1,   263,    -1,   176,    -1,   178,
      -1,    -1,    49,   145,   196,    -1,    -1,    50,   146,   198,
      -1,    62,   259,   252,    -1,    62,   259,   252,   133,    -1,
      62,   259,   252,   134,    -1,    -1,    63,   147,   253,    -1,
      -1,    64,    63,   148,   253,    -1,    16,    -1,    16,   167,
      -1,    16,   164,    -1,    48,   175,    -1,   110,   135,   164,
     136,    -1,    29,    -1,    29,   167,    -1,    90,   174,   134,
     164,    -1,    90,   174,   134,   164,   134,   164,    -1,    91,
     174,    -1,    93,   174,   134,   167,    -1,    93,   174,   134,
     167,   134,   164,    -1,    -1,    25,   149,   260,    -1,    -1,
      26,   150,   260,    -1,    54,   261,    -1,    53,   262,    -1,
      22,   269,    -1,    23,   269,    -1,    24,   269,    -1,    96,
     174,   134,   167,    -1,    17,   164,    -1,    -1,    18,   135,
     151,   180,   136,    -1,    -1,    19,   135,   152,   180,   136,
      -1,    -1,    72,   269,   153,   214,   154,    73,    -1,    74,
     158,    -1,    75,   160,    -1,   155,    -1,   154,   155,    -1,
     156,   214,    -1,   157,    -1,   156,   134,   157,    -1,     3,
      -1,   125,     3,    -1,     4,    -1,   159,    -1,   158,   134,
     159,    -1,   269,    21,   269,    -1,   272,    21,   269,    -1,
     270,    21,   269,    -1,   273,    21,   269,    -1,   269,    -1,
     160,   134,   269,    -1,   269,    60,   167,    -1,   177,    60,
     167,    -1,   272,    60,   164,    -1,    87,   135,   163,   134,
     167,   134,   167,   136,    60,   164,    -1,    87,   135,   163,
     134,   167,   136,    60,   164,    -1,    85,   135,   163,   134,
     167,   136,    60,   164,    -1,    86,   135,   163,   134,   167,
     136,    60,   164,    -1,   179,    60,   164,    -1,   272,    -1,
     273,    -1,   272,    -1,   165,    -1,   178,    -1,     4,    -1,
     164,   126,   164,    -1,   135,   164,   136,    -1,    85,   135,
     164,   134,   167,   136,    -1,    86,   135,   164,   134,   167,
     136,    -1,    87,   135,   164,   134,   167,   134,   167,   136,
      -1,    87,   135,   164,   134,   167,   136,    -1,   105,   135,
     167,   136,    -1,   105,   135,   167,   134,   164,   136,    -1,
     105,   135,   167,   134,   164,   134,   164,   136,    -1,   106,
     135,   167,   136,    -1,    88,   135,   164,   136,    -1,    89,
     135,   164,   136,    -1,   121,   135,   164,   136,    -1,   122,
     135,   164,   136,    -1,   120,   135,   164,   136,    -1,   116,
     135,   163,   134,   164,   136,    -1,   116,   135,   163,   136,
      -1,   118,   135,   163,   134,   164,   136,    -1,   118,   135,
     163,   136,    -1,   114,    -1,   113,    -1,   111,   135,   167,
     136,    -1,   112,   135,   164,   136,    -1,    -1,    19,   135,
     166,   180,   136,    -1,    -1,   167,     9,   168,   167,    -1,
      -1,   167,     8,   169,   167,    -1,    10,   167,    -1,   167,
      60,   167,    -1,   167,    55,   167,    -1,   167,    58,   167,
      -1,   167,    56,   167,    -1,   167,    59,   167,    -1,   167,
      57,   167,    -1,    92,   135,   174,   136,    -1,   119,   135,
     164,   134,   164,   136,    -1,     3,    -1,    51,   135,   170,
     136,    -1,    51,   135,   171,   136,    -1,    52,   135,   170,
     134,   167,   136,    -1,    52,   135,   171,   134,   167,   136,
      -1,   176,    -1,   269,    -1,   167,   126,   167,    -1,   167,
     125,   167,    -1,   167,   127,   167,    -1,   167,   128,   167,
      -1,   167,   129,   167,    -1,   167,    61,   167,    -1,   125,
     167,    -1,   126,   167,    -1,   164,    60,   164,    -1,   164,
      55,   164,    -1,   164,    58,   164,    -1,   164,    56,   164,
      -1,   164,    59,   164,    -1,   164,    57,   164,    -1,   172,
      -1,   135,   167,   136,    -1,   271,    -1,   275,    -1,    97,
     135,   167,   136,    -1,    98,   135,   167,   136,    -1,    99,
     135,   167,   136,    -1,   100,   135,   167,   136,    -1,   101,
     135,   167,   136,    -1,   102,   135,   167,   136,    -1,   102,
     135,   167,   134,   167,   136,    -1,   103,   135,   167,   136,
      -1,   104,   135,   167,   136,    -1,   104,   135,   167,   134,
     167,   136,    -1,    81,   135,   167,   136,    -1,    79,   135,
     167,   136,    -1,    80,   135,   167,   136,    -1,    82,   135,
     167,   136,    -1,    76,   135,   167,   136,    -1,    77,   135,
     167,   136,    -1,    78,   135,   167,   136,    -1,    78,   135,
     136,    -1,    83,   135,   167,   134,   167,   136,    -1,    84,
     135,   167,   134,   167,   136,    -1,   109,   135,   164,   136,
      -1,   107,   135,   164,   136,    -1,   108,   135,   164,   136,
      -1,   123,   135,   164,   134,   164,   136,    -1,   123,   135,
     164,   134,   164,   134,   167,   136,    -1,   124,   135,   164,
     134,   164,   136,    -1,   124,   135,   164,   134,   164,   134,
     167,   136,    -1,   110,   135,   164,   136,    -1,     8,   135,
     167,   134,   167,   136,    -1,     9,   135,   167,   134,   167,
     136,    -1,    11,   135,   167,   134,   167,   136,    -1,   115,
     135,   164,   134,   171,   134,   164,   136,    -1,   115,   135,
     164,   134,   171,   136,    -1,   117,   135,   164,   134,   171,
     134,   164,   136,    -1,   117,   135,   164,   134,   171,   136,
      -1,    90,   135,   164,   136,    -1,    90,   135,   164,   134,
     164,   136,    -1,    90,   135,   174,   134,   164,   136,    -1,
      90,   135,   174,   134,   164,   134,   164,   136,    -1,    94,
     135,   174,   136,    -1,    95,   135,   174,   136,    -1,    -1,
      18,   135,   173,   180,   136,    -1,   137,   167,    -1,   167,
      -1,   270,    -1,   273,    -1,   175,   134,   270,    -1,   175,
     134,   273,    -1,   270,    -1,   271,    -1,   270,    -1,   273,
      -1,   275,    -1,   273,    -1,   181,    -1,   180,   134,   181,
      -1,   164,    -1,   167,    -1,    -1,    -1,    -1,    -1,    14,
     183,   184,   188,   185,   135,   200,   136,   186,   141,   187,
      -1,    27,    -1,    15,    -1,   269,    -1,   272,    -1,    -1,
      -1,    -1,    20,   190,   193,   191,   135,   194,   136,   192,
      21,     4,    -1,   269,    -1,   272,    -1,    -1,   195,    -1,
     194,   134,   195,    -1,   269,    -1,   272,    -1,   271,    -1,
     275,    -1,   197,    -1,   196,   134,   197,    -1,   269,    -1,
     272,    -1,   270,    -1,   273,    -1,   199,    -1,   198,   134,
     199,    -1,   269,    -1,   272,    -1,   270,    -1,   273,    -1,
      -1,   201,    -1,   200,   134,   201,    -1,   269,    -1,   272,
      -1,   271,    -1,   275,    -1,    -1,    -1,    -1,    -1,    31,
     203,   269,    60,   204,   167,    32,   167,   209,   205,   141,
     206,   207,   208,    -1,    27,    -1,    33,    -1,    -1,   269,
      -1,    -1,    34,   167,    -1,    -1,    -1,    -1,    68,   211,
     212,   215,   214,   216,   218,    69,   213,    -1,     7,    -1,
     214,     7,    -1,   167,    -1,   164,    -1,    -1,    -1,   216,
      70,   217,   215,    -1,    -1,    -1,    -1,    71,     7,   219,
     220,   141,    -1,    -1,    -1,    39,   222,   223,   141,   224,
      -1,    27,    -1,    -1,    40,   225,    -1,    -1,    -1,    -1,
      35,   227,   228,   167,   229,   141,   230,    -1,    27,    -1,
      -1,    36,   231,    -1,    -1,    -1,    37,   233,   234,   141,
     235,    -1,    27,    -1,    -1,    38,   167,   236,    -1,    -1,
      -1,    -1,   246,   167,   238,    42,   141,   239,   248,   247,
     240,   245,    -1,    -1,    -1,   246,   167,   242,   144,   243,
      -1,    -1,   246,   167,   244,   214,   144,    -1,    27,    -1,
      45,    -1,    41,    -1,    -1,    43,   141,    -1,    -1,    -1,
      -1,    44,   167,    42,   249,   141,   250,   248,    -1,   269,
      -1,   272,    -1,   270,    -1,   273,    -1,    -1,   167,    -1,
     167,    65,   164,    -1,   164,    -1,   252,   134,   167,    -1,
     252,   134,   167,    65,   164,    -1,   252,   134,   164,    -1,
      -1,   254,   258,   251,    -1,    -1,   137,   269,   255,   251,
      -1,    -1,   137,     3,   256,   251,    -1,    -1,   137,   135,
     167,   136,   257,   251,    -1,   164,    -1,    -1,   137,   269,
      -1,   137,     3,    -1,   137,   135,   167,   136,    -1,    30,
      -1,   269,    -1,   261,   134,   269,    -1,   269,    -1,   262,
     134,   269,    -1,    -1,    66,   268,   269,   264,   214,   266,
      67,    -1,    -1,    66,   268,   270,   265,   214,   266,    67,
      -1,   267,   214,    -1,   266,   267,   214,    -1,   263,    -1,
     268,   269,    -1,   268,   272,    -1,   268,   270,    -1,   268,
     273,    -1,    -1,     5,    -1,   269,   132,     5,    -1,     5,
     135,    -1,   270,   132,     5,   135,   180,   136,    -1,   270,
     132,     5,    -1,   269,   132,     5,   135,    -1,     5,   135,
     136,    -1,   271,   132,     5,   135,   136,    -1,   271,   132,
       5,    -1,   269,   132,     5,   135,   136,    -1,     6,    -1,
     269,   132,     6,    -1,     6,   135,    -1,   270,   132,     6,
     135,   180,   136,    -1,   270,   132,     6,    -1,    -1,   269,
     132,     6,   135,   274,   180,   136,    -1,     6,   135,   136,
      -1,   271,   132,     6,   135,   136,    -1,   271,   132,     6,
      -1,   269,   132,     6,   135,   136,    -1
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
     469,   473,   477,   481,   485,   489,   493,   498,   505,   507,
     512,   517,   524,   531,   533,   535,   539,   543,   547,   551,
     555,   559,   562,   565,   569,   573,   577,   581,   585,   589,
     591,   595,   597,   599,   604,   609,   614,   619,   624,   629,
     636,   641,   646,   653,   658,   663,   668,   673,   678,   683,
     688,   692,   699,   706,   711,   716,   721,   728,   737,   744,
     753,   758,   765,   772,   779,   788,   795,   804,   811,   816,
     823,   830,   839,   844,   849,   850,   856,   859,   861,   863,
     865,   869,   873,   875,   877,   879,   881,   883,   885,   887,
     891,   893,   895,   896,   897,   898,   899,   911,   913,   915,
     917,   919,   920,   921,   922,   933,   935,   937,   938,   940,
     944,   946,   948,   950,   952,   954,   958,   960,   962,   964,
     966,   968,   972,   974,   976,   978,   980,   981,   983,   987,
     989,   991,   993,   995,   996,   997,   998,   999,  1014,  1016,
    1018,  1019,  1021,  1022,  1025,  1026,  1027,  1028,  1038,  1040,
    1043,  1045,  1047,  1048,  1049,  1054,  1055,  1056,  1057,  1063,
    1064,  1065,  1071,  1073,  1074,  1077,  1078,  1079,  1080,  1088,
    1090,  1091,  1094,  1095,  1096,  1102,  1104,  1105,  1109,  1110,
    1111,  1112,  1123,  1124,  1125,  1131,  1132,  1138,  1140,  1142,
    1144,  1145,  1148,  1149,  1150,  1151,  1159,  1161,  1163,  1165,
    1167,  1168,  1170,  1174,  1176,  1180,  1186,  1190,  1191,  1195,
    1196,  1201,  1202,  1207,  1208,  1215,  1217,  1218,  1221,  1224,
    1229,  1231,  1233,  1237,  1239,  1243,  1244,  1252,  1253,  1261,
    1264,  1268,  1270,  1273,  1276,  1279,  1282,  1283,  1285,  1289,
    1292,  1299,  1303,  1308,  1312,  1318,  1322,  1328,  1330,  1334,
    1337,  1344,  1348,  1349,  1357,  1361,  1367,  1371
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  parser::yyrline_[] =
  {
         0,   181,   181,   195,   196,   199,   200,   200,   209,   210,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   228,   234,   235,   236,   237,   238,   239,   239,
     240,   240,   241,   249,   254,   259,   259,   260,   260,   261,
     264,   269,   270,   271,   274,   275,   276,   277,   278,   279,
     280,   281,   281,   282,   282,   283,   284,   285,   288,   289,
     292,   293,   294,   294,   297,   297,   298,   298,   299,   300,
     303,   304,   307,   310,   311,   314,   315,   316,   319,   320,
     323,   324,   325,   326,   329,   330,   333,   334,   337,   338,
     339,   340,   341,   342,   347,   348,   351,   352,   353,   354,
     355,   356,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   380,   383,   383,   384,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   419,   422,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   466,   469,   470,   473,   474,
     475,   476,   479,   480,   483,   486,   487,   490,   493,   494,
     497,   498,   501,   501,   503,   506,   501,   515,   521,   524,
     527,   530,   533,   536,   530,   544,   550,   558,   559,   560,
     563,   566,   569,   572,   577,   578,   581,   582,   583,   584,
     587,   588,   591,   592,   593,   594,   597,   598,   599,   602,
     603,   606,   609,   614,   615,   619,   621,   614,   627,   632,
     635,   636,   639,   640,   643,   643,   645,   643,   650,   651,
     654,   655,   658,   659,   659,   667,   668,   668,   668,   674,
     674,   674,   679,   680,   680,   683,   683,   684,   683,   690,
     691,   691,   694,   694,   694,   699,   701,   700,   704,   705,
     707,   704,   711,   712,   711,   713,   713,   717,   718,   721,
     724,   725,   728,   730,   732,   729,   736,   737,   738,   739,
     742,   743,   748,   750,   752,   754,   756,   760,   760,   761,
     761,   762,   762,   763,   763,   766,   770,   775,   776,   777,
     780,   783,   784,   787,   788,   792,   792,   808,   808,   826,
     827,   830,   831,   839,   847,   855,   865,   873,   874,   877,
     879,   880,   881,   884,   887,   888,   889,   892,   893,   896,
     897,   898,   899,   899,   902,   903,   904,   905
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
       2,     2,     2,     2,     2,   137,     2,     2,     2,     2,
     135,   136,   127,   126,   134,   125,   132,   128,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   133,
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
     129,   130,   131
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int parser::yyeof_ = 0;
  const int parser::yylast_ = 3499;
  const int parser::yynnts_ = 138;
  const int parser::yyempty_ = -2;
  const int parser::yyfinal_ = 207;
  const int parser::yyterror_ = 1;
  const int parser::yyerrcode_ = 256;
  const int parser::yyntokens_ = 138;

  const unsigned int parser::yyuser_token_number_max_ = 382;
  const parser::token_number_type parser::yyundef_token_ = 2;

/* Line 1106 of lalr1.cc  */
#line 22 "parser.ypp"
} // qb
/* Line 1106 of lalr1.cc  */
#line 4274 "/home/cai/projects/basic/compiler/parser.cpp"
