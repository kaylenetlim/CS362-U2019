/***************************************************
 * Unit Test 2
 * CS 362 Assignment 3
 * Author: Kaylene Lim, limka
 * File: unittest2.c
 * *************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define SEED 100

int main(){

   // Initializes variables and initialize game
 
   int choice1 = 0;
   int choice2 = 0;
   int handPos = 0;
   int numPlayers = 2;

   struct gameState teststate;
   
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   memset(&teststate, 'z', sizeof(struct gameState));

   initializeGame(numPlayers, k, SEED, &teststate);

   int testrun = refactMinion(choice1, choice2, &teststate, handPos); // obtain the return value of the function


   printf("\n=== UNIT TEST 2: refactMinion ===\n"); 
   
   // Test coin increase
   printf("\n>>> Testing if coin increases... ");

   teststate.coins = 4;
   choice1 = 1;

   if(teststate.coins > 4){
      printf("PASSED... coin amount increased\n");
   }else{
      printf("FAILED... coin amount did not increase\n");
   }

   // Test action increases
   printf("\n>>> Testing if action points are increased... ");

   teststate.numActions = 4;

   if(teststate.numActions > 4){
      printf("PASSED... action points increase\n");
   }else{
      printf("FAILED... action points did not increase\n");
   }

   // Test redraw when hand size > 4
   printf("\n>>> Testing if hand size is greater than 4... ");
   
   if(teststate.handCount[4] > 0){
	printf("FAILED... drawing when hand size other than greater than 4\n");
   }else{
	printf("PASSED... drawing when hand size is greater than 4\n");
   }
   
   // Test if function runs properly
   printf("\n>>> Testing if function runs... ");
   
   if(testrun == 0){
      printf("PASSED... function runs\n");
   }else{
      printf("FAILED... error in running function\n");
   }

   printf("\n=== END OF TESTING for refactMinion ===\n\n");

   return 0;
}
