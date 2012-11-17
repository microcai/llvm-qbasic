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
#include "type.hpp"

#define debug	std::printf


#if 0
llvm::AllocaInst* VariableRefExprAST::nameresolve(ASTContext ctx)
{

	BOOST_ASSERT(ctx.astfunc);
	ExprTypeAST * exptype = this->type.get();

	//TODO: 寻找变量代表的类型
	if(!exptype->resolved()){
		debug("var %s type not found\n", var->ID.c_str());
		DimAST *dim;
 		this->type = dynamic_cast<UnknowTypeAST*>(exptype)->resolve(ctx.astfunc,&dim);
		this->define = dynamic_cast<VariableDimAST*>(dim);
		if(!this->define)
		{
			debug("%s is not variable\n",var->ID.c_str());
			exit(1);
		}
	}
	if(!this->define->AllocaInstRef){
		debug("=========== varable\"%s\" ======== not defined in block , maybe in argument?\n",
			  var->ID.c_str());
		//exit(1);
	}

	return this->define->AllocaInstRef;
}

llvm::Value* VariableRefExprAST::getptr(ASTContext ctx)
{
	BOOST_ASSERT(TheFunction);
	llvm::Value * ptr = this->nameresolve(ctx);
	if(!ptr){
		this->define->Codegen(ctx);
	}
	return this->define->AllocaInstRef;
}

llvm::Value* VariableRefExprAST::getval(ASTContext ctx)
{
	BOOST_ASSERT(ctx.llvmfunc);
	llvm::IRBuilder<> builder(ctx.llvmfunc->getContext());
	builder.SetInsertPoint(ctx.block);
	
	llvm::Value * ptr = this->nameresolve(ctx);
	if(ptr){
		return builder.CreateLoad(ptr);
	}else{
		// try to look up in argument
		// not found
		llvm::Function::arg_iterator llvmarg_it = ctx.llvmfunc->arg_begin();

		for(; llvmarg_it != ctx.llvmfunc->arg_end() ;  llvmarg_it++	){
			
			if(llvmarg_it->getName() == this->var->ID)
			{
				debug("got name \"%s\" as argument!\n",this->var->ID.c_str());
				return llvmarg_it;
			}
		}
		debug(":(\n");exit(1);
	}
	return builder.CreateLoad(ptr);
}

// resolve the function name to type and arge list, check for consistence
llvm::AllocaInst* CallExprAST::nameresolve(ASTContext ctx)
{
	//TODO 搜索函数类型信息, 做各种参数比较
	llvm::IRBuilder<>	builder(ctx.block);

	debug("===searching for function %s ====\n",var->ID.c_str() );

	if( ! (this->target = module->getFunction(this->var->ID)) ){
		// 生成函数定义

		//TODO 安装正确的类型生成

		//FIXME 现在就当是无参数无返回值的好了
		
		std::vector<llvm::Type *> targetArgs;

		llvm::Constant * f = module->getOrInsertFunction(
			var->ID,llvm::FunctionType::get(builder.getInt64Ty(),targetArgs,true));

		debug("target is %p\n",target);
		
		this->target = llvm::cast<llvm::Function>(f);

		debug("target now resolved to %p\n",target);

	}
	return NULL;
}

//TODO use the result !
llvm::Value* CallExprAST::getval(ASTContext ctx)
{
	llvm::Value * ret = NULL;
	
	nameresolve(ctx);

	llvm::IRBuilder<>	builder(ctx.block);

	// build call argument

	std::vector<llvm::Value*> args;

	if(callargs && callargs->expression_list.size() )
	{
		BOOST_FOREACH( ExprASTPtr expr , callargs->expression_list)
		{
			debug("pusing args \n");
			args.push_back( expr->getval(ctx) );
		}
	}
	
	if(args.empty()){
		debug("===I will call to %s ==== with no argument\n",var->ID.c_str());
		ret = builder.CreateCall(target);
	}else{
		debug("===I will call to %s ==== with argument number %d\n",var->ID.c_str() , args.size() );
		ret = builder.CreateCall(target, args);
	}
	// use the result
	return ret;
}
#endif

llvm::BasicBlock* EmptyStmtAST::Codegen(ASTContext ctx)
{
    debug("empty statement called !\n");
    return ctx.block;
}

// llvm::BasicBlock* StatementAST::Codegen(ASTContext ctx)
// {
// 
// }
llvm::BasicBlock* PrintIntroAST::Codegen(ASTContext ctx)
{
	BOOST_ASSERT(TheFunction);
	debug("PrintIntroAST expr for \n");
	return ctx.block;
}

//* 调用函数
llvm::BasicBlock* CallStmtAST::Codegen(ASTContext ctx)
{
	debug("call function? generating the call here!\n");
	// 然后调用吧
	callable->getval(ctx);

	// 忽略返回数值
	return ctx.block;
}

