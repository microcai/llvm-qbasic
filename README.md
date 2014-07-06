#llvm-qbc - llvm based qbasic compiler

llvm-qbc is a QBASIC compiler as well as a statically linked runtime library.

# Why BASIC ?

To answer that question, you need to ask, why not BASIC? There are multiple reasons.
For one, currenlty there is no cross-platform BASIC compiler that is feature complete.
What's worse is that you cannot distribute your program without first
distributing its interpreter. This problem is componded by the fact most commercial BASIC interpreters had limited
allowance for re-distribution. What other options are there? Compile your program? None exist that allow calling C functions. What can we do with BASIC without the help of avalable C libraries?

To make things even worse, there is no BASIC standard that all compilers agree with.

# Goals
	[1] Complete QBASIC support
	[3] Pointer support
	[2] Call C functions as easily as possible
	[4] Highly optimized
	[5] Built-in GUI facility

# Status updates
	[*] Dymanic array support, use arraydim to use that.
	[*] For loop
	[*] String concatenation
	[*] String literals and string variables can assign to a string variable
	[*] Free local strings on function return
	[*] Able to print numbers and string literals to screen
	[*] Comparison operators
	[*] Subroutine definition and invokation
	[*] Function definition and invokation
	[*] If statements
	[*] While statements
	[*] Basic mathmatical operations

# Benchmarks
	See [ test/compare.txt  https://github.com/microcai/llvm-qbasic/blob/master/test/compare.txt ]
	
# Implementation Details

#### Numerical types

`int` and `long` are directly supported by LLVM, so they are handled automatically.

#### String types:

We provide two types of strings, a C (literal) string and QBASIC string.

C strings are a NULL-Terminated char array. You can get a C string from a QBASIC string with `cstr(QBASIC string)`

A QBASIC string has its memory automatically managed by the compiler. The compiler does this by calling the helper functions which are defined in librt (see [ bre/README.md ]).

#### Array type:

An `array` is a vector space managed by the compiler automatically. You can make use of C style arrays (read only) with `CARRAY(array)` but if you want to write to that array, please use a `buffer` type for the job.

#### Buffer type

A `buffer` is a vector byte stream managed by the program. It's in fact just a `byte*` pointer along with its allocated space, with the space being fixed after you define it. To access an individual byte, use the `[]` operator. `buffer` only exists for calling external C functions.

Space is automantically freed when a `buffer` leaves the scope of the function. There is no need for manual memory management. The compiller will automantically call free(3) to clean up.

#### User defined structures

User defined structures are allowed. 
