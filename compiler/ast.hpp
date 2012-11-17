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

enum MathOperator{
	OPERATOR_ADD = 1 , // +
	OPERATOR_SUB , // -
	OPERATOR_MUL , // *
	OPERATOR_DIV , // /
	Mod , // % , MOD
	Power , // ^

	Equl , // == , =
	NotEqul , // <> , >< , != as in basic
	OPERATOR_LESS , // <
	OPERATOR_LESSEQU, // <=
	OPERATOR_GREATER, // >
	OPERATOR_GREATEREQUL, // >=
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

// 引用语句, 只要是包含了一个"标识符" 并在随后的语句中提供标识符的"解析操作"
class ReferenceAST;
typedef boost::shared_ptr<ReferenceAST> ReferenceASTPtr;

class ReferenceAST : public AST
{
public:
	std::string ID; //标识符
    ReferenceAST( std::string * tID );
};

// 引用结构体成员 //TODO ? 怎么实现?
class MemberReferenceAST : public ReferenceAST
{
    MemberReferenceAST(std::string* members);
};

//语句有, 声明语句和表达式语句和函数调用语句
class StatementAST;
typedef boost::shared_ptr<StatementAST>	StatementASTPtr;
class StatementAST: public AST
{
public:
	std::list<StatementASTPtr>	substatements;

    StatementAST(){parent=NULL;}
	StatementAST * parent; // 避免循环引用 :) , 用在查找变量声明的时候用到. 回溯法
	std::string	LABEL;	// label , if there is. then we can use goto
						// must be uniq among function bodys
	void addchild(StatementAST* item);

	virtual llvm::BasicBlock* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
	virtual ~StatementAST(){}
};

class EmptyStmtAST : public StatementAST
{
public:
	EmptyStmtAST(){}
    virtual llvm::BasicBlock* Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto);
};

#include "typeast.h"

//dim 就是定义一个名字,变量或者函数/过程
class DimAST: public StatementAST
{
public:
	DimAST(const std::string _name , ExprTypeASTPtr _type);
	//ExprType type; // the type of the expresion
	ExprTypeASTPtr	type;
	std::string		name; //定义的符号的名字
	virtual llvm::BasicBlock* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
    virtual ~DimAST(){}
};

class VariableDimAST : public DimAST
{
public:
	VariableDimAST(const std::string _name , ExprTypeASTPtr _type);
	virtual llvm::BasicBlock* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
	llvm::AllocaInst * AllocaInstRef;
};

typedef boost::shared_ptr<VariableDimAST> VariableDimASTPtr;

// 表达式
class ExprAST: public AST //
{
public:
	ExprTypeASTPtr type;

public:
    ExprAST(ExprTypeASTPtr ExprType):type(ExprType){};

	virtual llvm::AllocaInst*nameresolve(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto) = 0;
	virtual llvm::Value *getval(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto) = 0;
};
typedef boost::shared_ptr<ExprAST>	ExprASTPtr;

class ExprListAST : public AST //
{
public:
	std::vector<ExprASTPtr>	expression_list;
	
    ExprListAST(){}
	void Append(ExprAST* exp);
};
typedef boost::shared_ptr<ExprListAST> ExprListASTPtr;

class EmptyExprAST : public ExprAST
{
public:	
    EmptyExprAST():ExprAST(ExprTypeASTPtr(new VoidTypeAST())){}
	llvm::Value *getval(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto){return insertto;}

    virtual llvm::AllocaInst* nameresolve(StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto){ return NULL; }

};

// 引用一个ID标识符标识的变量. 
class VariableRefExprAST:public ExprAST
{
public:
	VariableDimAST	*	define; //在未来解析
    ReferenceASTPtr		var; //指向引用的变量名字.

    virtual bool canllvm();

    VariableRefExprAST(ReferenceASTPtr varname ); //用构变量构筑

	// helper function , resolve the name to llvm::AllocaInst
	virtual llvm::AllocaInst*nameresolve(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto);

	// get Val for this type. Not that , you simple can't use this for non simple type
	virtual llvm::Value *getval(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto);

	// get pointer to the val, then the llvm::Value can be used to CreateStore
	virtual	llvm::Value *getptr(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};
typedef 	boost::shared_ptr<VariableRefExprAST> VariableRefExprASTPtr;

//整数类型. 最简单的类型.可以直接生成  llvm-IR 代码
class NumberExprAST : public ExprAST
{
	VariableRefExprASTPtr var_num;
public:
    NumberExprAST():ExprAST(ExprTypeASTPtr(new NumberTypeAST())){};
	NumberExprAST(VariableRefExprASTPtr);

