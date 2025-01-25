#include "list.h"
#include <stdio.h>
#include <stdlib.h>
//#include "memwatch.h"

// create a list
list_t list_create() { return NULL; }

cards_t list_push(list_t *this_list, cards_t card) { // push a card onto the stack

  // push a card onto the stack
  node_t *new_node =
      (node_t *)malloc(sizeof(node_t)); // allocate memory for a new node

  new_node->card = card;       // copy the card data into the new node
  new_node->next = *this_list; // set the next pointer of the new node to the
                               // current top of the stack

  *this_list = new_node; // update the top of the stack to point to the new node

  return (*this_list)->card; // return the value of the card
}

void list_print(list_t *this_list) { // print the list
  node_t *curr = *this_list; // create a pointer to the current node
  while (1) {           // loop continously
    if (curr == NULL) { // if the current node is NULL
      break;            // break out of the loop
    }
    Print_all_Cards(&curr->card); // print the card
    curr = curr->next;       // move to the next node
  }
}

cards_t list_pop(list_t *this_list) { // pop a card from the stack
  if (*this_list == NULL) { // if the stack is empty
    perror("THIS LIST IS EMPTY");  // return -1
  }
  node_t *top = *this_list; // create a pointer to the top of the stack
  cards_t popped_Card =  top->card; // copy the card data from the top of the stack
  *this_list = (*this_list)->next; // update the top of the stack to point to the next node

  free(top); // free the memory allocated for the top node

  return popped_Card; // return the value of the card
}
