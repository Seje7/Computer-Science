#include "stack.h" // include the header file
#include <stdio.h>  // include the standard input/output library
#include <stdlib.h> // include the standard library
#include <string.h> // include the string library
#include "memwatch.h"

stack_t stack_create() { // create an empty stack
  return (stack_t)list_create();
}

cards_t push(stack_t *this_stack, cards_t card) { // push a card onto the stack
  return list_push(this_stack, card);
}

cards_t pop(stack_t *this_stack) { return list_pop(this_stack); }

void stack_print(stack_t *this_stack) { // print the contents of the stack
  list_print(this_stack);
}

cards_t peek(stack_t *this_stack) {
  return (*this_stack)->card;
}

cards_t Stack_Find_Max(stack_t *this_stack) { // find the maximum value in the stac

  return peek(this_stack);
}

void Stack_Free(stack_t *this_stack) {
  node_t *curr = *this_stack; // create a pointer to the current node
  while (*this_stack != NULL) { // loop continously

    *this_stack = (*this_stack)->next; // move to the next node
    free(curr); // free the memory allocated for the current node

    curr = *this_stack; // update the current node

  }
}