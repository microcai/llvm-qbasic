#pragma once

enum ExprType{
	EXPR_TYPE_VOID=0,	// nul type , used as return type of SUB XXX
			// only used by FunctionAST to define SUB in BASIC
	EXPR_TYPE_BOOL,// as boolear , TRUE,FALSE
	EXPR_TYPE_BYTE,	// for const char * used with CARRAY
	EXPR_TYPE_SHORT,	// as short
	EXPR_TYPE_INTGER,	// as Intger
	EXPR_TYPE_LONG,	// as long
	EXPR_TYPE_DOUBLE,	// as Double
 	EXPR_TYPE_POINTER,// as ptr
	STRUCT,	// qbasic supports structure,
	STRING,	// STRING is an internal struct type.
			// STRING is implemented as structure by calling some member function
			// automanticall by compiler
	CARRAY,	// C 数组, BYTE 类型
	ARRAY	// 数组，only used by VariableExprAST & DimAST
};
