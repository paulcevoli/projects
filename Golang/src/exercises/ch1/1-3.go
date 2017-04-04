// Exercise 1-3
package main

import (
	"fmt"
	"os"
	"strings"
	"time"
)

func main() {

	// buils string iteratively
	start := time.Now()
	var s, sep string
	for i := 1; i < len(os.Args); i++ {
		s += sep + os.Args[i]
		sep = " "
	}
	elapsed := time.Since(start)
	fmt.Printf("%s elapsed\n", elapsed)

	// use string Join method
	start = time.Now()
	fmt.Println(strings.Join(os.Args[1:], " "))
	elapsed = time.Since(start)
	fmt.Printf("%s elapsed\n", elapsed)
}
