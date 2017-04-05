/*
 * basic tree data structure implementation
 */
#include <cstdlib>
#include <algorithm>

#include "tree.h"

using namespace std;

/*
 * insert a node creating a BST
 */
tree_node *tree_insert( tree_node *root, int data ) {
    if ( root == nullptr ) {
        auto insert = new tree_node;
        insert->left = insert->right = nullptr;
        insert->data = data;
    }

    if ( root->data > data ) {
        root->left = tree_insert( root->left, data );
    } else {
        root->right = tree_insert( root->right, data );
    }

    return root;
}

/* 
 * find the given node recursively
 */
tree_node *tree_find( tree_node *root, int data ) {
    if ( ( root == nullptr ) || ( root->data == data ) ) {
        return root;
    }

    if ( data < root->data ) {
        return tree_find( root->left, data );
    } else {
        return tree_find( root->right, data );
    }
}

/*
 * remove the given node
 */

static tree_node *find_parent( tree_node *root, tree_node *target ) {
    if ( root == target ) {
        return nullptr;
    }

    while ( ( root->left != target ) && ( root->right != target ) ) {
        if ( target->data < root->data ) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}

static tree_node *find_successor( tree_node *root, tree_node *target ) {

    auto successor = target->right;

    if ( successor == nullptr ) {
        while ( successor->left != nullptr ) {
            successor = successor->left;
        }

        return successor;
    }


    do {
        if ( successor != nullptr ) {
            target = successor;
        }

        successor = find_parent( root, target );
    } while ( ( successor != nullptr ) && ( successor->right == target ) );

    return successor;
}

tree_node *tree_remove( tree_node *root, tree_node *target ) {
    if ( ( target->left != nullptr ) && ( target->right != nullptr ) ) {
        auto next = find_successor( root, target );
        auto data = next->data;
        tree_remove( root, next );
        target->data = data;
        return root;
    }

    if ( ( target->left != nullptr ) || ( target->right != nullptr ) ) {
        auto temp = target->left ? target->left : target->right;
        target->data = temp->data;
        target->left = temp->left;
        target->right = temp->right;
        delete temp;
        return root;
    }

    if ( root == target ) {
        delete root;
        return nullptr;
    }

    auto parent = find_parent( root, target );
    if ( parent->left == target ) {
        parent->left = nullptr;
    } else {
        parent->right = nullptr;
    }

    delete target;
    return root;
}

int32_t tree_size( tree_node *root ) {
    if ( root == nullptr ) {
        return 0;
    }

    return 1 + tree_size( root->left ) + tree_size( root->right );
}

int32_t tree_depth( tree_node *root ) {
    if ( root == nullptr ) {
        return 0;
    }

    return 1 + max( tree_depth( root->left ), tree_depth( root->right ) );
}

bool tree_balanced( tree_node *root ) {
    if ( root == nullptr ) {
        return true;
    }

    auto left_depth = tree_depth( root->left );
    auto right_depth = tree_depth( root->right );

    return ( abs( left_depth - right_depth ) <= 1 );
}

bool tree_find_path( tree_node *root, tree_node *target, int* visit ) {
    return false;
}

void tree_inorder( tree_node *root, int *visit ) {
}

void tree_preorder( tree_node *root, int *visit ) {
}

void tree_postorder( tree_node *root, int *visit ) {
}

