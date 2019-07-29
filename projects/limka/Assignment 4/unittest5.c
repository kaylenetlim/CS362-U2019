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


int main(){


   struct gameState* teststate;
   int handPos;
   int choice1 = 0;
   int choice2 = 0;

   printf("\n--- UNIT TEST 5: refactMine ---\n");


   // Test if treasure_map will return correctly
   puts("\n>>> Testing correct return when given choice2 value... "); 

   if(refactMine(choice1, treasure_map, teststate, handPos) != -1){
      puts("PASSED... correct return value\n");
   }else{
      puts("FAILED... incorrect return value\n");
   }

   printf("\n--- END TESTING for refactMINE ---\n");

   // Test player gained card
   // Test return when hand is silver
   
   return 0;

}
