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
int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}
*/

int main(){
  // Set up a game
  struct gameState GAME;


  GAME.numPlayers = 4;
  GAME.whoseTurn = 0;         // Player 1 turn


  int player;

  printf("UNIT TEST TWO: whoseTurn\n");
  player = whoseTurn(&GAME);
  printf("It is player 1's turn: >> ");
  if (player == 0)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");


  GAME.whoseTurn++;
  player = whoseTurn(&GAME);
  printf("It is player 2's turn: >> ");
  if (player == 1)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");


  GAME.whoseTurn++;
  player = whoseTurn(&GAME);
  printf("It is player 3's turn: >> ");
  if (player == 2)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");

  GAME.whoseTurn++;
  player = whoseTurn(&GAME);
  printf("It is player 4's turn: >> ");
  if (player == 3)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");

  GAME.whoseTurn++;
  player = whoseTurn(&GAME);
  printf("It is player 5's turn (should fail): >> ");
  if (player == 1)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");

  printf("END UNIT TEST TWO\n\n");
  return 0;
}
// end main
