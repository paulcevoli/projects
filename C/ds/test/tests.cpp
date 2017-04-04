#include <iostream>
#include "list.h"

using namespace std;

void test_list() {

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
    cout << hex << find << endl;

    list_node* tail = nullptr;
    tail = list_insert_tail( tail, 0 );
    tail = list_insert_tail( tail, 1 );
    tail = list_insert_tail( tail, 2 );
    tail = list_insert_tail( tail, 3 );
    list_print( tail );

    list_node* sorted_head = nullptr;    
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

int main() {
    test_list();

    return 0;
}
