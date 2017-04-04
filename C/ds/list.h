/*
 * simple implementation of of list
 */

#ifndef c_list_h
#define c_list_h

struct  list_node {
    list_node   *next;
    int         data;
};

list_node* list_insert_head( list_node *head, int data );
list_node* list_insert_tail( list_node *head, int data );
list_node* list_insert_sorted( list_node *head, int data );
list_node* list_search( list_node *head, int data );
list_node* list_remove( list_node *head, list_node *target );

void list_print( list_node *head );

#endif
