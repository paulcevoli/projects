#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int compare( const void *a, const void *b )
{
    return *(const char *) a < *(const char *)b;
}

int main( int argc, char *argv[] )
{
    bool anagram = true;
    char *string1 = argv[ 1 ];
    char *string2 = argv[ 2 ];

    if ( argc != 3 ) {
        printf( "%s string1 string2\n", argv[0] );
        return 1;
    }

    int32_t len1 = strlen( string1 );
    int32_t len2 = strlen( string2 );


    if ( len1 != len2 ) {
        anagram = false;
    } else {
        char *str1cp = new char[ len1 ];
        char *str2cp = new char[ len2 ];

        strncpy( str1cp, string1, len1 );
        strncpy( str2cp, string2, len2 );

        qsort( str1cp, len1, 1, compare );
        qsort( str2cp, len2, 1, compare );

        anagram = !strncmp( str1cp, str2cp, len1 );

        delete str1cp;  
        delete str2cp;  
    }

    printf( "%s %s %s anagrams\n", string1, string2, anagram ? "are" : "are not" );

    return 0;
}
