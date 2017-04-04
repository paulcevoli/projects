/*
 * debugging utilities
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "debug.h"

void dbg_dump_buffer( char *pbuffer, uint32_t length ) {
    for ( uint32_t i = 0; i < length; i += 8 ) {
        for ( uint32_t j = 0;  j < 8 ; j++ ) {
            if ( ( i + j ) < length ) { 
                printf( "%2X ", pbuffer[ i + j ] );
            } else {
                printf( "   " );
            }	
        }

        for ( uint32_t j = 0; ( ( j < 8 ) && ( ( i + j ) < length ) ) ; j++ ) {
            if ( isprint( pbuffer[ i + j ] ) ) {
                printf( "%1c", pbuffer[ i + j ] );
            } else { 
                printf( "." );
            }
        }

        printf( "\n" );
    }
}
