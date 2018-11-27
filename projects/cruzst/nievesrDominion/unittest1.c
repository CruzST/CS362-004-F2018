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
// This function takes in a player, a game, and a bonus.
// it will calculate the coins for the given player
// depending on the type of coin in hand

int updateCoins(int player, struct gameState *state, int bonus)
{
  int i;

  //reset coin count
  state->coins = 0;

  //add coins for each Treasure card in player's hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == copper)
	{
	  state->coins += 1;
	}
      else if (state->hand[player][i] == silver)
	{
	  state->coins += 2;
	}
      else if (state->hand[player][i] == gold)
	{
	  state->coins += 3;
	}
    }

  //add bonus
  state->coins += bonus;

  return 0;
}
*/

int main(){
  // Set up a game
  struct gameState GAME;

  GAME.coins = 0;
  GAME.numPlayers = 3;

  printf("\nUNIT TEST ONE: updateCoins\n");

  int i;
  for(i = 0; i < 2; i++){
    int j;
      for(j=0; j < 8; j++){
        GAME.hand[i][j] = copper;
        GAME.handCount[i]++;
      }
  }

  updateCoins(0, &GAME, 0);
  printf("Checking Player 1 coins. Should be 8 copper coins valued at 8 currency.\n");
  printf("Coin: %d\n", GAME.coins);
  if(GAME.coins == 8)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");

  printf("Checking Player 2 coins. Should be 8 copper coins valued at 8 currency.\n");
  printf("Coin: %d\n", GAME.coins);
  if(GAME.coins == 8)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");

  updateCoins(2, &GAME, 0);
  printf("Checking Player 3 coins. Should be 0 copper coins valued at 0 currency.\n");
  printf("Coin: %d\n", GAME.coins);
  if(GAME.coins == 0)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");


  printf("END UNIT TEST ONE\n\n");

  return 0;
}
// end main
