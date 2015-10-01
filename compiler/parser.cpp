// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.
#line 24 "parser.ypp" // lalr1.cc:404


/* Include main header file. */
#include "qbc.h"
#include "ast.hpp"
#include "parser.hpp"

extern	StatementAST * program;

extern int yylex(qb::parser::semantic_type * yylval_param );

extern int yylineno;

//#define debug printf
#define debug(...)

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

void qb::parser::error(const std::string& msg)
{
	std::cerr << " at line " << yylineno << msg << std::endl ;
	exit(1);
}


#line 75 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hpp"

// User implementation prologue.

#line 89 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 21 "parser.ypp" // lalr1.cc:479
namespace qb {
#line 156 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:479

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
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
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

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
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 177 "parser.ypp" // lalr1.cc:859
    {
			if(useDefautSubMain){
				debug("program ended , no main()\n");
				program = new DefaultMainFunctionAST( (yystack_[1].value.codeblocks) );
			}else{
				program = (yystack_[1].value.codeblocks);
				debug("module ended\n");
			}
			YYACCEPT;
		}
#line 590 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 187 "parser.ypp" // lalr1.cc:859
    {

			debug("!!!no new line at the end of file!!!\n"); exit(1);
			if(useDefautSubMain){
				debug("program ended\n");
				program = new DefaultMainFunctionAST( (yystack_[2].value.codeblocks) );
			}else{
				program = (yystack_[2].value.codeblocks);
				debug("module ended\n");
			}
			YYACCEPT;
		}
#line 607 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 201 "parser.ypp" // lalr1.cc:859
    {
					(yylhs.value.codeblocks) = (yystack_[1].value.codeblocks);
					if(!(yystack_[1].value.codeblocks)){
						(yystack_[1].value.codeblocks) = (yylhs.value.codeblocks) = new CodeBlockAST;
					}
					if((yystack_[0].value.statement_list)){
						(yylhs.value.codeblocks)->addchild((yystack_[0].value.statement_list));
					}else{
					}
	}
#line 622 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 211 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.codeblocks) = 0;
		if((yystack_[0].value.statement_list)){
			(yylhs.value.codeblocks) = new CodeBlockAST; 	(yylhs.value.codeblocks)->addchild((yystack_[0].value.statement_list));
		}
	}
#line 633 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 218 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.statement_list)=(yystack_[1].value.statement_list);  }
#line 639 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 219 "parser.ypp" // lalr1.cc:859
    {
		if(!(yystack_[1].value.statement)){debug("statement nil\n");}
		(yylhs.value.statement_list) = new StatementsAST ; (yylhs.value.statement_list)->push_back(StatementASTPtr((yystack_[1].value.statement)));
	}
#line 648 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 223 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.statement_list) = 0;}
#line 654 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 224 "parser.ypp" // lalr1.cc:859
    {
			ExprStmtAST * callstmt =  new ExprStmtAST( (yystack_[1].value.expression) );
			(yylhs.value.statement_list) = new StatementsAST ;
			(yylhs.value.statement_list)->push_back( StatementASTPtr(callstmt)  );
	}
#line 664 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 231 "parser.ypp" // lalr1.cc:859
    {  (yylhs.value.statement_list) = (yystack_[2].value.statement_list); (yylhs.value.statement_list)->push_back(StatementASTPtr((yystack_[0].value.statement))); }
#line 670 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 232 "parser.ypp" // lalr1.cc:859
    {
				(yylhs.value.statement_list) = new StatementsAST ;
				(yylhs.value.statement_list)->push_back(StatementASTPtr((yystack_[2].value.statement)));
				(yylhs.value.statement_list)->push_back(StatementASTPtr((yystack_[0].value.statement)));
		}
#line 680 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 239 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.statement) = (yystack_[0].value.printstatement); }
#line 686 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 240 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.statement) = (yystack_[0].value.dim_item); }
#line 692 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 241 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.statement) = (yystack_[0].value.dim_item); }
#line 698 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 242 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.statement)= (yystack_[0].value.variable_assignment);}
#line 704 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 243 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.statement) = (yystack_[0].value.variable_assignment);}
#line 710 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 244 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.statement) = new ReturnAST((yystack_[0].value.expression));}
#line 716 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 245 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.statement)= (yystack_[0].value.if_clause);}
#line 722 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 246 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.statement)= (yystack_[0].value.while_loop);}
#line 728 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 247 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.statement)= (yystack_[0].value.for_loop);}
#line 734 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 248 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.statement)= (yystack_[0].value.function_definition);}
#line 740 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 249 "parser.ypp" // lalr1.cc:859
    {(yylhs.value.statement)= (yystack_[0].value.function_definition);}
