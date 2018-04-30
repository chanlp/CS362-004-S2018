// This unit test is for the isGameOver function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

int main(){
	int numPlayer = 2;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState G;

	// Initialize a game state
	printf("TESTING isGameOver():\n");
	memset(&G, 23, sizeof(struct gameState));
	initializeGame(numPlayer, k, seed, &G);
	
	// set # province cards to 0
	printf("Setting stack of province cards to 0\n");
	G.supplyCount[province] = 0; 
	if(isGameOver(&G) == 1){
		printf("TEST PASSED. Province card stack empty and game is over.\n");
	}
	else {
		printf("TEST FAILED. Province card stack empty but game not over.\n");
	}

	// Set three supply pile to 0
	G.supplyCount[1] = 0;
	G.supplyCount[2] = 0;
	G.supplyCount[3] = 0;
	if(isGameOver(&G) == 1){
		printf("TEST PASSED due to three supply pile empty.\n");
	}
	else {
		printf("TEST FAILED. Three supply piles empty but game not over...\n");
	}

	// see that game is not over	

	return 0;
}
