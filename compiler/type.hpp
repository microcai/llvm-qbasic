/*
    defination of QBASIC Abstruct Syntax Tree - The Type System
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

#pragma once
#ifndef __AST_H__
	#include <string.h>
	#include <llvm/Type.h> // for KDevelop Only
	#include "ast.hpp" // for KDevelop Only
	#error "Don't include it diretly, use #include<ast.hpp>"
#endif

#if 0
大块的注释还是这个好用
//////////////////////////////////////////////////
////
////	参考我在聊天频道上发表的类型系统原型
////
//////////////////////////////////////////////////

//(09:50:34 PM) microcai: 类型系统的工作应该是这样的
// (09:50:53 PM) microcai: 变量引用, 函数调用, 都是一个 named expression
// (09:51:13 PM) microcai: 都派生子 expression
// (09:51:47 PM) microcai: expression 有2个东西也它捆绑在一起 :  type &  value
// (09:52:13 PM) microcai: 所谓 type 其实就是 size 和一系列的 operations
// (09:52:34 PM) microcai: value 则是表达式的值 . 采用递归处理的办法获得表达式的值 .
// (09:52:44 PM) talk@ikde.org: [AthrunArthur] 你打算直接用LLVM的type类？
// (09:52:58 PM) microcai: named expression 派生子 expression
// (09:53:16 PM) microcai: 除了 type & value 外,  还有一个 storage
// (09:53:25 PM) microcai: 就是存储区域.
// (09:53:31 PM) microcai: 不是
// (09:53:33 PM) microcai: 不是 llvm
// (09:53:38 PM) microcai: 不使用 llvm 的 type
// (09:53:54 PM) talk@ikde.org: [AthrunArthur] 啊  我明白了
// (09:55:02 PM) microcai: named expression 使用一个 storage , 需要一个 symbol table 来查找定义
// (09:55:16 PM) talk@ikde.org: [AthrunArthur] 基本来说  你还需要解决内存布局的问题 对吧
// (09:55:43 PM) microcai: 而基类的 expression 则使用的递归扫描的办法, 依据表达式对象来获得类型
// (09:56:02 PM) talk@ikde.org: [AthrunArthur] 话说LLVM应该支持一些基本类型吧？
// (09:56:14 PM) microcai: 这样 , 实现一个 类型系统需要 3 个基类, 都派生子 AST
// (09:56:47 PM) microcai: ExprAST , ExprTypeAST, SymbolDeclarAST
// (09:57:09 PM) microcai: ExprAST 派生的有,  BinaryOperatorExprAST
// (09:57:30 PM) microcai: ***OperatorExprAST
// (09:58:30 PM) microcai: ReferenceExprAST 派生子 ExprAST , 有两个子类: VarReferenceExprAST 和 FunctionCallExprAST
// (09:58:56 PM) microcai: SymbolDeclarAST  有两个子类
// (09:59:15 PM) microcai: VarDeclarAST 和 FunctionDeclarAST
// (09:59:58 PM) microcai: VarDeclarAST 还有一个派生类叫做 ParamterAST , 用来引用函数参数
// (10:00:09 PM) microcai: ExprTypeAST 是重点
// (10:00:45 PM) microcai: 主要有一个派生类 NumberExprTypeAST , 包含了对整数变量的 operator 操作.
// (10:01:07 PM) microcai: 然后是 StringExprTypeAST
// (10:01:14 PM) microcai: 包含对字符串的操作
// (10:01:33 PM) microcai: 在 virtual emitoperator() 中生成的是对库函数的调用
// (10:01:57 PM) microcai: 接着是 ArrayExprTypeAST
// (10:02:12 PM) microcai: 然后是 UserDefinedTypeAST
// (10:02:25 PM) microcai: 这个主要用来实现用户自定义的类型
// (10:02:46 PM) microcai: *ExprTypeAST 包含 emitoperator() 虚函数
// (10:03:09 PM) microcai: 用来提交运算操作的汇编/llvmIR 代码
// (10:03:19 PM) microcai: 好了
// (10:03:21 PM) microcai: done
// (10:03:23 PM) microcai: AA see ?
// (10:03:26 PM) talk@ikde.org: [AthrunArthur] 你的类型系统是为了支持用户自定义类型  对吧 ？
// (10:03:29 PM) microcai: yes
//
// (10:03:40 PM) talk@ikde.org: [AthrunArthur] OK ， I See
// (10:03:50 PM) microcai: 咋样?
//
//
// 引用语句, 只要是包含了一个"标识符" 并在随后的语句中提供标识符的"解析操作"    
#endif

class ReferenceAST : public AST
{
public:
	std::string ID; //the name of the variable
    ReferenceAST( std::string * tID );
    virtual ~ReferenceAST(){};
};
typedef boost::shared_ptr<ReferenceAST> ReferenceASTPtr;

// TODO ? how?
class MemberReferenceAST : public ReferenceAST
{
    MemberReferenceAST(std::string* members);
};

class ExprOperation;
class ExprAST;
class PointerTypeAST;

typedef boost::shared_ptr<ExprAST>	ExprASTPtr;
typedef boost::shared_ptr<PointerTypeAST> PointerTypeASTPtr;

// type of the expression
class ExprTypeAST : public AST
{
	std::string		_typename;
	size_t			_size; // sizeof() 
public:
	// name of type
	virtual std::string name(ASTContext){return _typename;};

	virtual llvm::Type	* llvm_type(ASTContext ctx) = 0;

	// allocate one on stack , if possible , name it
	virtual llvm::Value * Alloca(ASTContext ctx, const std::string _name){return NULL;}

	// dereference the pointer 
	virtual llvm::Value * deref(ASTContext ctx, llvm::Value *v);

	// initalize the default vaule
	virtual void initalize(ASTContext, llvm::Value * Ptr) {};

	// generate the call to deconstruction function here!
	virtual void destory(ASTContext, llvm::Value * Ptr) {};

	virtual	size_t size(){return _size;};

	// get operation table
	virtual ExprOperation * getop() = 0;

	virtual	PointerTypeASTPtr	getpointetype() =0;

	// create a temp from llvm::Valut *
	virtual ExprASTPtr		createtemp(ASTContext ,llvm::Value * , llvm::Value *ptr)=0;

public:
    ExprTypeAST(){}
    ExprTypeAST( size_t size , const std::string __typename );
    virtual ~ExprTypeAST(){}; // do nothing
protected:
    void printf(const char* arg1);
};
typedef boost::shared_ptr<ExprTypeAST>		ExprTypeASTPtr;

// expression
class ExprAST: public AST //
{
public:
#if 0
	//获得表达式类型信息, 如果是计算表达式, 需要的是递归操作哦
	//注意,不要释放返回值. 返回值是由 block 管理的.
	//block 退出的时候会释放掉本 block 注册的类型 (本地类型定义)   
#endif
	virtual ExprTypeASTPtr type(ASTContext ) = 0;
#if 0
	// 生成获得变量值的操作.
	// 对于计算表达式来说, 这个是递归操作
	// 对于函数调用表达式来说, 这会引起函数调用操作
	// 注意, 这里的意思是 "生成一个能获得该变量的操作".
	// 返回值其实是一系列的llvm-IR 语句节点,
	// 最终在程序生成的时候转化为正确的汇编语句.
	// 对于计算表达式来说, 这是不能执行的操作, 故而不在基类里   
#endif
	virtual llvm::Value *getval(ASTContext) = 0;
	virtual llvm::Value *getptr(ASTContext) = 0;

    virtual ~ExprAST(){}
};


#if 0
// 空表达式. 空表达式的类型是 void
// 用法 1 : 声明无返回值的函数
// 用法 2 :pirnt 语句通过识别参数列表里的空语句来正确生成回车符  
#endif
class EmptyExprAST : public ExprAST
{
public:
	virtual ExprTypeASTPtr type(ASTContext );

    virtual llvm::Value* getval(ASTContext ){ return 0;}
    virtual llvm::Value* getptr(ASTContext ){exit(132);};
};
#if 0
// 用来管理临时对象, 这是实现 QBASIC C++ style 的临时对象的重点哦~    
#endif
class TempExprAST : public ExprAST{
	ExprTypeASTPtr _type;
public:
	llvm::Value * val;
	llvm::Value	* ptr;
	ASTContext ctx;
	
    virtual ExprTypeASTPtr type(ASTContext ctx){return _type;}

	TempExprAST(ASTContext _ctx,llvm::Value * _val, llvm::Value *ptr,ExprTypeASTPtr type);
    virtual llvm::Value* getval(ASTContext ) { return val;}
    virtual llvm::Value* getptr(ASTContext ){return ptr;}
    virtual ~TempExprAST(){};
};


class TempNumberExprAST : public TempExprAST
{
public:
    TempNumberExprAST(ASTContext ctx,llvm::Value * numberresult,llvm::Value * pointertoval);
    virtual llvm::Value* getval(ASTContext );
};

class ConstNumberExprAST : public ExprAST
{
	int v;
public:
	ConstNumberExprAST( long num){ v = num;};
public:
	
    virtual ExprTypeASTPtr type(ASTContext );

    virtual llvm::Value* getval(ASTContext );
	virtual llvm::Value* getptr(ASTContext ){exit(128);};
};

class ConstStringExprAST :public ExprAST
{
	llvm::Value *		val;
	std::string			str;
public:
	ConstStringExprAST(const std::string _str);
	virtual ExprTypeASTPtr type(ASTContext );
    virtual llvm::Value* getval(ASTContext );
	virtual llvm::Value* getptr(ASTContext ){exit(129);};
};

class TempStringExprAST : public TempExprAST
{
public:
    TempStringExprAST(ASTContext ctx,llvm::Value * result , llvm::Value *ptr);
    virtual ~TempStringExprAST();
};

#if 0
// 命名表达式. 命名的表达式是 Function Call , 数组, 变量 的基类     
#endif
class DimAST;
class NamedExprAST : public ExprAST
{
public:
	ReferenceASTPtr			ID;

	NamedExprAST(ReferenceAST * _ID);

	virtual ExprTypeASTPtr	type(ASTContext ) = 0;

	virtual llvm::Value*	getptr(ASTContext) = 0;

	// resolve and get where it got defined
	virtual DimAST* nameresolve(ASTContext ctx);

    virtual ~NamedExprAST(){}
};
typedef boost::shared_ptr<NamedExprAST> NamedExprASTPtr;
#if 0
// 变量引用. 如果变量是个函数, 则是函数指针类型哦 ~ 
// 如果变量是数组, 则是数组类型哦.        
#endif
class VariableExprAST : public NamedExprAST
{
public:
    VariableExprAST(ReferenceAST* ID);
	virtual llvm::Value* getval(ASTContext );
	
    virtual llvm::Value* getptr(ASTContext );

    virtual DimAST* nameresolve(ASTContext ctx);
	
	virtual ExprTypeASTPtr type(ASTContext ctx);
    virtual ~VariableExprAST(){}
};

// expression of math 
class CalcExprAST : public ExprAST{
	MathOperator	op;
	ExprASTPtr		lval,rval;
	ExprASTPtr		result; // cache the result :)
public:
	CalcExprAST(ExprAST * , MathOperator op , ExprAST * );
	virtual ExprTypeASTPtr type(ASTContext);
    virtual llvm::Value* getval(ASTContext);
	virtual llvm::Value* getptr(ASTContext){exit(177);}
};

#if 0
// 赋值表达式. 注意, 在 QB 中没有赋值表达式
// 但是我在 AST 中使用一个包含赋值表达式的语句来使用这个 AST 提供的特性   
#endif
class AssignmentExprAST : public ExprAST
{
	NamedExprASTPtr lval;
	ExprASTPtr 		rval;
public:

	// 赋值表达式必须使用一个命名的类型为左值.
	AssignmentExprAST(NamedExprAST* , ExprAST *);
	
    virtual ExprTypeASTPtr type(ASTContext);
    virtual llvm::Value* getval(ASTContext);
    virtual llvm::Value* getptr(ASTContext ){exit(127);};
};

typedef boost::shared_ptr<AssignmentExprAST> AssignmentExprASTPtr;

class ExprListAST : public AST //
{
public:
	std::vector<ExprASTPtr>	expression_list;

    ExprListAST(){}
	void Append(ExprAST* exp);
    virtual ~ExprListAST(){};
};
typedef boost::shared_ptr<ExprListAST> ExprListASTPtr;

// 数组或者函数调用.
// 返回的类型就是数组成员的类型, 或者是函数的返回类型
// 依据是 calltarget 的类型是 CallableExprTypeAST 则为函数调用.
class CallExprAST : public ExprAST
{
	NamedExprASTPtr				calltarget; // should be callable
	ExprListASTPtr				callargs;
public:
	CallExprAST(NamedExprAST* , ExprListAST * exp_list = NULL);
	virtual ExprTypeASTPtr	type(ASTContext);

    virtual llvm::Value* getptr(ASTContext); // cann't get the address
    virtual llvm::Value* getval(ASTContext);
};

typedef boost::shared_ptr<CallExprAST>	CallExprASTPtr;


// wrapper class
class ExprType {
	ExprTypeASTPtr	_type;
public:
	ExprType(ExprTypeASTPtr type):_type(type){}
	operator	ExprTypeASTPtr(){ExprTypeASTPtr tmp = _type; delete this;  return tmp;}
};


class VoidExprTypeAST : public ExprTypeAST{
public:
	static ExprTypeASTPtr GetVoidExprTypeAST();
    virtual llvm::Type* llvm_type(ASTContext ctx);
    virtual llvm::Value* Alloca(ASTContext ctx, const std::string _name){return NULL;}
    virtual ExprOperation* getop(){return NULL;}
    virtual PointerTypeASTPtr getpointetype();
    virtual ExprASTPtr createtemp(ASTContext , llvm::Value* , llvm::Value *ptr );
};

class NumberExprTypeAST :public ExprTypeAST {
public:
    NumberExprTypeAST();
	
    virtual llvm::Type* llvm_type(ASTContext ctx);

    virtual size_t size(){return sizeof(long);};
	
	virtual llvm::Value* Alloca(ASTContext ctx, const std::string _name);
    virtual llvm::Value* deref(ASTContext ctx, llvm::Value* v);

    virtual ExprOperation* getop();

    virtual PointerTypeASTPtr getpointetype();

    virtual ExprASTPtr createtemp(ASTContext ctx,llvm::Value* val , llvm::Value *ptr);	

	static ExprTypeASTPtr   GetNumberExprTypeAST();
};

class StringExprTypeAST : public ExprTypeAST
{
public:
    StringExprTypeAST();
    virtual llvm::Type* llvm_type(ASTContext ctx);

    virtual size_t size(){return sizeof(size_t);}

	virtual llvm::Value* Alloca(ASTContext ctx, const std::string _name);
    virtual ExprOperation* getop();
    virtual PointerTypeASTPtr getpointetype();;
	
    virtual void destory(ASTContext , llvm::Value* Ptr);

    virtual ExprASTPtr createtemp(ASTContext , llvm::Value*  , llvm::Value *ptr);
	
	static ExprTypeASTPtr GetStringExprTypeAST();
};

class ArrayExprOperation;
class CallExprAST;
class ArrayExprTypeAST : public ExprTypeAST
{
	/**
	 * NOTE:
	 *
	 * An Array is of the type  struct QBArray
	 **/
	ExprTypeASTPtr	elementtype;
	friend class ArrayExprOperation;
	friend class CallExprAST;
