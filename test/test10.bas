/*
	llvm-QBASIC Compiler test

	for loop test
*/

function fab( i as long) as long

return i * i ;

end function


sub main()
dim a

for a = 1 to 100
print fab(a),
end for

end sub
