
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

llvm::Value* NumberExprTypeAST::Alloca(ASTContext ctx, const std::string _name)
{
	//TODO , 在堆栈上分配个变量
}

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

llvm::Type* NumberExprTypeAST::llvm_type(ASTContext ctx)
{
	return llvm::Type::getInt64Ty(ctx.module->getContext());
}

