#ifndef c_hash_hpp
#define c_hash_hpp

typedef struct
{
    int data;
    int key;
} hash;

hash *search_hash( int key );
void insert_hash( int key, int data );
void delete_hash( int key );
void print_hash();
void destroy_hash();

#endif
