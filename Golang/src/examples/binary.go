package main
import "fmt"

func main() {
     //Enter your code here. Read input from STDIN. Print output to STDOUT
     var n uint64
     var m uint64
     var c int
     var max = 0
                     
     fmt.Scanf("%d", &n)
                          
     m = 1
     c = 0
     for n > m {
        if ( ( n & m ) != 0 ) {
            c += 1
            if ( c > max ) {
                max = c
            }
         } else {
             c = 0
         }
        
         m = m << 1
                                                                                                                                                             
     }

     fmt.Printf("%d\n", max)
}