//TODO 为 print 语句生成,
llvm::BasicBlock* PrintStmtAST::Codegen(ASTContext ctx)
{
	bool need_brt = false;
    debug("generating llvm-IR for calling PRINT\n");
	BOOST_ASSERT(ctx.llvmfunc);

	//llvm::CallInst::Create();
	llvm::IRBuilder<> builder(ctx.llvmfunc->getContext());
	builder.SetInsertPoint(ctx.block);

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
			ctx.module->getOrInsertFunction("brt_print",
										llvm::FunctionType::get(builder.getInt32Ty(), brt_printArgs,
		/*必须为true, 这样才能接受可变参数*/true));

	llvm::Constant *printf_func = ctx.module->getOrInsertFunction("printf",
										llvm::FunctionType::get(builder.getInt32Ty(), printfArgs,
		/*必须为true, 这样才能接受可变参数*/true));

	std::vector<llvm::Value*> args; // 先插入第3个开始的参数.
	std::string	printfmt;
#if 0
	//第三个参数开始是 ... 参数对.
	if(! callargs->expression_list.empty()){
		// TODO : 支持字符串的版本修改第三个参数开始为参数对.
		//std::for_E
		BOOST_FOREACH(ExprASTPtr argitem,callargs->expression_list)
		{	
			switch(argitem->type(ctx)->size()){ //按照大小来啊,果然
				case sizeof(long): // 整数产量的类型

					if( dynamic_cast<PointerTypeAST*>(argitem->type.get()) ){
						//指针类型
						printfmt += "%p\t"; //TODO: 字符串
					debug("add code for print list args type %%p\n");

					}else{
					debug("add code for print list args type %%ld\n");
						printfmt += "%ld\t";
					}
					args.push_back(	argitem->getval(ctx) );
					break;
				case sizeof(int):
					printfmt += "%d\t";
					args.push_back(	argitem->getval(ctx) );
					break;
				case 0:
					printfmt +="\n"; // 很重要,呵呵
				default:
					//TODO, 目前只需要支持 number , brt_print 也只是支持数字
					debug("print argument not supported\n");
			}
		}
	}
#endif
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

	return ctx.block;
}

//为变量分配空间
llvm::BasicBlock* VariableDimAST::Codegen(ASTContext ctx)
{
	BOOST_ASSERT(ctx.llvmfunc);

	//map type name to type
	ExprTypeAST * exptype = TypeNameResolve(ctx,this->type);
	
	debug("allocate stack for var %s , type %s\n", name.c_str(), type.c_str());

	alloca_var = exptype->Alloca(ctx,this->name,this->type);

	// register with symbolic table
	ctx.codeblock->symbols.insert(std::make_pair(this->name,this));
	
	return ctx.block;
}

// 获得分配的类型
llvm::Value* VariableDimAST::getptr()
{
	debug("get ptr of this %p\n", alloca_var);
	return alloca_var;
}

llvm::Value* FunctionDimAST::getptr()
{
	return this->target;
}

// 赋值语句, NOTE 直接调用赋值表达式
llvm::BasicBlock* AssigmentAST::Codegen(ASTContext ctx)
{
 	BOOST_ASSERT(ctx.llvmfunc);
 	debug("called for number assigment\n");

	assignexpr->getval(ctx);
 	return ctx.block;
}

llvm::BasicBlock* ReturnAST::Codegen(ASTContext ctx)
{

	llvm::IRBuilder<> builder(ctx.llvmfunc->getContext());
	builder.SetInsertPoint(ctx.block);

	llvm::Value * ret = this->expr->getval(ctx);
	
	builder.CreateRet(ret);
	debug("生成返回值\n");
	return ctx.block;
}

// IF ELSE 语句
llvm::BasicBlock* IFStmtAST::Codegen(ASTContext ctx)
{
	BOOST_ASSERT(ctx.llvmfunc);
	debug("if else statement\n");

	// true cond is always there
	llvm::BasicBlock* cond_true = llvm::BasicBlock::Create(ctx.llvmfunc->getContext(), "cond_true", ctx.llvmfunc);
	llvm::BasicBlock* cond_false ;

	if( this->_else){
		cond_false = llvm::BasicBlock::Create(ctx.llvmfunc->getContext(), "cond_false",ctx.llvmfunc);
	}
	llvm::BasicBlock* cond_continue = llvm::BasicBlock::Create(ctx.llvmfunc->getContext(), "continue", ctx.llvmfunc);
	
	if(! this->_else){
		cond_false = cond_continue;
	}

	llvm::IRBuilder<> builder(ctx.block);

	llvm::Value * expcond = this->_expr->getval(ctx);
	
	expcond = builder.CreateICmpNE(expcond, qbc::getconstlong(0), "tmp");
	builder.CreateCondBr(expcond, cond_true, cond_false);

	// generating true
	ctx.block = cond_true;

	this->_then->parent = ctx.codeblock;// NOTE important
	this->_then->Codegen(ctx);
	builder.SetInsertPoint(cond_true);
	builder.CreateBr(cond_continue);

	// generating false , if there is any
	if( this->_else){
		this->_else->parent = ctx.codeblock;// NOTE important
		ctx.block = cond_false;
		this->_else->Codegen(ctx);
		builder.SetInsertPoint(cond_false);
		builder.CreateBr(cond_continue);
	}
	builder.CreateBr(cond_continue);
	return cond_continue;
}

