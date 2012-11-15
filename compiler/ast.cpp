/*
    <one line to give the library's name and an idea of what it does.>
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


#include "llvmwrapper.hpp"
#include "ast.hpp"

#define debug printf

llvm::Module * AST::module ;


AST::AST()
{
}

AST::~AST()
{
}

// nop 语句, 自动调用下一条.
llvm::Value* StatementAST::Codegen(llvm::BasicBlock* insertto)
{
	debug("%s called \n",__func__);
	if(this->next)
		return this->next->Codegen(insertto);
	else return insertto;
}

// 为立即数生成 IR
llvm::Value* ConstExprAST::Codegen(llvm::BasicBlock * insertto)
{	
	debug("%s\n",__func__);
    return llvm::ConstantInt::get(llvm::getGlobalContext(),llvm::APInt(64,this->constval,10));
}

void StatementAST::append(StatementAST * item)
{
	if(!next)
		next.reset(item);
	else{
		StatementAST * p = (this->next.get());
		while(p->next.get())
			p = p->next.get();
		p->next.reset(item);
	}
}

PrintStmtAST::PrintStmtAST(PrintIntroASTPtr intro,PrintListASTPtr args)
	:callargs(args),print_intro(intro)
{
	
}

//TODO 为 print 语句生成,
llvm::Value* PrintStmtAST::Codegen(llvm::BasicBlock * insertto)
{
    debug("generating llvm-IR for calling PRINT\n");
	
	//llvm::CallInst::Create();
	llvm::IRBuilder<> builder(llvm::getGlobalContext());
	builder.SetInsertPoint(insertto);

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
		default:
			std::cerr << "unknow int type" << std::endl ;
	}

	llvm::Constant *brt_print =
			module->getOrInsertFunction("brt_print",
										llvm::FunctionType::get(builder.getInt32Ty(), brt_printArgs,
		/*必须为true, 这样才能接受可变参数*/true));

	// TODO: 调用 this->print_intro->Codegen() 生成第一个参数
	// 现在 brt 忽略第一个参数
	std::vector<llvm::Value*> args;
	args.push_back( qbc::getconstint(0) );

	//第二个参数是参数(个数/2)
	args.push_back( qbc::getconstint( callargs->size() ) );

	//第三个参数开始是 ... 参数对.
#if 0
	if(callargs->size() > 0){
		// TODO : 支持字符串的版本修改第三个参数开始为参数对.
		//std::for_E	BOOST_FOREACH(ExprASTPtr argitem,callargs->printlist);
		for( std::vector<ExprASTPtr>::iterator it = callargs->printlist.begin();
			it != callargs->printlist.end() ; it++)
		{
			ExprASTPtr argitem = *it;
			
			switch(argitem->type){
				case EXPR_TYPE_BOOL:
				case EXPR_TYPE_BYTE:	// for const char * used with CARRAY
				case EXPR_TYPE_SHORT:	// as short
				case EXPR_TYPE_INTGER:	// as Intger
					// this are types that can be manipulated directly
					args.push_back(	qbc::getconstint(argitem->type) );
					debug("add code for print list args type %d\n",argitem->type);
					args.push_back(	argitem->Codegen(insertto) );
					break;
				case EXPR_TYPE_LONG:	// as long
					// this are types that can be manipulated directly
					args.push_back(	qbc::getconstint(argitem->type) );
					debug("add code for print list args type %d\n",argitem->type);
					args.push_back(	argitem->Codegen(insertto) );
					break;
				case EXPR_TYPE_VOID:
					args.push_back(	qbc::getconstint(argitem->type) );
					debug("add code for print list args type %d\n",argitem->type);
					break;
				case EXPR_TYPE_DOUBLE:	// as Double
				case EXPR_TYPE_POINTER:// as ptr
					//TODO: 64位的数字
				default:
					//TODO, 目前只需要支持 number , brt_print 也只是支持数字
					printf("print argument not supported\n");
			}
			//argitem->Codegen()
		}
	}
#endif
	//调用 print
	builder.CreateCall(brt_print,args ,"PRINT");

	return StatementAST::Codegen(insertto);
}

PrintIntroAST::PrintIntroAST() {}

ConstNumberExprAST::ConstNumberExprAST(const int64_t v)
	:val(v)
{
}

llvm::Value* ConstNumberExprAST::Codegen(llvm::BasicBlock * insertto)
{
	debug("const for %d\n",this->val);
    return qbc::getconstlong(this->val);
}

llvm::Value* NumberExprAST::Codegen(llvm::BasicBlock* insertto)
{
	//return insertto;
	debug("number expr for \n");

}

llvm::Value* PrintIntroAST::Codegen(llvm::BasicBlock* insertto)
{
	debug("PrintIntroAST expr for \n");
}

