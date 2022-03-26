// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 24 "/home/cai/projects/basic/compiler/parser.ypp"


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


#line 80 "/home/cai/projects/basic/compiler/parser.cpp"


#include "parser.hpp"




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


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



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
      *yycdebug_ << '\n';                       \
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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 21 "/home/cai/projects/basic/compiler/parser.ypp"
namespace qb {
#line 159 "/home/cai/projects/basic/compiler/parser.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
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

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
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

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
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
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: lines tEOPROG
#line 177 "/home/cai/projects/basic/compiler/parser.ypp"
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
#line 624 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 3: // program: lines statements tEOPROG
#line 187 "/home/cai/projects/basic/compiler/parser.ypp"
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
#line 641 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 4: // lines: lines line
#line 201 "/home/cai/projects/basic/compiler/parser.ypp"
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
#line 656 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 5: // lines: line
#line 211 "/home/cai/projects/basic/compiler/parser.ypp"
               {
		(yylhs.value.codeblocks) = 0;
		if((yystack_[0].value.statement_list)){
			(yylhs.value.codeblocks) = new CodeBlockAST; 	(yylhs.value.codeblocks)->addchild((yystack_[0].value.statement_list));
		}
	}
#line 667 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 6: // line: statements tNEWLINE
#line 218 "/home/cai/projects/basic/compiler/parser.ypp"
                          { (yylhs.value.statement_list)=(yystack_[1].value.statement_list);  }
#line 673 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 7: // line: statement tNEWLINE
#line 219 "/home/cai/projects/basic/compiler/parser.ypp"
                             {
		if(!(yystack_[1].value.statement)){debug("statement nil\n");}
		(yylhs.value.statement_list) = new StatementsAST ; (yylhs.value.statement_list)->push_back(StatementASTPtr((yystack_[1].value.statement)));
	}
#line 682 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 8: // line: tNEWLINE
#line 223 "/home/cai/projects/basic/compiler/parser.ypp"
                   { (yylhs.value.statement_list) = 0;}
#line 688 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 9: // line: expression tNEWLINE
#line 224 "/home/cai/projects/basic/compiler/parser.ypp"
                              {
			ExprStmtAST * callstmt =  new ExprStmtAST( (yystack_[1].value.expression) );
			(yylhs.value.statement_list) = new StatementsAST ;
			(yylhs.value.statement_list)->push_back( StatementASTPtr(callstmt)  );
	}
#line 698 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 10: // statements: statements comma_or_colon statement
#line 231 "/home/cai/projects/basic/compiler/parser.ypp"
                                                 {  (yylhs.value.statement_list) = (yystack_[2].value.statement_list); (yylhs.value.statement_list)->push_back(StatementASTPtr((yystack_[0].value.statement))); }
#line 704 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 11: // statements: statement comma_or_colon statement
#line 232 "/home/cai/projects/basic/compiler/parser.ypp"
                                                     {
				(yylhs.value.statement_list) = new StatementsAST ;
				(yylhs.value.statement_list)->push_back(StatementASTPtr((yystack_[2].value.statement)));
				(yylhs.value.statement_list)->push_back(StatementASTPtr((yystack_[0].value.statement)));
		}
#line 714 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 12: // statement: printstatement
#line 239 "/home/cai/projects/basic/compiler/parser.ypp"
                          { (yylhs.value.statement) = (yystack_[0].value.printstatement); }
#line 720 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 13: // statement: dim_item
#line 240 "/home/cai/projects/basic/compiler/parser.ypp"
                           { (yylhs.value.statement) = (yystack_[0].value.dim_item); }
#line 726 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 14: // statement: array_dim
#line 241 "/home/cai/projects/basic/compiler/parser.ypp"
                            { (yylhs.value.statement) = (yystack_[0].value.dim_item); }
#line 732 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 15: // statement: assigment
#line 242 "/home/cai/projects/basic/compiler/parser.ypp"
                            {(yylhs.value.statement)= (yystack_[0].value.variable_assignment);}
#line 738 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 16: // statement: tLET assigment
#line 243 "/home/cai/projects/basic/compiler/parser.ypp"
                                 { (yylhs.value.statement) = (yystack_[0].value.variable_assignment);}
#line 744 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 17: // statement: tRETURN expression
#line 244 "/home/cai/projects/basic/compiler/parser.ypp"
                                     { (yylhs.value.statement) = new ReturnAST((yystack_[0].value.expression));}
#line 750 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 18: // statement: if_clause
#line 245 "/home/cai/projects/basic/compiler/parser.ypp"
                            {(yylhs.value.statement)= (yystack_[0].value.if_clause);}
#line 756 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 19: // statement: while_loop
#line 246 "/home/cai/projects/basic/compiler/parser.ypp"
                             {(yylhs.value.statement)= (yystack_[0].value.while_loop);}
#line 762 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 20: // statement: for_loop
#line 247 "/home/cai/projects/basic/compiler/parser.ypp"
                           {(yylhs.value.statement)= (yystack_[0].value.for_loop);}
#line 768 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 21: // statement: sub_definition
#line 248 "/home/cai/projects/basic/compiler/parser.ypp"
                                  {(yylhs.value.statement)= (yystack_[0].value.function_definition);}
#line 774 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 22: // statement: function_definition
#line 249 "/home/cai/projects/basic/compiler/parser.ypp"
                                       {(yylhs.value.statement)= (yystack_[0].value.function_definition);}
#line 780 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 23: // statement: expression comma_or_colon
#line 251 "/home/cai/projects/basic/compiler/parser.ypp"
                                            { /*TODO*/debug("here====3====\n"); exit(1);	}
#line 786 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 24: // exprtype: tLONG
#line 254 "/home/cai/projects/basic/compiler/parser.ypp"
                {
		(yylhs.value.exprtype) = new ExprType (NumberExprTypeAST::GetNumberExprTypeAST());
	}
#line 794 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 25: // exprtype: tSTR
#line 257 "/home/cai/projects/basic/compiler/parser.ypp"
               {
		(yylhs.value.exprtype) = new ExprType (StringExprTypeAST::GetStringExprTypeAST());
	}
#line 802 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 26: // exprtype: tID
#line 260 "/home/cai/projects/basic/compiler/parser.ypp"
              {
		debug("define as user type not supported\n");
		exit(1);
	}
#line 811 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 27: // printstatement: tPRINT printinto expression_list
#line 267 "/home/cai/projects/basic/compiler/parser.ypp"
                                            {

		(yystack_[0].value.expression_list)->Append( new EmptyExprAST );
		(yylhs.value.printstatement) = new PrintStmtAST( (yystack_[1].value.printinto), (yystack_[0].value.expression_list) );

		debug("got print1 done\n");
	}
#line 823 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 28: // printstatement: tPRINT printinto expression_list ','
#line 274 "/home/cai/projects/basic/compiler/parser.ypp"
                                               {
		(yylhs.value.printstatement) = new PrintStmtAST( (yystack_[2].value.printinto), (yystack_[1].value.expression_list) );
	}
#line 831 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 29: // printstatement: tPRINT printinto expression_list ';'
#line 277 "/home/cai/projects/basic/compiler/parser.ypp"
                                                {
		(yylhs.value.printstatement) = new PrintStmtAST( (yystack_[2].value.printinto), (yystack_[1].value.expression_list) );
	}
#line 839 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 30: // printstatement: tPRINT printinto
#line 280 "/home/cai/projects/basic/compiler/parser.ypp"
                           {
		ExprListAST * exprList = new ExprListAST;
		exprList->Append( new EmptyExprAST );
		(yylhs.value.printstatement) = new PrintStmtAST( (yystack_[0].value.printinto), exprList );
	}
#line 849 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 31: // printinto: '#' tInteger ','
#line 287 "/home/cai/projects/basic/compiler/parser.ypp"
                             { debug("print has got itger\n") ;}
#line 855 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 32: // printinto: %empty
#line 288 "/home/cai/projects/basic/compiler/parser.ypp"
                        { (yylhs.value.printinto) = 0;}
#line 861 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 33: // expression_list: expression_list ',' expression
#line 291 "/home/cai/projects/basic/compiler/parser.ypp"
                                                { (yylhs.value.expression_list) = (yystack_[2].value.expression_list) ; (yylhs.value.expression_list)->Append((yystack_[0].value.expression)); }
#line 867 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 34: // expression_list: expression
#line 292 "/home/cai/projects/basic/compiler/parser.ypp"
                     {
		(yylhs.value.expression_list) =  new ExprListAST;
		(yylhs.value.expression_list)->Append((yystack_[0].value.expression));
	}
#line 876 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 36: // expression: '(' expression ')'
#line 299 "/home/cai/projects/basic/compiler/parser.ypp"
                                     { (yylhs.value.expression) = (yystack_[1].value.expression) ;}
#line 882 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 37: // expression: expression '+' expression
#line 300 "/home/cai/projects/basic/compiler/parser.ypp"
                                            {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_ADD , (yystack_[0].value.expression) );  }
