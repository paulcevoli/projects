//
//  crypto.h
//  Header file for code for the Crypto security challenge
//  http://www.cryptopals.com
//
#ifndef c_crypto_h
#define c_crytpo_h

#include <stdint.h>

uint8_t crypto_char2hex( char letter );
char    crypto_hex2char( uint8_t digit );
int     crypto_hex2base64(const char *phex, char *pbase64 );
void    crypto_fixedxor(const char *phex1, const char *phex2, char *pxor );
void    crypto_xorcrypto(const char *pHex, char *pBase, double *score );

#endif

