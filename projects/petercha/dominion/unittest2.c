// This is the test us for the updateCoins function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

int main() {

	int numPlayer = 2;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState G; 
	struct gameState testG;
	int player1 = 0;
	int coinTotal = 0;

	// initialize a game state
	printf("TESTING updateCoins\n\n");
	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG,&G, sizeof(struct gameState));


	// We will test each type of coin: copper, silver, and gold:
	printf("Testing each type of coin: copper, silver, and gold:\n");

	printf("TEST 1: Copper coin adds +1 to total coins\n");
	testG.hand[player1][0] = copper;
	testG.hand[player1][1] = adventurer;
	testG.hand[player1][2] = remodel;
	testG.hand[player1][3] = gardens;
	testG.hand[player1][4] = feast;
	updateCoins(player1, &testG, 0);
	
	if(testG.coins == coinTotal+ 1){
		printf("PASSED. Coins expected: %d, Actual coins: %d\n", coinTotal + 1, testG.coins);
	}
	else {
		printf("FAILED. Coins expected: %d, Actual coins: %d\n", coinTotal + 1, testG.coins);
	}






	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG,&G, sizeof(struct gameState));

	printf("TEST 2: Silver coin adds +2 to total coins\n");
	testG.hand[player1][0] = silver;
	testG.hand[player1][1] = adventurer;
	testG.hand[player1][2] = remodel;
	testG.hand[player1][3] = gardens;
	testG.hand[player1][4] = feast;
	updateCoins(player1, &testG, 0);
	
	if(testG.coins == coinTotal+ 2){
		printf("PASSED. Coins expected: %d, Actual coins: %d\n", coinTotal + 2, testG.coins);
	}
	else {
		printf("FAILED. Coins expected: %d, Actual coins: %d\n", coinTotal + 2, testG.coins);
	}






	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG,&G, sizeof(struct gameState));

	printf("TEST 3: Gold coin adds +3 to total coins\n");
	testG.hand[player1][0] = gold;
	testG.hand[player1][1] = adventurer;
	testG.hand[player1][2] = remodel;
	testG.hand[player1][3] = gardens;
	testG.hand[player1][4] = feast;
	updateCoins(player1, &testG, 0);
	
	if(testG.coins == coinTotal+ 3){
		printf("PASSED. Coins expected: %d, Actual coins: %d\n", coinTotal + 3, testG.coins);
	}
	else {
		printf("FAILED. Coins expected: %d, Actual coins: %d\n", coinTotal + 3, testG.coins);
	}






	initializeGame(numPlayer, k, seed, &G);
	memcpy(&testG,&G, sizeof(struct gameState));

	printf("TEST 4: Testing bonus, which shoudld give coinVal +1\n");
	testG.hand[player1][0] = gold;
	testG.hand[player1][1] = adventurer;
	testG.hand[player1][2] = remodel;
	testG.hand[player1][3] = gardens;
	testG.hand[player1][4] = feast;
	updateCoins(player1, &testG, 1);
	
	if(testG.coins == coinTotal+ 4){
		printf("PASSED. Coins expected: %d, Actual coins: %d\n", coinTotal + 4, testG.coins);
	}
	else {
		printf("FAILED. Coins expected: %d, Actual coins: %d\n", coinTotal + 4, testG.coins);
	}


	return 0; 
}
