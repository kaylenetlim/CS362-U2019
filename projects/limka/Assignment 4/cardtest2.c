/******************************
 * CARD TEST 2
 * CS 362 - Assignment 3
 * Author: Kaylene Lim
 * File: cardtest2.c, shuffle
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
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
   int currentPlayer = 0;

   memset(&teststate, 'z', sizeof(struct gameState));

   initializeGame(2, k, SEED, &teststate);

   int testret = shuffle(currentPlayer, &teststate);


   printf("\n>>> TESTING: shuffle... ");

   printf("checking correct return value... ");

   if(testret == -1){
      printf("FAILED\n");
      assert(testret == -1); // this return value indicates function did not reach completion
   }else{
      printf("PASSED\n");
      assert(testret == 0);
   }

   return 0;

}


