/*
	llvm-QBASIC Compiler test

	in development test cases

	for historcal test cases, see test[0-9]*.bas
*/

REM  sun define here


function  sum ( a as long , b as long) as long

dim s as long

s = a + b

return s

end function

sub main()

dim s as long
dim a as long
dim b as long

print 123

a =  10
b = 44

print a

s = sum(a,b)

print s


end sub
