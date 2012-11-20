/*
    operator support for internal data struct

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
#include <cstdio>
#include <boost/make_shared.hpp>
#include <boost/foreach.hpp>
#include <llvm/Support/IRBuilder.h>

#include "ast.hpp"
#include "type.hpp"
#include "llvmwrapper.hpp"

#define debug std::printf

static	NumberExprOperation	numberop;
static	StringExprOperation stringop;
static	FunctionExprOperation funcop;

ExprOperation* NumberExprTypeAST::getop()
{
	return & numberop;
}

ExprOperation* StringExprTypeAST::getop()
{
	return & stringop;
}

ExprOperation* ArrayExprTypeAST::getop()
{
	exit(1);
}

ExprOperation* CallableExprTypeAST::getop()
{
	return &funcop;
}

ExprASTPtr ExprOperation::operator_assign(ASTContext, NamedExprASTPtr lval, ExprASTPtr rval)
{
	debug("can not assign to  this target\n");
    exit(2);
}

ExprASTPtr ExprOperation::operator_add(ASTContext, ExprASTPtr lval, ExprASTPtr rval)
{
	debug("can not add this target\n");
    exit(2);
}

ExprASTPtr ExprOperation::operator_sub(ASTContext, ExprASTPtr lval, ExprASTPtr rval)
{
	debug("can not sub this target\n");
    exit(2);
}

ExprASTPtr ExprOperation::operator_mul(ASTContext, ExprASTPtr lval, ExprASTPtr rval)
{
	debug("can not mul this target\n");
    exit(2);
}

ExprASTPtr ExprOperation::operator_div(ASTContext, ExprASTPtr lval, ExprASTPtr rval)
{
	debug("can not div this target\n");
    exit(2);
}

ExprASTPtr ExprOperation::operator_comp(ASTContext, MathOperator op, ExprASTPtr lval, ExprASTPtr rval)
{
    debug("can comp non-comp target\n");
    exit(2);
}

ExprASTPtr ExprOperation::operator_call(ASTContext, NamedExprASTPtr target, ExprListASTPtr callargslist)
{
	debug("can not call on a non-callable target\n");
	exit(2);
}

//	call get on lval and rval, then wrapper an value to NumberExprAST;
ExprASTPtr NumberExprOperation::operator_assign(ASTContext ctx, NamedExprASTPtr lval, ExprASTPtr rval)
{
	llvm::Value * LHS =	lval->getptr(ctx);
	llvm::Value * RHS =	rval->getval(ctx);

 	llvm::IRBuilder<> builder(ctx.block);
 	// 生成赋值语句,因为是简单的整型赋值,所以可以直接生成而不用调用 operator==()
  	builder.CreateStore(RHS,LHS);
	debug("get ptr of this\n");
	return lval; // FIXME 可以吧, 呵呵
}

//TODO 添加 free + strdup  指令
ExprASTPtr StringExprOperation::operator_assign(ASTContext ctx, NamedExprASTPtr lval, ExprASTPtr rval)
{
	llvm::IRBuilder<> builder(ctx.block);
	
	llvm::Constant * llvmfunc_free =  qbc::getbuiltinprotype(ctx,"free");
	llvm::Constant * llvmfunc_strdup = qbc::getbuiltinprotype(ctx,"strdup");

	builder.CreateCall(llvmfunc_free,lval->getval(ctx));

	llvm::Value * dupedstr = builder.CreateCall(llvmfunc_strdup,rval->getval(ctx),"dumpstring");

	builder.CreateStore(dupedstr,lval->getptr(ctx));
	return lval;
}

// 数字加法.
ExprASTPtr NumberExprOperation::operator_add(ASTContext ctx, ExprASTPtr lval, ExprASTPtr rval)
{
	llvm::Value * LHS =	lval->getval(ctx);
	llvm::Value * RHS =	rval->getval(ctx);
	llvm::IRBuilder<> builder(ctx.block);
	llvm::Value * result = builder.CreateAdd(LHS,RHS);

	//TODO , 构造临时 Number 对象
	return lval->type(ctx)->createtemp(ctx,result);
}

// 字符串加法
ExprASTPtr StringExprOperation::operator_add(ASTContext ctx, ExprASTPtr lval, ExprASTPtr rval)
{
	llvm::IRBuilder<> builder(ctx.block);

	llvm::Constant * llvmfunc_calloc =  qbc::getbuiltinprotype(ctx,"malloc");
	llvm::Constant * llvmfunc_strlen =  qbc::getbuiltinprotype(ctx,"strlen");
	llvm::Constant * llvmfunc_strcpy = qbc::getbuiltinprotype(ctx,"strcpy");
	llvm::Constant * llvmfunc_strcat = qbc::getbuiltinprotype(ctx,"strcat");

	llvm::Value * string_left_length = builder.CreateCall(llvmfunc_strlen,lval->getval(ctx));
	llvm::Value * string_right_length = builder.CreateCall(llvmfunc_strlen,rval->getval(ctx));

	llvm::Value * result_length = builder.CreateAdd(string_left_length,string_right_length);

	llvm::Value * resultstring = builder.CreateCall(llvmfunc_calloc,
												 qbc::getconstlong(1));
	
	builder.CreateCall2(llvmfunc_strcpy,resultstring,lval->getval(ctx));
	builder.CreateCall2(llvmfunc_strcat,resultstring,rval->getval(ctx));
	return 	lval->type(ctx)->createtemp(ctx,resultstring);
}


// 数字减法
ExprASTPtr NumberExprOperation::operator_sub(ASTContext ctx, ExprASTPtr lval, ExprASTPtr rval)
{	
	llvm::Value * LHS =	lval->getval(ctx);
	llvm::Value * RHS =	rval->getval(ctx);
	llvm::IRBuilder<> builder(ctx.block);
	llvm::Value * result = builder.CreateSub(LHS,RHS);

	//TODO , 构造临时 Number 对象
	return boost::make_shared<TempNumberExprAST>(ctx,result);
}

//  数字乘法, 使用乘法指令
ExprASTPtr NumberExprOperation::operator_mul(ASTContext ctx, ExprASTPtr lval, ExprASTPtr rval)
{
	llvm::Value * LHS =	lval->getval(ctx);
	llvm::Value * RHS =	rval->getval(ctx);
	llvm::IRBuilder<> builder(ctx.block);
	llvm::Value * result;
	
	result = builder.CreateMul(LHS,RHS);
	//TODO , 构造临时 Number 对象
	return boost::make_shared<TempNumberExprAST>(ctx,result);
}

// 数字除法
ExprASTPtr NumberExprOperation::operator_div(ASTContext ctx, ExprASTPtr lval, ExprASTPtr rval)
{
	llvm::Value * LHS =	lval->getval(ctx);
	llvm::Value * RHS =	rval->getval(ctx);
	llvm::IRBuilder<> builder(ctx.block);
	llvm::Value * result = builder.CreateSDiv(LHS,RHS);

	//TODO , 构造临时 Number 对象
	return boost::make_shared<TempNumberExprAST>(ctx,result);
}

ExprASTPtr NumberExprOperation::operator_comp(ASTContext ctx, MathOperator op, ExprASTPtr lval, ExprASTPtr rval)
{
	llvm::Value * LHS =	lval->getval(ctx);
	llvm::Value * RHS =	rval->getval(ctx);
	llvm::IRBuilder<> builder(ctx.block);
	llvm::Value * result;
	
	switch(op){
		case OPERATOR_LESS:
			result = builder.CreateICmpSLT(LHS,RHS);
			break;
		case OPERATOR_LESSEQU:
			result = builder.CreateICmpSLE(LHS,RHS);
			break;
		case OPERATOR_GREATER:
			result = builder.CreateICmpSGT(LHS,RHS);
			break;
		case OPERATOR_GREATEREQUL:
			result = builder.CreateICmpSGE(LHS,RHS);
			break;
	}
	
	//TODO , 构造临时 Number 对象
	return boost::make_shared<TempNumberExprAST>(ctx,result);
}

ExprASTPtr StringExprOperation::operator_comp(ASTContext ctx,MathOperator op, ExprASTPtr lval, ExprASTPtr rval)
{
	debug("string comp not supported yet\n");
	exit(2);
}

// 函数调用
ExprASTPtr FunctionExprOperation::operator_call(ASTContext ctx,NamedExprASTPtr calltarget,ExprListASTPtr callargs)
{
	llvm::IRBuilder<> builder(ctx.llvmfunc->getContext());
	builder.SetInsertPoint(ctx.block);

	// call functions TODO
    debug("sigfault herekkk?\n");
	llvm::Value * ret = NULL;

	//获得函数定义

	DimAST * funcdim = calltarget->nameresolve(ctx);
	
	llvm::Value * llvmfunc =funcdim->getval(ctx);

	if(!llvmfunc){ //有定义, 则直接调用, 无定义就 ... 呵呵
		llvmfunc = dynamic_cast<CallableExprTypeAST*>(funcdim)->defaultprototype(ctx,calltarget->ID->ID);
	}

	//构建参数列表
	std::vector<llvm::Value*> args;
	if(callargs && callargs->expression_list.size() )
	{
		BOOST_FOREACH( ExprASTPtr expr , callargs->expression_list)
		{
			debug("pusing args \n");
			args.push_back( expr->getval(ctx) );
		}
	}

	return calltarget->type(ctx)->createtemp( ctx, builder.CreateCall(llvmfunc,args) );
}

ExprASTPtr NumberExprTypeAST::createtemp(ASTContext ctx, llvm::Value* val)
{
	return boost::make_shared<TempNumberExprAST>(ctx,val);
}

ExprASTPtr StringExprTypeAST::createtemp(ASTContext ctx, llvm::Value* val)
{
    return boost::make_shared<TempStringExprAST>(ctx,val);
}

//TODO
ExprASTPtr CallableExprTypeAST::createtemp(ASTContext ctx, llvm::Value*v)
{
	return this->returntype->createtemp(ctx,v);
}

