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

#include <boost/lexical_cast.hpp>
#include <llvm/DerivedTypes.h>
#include <llvm/Constants.h>
#include <llvm/Constant.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Analysis/Verifier.h>

#include "ast.h"

#define debug printf

AST::~AST()
{
}

ConstExprAST::ConstExprAST(const std::string* val)
{
	constval = val->c_str();
}

LetStatementAST::LetStatementAST(VariableRefExprASTPtr l, ExprASTPtr r)
	:lval(l),rval(r)
{

}

// 为 LET A=XX 赋值语句生成IR代码
llvm::Value* LetStatementAST::Codegen()
{
    
}

// 为立即数生成 IR
llvm::Value* ConstExprAST::Codegen()
{
	debug("%s\n",__func__);
	long v = boost::lexical_cast<long>(this->constval);
    return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(64,v,1));
}
