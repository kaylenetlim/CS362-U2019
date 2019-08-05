/***************************
 * RANDOM TEST 2 - MINION
 * CS 362 Assignment 4
 * Author: Kaylene Lim
 * File: randomtestcard2.c
 * ************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SEED 1000
#define MAX_TEST 5
#define CARD_NAME "Minion"

int main(){

   // Set up clock to time test
   double tottime;
   clock_t start, end;

   start = clock(); // Start timer

   srand(time(NULL));

   // Initialize dominion game variables
   int handPos = 0;
   int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
   int players = 0;
   int currentPlayer = 0;

   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, ambassador};

   struct gameState state, teststate;

   // Begin random test for refactMinion
   printf("\n=== RANDOM TEST: %s ===\n", CARD_NAME);

   int pass = 0, fail = 0;
   int tottest = MAX_TEST * 3; // Max total number of possible outcomes

   for(int i = 0; i < MAX_TEST; i++){
      
      printf("\n|| TEST NUMBER %i ||\n", i+1);

      choice1 = (rand() % 5) + 0; // Randomize choices
      choice2 = (rand() % 5) + 0;
      players = (rand() % 3) + 2; // 2-4 players

      int testret = cardEffect(minion, choice1, choice2, choice3, &teststate, handPos, &bonus); // Holds return value of cardEffect

      // Initialize dominion game
      initializeGame(players, k, 1000, &state); 

      // 'Manually' run refactMinion on state
      currentPlayer = rand() % players;
      state.whoseTurn = currentPlayer;
      state.deckCount[currentPlayer] = (rand() % MAX_DECK);
      state.discardCount[currentPlayer] = (rand() % MAX_DECK);
      state.handCount[currentPlayer] = (rand() % MAX_HAND);
      state.hand[currentPlayer][0] = minion;
      state.numActions = (rand() % 10);

      // Copy manual state to teststate struct
      memcpy(&teststate, &state, sizeof(struct gameState));

      // Test if program runs
      printf("\n>>> Testing program... ");

      if(testret == 0){
	 printf("PASSED... program runs\n");
	 pass++;
      }else{
	 printf("FAILED... error in running program\n");
	 fail++;
      }

      // Test if player cardDeck decreases
      printf("\n>>> Testing that cardDeck decreases...");

      if(state.deckCount[currentPlayer] == (teststate.deckCount[currentPlayer] - 1)){
	printf("PASSED... cardDeck decreases correctly\n");
	pass++;
      }else{
 	printf("FAILED... cardDeck does not decrease correctly\n");
	fail++;
      }	

      // Test if action points increased
      printf("\n>>> Testing action points... ");

      if(state.numActions == (teststate.numActions + 1)){
	 printf("PASSED... action points increase by 1\n");
	 pass++;
      }else{
	 printf("FAILED... action points did not increase by 1\n");
	 fail++;
      }
   }

   printf("\n=== END OF TESTING: %s ===\n", CARD_NAME);

   end = clock(); // End timer
   tottime = ((double) (end-start))/CLOCKS_PER_SEC;
   printf("\n--> Testing time: %f sec", tottime);
   printf("\n--> Passed: %i/%i", pass, tottest);
   printf("\n--> Failed: %i/%i\n\n", fail, tottest);

   return 0;

 }