#line 746 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 251 "parser.ypp" // lalr1.cc:859
    { /*TODO*/debug("here====3====\n"); exit(1);	}
#line 752 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 254 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.exprtype) = new ExprType (NumberExprTypeAST::GetNumberExprTypeAST());
	}
#line 760 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 257 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.exprtype) = new ExprType (StringExprTypeAST::GetStringExprTypeAST());
	}
#line 768 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 260 "parser.ypp" // lalr1.cc:859
    {
		debug("define as user type not supported\n");
		exit(1);
	}
#line 777 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 267 "parser.ypp" // lalr1.cc:859
    {

		(yystack_[0].value.expression_list)->Append( new EmptyExprAST );
		(yylhs.value.printstatement) = new PrintStmtAST( (yystack_[1].value.printinto), (yystack_[0].value.expression_list) );

		debug("got print1 done\n");
	}
#line 789 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 274 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.printstatement) = new PrintStmtAST( (yystack_[2].value.printinto), (yystack_[1].value.expression_list) );
	}
#line 797 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 277 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.printstatement) = new PrintStmtAST( (yystack_[2].value.printinto), (yystack_[1].value.expression_list) );
	}
#line 805 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 280 "parser.ypp" // lalr1.cc:859
    {
		ExprListAST * exprList = new ExprListAST;
		exprList->Append( new EmptyExprAST );
		(yylhs.value.printstatement) = new PrintStmtAST( (yystack_[0].value.printinto), exprList );
	}
#line 815 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 287 "parser.ypp" // lalr1.cc:859
    { debug("print has got itger\n") ;}
#line 821 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 288 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.printinto) = 0;}
#line 827 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 291 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.expression_list) = (yystack_[2].value.expression_list) ; (yylhs.value.expression_list)->Append((yystack_[0].value.expression)); }
#line 833 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 292 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.expression_list) =  new ExprListAST;
		(yylhs.value.expression_list)->Append((yystack_[0].value.expression));
	}
#line 842 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 299 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.expression) = (yystack_[1].value.expression) ;}
#line 848 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 300 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_ADD , (yystack_[0].value.expression) );  }
#line 854 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 301 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_SUB , (yystack_[0].value.expression) );  }
#line 860 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 302 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_MUL , (yystack_[0].value.expression) );  }
#line 866 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 303 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_DIV , (yystack_[0].value.expression) );  }
#line 872 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 304 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_LESS , (yystack_[0].value.expression) );  }
#line 878 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 305 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_LESSEQU , (yystack_[0].value.expression) );  }
#line 884 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 306 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_GREATER , (yystack_[0].value.expression) );  }
#line 890 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 307 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_GREATEREQUL , (yystack_[0].value.expression) );  }
#line 896 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 308 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_EQUL , (yystack_[0].value.expression) );  }
#line 902 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 309 "parser.ypp" // lalr1.cc:859
    {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_EQUL , (yystack_[0].value.expression) );  }
#line 908 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 312 "parser.ypp" // lalr1.cc:859
    {
			(yylhs.value.expression) = new ConstNumberExprAST( (yystack_[0].value.integer) );
		}
#line 916 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 315 "parser.ypp" // lalr1.cc:859
    {
			(yylhs.value.expression) = new ConstStringExprAST((yystack_[0].value.string));
		}
#line 924 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 318 "parser.ypp" // lalr1.cc:859
    {
			ExprAST* zero = new ConstNumberExprAST(0);
			(yylhs.value.expression) = new CalcExprAST(zero, OPERATOR_SUB, (yystack_[0].value.expression));
		}
#line 933 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 324 "parser.ypp" // lalr1.cc:859
    {
		//VariableExprAST * varref = new VariableExprAST($1);
		(yylhs.value.variable_assignment) = new AssigmentAST((yystack_[2].value.varref), (yystack_[0].value.expression));
	}
