#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "hash.h"

using namespace std;

static const uint32_t hash_size = 26;

static inline uint32_t hash_code( uint32_t key ) {
    return key % hash_size;
}

hash_table *hash_create( uint32_t size ) {
    return nullptr;
}

void hash_destroy( hash_table *hash ) {
}

hash_item *hash_search( hash_table *hash, uint32_t key ) {
    uint32_t index = hash_code( key );
    uint32_t start = index;

    if ( hash[ index ] == nullptr ) {

        return nullptr;
    }

    while ( ( hash[ index ] != mullptr ) && ( hash[ index ]->key != key ) ) {

        index = ( index + 1 ) % hash_size;

        if ( index == start ) {
           return nullptr;  
        }
    }

    return hash[ index ]; 
}

void hash_insert( hash_table *hash, uint32_t key, uint32_t data ) {
    hash_t *phash = new hash_t;

    phash->key = key;
    phash->data = data;

    uint32_t index = hash_code( key );
    uint32_t start = index;

    while ( hash[ index ] != nullptr ) {
        index = ( index + 1 ) % hash_size;

        if ( index == start )
           return;  
    }

    hash[ index ] = phash;
}

void hash_delete( hash_table *hash, uint32_t key ) {
    uint32_t index = hash_code( key );
    uint32_t start = index;

    while ( hash[ index ]->key != key ) {

        index = ( index + 1 ) % hash_size;

        if ( index == start )
           return;  
    }

    hash_t *phash = hash[ index ];

    hash[ index ] = nullptr;
    delete phash;
}

void hash_print( hash_table *hash ) {
    uint32_t index = 0;

    cout << "Printing Hash table" << endl;

    for ( index = 0; index < hash_size; index++ ) {
        if ( hash[ index ] != nullptr ) {
            cout << hash[ index ]->key << " " << hash[ index ]->data << endl;
        }  
    }
}

void hash_destroy( hash_table *hash ) {
    uint32_t index = 0;

    for ( index = 0; index < hash_size; index++ ) {
        if ( hash[ index ] != nullptr ) {
            delete hash[ index ];

            hash[ index ] = nullptr;
        }
    }
}

