/*
    <one line to give the library's name and an idea of what it does.>
    Copyright (C) 2012  microcai <microcai@fedoraproject.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef __AST_H__
#define __AST_H__

#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

enum CompOperator{
	Equl = 1, // == , =
	NotEqul , // <> , >< , != as in basic
	Less , // <
	Greater , // >
};

enum MathOperator{
	Mul = 1 , // *
	Div , // /
	Add , // +
	Minus , // -
	Mod , // % , MOD
	Power , // ^	
};

enum ExprType{
	VOID=0,	// nul type , used as return type of SUB XXX
			// only used by FunctionAST to define SUB in BASIC
	BOOLEAR,	// as boolear , TRUE,FALSE
	SHORT,	// as short
	Intger,	// as Intger
	Long,	// as long
	Double,	// as Double
	STRUCT,	// qbasic supports structure,
	STRING,	// STRING is an internal struct type.
			// STRING is implemented as structure by calling some member function
			// automanticall by compiler
	ARRAY	// 数组，only used by VariableExprAST & DimAST
};

// allow us to use shared ptr to manage the memory
class AST:public boost::enable_shared_from_this<AST>
{
public:
	virtual ~AST() ;
};

// 表达式
class ExprAST: public AST //
{
	ExprType type; // the type of the expresion
	

};

typedef boost::shared_ptr<ExprAST>	ExprASTPtr;

class VariableExprAST:public ExprAST
{
	std::string	name; //变量名字
};

typedef 	boost::shared_ptr<VariableExprAST> VariableExprASTPtr;


// 结构体变量，就是各种变量类型的集合
class StructVariableExprAST: public VariableExprAST
{
	std::list<VariableExprASTPtr>	members; //各个成员
};

typedef boost::shared_ptr<StructVariableExprAST> StructVariableExprASTPtr;

//结构体成员的引用
class StructVariableRefExprAST: public VariableExprAST
{
	StructVariableExprASTPtr	structvar; //引用的结构体
	std::string			nameormember; //引用的成员
};

//数组变量的使用
class ArrayVariableRefExprAST:public VariableExprAST
{
	VariableExprASTPtr array; //数组变量的话，数组的成员的类型

	ExprASTPtr		index; //下表操作还是一个表达式
};

//比较表达式 比较两个表达式的值
class CompExprAST:public ExprAST // bool as result
{
	ExprASTPtr  RHS,LHS;
	enum CompOperator op;	
};

// 数值计算表达式
class CalcExprAST:public ExprAST
{
	ExprASTPtr  RHS,LHS;
	enum MathOperator op;
};

class DimAST: public AST
{
	//ExprType type; // the type of the expresion
	VariableExprAST var; //定义的变量
};

// CALL Sub Functions , 函数调用也是表达式之一，返回值是表达式嘛
class CallExpr:public ExprAST
{
	//参数，参数是一个表达式列表
	std::list<ExprASTPtr>	args;
};



// 语句
class StatementAST: public AST
{
	std::string	LABEL;	// label , if there is. then we can use goto
						// must be uniq among function bodys

};

typedef boost::shared_ptr<StatementAST>	StatementASTPtr;
typedef std::list<StatementASTPtr> StatementsAST;

//左值和右值, 把右值赋给左值
class LetStatementAST: public StatementAST
{
	VariableExprAST * lval;//注意，左值只能是变量表达式
	ExprAST *rval; // 右值可以是任意的表达式。注意，需要可以相互转化的。
};

// IF XX THEN xx ELSE xx ENDIF
class IFExprAST:public StatementAST
{
	ExprASTPtr ifexpresion;
	StatementsAST THEN;
	StatementsAST ELSE;
};

// loop XXX until
class LoopExprAST: public StatementAST
{
	
	
};

#endif // __AST_H__
