/*
	llvm-QBASIC Compiler test

	function defind with arguments and call it
*/

sub testfunc1()

print 100

end sub

sub testfunc2( i as long )

print i,

i=54321

print i

end sub


sub main()

dim a as long

testfunc1()

testfunc2( 100 )

end sub


//  ========= here goes the llvm-IR code
