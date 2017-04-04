#ifndef c_tree_h

typedef struct tree
{
    int data;
    tree *left, *right;
} tree;


tree  **get_root();

tree  *search_tree( tree *node, int val );
void  insert_tree( tree **node, int val );
tree  *remove_tree( tree *node, int val );

void  delete_tree( tree *node );

void  inorder_tree( tree *node );
void  preorder_tree( tree *node );
void  postorder_tree( tree *node );

#endif
