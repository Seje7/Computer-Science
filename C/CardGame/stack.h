#ifndef _STACK_H_ // check if not defined
// define it
#define _STACK_H_
#include "list.h"  // include the header file
#include <stdio.h> // include the standard input/output library

typedef node_t *stack_t; // define the stack type

stack_t stack_create(); // create an empty stack

cards_t push(stack_t *this_stack, cards_t card); // push a card onto the stack

void stack_print(stack_t *this_stack); // print the contents of the stack

cards_t pop(stack_t *this_stack);

cards_t peek(stack_t *this_stack); // print the last content of the stack

cards_t Stack_Find_Max(stack_t *this_stack); // find the maximum value in the stack

void Stack_Free(stack_t *this_stack);

#endif