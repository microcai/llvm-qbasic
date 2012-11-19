/*
	llvm-QBASIC Compiler test

	string test
*/

/*
	print string test!
	and string should get de-allocated when function returns
*/

sub main()

dim a as string
dim b as string

dim c as long

a = "hello world"
c = 100
b = "yes my lorld"

print a , b, "hello world" , a + b , "ye" + "s"

end sub
