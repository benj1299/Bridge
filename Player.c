#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Functions.h"

typedef struct Player Player;
struct Player {
	char name[100];
	int nb_points_total;

	int position;
	int deck[13];
	int role; // déclarant (1) / mort (-1) / flancs (0)
	int nb_raises; // nombre de levées personnelles
};

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

char * NameTeam(int team)
{
	return (team == 0) ? "Nord-Sud" : "Est-Ouest";
}

/*
Retourne le score de levée d'une équipe
return int;
*/
int SumRaisesTeam(Player players[], int team)
{
	return (team == 0) ? players[0].nb_raises + players[1].nb_raises : players[2].nb_raises + players[3].nb_raises;
}
