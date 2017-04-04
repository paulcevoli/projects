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
    bool     uniq = true;

    if ( argc != 2 ) {
        printf( "%s: string\n", argv[0] );
        exit( -1 );
    }

    pstr = argv[ 1 ];
    len = strlen( pstr );

    for ( int i = 0; i < len; i++ ) {
        uint32_t charbit = ( 1 << ( tolower( pstr[ i ] ) - ascii_a ) );

        //printf( "%#8x, %#8x\n", charmask, charbit );

        if ( ( charmask & charbit ) == 1 ) {
            uniq = false;
        } else {
            charmask |= charbit;
        }
    }

    printf( "%s %s unique\n", pstr, uniq ? "is" : "is not" );
}
