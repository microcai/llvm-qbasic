#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/foreach.hpp>

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

llvm::Type* NumberTypeAST::llvmtype()
{
	debug("number type called\n");
	return llvm::Type::getInt64Ty(llvm::getGlobalContext());
}
