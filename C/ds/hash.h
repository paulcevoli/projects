#ifndef c_hash_hpp
#define c_hash_hpp

typedef struct
{
    char     ckey[ 64 ];
    uint32_t key;
    uint32_t data;
} hash_t;

hash_t *hash_search( uint32_t key );
void hash_insert( uint32_t key, uint32_t data );
void hash_delete( uint32_t key );
void hash_print();
void hash_destroy();

class hash {
    public:
        hash( int size );
        ~hash();

        hash_t*     search( char* key );
        void        insert( char* key, uint32_t data );
        void        print();

    private:
        uint32_t hash_code( char* key );

        hash_t  **_hash_tbl;
        uint32_t  _hash_size;
};

#endif
