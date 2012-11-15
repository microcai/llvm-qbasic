/*
    defination of QBASIC Abstruct Syntax Tree
    Copyright (C) 2012  microcai <microcai@fedoraproject.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

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
#include <llvm/Value.h>
#include <llvm/Module.h>
#include <llvm/Type.h>
#include <llvm/Instructions.h>

enum CompOperator{
	Equl = 1, // == , =
	NotEqul , // <> , >< , != as in basic
	Less , // <
	LessEqul, // <=
	Greater, // >
	GreaterEqul, // >=
};

enum MathOperator{
	Mul = 1 , // *
	Div , // /
	Add , // +
	Minus , // -
	Mod , // % , MOD
	Power , // ^
};


enum Linkage{
	STATIC = 1,	//静态函数，无导出
	EXTERN,		//导出函数
	IMPORTC,		//导入C函数，这样就可以使用 C 函数调用了，算是我提供的一个扩展吧
};

enum ReferenceType{
	BYVALUE,	//传值
	BYREF,	//引用，实质就是指针了. 函数的默认参数是传引用
};
// allow us to use shared ptr to manage the memory
class AST // :public boost::enable_shared_from_this<AST>
{
public:
	AST();
	virtual ~AST();
	static llvm::Module * module;
	//static llvm: * module;
private:
	AST( const AST &  );
	AST & operator =( const AST &  );
};


//语句有, 声明语句和表达式语句和函数调用语句
class StatementsAST;
class StatementAST: public AST
{
public:
    StatementsAST * parent; // 避免循环引用 :) , 用在查找变量声明的时候用到. 回溯法
	std::string	LABEL;	// label , if there is. then we can use goto
						// must be uniq among function bodys
	virtual llvm::Value* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto)=0;
};
typedef boost::shared_ptr<StatementAST>	StatementASTPtr;

class StatementsAST : public StatementAST
{
public:
	std::list<StatementASTPtr>	statements;
    void append( StatementASTPtr item);
	llvm::Value* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};

typedef boost::shared_ptr<StatementsAST> StatementsASTPtr;

#include "typeast.h"

//dim 就是定义一个名字,变量或者函数/过程
class DimAST: public StatementAST
{
public:
	DimAST(const std::string _name , ExprTypeASTPtr _type);
	//ExprType type; // the type of the expresion
	ExprTypeASTPtr	type;
	std::string		name; //定义的符号的名字
	virtual llvm::Value* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto)=0;
};

class VariableDimAST : public DimAST
{
public:
	VariableDimAST(const std::string _name , ExprTypeASTPtr _type);
	virtual llvm::Value* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
	llvm::AllocaInst * AllocaInstRef;
};

typedef boost::shared_ptr<VariableDimAST> VariableDimASTPtr;

//定义结构体变量
class VariableStructDimAST : VariableDimAST
{
	//VariableSimpleDimAST	
	std::list<VariableDimASTPtr> members;
};

//定义数组
class VariableArrayDimAST : VariableDimAST
{
	VariableDimASTPtr	itemtype;
	int start,end; //起始位置
};

// 表达式
class ExprAST: public AST //
{
public:
	ExprTypeASTPtr type;
    ExprAST(ExprTypeASTPtr ExprType):type(ExprType){};
	virtual llvm::Value *Codegen(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto) = 0;
};

typedef boost::shared_ptr<ExprAST>	ExprASTPtr;

class EmptyExprAST : public ExprAST
{
public:	
    EmptyExprAST():ExprAST(ExprTypeASTPtr(new VoidTypeAST())){}
	llvm::Value *Codegen(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto){return insertto;}
};

class VariableRefExprAST:public ExprAST
{
public:
	VariableDimAST	*	define;
    VariableRefExprAST(const std::string _name);
	std::string	var; //指向引用的变量名字.
	virtual llvm::Value *Codegen(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};
typedef 	boost::shared_ptr<VariableRefExprAST> VariableExprASTPtr;

//整数类型. 最简单的类型.可以直接生成  llvm-IR 代码
class NumberExprAST : public ExprAST
{
	VariableExprASTPtr var_num;
public:
    NumberExprAST():ExprAST(ExprTypeASTPtr(new NumberTypeAST())){};
	NumberExprAST(VariableExprASTPtr);

	virtual llvm::Value *Codegen(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};
typedef boost::shared_ptr<NumberExprAST> NumberExprASTPtr;

// 常量 , 需要一步转化为 Number 或者是 String
class ConstExprAST:public ExprAST
{
public:
	std::string constval;
	virtual	llvm::Value *Codegen(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};

class ConstNumberExprAST :public NumberExprAST
{
	const int64_t val;
public:
    ConstNumberExprAST(const int64_t);
	llvm::Value *Codegen(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto); // final , 不允许继承了.
};

// 结构体变量，就是各种变量类型的集合
class StructVariableExprAST: public VariableRefExprAST
{
	std::list<VariableExprASTPtr>	members; //各个成员
};

typedef boost::shared_ptr<StructVariableExprAST> StructVariableExprASTPtr;

//结构体成员的引用
class StructVariableRefExprAST: public VariableRefExprAST
{
	StructVariableExprASTPtr	structvar; //引用的结构体
	std::string			nameormember; //引用的成员
};

//数组变量的使用
class ArrayVariableRefExprAST:public VariableRefExprAST
{
	VariableExprASTPtr items; //数组变量的话，数组的成员的类型

	ExprASTPtr		index; //下表操作还是一个表达式
};
typedef boost::shared_ptr<VariableRefExprAST> VariableRefExprASTPtr;

class NumberAssigmentAST : public StatementAST
{
public:
	NumberAssigmentAST(VariableRefExprASTPtr _lvar, NumberExprASTPtr _rval);
	VariableRefExprASTPtr lval;
	NumberExprASTPtr	rval;
    llvm::Value* Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto);
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

// 前向函数声明
class FunctionDeclarAST: public DimAST
{
	Linkage		linkage; //链接类型。static? extern ?
	ExprTypeASTPtr	type; //返回值
	std::string	name; //函数名字
	std::list<VariableDimASTPtr> args_type; //checked by CallExpr
};

//函数体
class FunctionDimAST: public FunctionDeclarAST
{
	std::list<VariableDimAST> args; //定义的参数

	AST * body; //函数体

//	std::list<DimAST>	dims;//定义的本地变量

//	StatementsAST		body;//函数体
};

typedef std::list<ExprASTPtr>	FunctionParameterListAST;

////////////////////////////////////////////////////////////////////////////////
//内建函数语句. PRINT , 为 PRINT 生成特殊的函数调用:)
////////////////////////////////////////////////////////////////////////////////

//打印目的地. 默认打印到屏幕
class PrintIntroAST : public NumberExprAST
{
public:
	PrintIntroAST();
    llvm::Value* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};
typedef boost::shared_ptr<PrintIntroAST> PrintIntroASTPtr;

class PrintListAST: public AST
{
public:
	std::vector<ExprASTPtr> printlist;
	int size(){
		return printlist.size();
	}
	void additem(ExprASTPtr item){
		printlist.push_back(item);		
	}
};

typedef boost::shared_ptr<PrintListAST> PrintListASTPtr;

class PrintStmtAST: public StatementAST
{
public:
	PrintIntroASTPtr	print_intro;
	PrintListASTPtr		callargs;
	PrintStmtAST(PrintIntroASTPtr,PrintListASTPtr);
    virtual llvm::Value* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};

#endif // __AST_H__

