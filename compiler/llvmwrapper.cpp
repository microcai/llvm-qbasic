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

llvm::Value * getconstint(int v)
{
	return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(sizeofint(),(uint64_t)v,true));
}

llvm::Value * getconstlong(long v)
{
	return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(sizeoflong(),(uint64_t)v,true));
}

static llvm::Constant *getbuiltinprotype_printf(ASTContext ctx)
{
	llvm::IRBuilder<> builder(ctx.block);
	std::vector<llvm::Type *> printfArgs;
	printfArgs.push_back(builder.getInt8PtrTy());

	llvm::Constant *printf_func = ctx.module->getOrInsertFunction("printf",
										llvm::FunctionType::get(builder.getInt32Ty(), printfArgs,
		/*必须为true, 这样才能接受可变参数*/true));

	return printf_func;
}

static llvm::Constant *getbuiltinprotype_brt_print(ASTContext ctx)
{
	llvm::IRBuilder<> builder(ctx.block);
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
		//default:
		//	std::cerr << "unknow int type of int\n" << std::endl ;
	}

	llvm::Constant *brt_print =
			ctx.module->getOrInsertFunction("brt_print",
										llvm::FunctionType::get(builder.getInt32Ty(), brt_printArgs,
		/*必须为true, 这样才能接受可变参数*/true));

	return brt_print;
}

static llvm::Constant *getbuiltinprotype_malloc(ASTContext ctx)
{
	llvm::IRBuilder<> builder(ctx.block);
	std::vector<llvm::Type *> args;

	switch(sizeof(size_t)){
	case 4:
		args.push_back(builder.getInt32Ty());
		break;
	case 8:
		args.push_back(builder.getInt64Ty());
		break;
	case 2:
		args.push_back(builder.getInt16Ty());
	}

	llvm::Constant *func = ctx.module->getOrInsertFunction("malloc",
										llvm::FunctionType::get(builder.getInt8PtrTy(), args,false));

	return func;
}

static llvm::Constant *getbuiltinprotype_free(ASTContext ctx)
{
	llvm::IRBuilder<> builder(ctx.block);
	std::vector<llvm::Type *> args;
	args.push_back(builder.getInt8PtrTy());

	llvm::Constant *func = ctx.module->getOrInsertFunction("free",
										llvm::FunctionType::get(builder.getVoidTy(), args,false));

	return func;
}

static llvm::Constant *getbuiltinprotype_strdup(ASTContext ctx)
{
	llvm::IRBuilder<> builder(ctx.block);
	std::vector<llvm::Type *> args;
	args.push_back(builder.getInt8PtrTy());

	llvm::Constant *func = ctx.module->getOrInsertFunction("strdup",
										llvm::FunctionType::get(builder.getInt8PtrTy(), args,false));
	return func;
}

// 从字符串获得标准C库和内置BRT库的标准声明
llvm::Constant * getbuiltinprotype(ASTContext ctx,const std::string name)
{
	llvm::Function * retfunc = ctx.module->getFunction(name);

	if(!retfunc){ // 根据函数名字生成

		if(name == "printf"){
			return getbuiltinprotype_printf(ctx);
		}
		if(name == "brt_print"){
			return getbuiltinprotype_brt_print(ctx);
		}
		if(name == "malloc"){
			return getbuiltinprotype_malloc(ctx);
		}
		if(name == "free"){
			return getbuiltinprotype_free(ctx);
		}
		if(name == "strdup"){
			return getbuiltinprotype_strdup(ctx);
		}

		printf("no define for %s yet\n",name.c_str());
		exit(1);
	}
	return retfunc;
}

}