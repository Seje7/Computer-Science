// This code is not fully commplete
// The functions done so far are the card_create, card_print
// the push, stack_print and stack_find_max
// , stack_create, stack_push, stack_pop, stack_peek
// NO incomplete functions 
// chars rank and suit the output is the rank and suit of the card in strings,
// the highest card in the stack is printed These depend on the function you


#include "stack.h"  // include the header file
#include <stdio.h>  // include the standard input/output library
#include <stdlib.h> // include the standard library
#include <string.h> // include the string library
#include "memwatch.h" 

// define the push command
#define PUSH		's'  
// define the pop command
#define POP			'p'
// define the peek command
#define PEEK		'k'
// define the print command
#define FIND_MAX	'f'
// define the print command
#define PRINT		't' 
// define the print command
#define QUIT		'q'


// define the maximum size of the input
#define MAX_SIZE 2
// define the maximum size of the card, This is just a random number for now
#define MAX 100

int main(void) {

  cards_t current_max_card, current_big_card, peek_card, result; // cards 
  cards_t store; // allocate memory for the store
  
  stack_t my_stack = stack_create();      // create an empty stack
  stack_t max_stack = stack_create();     // create an empty stack

  char card[MAX_SIZE];       // create a character array to store the input
  char command; // initialize the count and command to 0

  while (1) { // loop continously
    
    // print the menu
    printf("Command: \ns: push, \np: pop, \nk: peek, \nf: find max, \nt: print, \nq: quit\n"); // prompt the user to enter a command
    printf("Enter an command: ");
    scanf(" %c", &command);        // read the command from the user
    getchar();        //get rid of the \n character

    switch (command) {                          // switch to select command
    case PUSH:                                    // if the command is 1
      printf("Enter a card You want to Create: ");
      scanf("%s", card);
      printf("\n");
      Create_A_Card(card, &store); // call the Create_A_Card function
      push(&my_stack, store); // push the card onto the stack

     if (max_stack == NULL) { // assign values if the max stack is empty
        current_max_card.values1 = 0;
        current_max_card.values2 = 0;
        strcpy(current_max_card.rank, "NULL");
        strcpy(current_max_card.suit, "NULL");
      } else {
        current_max_card = peek(&max_stack);
      }
     current_big_card = Compare_Cards(&store, &current_max_card); // compare the created card with the current max card
       push(&max_stack, current_big_card);  // push the card onto the max_stack
      break;
      
    case PRINT: // if the command is 2
      stack_print(&my_stack); // print the contents of the stack
      break;
      
    case POP:
      result = pop(&my_stack); // pop the top card from the stack
      printf("The popped is : %s of %s\n\n", result.rank, result.suit); // print the popped card
      pop(&max_stack);
      break;
      
    case PEEK:                // if the command is 3
      peek_card = peek(&my_stack); // peek the top card from the stack
      printf("The top card is : %s of %s\n\n", peek_card.rank, peek_card.suit); // print the top card
      break;
      
    case FIND_MAX:
      current_max_card = Stack_Find_Max(&max_stack);
      printf("The highest card is : %s of %s\n\n", current_max_card.rank, current_max_card.suit); // print the highest card
      break;
      
    case QUIT: // if the command is 4
      Stack_Free(&my_stack); // free stack
      Stack_Free(&max_stack); // free stack with max value
      printf("Exiting the program.\n"); // print a message to indicate that the program is exiting
      exit(0);                          // exit the program
      
    default: // if the command is not 1, 2,3 or 4
      printf("Invalid command. Please try again.\n"); // print an error message
    }
  }

  return 0;
}
