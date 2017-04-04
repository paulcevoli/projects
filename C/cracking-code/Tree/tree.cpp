#include <iostream>
#include <stddef.h>

#include "tree.hpp"


static tree *root = NULL;

tree **get_root()
{
    return &root;
}

tree *search_tree( tree *node, int val )
{
    if ( node == NULL )
    {
        return NULL;
    }
    else if ( node->data == val )
    {
        return node;
    }
    else if ( val < node->data )
    {
         search_tree( node->left, val );
    }
    else
    {
         search_tree( node->right, val );
    }
}

void insert_tree( tree **node, int val )
{
    if ( *node == NULL )
    {
        tree *new_node = new tree;

        new_node->data = val;
        new_node->left = new_node->right = NULL;

        *node = new_node;
    }
    else
    {
        if ( val < (*node)->data )
        {
            insert_tree( &(*node)->left, val );
        }
        else
        {
            insert_tree( &(*node)->right, val );
        }
    }
}

tree *remove_tree( tree* node, int val )
{
    if ( node == NULL )
    {
        return node;
    }
    else if ( val < node->data )
    {
        node->left = remove_tree( node->left, val );
    }
    else if ( val > node->data )
    {
        node->right = remove_tree( node->right, val );
    }
    else
    {
        if ( ( node->left == NULL ) && ( node->right == NULL ) )
        {
             delete node;
     
             node = NULL;
        }
        else if ( node->left == NULL )
        {
            tree *temp = node;

            node = node->right;

            delete temp;
        }
        else if ( node->right == NULL )
        {
            tree *temp = node;

            node = node->left;

            delete temp;
        }
        else
        {
            tree *temp = node->right;

            while ( temp->left != NULL )
            {
                temp = temp->left;
            }

            node->data = temp->data;

            node->right = remove_tree( node->right, temp->data );
        }
    }

    return node;
}

void  delete_tree( tree *node )
{
    if ( node )
    {
        delete_tree( node->left );
        delete_tree( node->right );
        delete node;
    }
}

void  inorder_tree( tree* node )
{
    if ( node )
    {
        inorder_tree( node->left );
        std::cout << node->data << " ";
        inorder_tree( node->right );
    } 
}

void  preorder_tree( tree* node )
{
    if ( node )
    {
        std::cout << node->data << " ";
        preorder_tree( node->left );
        preorder_tree( node->right );
    } 
}

void  postorder_tree( tree* node )
{
    if ( node )
    {
        postorder_tree( node->left );
        postorder_tree( node->right );
        std::cout << node->data << " ";
    } 
}

