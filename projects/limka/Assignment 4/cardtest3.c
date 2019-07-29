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

   initializeGame(2, k, SEED, &teststate);

   int i = 0;
   int testret = endTurn(&teststate);

   printf("\n>>> TESTING: endTurn... ");

   printf("checking correct return value... ");

   if(testret != 0){
      printf("FAILED\n");
      assert(testret != 0);
   }else{
      printf("PASSED\n");
      assert(testret == 0);
   }

   return 0;

}