#line 888 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 38: // expression: expression '-' expression
#line 301 "/home/cai/projects/basic/compiler/parser.ypp"
                                            {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_SUB , (yystack_[0].value.expression) );  }
#line 894 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 39: // expression: expression '*' expression
#line 302 "/home/cai/projects/basic/compiler/parser.ypp"
                                            {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_MUL , (yystack_[0].value.expression) );  }
#line 900 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 40: // expression: expression '/' expression
#line 303 "/home/cai/projects/basic/compiler/parser.ypp"
                                            {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_DIV , (yystack_[0].value.expression) );  }
#line 906 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 41: // expression: expression tLTN expression
#line 304 "/home/cai/projects/basic/compiler/parser.ypp"
                                             {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_LESS , (yystack_[0].value.expression) );  }
#line 912 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 42: // expression: expression tLEQ expression
#line 305 "/home/cai/projects/basic/compiler/parser.ypp"
                                             {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_LESSEQU , (yystack_[0].value.expression) );  }
#line 918 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 43: // expression: expression tGTN expression
#line 306 "/home/cai/projects/basic/compiler/parser.ypp"
                                             {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_GREATER , (yystack_[0].value.expression) );  }
#line 924 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 44: // expression: expression tGEQ expression
#line 307 "/home/cai/projects/basic/compiler/parser.ypp"
                                             {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_GREATEREQUL , (yystack_[0].value.expression) );  }
