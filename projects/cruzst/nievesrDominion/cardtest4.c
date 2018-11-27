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
int playVillage(struct gameState *state,int handPos){
	int currentPlayer = whoseTurn(state);

	//+1 Card
	drawCard(currentPlayer, state);
	//+3 Actions
	state->numActions = state->numActions + 3;
	//discard played card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}
*/


int main(){
  struct gameState GAME, testGAME;
  int deck[10] = {copper, minion, mine, silver, gold, curse, council_room, smithy, tribute, adventurer};

  printf("====TESTING VILLAGEINTERNAL nievesR ====\n");
  initializeGame(4, deck, 888, &GAME);
  initializeGame(4, deck, 888, &testGAME);

  playVillage(&testGAME, 0);

  printf("Checking handcount\n");
  printf("Expected handCount: %d, villageInternal handcount: %d\n", GAME.handCount[GAME.whoseTurn], testGAME.handCount[GAME.whoseTurn]);
  if(GAME.handCount[GAME.whoseTurn] == testGAME.handCount[GAME.whoseTurn])
    printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

  printf("Checking numActions\n");
  printf("Expected actions: %d, villageInternal actions: %d\n", GAME.numActions + 1, testGAME.numActions);
  if(GAME.numActions + 1 == testGAME.numActions)
    printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

  printf("====END TEST====\n\n");
  return 0;
}
