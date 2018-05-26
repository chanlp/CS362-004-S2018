// This unit test is for the whoseTurn function

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	struct gameState G;
	//struct gameState testG;

	printf("---------- TESTING FUNCTION: whoseTurn ------------\n\n");
	printf("TEST 1: Checking to see if function correctly returns the correct turn\n\n");

	printf("Manually setting the turn for the game state...\n");
	G.whoseTurn = 3; //manually set the turn for the gamestate

	if(whoseTurn(&G) == 3){
		printf("TEST PASSED: Function correctly returns turn.\n"); 
	}
	else {
		printf("TEST FAILED: Turn numbers do not match.\n");
	}

	return 0; 
}