public:
    ArrayExprTypeAST(ExprTypeASTPtr elementtype);
    virtual llvm::Type* llvm_type(ASTContext ctx);

    virtual size_t size(){return sizeof(struct QBArray);}

	virtual llvm::Value* Alloca(ASTContext ctx, const std::string _name);
    virtual ExprOperation* getop();
    virtual PointerTypeASTPtr getpointetype(){ ::printf("get pointer to type\n");exit(1);};
    virtual void destory(ASTContext , llvm::Value* Ptr);
    virtual ExprASTPtr createtemp(ASTContext , llvm::Value*  , llvm::Value *ptr);

public:
	static ExprTypeASTPtr create(ExprTypeASTPtr);
};
#if 0
//  函数对象类型. 这是基类
//  而一个函数声明本身也是一个 callable 类型
//  一个函数指针是 callable 类型
//  一个函数对象也是 callable 类型   
#endif
class CallableExprTypeAST : public ExprTypeAST{
	ExprTypeASTPtr	returntype;
	friend class FunctionDimAST;
	friend class CallExprAST;
public:
    CallableExprTypeAST(ExprTypeASTPtr	_returntype);
	static	llvm::Value * defaultprototype(ASTContext ctx,std::string functionname);
    virtual ExprOperation* getop();
	virtual PointerTypeASTPtr getpointetype(){::printf("get pointer to function\n");exit(1);};
	
