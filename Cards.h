#pragma once

void DistribCards(int nb_cards, Player players[4]);
void ConvertCard(int card_id, int card[2]);
int ConvertColorString(char color[8]);
int ConvertCardString(char card[8]);
int ReverseCardConvert(char * card, char * color);
void ShowCard(int card_id, char string[22]);

#include "Random.h"
#include "Functions.h"

int * InitNoDuplicates(int a, int b);
void Mix(int * numbers_array, int size);
void UpperCase(char * string);

const char card_name[13][7] = { "AS", "ROI", "DAME", "VALET", "DIX", "NEUF", "HUIT", "SEPT", "SIX", "CINQ", "QUATRE", "TROIS", "DEUX" };
const char card_color[4][8] = { "PIQUE", "COEUR", "CARREAU", "TREFLE" };

/*
Distribue les cartes et les sépare selon le nombre de joueurs dans un tableau
*/
void DistribCards(int nb_cards, Player players[4])
{
	int card_id = 0;

	int * tossed_cards = InitNoDuplicates(0, nb_cards);
	Mix(tossed_cards, nb_cards);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			players[i].deck[j] = tossed_cards[card_id];
			card_id++;
		}
	}
	free(tossed_cards);
}


/*
Attribue à une valeur une carte correspondante
*/
void ConvertCard(int card_id, int card[2]) {
	if (card_id <= 51) {
		int card_color = (card_id + 1) / 13;
		int card_number = card_id - (13 * (card_color));

		card[0] = card_color;
		card[1] = card_number;
	}
}

/*
Convertir une couleur de carte en un nombre
*/
int ConvertColorString(char color[8])
{
	UpperCase(&color[8]);

	for (int i = 0; i < 4; i++) {
		if (strcmp(color, card_color[i]) == 0) {
			return i;
		}
	}
	return -1;
}

/*
Convertir une carte en un nombre
*/
int ConvertCardString(char card[8]) {

	UpperCase(card);

	for (int i = 0; i < 4; i++) {
		if (strcmp(card, card_name[i]) == 0) {
			return i;
		}
	}
	return -1;
}

/*
Attribue à une carte une valeur correspondante
*/
int ReverseCardConvert(char * card, char * color) {
	int color_nbr = ConvertColorString(color);
	int card_nbr = ConvertCardString(card);

	return card_nbr * (color_nbr + 1);
}


/*
Parse la carte et renvoie une chaîne lisible pour l'utilisateur de taille 20
*/
void ShowCard(int card_id, char string[20]) {
	int card[2];
	ConvertCard(card_id, card);
	sprintf(string, "%s de %s", card_name[card[1]], card_color[card[0]]);
}


void ShowDeck(Player player) {
	char parsed_card[20];
	for (int i = 0; i < 13; i++) {
		ShowCard(player.deck[i], parsed_card);
		printf("%s ; ", parsed_card);
	}
}