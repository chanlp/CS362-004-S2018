//Unit test for the Smithy Card

/* include the following lines in your makefile:
 * 
 * cardtest1: cardtest1.c dominion.o rngs.o
 * 		gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
 */ 

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>

int main(){

	int newCards = 0; 
	int discarded = 1; 
	int numPlayers = 2;
	int shuffledCards = 0; 
	int handpos = 0;
	int choice1 = 0; 
	int choice2 = 0; 
	int choice3 = 0; 
	int bonus = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int seed = 1000;
	struct gameState G, testG;
	int player1 = 0; 
	int player2 = 1; 

// initialize a game and player cards
initializeGame(numPlayers, k, seed, &G);

printf("---------------- Testing Card: %s --------------------\n", "Smithy");

printf("Test 1: Current player should receive exact 3 cards");
memcpy(&testG, &G, sizeof(struct gameState));
choice1 = 1;
cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

// Player should receive exactly 3 cards
newCards = 3;
printf("hand count = %d, expected = %d\n", testG.handCount[player1], G.handCount[player1] + newCards - discarded); 

if(testG.handCount[player1] == G.handCount[player1] + newCards - discarded){
	printf("TEST PASSED: Player recieved exactly 3 cards\n");
}
else {
	printf("TEST FAILED. Did not receive exactly 3 cards\n");
}

// Test 2: 3 cards should come from his own pile
printf("deck count = %d, expected = %d\n", testG.deckCount[player1], G.deckCount[player1] - newCards + shuffledCards);
if(testG.handCount[player1] == G.deckCount[player1] - newCards + shuffledCards){
	printf("TEST PASSED: 3 cards came from own pile\n");
}
else {
	printf("TEST FAILED: 3 cards did not come from own pile\n"); 
}

// Test 3: No state change should occur for other players
printf("\nTest3: Player 2's deck size unchanged when smithy card is drawn:\n");
if(testG.deckCount[player2] == G.deckCount[player2]){
	printf("PASSED. Deck size start: %d, Deck size finish: %d\n", G.deckCount[player2], testG.deckCount[player2]);
}
else {
	printf("FAILED. Deck size start: %d, Deck size finish: %d\n", G.deckCount[player2], testG.deckCount[player2]);
}


printf("\nTest3.1: Player 2's hand size unchanged when smithy card is drawn:\n");
if(testG.handCount[player2] == G.handCount[player2]){
	printf("PASSED. Hand size start: %d, Hand size finish: %d\n", G.handCount[player2], testG.handCount[player2]);
}
else {
	printf("FAILED. Hand size start: %d, Hand size finish: %d\n", G.handCount[player2], testG.handCount[player2]);
}


// Test 4: No state change should occur to the victory card piles and kingdom card piles

printf("\nTest 4: Test for state changes to see if any changes have been made to the victory card piles: \n");
if(G.supplyCount[estate] != testG.supplyCount[estate]){
	printf("FAILED. Estate count does not match. Expected: %d, Received: %d\n", G.supplyCount[estate], testG.supplyCount[estate]);
}
if(G.supplyCount[duchy] != testG.supplyCount[duchy]){
	printf("FAILED. Duchy count does not match. Expected: %d, Received: %d\n", G.supplyCount[duchy], testG.supplyCount[duchy]);
}
if(G.supplyCount[province] != testG.supplyCount[province]){
	printf("FAILED. Province count does not match. Expected: %d, Received: %d\n", G.supplyCount[province], testG.supplyCount[province]);
}
else {
	printf("PASSED: No state changes to Victory cards.");
}

printf("\nTest 4.1: Test for state changes to see if any changes have been made to the kingdom card piles: \n");

if(G.supplyCount[great_hall] != testG.supplyCount[great_hall]){
	printf("FAILED. great hall count does not match. Expected: %d, Received: %d\n", G.supplyCount[great_hall], testG.supplyCount[great_hall]);
}
if(G.supplyCount[gardens] != testG.supplyCount[gardens]){
	printf("FAILED. Gardens count does not match. Expected: %d, Received: %d\n", G.supplyCount[gardens], testG.supplyCount[gardens]);
}
else {
	printf("PASSED: No state changes to Kingdom cards.");
}

	printf("\n ---------- SUCCESS: Testing Complete for %s ---------\n\n", "Smithy card"); 

	return 0;
}