    virtual llvm::Type* llvm_type(ASTContext ctx);
    virtual llvm::Value* Alloca(ASTContext ctx, const std::string _name);
    virtual ExprASTPtr createtemp(ASTContext , llvm::Value*  , llvm::Value *ptr);
};

class PointerTypeAST : public ExprTypeAST
{
	ExprTypeASTPtr		pointeetype;
public:
	PointerTypeAST(ExprTypeASTPtr _pointeetype);
    virtual ExprOperation* getop();
    virtual llvm::Type* llvm_type(ASTContext ctx){return llvm::Type::getInt8PtrTy(ctx.module->getContext());};
    virtual PointerTypeASTPtr getpointetype(){::printf("pointer to pointer\n");exit(1);};
    virtual ExprASTPtr createtemp(ASTContext ctx, llvm::Value* val , llvm::Value *ptr ){
		::printf("pointer to tmp  val");
		exit(1);
	}
};

class StructExprTypeAST : public ExprTypeAST{
	size_t	_size;
public:
    StructExprTypeAST(const std::string __typename);
    size_t size(){return _size;}
	size_t size(size_t newsize){_size = newsize;return _size;} // set size

public:
	ExprASTPtr createtemp(ASTContext , llvm::Value* , llvm::Value* ptr){}
	ExprOperation* getop();
	PointerTypeASTPtr getpointetype(){}
	llvm::Type* llvm_type(ASTContext ctx);

public:
	static ExprTypeASTPtr create( const std::string __typename);
};

