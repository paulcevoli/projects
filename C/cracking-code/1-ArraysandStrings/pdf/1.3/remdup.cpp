//
//  uniqchar.cpp
//  Implement and algorith to determine if a string has all unique characters
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

const uint32_t ascii_a = 97;

int main(int argc, char *argv[])
{
    uint32_t charmask = 0;
    int32_t  len = 0;
    char     *pstr = NULL;

    if ( argc != 2 ) {
        printf( "%s: string\n", argv[0] );
        exit( -1 );
    }

    pstr = argv[ 1 ];
    len = strlen( pstr );
    int i = 0;

    if ( pstr == NULL ) {
        return 0;
    }

    if ( len < 2 ) {
        return 0;
    }

    while ( i < len ) {
        uint32_t charbit = ( 1 << ( tolower( pstr[ i ] ) - ascii_a ) );
        if ( ( charmask & charbit ) != 0 ) {
            memmove( &pstr[ i ], &pstr[ i + 1 ], len - i );
            pstr[ len ] = 0;
            len--;
        } else {
            charmask |= charbit;
            i += 1;
        }
    }

    printf( "nodup string %s \n", pstr );
}
