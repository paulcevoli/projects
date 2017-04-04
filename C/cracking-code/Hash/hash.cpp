#include <iostream>
#include <stdlib.h>

#include "hash.hpp"

static const int hash_size = 32;

static hash *hash_table[ hash_size ] = { NULL };

static int hash_code( int key )
{
    return key % hash_size;
}

hash *search_hash( int key )
{
    int index = hash_code( key );
    int start = index;
    hash *phash = NULL;

    while ( ( hash_table[ index ] != NULL ) && ( hash_table[ index ]->key != key ) )
    {
        index = ++index % hash_size;

        if ( index == start )
           return NULL;  
    }

    return hash_table[ index ]; 
}

void insert_hash( int key, int data )
{
    hash *phash = new hash;
    phash->key = key;
    phash->data = data;

    int index = hash_code( key );
    int start = index;

    while ( hash_table[ index ] != NULL )
    {
        index = ++index % hash_size;

        if ( index == start )
           return;  
    }

    hash_table[ index ] = phash;
}

void delete_hash( int key )
{
    int index = hash_code( key );
    int start = index;

    while ( hash_table[ index ]->key != key )
    {
        index = ++index % hash_size;

        if ( index == start )
           return;  
    }

    hash *phash = hash_table[ index ];
    hash_table[ index ] = NULL;
    delete phash;
}

void print_hash()
{
    int index = 0;

    std::cout << "Printing Hash table" << std::endl;

    for ( index = 0; index < hash_size; index++ )
    {
        if ( hash_table[ index ] != NULL )
        {
            std::cout << hash_table[ index ]->key << " " << hash_table[ index ]->data << std::endl;
        }
        else
        {
            std::cout << "~~ ~~" << std::endl;
        }
    }
}

void destroy_hash()
{
    int index = 0;

    for ( index = 0; index < hash_size; index++ )
    {
        if ( hash_table[ index ] != NULL )
        {
            delete hash_table[ index ];
        }
    }
}
