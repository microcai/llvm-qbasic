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
#include <llvm/Support/Allocator.h>

#include "llvmwrapper.hpp"
#include "ast.hpp"
#include "typeast.h"

#define debug	std::printf


llvm::Value* ConstNumberExprAST::getval(
	StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
    return qbc::getconstlong(this->val);
}


//TODO:
llvm::Value* NumberExprAST::getval(StatementAST * parent,
		llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	BOOST_ASSERT(TheFunction);
	VariableRefExprAST * var =  var_num.get();
	debug("%p is the var_num\n",var);
	if(!var){
		debug("number expr for XXX \n");
		var->define = 0;
	}
	debug("number expr for %s \n" ,var->var->ID.c_str());
	return (var->getval(parent,TheFunction,insertto));
}

llvm::Value* CalcExprAST::getval(
	StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	BOOST_ASSERT(TheFunction);
	//TODO, 生成计算表达式 !
	llvm::Value * LHS =	this->lval->getval(parent,TheFunction,insertto);
	llvm::Value * RHS =	this->rval->getval(parent,TheFunction,insertto);

	llvm::IRBuilder<> builder(TheFunction->getContext());
	builder.SetInsertPoint(insertto);

	switch(this->op){
		case OPERATOR_ADD:
			return builder.CreateAdd(LHS,RHS);
		case OPERATOR_SUB:
			return builder.CreateSub(LHS,RHS);
		case OPERATOR_MUL:
			return builder.CreateMul(LHS,RHS);
		case OPERATOR_DIV:
			return builder.CreateSDiv(LHS,RHS);
		case OPERATOR_LESS:
			return builder.CreateICmpSLT(LHS,RHS);
		case OPERATOR_LESSEQU:
			return builder.CreateICmpSLE(LHS,RHS);
		case OPERATOR_GREATER:
			return builder.CreateICmpSGT(LHS,RHS);
		case OPERATOR_GREATEREQUL:
			return builder.CreateICmpSGE(LHS,RHS);
		default:
			debug("operator not supported yet\n");
			exit(1);
	}

	return insertto;
}

llvm::AllocaInst* VariableRefExprAST::nameresolve(
	StatementAST * parent,llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	BOOST_ASSERT(TheFunction);
	ExprTypeAST * exptype = this->type.get();

	//TODO: 寻找变量代表的类型
	if(!exptype->resolved()){
		debug("var %s type not found\n", var->ID.c_str());
		DimAST *dim;
 		this->type = dynamic_cast<UnknowTypeAST*>(exptype)->resolve(parent,&dim);
		this->define = dynamic_cast<VariableDimAST*>(dim);
		if(!this->define)
		{
			debug("%s is not variable\n",var->ID.c_str());
			exit(1);
		}
	}
	if(!this->define->AllocaInstRef){
		debug("=========== varable\"%s\" ======== not defined\n",var->ID.c_str());
		exit(1);
	}
	return this->define->AllocaInstRef;
}

llvm::Value* VariableRefExprAST::getptr(
	StatementAST* parent, llvm::Function* TheFunction,llvm::BasicBlock* insertto)
{
	BOOST_ASSERT(TheFunction);
	return this->nameresolve(parent,TheFunction,insertto);
}

llvm::Value* VariableRefExprAST::getval(StatementAST * parent,llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	BOOST_ASSERT(TheFunction);
	llvm::Value * ptr = this->getptr(parent,TheFunction,insertto);
	llvm::IRBuilder<> builder(TheFunction->getContext());
	builder.SetInsertPoint(insertto);
	return builder.CreateLoad(ptr);
}

// resolve the function name to type and arge list, check for consistence
llvm::AllocaInst* CallExprAST::nameresolve(StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	//TODO 搜索函数类型信息, 做各种参数比较
	llvm::IRBuilder<>	builder(insertto);

	debug("===searching for function %s ====\n",var->ID.c_str() );

	if( ! (this->target = module->getFunction(this->var->ID)) ){
		// 生成函数定义

		//TODO 安装正确的类型生成

		//FIXME 现在就当是无参数无返回值的好了
		
		std::vector<llvm::Type *> targetArgs;

		llvm::Constant * f = module->getOrInsertFunction(
			var->ID,llvm::FunctionType::get(builder.getInt32Ty(),targetArgs,true));

		debug("target is %p\n",target);
		
		this->target = llvm::cast<llvm::Function>(f);		
	}
	return NULL;
}

