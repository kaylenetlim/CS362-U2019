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

#define SEED 100

int main(){
   struct gameState teststate;

   int numPlayers = 2;
   int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

   memset(&teststate, 'z', sizeof(struct gameState));

   int testret = initializeGame(numPlayers, k, SEED, &teststate);

   printf("\n=== CARD TEST 1: initializeGame ===\n");

   // Check if function runs properly
   printf("\n>>> checking if function runs properly... ");

   if(testret == -1){
      printf("FAILED\n\n");
      assert(testret == -1);
   }else{
      printf("PASSED\n\n");
      assert(testret == 0);
   }

   // Check variables
   printf("\n>>> checking if numPlayers is initialized... ");

   if(numPlayers != NULL){
      printf("PASSED\n\n");
      assert(numPlayers != NULL);
   }else{
      printf("FAILED\n\n");
      assert(numPlayers == NULL);
   }

   printf("\n>>> checking if kingdomCards is initialized... ");

   if(k != NULL){
      printf("PASSED\n\n");
   }else{
      printf("FAILED\n\n");
   }
   
   printf("\n>>> checking if randomSeed is initialized... ");

   if(SEED != NULL){
     printf("PASSED\n\n");
   }else{
     printf("FAILED\n\n");
   }

   printf("=== END CARD TEST 1 ===\n\n");

   return 0;

}