#line 930 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 45: // expression: expression tEQU expression
#line 308 "/home/cai/projects/basic/compiler/parser.ypp"
                                             {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_EQUL , (yystack_[0].value.expression) );  }
#line 936 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 46: // expression: expression '=' expression
#line 309 "/home/cai/projects/basic/compiler/parser.ypp"
                                            {   (yylhs.value.expression) = new CalcExprAST( (yystack_[2].value.expression), OPERATOR_EQUL , (yystack_[0].value.expression) );  }
#line 942 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 48: // expression: tInteger
#line 312 "/home/cai/projects/basic/compiler/parser.ypp"
                            {
			(yylhs.value.expression) = new ConstNumberExprAST( (yystack_[0].value.integer) );
		}
#line 950 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 49: // expression: tSTRING
#line 315 "/home/cai/projects/basic/compiler/parser.ypp"
                          {
			(yylhs.value.expression) = new ConstStringExprAST((yystack_[0].value.string));
		}
#line 958 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 50: // expression: '-' expression
#line 318 "/home/cai/projects/basic/compiler/parser.ypp"
                                 {
			ExprAST* zero = new ConstNumberExprAST(0);
			(yylhs.value.expression) = new CalcExprAST(zero, OPERATOR_SUB, (yystack_[0].value.expression));
		}
#line 967 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 51: // assigment: varref '=' expression
#line 324 "/home/cai/projects/basic/compiler/parser.ypp"
                                 {
		//VariableExprAST * varref = new VariableExprAST($1);
		(yylhs.value.variable_assignment) = new AssigmentAST((yystack_[2].value.varref), (yystack_[0].value.expression));
	}
#line 976 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 52: // call_function: varref '(' ')'
#line 330 "/home/cai/projects/basic/compiler/parser.ypp"
                                {
			(yylhs.value.call_function) = new CallExprAST((yystack_[2].value.varref));
			debug("functioncall %s with no arg\n", (yystack_[2].value.varref)->ID->ID.c_str());
		}
#line 985 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 53: // call_function: varref '(' expression_list ')'
#line 334 "/home/cai/projects/basic/compiler/parser.ypp"
                                                  {
			 (yylhs.value.call_function) = new CallExprAST((yystack_[3].value.varref) , (yystack_[1].value.expression_list) );
		}
