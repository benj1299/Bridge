#pragma once

#include <stdio.h>
#include "Player.h"

typedef struct GameConfig GameConfig;
struct GameConfig {
    int levee_goal; //nombre de levées à réaliser
    int atout;
    int donneur;
    int avancement[]; //nombre de levées en cours
};

typedef struct Aucount Aucount;
struct Aucount {
    bool player_choice[4];
    int card;
    int color
};

/*
Retourne le score de levée d'une équipe
return int;
*/
int SumRaisesTeam(Player players[], int team) {
	return (team == 0) ? players[0].nb_raises + players[1].nb_raises : players[2].nb_raises + players[3].nb_raises;
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

const char * ShowCard(int card_id) {
	const char card_name[13][7] = { "AS", "ROI", "DAME", "VALET", "DIX", "NEUF", "HUIT", "SEPT", "SIX", "CINQ", "QUATRE", "TROIS", "DEUX" };
	const char card_color[4][8] = { "PIQUE", "COEUR", "CARREAU", "TREFLE" };

	int card[2];
	ConvertCard(card_id, card);

	char string[50];
	sprintf(string, "%s de %s\n", card_name[card[1]], card_color[card[0]]);
	return string;
}

void Auction(GameConfig game_config, Player players[4]){
    Aucount aucount;
    for (i = 0; i < 4; i++)
    {
        char choice[8];
        bool action = FALSE;
        
        while action
        {
            scanf("Entrer PASSE pour passer ou ENCHERE pour encherir : %s", choice);
            if (choice == "PASSE") {
                aucount.player_choice[i] = FALSE;
                action = TRUE;
            }
            else if(choice == "ENCHERE"){
                aucount.player_choice[i] = TRUE;
                scanf("Entrez une carte : %s", card);
                scanf("Entrez une couleur : %s", color);
                aucount.card = card;
                aucount.color = color;
                action = TRUE;
            }
            else {action = FALSE;}
        }

    }
}

void CreateGame(int nb_player, int nb_card)
{
	Player players[4];
    GameConfig game_config;
    
    CreateTeams(players);
	DistribCards(nb_player, nb_card, players);
    game_config.donneur = RandRange(0, 4);
    Auction(game_config, players);
}