/////////////// 一下类型未实现.

//  浮点运算. 在不支持浮点数的平台这个类要提交浮点模拟.
class FlatExprTypeAST : ExprTypeAST {

};


// 引用类型.
class ReferenceTypeAST : public ExprTypeAST
{

};

///////////////////////// 运算符支持.
class ExprOperation{
public:
	// 赋值运算符, 对于字符串来说, 这个运算符的意义就是调用 strdup
	// 每个类型都会有自己的 Operator 实现.
	// 对于其他类型来说, 呵呵, 那就是 Load / Store 啦
	// 运算结果是一个 ExprASTPtr , 事实上可以忽略,呵呵. C++编译器将自动释放它.
	virtual	ExprASTPtr operator_assign(ASTContext , NamedExprASTPtr lval, ExprASTPtr rval);

	// 加法运算, 对于字符串来说, 这运算过程会生成一个临时字符串,
	// 临时字符串 AST 对象将会被 AST节点被析构的时候向当前llvm basicbody 位置插入临时字符串的释放指令.
	virtual ExprASTPtr operator_add(ASTContext , ExprASTPtr lval, ExprASTPtr rval);

	// 减法运算, 对于字符串来说无此类型的运算. 试图对字符串执行减法导致一个编译期错误.
	virtual ExprASTPtr operator_sub(ASTContext , ExprASTPtr lval, ExprASTPtr rval);

