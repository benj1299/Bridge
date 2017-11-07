#pragma once

#include "Player.h"
#include "Random.h"
#include "Functions.h"

void DistribCards(int nb_cards, Player players[4]);
void ConvertCard(int card_id, int card[2]);
int ConvertColorString(char color[8]);
int ConvertCardString(char card[8]);
int ReverseCardConvert(char * card, char * color);
void ShowCard(int card_id, char string[22]);
void ShowDeck(Player player);
