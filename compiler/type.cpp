
/*
    defination of QBASIC Abstruct Syntax Tree - The Type System
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
#include <boost/make_shared.hpp>

#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/IRBuilder.h>

#include "llvmwrapper.hpp"
#include "ast.hpp"
#include "type.hpp"

#define debug std::printf
//#define debug(...) do{}while(0)

//static map of the internal type system
static	ExprTypeASTPtr numbertype(new NumberExprTypeAST);
static	ExprTypeASTPtr stringtype(new StringExprTypeAST);
static	ExprTypeASTPtr voidtype(new VoidExprTypeAST);

ExprTypeASTPtr VoidExprTypeAST::GetVoidExprTypeAST()
{
	return voidtype;
}

ExprTypeASTPtr NumberExprTypeAST::GetNumberExprTypeAST()
{
	return numbertype;
}

ExprTypeASTPtr StringExprTypeAST::GetStringExprTypeAST()
{
	return stringtype;
}

ExprTypeASTPtr ArrayExprTypeAST::create(ExprTypeASTPtr elementtype)
{
	return boost::make_shared<ArrayExprTypeAST>(elementtype);
}

ExprTypeASTPtr StructExprTypeAST::create(const std::string __typename)
{
	return boost::make_shared<StructExprTypeAST>(__typename);
}

ExprTypeASTPtr EmptyExprAST::type(ASTContext)
{
    return ExprTypeASTPtr();
}

ExprTypeASTPtr ConstNumberExprAST::type(ASTContext)
{
    return numbertype;
}

ExprTypeASTPtr ConstStringExprAST::type(ASTContext)
{
	return stringtype;
}

ExprTypeASTPtr VariableExprAST::type(ASTContext ctx)
{
	return nameresolve(ctx)->type;
}

ExprTypeASTPtr AssignmentExprAST::type(ASTContext ctx)
{
	//TODO, result the type
	return lval->type(ctx);
}

ExprTypeASTPtr CalcExprAST::type(ASTContext ctx)
{
	if(op==OPERATOR_EQUL)
		return numbertype;
	// left hand type
	return lval->type(ctx);
}

ExprTypeASTPtr CallExprAST::type(ASTContext ctx)
{
	ExprTypeASTPtr typeast = calltarget->nameresolve(ctx)->type;

	if(typeast){
		debug("got type of function or array\n");
	}

	ArrayExprTypeAST * arrayval =dynamic_cast<ArrayExprTypeAST*>(typeast.get());
	CallableExprTypeAST* callval = dynamic_cast<CallableExprTypeAST*>(typeast.get());

	if(arrayval){
		debug("got type of function or array ? ==== array!\n");
		return arrayval->elementtype;
	}if(callval){
		debug("got type of function or array ? ==== func!");
		return callval->returntype;
	}else
	{
		debug("operator () on non-function nor array");
		exit(12);
	}
}

llvm::Type* VoidExprTypeAST::llvm_type(ASTContext ctx)
{
	return llvm::Type::getVoidTy(ctx.module->getContext());
}

llvm::Type* NumberExprTypeAST::llvm_type(ASTContext ctx)
{
	switch(sizeof(long)){
		case 8:
			return llvm::Type::getInt64Ty(ctx.module->getContext());
		case 4:
			return llvm::Type::getInt32Ty(qbc::getGlobalContext);
	}
	return llvm::Type::getInt32Ty(qbc::getGlobalContext);
}

llvm::Type* StringExprTypeAST::llvm_type(ASTContext ctx)
{
	return llvm::Type::getInt8PtrTy(qbc::getGlobalContext);
}

// the llvm_type of array is in fact QBArray
llvm::Type* ArrayExprTypeAST::llvm_type(ASTContext ctx)
{
	static llvm::Type * arraytype =NULL;
	if(!arraytype){
		std::vector<llvm::Type*>	members;

		members.push_back(llvm::Type::getInt8PtrTy(ctx.module->getContext()));

 		members.push_back(qbc::getplatformlongtype());
		members.push_back(qbc::getplatformlongtype());
		members.push_back(qbc::getplatformlongtype());

		arraytype = llvm::StructType::create(members,"QBArray");
	}
	return arraytype;
}

llvm::Type* CallableExprTypeAST::llvm_type(ASTContext ctx)
{
	return this->returntype->llvm_type(ctx);
	debug("get function type of  llvm\n");
    exit(0);
}

// 结构体的 llvm_type 实际上是 。。。 各个子成员的集合.
llvm::Type* StructExprTypeAST::llvm_type(ASTContext ctx)
{
	//TODO 获得子成员的类型，并依次堆叠

}

llvm::Value* NumberExprTypeAST::Alloca(ASTContext ctx, const std::string _name)
{
	debug("allocation for value %s type long\n",_name.c_str());

	llvm::IRBuilder<> builder(&ctx.llvmfunc->getEntryBlock(),
							  ctx.llvmfunc->getEntryBlock().begin());

	builder.SetInsertPoint(ctx.block);

	return builder.CreateAlloca(this->llvm_type(ctx),0,_name);
}

llvm::Value* ExprTypeAST::deref(ASTContext ctx, llvm::Value* v)
{
	debug("de reference unkonw type\n");
	exit(200);
}

llvm::Value* StringExprTypeAST::Alloca(ASTContext ctx, const std::string _name)
{
	debug("allocation for value %s type string\n",_name.c_str());

	llvm::IRBuilder<> builder(&ctx.llvmfunc->getEntryBlock(),
							  ctx.llvmfunc->getEntryBlock().begin());

	builder.SetInsertPoint(ctx.block);

	llvm::Value * newval = builder.CreateAlloca(this->llvm_type(ctx),0,_name);

	builder.CreateStore( qbc::getnull(), newval);
	return newval;
}

llvm::Value* ArrayExprTypeAST::Alloca(ASTContext ctx, const std::string _name)
{
	debug("allocation for array %s type %s\n",_name.c_str() , this->elementtype->name(ctx).c_str());

	llvm::IRBuilder<> builder(&ctx.llvmfunc->getEntryBlock(),
							  ctx.llvmfunc->getEntryBlock().begin());

	llvm::Value * newval = builder.CreateAlloca(this->llvm_type(ctx),0,_name);

	//call btr_qbarray_new()
	auto btr_qbarray_new = qbc::getbuiltinprotype(ctx,"btr_qbarray_new");

	builder.CreateCall(btr_qbarray_new, {newval, qbc::getconstlong(elementtype->size())});
	return newval;
}

llvm::Value* CallableExprTypeAST::Alloca(ASTContext ctx, const std::string _name)
{
    ::printf("alloca function?\n");
    __builtin_trap();
    exit(0);

}

llvm::Value* NumberExprTypeAST::deref(ASTContext ctx, llvm::Value* v)
{
	llvm::IRBuilder<> builder(ctx.block);

	debug("de reference long type\n");

	llvm::Value * ptr = builder.CreateBitCast(v,qbc::getplatformlongtype()->getPointerTo());

	return builder.CreateLoad(ptr->getType(), ptr);
}

void StringExprTypeAST::destory(ASTContext ctx, llvm::Value* Ptr)
{
	debug("generate dealloca for string\n");

	llvm::IRBuilder<>	builder(ctx.block);

	auto func_free = qbc::getbuiltinprotype(ctx,"free");

	builder.CreateCall(func_free,builder.CreateLoad(Ptr->getType(), Ptr));
}

void ArrayExprTypeAST::destory(ASTContext ctx, llvm::Value* Ptr)
{
	debug("generate dealloca for QBArray\n");

	llvm::IRBuilder<>	builder(ctx.block);

	auto func_btr_qbarray_free = qbc::getbuiltinprotype(ctx,"btr_qbarray_free");

	builder.CreateCall(func_btr_qbarray_free,Ptr);
}

llvm::FunctionCallee CallableExprTypeAST::defaultprototype(ASTContext ctx, std::string functionname)
{
    //build default function type
    llvm::IRBuilder<>	builder(ctx.block);
    std::vector<llvm::Type*> no_args;

    return ctx.module->getOrInsertFunction(
		functionname,llvm::FunctionType::get(numbertype->llvm_type(ctx), no_args,true));
}

llvm::Value* ConstNumberExprAST::getval(ASTContext ctx)
{
	return qbc::getconstlong(	this->v);
}

llvm::Value* ConstStringExprAST::getval(ASTContext ctx)
{
	if(val)
		return val;
	llvm::IRBuilder<>	builder(ctx.block);

	// cache the result
	return val = builder.CreateGlobalStringPtr( this->str );
}

DimAST* VariableExprAST::nameresolve(ASTContext ctx)
{
	// FIXME add struct support
	std::string varname =  this->ID->ID;

// 	debug("searching for var %s\n",varname.c_str());

	if(! ctx.codeblock ){
		debug("var %s not defined\n",varname.c_str());
		exit(1);
		return NULL;
	}

	std::map< std::string, DimAST* >::iterator dimast_iter = ctx.codeblock->symbols.find(varname);

	if(dimast_iter != ctx.codeblock->symbols.end()){

		debug("searching for var %s have result %p\n",varname.c_str(),dimast_iter->second);

		return dimast_iter->second;
	}
	ctx.codeblock = ctx.codeblock->parent;
	return nameresolve(ctx);
}

DimAST* NamedExprAST::nameresolve(ASTContext ctx)
{
	debug("NamedExprAST::nameresolve\n");
	exit(1);
}

llvm::Value* TempNumberExprAST::getval(ASTContext)
{
	if(this->ptr)
	{
		return this->type(ctx)->deref(ctx,this->ptr);
	}
	return this->val;
}


llvm::Value* VariableExprAST::getval(ASTContext ctx)
{
 	llvm::IRBuilder<> builder(ctx.block);

	std::string desc = std::string("load local var ")+this->ID->ID;

	debug("%s\n",desc.c_str());

	return nameresolve(ctx)->getval(ctx);
}

llvm::Value* VariableExprAST::getptr(ASTContext ctx)
{
	return nameresolve(ctx)->getptr(ctx);
}

llvm::Value* CallExprAST::getptr(ASTContext ctx)
{
	ExprASTPtr tmp = calltarget->type(ctx)->getop()->operator_call(ctx,calltarget,callargs);
	return tmp->getptr(ctx);
}

// so simple , right ?
llvm::Value* AssignmentExprAST::getval(ASTContext ctx)
{
	return this->type(ctx)->getop()->operator_assign(ctx,this->lval,this->rval)->getval(ctx);
}

llvm::Value* CallExprAST::getval(ASTContext ctx)
{
	ExprASTPtr tmp = calltarget->type(ctx)->getop()->operator_call(ctx,calltarget,callargs);
	return tmp->getval(ctx);
}

llvm::Value* CalcExprAST::getval(ASTContext ctx)
{
	switch(this->op){
		case OPERATOR_ADD:
			if(!result)
				result = lval->type(ctx)->getop()->operator_add(ctx,lval,rval);
			return result->getval(ctx);
		case OPERATOR_SUB:
			if(!result)
				result = lval->type(ctx)->getop()->operator_sub(ctx,lval,rval);
			return result->getval(ctx);
		case OPERATOR_MUL:
			if(!result)
				result = lval->type(ctx)->getop()->operator_mul(ctx,lval,rval);
			return result->getval(ctx);
		case OPERATOR_DIV:
			if(!result)
				result = lval->type(ctx)->getop()->operator_div(ctx,lval,rval);
			return result->getval(ctx);
		case OPERATOR_GREATEREQUL:
		case OPERATOR_GREATER:
		case OPERATOR_LESS:
		case OPERATOR_LESSEQU:
		case OPERATOR_EQUL:
			if(!result){
				result = lval->type(ctx)->getop()->operator_comp(ctx,op,lval,rval);
			}
			return result->getval(ctx);
		default:
			debug("operator not supported yet\n");
			exit(1);
	}
	return result->getval(ctx);
}

///////////////////////////////////////////////////////////////////
//////////////////// constructors ////////////////////////////////////
//////////////////////////////////////////////////////////////////
ExprTypeAST::ExprTypeAST(size_t size, const std::string __typename)
	:_size(size),_typename(__typename)
{
}

NumberExprTypeAST::NumberExprTypeAST() : ExprTypeAST(sizeof(long),"long")
{

}

StringExprTypeAST::StringExprTypeAST() :ExprTypeAST(sizeof(void*),"string")
{
}

ConstStringExprAST::ConstStringExprAST(const std::string _str)
	:str(_str),val(0)
{
}


ArrayExprTypeAST::ArrayExprTypeAST(ExprTypeASTPtr _elementtype)
	:elementtype(_elementtype)
{
}

CallableExprTypeAST::CallableExprTypeAST(ExprTypeASTPtr _returntype)
	:returntype(_returntype)
{
}

PointerTypeAST::PointerTypeAST(ExprTypeASTPtr _pointeetype)
	:pointeetype(_pointeetype)
{
}

StructExprTypeAST::StructExprTypeAST(const std::string __typename)
	:ExprTypeAST(0,__typename)
{

}



NamedExprAST::NamedExprAST(ReferenceAST* _ID)
	:ID(_ID)
{
}

VariableExprAST::VariableExprAST(ReferenceAST* ID)
	:NamedExprAST(ID)
{
}

AssignmentExprAST::AssignmentExprAST(NamedExprAST* l, ExprAST*r)
	:lval(l),rval(r)
{
}

CallExprAST::CallExprAST(NamedExprAST* _target, ExprListAST* exp_list)
	:callargs(exp_list),calltarget(_target)
{
}

CalcExprAST::CalcExprAST(ExprAST* l, MathOperator _op, ExprAST* r)
	:lval(l),rval(r),op(_op)
{

}

TempExprAST::TempExprAST(ASTContext _ctx, llvm::Value* _val , llvm::Value *_ptr, ExprTypeASTPtr type) :ctx(_ctx),val(_val),_type(type),ptr(_ptr) {}

TempNumberExprAST::TempNumberExprAST(ASTContext ctx,llvm::Value* numberresult, llvm::Value *ptr)
	:TempExprAST(ctx,numberresult,ptr, numbertype)
{

}

TempStringExprAST::TempStringExprAST(ASTContext ctx,llvm::Value* result , llvm::Value *ptr)
	:TempExprAST(ctx,result,ptr,  stringtype)
{

}

TempStringExprAST::~TempStringExprAST()
{
	llvm::IRBuilder<>	builder(ctx.block);
	auto func_free = qbc::getbuiltinprotype(ctx,"free");
	builder.CreateCall(func_free,this->val);
}