#line 993 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 54: // varref: expression '.' tID
#line 338 "/home/cai/projects/basic/compiler/parser.ypp"
                           {
		debug("ref menber %s . %s , not supported yet\n" );
		exit(1);
	}
#line 1002 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 55: // varref: expression tDREF tID
#line 342 "/home/cai/projects/basic/compiler/parser.ypp"
                                 { exit(1); }
#line 1008 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 56: // varref: tID
#line 343 "/home/cai/projects/basic/compiler/parser.ypp"
              {
		(yylhs.value.varref) = new VariableExprAST(  new ReferenceAST( (yystack_[0].value.id) ));
	}
#line 1016 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 62: // array_dim: tARRAYDIM tID tAS exprtype
#line 356 "/home/cai/projects/basic/compiler/parser.ypp"
                                       {

		debug("definning %s as array\n",(yystack_[2].value.id)->c_str());

		(yylhs.value.dim_item) = new VariableDimAST( *(yystack_[2].value.id)  , ArrayExprTypeAST::create(* (yystack_[0].value.exprtype)) );
	}
#line 1027 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 63: // dim_item: tDIM tID tAS exprtype
#line 374 "/home/cai/projects/basic/compiler/parser.ypp"
                                {
		(yylhs.value.dim_item) = new VariableDimAST( *(yystack_[2].value.id)  , * (yystack_[0].value.exprtype) );
	}
#line 1035 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 64: // dim_item: tDIM tID
#line 377 "/home/cai/projects/basic/compiler/parser.ypp"
                  {
		(yylhs.value.dim_item) = new VariableDimAST( *(yystack_[0].value.id)  , NumberExprTypeAST::GetNumberExprTypeAST() );
	}
#line 1043 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 65: // function_definition: tFUNCTION tID '(' arg_list ')' tAS exprtype tNEWLINE lines tFUNCTIONEND
#line 394 "/home/cai/projects/basic/compiler/parser.ypp"
                                             {
					useDefautSubMain = false;

					(yylhs.value.function_definition) = new FunctionDimAST(*(yystack_[8].value.id),
											ExprTypeASTPtr(new CallableExprTypeAST(*(yystack_[3].value.exprtype))),
											(yystack_[6].value.arg_list));

					(yylhs.value.function_definition)->body = CodeBlockASTPtr((yystack_[1].value.codeblocks));
				}
#line 1057 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 66: // function_definition: tFUNCTION tID '(' arg_list ')' tNEWLINE lines tFUNCTIONEND
#line 405 "/home/cai/projects/basic/compiler/parser.ypp"
                                             {
					useDefautSubMain = false;
					(yylhs.value.function_definition) = new FunctionDimAST(*(yystack_[6].value.id),
											ExprTypeASTPtr(new CallableExprTypeAST(NumberExprTypeAST::GetNumberExprTypeAST())),
											(yystack_[4].value.arg_list));

					(yylhs.value.function_definition)->body = CodeBlockASTPtr((yystack_[1].value.codeblocks));
				}
#line 1070 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 67: // sub_definition: tSUB tID '(' arg_list ')' lines tSUBEND
#line 417 "/home/cai/projects/basic/compiler/parser.ypp"
                                {
				useDefautSubMain = false;
				debug("!!SUB %s defined with arg !!\n",(yystack_[5].value.id)->c_str());

				(yylhs.value.function_definition) = new FunctionDimAST( *(yystack_[5].value.id),
										 ExprTypeASTPtr(new CallableExprTypeAST(VoidExprTypeAST::GetVoidExprTypeAST())),
										 (yystack_[3].value.arg_list)); //delete $2;
				(yystack_[1].value.codeblocks)->parent = (yystack_[3].value.arg_list);
				(yylhs.value.function_definition)->body = CodeBlockASTPtr((yystack_[1].value.codeblocks));
			}
#line 1085 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 68: // arg_list: %empty
#line 429 "/home/cai/projects/basic/compiler/parser.ypp"
         { (yylhs.value.arg_list) = 0; }
#line 1091 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 69: // arg_list: arg_list ',' tID tAS exprtype
#line 430 "/home/cai/projects/basic/compiler/parser.ypp"
                                       {
		(yylhs.value.arg_list) = (yystack_[4].value.arg_list);
		(yylhs.value.arg_list)->addchild( new ArgumentDimAST( *(yystack_[2].value.id)  , * (yystack_[0].value.exprtype) ) );
	}
