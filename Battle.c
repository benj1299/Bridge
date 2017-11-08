#include <stdio.h>
#include "Battle.h"

/*
 Lance la 2e phase du jeu
 */
void Battle(GameConfig game_config, Player players[], int winner)
{
     int westmost_player, mort, cards_played;
     char entame_nbr[7], entame_color[8], parsed_entame[20];
    
     PlayerSitting(players, winner, &westmost_player, &mort);

     /*for (int i = 0; i < 4; i++)
     printf("Joueur %d : role -> %d, pos -> %d\n", i + 1, players[i].role, players[i].position);
      */

     printf("\nA vous de jouer %s, voici vos cartes :\n", players[westmost_player].name);
     ShowDeck(players[westmost_player]);
     SelectCardBattle(entame_color, entame_nbr);
     cards_played = ReverseCardConvert(entame_nbr, entame_color);
    
     printf("\nVoici le jeu du mort (joueur %s) : \n", players[mort].name);
     ShowDeck(players[mort]);
    
     //Affiche la carte selectionné par le joueur
     ShowCard(cards_played, parsed_entame);
     printf("\n\nEntame : %s", parsed_entame);

     // Chaque joueur joue sur l'entame
     for (int i = westmost_player; i < westmost_player; i++)
     {
       printf("\nA vous de jouer %s, voici vos cartes :\n", players[i].name);
       ShowDeck(players[westmost_player]);
       SelectCardBattle(entame_color, entame_nbr);
         for(int j = 0; j < 13; j++){
             if(players[i].deck[j] == cards_played){
                 players[i].deck[j] = -1;
                 break;
             }
         }
     }
}
