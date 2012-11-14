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


enum CompOperator{
	Equl = 1, // == , =
	NotEqul , // <> , >< , != as in basic
	Less , // <
	Greater , // >
};

enum MathOperator{
	Mul = 1 , // *
	Div , // /
	Add , // +
	Minus , // -
	Mod , // % , MOD
	Power , // ^
};


enum Linkage{
	STATIC = 1,	//静态函数，无导出
	EXTERN,		//导出函数
	IMPORTC,		//导入C函数，这样就可以使用 C 函数调用了，算是我提供的一个扩展吧
};

enum ReferenceType{
	BYVALUE,	//传值
	BYREF,	//引用，实质就是指针了. 函数的默认参数是传引用
};