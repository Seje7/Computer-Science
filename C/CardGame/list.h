#ifndef _LIST_H_
#define _LIST_H_
#include "card.h" // include the header file

// include card.h here

typedef struct node_s {
  cards_t card;
  struct node_s *next;
} node_t;

typedef node_t *list_t;

list_t list_create();

cards_t list_push(list_t *this_list, cards_t card);

void list_print(list_t *this_list);

cards_t list_pop(list_t *this_list);

#endif