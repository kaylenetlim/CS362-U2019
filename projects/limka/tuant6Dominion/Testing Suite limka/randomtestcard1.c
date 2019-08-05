/****************************
 * RANDOM TEST 1 - BARON
 * CS 362 Assignment 4
 * Author: Kaylene Lim
 * File: randomtestcard1.c
 * *************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TEST 1000
#define CARD_NAME "Baron"

int main(){

   // Set up clock to time test
   double tottime;
   clock_t start, end;

   start = clock(); // Start timer

   srand(time(NULL));

   // Initialize dominion game variables
   int handPos = 0;
   int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
   int currentPlayer = 0;

   int card = 1, discard = 1, buys = 4;

   struct gameState teststate, state;

   // Begin random test for refactBaron
   printf("\n=== RANDOM TEST: %s ===\n", CARD_NAME);

   int pass = 0, fail = 0;

   for(int i = 0; i < MAX_TEST; i++){
      for(int j = 0; j < sizeof(struct gameState)/ sizeof(int); j++){
	 ((int*)&state) [j] = rand() % 128;
      }

      printf("\n|| TEST NUMBER %i ||\n", i+1);

      choice1 = (rand() % 2) + 0; // Randomize choice1 value

      // 'Manually' run refactBaron on state
      currentPlayer = whoseTurn(&state);
      
      state.numPlayers = (rand() % 3) + 2;
      state.coins = 0;
      state.supplyCount[estate] = (rand() % 7) + 0;
      state.whoseTurn = rand() % state.numPlayers;
      state.handCount[currentPlayer] = (rand() % (MAX_HAND/2)) + 1;
      state.deckCount[currentPlayer] = (rand() % (MAX_DECK/2)) + 1;
      state.discardCount[currentPlayer] = (rand() % (MAX_DECK/2)) + 1;
      state.numBuys = 0;
      handPos = (rand() % state.handCount[currentPlayer]);

      // Copy manual state to the teststate struct before running tests
      memcpy(&teststate, &state, sizeof(struct gameState));

      // Test if program works properly
      printf("\n>>> Testing program... ");

      int testret = cardEffect(baron, choice1, choice2, choice3, &teststate, handPos, &bonus); // Create variable to hold return value from cardEffect

      if(testret == 0){
	 printf("PASSED... program works correctly\n");
	 pass++;
      }else{
	 printf("FAILED... error in running program\n");
	 fail++;
      }

      // Test number of cards in hand
      printf("\n>>> Testing card number in hand... ");

      if(teststate.handCount[currentPlayer] == state.handCount[currentPlayer]+card-discard){
	 printf("PASSED... correct number of cards in hand\n");
	 pass++;
      }else{
	 printf("FAILED... wrong number of cards in hand\n");
	 fail++;
      }

      // Test supply count of estates
      printf("\n>>> Testing estate supply count... ");

      if(teststate.supplyCount[estate] == (state.supplyCount[estate] - 1)){
	 printf("PASSED... supply of estate correctly decreased\n");
	 pass++;
      }else{
	 printf("FAILED... supply of estate did not correctly decrease\n");
	 fail++;
      }
 
      // Test number of buys
      printf("\n>>> Testing if number of buys increase... ");

      if(teststate.numBuys == state.numBuys + buys){
	 printf("PASSED... number of buys increases correctly\n");
	 pass++;
      }else{
	 printf("FAILED... error in increasing buys\n");
	 fail++;
      }

   }

   printf("\n=== END OF TESTING: %s ===\n", CARD_NAME);

   end = clock(); // End timer
   tottime = ((double) (end-start))/CLOCKS_PER_SEC;
   printf("\n--> Testing time: %f sec", tottime);
   printf("\n--> Passed: %i/4000 ", pass);
   printf("\n--> Failed: %i/4000 \n\n", fail);

   return 0;
}

   


