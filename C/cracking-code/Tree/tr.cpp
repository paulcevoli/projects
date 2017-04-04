#include <iostream>

#include "tree.hpp"

int main()
{

    std::cout << "Building tree..." << std::endl;
    insert_tree( get_root(), 9  );
    insert_tree( get_root(), 4  );
    insert_tree( get_root(), 15 );
    insert_tree( get_root(), 6  );
    insert_tree( get_root(), 12 );
    insert_tree( get_root(), 17 );
    insert_tree( get_root(), 2  );

    std::cout << "Searching tree..." << std::endl;
    std::cout << std::hex << search_tree( *get_root(), 4  ) << std::endl;
    std::cout << std::hex << search_tree( *get_root(), 12 ) << std::endl;
    std::cout << std::hex << search_tree( *get_root(), 88 ) << std::endl;
    std::cout << std::hex << search_tree( *get_root(), 2  ) << std::endl;
    std::cout << std::endl;

    std::cout << std::dec;
    std::cout << "Inorder tree..." << std::endl;
    inorder_tree( *get_root() );
    std::cout << std::endl;

    std::cout << "Preorder tree..." << std::endl;
    preorder_tree( *get_root() );
    std::cout << std::endl;

    std::cout << "Postorder tree..." << std::endl;
    postorder_tree( *get_root() );
    std::cout << std::endl;

    std::cout << "Removing tree..." << std::endl;
    remove_tree( *get_root(), 15 );
    remove_tree( *get_root(), 6 );
    remove_tree( *get_root(), 22 );
    remove_tree( *get_root(), 2 );

    std::cout << std::dec;
    std::cout << "Inorder tree..." << std::endl;
    inorder_tree( *get_root() );
    std::cout << std::endl;

    std::cout << "Deleting tree..." << std::endl;
    delete_tree( *get_root() );

    return 0;
}
