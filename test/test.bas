/*
	llvm-QBASIC Compiler test

	in development test cases

	for historcal test cases, see test[0-9]*.bas
*/

/*
	for loop test
*/

function fab( i as long) as long

return i * i ;

end function


sub main()
array dim a as long REM the type of the array

dim i

for i = 1 to 100
	a(i) = 	fab(a)
end for

print a  REM the compile has internal support for printing array.

end sub
