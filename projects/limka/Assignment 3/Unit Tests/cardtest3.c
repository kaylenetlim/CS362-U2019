/****************************
 * CARD TEST 3
 * CS 362 - Assignment 3
 * Author: Kaylene Lim
 * File: cardtest3.c, endTurn
 * ***************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define SEED 100

int main(){

   struct gameState teststate;
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
   memset(&teststate, 'z', sizeof(struct gameState));

   int currentPlayer = 0;

   initializeGame(2, k, SEED, &teststate);

   int i = 0;
   int testret = endTurn(&teststate);

   printf("\n=== CARD TEST 3: endTurn ===\n");

   printf("\n>>> checking that function runs properly... ");

   if(testret != 0){
      printf("FAILED\n");
      assert(testret != 0);
   }else{
      printf("PASSED\n");
      assert(testret == 0);
   }

   printf("\n>>> checking that handcount is reset... ");

   if(teststate.handCount[currentPlayer] == 0){
      printf("PASSED\n");
   }else{
      printf("FAILED\n");
   }

   printf("\n=== END CARD TEST 3 ===\n\n");
   
   return 0;

}