#line 942 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 330 "parser.ypp" // lalr1.cc:859
    {
			(yylhs.value.call_function) = new CallExprAST((yystack_[2].value.varref));
			debug("functioncall %s with no arg\n", (yystack_[2].value.varref)->ID->ID.c_str());
		}
#line 951 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 334 "parser.ypp" // lalr1.cc:859
    {
			 (yylhs.value.call_function) = new CallExprAST((yystack_[3].value.varref) , (yystack_[1].value.expression_list) );
		}
#line 959 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 338 "parser.ypp" // lalr1.cc:859
    {
		debug("ref menber %s . %s , not supported yet\n" );
		exit(1);
	}
#line 968 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 342 "parser.ypp" // lalr1.cc:859
    { exit(1); }
#line 974 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 343 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.varref) = new VariableExprAST(  new ReferenceAST( (yystack_[0].value.id) ));
	}
#line 982 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 356 "parser.ypp" // lalr1.cc:859
    {

		debug("definning %s as array\n",(yystack_[2].value.id)->c_str());

		(yylhs.value.dim_item) = new VariableDimAST( *(yystack_[2].value.id)  , ArrayExprTypeAST::create(* (yystack_[0].value.exprtype)) );
	}
#line 993 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 374 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.dim_item) = new VariableDimAST( *(yystack_[2].value.id)  , * (yystack_[0].value.exprtype) );
	}
#line 1001 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 377 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.dim_item) = new VariableDimAST( *(yystack_[0].value.id)  , NumberExprTypeAST::GetNumberExprTypeAST() );
	}
#line 1009 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 394 "parser.ypp" // lalr1.cc:859
    {
					useDefautSubMain = false;

					(yylhs.value.function_definition) = new FunctionDimAST(*(yystack_[8].value.id),
											ExprTypeASTPtr(new CallableExprTypeAST(*(yystack_[3].value.exprtype))),
											(yystack_[6].value.arg_list));

					(yylhs.value.function_definition)->body = CodeBlockASTPtr((yystack_[1].value.codeblocks));
				}
#line 1023 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 405 "parser.ypp" // lalr1.cc:859
    {
					useDefautSubMain = false;
					(yylhs.value.function_definition) = new FunctionDimAST(*(yystack_[6].value.id),
											ExprTypeASTPtr(new CallableExprTypeAST(NumberExprTypeAST::GetNumberExprTypeAST())),
											(yystack_[4].value.arg_list));

					(yylhs.value.function_definition)->body = CodeBlockASTPtr((yystack_[1].value.codeblocks));
				}
#line 1036 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 417 "parser.ypp" // lalr1.cc:859
    {
				useDefautSubMain = false;
				debug("!!SUB %s defined with arg !!\n",(yystack_[5].value.id)->c_str());

				(yylhs.value.function_definition) = new FunctionDimAST( *(yystack_[5].value.id),
										 ExprTypeASTPtr(new CallableExprTypeAST(VoidExprTypeAST::GetVoidExprTypeAST())),
										 (yystack_[3].value.arg_list)); //delete $2;
				(yystack_[1].value.codeblocks)->parent = (yystack_[3].value.arg_list);
				(yylhs.value.function_definition)->body = CodeBlockASTPtr((yystack_[1].value.codeblocks));
			}
#line 1051 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 429 "parser.ypp" // lalr1.cc:859
    { (yylhs.value.arg_list) = 0; }
#line 1057 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 430 "parser.ypp" // lalr1.cc:859
    {
		(yylhs.value.arg_list) = (yystack_[4].value.arg_list);
		(yylhs.value.arg_list)->addchild( new ArgumentDimAST( *(yystack_[2].value.id)  , * (yystack_[0].value.exprtype) ) );
	}
#line 1066 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 434 "parser.ypp" // lalr1.cc:859
    {
		debug("definning %s is type %p as arg\n",(yystack_[2].value.id)->c_str(), (yystack_[0].value.exprtype));
		(yylhs.value.arg_list) = new ArgumentDimsAST ;
		(yylhs.value.arg_list)->addchild(new ArgumentDimAST( *(yystack_[2].value.id)  , * (yystack_[0].value.exprtype) ));
	}
#line 1076 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 449 "parser.ypp" // lalr1.cc:859
    {
			(yylhs.value.if_clause) = new IFStmtAST( ExprASTPtr((yystack_[2].value.expression)));
			(yylhs.value.if_clause)->_then = CodeBlockASTPtr(new CodeBlockAST((yystack_[0].value.statement)));
	}
