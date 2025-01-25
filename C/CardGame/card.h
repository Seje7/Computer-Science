#ifndef _CARD_H_ // check if not defined
// define it
#define _CARD_H_
// define the maximum size of the card rank and suit
#define MAX 100

typedef struct cards { // define the cards struct
  char rank[MAX];
  char suit[MAX];
  int values1, values2;
} cards_t;


void Print_all_Cards(cards_t *store); // prints all the files

void Create_A_Card(char *card, struct cards *store); // creates a card

cards_t Compare_Cards(cards_t *store, cards_t *store2);
// compares two cards and returns the highest card

#endif