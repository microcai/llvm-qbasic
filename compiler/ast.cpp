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
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/make_shared.hpp>

#include <llvm/DerivedTypes.h>
#include <llvm/Constants.h>
#include <llvm/Constant.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Instructions.h>
#include <llvm/Instruction.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/Support/Allocator.h>

#include "llvmwrapper.hpp"
#include "ast.hpp"

#define debug	std::printf

llvm::Module * AST::module ;


AST::AST()
{
}

AST::~AST()
{
}

void StatementAST::addchild(StatementAST* item) {
    if(item) {
        this->substatements.push_back(StatementASTPtr(item));
        item->parent = this;
    }
}


PrintStmtAST::PrintStmtAST(PrintIntroAST * intro,ExprListAST* args)
	:callargs(args),print_intro(intro)
{
}

PrintIntroAST::PrintIntroAST() {}

ConstNumberExprAST::ConstNumberExprAST(const int64_t v)
	:val(v)
{
}

DimAST::DimAST(const std::string _name, ExprTypeASTPtr _type)
	:name(_name),type(_type)
{

}

VariableDimAST::VariableDimAST(const std::string _name, ExprTypeASTPtr _type)
	:DimAST(_name,_type)
{
}

VariableRefExprAST::VariableRefExprAST(const std::string _name)
	:ExprAST(ExprTypeASTPtr(new UnknowTypeAST(_name))),var(_name)
{

}

AssigmentAST::AssigmentAST(VariableRefExprASTPtr _lval, ExprASTPtr _rval)
	:lval(_lval),rval(_rval)
{
	
}

NumberExprAST::NumberExprAST(VariableExprASTPtr _var_num)
	:var_num(_var_num),ExprAST(ExprTypeASTPtr(new NumberTypeAST()))
{
	debug("numver expresion is a local var reference code %p\n",var_num.get());
	// the varable is a type of number, right ?	
}

CalcExprAST::CalcExprAST(ExprASTPtr lhs, MathOperator OP, ExprASTPtr rhs)
	:rval(rhs),lval(lhs),op(OP),ExprAST(ExprTypeASTPtr(new UnknowTypeAST("@@expresion@@")))
{
	
}

FunctionDimAST::FunctionDimAST(const std::string _name, ExprTypeASTPtr _type)
	:DimAST(_name,_type)
{
	
}


DefaultMainFunctionAST::DefaultMainFunctionAST(StatementAST * body)
	:FunctionDimAST("main",ExprTypeASTPtr( new VoidTypeAST())  )
{
	this->body = StatementASTPtr(body);
}


WhileLoopAST::WhileLoopAST(ExprASTPtr _condition , StatementASTPtr body)
	:condition(_condition),LoopAST(body)
{
}

ReferenceAST::ReferenceAST(std::string* tID) :ID(*tID)
{
	
}

void ExprListAST::Append(ExprAST* exp)
{
    expression_list.push_back( ExprASTPtr(exp));
}
