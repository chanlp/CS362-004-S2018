// This file randomly tests the Village card

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

	printf("--------- TESTING: Village card ----------\n");

	for(i=0; i<3000; i++){
		// Constrain t0 2 to 4 players 
		int numPlayers = rand() % (MAX_PLAYERS -1) + 2;
		struct gameState G; 
		struct gameState testG;

		int m[10] = {adventurer, province, gardens, smithy, great_hall, remodel, village, embargo, salvager, duchy};

		// Initialize game and randomize card inputs per iteration
		initializeGame(numPlayers, m, rand(), &G);
		player = rand() % numPlayers;
		G.whoseTurn = player;
		int handPosition = rand() % MAX_HAND;

		// Copy into new game state
		memcpy(&testG, &G, sizeof(struct gameState));
		// Play Village card, passing in random elements 
		cardEffect(village, 0, 0, 0, &testG, handPosition, 0);


		// Test 1: Make sure player gains +1 card
		printf("TEST 1: Make sure player gains +1 card:\n");
		if(G.handCount[player] == testG.handCount[player]){
			printf("PASSED. Player lost village card and drew a card. Card count is the same.\n");
		}
		else{
			printf("FAILED. Starting Deck size: %d, Finishing Deck size: %d\n", G.handCount[player], testG.handCount[player]);
			NumErrors = NumErrors + 1;
		}

		// Test 2: Ensure that player gains 2 actions
		printf("Test 2: Ensure that player gains 2 actions\n");
		if(testG.numActions - G.numActions == 2){
			printf("PASSED. Expected Action Card count: %d, Actual count: %d\n", 2, testG.numActions - G.numActions);
		}	
		else {
			printf("FAILED. Expected Action Card count: %d, Actual count: %d\n", 2, testG.numActions - G.numActions);
			NumErrors = NumErrors + 1;
		}	

		// Test 3: Played village card is discarded from hand
		printf("TEST 3: Make sure played village card is discarded from hand\n");
		if(testG.playedCardCount == 1){
			printf("PASSED. Expected number of cards put onto pile: %d, Actual number: %d\n", 1, testG.playedCardCount);
		}
		else {
			printf("FAILED. Expected number of cards put onto pile: %d, Actual number: %d\n", 1, testG.playedCardCount);
			NumErrors = NumErrors + 1;
		}
		printf("\n\n");
	}
	printf("\nTotal tests: %d\n", 3000 * NumChecks);
	printf("Tests Passed: %d\n", 3000 * NumChecks - NumErrors);
	printf("Tests Failed: %d\n", NumErrors);

	return 0; 
}