#line 1100 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 70: // arg_list: tID tAS exprtype
#line 434 "/home/cai/projects/basic/compiler/parser.ypp"
                           {
		debug("definning %s is type %p as arg\n",(yystack_[2].value.id)->c_str(), (yystack_[0].value.exprtype));
		(yylhs.value.arg_list) = new ArgumentDimsAST ;
		(yylhs.value.arg_list)->addchild(new ArgumentDimAST( *(yystack_[2].value.id)  , * (yystack_[0].value.exprtype) ));
	}
#line 1110 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 71: // if_clause: tIF expression tTHEN statement
#line 449 "/home/cai/projects/basic/compiler/parser.ypp"
                                           {
			(yylhs.value.if_clause) = new IFStmtAST( ExprASTPtr((yystack_[2].value.expression)));
			(yylhs.value.if_clause)->_then = CodeBlockASTPtr(new CodeBlockAST((yystack_[0].value.statement)));
	}
#line 1119 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 72: // if_clause: tIF expression tTHEN seperator lines tENDIF
#line 455 "/home/cai/projects/basic/compiler/parser.ypp"
                       {
			(yylhs.value.if_clause) = new IFStmtAST( ExprASTPtr((yystack_[4].value.expression)));
			(yylhs.value.if_clause)->_then = CodeBlockASTPtr((yystack_[1].value.codeblocks));
		}
#line 1128 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 73: // if_clause: tIF expression tTHEN seperator lines tELSE lines tENDIF
#line 463 "/home/cai/projects/basic/compiler/parser.ypp"
                        {
			(yylhs.value.if_clause) = new IFStmtAST( ExprASTPtr((yystack_[6].value.expression)));
			(yylhs.value.if_clause)->_then = CodeBlockASTPtr((yystack_[3].value.codeblocks));
			(yylhs.value.if_clause)->_else = CodeBlockASTPtr((yystack_[1].value.codeblocks));
		}
#line 1138 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 74: // while_loop: tWHILE expression seperator lines tENDWHILE
#line 476 "/home/cai/projects/basic/compiler/parser.ypp"
                          {
			(yylhs.value.while_loop) = new WhileLoopAST( ExprASTPtr((yystack_[3].value.expression)) , (yystack_[1].value.codeblocks));
		}
#line 1146 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 75: // for_loop: tFOR varref '=' expression tTO expression optstep tNEWLINE lines tENDFOR
#line 485 "/home/cai/projects/basic/compiler/parser.ypp"
                                {
				debug("got for loop");
				(yylhs.value.for_loop) = new ForLoopAST((yystack_[8].value.varref), (yystack_[6].value.expression),(yystack_[4].value.expression), 0 ,(yystack_[1].value.codeblocks));
			}
#line 1155 "/home/cai/projects/basic/compiler/parser.cpp"
    break;

  case 77: // optstep: tSTEP expression
#line 492 "/home/cai/projects/basic/compiler/parser.ypp"
                                  { debug("step");}
#line 1161 "/home/cai/projects/basic/compiler/parser.cpp"
    break;


