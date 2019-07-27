/***************************************************
 * Unit Test 4
 * CS 362 Assignment 3
 * Author: Kaylene Lim, limka
 * File: unittest4.c
 * *************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SEED 100

int main(){

   // Initializes variables and initialize game
 
   int numPlayers = 2;

   struct gameState teststate;
   
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   memset(&teststate, 'z', sizeof(struct gameState));

   initializeGame(numPlayers, k, SEED, &teststate);

   int testrun = refactTribute(&teststate); // obtain the return value of the function

   // Begin testing
  printf("\n=== UNIT TEST 4: refactTribute ===\n");


   // Test if action points increased 
   printf("\n>>> Testing action points... ");
      
   teststate.numActions = 4;

   if(teststate.numActions > 4){
      printf("PASSED... action points are increased\n");
   }else{
      printf("FAILED... action points are not increased\n");
   }

   // Test if coins are increased
   printf("\n>>> Testing coin increased... ");

   teststate.coins = 4;

   if(teststate.coins > 4){
      printf("PASSED... coins are increased\n");
   }else{
      printf("FAILED... coins are not increased\n");
   }

   // Test if function runs properly
   printf("\n>>> Testing if function runs properly... ");

   if(testrun == 0){
      printf("PASSED... function runs properly\n");
   }else{
      printf("FAILED... error in running function\n");
   }

   // End testing
   printf("\n=== END OF TESTING for refactTribute ===\n\n"); 


   return 0;
}
