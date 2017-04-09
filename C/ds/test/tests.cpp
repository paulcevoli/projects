#include <iostream>
#include "ds.h"

using namespace std;

void test_list() {

    cout << "List test" << endl;

    list_node *head = nullptr;
    head = list_insert_head( head, 0 );
    head = list_insert_head( head, 1 );
    head = list_insert_head( head, 2 );
    head = list_insert_head( head, 3 );
    list_print( head );

    list_node *find = nullptr;
    find = list_search( head, 3 );
    cout << hex << find << " " << find->data << endl;
    find = list_search( head, 7 );
    cout << hex << find << endl << dec;

    list_node *tail = nullptr;
    tail = list_insert_tail( tail, 0 );
    tail = list_insert_tail( tail, 1 );
    tail = list_insert_tail( tail, 2 );
    tail = list_insert_tail( tail, 3 );
    list_print( tail );

    list_node *sorted_head = nullptr;    
    sorted_head = list_insert_sorted( sorted_head, 0 );
    sorted_head = list_insert_sorted( sorted_head, 1 );
    sorted_head = list_insert_sorted( sorted_head, 2 );
    sorted_head = list_insert_sorted( sorted_head, 3 );
    sorted_head = list_insert_sorted( sorted_head, 6 );
    sorted_head = list_insert_sorted( sorted_head, 5 );
    sorted_head = list_insert_sorted( sorted_head, 4 );
    sorted_head = list_remove( sorted_head, list_search( sorted_head, 0 ) );
    sorted_head = list_remove( sorted_head, list_search( sorted_head, 6 ) );
    sorted_head = list_remove( sorted_head, list_search( sorted_head, 4 ) );
    sorted_head = list_remove( sorted_head, list_search( sorted_head, 9 ) );
    list_print( sorted_head );
}


void test_tree() {

    cout << "Tree test" << endl;

    tree_node *root = nullptr;
    list_node *sorted_head = nullptr;    
    root = tree_insert( root, 1 );
    root = tree_insert( root, 3 );
    root = tree_insert( root, 0 );
    root = tree_insert( root, 6 );
    root = tree_insert( root, 5 );
    root = tree_insert( root, 4 );
    root = tree_insert( root, 2 );
   
    tree_inorder( root, &sorted_head );
    list_print( sorted_head );

    for ( int i = 0; i <= 6; i++ ) {
        sorted_head = list_remove( sorted_head, list_search( sorted_head, i ) );
    }

    tree_preorder( root, &sorted_head );
    list_print( sorted_head );

    for ( int i = 0; i <= 6; i++ ) {
        sorted_head = list_remove( sorted_head, list_search( sorted_head, i ) );
    }

    tree_postorder( root, &sorted_head );
    list_print( sorted_head );

    for ( int i = 0; i <= 6; i++ ) {
        sorted_head = list_remove( sorted_head, list_search( sorted_head, i ) );
    }

    for ( int i = 0; i <= 6; i++ ) {
        root = tree_remove( root, tree_search( root, i ) );
    }

    cout << root << endl;
}

void test_stack() {
    cout << "Stack test" << endl;

    stack_node *stack = stack_new(); 
    stack = stack_push( stack, 5 );
    stack_print( stack );
    stack = stack_push( stack, 10 );
    stack_print( stack );
    stack = stack_push( stack, 15 );
    stack_print( stack );
    stack = stack_push( stack, 20 );
    stack_print( stack );
    stack = stack_push( stack, 0 );
    stack_print( stack );
    stack = stack_push( stack, -15 );
    stack_print( stack );

    stack_delete( stack );
}

int main() {
    test_list();
    test_tree();
    test_stack();

    return 0;
}
