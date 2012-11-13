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
#include <llvm/Instructions.h>
#include <llvm/Instruction.h>
#include <llvm/Support/IRBuilder.h>

#include "ast.h"

#define debug printf

llvm::Module * AST::module ;


AST::AST()
	:next()
{

}

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
// nop 语句
llvm::Value* StatementAST::Codegen()
{
	debug("empty statementn\n");
	llvm::Value * l = llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt());
	llvm::Value * r = llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt());
	return llvm::BinaryOperator::CreateNUWSub(l,r);
}

// 为 LET A=XX 赋值语句生成IR代码
llvm::Value* LetStatementAST::Codegen()
{
	//TODO 只能为简单类型生成赋值语句
	//TODO 复杂类型实质是要调用 operator ==
	
    llvm::Value * r = this->rval->Codegen();
	llvm::Value * l = this->lval->Codegen();
//	return llvm::
}

// 为立即数生成 IR
llvm::Value* ConstExprAST::Codegen()
{
	debug("%s\n",__func__);
	long v = boost::lexical_cast<long>(this->constval);
    return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(64,v,1));
}

//TODO 为 print 语句生成,
llvm::Value* PrintAST::Codegen()
{
    debug("call PRINT\n");
	
	//llvm::CallInst::Create();
	llvm::IRBuilder<> builder(llvm::getGlobalContext());

	//llvm::Function * printf = llvm::Function::get(

	//builder.CreateCall();
}

PrintAST::PrintAST(FunctionParameterListAST args):
	printlist(args)
{    
}