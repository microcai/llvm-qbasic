/*
	llvm-QBASIC Compiler test

	in development test cases

	for historcal test cases, see test[0-9]*.bas
*/

/*
	fibonacci test
*/

function  fibonacci( n as long ) as long

if  n < 2 then return n

return  fibonacci(n - 2) + fibonacci(n - 1)

end function

sub main()

print  fibonacci(40)

end sub