	virtual llvm::Value *getval(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};
typedef boost::shared_ptr<NumberExprAST> NumberExprASTPtr;

class ConstNumberExprAST :public NumberExprAST
{
	const int64_t val;
public:
    ConstNumberExprAST(const int64_t);
	llvm::Value *getval(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto); // final , 不允许继承了.
    virtual llvm::AllocaInst* nameresolve(StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto){ return NULL;}
};

class AssigmentAST : public StatementAST
{
public:
	AssigmentAST(VariableRefExprASTPtr _lvar, ExprASTPtr _rval);
	VariableRefExprASTPtr lval;
	ExprASTPtr	rval;
    llvm::BasicBlock* Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto);
};

// 数值计算表达式
class CalcExprAST : public ExprAST
{
public:
    CalcExprAST(ExprAST * , MathOperator  ,ExprAST * );
	ExprASTPtr  rval,lval;
	enum MathOperator op;

    virtual llvm::Value* getval(StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto);

	//TODO , 为复杂的表达式类型执行混成
    virtual llvm::AllocaInst* nameresolve(StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto){ return NULL; };
};

// 函数调用, 也是个数字表达式 , 更是一个名称引用表达式!
class CallExprAST : public VariableRefExprAST {

	llvm::Function * target; // resolved target
public:
	// the type of the return function , also is the type of itself. default return type is number
    CallExprAST(ReferenceAST * target ,  ExprListAST * args = NULL);
	
	ExprListASTPtr		callargs; // args for call

	// call this to the the return value of the function. this will insert neceserry calls
    virtual llvm::Value* getval(StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto);
    virtual llvm::AllocaInst* nameresolve(StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto);
};
typedef boost::shared_ptr<CallExprAST>	CallExprASTPtr;

// 对函数的调用, 实质是函数调用表达式的包装
class CallStmtAST : public StatementAST
{
	CallExprASTPtr			callable;
public:
	CallStmtAST(CallExprAST * callexp);

    virtual llvm::BasicBlock* Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto);
};


// IF 语句
class IFStmtAST : public StatementAST
{
public:
	IFStmtAST(ExprASTPtr expr):_expr(expr){}
	ExprASTPtr _expr;
	StatementASTPtr _then;
	StatementASTPtr _else;
    virtual llvm::BasicBlock* Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto);
};

// 所有循环语句的基类, while until for 三种循环
class LoopAST : public StatementAST
{
	StatementASTPtr		loopbody; // 循环体
public:
	LoopAST(StatementASTPtr body):loopbody(body){}
	// 生成循环体
    llvm::BasicBlock*	bodygen(llvm::Function* TheFunction, llvm::BasicBlock* insertto);
    virtual llvm::BasicBlock* Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto) = 0;
};

// while 语句
class WhileLoopAST : public LoopAST
{
	//循环条件
	ExprASTPtr	condition;
public:
	WhileLoopAST(ExprASTPtr _condition , StatementASTPtr body);

    virtual llvm::BasicBlock* Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto);
};

//函数 AST , 有 body 没 body 来区别是不是定义或者声明
//定义的参数为 substatements, 目的是为了 nameresolve 的时候找到
class FunctionDimAST: public DimAST
{
public:
	Linkage		linkage; //链接类型。static? extern ?
	std::list<VariableDimASTPtr> args_type; //checked by CallExpr

	StatementASTPtr	body; //函数体
	
    FunctionDimAST(const std::string _name, VariableDimAST * argsdef,ExprTypeASTPtr _type = ExprTypeASTPtr(new VoidTypeAST) );
    FunctionDimAST(const std::string _name, ExprTypeASTPtr _type = ExprTypeASTPtr(new VoidTypeAST) );
	//如果是声明, 为 dim 生成 llvm::Function * 声明供使用
    virtual llvm::BasicBlock* Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto);
};

class DefaultMainFunctionAST : public FunctionDimAST
{
public:
	DefaultMainFunctionAST(StatementAST * body);
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
    llvm::BasicBlock* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};
typedef boost::shared_ptr<PrintIntroAST> PrintIntroASTPtr;

class PrintStmtAST: public StatementAST
{
public:
	PrintIntroASTPtr	print_intro;
	ExprListASTPtr		callargs;
	PrintStmtAST(PrintIntroAST *,ExprListAST * );
    virtual llvm::BasicBlock* Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto);
};

#endif // __AST_H__

