#include <iostream>

#include "hash.hpp"

int main()
{
    hash *ptemp;

    insert_hash( 27, 32768 );
    insert_hash( 32, 65535 );
    insert_hash( 36, 65536 );
    insert_hash( 128, 28000 );

    std::cout << "Search hash" << std::endl;
    ptemp = search_hash( 128 );
    std::cout << ptemp->key << " " << ptemp->data << std::endl;
    ptemp = search_hash( 77 );
    if ( ptemp )
    {
        std::cout << ptemp->key << " " << ptemp->data << std::endl;
    }
    std::cout << std::endl;

    delete_hash( 128 );

    std::cout << "Search hash" << std::endl;
    ptemp = search_hash( 128 );
    if ( ptemp != NULL )
        std::cout << ptemp->key << " " << ptemp->data << std::endl;

    print_hash();

    destroy_hash();

    return 0;
}
