#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

using namespace std;

static vector<bool> sieve;

void generate_sieve_of_eratosthenes( int64_t n ) {
    
    //int64_t primefactormax = n / 2;
    int64_t primefactormax = floor( sqrt( n ) );

    for ( int64_t i = 0; i < primefactormax; i++ ) {
        sieve.push_back( true );
    }

    for ( int p = 2; ( p * p ) <= primefactormax; p++ ) {
        if ( sieve[ p ] == true ) {
            for ( int i = p * 2; i <= primefactormax; i += p ) {
                sieve[ i ] = false;
            }
        }
    }

}

bool isprime( int64_t n ) {
    bool prime = true;

    if ( n <= 1 ) {
        prime = false;
    } else if ( n == 2 ) {
        prime = true;
    } else {
        if ( ( n & 1 ) == 1 ) {
            int64_t nmax =  n / 2;
 
            for ( int64_t i = 3; i < nmax ;  i += 2 ) {
                register int64_t rem;

                rem = n % i;
                if ( rem == 0 ) {
                    prime = false;
                    break;
                }
            }
        } else {
            prime = false;
        }
    }
    
    return prime;
}

const int64_t nmax = 600851475143;

int main() {
    int64_t factor = 1;
    int64_t dmax = nmax / 2;

#if 0     
    for ( int64_t i = 3 ; i < dmax; i += 2 ) {
        if ( isprime( i ) ) {
            if ( ( nmax % i ) == 0 ) {
                factor = i;
            }
        }

        if ( ( i % 10000000 ) == 0 ) {
            cout << i << endl;
        }
    }
#else
    generate_sieve_of_eratosthenes( nmax );

    for ( int64_t i = 1; i != sieve.size(); i++ ) {
        if ( sieve[ i ]  == true ) {
            if ( ( nmax % i ) == 0 ) {
                factor = i;
            }
        }
    }
#endif

    cout << "The largest prime factor of " << nmax << " is " << factor << endl;

    return 0;
}
