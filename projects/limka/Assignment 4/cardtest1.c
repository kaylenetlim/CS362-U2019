/*************************************
 * CARD TEST 1
 * CS 362 Assignment 3
 * Author: Kaylene Lim, limka
 * File: cardtest1.c, initializeGame
 *************************************/

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

   int testret = initializeGame(2, k, SEED, &teststate);

   printf("\n>>> TESTING: initializeGame... ");

   printf("checking correct return value... ");

   if(testret == -1){
      printf("FAILED\n");
      assert(testret == -1);
   }else{
      printf("PASSED\n");
      assert(testret == 0);
   }

   return 0;

}


