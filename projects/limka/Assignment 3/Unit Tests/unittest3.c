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
#include <assert.h>

int main(){

   int choice1 = 0;
   int choice2 = 0;
   struct gameState* teststate;
   int handPos;

   printf("\n--- UNIT TEST 3: refactAmbassador ---\n");

   // Test if 0 < choice2 < 2 returns -1
   printf("\n>>> Testing if correct return value for choice 2... ");

   if(refactAmbassador(choice1, 0, teststate, handPos) == -1){
     printf("PASSED... correct return value\n");
   }else{
     printf("FAILED... incorrect return value\n");
   }

   if(refactAmbassador(choice1, 2, teststate, handPos) == -1){
     printf("PASSED... correct return value\n");
   }else{
     printf("FAILED... incorrect return value\n");
   }

   // Test if choice1 is equal to handPos
   printf("\n>>> Testing if correct return value when choice 1 = handPos... ");

   handPos = 0;

   if(refactAmbassador(choice1, choice2, teststate, handPos) == -1){
      printf("PASSED... correct return value\n");
   }else{
      printf("FAILED... incorrect return value\n");
   }

   //Test if card was discarded from hand
   printf("\n>>> Testing if card was discarded from hand... ");

   teststate->handCount[4] = 4;
   refactAmbassador(choice1, choice2, teststate, handPos);
   if(teststate->handCount[4] < 4){
      printf("PASSED... discarded cards\n");
   }else{
      printf("FAILED... did not discard cards\n");
   }

   printf("\n--- END OF TESTING for refactAmbassador ---\n");

   return 0;
}
