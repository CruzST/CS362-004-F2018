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
int adventurerInternal(struct gameState *state){
  int temphand[MAX_HAND];
  int cardDrawn;
  int drawntreasure = 0;
  int z = 0;
  int currentPlayer = whoseTurn(state);

  while(drawntreasure<1){         // BUG: only 1 treasure is drawn
    if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(currentPlayer, state);
    }

    drawCard(currentPlayer, state);
    cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.

    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
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
  int x;
  int treasure;
  int draw;
  int treasure1, treasure2;
  int temp[MAX_HAND];
  struct gameState GAME, testGAME;
  int deck[10] = {copper, minion, mine, silver, gold, curse, council_room, smithy, tribute, adventurer};
  srand(time(NULL));
  int passed = 0;
  int failed = 0;

  printf("====TESTING ADVENTURER(contains bug)====\n");

  int n;
  for (n = 0; n < 2000; n++){
    int numPlayers = (rand() % (4 - 2 + 1)) + 2;
    int randoSeed = (rand() % 1000) + 1;

    initializeGame(numPlayers, deck, randoSeed, &GAME);
    initializeGame(numPlayers, deck, randoSeed, &testGAME);

    int p;
    for (p = 0; p < numPlayers; p++){
      adventurerInternal(&testGAME);
      if (GAME.handCount[GAME.whoseTurn]+1 == testGAME.handCount[GAME.whoseTurn]){
        passed++;
      }
      else{
        printf("TEST FAILED. Something went Wrong.\n");
        failed++;
      }
      endTurn(&GAME);
      endTurn(&testGAME);
    }
  }

  printf("Tests passed: %d. Tests failed: %d\n", passed, failed);


  printf("====END TESTING ADVENTURER====\n\n");
  return 0;
}
