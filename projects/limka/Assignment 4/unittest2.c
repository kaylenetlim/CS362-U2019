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

int main(){

   int choice1 = 0;
   int choice2 = 0;
   struct gameState* teststate;
   int handPos = 0;

   printf("\n--- UNIT TEST 2: refactMinion ---\n"); 
   
   
   // Test coin increase
   printf("\n>>> Testing if coin increases... ");

   teststate->coins = 4;

   refactMinion(1, choice2, *teststate, handPos);

   if(teststate->coins > 4){
      printf("PASSED... coin amount increased\n");
   }else{
      printf("FAILED... coin amount did not increase\n");
   }

   // Test action increases
   printf("/n>>> Testing if action points are increased... ");

   teststate->numActions = 4;

   refactMinion(1, choice2, *teststate, handPos);

   if(teststate->numActions > 4){
      printf("PASSED... action points increase\n");
   }else{
      printf("FAILED... action points did not increase\n");
   }

   // Test redraw when hand size > 4
   printf("\n>>> Testing if hand size is greater than 4... ");
   
   refactMinion(1, 0, *teststate, handPos);

   if(teststate->handCount[4] > 0){
	printf("FAILED... drawing when hand size other than greater than 4\n");
   }else{
	printf("PASSED... drawing when hand size is greater than 4\n");
   }
      
   return 0;
}
