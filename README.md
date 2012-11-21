#llvm-qbc - llvm based qbasic compiler

llvm-qbc is a QBASIC compiler as well as an runtime library ( statically linked )

# Why BASIC ?

To answer this questions, you must ask, why not BASIC?
Because there is no BASIC compiler that is cross-platform, and feature complete.
And basic interpreter is even worse, you can't distribute your program unless you
distribute its interpreter first, but most commercial basic interpreter had limited
premit for re-distribution. Then ? Compile ? You can't even find a compiler that supports
calling C functions. What can we do with basic without the help of all avalable C libraries?

To make things even worse, BASIC have not standart that every compiler agree with.

# goal
	[1]	complete QBASIC support
	[3] pointer support
	[2]	call C function as freely as possible
	[4] highly optimized
	[5] a builtin GUI facility

# Status update
	[*] dymanic array support, use arraydim to use that.
	[*] for loop
	[*] string is capable of doing "+" operation
	[*]	string literal and string variable can assign to string variable
	[*] deallocating function local string when the function returns
	[*]	being able to print numbers and string literal to screen
	[*] compare operation
	[*] sub define and invoke
	[*] function define and invoke
	[*] if statement
	[*] while statement
	[*] basic mathmatical operation
	[*] if statement

# Implementation Detail

	int/long is directly supported by LLVM, so , no discssiion needed.

####	for the type "string":

 there are two types of string :
		 C string (literal) and QBASIC string

C string is an NULL-Terminated char array. you can get a C string of an QBASIC string with
	cstr(QBASIC string)

	QBASIC string is an string which has memory automantically managed by compiler. the compiler
	does this by calling helper functions defined in librt see  [ bre/README.md ]

#### for the type "array":

	array is an vector space managed by the compiler automantically. you can have C style array (read only) with CARRAY(array) 

	but if you want to "write" to that array, please use another type for this kind of job: buffer.

#### for the type buffer

	buffer is an vector byte stream managed by user program. it's infact just  byte* pointer and it's allocated space.
	the space is fixed when you define it. to access individual byte, use [] operator. the use of buffer is only for calling C functions.
	the space will be automantically freed when buffer leaves the function body. there is no need to manage the memory space. the compiller automanticall call free(3) to free the space.

#### user defined structure

	user is allow to define structures. 
