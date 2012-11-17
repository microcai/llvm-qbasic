/*
	llvm-QBASIC Compiler test

	the function call and while and if .  3 cases test	
*/

sub testfunc( i as long )

print i

i=54321

print i


end sub


sub main()

print 1000000

testfunc( 100 )

end sub
