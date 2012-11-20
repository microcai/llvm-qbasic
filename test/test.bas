/*
	llvm-QBASIC Compiler test

	in development test cases

	for historcal test cases, see test[0-9]*.bas
*/

/*
	for loop test
*/

function ffffab( i as long) as long

return i * i 

end function

sub main()

arraydim a as long

dim i as int

for i = 1 to 100

a(i) = 	ffffab(a)

end for

print a  REM the compile has internal support for printing array.

end sub
