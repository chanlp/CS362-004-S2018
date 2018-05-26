// This is the unit test for the Remodel card.

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int numPlayers = 2;
	struct gameState G;
	struct gameState testG;
	int k[10] = {feast, remodel, embargo, gardens, mine, tribute, ambassador, cutpurse, great_hall, village};
	int player1 = 0;
	int seed = 1000;

	printf("---------- TESTING CARD: Remodel---------------------\n\n");
	
	// Set up the game
	initializeGame(numPlayers, k, seed, &G);	
	memcpy(&testG, &G, sizeof(struct gameState));

	// Play the remodel card
	cardEffect(remodel, 0, 0, 0, &testG, 0, 0);

	// Test 1: Make sure a cards is discarded from hand
	printf("\nTEST 1: remodel card is discarded to played pile after used.\n");
	if(testG.playedCardCount == 1){
		printf("PASSED. Expected addition to played pile: %d, Actual addition: %d\n", 1, testG.playedCardCount);
	}
	else {
		printf("FAILED. Expected addition to played pile: %d, Actual addition: %d\n", 1, testG.playedCardCount);
	}

	// Test 2: Make sure trashed card is discarded
	printf("TEST 1: remodel card is discarded to played pile after used and a card is trashed.\n");
	if(testG.discardCount[player1] == 2){
		printf("PASSED. Expected discard: %d, Actual discard: %d\n", 2, testG.discardCount[player1]);
	}
	else {
		printf("FAILED. Expected discard: %d, Actual discard: %d\n", 2, testG.discardCount[player1]);
	}

	return 0; 
}
