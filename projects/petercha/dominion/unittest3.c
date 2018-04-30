// This is a unit test for the discardCard function

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int numPlayers = 2;
	int player1 = 0;
	struct gameState G;
	struct gameState testG;
	int k[10] = {gardens, remodel, village, smithy, feast, tribute, ambassador, adventurer, mine, embargo}; 
	int seed = 1000;

	printf("---------- TESTING FUNCTION: discardCard ----------\n\n");

	// Test 1: if card not trashed, add to player pile
	printf("TEST 1: If card not trashed, add to player pile\n"); 
	initializeGame(numPlayers, k, seed, &G);
	G.hand[player1][0] = estate;
	G.hand[player1][1] = mine;
	G.hand[player1][2] = province;
	G.hand[player1][3] = embargo;
	G.hand[player1][4] = duchy;
	memcpy(&testG, &G, sizeof(struct gameState));

	// Discard estate card and do not trash
	discardCard(estate, player1, &testG, 0);
	if(testG.playedCardCount == G.playedCardCount + 1){
		printf("PASSED. Expected %d, Received %d\n", G.playedCardCount + 1, testG.playedCardCount);
	}
	else{
	printf("FAILED. Expected %d, Received %d\n", G.playedCardCount + 1, testG.playedCardCount);
	}

	// Ensure the card is no longer in the player's hand
	printf("TEST 2: Ensure the card is no longer in the player hand\n"); 
	int check = 0;
   	int i;	
	initializeGame(numPlayers, k, seed, &G);
	G.hand[player1][0] = estate;
	G.hand[player1][1] = mine;
	G.hand[player1][2] = province;
	G.hand[player1][3] = embargo;
	G.hand[player1][4] = duchy;
	memcpy(&testG, &G, sizeof(struct gameState));

	// Discard estate card and do not trash
	discardCard(estate, player1, &testG, 0);
	for(i=0; i<testG.handCount[player1]; i++){
		if(testG.hand[player1][i] == estate){
			check = 1;
		}
	}
	if(check != 1){
		printf("PASSED. The card is no longer in player hand");
	}
	else{
		printf("FAILED. Card is still in player hand...\n");
	}

	// If all cards used, set the last card
	printf("TEST 3: If all cards are used, set the last card\n");
	
	initializeGame(numPlayers, k, seed, &G);
	G.hand[player1][0] = estate;
	G.hand[player1][1] = mine;
	G.hand[player1][2] = province;
	G.hand[player1][3] = embargo;
	G.hand[player1][4] = duchy;
	memcpy(&testG, &G, sizeof(struct gameState));

	discardCard(estate, player1, &testG, 0);
	if(testG.hand[player1][testG.handCount[player1]]==-1){
		printf("PASSED. Expected -1, Received %d\n", testG.hand[player1][testG.handCount[player1]]);
	}
	else {
		printf("FAILED. Expected -1, Received %d\n", testG.hand[player1][testG.handCount[player1]]);
	}

	return 0; 
}
