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
int playSmithy(struct gameState *state, int handPos){
	int currentPlayer = whoseTurn(state);
	int i;
	int size = 5;

	//+3 Cards
	for (i = 0; i < size; i++){
	drawCard(currentPlayer, state);
	}
	//discard card from hand
	discardCard(handPos, currentPlayer, state, 0);
	return 0;

}
*/


int main(){
  printf("====TESTING SMITHY nieves R=====\n");
  struct gameState GAME, testGAME;
  int deck[10] = {copper, minion, mine, silver, gold, curse, council_room, smithy, tribute, adventurer};

  initializeGame(2, deck, 888, &GAME);
  initializeGame(2, deck, 888, &testGAME);
  //memcpy(&testGAME, &GAME, sizeof(struct gameState));
  playSmithy(&testGAME, 0);

  printf("Testing handcount size\n");
  printf("Expected handCount: %d, smityInternal handCount: %d\n", GAME.handCount[GAME.whoseTurn]+2, testGAME.handCount[GAME.whoseTurn]);
  if (GAME.handCount[GAME.whoseTurn]+2 == testGAME.handCount[GAME.whoseTurn])
    printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");



  printf("====END TESTING SMITHY====\n\n");
  return 0;
}
