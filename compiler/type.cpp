
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

#undef NDEBUG
#include <assert.h>

#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/assert.hpp>

#include <llvm/DerivedTypes.h>
#include <llvm/Constants.h>
#include <llvm/Constant.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Instructions.h>
#include <llvm/Instruction.h>
#include <llvm/Support/IRBuilder.h>

#include "llvmwrapper.hpp"
#include "ast.hpp"
#include "type.hpp"

#define debug std::printf

//static map of the internal type system

static	NumberExprTypeAST numbertype;

// todo 检查当前 block 并回朔到根节点, 查找定义
ExprTypeAST*	TypeNameResolve(ASTContext ctx,const std::string _typename)
{
	if(_typename == "long")
		return &numbertype;
	return NULL;
}

ExprTypeAST* NumberExprAST::type(ASTContext)
{
    return &numbertype;
}


llvm::Type* NumberExprTypeAST::llvm_type(ASTContext ctx)
{
	switch(sizeof(long)){
		case 8:
			return llvm::Type::getInt64Ty(ctx.module->getContext());
		case 4:
			return llvm::Type::getInt32Ty(llvm::getGlobalContext());
	}
	return llvm::Type::getInt32Ty(llvm::getGlobalContext());
}

llvm::Value* NumberExprAST::getval(ASTContext ctx)
{
	return qbc::getconstlong(	this->v);
}

DimAST* NamedExprAST::nameresolve(ASTContext ctx)
{
	// 首先查找变量的分配 FIXME 将来要支持结构体成员

	std::string varname =  this->ID->ID;

	debug("searching for var %s\n",varname.c_str());

	if(! ctx.codeblock ){
		debug("var %s not defined\n",varname.c_str());
		exit(1);
		return NULL;
	}

	std::map< std::string, DimAST* >::iterator dimast_iter = ctx.codeblock->symbols.find(varname);

	// 定义找到
	if(dimast_iter != ctx.codeblock->symbols.end()){

		debug("searching for var %s have result %p\n",varname.c_str(),dimast_iter->second);

		return dimast_iter->second;
	}
	ctx.codeblock = ctx.codeblock->parent;
	return nameresolve(ctx);
}

llvm::Value* VariableExprAST::getval(ASTContext ctx)
{
 	llvm::IRBuilder<> builder(ctx.block);

	std::string desc = std::string("load local var ")+this->ID->ID;
	
	debug("%s\n",desc.c_str());
	
	return nameresolve(ctx)->getval(ctx);
}
// 获得变量的分配
llvm::Value* VariableExprAST::getptr(ASTContext ctx)
{
	return nameresolve(ctx)->getptr(ctx);
}

ExprTypeAST* AssignmentExprAST::type(ASTContext ctx)
{
	//TODO, result the type
	return lval->type(ctx);
}

llvm::Value* AssignmentExprAST::getval(ASTContext ctx)
{

	llvm::Value * LHS =	this->lval->getptr(ctx);	
	llvm::Value * RHS =	this->rval->getval(ctx);

// 	//FIXME 为复杂类型执行高层调用
 	llvm::IRBuilder<> builder(ctx.block);
 	// 生成赋值语句,因为是简单的整型赋值,所以可以直接生成而不用调用 operator==()
  	builder.CreateStore(RHS,LHS);
		debug("get ptr of this\n");
	return RHS;
}

llvm::Value* NumberExprTypeAST::Alloca(ASTContext ctx, const std::string _name,const std::string _typename)
{
	debug("allocation for value %s type %s\n",_name.c_str(),_typename.c_str());
	//TODO , 在堆栈上分配个变量
	llvm::IRBuilder<> builder(&ctx.llvmfunc->getEntryBlock(),
							  ctx.llvmfunc->getEntryBlock().begin());
	
	builder.SetInsertPoint(ctx.block);

	return builder.CreateAlloca(this->llvm_type(ctx),0,_name);
}

