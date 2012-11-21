package main
import "fmt"
func fibonacci(n int) int{
	if (n < 2) {
		return n
}
	return fibonacci(n - 2) + fibonacci(n - 1)
}

func main() {
fmt.Println(fibonacci(40))
}

