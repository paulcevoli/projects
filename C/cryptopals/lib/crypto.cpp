//
//  crypto.cpp
//  utility routines for the crypto challenge
//
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "hash.h"

static const char *c_pBase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghilklmnopqrstuvwxyz0123456789+/";
static const uint32_t c_Base64Mask = 63;
static const uint8_t  c_HexError = 16;

//
// char2hex convert an input character to a hex value
//
uint8_t crypto_char2hex( const char letter )
{
#if 0
    uint8_t digit = static_cast< uint8_t >( Char );
    if ( isxdigit( digit ) ) {
        if ( isupper( digit ) ) {
            digit -= 'A';
            digit += 10;
        } else if ( islower( digit ) ) {
            digit -= 'a';
            digit += 10;
        } else if ( isdigit( digit ) ) {
            digit -= '0';
        }
    } else {
        return c_HexError;
    }
#else
    // use of case statement improves execution speed
    switch ( letter ) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'a':
        case 'A':
            return 10;
        case 'b':
        case 'B':
            return 11;
        case 'c':
        case 'C':
            return 12;
        case 'd':
        case 'D':
            return 13;
        case 'e':
        case 'E':
            return 14;
        case 'f':
        case 'F':
            return 15;
    }
#endif
    return c_HexError;
}

//
// hex2char: convert a hex number to its ASCII char equivalent
//

static const uint8_t c_ascii_0 = '0';
static const uint8_t c_ascii_a = 'a';

inline char crypto_hex2char( uint8_t Hex )
{
    char letter = Hex;

    if ( letter <= 9 ) {
        letter += c_ascii_0;
    } else {
        letter += ( c_ascii_a - 10 );
    }

    return letter;
}

//
// fixedxor: given 2 strings compute their XOR value
//
int crypto_fixedxor(const char *pHex1, const char *pHex2, char *pXOR )
{
    uint32_t len16 = strlen( pHex1 );

    for ( uint32_t i = 0; i < len16; i++ ) {
        uint8_t digitXOR;

        digitXOR = crypto_char2hex( pHex1[ i ] ) ^ crypto_char2hex( pHex2[ i ] ); 

        pXOR[ i ] = crypto_hex2char( digitXOR );
    }

    return 0;
}

//
// hex2base64: convert a ASCII string of hex chars to base 64
int crypto_hex2base64(const char *pHex, char *pBase64 )
{
    uint32_t bits;
    uint32_t digit;
    uint32_t len16 = strlen( pHex );
    uint32_t len64 = 0;

    for ( uint32_t i = 0, j = 0; i < len16; i += 6, j += 4 ) {
       
        bits  = 0;

        for ( uint32_t k = 0; k < 6; k++ ) {

            digit = crypto_char2hex( pHex[ i + k ] );

            bits |= digit << ( 4 * ( 5 - k ) );
        }

        pBase64[ j     ] = c_pBase64[ ( ( bits >> 18 ) & c_Base64Mask ) ];
        pBase64[ j + 1 ] = c_pBase64[ ( ( bits >> 12 ) & c_Base64Mask ) ];
        pBase64[ j + 2 ] = c_pBase64[ ( ( bits >>  6 ) & c_Base64Mask ) ];
        pBase64[ j + 3 ] = c_pBase64[ ( ( bits )       & c_Base64Mask ) ];

        len64 = j + 3;
    }

    for ( uint32_t i = 0; len64 % 3; i++ ) {
        pBase64[ len64 + i ] = '=';
    }

    return 0;
}

typedef struct {
    uint32_t    letter;
    double      frequency;
} freq_t;


