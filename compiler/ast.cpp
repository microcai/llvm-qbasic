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
#include "type.hpp"

#define debug	std::printf

AST::AST(){}
AST::~AST(){}

PrintStmtAST::PrintStmtAST(PrintIntroAST * intro,ExprListAST* args)
	:callargs(args),print_intro(intro)
{
}

PrintIntroAST::PrintIntroAST()
	:ConstNumberExprAST(0)
{

	
}


DimAST::DimAST(const std::string _name, const std::string _type)
	:name(_name),type(_type)
{

}

VariableDimAST::VariableDimAST(const std::string _name, const std::string _type)
	:DimAST(_name,_type)
{
}

FunctionDimAST::FunctionDimAST(const std::string _name,ArgumentDimsAST*	_callargs, const std::string _type)
	:DimAST(_name,_type),callargs(_callargs)
{
	
}


DefaultMainFunctionAST::DefaultMainFunctionAST(CodeBlockAST * body)
	:FunctionDimAST("main",0,"" )
{
	this->body = CodeBlockASTPtr(body);
}


WhileLoopAST::WhileLoopAST(ExprASTPtr _condition , CodeBlockAST* body)
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

CallStmtAST::CallStmtAST(CallExprAST* callexp)
	:callable(callexp)
{
	
}

ReturnAST::ReturnAST(ExprAST* _expr)
	:expr(_expr)
{

}

int CodeBlockAST::find(StatementAST* child)
{
	int index = 0;
	BOOST_FOREACH( StatementASTPtr item , statements)
	{
		if( item == child ){
			return index;
		}
		index ++;
	}
	debug("not a child??????????\n");
	exit(1);
}

void CodeBlockAST::addchild(StatementAST* item)
{
    if(item) {
		debug("here === addchild1\n");
        this->statements.push_back(StatementASTPtr(item));
        item->parent = this;
    }
}
void CodeBlockAST::addchild(StatementsAST* items)
{
	std::list< StatementASTPtr >::iterator it = items->begin();
	for(;it != items->end() ; it ++)
	{
		debug("here === addchild2 -- beg\n");
		(*it)->parent = this;
//		item->parent = this;
		debug("here === addchild2\n");
        this->statements.push_back(*it);
	}
}

CodeBlockAST::CodeBlockAST(StatementsAST* items)
	:parent(0)
{
    addchild(items);
}
CodeBlockAST::CodeBlockAST(StatementAST* item)
	:parent(0)
{
    addchild(item);
}

AssigmentAST::AssigmentAST(NamedExprAST* lval, ExprAST* rval)
	:assignexpr(new AssignmentExprAST(lval,rval))
{
}

ArgumentDimAST::ArgumentDimAST(const std::string _name, const std::string _type)
	:VariableDimAST(_name,_type),modified_stackvar(0)
{	
}
