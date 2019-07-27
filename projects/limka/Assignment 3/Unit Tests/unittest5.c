/***************************************************
 * Unit Test 5
 * CS 362 Assignment 3
 * Author: Kaylene Lim, limka
 * File: unittest5.c
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
   int handPos = 0;
   int player = 0;
   int numPlayers = 2;
   int currentPlayer = 0;

   struct gameState teststate;
   
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   memset(&teststate, 'z', sizeof(struct gameState));

   initializeGame(numPlayers, k, SEED, &teststate);

   int testrun = refactMine(choice1, choice2, &teststate, handPos); // obtain the return value of the function

   // Begin testing
   printf("\n=== UNIT TEST 5: refactMine ===\n");


   // Test if treasure_map will return correctly
   choice2 = treasure_map;
   
   puts("\n>>> Testing correct return when given choice2 value... ");  

   if(testrun != -1){
       puts("FAILED... incorrect return value\n");
   }else{
       puts("PASSED... correct return value\n");        
   }

   // Test if hand equals silver 
   printf("\n>>> Testing correct return value based on hand value.. ");

   teststate.hand[currentPlayer][choice1] = silver;

   if(testrun == -1){
      printf("PASSED... correct return value\n");
   }else{
      printf("FAILED... incorrect return value\n");
   }

   // Test if function runs properly
   printf("\n>>> Testing if the function runs properly... ");

   choice2 = 0;
   teststate.hand[currentPlayer][choice1] = copper;

   if(testrun == 0){
      printf("PASSED... function runs properly\n");
   }else{
      printf("FAILED... error in running function\n");
   }

   printf("\n=== END TESTING for refactMINE ===\n\n");

   
   return 0;

}
