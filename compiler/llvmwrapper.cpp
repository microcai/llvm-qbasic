/*
    some helper functions for generationg llvm-IR
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

#include <llvm/Support/IRBuilder.h>
#include "qbc.h"
#include "ast.hpp"
#include "llvmwrapper.hpp"


namespace qbc{

static unsigned sizeofint()
{
	return sizeof(int)*8;
}

static unsigned sizeoflong()
{
	return sizeof(long)*8;
}

llvm::Value * getnull()
{
	return llvm::ConstantPointerNull::get(llvm::Type::getInt8PtrTy(llvm::getGlobalContext()));
}

llvm::Value * getconstfalse()
{
	return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(1,0,true));
}

llvm::Value * getconsttrue()
{
	return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(1,1,true));
}

llvm::Value * getconstint(int v)
{
	return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(sizeofint(),(uint64_t)v,true));
}

llvm::Value * getconstlong(long v)
{
	return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(sizeoflong(),(uint64_t)v,true));
}

llvm::Type * getbooltype()
{
	return llvm::Type::getInt1Ty(llvm::getGlobalContext());
}

llvm::Type * getplatformlongtype()
{
	switch(sizeof(long)){
		case 8:
			return llvm::Type::getInt64Ty(llvm::getGlobalContext());
		case 4:
			return llvm::Type::getInt32Ty(llvm::getGlobalContext());
		case 2:
			return llvm::Type::getInt16Ty(llvm::getGlobalContext());
	}
}

#define GETBUILTINTYPE_ENTER()	\
	llvm::IRBuilder<> builder(ctx.block); std::vector<llvm::Type *> args
		
#define	BUILTINTYPE_DEFINE(x ,  ret , block )	\
	static llvm::Constant *getbuiltinprotype_##x(ASTContext ctx) \
	{\
		GETBUILTINTYPE_ENTER(); \
		block \
		llvm::Constant *func = ctx.module->getOrInsertFunction(#x, \
		llvm::FunctionType::get(builder.get##ret##Ty(), args,false)); \
		return func; \
	}

static llvm::Constant *getbuiltinprotype_printf(ASTContext ctx)
{
	GETBUILTINTYPE_ENTER();
	args.push_back(builder.getInt8PtrTy());

	llvm::Constant *printf_func = ctx.module->getOrInsertFunction("printf",
										llvm::FunctionType::get(builder.getInt32Ty(), args,
		/*必须为true, 这样才能接受可变参数*/true));

	return printf_func;
}

static llvm::Constant *getbuiltinprotype_brt_print(ASTContext ctx)
{
	GETBUILTINTYPE_ENTER();
	args.push_back(getplatformlongtype());

	llvm::Constant *brt_print =
			ctx.module->getOrInsertFunction("brt_print",
										llvm::FunctionType::get(builder.getInt32Ty(), args,
		/*必须为true, 这样才能接受可变参数*/true));

	return brt_print;
}

BUILTINTYPE_DEFINE(malloc , Int8Ptr , {
	args.push_back(getplatformlongtype());}  )

BUILTINTYPE_DEFINE(calloc , Int8Ptr , {
	args.push_back(getplatformlongtype());
	args.push_back(getplatformlongtype());}  )

BUILTINTYPE_DEFINE(free , Void , {args.push_back(builder.getInt8PtrTy());}  )

BUILTINTYPE_DEFINE(strdup , Int8Ptr , {args.push_back(builder.getInt8PtrTy());}  )

static llvm::Constant *getbuiltinprotype_strlen(ASTContext ctx)
{
	GETBUILTINTYPE_ENTER();

	args.push_back(builder.getInt8PtrTy());

	llvm::Constant *func = ctx.module->getOrInsertFunction("strlen",
										llvm::FunctionType::get(getplatformlongtype(), args,false));
	return func;
}

BUILTINTYPE_DEFINE(strcpy , Int8Ptr , {
	args.push_back(builder.getInt8PtrTy());
	args.push_back(builder.getInt8PtrTy());}  )

BUILTINTYPE_DEFINE(strcat , Int8Ptr , {
	args.push_back(builder.getInt8PtrTy());
	args.push_back(builder.getInt8PtrTy());}  )

BUILTINTYPE_DEFINE(strcmp , Int32 , {
	args.push_back(builder.getInt8PtrTy());
	args.push_back(builder.getInt8PtrTy());}  )

BUILTINTYPE_DEFINE(btr_qbarray_new , Void , {
	args.push_back(builder.getInt8PtrTy());
	args.push_back(getplatformlongtype());}  )


BUILTINTYPE_DEFINE(btr_qbarray_free , Void , {
	args.push_back(builder.getInt8PtrTy());}  )

BUILTINTYPE_DEFINE(btr_qbarray_at , Int8Ptr , {
	args.push_back(builder.getInt8PtrTy());
	args.push_back(getplatformlongtype());}  )

#undef BUILTINTYPE_DEFINE
#undef GETBUILTINTYPE_ENTER

// 从字符串获得标准C库和内置BRT库的标准声明
llvm::Constant * getbuiltinprotype(ASTContext ctx,const std::string name)
{
	llvm::Function * retfunc = ctx.module->getFunction(name);
#define			RETURNBUILTINENTRY(x)	\
	if(name == #x ) { return getbuiltinprotype_##x (ctx); }
	
	if(!retfunc){ // 根据函数名字生成
		RETURNBUILTINENTRY(printf)
		RETURNBUILTINENTRY(brt_print)
		RETURNBUILTINENTRY(malloc)
		RETURNBUILTINENTRY(calloc)
		RETURNBUILTINENTRY(free)
		RETURNBUILTINENTRY(strdup)
		RETURNBUILTINENTRY(strlen)
		RETURNBUILTINENTRY(strcpy)
		RETURNBUILTINENTRY(strcat)
		RETURNBUILTINENTRY(strcmp)
		RETURNBUILTINENTRY(btr_qbarray_new)
		RETURNBUILTINENTRY(btr_qbarray_free)
		RETURNBUILTINENTRY(btr_qbarray_at)

		printf("no define for %s yet\n",name.c_str());
		exit(1);
	}
#undef RETURNBUILTINENTRY
	return retfunc;
}

}