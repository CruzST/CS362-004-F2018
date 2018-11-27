/*****************************
name: steven cruz
date: 11/9/2018
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
  srand(time(NULL));
  int passed = 0;
  int failed = 0;
  int flag;

  printf("====TESTING ADVENTURER(contains bug, nievesR)====\n");

  int n;
  for (n = 0; n < 5000; n++){
    int numPlayers = (rand() % (4 - 2 + 1)) + 2;
    int randoSeed = (rand() % 1000) + 1;
    initializeGame(numPlayers, deck, randoSeed, &GAME);
    initializeGame(numPlayers, deck, randoSeed, &testGAME);

    int p;
    for (p = 0; p < numPlayers; p++){


      //printf("PLAYER %d TURN\n", testGAME.whoseTurn);

      int deckEmpty = rand() % 4;
      if (deckEmpty == 0){
/*
          //printf("--->PLAYER %d 0 deck\n", testGAME.whoseTurn);

        //printf("PLAYER %d 0 deck\n", testGAME.whoseTurn);
        // discard 5 cards, draw 5 cards, deck should be 0 now
        int d;
        for (d = 0; d < 5; d++){
          discardCard(d, GAME.whoseTurn, &testGAME, 0);
          drawCard(GAME.whoseTurn, &testGAME);

          discardCard(d, GAME.whoseTurn, &GAME, 0);
          drawCard(GAME.whoseTurn, &GAME);
        }
*/
        testGAME.deckCount[GAME.whoseTurn] = 0;
        //printf("b4 deck GAME: %d TESTGAME: %d\n", GAME.deckCount[GAME.whoseTurn], testGAME.deckCount[GAME.whoseTurn]);
        //printf("b4 hand GAME: %d TESTGAME: %d\n", GAME.handCount[GAME.whoseTurn], testGAME.handCount[GAME.whoseTurn]);
      }


      playAdventurer(&testGAME);
      //printf("after hand GAME: %d TESTGAME: %d\n", GAME.handCount[GAME.whoseTurn], testGAME.handCount[GAME.whoseTurn]);
      if (GAME.handCount[GAME.whoseTurn]+1 == testGAME.handCount[GAME.whoseTurn]){
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


  printf("====END TESTING ADVENTURER====\n\n");
  return 0;
}
