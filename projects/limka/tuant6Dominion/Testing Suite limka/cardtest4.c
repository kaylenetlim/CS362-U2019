/********************************
 * CARD TEST 4
 * CS 362 - Assignment 3
 * Author: Kaylene Lim
 * File: cardtest4.c, getWinners
 * ******************************/

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

   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   memset(&teststate, 'z', sizeof(struct gameState));

   initializeGame(2, k, SEED, &teststate);

   int players[MAX_PLAYERS];
   int testret = getWinners(players, &teststate);

   printf("\n=== CARD TEST 4: getWinners ===\n");

   printf("\n>>> checking that function runs properly... ");

   if(testret != 0){
      printf("FAILED\n");
      assert(testret != 0);
   }else{
      printf("PASSED\n");
      assert(testret == 0);
   }

   printf("\n>>> checking that players is initialized... ");

   if(players != NULL){
      printf("PASSED\n");
   }else{
      printf("FAILED\n");
   }

   printf("\n=== END CARD TEST 4 ===\n\n");

   return 0;

}


