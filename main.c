// main.c: Defines the entry point for the console application.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Game.h"
#include "Random.h"
#include "Player.h"

#define NB_CARDS 51


int RandRange(int a, int b);
int* InitNoDuplicates(int a, int b);
void Mix(int* numbers_array, int size);
void DistribCards(int *players[4], int nb_cards);

void CreatePlayers(int *tossed_cards) {
	int *players[4];
	DistribCards(players, NB_CARDS);
}


int main(void)
{
	srand(time(NULL));

	enum card_nbr { AS, ROI, DAME, VALET, DIX, NEUF, HUIT, SEPT, SIX, CINQ, QUATRE, TROIS, DEUX };
	enum card_color { PIQUE, COEUR, CARREAU, TREFLE };
	int *players[4];

	DistribCards(players, NB_CARDS);

	return EXIT_SUCCESS;
}
