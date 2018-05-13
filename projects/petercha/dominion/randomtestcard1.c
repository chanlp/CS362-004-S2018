// This file randomly tests the Remodel Card

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

	srand(time(NULL));
	int i;
	int player;
	int NumErrors; 
	int NumChecks = 3;

	printf("--------- TESTING: Remodel card ----------\n");

	for(i=0; i<3000; i++){
		// Constrain to 2 to 4 players 
		int numPlayers = rand() % (MAX_PLAYERS -1) + 2;
		struct gameState G; 
		struct gameState testG;

		int m[10] = {adventurer, province, gardens, smithy, great_hall, remodel, village, embargo, salvager, duchy};

		// Initialize game and randomize card inputs per iteration
		initializeGame(numPlayers, m, rand(), &G);
		player = rand() % numPlayers;
		G.whoseTurn = player;
		// randomize choices 1-3, and hand position
		int c1 = rand() % 50;	
		int c2 = rand() % 50;
		int c3 = rand() % 50;
		int handPosition = rand() % MAX_HAND;

		// Copy into new game state
		memcpy(&testG, &G, sizeof(struct gameState));
		// Play Village card, passing in random elements 
		cardEffect(remodel, c1, c2, c3, &testG, handPosition, 0);

		// Test 1: Make sure a card is played 
		printf("\nTEST 1: remodel card is discarded to played pile after used.\n");
		if(testG.playedCardCount == 1){
			printf("PASSED. Expected addition to played pile: %d, Actual addition: %d\n", 1, testG.playedCardCount);
		}
		else {
			printf("FAILED. Expected addition to played pile: %d, Actual addition: %d\n", 1, testG.playedCardCount);
			NumErrors = NumErrors + 1;
		}

		// Test 2: Make sure trashed card is discarded
		printf("TEST 2: remodel card is discarded to played pile after used and a card is trashed.\n");
		if(testG.discardCount[player] == 2){
			printf("PASSED. Expected discard: %d, Actual discard: %d\n", 2, testG.discardCount[player]);
		}
		else {
			printf("FAILED. Expected discard: %d, Actual discard: %d\n", 2, testG.discardCount[player]);
			NumErrors = NumErrors + 1;
		}
		
		// Test 3: Make sure player gains +1 card
		printf("TEST 3: Make sure player gains +1 card:\n");
		if(G.handCount[player] == testG.handCount[player]){
			printf("PASSED. Player lost remodel card and drew a card. Card count is the same.\n");
		}
		else{
			printf("FAILED. Starting Deck size: %d, Finishing Deck size: %d\n", G.handCount[player], testG.handCount[player]);
			NumErrors = NumErrors + 1;
		}

		printf("\n\n");
	}

	printf("\nTotal tests: %d\n", 3000 * NumChecks);
	printf("Tests Passed: %d\n", 3000 * NumChecks - NumErrors);
	printf("Tests Failed: %d\n", NumErrors);

	return 0;
}
