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

void AssociateCards(int card_id);

typedef struct Player Player;
struct Player
{
    int tossed_cards;
};

void DistribCards(int nb_player, int nb_cards)
{
    int* tossed_cards = InitNoDuplicates(0, nb_cards);
    int* player_tmp[nb_player][13];
    Mix(tossed_cards, nb_cards);
    int card_id = 0;
    
    for (int i=0; i < nb_player; i++)
    {
        for (int j=0; j < 13; j++) {
            player_tmp[i][j] = &tossed_cards[card_id];
            printf("%d pour %d\n", tossed_cards[card_id], i);
            card_id++;
        }
    }
}

void CreatePlayers(int nb_player, int nb_card){
    Player player[nb_player];
    DistribCards(nb_player, nb_card);
}

#endif /* Player_h */

