/*
 * tree data structure implmentation
 */
#ifndef c_tree_h
#define c_tree_h

#include <cstdint>

struct tree_node {
    int data;
    tree_node *right;
    tree_node *left;
};

tree_node *tree_insert( tree_node *root, int data );
tree_node *tree_find( tree_node *root, int data );
tree_node *tree_remove( tree_node *root, tree_node *target );

int32_t tree_size( tree_node *root );
int32_t tree_depth( tree_node *root );
bool tree_balanced( tree_node *root );

bool tree_find_path( tree_node *root, tree_node *target, int* visit );
void tree_inorder( tree_node *root, int *visit );
void tree_preorder( tree_node *root, int *visit );
void tree_postorder( tree_node *root, int *visit );

#endif
