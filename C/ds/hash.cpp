#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "hash.h"

static const uint32_t hash_size = 26;

static hash_t *hash_table[ hash_size ] = { NULL };

static inline uint32_t hash_code( uint32_t key )
{
    return key % hash_size;
}

hash_t *hash_search( uint32_t key )
{
    uint32_t index = hash_code( key );
    uint32_t start = index;

    if ( hash_table[ index ] == NULL ) {

        return NULL;
    }

    while ( ( hash_table[ index ] != NULL ) && ( hash_table[ index ]->key != key ) ) {

        index = ( index + 1 ) % hash_size;

        if ( index == start ) {
           return NULL;  
        }
    }

    return hash_table[ index ]; 
}

void hash_insert( uint32_t key, uint32_t data )
{
    hash_t *phash = new hash_t;

    phash->key = key;
    phash->data = data;

    uint32_t index = hash_code( key );
    uint32_t start = index;

    while ( hash_table[ index ] != NULL ) {
        index = ( index + 1 ) % hash_size;

        if ( index == start )
           return;  
    }

    hash_table[ index ] = phash;
}

void hash_delete( uint32_t key )
{
    uint32_t index = hash_code( key );
    uint32_t start = index;

    while ( hash_table[ index ]->key != key ) {

        index = ( index + 1 ) % hash_size;

        if ( index == start )
           return;  
    }

    hash_t *phash = hash_table[ index ];

    hash_table[ index ] = NULL;
    delete phash;
}

void hash_print()
{
    uint32_t index = 0;

    std::cout << "Printing Hash table" << std::endl;

    for ( index = 0; index < hash_size; index++ ) {
        if ( hash_table[ index ] != NULL ) {
            std::cout << hash_table[ index ]->key << " " << hash_table[ index ]->data << std::endl;
        }  
    }
}

void hash_destroy()
{
    uint32_t index = 0;

    for ( index = 0; index < hash_size; index++ ) {
        if ( hash_table[ index ] != NULL ) {
            delete hash_table[ index ];

            hash_table[ index ] = NULL;
        }
    }
}

hash::hash( int size )
{
    _hash_tbl = new hash_t*[ size ];
}

hash::~hash()
{
    delete []*_hash_tbl;
}

hash_t* hash::search( char *key )
{
    uint32_t index = hash_code( key );
    uint32_t start = index;

    if ( _hash_tbl[ index ] == NULL ) {

        return NULL;
    }

    while ( ( _hash_tbl[ index ] != NULL ) && ( strcmp(_hash_tbl[ index ]->ckey, key ) != 0 ) ) {

        index = ( index + 1 ) % _hash_size;

        if ( index == start ) {
           return NULL;  
        }
    }

    return _hash_tbl[ index ]; 
}

void hash::insert( char *key, uint32_t value )
{
    hash_t *phash = new hash_t;
    int    ssize = strlen( key );

    // do not overwrite the size of the hash string key
    if ( ssize > 64 ) {
        ssize = 64;
    }

    strncpy( phash->ckey, key, ssize  );
    phash->data = value;

    uint32_t index = hash_code( key );
    uint32_t start = index;

    while ( _hash_tbl[ index ] != NULL ) {
        index = ( index + 1 ) % hash_size;

        if ( index == start )
           return;  
    }

    _hash_tbl[ index ] = phash;
}


void hash::print()
{
    uint32_t index = 0;

    std::cout << "Printing Hash table" << std::endl;

    for ( index = 0; index < _hash_size; index++ ) {
        if ( _hash_tbl[ index ] != NULL ) {
            std::cout << _hash_tbl[ index ]->ckey << " " << _hash_tbl[ index ]->data << std::endl;
        }  
    }
}

uint32_t hash::hash_code( char *key )
{
    uint32_t sum = 0;

    for ( uint32_t i = 0; i < strlen( key ); i++ ) {
        sum += key[ i ];   
    }
    return sum % _hash_size;
}

