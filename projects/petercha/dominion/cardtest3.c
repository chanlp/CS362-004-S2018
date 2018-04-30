// This unit test is for the Village Card

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	//int position = -1;
	int player1 = 0;
	//int player2 = 1;
	int numPlayers = 2;
	struct gameState G;
	struct gameState testG;
	int k[10] = {feast, gardens, embargo, remodel, tribute, mine, cutpurse, ambassador, great_hall, village};
	int seed = 1000;
	//int deckSizeP1;
	//int	deckSizeP2;
	//int numActions;
	//int pileSize;

	printf("---------- TESTING CARD: Village ------------\n\n");

	// inialize new game state
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	//deckSizeP1 = testG.handCount[player1];
	//deckSizeP2 = testG.deckCount[player2];
	//numActions = testG.numActions;
	//pileSize = testG.deckCount[player1];

	//Play the Village card
	cardEffect(village, 0, 0, 0, &testG, 0, 0);

	// Test 1: Make sure player gains +1 card
	printf("TEST 1: Make sure player gains +1 card:\n");
	if(G.handCount[player1] == testG.handCount[player1]){
		printf("PASSED. Players lost village card and drew a card. Card count is the same.\n");
	}
	else{
		printf("FAILED. Starting Deck size: %d, Finishing Deck size: %d\n", G.handCount[player1], testG.handCount[player1]);
	}

	// Test 2: Ensure that player gains 2 actions
	printf("Test 2: Ensure that player gains 2 actions\n");
   	if(testG.numActions - G.numActions == 2){
		printf("PASSED. Expected Action Card count: %d, Actual count: %d\n", 2, testG.numActions - G.numActions);
	}	
	else {
		printf("PASSED. Expected Action Card count: %d, Actual count: %d\n", 2, testG.numActions - G.numActions);
	}	

	// Test 3: Played village card is discarded from hand
	printf("TEST 3: Make sure played village card is discarded from hand\n");
	if(testG.playedCardCount == 1){
		printf("PASSED. Expected number of cards put onto pile: %d, Actural number: %d\n", 1, testG.playedCardCount);
	}
	else {
	printf("FAILED. Expected number of cards put onto pile: %d, Actural number: %d\n", 1, testG.playedCardCount);

	}

	return 0;
}
