#include <iostream>
#include <cstdint>

using namespace std;

uint64_t fibonacci( uint64_t n ) {

    uint64_t f = 1;
        
    if ( n <= 1 ) {
        return 1;
    } else {
        f = fibonacci( n - 1 ) + fibonacci( n - 2 );
    }

    return f;
}

int main() {

    uint64_t fib = 0;
    uint64_t n = 1;
    uint64_t sum = 0;

    fib = fibonacci( n );
    while ( fib < 4000000 ) {
        n += 1;
  
        fib = fibonacci( n );
        if ( fib % 2 == 0 ) {
            sum += fib;
        }
        cout << n << ", " << fib << endl;
    }

    cout << "The sum of even Fibonacci numbers < 4,000,000 is " << sum << endl;
}
