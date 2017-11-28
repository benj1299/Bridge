#pragma once

#include "Player.h"
#include "Game.h"
#include "Functions.h"
#include "Cards.h"

void Battle(GameConfig game_config, Player players[], int winner);
void EntameGame(int first, Player players[], int cards_played, int entame_color[], int entame_nbr[]);
