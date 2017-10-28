// main.c: Defines the entry point for the console application.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "Random.h"
#include "Game.h"
#include "Cards.h"

#define NB_CARDS 51


void CreatePlayers(int nb_player, int nb_card);

int main(void)
{
	srand(time(NULL));

	enum card_nb { AS, ROI, DAME, VALET, DIX, NEUF, HUIT, SEPT, SIX, CINQ, QUATRE, TROIS, DEUX };
	enum card_color { PIQUE, COEUR, CARREAU, TREFLE };
    
	CreateGame(4, NB_CARDS);

	return EXIT_SUCCESS;
}
