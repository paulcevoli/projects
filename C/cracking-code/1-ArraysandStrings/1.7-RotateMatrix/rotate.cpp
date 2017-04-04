#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void RotateNxN( int *matrix, int size )
{
    int i, j;
    int matrixsz = sizeof(int) * size * size;

    int *rotated = (int *)malloc( matrixsz );
    if ( rotated == NULL ) {
        return;
    }

    for ( i = 0; i < size; i++ ) {
        for ( j = 0; j < size; j++ ) {
            int xy = ( i * size ) + j;
            int yx = ( size * ( size - 1 - j ) + i );
            *( rotated + yx ) = *( matrix + xy ); 
        }
    }

    memcpy( matrix, rotated, matrixsz );

    free( rotated );
}

int main( int argc, char *argv[] )
{
    int m3x3[ 3 ][ 3 ] = {  { 1, 2, 3 }, 
                            { 4, 5, 6 }, 
                            { 7, 8, 9 } } ;
    int m5x5[ 5 ][ 5 ] = {  {  1,  2,  3,  4,  5 }, 
                            {  6,  7,  8,  9, 10 }, 
                            { 11, 12, 13, 14, 15 },
                            { 16, 17, 18, 19, 20 },
                            { 21, 22, 23, 24, 25 } } ;

    printf( "initial\n" );
    PrintNxN( &m3x3[ 0 ][ 0 ], 3 );
    RotateNxN( &m3x3[ 0 ][ 0 ], 3 );
    printf( "rotated\n" );
    PrintNxN( &m3x3[ 0 ][ 0 ], 3 );
    printf( "initial\n" );
    PrintNxN( &m5x5[ 0 ][ 0 ], 5 );
    RotateNxN( &m5x5[ 0 ][ 0 ], 5 );
    printf( "rotated\n" );
    PrintNxN( &m5x5[ 0 ][ 0 ], 5 );

    return 0;
}
