/*
	llvm-QBASIC Compiler test

	function return value test
*/

function  sum ( a as long , b as long) as long

dim s as long

s = a + b

print s

return s

end function

sub main()

dim s as long
dim a as long
dim b as long

a = 100
b = 50

s = sum(a,b)

print s

end sub
