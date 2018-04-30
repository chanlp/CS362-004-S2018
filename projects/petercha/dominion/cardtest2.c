// This unit test is for the adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
	
	int player1 = 0;
	//int pos = 0;
	//int played;
	//int deckSizeP1;
	//int deckSizeP2;
	//int cardPile;
	int numPlayers = 2;
	//int amountCoins;
	//int totalDrawn;
	//int drawnTreasureCards;
	struct gameState G;
	struct gameState testG;
	int seed = 1000;
   	int k[10] = {duchy, gardens, province, estate, tribute, mine, cutpurse, ambassador, great_hall, adventurer};

	printf("------- TESTING CARD: %s ---------\n\n", "Adventurer");
	// initialize the game
	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	// set values for test
	//deckSizeP1 = testG.handCount[player1];
	//deckSizeP2 = testG.deckCount[player2];
	//played = testG.handCount[player1] - testG.discardCount[player1];
	//cardPile = testG.deckCount[player1];
	//totalDrawn = 0; 
	//drawnTreasureCards = 0;
	//amountCoins = 0;
	int checkCount;

	// Test drawing cards until you get two coin cards
	testG.deck[player1][0] = copper;
	testG.deck[player1][1] = silver;
	testG.deck[player1][2] = gold;
	testG.deck[player1][3] = copper;
	testG.deck[player1][4] = silver;
	
	testG.hand[player1][0] = adventurer;	
	testG.hand[player1][1] = duchy;
	testG.hand[player1][2] = estate;
	testG.hand[player1][3] = province;
	testG.hand[player1][4] = gardens;

	checkCount = testG.handCount[player1];
	cardEffect(adventurer, 0, 0, 0, &testG, 0, 0); 

	printf("TEST 1: Testing drawing cards until you get 2 coin cards\n");
	if(testG.handCount[player1] - checkCount == 2){
		printf("PASSED. Coin card amount expected: %d, count finish: %d\n", 2, testG.handCount[player1] - checkCount);
	}
	else {
		printf("FAILED. Coin card amount expected: %d, count finish: %d\n", 2, testG.handCount[player1] - checkCount);
	}
	
	// Make sure that non-coin cards were discarded.
	printf("\nTEST 2: Ensure that non-coin cards were discarded\n");
	if(testG.discardCount[player1] == 1){
		printf("PASSED. Expected discard amount: %d, Result discarded: %d\n", 1, testG.discardCount[player1]);
	}
	else {
		printf("FAILED. Expected discard amount: %d, Result discarded: %d\n", 1, testG.discardCount[player1]);
	}
	
	// Test for state changes. Make sure victory card counts remain same
	printf("\nTEST 3: Test for state changes. Make sure victory card counts remain the same\n");
	if(G.supplyCount[estate] != testG.supplyCount[estate]){
		printf("FAILED. Estate count does not match. Expected: %d, Got: %d\n", G.supplyCount[estate], testG.supplyCount[estate]);
	}
	if(G.supplyCount[duchy] != testG.supplyCount[duchy]){
		printf("FAILED. Duchy count does not match. Expected: %d, Got: %d\n", G.supplyCount[duchy], testG.supplyCount[duchy]);
	}
	if(G.supplyCount[province] != testG.supplyCount[province]){
		printf("FAILED. Province count does not match. Expected: %d, Got: %d\n", G.supplyCount[province], testG.supplyCount[province]);
	}
	else {
		printf("PASSED. No state change. Victory card count are the same.\n");
	}

	return 0;
}
