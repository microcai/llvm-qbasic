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

UnknowTypeAST::UnknowTypeAST()
	:ExprTypeAST(-1)
{
	
}

UnknowTypeAST::UnknowTypeAST(ReferenceASTPtr _name)
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
	debug("finding type for %s\n",varname->ID.c_str());
	
	if(theblock)
	{
		//查找变量声明
		BOOST_FOREACH( StatementASTPtr stmt , theblock->substatements)
		{
			DimAST * dim = dynamic_cast<DimAST*>(stmt.get());
			if(!dim)
				continue;
			//	查看变量声明
			debug("god dim block %p\n",dim);
			if(dim->name == this->varname->ID){
				if(vardim)
					*vardim = dim;
				if(dim->type->resolved()){
					debug("变量 %s 的类型找到, 是 %s\n", varname->ID.c_str(), dim->type->name.c_str());
					return dim->type;
				}
				else
					return dynamic_cast<UnknowTypeAST*>(dim)->resolve(dim,vardim);
			}
		}
		//到父类型去
		return resolve(theblock->parent,vardim);
	}
	//TODO: 打印行号信息
	printf("variable %s not defined!", this->name.c_str());
	exit(1);
}

