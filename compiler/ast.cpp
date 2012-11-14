/*
    <one line to give the library's name and an idea of what it does.>
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
#include <iostream>
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

#include "ast.hpp"

#define debug printf

llvm::Module * AST::module ;


AST::AST()
{
}

AST::~AST()
{
}

ConstExprAST::ConstExprAST(const std::string* val)
{
	constval = val->c_str();
}

LetExprAST::LetExprAST(VariableRefExprASTPtr l, ExprASTPtr r)
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
llvm::Value* LetExprAST::Codegen()
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
llvm::Value* PrintStmtAST::Codegen()
{
    debug("generating llvm-IR for calling PRINT\n");
	
	//llvm::CallInst::Create();
	llvm::IRBuilder<> builder(llvm::getGlobalContext());

	std::vector<llvm::Type *> brt_printArgs;
	switch(sizeof(int)){
		case 4:
			brt_printArgs.push_back(builder.getInt32Ty());
			break;
		case 8:
			brt_printArgs.push_back(builder.getInt64Ty());
			break;
		case 2:
			brt_printArgs.push_back(builder.getInt16Ty());
		default:
			std::cerr << "unknow int type" << std::endl ;
	}

	llvm::Constant *brt_print =
			module->getOrInsertFunction("brt_print",
										llvm::FunctionType::get(builder.getInt32Ty(), llvm::ArrayRef<llvm::Type*>(brt_printArgs), true));

	
	// creat call into BASIC Runtime function brt_print
	builder.CreateCall(brt_print,0,"PRINT");

	// int brt_print( int print_intro , int numargs , ... );
	
	//llvm::Function * printf = llvm::Function::get(

	//builder.CreateCall();
}

PrintStmtAST::PrintStmtAST(FunctionParameterListAST args)
	:callargs(args)
{
}

CallExprAST::CallExprAST(FunctionParameterListAST args)
	:callargs(args)
{
	
}
