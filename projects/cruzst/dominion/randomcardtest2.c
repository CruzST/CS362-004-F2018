/*****************************
name: steven cruz
date: 11/12/2018
CS 362 - Assignment 4
******************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*
int smithyInternal(struct gameState *state, int handPos){
  // +3 Cards
  int currentPlayer = whoseTurn(state);
  int i;
  for (i = 0; i < 3; i++){
    drawCard(currentPlayer, state);
  }

  // Discard card from hand
  discardCard(handPos, currentPlayer, state, 0);      // BUG Dont discard.
  return 0;
}
*/


int main(){
  printf("====TESTING SMITHY (contains a bug)=====\n");
  struct gameState GAME, testGAME;
  int deck[10] = {copper, minion, mine, silver, gold, curse, council_room, smithy, tribute, adventurer};
  int passed = 0;
  int failed = 0;
  int flag;

  int n;
  for (n = 0; n < 5000; n++){
    int numPlayers = (rand() % (4 - 2 + 1)) + 2;
    int randoSeed = (rand() % 1000) + 1;
    initializeGame(numPlayers, deck, randoSeed, &GAME);
    initializeGame(numPlayers, deck, randoSeed, &testGAME);

    int p;
    for (p = 0; p < numPlayers; p++){
      smithyInternal(&testGAME, 0);
      //printf("testgame: %d\n", testGAME.handCount[GAME.whoseTurn]);
      if (GAME.handCount[GAME.whoseTurn]+3 == testGAME.handCount[GAME.whoseTurn]){
        flag = 1;
      }
      else{
        flag = 0;
      }
      endTurn(&GAME);
      endTurn(&testGAME);
    }
    if (flag)
      passed++;
    else
      failed++;
  }


  printf("Tests passed: %d. Tests failed: %d\n", passed, failed);
  printf("====END TESTING SMITHY====\n\n");
  return 0;
}
