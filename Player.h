#pragma once

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

void CreateTeams(Player players[]);
int  SumRaisesTeam(Player players[], int team);
void PlayerSitting(Player players[], int winner, int *westmost_player, int *mort);
char * NameTeam(int team);
