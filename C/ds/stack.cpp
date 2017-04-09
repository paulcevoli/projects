/*
 * implementation of a stack using a list
 */

#include <iostream>
#include <climits>

#include "ds.h"

stack_node *stack_new( void ) {
    auto stack = new stack_node;
    stack->next = nullptr;
    stack->elements = 0;
    return stack;
}

void stack_delete( stack_node *stack ) {
    while ( stack->next != nullptr ) {
        stack->next = list_remove( stack->next, stack->next );
    }

    delete stack;
}

int stack_top( stack_node *stack ) {
    int data = INT_MAX;

    if ( stack->elements > 0 ) {
        data = stack->next->data;
    }

    return data;
}

bool stack_empty( stack_node *stack ) {
    return !stack->elements > 0;
}

stack_node *stack_push( stack_node *stack, int data ) {
    if ( stack == nullptr ) {
        stack = stack_new();
    }

    stack->elements++;
    stack->next = list_insert_head( stack->next, data );
    return stack;
}

int stack_pop( stack_node *stack ) {
    int data = INT_MAX;
    if ( stack != nullptr ) {
        if ( stack->elements > 0 ) {
            stack->elements--;
            stack->next = list_remove( stack->next, list_search( stack->next, stack_top( stack ) ) );
            if ( stack->next != nullptr ) {
                data = stack->next->data;
            }
        }
    }
    return data;
}

void stack_print( stack_node *stack ) {
    list_print( stack->next );
}

