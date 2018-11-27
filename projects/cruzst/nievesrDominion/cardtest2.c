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
int playAdventurer(struct gameState *state){

	int z = 0;
	int drawntreasure = 0;
	int cardDrawn;
	int temphand[MAX_HAND];
	int currentPlayer = whoseTurn(state);

	while(drawntreasure<2){
		if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
		  shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver)
		  drawntreasure++;
		else{
		  temphand[z]=cardDrawn;
		  state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
		  z++;
		}
		  }
		while(z-1>=0){
		state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
		z=z-1;
        }
      return 0;

}
*/


int main(){
  struct gameState GAME, testGAME;
  int deck[10] = {copper, minion, mine, silver, gold, curse, council_room, smithy, tribute, adventurer};

  printf("====TESTING ADVENTURER(contains bug nievesR)====\n");
  initializeGame(2, deck, 888, &GAME);
  initializeGame(2, deck, 888, &testGAME);
  //memcpy(&testGAME, &GAME, sizeof(struct gameState));

  playAdventurer(&testGAME);
  printf("Testing handCount\n");
  printf("Expected handcCound: %d, adventurer handCount: %d\n", GAME.handCount[GAME.whoseTurn]+2, testGAME.handCount[GAME.whoseTurn]);

  if (GAME.handCount[GAME.whoseTurn]+2 == testGAME.handCount[GAME.whoseTurn])
    printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");


  printf("====END TESTING ADVENTURER====\n\n");
  return 0;
}
