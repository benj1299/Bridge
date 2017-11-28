#include <stdio.h>
#include <stdlib.h>

#include "Player.h"

/*
Crée les équipes en attribuant un nom et une position à chaque joueur
*/
void CreateTeams(Player players[])
{
	for (int i = 0; i < 4; i++) {
		printf("Joueur %d, entrez votre nom : ", i + 1);
		Scan(players[i].name, 100);
		Capitalize(players[i].name);
	}

	players[0].position = 0; // N
	players[1].position = 1; // S
	players[2].position = 2; // E
	players[3].position = 3; // W
}

/*
Retourne le score de levée d'une équipe
return int;
*/
int SumRaisesTeam(Player players[], int team)
{
	return (team == 0) ? players[0].nb_raises + players[1].nb_raises : players[2].nb_raises + players[3].nb_raises;
}

/*
Place correctement les joueurs et leur assigne les bons roles
*/
void PlayerSitting(Player players[], int winner, int *westmost_player, int *mort)
{
	players[winner].role = 1; // déclarant
	*westmost_player = 0;
	*mort = 0;

	for (int i = 0; i < 4; i++) {
		if (i != winner) {
			if ((winner > 1 && i > 1) || (winner < 2 && i < 2))
			{
				players[i].role = -1; // mort
				players[i].position = 0;
				*mort = i;
			}
			else {
				players[i].role = 0; // flancs
				if (*westmost_player) {
					players[i].position = 3;
					*westmost_player = i;
				}
				else
				{
					players[i].position = 2;
					*westmost_player = 1;
				}
			}
		}
		else
			players[i].position = 1;
	}
}

/*
Retourne le nom de l'équipe selon son numéro
*/
char * NameTeam(int team)
{
	return (team == 0) ? "Nord-Sud" : "Est-Ouest";
}