llvm::BasicBlock* LoopAST::bodygen(ASTContext ctx)
{
	loopbody->parent = ctx.codeblock;
	ctx.codeblock = loopbody.get();	
    return loopbody->Codegen(ctx);
}

llvm::BasicBlock* WhileLoopAST::Codegen(ASTContext ctx)
{
	BOOST_ASSERT(ctx.llvmfunc);
	debug("generation code for while statement\n");

	llvm::BasicBlock* cond_while =
		llvm::BasicBlock::Create(ctx.llvmfunc->getContext(), "while", ctx.llvmfunc);

	llvm::BasicBlock* while_body =
		llvm::BasicBlock::Create(ctx.llvmfunc->getContext(), "whileloop", ctx.llvmfunc);

	llvm::BasicBlock* cond_continue =
		llvm::BasicBlock::Create(ctx.llvmfunc->getContext(), "whileend", ctx.llvmfunc);

	llvm::IRBuilder<> builder(ctx.llvmfunc->getContext());
	builder.SetInsertPoint(ctx.block);
	builder.CreateBr(cond_while);

	builder.SetInsertPoint(cond_while);
	llvm::Value * expcond = this->condition->getval(ctx);
	expcond = builder.CreateICmpEQ(expcond, qbc::getconstlong(0), "tmp");
	builder.CreateCondBr(expcond, cond_continue, while_body);

	ctx.block = while_body;
	this->bodygen(ctx);
	builder.SetInsertPoint(while_body);
	builder.CreateBr(cond_while);
	
	return cond_continue;	
}

llvm::BasicBlock* CodeBlockAST::Codegen(ASTContext ctx)
{
	if(!ctx.llvmfunc ){
		debug("statements called with ctx.llvmfunc=null\n");
	}else{
		debug("statements called with good ctx.llvmfunc\n");
	}

	ctx.codeblock = this;

	BOOST_FOREACH( StatementASTPtr stmt , this->statements)
	{
		if(stmt)
			ctx.block = stmt->Codegen(ctx);
		else
			debug("strange, stmt is null\n");
	}
	return ctx.block;
}

// 生成函数 参数和反回值支持
llvm::BasicBlock* FunctionDimAST::Codegen(ASTContext ctx)
{
	BOOST_ASSERT(!ctx.llvmfunc);
	BOOST_ASSERT(!ctx.block);

	debug("generating function %s and its body now\n", this->name.c_str());

	//首先生成全局可用的外部辅助函数
	llvm::IRBuilder<> builder(llvm::getGlobalContext());

	// 参数生成 args
	//为 ARG 生成代码!
	std::vector<llvm::Type*>	args;

	//TODO need re-work

	if(callargs){
		BOOST_FOREACH( VariableDimASTPtr stmt , callargs->dims)
		{
			VariableDimAST * dim = stmt.get();
			ExprTypeAST * exprtype = TypeNameResolve(ctx,dim->type);

			args.push_back(exprtype->llvm_type(ctx));
		}
	}

	ExprTypeAST * exprtype = TypeNameResolve(ctx,this->type);
	//函数返回类型
	llvm::FunctionType *funcType =
		llvm::FunctionType::get(exprtype ? exprtype->llvm_type(ctx) : builder.getVoidTy(),args,true);

	target = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, this->name , ctx.module);
	llvm::BasicBlock *entry = llvm::BasicBlock::Create(builder.getContext(), "entrypoint", target);
	builder.SetInsertPoint(entry);
	//开始生成代码

	// 为参数设定 name
	llvm::Function::arg_iterator llvmarg_it = target->arg_begin();

	if( callargs){
		std::vector< VariableDimASTPtr >::iterator argit = callargs->dims.begin();

		for(; argit != callargs->dims.end() ; argit++ , llvmarg_it++	){
			VariableDimAST * argdim = argit->get();
			llvmarg_it->setName(argdim->name);
		}
	}

	ASTContext newctx;
	if(callargs)
		newctx.codeblock = this->parent;
	else
		newctx.codeblock = this->callargs.get();

	newctx.llvmfunc = target;
	newctx.block = entry;
	//now code up the function body
	builder.SetInsertPoint(body->Codegen(newctx));
	builder.CreateRetVoid();

	return ctx.block;
}