#line 1165 "/home/cai/projects/basic/compiler/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -80;

  const signed char parser::yytable_ninf_ = -58;

  const short
  parser::yypact_[] =
  {
     641,    38,   -80,   -39,   -20,    38,    38,    -7,    18,    51,
      38,    38,    38,   -80,   -80,   -80,    38,   105,   154,   -80,
      39,    56,   -80,   203,   -80,    55,     7,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,    -8,    57,    58,    62,   327,   327,
     -80,    66,    38,    98,    99,    22,   219,    46,   271,   -80,
     -80,   -80,     1,   -80,   -80,   -80,   673,   -80,   673,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    75,    79,
     -80,    38,   -80,   -10,    38,    81,    81,    78,    37,   327,
      60,    60,   365,   -80,   -80,   641,    38,   -80,   -80,   -80,
     237,   -80,   342,   150,   354,   413,   178,    -8,    -8,     6,
       6,   -80,   -80,   327,   -80,   -48,   327,   109,    42,    44,
     -80,    38,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   641,
     449,   289,    38,   -80,    60,    90,   641,    30,   327,   417,
     -80,    38,   -80,   119,   481,   641,    60,   -80,   641,   304,
      60,   -80,   513,   122,   545,    38,   123,   -80,   -80,   641,
     -80,   327,   641,   577,   609,   -80,   -80
  };

  const signed char
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

  const short
  parser::yypgoto_[] =
  {
     -80,   -80,    21,   -17,   130,   -33,   -79,   -80,   -80,    77,
      10,   145,   -80,     0,    -4,    76,   -80,   -80,   -80,   -80,
      92,   -80,   -80,   -80,   -80
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    17,    18,    19,    20,    21,   116,    22,    42,    78,
      23,    24,    25,    35,    56,    85,    27,    28,    29,    30,
     108,    31,    32,    33,   146
  };

  const short
  parser::yytable_[] =
  {
      26,    51,   117,     1,    88,   122,    26,    66,    67,   123,
      36,    34,    47,    68,    69,    38,    39,    58,    26,    72,
      45,    46,    39,    89,    53,    91,    48,    68,    69,    37,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    13,
      14,    15,    84,    68,    69,   132,    16,   104,    41,   118,
      71,     1,    79,   135,   136,    54,    26,   143,    26,    82,
      55,   147,    53,    73,    71,    74,    90,    43,    90,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    84,    57,
      71,   103,    26,    79,   106,    26,    72,    13,    14,    15,
     111,   112,    90,    54,    16,   125,   121,   125,    55,   126,
      44,   127,    73,    51,    86,    49,   120,   113,   114,   115,
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

  const short
  parser::yycheck_[] =
  {
       0,    18,    81,    13,     3,    53,     6,    15,    16,    57,
      49,     1,    12,    21,    22,     5,     6,    21,    18,    23,
      10,    11,    12,    56,    23,    58,    16,    21,    22,    49,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    49,
      50,    51,    46,    21,    22,   124,    56,    57,    55,    82,
      58,    13,    42,    23,    24,    54,    56,   136,    58,    37,
      59,   140,    23,    56,    58,    58,    56,    49,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    82,    23,
      58,    71,    82,    73,    74,    85,    90,    49,    50,    51,
      53,    54,    82,    54,    56,    53,    86,    53,    59,    57,
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

  const signed char
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
      24,    24,    37,    23,    74,    75,    58,    57,     3,    65,
      70,    65,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    49,    49,    70,    57,    69,    70,    49,    80,    80,
      53,    53,    54,    47,    48,    49,    66,    66,    65,    75,
      62,    70,    53,    57,    24,    53,    57,    57,    70,    62,
      42,    45,    66,    49,    62,    23,    24,    38,    39,    70,
      24,    26,    62,    66,    62,    46,    84,    66,    28,    23,
      38,    70,    23,    62,    62,    28,    44
  };

  const signed char
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

  const signed char
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
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "tEOPROG", "tOR",
  "tAND", "tNOT", "tNEQ", "tGEQ", "tLEQ", "tLTN", "tGTN", "tEQU", "'-'",
  "'+'", "'*'", "'/'", "tMOD", "UMINUS", "UPLUS", "tPOW", "tDREF", "'.'",
  "tNEWLINE", "tAS", "tSUB", "tSUBEND", "tFUNCTION", "tFUNCTIONEND",
  "tRETURN", "tLET", "tPRINT", "tARRAYDIM", "tDIM", "tSTRUCTDIM",
  "tENDSTRUCDIM", "tIF", "tTHEN", "tENDIF", "tELSE", "tELSEIF", "tWHILE",
  "tENDWHILE", "tFOR", "tENDFOR", "tTO", "tSTEP", "tLONG", "tSTR", "tID",
  "tInteger", "tSTRING", "tNUMBER", "','", "';'", "'#'", "'('", "')'",
  "'='", "':'", "$accept", "program", "lines", "line", "statements",
  "statement", "exprtype", "printstatement", "printinto",
  "expression_list", "expression", "assigment", "call_function", "varref",
  "comma_or_colon", "seperator", "array_dim", "dim_item",
  "function_definition", "sub_definition", "arg_list", "if_clause",
  "while_loop", "for_loop", "optstep", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
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

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
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
    // Last valid token kind.
    const int code_max = 302;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 21 "/home/cai/projects/basic/compiler/parser.ypp"
} // qb
#line 1739 "/home/cai/projects/basic/compiler/parser.cpp"

