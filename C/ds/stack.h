#ifndef c_stack_h
#define c_stack_h

#include "list.h"

struct  stack_node {
    list_node   *next;
    int         elements;
};

stack_node *stack_new( void );
void stack_delete( stack_node *stack );

int stack_top( stack_node *stack );
bool stack_empty( stack_node *stack );
stack_node *stack_push( stack_node *stack, int data );
int stack_pop( stack_node *stack );

void stack_print( stack_node *stack );
#endif
