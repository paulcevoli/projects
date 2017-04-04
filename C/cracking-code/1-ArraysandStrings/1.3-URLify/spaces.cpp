#include <stdio.h>
#include <string.h>
#include <stdint.h>

using namespace std;

// replace space
// replaces all instances of ' ' with %20
//
void replacespace( char *pstr, int32_t max )
{
    int len = strlen( pstr );
    int nspace = 0;

    for ( int i = 0; i < strlen( pstr ); i++ ) {
        if ( pstr[ i ] == ' ' ) {
            nspace++;
        }
    }

    // make sure new string can fit in parameter
    int newlen = len + nspace * 2;
    if ( newlen > max ) {
        return;
    }

    for ( ; len >= 0; len-- ) {
        if ( pstr[ len ] == ' ' ) {
            pstr[ newlen - 2 ] = '%';
            pstr[ newlen - 1 ] = '2';
            pstr[ newlen - 0 ] = '0';
            newlen -= 3;
        } else {
            pstr[ newlen ] = pstr[ len ];
            newlen -= 1;
        }            
    }
}

const int maxstring = 512;

int main( int argc, char *argv[] )
{
    if ( argc != 2 ) {
        printf( "%s string\n", argv[ 0 ] );
        return 1;
    }

    char *str = new char[ maxstring ];

    strncpy( str, argv[ 1 ], strlen( argv[ 1 ] ) );

    replacespace( str, maxstring );

    printf( "%s\n", str );

    delete str;

    return 0;
}