#line 1085 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 455 "parser.ypp" // lalr1.cc:859
    {
			(yylhs.value.if_clause) = new IFStmtAST( ExprASTPtr((yystack_[4].value.expression)));
			(yylhs.value.if_clause)->_then = CodeBlockASTPtr((yystack_[1].value.codeblocks));
		}
#line 1094 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 463 "parser.ypp" // lalr1.cc:859
    {
			(yylhs.value.if_clause) = new IFStmtAST( ExprASTPtr((yystack_[6].value.expression)));
			(yylhs.value.if_clause)->_then = CodeBlockASTPtr((yystack_[3].value.codeblocks));
			(yylhs.value.if_clause)->_else = CodeBlockASTPtr((yystack_[1].value.codeblocks));
		}
#line 1104 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 476 "parser.ypp" // lalr1.cc:859
    {
			(yylhs.value.while_loop) = new WhileLoopAST( ExprASTPtr((yystack_[3].value.expression)) , (yystack_[1].value.codeblocks));
		}
#line 1112 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 485 "parser.ypp" // lalr1.cc:859
    {
				debug("got for loop");
				(yylhs.value.for_loop) = new ForLoopAST((yystack_[8].value.varref), (yystack_[6].value.expression),(yystack_[4].value.expression), 0 ,(yystack_[1].value.codeblocks));
			}
#line 1121 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 492 "parser.ypp" // lalr1.cc:859
    { debug("step");}
#line 1127 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
    break;


#line 1131 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
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
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
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

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
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
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -80;

  const signed char parser::yytable_ninf_ = -58;

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

  const short int
  parser::yypgoto_[] =
  {
     -80,   -80,    21,   -17,   130,     9,   -79,   -80,   -80,    77,
      10,   145,   -80,     0,    -4,    76,   -80,   -80,   -80,   -80,
      92,   -80,   -80,   -80,   -80
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    17,    18,    19,    20,    21,   116,    22,    42,    78,
      23,    24,    25,    35,    56,    85,    27,    28,    29,    30,
     108,    31,    32,    33,   146
  };

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
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "tEOPROG", "tOR", "tAND", "tNOT", "tNEQ",
  "tGEQ", "tLEQ", "tLTN", "tGTN", "tEQU", "'-'", "'+'", "'*'", "'/'",
  "tMOD", "UMINUS", "UPLUS", "tPOW", "tDREF", "'.'", "tNEWLINE", "tAS",
  "tSUB", "tSUBEND", "tFUNCTION", "tFUNCTIONEND", "tRETURN", "tLET",
  "tPRINT", "tARRAYDIM", "tDIM", "tSTRUCTDIM", "tENDSTRUCDIM", "tIF",
  "tTHEN", "tENDIF", "tELSE", "tELSEIF", "tWHILE", "tENDWHILE", "tFOR",
  "tENDFOR", "tTO", "tSTEP", "tLONG", "tSTR", "tID", "tInteger", "tSTRING",
  "tNUMBER", "','", "';'", "'#'", "'('", "')'", "'='", "':'", "$accept",
  "program", "lines", "line", "statements", "statement", "exprtype",
  "printstatement", "printinto", "expression_list", "expression",
  "assigment", "call_function", "varref", "comma_or_colon", "seperator",
  "array_dim", "dim_item", "function_definition", "sub_definition",
  "arg_list", "if_clause", "while_loop", "for_loop", "optstep", YY_NULLPTR
  };


  const unsigned short int
  parser::yyrline_[] =
  {
       0,   177,   177,   187,   201,   211,   218,   219,   223,   224,
     231,   232,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   251,   254,   257,   260,   267,   274,   277,
     280,   287,   288,   291,   292,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   311,   312,   315,
     318,   324,   330,   334,   338,   342,   343,   346,   349,   349,
     352,   353,   356,   374,   377,   392,   403,   415,   429,   430,
     434,   449,   453,   459,   474,   483,   491,   492
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
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
    const unsigned int user_token_number_max_ = 302;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 21 "parser.ypp" // lalr1.cc:1167
} // qb
#line 1676 "/home/cai/projects/basic/compiler/parser.cpp" // lalr1.cc:1167
