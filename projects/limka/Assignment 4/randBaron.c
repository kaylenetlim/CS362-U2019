/*************************
 * RANDOM TEST - BARON
 * CS 362 Assignment 4
 * Author: Kaylene Lim
 * File: randBaron.c
 * **********************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TEST 1000

int main(){

   double tottime;
   clock_t start, end;

   start = clock();

   struct gameState state, teststate;

   int handPos = 0;
   int choice1 = 0;
   int choice2 = 0;
   int choice3 = 0;
   int bonus = 0;
   int currentPlayer = 0;

   int card = 1;

   int discard = 1;

   int numBuys = 4;

   srand(time(NULL));

   printf("\n=== RANDOM TEST: refactBaron ===\n");


   for(int i = 0; i < MAX_TEST; i++){
      for(int n = 0; n < sizeof(struct gameState)/ sizeof(int); n++){
	 ((int*)&state) [n] = rand() % 128;
      }

      printf("\n|| TEST NUMBER %i ||\n", i+1);

      state.numPlayers = (rand() % 3) + 2;
      state.whoseTurn = rand() % state.numPlayers;
      currentPlayer = whoseTurn(&state);
      state.handCount[currentPlayer] = (rand() % (MAX_HAND/2)) + 1;
      state.deckCount[currentPlayer] = (rand() % (MAX_DECK/2)) + 1;
      state.discardCount[currentPlayer] = (rand() % (MAX_DECK/2)) + 1;
      state.numBuys = 0;
      handPos = (rand() % state.handCount[currentPlayer]);

      memcpy(&teststate, &state, sizeof(struct gameState));

      int r = cardEffect(baron, choice1, choice2, choice3, &teststate, handPos, &bonus);


      printf("\n>>> Testing that cardEffect works... ");
      
      if(r != 0){
	 printf("PASSED... cardEffect works correctly\n");
      }else{
	 printf("FAILED... there is an error in cardEffect\n");
      }

      printf("\n>>> Testing that number of cards is correct... ");

      if(teststate.handCount[currentPlayer] != state.handCount[currentPlayer]+card-discard){
	 printf("PASSED... correct number of cards in hand\n");
      }else{
	 printf("FAILED... wrong number of cards in hand\n");
      }

      printf("\n>>> Testing an increase in buys... ");
      if(teststate.numBuys != state.numBuys + numBuys){
	 printf("PASSED... buys increases correctly\n");
      }else{
	 printf("FAILED... buys did not increase correctly\n");
      }
   }

   printf("\n=== END OF TESTING: refactBaron ===\n");
   
   end = clock();
   tottime = ((double) (end-start))/CLOCKS_PER_SEC;
   printf("\nTesting time: %f seconds\n", tottime);

   return 0;

}
