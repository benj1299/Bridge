#pragma once

#include <stdio.h>
#include "Player.h"


/*
Retourne le score de levée d'une équipe
return int;
*/
int SumRaisesTeam(Player players[], int team) {
	return (team == 0) ? players[0].nb_raises + players[1].nb_raises : players[2].nb_raises + players[3].nb_raises;
}


void ConvertCard(int card_id, int card[2]) {
	int card_color = (card_id + 1) / 13;
	int card_number = card_id - (13 * (card_color));

	card[0] = card_color;
	card[1] = card_number;

}

const char * ShowCard(int card_id) {
	const char card_name[13][7] = { "AS", "ROI", "DAME", "VALET", "DIX", "NEUF", "HUIT", "SEPT", "SIX", "CINQ", "QUATRE", "TROIS", "DEUX" };
	const char card_color[4][8] = { "PIQUE", "COEUR", "CARREAU", "TREFLE" };

	int card[2];
	ConvertCard(card_id, card);

	char string[50];
	sprintf(string, "%s de %s\n", card_name[card[1]], card_color[card[0]]);
	return string;
}


void CreateGame(int nb_player, int nb_card)
{
	Player players[4];

	DistribCards(nb_player, nb_card, players);

	for (int i = 0; i < nb_player; i++)
	{
		for (int j = 0; j < 13; j++)
			printf("%s pour joueur %d\n", ShowCard(players[i].deck[j]), i + 1);
	}


	//CreateTeams(players);
	//ConfigGameType();
}