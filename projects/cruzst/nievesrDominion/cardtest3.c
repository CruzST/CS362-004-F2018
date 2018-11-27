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
int playcouncil_room(struct gameState *state, int handPos){
	//+4 Cards
	int i;
	int currentPlayer = whoseTurn(state);
	for (i = 0; i < 5; i++){
		drawCard(currentPlayer, state);
	}

	//+1 Buy
	state->numBuys++;

	//Each other player draws a card
	for (i = 0; i < state->numPlayers; i++){
		if ( i != currentPlayer ){
			drawCard(i, state);
			drawCard(i,state);
		}
	}

	//put played card in played card pile
	discardCard(handPos, currentPlayer, state, 0);
	return 0;
}
*/


int main(){

  struct gameState GAME, testGAME;
  int deck[10] = {copper, minion, mine, silver, gold, curse, council_room, smithy, tribute, adventurer};

  printf("====TESTING COUNCIL_ROOMINTERNAL nievesR ====\n");
  initializeGame(4, deck, 888, &GAME);
  initializeGame(4, deck, 888, &testGAME);


  playcouncil_room(&testGAME, 0);
  printf("Checking current Players handCount (should pass)\nExpected handcount: %d councilRoom handcount: %d\n", GAME.handCount[GAME.whoseTurn]+3, testGAME.handCount[GAME.whoseTurn]);
  if(GAME.handCount[GAME.whoseTurn]+3 == testGAME.handCount[GAME.whoseTurn])
    printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");


  printf("Checking other players handcount \n");
  int currentPlayer = whoseTurn(&GAME);
  int flag = 1;
  int i;
    for (i = 0; i < GAME.numPlayers; i++){
    if (i != currentPlayer){
      if (GAME.handCount[i] != GAME.handCount[i]+1)
        flag = 0;
    }
  }
  if(flag == 0)
    printf("TEST FAILED\n");
  else
    printf("TEST PASSED\n");



  printf("====END TESTING====\n\n");
  return 0;
}
