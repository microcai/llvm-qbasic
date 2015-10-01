
function fibonacci( n as long ) as long

if  n < 2 then return n

return  fibonacci(n - 2) + fibonacci(n - 1)

end function

sub main()

print "fibonacci(41) = " , fibonacci(41)

End Sub
