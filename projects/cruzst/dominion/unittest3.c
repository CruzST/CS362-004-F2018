/*****************************
name: steven cruz
date: 10/26/2018
CS 362 - Assignment 3
******************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
// This function takes in a state and
// determines if the game is over

int isGameOver(struct gameState *state) {
  int i;
  int j;

  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}
*/

int main(){
  // Set up a game
  struct gameState GAME;

  printf("UNIT TEST THREE: isGameOver\n");
  GAME.supplyCount[province] = 0;
  printf("Game is over due to Province cards stack empty: >> ");
  if (isGameOver(&GAME))
    printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");


  GAME.supplyCount[province] = 8;
  int i;
  for (i = 0; i < 25; i++){
    GAME.supplyCount[i] = 10;
  }
  printf("Game is NOT over: >> ");
  if (isGameOver(&GAME))
    printf("TEST FAILED\n");
  else
    printf("TEST PASSED\n");

  GAME.supplyCount[0] = 0;
  GAME.supplyCount[1] = 0;
  GAME.supplyCount[2] = 0;
  printf("Game is over due to 3 card stacks empty: >> ");
  if (isGameOver(&GAME))
    printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

  printf("END UNIT TEST THREE\n\n");
  return 0;
}
// end main