	// 乘法运算, 对字符串来说无此类型的运算.
	virtual ExprASTPtr operator_mul(ASTContext, ExprASTPtr lval, ExprASTPtr rval);

	//除法.
	virtual ExprASTPtr operator_div(ASTContext, ExprASTPtr lval, ExprASTPtr rval);

	// 各种比较运算.
	virtual	ExprASTPtr operator_comp(ASTContext, MathOperator op, ExprASTPtr lval,ExprASTPtr rval);

	// 括号操作, 也就是函数调用, 或者是数组下标寻址.
	virtual ExprASTPtr operator_call(ASTContext, NamedExprASTPtr target, ExprListASTPtr callargslist);
};

class NumberExprOperation : public ExprOperation {
    virtual ExprASTPtr operator_assign(ASTContext , NamedExprASTPtr lval, ExprASTPtr rval);
    virtual ExprASTPtr operator_add(ASTContext , ExprASTPtr lval, ExprASTPtr rval);
	virtual ExprASTPtr operator_sub(ASTContext , ExprASTPtr lval, ExprASTPtr rval);
    virtual ExprASTPtr operator_mul(ASTContext , ExprASTPtr lval, ExprASTPtr rval);
    virtual ExprASTPtr operator_div(ASTContext , ExprASTPtr lval, ExprASTPtr rval);
    virtual ExprASTPtr operator_comp(ASTContext , MathOperator op, ExprASTPtr lval, ExprASTPtr rval);
};

class StringExprOperation : public ExprOperation {
    virtual ExprASTPtr operator_assign(ASTContext , NamedExprASTPtr lval, ExprASTPtr rval);
    virtual ExprASTPtr operator_add(ASTContext , ExprASTPtr lval, ExprASTPtr rval);
    virtual ExprASTPtr operator_comp(ASTContext ctx, MathOperator op, ExprASTPtr lval, ExprASTPtr rval);
};

class ArrayExprOperation : public ExprOperation{
	virtual ExprASTPtr operator_assign(ASTContext ctx,NamedExprASTPtr lval,ExprASTPtr rval);
    virtual ExprASTPtr operator_call(ASTContext , NamedExprASTPtr target, ExprListASTPtr callargslist);	
};

class FunctionExprOperation : public ExprOperation{
    virtual ExprASTPtr operator_call(ASTContext , NamedExprASTPtr target, ExprListASTPtr callargslist);
};

class PointerTypeOperation: public ExprOperation{

};

class StructTypeOperation : public ExprOperation{
	
};