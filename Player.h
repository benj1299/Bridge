#pragma once
#include "Game.h"


void DistribCards(int *players[4], int nb_cards) {
	int* tossed_cards = InitNoDuplicates(0, nb_cards);
	int* players_tmp[4][13];
	Mix(tossed_cards, nb_cards);
	int card_id = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++) {
			players_tmp[i][j] = &tossed_cards[card_id];
			printf("%d pour %d\n", tossed_cards[card_id], i);
			card_id++;
		}
	}

}