llvm::Value* CallExprAST::getval(ASTContext ctx)
{
	llvm::IRBuilder<> builder(ctx.block);

	// call functions TODO
    debug("sigfault herekkk?\n");
	llvm::Value * ret = NULL;

	//获得函数定义
	DimAST * dim = nameresolve(ctx);
	FunctionDimAST* fundim = dynamic_cast<FunctionDimAST*>(dim);
	
	if(fundim){ //有定义, 则直接调用, 无定义就 ... 呵呵

		// 获得符号类型
		ExprTypeAST * symboltype = TypeNameResolve(ctx,dim->type);

		//获得函数类型信息
		llvm::Value * llvmfunc =	fundim->getval(ctx);

		//构建参数列表
		std::vector<llvm::Value*> args;
		ret = builder.CreateCall(llvmfunc,args,this->ID->ID);

	}else {
		debug("function %s not defined", this->ID->ID.c_str());
	    exit(1);
	}
	return ret;

	   exit(1);

#if 0
	llvm::IRBuilder<>	builder(ctx.block);

	// build call argument

	std::vector<llvm::Value*> args;

	if(callargs && callargs->expression_list.size() )
	{
		BOOST_FOREACH( ExprASTPtr expr , callargs->expression_list)
		{
			debug("pusing args \n");
			args.push_back( expr->getval(ctx) );
		}
	}

	if(args.empty()){
		debug("===I will call to %s ==== with no argument\n",var->ID.c_str());
		ret = builder.CreateCall(target);
	}else{
		debug("===I will call to %s ==== with argument number %d\n",var->ID.c_str() , args.size() );
		ret = builder.CreateCall(target, args);
	}
	// use the result
	
#endif
}


llvm::Value* CalcExprAST::getval(ASTContext ctx)
{
	BOOST_ASSERT(ctx.llvmfunc);
	//TODO, 生成计算表达式 !
	llvm::Value * LHS =	this->lval->getval(ctx);
	llvm::Value * RHS =	this->rval->getval(ctx);

	llvm::IRBuilder<> builder(ctx.llvmfunc->getContext());
	builder.SetInsertPoint(ctx.block);

	switch(this->op){
		case OPERATOR_ADD:
			return builder.CreateAdd(LHS,RHS);
		case OPERATOR_SUB:
			return builder.CreateSub(LHS,RHS);
		case OPERATOR_MUL:
			return builder.CreateMul(LHS,RHS);
		case OPERATOR_DIV:
			return builder.CreateSDiv(LHS,RHS);
		case OPERATOR_LESS:
			return builder.CreateICmpSLT(LHS,RHS);
		case OPERATOR_LESSEQU:
			return builder.CreateICmpSLE(LHS,RHS);
		case OPERATOR_GREATER:
			return builder.CreateICmpSGT(LHS,RHS);
		case OPERATOR_GREATEREQUL:
			return builder.CreateICmpSGE(LHS,RHS);
		default:
			debug("operator not supported yet\n");
			exit(1);
	}
	return ctx.block;
}

///////////////////////////////////////////////////////////////////
//////////////////// 构造函数们 ////////////////////////////////////
//////////////////////////////////////////////////////////////////
NamedExprAST::NamedExprAST(ReferenceAST* _ID)
	:ID(_ID)
{
}

VariableExprAST::VariableExprAST(ReferenceAST* ID)
	:NamedExprAST(ID)
{
}

AssignmentExprAST::AssignmentExprAST(NamedExprAST* l, ExprAST*r)
	:lval(l),rval(r)
{
}

CallOrArrayExprAST::CallOrArrayExprAST(ReferenceAST* _ID)
	:NamedExprAST(_ID)
{
}

CallExprAST::CallExprAST(ReferenceAST* ID, ExprListAST* exp_list)
	:CallOrArrayExprAST(ID)
{
}

CalcExprAST::CalcExprAST(ExprAST* l, MathOperator _op, ExprAST* r)
	:lval(l),rval(r),op(_op)
{
	
}
