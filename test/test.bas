/*
	llvm-QBASIC Compiler test

	in development test cases

	for historcal test cases, see test[0-9]*.bas
*/

/*
	fibonacci test
*/

function  fibonacci( n as long ) as long

dim prev
dim curr
dim tmp
dim idx

curr=1
prev=0
tmp=0
idx=0

if  n < 2 then return n

for idx = 2 to n
			tmp = prev
			prev = curr
			curr = tmp + prev	
end for

return curr

end function

sub main()

print  fibonacci(36)

end sub
