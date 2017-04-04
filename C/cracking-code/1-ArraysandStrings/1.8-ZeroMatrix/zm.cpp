#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void PrintNxN( int *matrix, int size )
{
    int i, j;

    for ( i = 0; i < size; i++ ) {
        for ( j = 0; j < size; j++ ) {
            printf( " { %3d }", matrix[ i * size + j ] ); 
        }

        printf( "\n" );
    }
}

void ZeroNxN( int *matrix, int size )
{
    int i, j;
    uint32_t rows = 0;
    uint32_t cols = 0;

    // size limited to 32 due to bit masks (unit32_t )
    if ( size > 32 ) {
        return;
    }

    for ( i = 0; i < size; i++ ) {
        for ( j = 0; j < size; j++ ) {
            int xy = ( i * size ) + j;
            if ( *( matrix + xy ) == 0 ) {
                //mark row and column for zeroing
                rows |= ( 1 << i );
                cols |= ( 1 << j );
            }
        }
    }

    for ( i = 0; i < size; i++ ) {
        for ( j = 0; j < size; j++ ) {
            uint32_t r = ( 1 << i );
            uint32_t c = ( 1 << j );
            int xy = ( i * size ) + j;

            if ( ( rows & r ) || ( cols & c ) ) {
                *( matrix + xy ) = 0;
            } 
        }
    }
}

int main( int argc, char *argv[] )
{
    int m3x3[ 3 ][ 3 ] = {  { 1, 2, 3 },
                            { 4, 5, 6 },
                            { 7, 8, 9 } };
    int m4x4[ 4 ][ 4 ] = {  { 1,   2,  3,  4 }, 
                            { 4,   5,  6,  6 }, 
                            { 7,   8,  9,  9 },
                            { 10, 11, 12, 13 } } ;
    int m5x5[ 5 ][ 5 ] = {  {  1,  2,  3,  4,  5 }, 
                            {  6,  0,  8,  9, 10 }, 
                            { 11, 12, 13, 14, 15 },
                            { 16, 17, 18,  0, 20 },
                            { 21, 22, 23, 24, 25 } } ;

    printf( "initial\n" );
    PrintNxN( &m3x3[ 0 ][ 0 ], 3 );
    ZeroNxN( &m3x3[ 0 ][ 0 ], 3 );
    printf( "zeroed\n" );
    PrintNxN( &m3x3[ 0 ][ 0 ], 3 );

    printf( "initial\n" );
    PrintNxN( &m4x4[ 0 ][ 0 ], 3 );
    ZeroNxN( &m4x4[ 0 ][ 0 ], 3 );
    printf( "zeroed\n" );
    PrintNxN( &m4x4[ 0 ][ 0 ], 3 );

    printf( "initial\n" );
    PrintNxN( &m5x5[ 0 ][ 0 ], 5 );
    ZeroNxN( &m5x5[ 0 ][ 0 ], 5 );
    printf( "zeroed\n" );
    PrintNxN( &m5x5[ 0 ][ 0 ], 5 );

    return 0;
}
