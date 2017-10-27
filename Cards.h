//
//  Cards.h
//  Bridge
//
//  Created by Benjamin Kauffmann on 25/10/2017.
//  Copyright © 2017 Benjamin Kauffmann. All rights reserved.
//

#ifndef Cards_h
#define Cards_h
#include <string.h>
#include "Random.h"
#include "Functions.h"

int* InitNoDuplicates(int a, int b);
void Mix(int* numbers_array, int size);
void majuscule(char *chaine);

const char card_name[13][7] = { "AS", "ROI", "DAME", "VALET", "DIX", "NEUF", "HUIT", "SEPT", "SIX", "CINQ", "QUATRE", "TROIS", "DEUX" };
const char card_color[4][8] = { "PIQUE", "COEUR", "CARREAU", "TREFLE" };

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
 Convertir une couleur de carte en un nombre
 */
int ConvertColorString(char color[8])
{
    majuscule(&color[8]);
    
    char pique[] = "PIQUE", coeur[] = "COEUR", carreau[] = "CARREAU", trefle[] = "TREFLE";
    
    if(strcmp(color, pique) == 0){
        return 0;
    }
    else if(strcmp(color, coeur) == 0){
        return 1;
    }
    else if(strcmp(color, carreau) == 0){
        return 2;
    }
    else if(strcmp(color, trefle) == 0){
        return 3;
    }
    return -1;
}

int ConvertCardsString(char card[8]){
    int num_card;
    for (int i = 0; i < 13; i++) {
        if(strcmp(card, card_name) == 0){
            num_card = i;
        }
    }
    return card_name[num_card];
}

/*
 Attribut à une carte une valeur correspondant
 */
int ReverseCardConvert(char *card, char *color){
    ConvertColorString(color);
    return 0; //temporaire
}


const char * ShowCard(int card_id) {
    int card[2];
    ConvertCard(card_id, card);
    
    char string[50];
    sprintf(string, "%s de %s\n", card_name[card[1]], card_color[card[0]]);
    return string;
}


#endif /* Cards_h */
