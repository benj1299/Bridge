//
//  Cards.h
//  Bridge
//
//  Created by Benjamin Kauffmann on 25/10/2017.
//  Copyright © 2017 Benjamin Kauffmann. All rights reserved.
//

#ifndef Cards_h
#define Cards_h
#include "Random.h";

int* InitNoDuplicates(int a, int b);
void Mix(int* numbers_array, int size);

/*
 Distribue les cartes et les sépare selon le nombre de joueurs dans un tableau
 */
void DistribCards(int nb_player, int nb_cards, Player players[4])
{
    int card_id = 0;
    
    int* tossed_cards = InitNoDuplicates(0, nb_cards);
    Mix(tossed_cards, nb_cards);
    
    for (int i = 0; i < nb_player; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            players[i].deck[j] = tossed_cards[card_id];
            card_id++;
        }
    }
}


/*
 Attribut à une valeur une carte correspondante
 */
void ConvertCard(int card_id, int card[2]) {
    if(card_id <= 51){
        int card_color = (card_id + 1) / 13;
        int card_number = card_id - (13 * (card_color));
        
        card[0] = card_color;
        card[1] = card_number;
    }
}

/*
 Convertir un nombre en couleur de carte
 */
int ConvertColor(char color[8]) {
    if(color[8] == "PIQUE"){
        return 0;
    }
    else if(color[8] == "COEUR"){
        return 1;
    }
    else if(color[8] == "CARREAU"){
        return = 2;
    }
    else if(color[8] == "TREFLE"){
        return 3;
    }
}

const char * ShowCard(int card_id) {
    const char card_name[13][7] = { "AS", "ROI", "DAME", "VALET", "DIX", "NEUF", "HUIT", "SEPT", "SIX", "CINQ", "QUATRE", "TROIS", "DEUX" };
    const char card_color[4][8] = { "PIQUE", "COEUR", "CARREAU", "TREFLE" };
    
    int card[2];
    ConvertCard(card_id, card);
    
    char string[50];
    sprintf(string, "%s de %s\n", card_name[card[1]], card_color[card[0]]);
    return string;
}


#endif /* Cards_h */
