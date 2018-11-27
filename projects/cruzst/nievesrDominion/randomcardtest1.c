/*****************************
name: steven cruz
date: 11/11/2018
CS 362 - Assignment 4
******************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


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

  int passed = 0;
  int failed = 0;
  int flag;
 printf("====TESTING Village Internal(nievesR)====\n");
  int i;
  for (i = 0; i < 2000; i++){
    int numPlayers = (rand() % (4 - 2 + 1)) + 2;
    int randoSeed = (rand() % 1000) + 1;

    initializeGame(numPlayers, deck, randoSeed, &GAME);
    initializeGame(numPlayers, deck, randoSeed, &testGAME);
    int p;
    for (p = 0; p < numPlayers; p++){
      assert(GAME.handCount[GAME.whoseTurn] == testGAME.handCount[GAME.whoseTurn]);

      //printf("b4 actions: %d \n", testGAME.numActions);
      playVillage(&testGAME, 0);
      //printf("after actions: %d \n", testGAME.numActions);
      if (GAME.numActions + 2 == testGAME.numActions){                        // The numActions-- takes place after the card effect function
        flag = 1;
      }
      else{
        //printf("TEST FAILED. Something went Wrong.\n");
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
  printf("====END TEST====\n\n");
  return 0;
}
