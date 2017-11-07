#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "Functions.h"

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
Retourne le nom de l'équipe selon son numéro
*/
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
