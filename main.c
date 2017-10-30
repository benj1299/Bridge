// main.c: Defines the entry point for the console application.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Game.h"

void CreateGame(void);

int main(void)
{
	srand(time(NULL));

	enum card_nb { AS, ROI, DAME, VALET, DIX, NEUF, HUIT, SEPT, SIX, CINQ, QUATRE, TROIS, DEUX };
	enum card_color { PIQUE, COEUR, CARREAU, TREFLE };

	CreateGame();

	return EXIT_SUCCESS;
}
