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
int numHandCards(struct gameState *state) {
  return state->handCount[ whoseTurn(state) ];
}
*/

int main(){
  // Set up a game
  struct gameState GAME;

  GAME.numPlayers = 4;
  GAME.whoseTurn = 0;       // << Start at player 1


  GAME.handCount[0] = 8;
  GAME.handCount[1] = 7;
  GAME.handCount[2] = 0;
  GAME.handCount[3] = 9;

  int handSize;

  printf("UNIT TEST FOUR: numHandCards\n");
  handSize = numHandCards(&GAME);
  printf("Player 1 has 8 cards: >> ");
  if (handSize == 8)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");

  GAME.whoseTurn++;
  handSize = numHandCards(&GAME);
  printf("Player 2 has 7 cards: >> ");
  if (handSize == 7)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");

  GAME.whoseTurn++;
  handSize = numHandCards(&GAME);
  printf("Player 3 has 0 cards: >> ");
  if (handSize == 0)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");

  GAME.whoseTurn++;
  handSize = numHandCards(&GAME);
  printf("Player 4 has 10 cards: (should fail)>> ");
  if (handSize == 10)
    printf("TEST PASSED\n\n");
  else
    printf("TEST FAILED\n\n");


  printf("END UNIT TEST FOUR\n\n");
  return 0;
}
// end main
