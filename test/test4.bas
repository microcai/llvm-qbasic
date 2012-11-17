/*
	llvm-QBASIC Compiler test

	the function call and while and if .  3 cases test
*/

sub main2()

dim a as long
dim b as long
dim c as long

a=1
b=800

c = 6000

print a , b

print b

if 1 then
print a
end if

while b > 400
	a = a + b
	print  b  , 1
	b = b - 1
end while

end sub

sub main()

print 1000000

main2( )

end sub