//TODO call function and use the result
llvm::Value* CallExprAST::getval(StatementAST* parent, llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	debug("===I will call to %s ====\n",var->ID.c_str() );

	llvm::IRBuilder<>	builder(insertto);

	builder.CreateCall(target);
}

llvm::BasicBlock* DimAST::Codegen(llvm::Function*, llvm::BasicBlock* insertto)
{
    debug("%s should not be called\n",__func__);
    exit(1);
	return insertto;
}

llvm::BasicBlock* EmptyStmtAST::Codegen(llvm::Function*, llvm::BasicBlock* insertto)
{
    debug("empty statement called !\n");
    return insertto;
}

llvm::BasicBlock* StatementAST::Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	if(!TheFunction ){
		debug("statements called with TheFunction=null\n");
	}else{
		debug("statements called with good TheFunction\n");
	}

	BOOST_FOREACH( StatementASTPtr stmt , this->substatements)
	{
		if(stmt)
			insertto = stmt->Codegen(TheFunction,insertto);
		else
			debug("strange, stmt is null\n");
	}
	return insertto;
}
llvm::BasicBlock* PrintIntroAST::Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	BOOST_ASSERT(TheFunction);
	debug("PrintIntroAST expr for \n");
	return insertto;
}

//* 调用函数
llvm::BasicBlock* CallStmtAST::Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	debug("call function? generating the call here!\n");

	// 首先, name solve
	callable->nameresolve(this,TheFunction,insertto);

	// 然后调用吧

	callable->getval(this,TheFunction,insertto);

	// 忽略返回数值
	return insertto;
}

//TODO 为 print 语句生成,
llvm::BasicBlock* PrintStmtAST::Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	bool need_brt = false;
    debug("generating llvm-IR for calling PRINT\n");
	BOOST_ASSERT(TheFunction);

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
	if(! callargs->expression_list.empty()){
		// TODO : 支持字符串的版本修改第三个参数开始为参数对.
		//std::for_E
		BOOST_FOREACH(ExprASTPtr argitem,callargs->expression_list)
		{
			argitem->nameresolve(this,TheFunction,insertto);
			
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
					args.push_back(	argitem->getval(this,TheFunction,insertto) );
					break;
				case sizeof(int):
					printfmt += "%d\t";
					args.push_back(	argitem->getval(this,TheFunction,insertto) );
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
llvm::BasicBlock* VariableDimAST::Codegen(llvm::Function *TheFunction,llvm::BasicBlock * insertto)
{
	BOOST_ASSERT(TheFunction);
	llvm::IRBuilder<> builder(&TheFunction->getEntryBlock(),
							  TheFunction->getEntryBlock().begin());
	builder.SetInsertPoint(insertto);
	
	ExprTypeAST * exptype = this->type.get();

	debug("allocate stack for var %s , type %s\n", name.c_str(), exptype->name.c_str()	);

	if(!exptype->resolved()){
		debug("var %s type not found\n", this->name.c_str()	);
 		this->type = dynamic_cast<UnknowTypeAST*>(exptype)->resolve(this, NULL);
	}
	exptype = this->type.get();	
	AllocaInstRef = builder.CreateAlloca(exptype->llvmtype(), 0 , this->name );
	return insertto;
}

// 赋值语句
llvm::BasicBlock* AssigmentAST::Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	BOOST_ASSERT(TheFunction);
	debug("called for number assigment\n");
	//return NULL;
	llvm::Value * LHS =	this->lval->getptr(this,TheFunction,insertto);
	llvm::Value * RHS =	this->rval->getval(this,TheFunction,insertto);

	llvm::IRBuilder<> builder(TheFunction->getContext());
	builder.SetInsertPoint(insertto);	
	// 生成赋值语句,因为是简单的整型赋值,所以可以直接生成而不用调用 operator==()
	builder.CreateStore(RHS,LHS);
	return insertto;
}

// 生成函数 , TODO 参数和反正值支持
llvm::BasicBlock* FunctionDimAST::Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	BOOST_ASSERT(!TheFunction);
	BOOST_ASSERT(!insertto);

	debug("generating function %s and its body now\n", this->name.c_str());

	//首先生成全局可用的外部辅助函数
	llvm::IRBuilder<> builder(llvm::getGlobalContext());
	llvm::FunctionType *funcType = llvm::FunctionType::get(builder.getVoidTy(), false);
	llvm::Function *mainFunc =
		llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, this->name , AST::module);
	llvm::BasicBlock *entry = llvm::BasicBlock::Create(builder.getContext(), "entrypoint", mainFunc);
	builder.SetInsertPoint(entry);	
	//开始生成代码
	//now code up the function body
	void * p = this->body->Codegen(mainFunc,entry);
	//llvm::BasicBlock *ret = llvm::BasicBlock::Create(builder.getContext(),"" , mainFunc);

	builder.SetInsertPoint((llvm::BasicBlock*)p);
	//返回值
	builder.CreateRetVoid();
	return insertto;
}

