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


int main(){

   int choice1 = 0;
   struct gameState* teststate;

   printf("\n--- UNIT TEST 1: refactBaron ---\n");

   teststate->coins = 5;
   teststate->numBuys = 2;

   // Ability to run
   printf("\n>>> Testing for ability to run function... ");

   if(refactBaron(choice1, teststate) == 0){
      printf("program runs\n");
   }else{
      printf("error in running program\n");
   } 

   // Testing buys
   printf("\n>>> Testing for increased buys... ");
   
   refactBaron(choice1, teststate);
   if(teststate->numBuys > 2){
      printf("PASSED... increased buys\n");
   }else if(teststate->numBuys == 2){
      printf("FAILED... buys stayed the same\n");
   }else if(teststate->numBuys < 2){
      printf("FAILED... buys decreased instead\n");
   }

   // Testing coin increase
   printf("\n>>> Testing for coin increase... ");

   refactBaron(choice1, teststate);
   if(teststate->coins > 5){
      printf("PASSED... coins increased\n");
   }else{
      printf("FAILED... coins did not increase\n");
   }

   //Testing coin increases by 4 when estate card discarded
   printf("\n>>> Testing for coin increase by 4... ");

   int diff;
   diff = teststate->coins - 5;

   if(diff == 4){
      printf("PASSED... coin increased by 4\n");
   }else{
      printf("FAILED... coin did not increase by 4\n");
   }

   printf("\n--- END OF TESTING for refactBaron ---\n");

   //return 0;  
}



