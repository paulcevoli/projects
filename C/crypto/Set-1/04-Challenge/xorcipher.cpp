#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "hash.h"
#include "crypto.h"

int main( int argc, char *argv[] )
{
    if ( argc != 2 ) {
        printf( "%s filename\n", argv[ 0 ] );
        return 1;
    }

    FILE *fp = fopen( argv[1], "r" );
    if ( fp == NULL ) {
        printf( "Unable to open '%s' - bye\n", argv[ 1 ] );
        return 1;
    }

    double max = 0.0;
    double score;
    char line[ 128 ];

    char *pBase = (char *)malloc( 128 * sizeof( char ) );
    char *pBest = (char *)malloc( 128 * sizeof( char ) );

    while( fscanf( fp, "%s", line ) != EOF ) { 

printf( "%s\n", line );

        clock_t start = clock();

        crypto_xorcrypto( line, pBase, &score );

        clock_t end = clock();
        double duration = static_cast<double>(end - start)  * 1000 / CLOCKS_PER_SEC;

        if ( score > max ) {    
            max = score;
            strncpy( pBest, pBase, strlen( pBase ) );
        }

        printf( " %s, %f, %f\n", pBase, score, duration ); 
    }

    printf( "%s, %f\n", pBest, max ); 

    fclose( fp );
    free( pBase );
    free( pBest );

    return 0;
}
