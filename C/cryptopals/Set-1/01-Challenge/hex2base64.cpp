// Crypto Challenge Set 1 Challenge 1
// Convert hex to base64
//
#include <stdio.h>
#include <string.h>

#include "crypto.h"

int main( int argc, char *argv[] )
{
    if ( argc != 2 ) {
        printf( "%s hex-string\n", argv[ 0 ] );
        return 1;
    }

    char *pBase64 = new char[ 2 * strlen( argv[ 1 ] ) ];

    crypto_hex2base64( argv[ 1 ], pBase64 );

    printf( "%s\n", pBase64 ); 

    delete pBase64;

    return 0;
}
