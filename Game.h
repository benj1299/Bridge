#pragma once

#include <stdio.h>
#include "Player.h"
#include "Cards.h"
#include "Functions.h"

typedef struct GameConfig GameConfig;
struct GameConfig {
    int levee_goal; //nombre de levées à réaliser
    int atout;
    int donneur;
    int avancement[]; //nombre de levées en cours
};

void CreateTeams(Player players[]);
void DistribCards(int nb_player, int nb_cards, Player players[4]);
void majuscule(char *chaine);

/*
Retourne le score de levée d'une équipe
return int;
*/
int SumRaisesTeam(Player players[], int team) {
	return (team == 0) ? players[0].nb_raises + players[1].nb_raises : players[2].nb_raises + players[3].nb_raises;
}

/*
 Jeu d'enchère de début de partie
 */
int Auction(GameConfig game_config)
{
    int contrat_tmp = 10; //temporaire mettre à 0
    int contrat = 0;
    char card[7], color[8];
    int winner;
    
    for (int i = 0; i < 4; i++)
    {
        char choice[8], passe[] = "PASSE", enchere[] = "ENCHERE";
        int action = 1;
        
        while (action)
        {
            scanf("Entrer PASSE pour passer ou ENCHERE pour encherir : %s", choice);
            majuscule(choice);
            
            if (strcmp(choice, passe) == 0) {
                action = 0;
            }
            
            else if(strcmp(choice, enchere) == 0)
            {
                scanf("Entrez une carte : %s", card);
                scanf("Entrez une couleur : %s", color);
                
                majuscule(card);
                majuscule(color);
                
                //contrat_tmp = ReverseCardConvert(card, color);
                
                if (contrat_tmp > contrat)
                {
                    contrat = contrat_tmp;
                    contrat_tmp = 0;
                    
                    game_config.levee_goal = 6 + card;
                    game_config.atout = 4;// mettre une fonction ColorConvert(color);
                    winner = i;
                    
                    action = 0;
                }
                
                else
                {
                    printf("L'enchère est trop basse, veuillez en sélectionner une plus haute ou passer\n");
                    action = 1;
                }
            }
            
            else {action = 1;}
        }
    }
    return winner;
}

/*
 Déclancheur de partie
 */
void CreateGame(int nb_player, int nb_card)
{
	Player players[4];
    GameConfig game_config;
    
    CreateTeams(players);
	DistribCards(nb_player, nb_card, players);
    game_config.donneur = RandRange(0, 4);
    
    int winner = Auction(game_config);
    players[winner].role = 1;
}
