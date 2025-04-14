#include "card.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "memwatch.h"

#define MAX_SIZE 2
#define MAX 100

void Print_all_Cards(cards_t *store) { // prints all the files
  printf("The Card is: %s of %s\n\n", store->rank,
         store->suit); // prints the file name
}

void Create_A_Card(char *card, cards_t *store) { // creates a card
  switch (card[0]) {                             // switch to select rank
  case 'A':
    store->values1 = 13;
    strcpy(store->rank, "Ace");
    break;
  case 'K':
    store->values1 = 12;
    strcpy(store->rank, "King");
    break;
  case 'Q':
    store[0].values1 = 11;
    strcpy(store->rank, "Queen");
    break;
  case 'J':
    store->values1 = 10;
    strcpy(store->rank, "Jack");
    break;
  case 'T':
    store->values1 = 9;
    strcpy(store->rank, "Ten");
    break;
  case '9':
    store->values1 = 8;
    strcpy(store->rank, "Nine");
    break;
  case '8':
    store->values1 = 7;
    strcpy(store->rank, "Eight");
    break;
  case '7':
    store->values1 = 6;
    strcpy(store->rank, "Seven");
    break;
  case '6':
    store->values1 = 5;
    strcpy(store->rank, "Six");
    break;
  case '5':
    store->values1 = 4;
    strcpy(store->rank, "Five");
    break;
  case '4':
    store->values1 = 3;
    strcpy(store->rank, "Four");
    break;
  case '3':
    store->values1 = 2;
    strcpy(store->rank, "Three");
    break;
  case '2':
    store->values1 = 1;
    strcpy(store->rank, "Two");
    break;
  default:
    printf("Invalid Card");
  }

  switch (card[1]) { // switch to select suit
  case 'S':
    store->values2 = 4; // spades
    strcpy(store->suit, "Spades");
    break;
  case 'H':
    store->values2 = 3; // hearts
    strcpy(store->suit, "Hearts");
    break;
  case 'D': // diamonds
    store->values2 = 2;
    strcpy(store->suit, "Diamonds");
    break;
  case 'C': // clubs
    store->values2 = 1;
    strcpy(store->suit, "Clubs");
    break;
  default: // if the input is not valid
    printf("Invalid Card");
  }
}

cards_t Compare_Cards(cards_t *store, cards_t *store2) { // compares two cards and returns the highest card
  if (store->values1 ==
      store2->values1) { // if the values of the cards are equal
    if (store->values2 >
        store2->values2) { // if the suit of the cards are equal
      return *store;       // return the first card
    } else {               // if the values of the cards are not equal
      return *store2;      // return the second card
    }
  }

  if (store->values1 >
      store2->values1) { // if the values of the cards are not equal
    return *store;       // return the first card
  }
  return *store2; // return the second card
}