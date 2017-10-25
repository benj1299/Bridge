#pragma once

#include <stdio.h>
#include "Player.h"
#include "Cards.h"
#include "Aucount.h"

typedef struct GameConfig GameConfig;
struct GameConfig {
    int levee_goal; //nombre de levées à réaliser
    int atout;
    int donneur;
    int avancement[]; //nombre de levées en cours
};

void CreateTeams(Player players[]);
void DistribCards(int nb_player, int nb_cards, Player players[4]);
void Auction(GameConfig game_config);

/*
Retourne le score de levée d'une équipe
return int;
*/
int SumRaisesTeam(Player players[], int team) {
	return (team == 0) ? players[0].nb_raises + players[1].nb_raises : players[2].nb_raises + players[3].nb_raises;
}


void CreateGame(int nb_player, int nb_card)
{
	Player players[4];
    GameConfig game_config;
    
    CreateTeams(players);
	DistribCards(nb_player, nb_card, players);
    game_config.donneur = RandRange(0, 4);
    
    int winner = Auction(game_config);
    players[winner].role = TRUE;
}
