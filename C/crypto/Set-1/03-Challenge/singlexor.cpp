#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "crypto.h"

int main( int argc, char *argv[] )
{
    if ( argc != 2 ) {
        printf( "%s hex-string\n", argv[ 0 ] );
        return 1;
    }

    double score;
    char *pBase = new char[ 2 * strlen( argv[ 1 ] ) ];

    clock_t start = clock();

    crypto_xorcrypto( argv[ 1 ], pBase, &score );

    clock_t end = clock();
    double duration = static_cast<double>(end - start)  * 1000 / CLOCKS_PER_SEC;

    printf( "%s, %f, %f\n", pBase, score, duration ); 

    delete pBase;

    return 0;
}
