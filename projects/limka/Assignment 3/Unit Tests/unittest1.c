/***************************************************
 * Unit Test 1
 * CS 362 Assignment 3
 * Author: Kaylene Lim, limka
 * File: unittest1.c
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
   int numPlayers = 2;

   struct gameState teststate;
   
   int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

   memset(&teststate, 'z', sizeof(struct gameState));

   initializeGame(numPlayers, k, SEED, &teststate);

   int testrun = refactBaron(choice1, &teststate); // obtain the return value of the function

   printf("\n=== UNIT TEST 1: refactBaron ===\n");
   
   // Testing buys
   printf("\n>>> Testing for increased buys... ");
   
   if(teststate.numBuys > 2){
      printf("PASSED... increased buys\n");
   }else if(teststate.numBuys == 2){
      printf("FAILED... buys stayed the same\n");
   }else if(teststate.numBuys < 2){
      printf("FAILED... buys decreased instead\n");
   }

   // Testing coin increase
   printf("\n>>> Testing for coin increase... ");

   refactBaron(choice1, teststate);
   if(teststate.coins > 5){
      printf("PASSED... coins increased\n");
   }else{
      printf("FAILED... coins did not increase\n");
   }

   //Testing coin increases by 4 when estate card discarded
   printf("\n>>> Testing for coin increase by 4... ");

   int diff = teststate.coins - 5;

   if(diff == 4){
      printf("PASSED... coin increased by 4\n");
   }else{
      printf("FAILED... coin did not increase by 4\n");
   }

   // Ability to run
   printf("\n>>> Testing for ability to run function to completion... ");

   if(testrun == 0){
      printf("PASSED... program runs to completion\n");
   }else{
      printf("FAILED... error in running program\n");
   }  

   printf("\n=== END OF TESTING for refactBaron ===\n\n");
  
}



