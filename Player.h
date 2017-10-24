//
//  Player.h
//  Bridge
//
//  Created by Benjamin Kauffmann on 21/10/2017.
//  Copyright © 2017 Benjamin Kauffmann. All rights reserved.
//
#include "Game.h"
#ifndef Player_h
#define Player_h

void ConvertCards(int card_id);

typedef struct Player Player;
struct Player {
    int cards[13];
    char position;
    int nb_raises;
};

/*
 Distribue les cartes et les separes selon le nombre de joueurs dans un tableau
 */
void DistribCards(int nb_player, int nb_cards, Player *player)
{
    int card_id = 0;
    
    int* tossed_cards = InitNoDuplicates(0, nb_cards);
    Mix(tossed_cards, nb_cards);
    
    for (int i=0; i < nb_player; i++)
    {
        for (int j=0; j < 13; j++)
        {
            player[i].cards[j] = tossed_cards[card_id];
            //printf("%d : %d\n", tossed_cards[card_id], i);
            card_id++;
        }
    }
}


void CreateTeams(Player *player){
    player[0]->position = "N";
    player[1]->position = "S";
    player[2]->position = "E";
    player[3]->position = "W";
}

void CreateParty(int nb_player, int nb_card)
{
    Player player;
    DistribCards(nb_player, nb_card, &player);
    //CreateTeams(&player);
    //ConfigTypeParty();
}

#endif /* Player_h */

