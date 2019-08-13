/***************************
 * CS 362 Extra Credit
 * Author: Kaylene Lim
 * Filename: ecunittest1.c
 * *************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define SEED 100
#define TYPE tribute

// UNIT TEST FOR TRIBUTE FUNCTION, EXTRA CREDIT BUG 1

int main(){

   // Initialize game

   int choice1 = 0;
   int choice2 = 0;
   int choice3 = 0;
   int handPos = 0;
   int bonus = 0;
   int currentPlayer = 0;
   int numPlayers = 2;

   struct gameState test, state;

   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   initializeGame(numPlayers, k, SEED, &test);
   
   //memset(&test, 'z', sizeof(struct gameState));
   
   int rettest = cardEffect(TYPE, choice1, choice2, choice3, &test, handPos, &bonus);

   printf("\n=== UNIT TEST FOR TRIBUTE ===\n");

   printf("\n>>> Test if function runs... ");

   if(rettest == 0){
      printf("PASS\n");
   }else{
      printf("FAIL\n");
   }

   printf("\n>>> Test if no cards to reveal works... ");

   currentPlayer = whoseTurn(&test);

   test.deckCount[currentPlayer + 1] = 0;
   test.discardCount[currentPlayer + 1] = 0;

   memcpy(&state, &test, sizeof(struct gameState));

   if(test.discardCount[currentPlayer + 1] == 0){
      printf("PASS\n");
   }else{
      printf("FAIL\n");
   }


   printf("\n=== DONE ===\n");


   return 0;
}



