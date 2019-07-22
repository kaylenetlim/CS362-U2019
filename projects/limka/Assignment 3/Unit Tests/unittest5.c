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
#include <assert.h>

int main(){

   int choice1 = 0;
   int choice2 = 0;
   struct gameState* state;
   int handPos;

   printf("\n--- UNIT TEST 5: refactMine ---\n");

   // Test if treasure_map will return correctly
   printf("\n>>> Testing correct return when given choice2 value... ");

   choice2 = treasure_map;
   if(refactMine(state) != -1){
      printf("PASSED... correct return value\n");
   }else{
      printf("FAILED... incorrect return value\n");
   }

   // Test player gained card
   // Test return when hand is silver

}