static const freq_t c_FreqTable[] = {
    { 'e', 12.02 },
    { 't',  9.10 },
    { 'a',  8.12 },
    { 'o',  7.68 },
    { 'i',  7.31 },
    { 'n',  6.95 },
    { 's',  6.28 },
    { 'r',  6.02 },
    { 'h',  5.92 },
    { 'd',  4.32 },
    { 'l',  3.98 },
    { 'u',  2.88 },
    { 'c',  2.71 },
    { 'm',  2.61 },
    { 'f',  2.30 },
    { 'y',  2.11 },
    { 'w',  2.09 },
    { 'g',  2.03 },
    { 'p',  1.82 },
    { 'b',  1.49 },
    { 'v',  1.11 },
    { 'k',  0.69 },
    { 'x',  0.17 },
    { 'q',  0.11 },
    { 'j',  0.10 },
    { 'z',  0.07 }
};


static const int32_t c_FreqTableSize = sizeof(c_FreqTable) / sizeof(freq_t);

static double letterscore() 
{
    double score = 0.0;

    for ( int32_t i = 0; i < c_FreqTableSize; i++ ) {
        hash_t *pHash = NULL;

        pHash = hash_search( c_FreqTable[ i ].letter );

        if ( pHash != NULL ) {
            score += ( pHash->data * c_FreqTable[ i ].frequency );
        }
    }

    return score;
}

static double wordscore( char* pString )
{
    double score = 0.0;
    char *pWord;
    char command[ 256 ];
    int stat = 0;
    char *pDup = strdup( pString );

    if ( pDup == NULL ) {
        return 0.0;
    }

    pWord = strtok( pDup, " " );
    while ( pWord != NULL ) {
        bool legal;
        int len;

        legal = true;
        len = strlen( pWord );

        for ( int i = 0; i < len; i++ ) {
            if ( !isalpha( pWord[ i ] ) ) {
                    legal = false;
            }
        }

        if ( legal ) {
            sprintf( command, "fgrep -i \"%s\" wordlist > /dev/null 2>&1", pWord );
            stat = system( command );
            if ( stat == 0 ) {
                score = letterscore();
                break;
            }
        }

        pWord = strtok( NULL, " " );
    }

    free( pDup );

    return score;
}

void crypto_xorcrypto(const char *pHex, char *pBase, double *score )
{
    uint32_t len16 = strlen( pHex );
    char *tmp = NULL;
    char *pBest = NULL;
    double max = 0.0;

    tmp = (char*)malloc( strlen( pHex ) );

    // convert hex string to binary
    for ( uint8_t i = 0 ; i < len16; i++ ) {
        tmp[ i ] = crypto_char2hex( pHex[ i ] ) ; 
    }

    for ( uint8_t crypt = 1; crypt < 255; crypt++ ) {
        double score = 0.0;
        int sentenceCount;
        char sentence[ 256 ];

        memset( sentence, 0, 256 );
        sentenceCount = 0;
        hash_destroy();

        for ( uint8_t j = 0; j < strlen( tmp ); j +=2 ) {
            uint8_t letter;

            letter =  ( ( tmp[ j ] << 4 ) | ( tmp[ j + 1 ] ) ) ^ crypt;
            if ( ( isalnum( letter ) || isspace( letter ) || ispunct( letter ) ) && ( !iscntrl( letter ) ) ) {
                uint8_t lower;
                hash_t *pHash;

                sentence[ sentenceCount++ ] = letter;

                lower = tolower( letter );
                pHash = hash_search( lower );
                if ( pHash == NULL ) {
                    hash_insert( lower, 1 );
                } else {
                    pHash->data += 1;
                }
            } else {
                // if control chars or non letters/numbers give up
                break;
            }
        }

        if ( sentenceCount > 0 ) {

            score = wordscore( sentence );
            if ( score > max ) {
                max = score;

printf( "new best score = (%s:%f)\n", sentence, score );

                if ( pBest != NULL ) {
                    free( pBest );
                }

                pBest = strdup( sentence );
            }
        }
    }

    *score = max;
    if ( ( pBase != NULL ) && ( pBest != NULL ) ) {
        strncpy( pBase, pBest, strlen( pBest ) );  
        free( pBest );
    }

    free( tmp );
}

