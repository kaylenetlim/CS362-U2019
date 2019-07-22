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
#include <assert.h>

int main(){

   struct gameState* teststate;

   printf("\n--- UNIT TEST 4: refactTribute ---\n");

   // Test if action points increased
   printf("\n>>> Testing action points... ");

   teststate->numActions = 4;
   refactTribute(teststate);
   if(teststate->numActions > 4){
      printf("PASSED... action points are increased\n");
   }else{
      printf("FAILED... action points are not increased\n");
   }

   // Test if coins are increased
   printf("\n>>> Testing coin increased... ");

   teststate->coins = 4;
   if(teststate->coins > 4){
      printf("PASSED... coins are increased\n");
   }else{
      printf("FAILED... coins are not increased\n");
   }

   // Verify current player
   // Test if cards are revealed
   // Test if card properly discarded
   // Test if deck count is correct

   return 0;
}
