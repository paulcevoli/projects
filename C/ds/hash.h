#ifndef c_hash_h
#define c_hash_h

struct hash_item {
    char     ckey[ 128 ];
    uint32_t key;
    uint32_t data;
};

struct hash_table {
    uint32_t    size;
    hash_table  *hash;
};

hash_table *hash_create( uint32_t size );
void hash_destroy( hash_table *hash );

hash_item *hash_search( hash_table *hash, uint32_t key );
void hash_insert( hash_table *hash, uint32_t key, uint32_t data );
void hash_delete( hash_table *hash, uint32_t key );
void hash_print( hash_table *hash );
void hash_destroy( hash_table *hash );

#endif
