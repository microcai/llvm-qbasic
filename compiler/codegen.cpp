/*
    Main Code Generation 
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
#include "typeast.h"

#define debug	std::printf

llvm::Value* StatementsAST::Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	for(
		std::list< StatementASTPtr >::iterator it = this->statements.begin();
		it != this->statements.end();
		it ++)
	{
		StatementASTPtr stmt = *it;
		stmt->Codegen(TheFunction,insertto);		
	}
	return &TheFunction->back();
}

// 为立即数生成 IR
llvm::Value* ConstExprAST::Codegen(StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	debug("%s\n",__func__);
    return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(64,this->constval,10));
}

llvm::Value* ConstNumberExprAST::Codegen(
	StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
    return qbc::getconstlong(this->val);
}

llvm::Value* PrintIntroAST::Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	debug("PrintIntroAST expr for \n");
	return insertto;
}
//TODO 为 print 语句生成,
llvm::Value* PrintStmtAST::Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	bool need_brt = false;
    debug("generating llvm-IR for calling PRINT\n");

	//llvm::CallInst::Create();
	llvm::IRBuilder<> builder(TheFunction->getContext());
	builder.SetInsertPoint(insertto);

	std::vector<llvm::Type *> brt_printArgs;
	std::vector<llvm::Type *> printfArgs;
	printfArgs.push_back(builder.getInt8PtrTy());

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
										llvm::FunctionType::get(builder.getInt32Ty(), brt_printArgs,
		/*必须为true, 这样才能接受可变参数*/true));

	llvm::Constant *printf_func = module->getOrInsertFunction("printf",
										llvm::FunctionType::get(builder.getInt32Ty(), printfArgs,
		/*必须为true, 这样才能接受可变参数*/true));

	std::vector<llvm::Value*> args; // 先插入第3个开始的参数.
	std::string	printfmt;

	//第三个参数开始是 ... 参数对.
	if(callargs->size() > 0){
		// TODO : 支持字符串的版本修改第三个参数开始为参数对.
		//std::for_E	BOOST_FOREACH(ExprASTPtr argitem,callargs->printlist);
		for( std::vector<ExprASTPtr>::iterator it = callargs->printlist.begin();
			it != callargs->printlist.end() ; it++)
		{
			ExprASTPtr argitem = *it;
			switch(argitem->type->size()){ //按照大小来啊,果然
				case sizeof(long): // 整数产量的类型

					if( dynamic_cast<PointerTypeAST*>(argitem->type.get()) ){
						//指针类型
						printfmt += "%p\t"; //TODO: 字符串
					debug("add code for print list args type %%p\n");

					}else{
					debug("add code for print list args type %%ld\n");
						printfmt += "%ld\t";
					}
					args.push_back(	argitem->Codegen(this,TheFunction,insertto) );
					break;
				case sizeof(int):
					printfmt += "%d\t";
					args.push_back(	argitem->Codegen(this,TheFunction,insertto) );
					break;
				case 0:
					printfmt +="\n"; // 很重要,呵呵
				default:
					//TODO, 目前只需要支持 number , brt_print 也只是支持数字
					debug("print argument not supported\n");
			}
		}
	}

	// 现在 brt 忽略第一个参数 , 其实质是 一个 map 到 FILE* 的转化, 由 btr_print 实现
	//第二个参数是打印列表.
	args.insert(args.begin(), builder.CreateGlobalStringPtr(printfmt.c_str()));

	//调用 print
	if(need_brt){
		args.insert(args.begin(), qbc::getconstint(0) );
		builder.CreateCall(brt_print,args ,"PRINT");
	}
	else{
		builder.CreateCall(printf_func,args ,"PRINT_via_printf");
	}

	return insertto;
}

//为变量分配空间
llvm::Value* VariableDimAST::Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	llvm::IRBuilder<> builder(&TheFunction->getEntryBlock(),
							  TheFunction->getEntryBlock().begin());
	//builder.SetInsertPoint(,insertto);
	
	ExprTypeAST * exptype = this->type.get();

	debug("allocate stack for var %s , type %s\n", name.c_str(), exptype->name.c_str()	);

	if(!exptype->resolved()){
		debug("var %s type not found\n", this->name.c_str()	);
 		this->type = dynamic_cast<UnknowTypeAST*>(exptype)->resolve(this, NULL);
	}
	exptype = this->type.get();	
	AllocaInstRef = builder.CreateAlloca(exptype->llvmtype(), 0 , this->name );
	return AllocaInstRef;
}


llvm::Value* VariableRefExprAST::Codegen(StatementAST * parent,llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	ExprTypeAST * exptype = this->type.get();

	//TODO: 寻找变量代表的类型
	if(!exptype->resolved()){
		debug("var %s type not found\n", var.c_str());
		DimAST *dim;
 		this->type = dynamic_cast<UnknowTypeAST*>(exptype)->resolve(parent,&dim);
		this->define = dynamic_cast<VariableDimAST*>(dim);
		if(!this->define)
		{
			debug("%s is not variable\n",var.c_str());
			exit(1);
		}
	}
	exptype = this->type.get();

	return this->define->AllocaInstRef;
	//找到生成的变量的定义语句
	exit(1);
}

llvm::Value* NumberAssigmentAST::Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	debug("called for number assigment\n");
	//return NULL;
	llvm::Value * LHS =	this->lval->Codegen(this,TheFunction,insertto);
	llvm::Value * RHS =	this->rval->Codegen(this,TheFunction,insertto);

	llvm::IRBuilder<> builder(TheFunction->getContext());
	builder.SetInsertPoint(insertto);	
	// 生成赋值语句,因为是简单的整型赋值,所以可以直接生成而不用调用 operator==()
	return builder.CreateStore(RHS,LHS);
}

//TODO:
llvm::Value* NumberExprAST::Codegen(StatementAST * parent,
		llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	VariableRefExprAST * var =  var_num.get();
	debug("%p is the var_num\n",var);
	if(!var){
		debug("number expr for XXX \n");
		var->define = 0;
	}
	debug("number expr for %s \n" ,var->var.c_str());

	llvm::IRBuilder<> builder(TheFunction->getContext());
	builder.SetInsertPoint(insertto);

	llvm::Value * alloc = (var->Codegen(parent,TheFunction,insertto));
	return builder.CreateLoad(alloc);
}

