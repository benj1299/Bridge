#pragma once

#include "Player.h"
#include "Random.h"
#include "Functions.h"

void DistribCards(int nb_cards, Player players[4]);
void ConvertCard(unsigned int card_id, int card[2]);
int  ConvertColorString(char color[8]);
int  ConvertCardString(char card[8]);
int  ReverseCardConvert(char card[8], char color[8]);
void ShowCard(unsigned int card_id, char string[22]);
void ShowDeck(Player player);
void SelectCardBattle(char entame_color[], char entame_nbr[]);
void SortCards(int card_id[]);
