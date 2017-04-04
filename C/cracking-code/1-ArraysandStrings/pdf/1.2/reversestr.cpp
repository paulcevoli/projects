// Exercise 1.2 Write code to reverse a C style string.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

void dumpstring( char *pstr, int32_t len )
{
    for ( int i = 0; i <= len; i++ ) {
        printf( "('%c', '%d') ", pstr[ i ], pstr[ i ] ) ;
    }

    printf( "\n" );
}

int main( int argc, char *argv[] )
{
    if ( argc != 2 )
    {
        printf( "%s string\n", argv[ 0 ] );
        exit( 1 );
    }

    char *pstr = argv[ 1 ];
    int32_t len = strlen( pstr );

    dumpstring( pstr, len );

    for ( int i  = 0, j = len; i <= j; i++, j-- ) {
        char tmp;
        
        tmp = pstr[ i ];
        pstr[ i ] = pstr[ j ];
        pstr[ j ] = tmp;
    }

    dumpstring( pstr, len );
}
