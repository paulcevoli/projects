/*
 *  basic list operations
 */

#include <iostream>
#include <cstdlib>

#include "list.h"

using namespace std;

// insert a new node at the head of a list
list_node* list_insert_head( list_node* head, int data ) {

    list_node* insert = new list_node;
    insert->data = data;
    insert->next = nullptr;

    if ( head == nullptr ) {
        head = insert;
    } else {
        insert->next = head;
        head = insert;
    }

    return head;
}

// insert a new node at the tail of a list
list_node* list_insert_tail( list_node* head, int data ) {

    list_node* insert = new list_node;
    insert->data = data;
    insert->next = nullptr;

    if ( head == nullptr ) {
        head = insert;
    } else {
        list_node *current = head;

        while ( current->next != nullptr ) {
            current = current->next;
        }

        list_node* insert = new list_node;
        insert->data = data;
        insert->next = current->next;
        current->next = insert;
    }

    return head;
}
list_node* list_insert_sorted( list_node* head, int data ) {

    if ( ( head == nullptr ) || ( head->data > data ) ) {
        head = list_insert_head( head, data );
    } else {
        list_node *current = head;

        while ( ( current->next != nullptr ) && ( current->next->data < data ) ) {
            current = current->next;
        }

        list_node* insert = new list_node;
        insert->data = data;
        insert->next = current->next;
        current->next = insert;
    }

    return head;
}

list_node* list_search( list_node* head, int data ) {

    list_node* current = head;

    while ( ( current != nullptr ) && ( current->data != data ) ) {
        current = current->next;
    }

    return current;
}

list_node* list_remove( list_node* head, list_node* target ) {

    if ( target != nullptr ) {
        if ( head == target ) {
            head = head->next;
        } else {
            list_node *current = head;

            while ( ( current->next != target ) && ( current->next != nullptr ) ) {
                current = current->next;   
            }

            current->next = current->next->next;
        }

        delete target;
    }


    return head;
}

void list_print( list_node* head ) {
    list_node* current = head;

    while ( current != nullptr ) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}
