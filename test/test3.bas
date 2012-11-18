//  循环测试

sub main ( )

DIM A as long

A = 1000

while A
	print A ,
	if A > 100 then A = A - 10
	A = A - 1
end while

print 

end sub
