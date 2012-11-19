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
#include <llvm/Support/IRBuilder.h>

#include "ast.hpp"
#include "type.hpp"
#include "llvmwrapper.hpp"

#define debug std::printf

static	NumberExprOperation	numberop;
static	StringExprOperation stringop;

ExprOperation* NumberExprTypeAST::getop()
{
	return & numberop;
}

ExprOperation* StringExprTypeAST::getop()
{
	return & stringop;
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
	
}
