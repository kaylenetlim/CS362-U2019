/*******************************
 * CARD TEST 5
 * CS 362 - Assignment 3
 * Author: Kaylene Lim
 * File: cardtest5.c, drawCard
 * ****************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define SEED 50

int main(){
   struct gameState teststate;
   int currentPlayer = 0;
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   memset(&teststate, 'z', sizeof(struct gameState));

   initializeGame(2, k, SEED, &teststate);

   int testret = drawCard(currentPlayer, &teststate);

   printf("\n=== CARD TEST 5: drawCard ===\n");

   printf("\n>>> checking if function runs properly... ");

   if(testret != 0){
      printf("FAILED\n");
      assert(testret != 0);
   }else{
      printf("PASSED\n");
      assert(testret == 0);
   }

   printf("\n=== END CARD TEST 5 ===\n\n");

   return 0;

}

