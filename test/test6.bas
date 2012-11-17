/*
	llvm-QBASIC Compiler test

	the function call and used as result
*/

sub testfunc1()

print 100

end sub

sub testfunc2( i as long )

print i

i=54321

print i


end sub


sub main()

print 1000000

dim a as long

testfunc1()

testfunc2( 100 )

a = abs( 100 )

print a

end sub