// IF ELSE 语句
llvm::BasicBlock* IFStmtAST::Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	BOOST_ASSERT(TheFunction);
	debug("if else statement\n");

	// true cond is always there
	llvm::BasicBlock* cond_true = llvm::BasicBlock::Create(TheFunction->getContext(), "cond_true", TheFunction);
	llvm::BasicBlock* cond_false ;

	if( this->_else.get()){
		cond_false = llvm::BasicBlock::Create(TheFunction->getContext(), "cond_false",TheFunction);		
	}
	llvm::BasicBlock* cond_continue = llvm::BasicBlock::Create(TheFunction->getContext(), "continue", TheFunction);
	
	if(! this->_else.get()){
		cond_false = cond_continue;
	}

	llvm::IRBuilder<> builder(insertto);

	llvm::Value * expcond = this->_expr->getval(this,TheFunction,insertto);
	expcond = builder.CreateICmpNE(expcond, qbc::getconstlong(0), "tmp");
	builder.CreateCondBr(expcond, cond_true, cond_false);

	// generating true	
	this->_then->Codegen(TheFunction,cond_true);
	builder.SetInsertPoint(cond_true);
	builder.CreateBr(cond_continue);

	// generating false , if there is any
	if( this->_else.get()){
		this->_else->Codegen(TheFunction,cond_false);
		builder.SetInsertPoint(cond_false);
		builder.CreateBr(cond_continue);
	}
	builder.CreateBr(cond_continue);
	return cond_continue;
}

llvm::BasicBlock* LoopAST::bodygen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
    return loopbody->Codegen(TheFunction,insertto);
}

llvm::BasicBlock* WhileLoopAST::Codegen(llvm::Function* TheFunction, llvm::BasicBlock* insertto)
{
	BOOST_ASSERT(TheFunction);
	debug("generation code for while statement\n");

	llvm::BasicBlock* cond_while = llvm::BasicBlock::Create(TheFunction->getContext(), "", TheFunction);

	llvm::BasicBlock* while_body = llvm::BasicBlock::Create(TheFunction->getContext(), "", TheFunction);


	llvm::BasicBlock* cond_continue = llvm::BasicBlock::Create(TheFunction->getContext(), "", TheFunction);

	llvm::IRBuilder<> builder(TheFunction->getContext());
	builder.SetInsertPoint(insertto);
	builder.CreateBr(cond_while);

	builder.SetInsertPoint(cond_while);
	llvm::Value * expcond = this->condition->getval(this,TheFunction,cond_while);
	expcond = builder.CreateICmpEQ(expcond, qbc::getconstlong(0), "tmp");
	builder.CreateCondBr(expcond, cond_continue, while_body);

	this->bodygen(TheFunction,while_body);
	builder.SetInsertPoint(while_body);
	builder.CreateBr(cond_while);
	
	return cond_continue;	
}
