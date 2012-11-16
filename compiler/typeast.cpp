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
#include "typeast.h"

#define debug printf

UnknowTypeAST::UnknowTypeAST(const std::string _name)
	:ExprTypeAST(-1),varname(_name)
{

}

llvm::Type* NumberTypeAST::llvmtype()
{
	debug("number type called\n");
	return llvm::Type::getInt64Ty(llvm::getGlobalContext());
}

ExprTypeAST::ExprTypeAST(size_t __size, const std::string _name)
	:_size(__size),name(_name)
{
}

NumberTypeAST::NumberTypeAST()
	:ExprTypeAST(sizeof(long),"LONG")
{

}

ExprTypeASTPtr UnknowTypeAST::resolve(StatementAST* theblock,DimAST ** vardim)
{
	BOOST_ASSERT(theblock);
	
	debug("finding type for %s\n",varname.c_str());
	
	StatementsAST * functionblock = theblock->parent;

	if(functionblock)
	{
		//查找变量声明
		for(std::list< StatementASTPtr >::iterator it = functionblock->statements.begin();
			it != functionblock->statements.end();
			it ++ )
		{
			DimAST * dim = dynamic_cast<DimAST*>(it->get());
			if(!dim)
				continue;
			//	查看变量声明
			debug("god dim block %p\n",dim);
			if(dim->name == this->varname){
				if(vardim)
					*vardim = dim;
				if(dim->type->resolved()){
					debug("变量 %s 的类型找到, 是 %s\n", varname.c_str(), dim->type->name.c_str());
					return dim->type;
				}
				else
					return dynamic_cast<UnknowTypeAST*>(dim)->resolve(dim,vardim);
			}
		}
		//到父类型去
		if(functionblock->parent)
			return UnknowTypeAST::resolve(functionblock->parent,vardim);
	}
	//TODO: 打印行号信息
	printf("variable %s not defined!", this->name.c_str());
	exit(1);
}

