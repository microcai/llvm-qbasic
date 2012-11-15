/*
    defination of QBASIC Abstruct Syntax Tree - The Expresion Type
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
	#include <llvm/Type.h> // for KDevelop Only
	#include "ast.hpp" // for KDevelop Only
	#error "Don't include it diretly, use #include<ast.hpp>"
#endif


// 变量类型定义.
class ExprTypeAST : public AST
{
	size_t			_size;
public:
    ExprTypeAST(size_t __size):_size(__size){}
	std::string		name; // name of the type. // for debug only
	virtual	size_t	size(){return _size;} // memory size of this type , can be overided

	virtual llvm::Type *	llvmtype() = 0; // llvm type of this type, NULL if not reperentable directly
};
typedef	boost::shared_ptr<ExprTypeAST> ExprTypeASTPtr;

class VoidTypeAST : public ExprTypeAST
{
public:
    VoidTypeAST():ExprTypeAST(0){};
	llvm::Type *	llvmtype(){return NULL;};
};

class NumberTypeAST : public ExprTypeAST
{
public:
	NumberTypeAST():ExprTypeAST(sizeof(long)){}
	llvm::Type *	llvmtype();
};

// 指针类型
class PointerTypeAST : public ExprTypeAST
{

};

// 引用类型
class ReferenceTypeAST : public ExprTypeAST
{

};


