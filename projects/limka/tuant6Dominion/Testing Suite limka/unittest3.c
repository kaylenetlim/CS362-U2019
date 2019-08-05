/***************************************************
 * Unit Test 3
 * CS 362 Assignment 3
 * Author: Kaylene Lim, limka
 * File: unittest3.c
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
 
   int choice1 = 0;
   int choice2 = 0;
   int choice3 = 0;
   int handPos = 0;
   int bonus = 0;
   int player = 0;
   int numPlayers = 2;

   struct gameState teststate;
   
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   memset(&teststate, 'z', sizeof(struct gameState));

   initializeGame(numPlayers, k, SEED, &teststate);

   int testrun = cardEffect(ambassador, choice1, choice2, choice3, &teststate, handPos, &bonus); // obtain the return value of the function


   // Begin testing
   printf("\n=== UNIT TEST 3: Ambassador ===\n");


   // Test if 0 < choice2 < 2 returns -1
   printf("\n>>> Testing if correct return value for choice 2... ");

   if(testrun == -1){
     printf("PASSED... correct return value\n");
   }else{
     printf("FAILED... incorrect return value\n");
   }

   // Test if choice1 is equal to handPos
   printf("\n>>> Testing if correct return value when choice 1 = handPos... ");

   if(testrun == -1){
      printf("PASSED... correct return value\n");
   }else{
      printf("FAILED... incorrect return value\n");
   }

   // Test if card was discarded from hand
   printf("\n>>> Testing if card was discarded from hand... ");

   teststate.handCount[4] = 4;
   
   if(teststate.handCount[4] < 4){
      printf("PASSED... discarded cards\n");
   }else{
      printf("FAILED... did not discard cards\n");
   }

   printf("\n=== END OF TESTING for Ambassador ===\n\n");

   return 0;
}
