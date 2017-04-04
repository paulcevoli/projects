// Exercise 1-2
package main

import (
	"fmt"
	"os"
)

func main() {
    sep := " " 
    for index, arg := range os.Args[1:] {
	fmt.Print(index)
        fmt.Print(sep)
        fmt.Println(arg)
        sep = " "
    }
}
