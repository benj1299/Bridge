#pragma once

#include "Player.h"
#include "Functions.h"
#include "Cards.h"

typedef struct GameConfig GameConfig;
struct GameConfig {
	int levee_goal; // nombre de levées à réaliser
	int atout;
	int donneur;
	int avancement[]; // nombre de levées en cours
};

int  Auction(GameConfig game_config, Player players[4]);
int  EndGame(Player players[], GameConfig game_config);
void CreateGame(void);
