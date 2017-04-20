// Crypto Challenge Set 1 Challenge 1
// Convert hex to base64
//
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#include "crypto.h"


int main( int argc, char *argv[] )
{
    if ( ( argc != 3 ) || ( strlen( argv[ 1 ] ) != strlen( argv[ 2 ] ) ) ) {
        printf( "%s hex-string1 hex-string2\n", argv[ 0 ] );
        return 1;
    }

    char *pXOR = new char[ 2 * strlen( argv[ 1 ] ) ];

    crypto_fixedxor( argv[ 1 ], argv[ 2 ],  pXOR );

    printf( "%s\n", pXOR ); 

    delete pXOR;

    return 0;
}
