#include <stdio.h>
#include "Battle.h"

void Battle(GameConfig game_config, Player players[], int winner)
{
 // On place les joueurs correctement et leur assigne leurs bon roles
 players[winner].role = 1; // déclarant
 int westmost_player = 0, mort = 0;
    
 for (int i = 0; i < 4; i++) {
   if (i != winner) {
     if ((winner > 1 && i > 1) || (winner < 2 && i < 2))
     {
       players[i].role = -1; // mort
       players[i].position = 0;
       mort = i;
     }
     else {
       players[i].role = 0; // flancs
       if (westmost_player) {
         players[i].position = 3;
         westmost_player = i;
       }
       else
       {
         players[i].position = 2;
         westmost_player = 1;
       }
     }
   }
   else
     players[i].position = 1;
 }

 /*for (int i = 0; i < 4; i++)
 printf("Joueur %d : role -> %d, pos -> %d\n", i + 1, players[i].role, players[i].position);
  */

 // Le joueur à l'Ouest joue l'entame
    
 printf("\nA vous de jouer %s, voici vos cartes :\n", players[westmost_player].name);

 ShowDeck(players[westmost_player]);
 char entame_nbr[7], entame_color[8];
 while (1) {
   printf("\nEntrez une couleur de carte pour l'entame : ");
   Scan(entame_color, 8);
   UpperCase(entame_color);
   if (ConvertColorString(entame_color) == -1) {
     printf("La couleur de carte utilisee n'est pas autorise.\n");
     continue;
   }
   printf("Entrez la valeur de l'entame : ");
   Scan(entame_nbr, 7);
   UpperCase(entame_nbr);
   if (ConvertCardString(entame_nbr) == -1) {
     printf("La carte utilisee n'est pas autorise.\n");
     continue;
   }
     /*vérifier qu'il possède bien la carte (par hache assoiciatif à l'indice et couleur de la carte dans un pointeur)*/
   break;
 }
    
 // Le mort montre son jeu
 printf("\nVoici le jeu du mort (joueur %s) : \n", players[mort].name);
 ShowDeck(players[mort]);


 char parsed_entame[20];
 ShowCard(ReverseCardConvert(entame_nbr, entame_color), parsed_entame);
 printf("\n\nEntame : %s", parsed_entame);

 // Chaque joueur joue sur l'entame
 int cards_played[4];
 for (int i = westmost_player; i < westmost_player; i++) {

   printf("\nA vous de jouer %s, voici vos cartes :\n", players[i].name);
   ShowDeck(players[westmost_player]);
   char card[7], color[8];
   while (1) {
     printf("Entrez une couleur de carte : ");
     Scan(color, 8);
     UpperCase(color);
     if (ConvertColorString(color) == -1) {
       printf("La couleur de carte utilisee n'est pas autorise.\n");
       continue;
     }

     printf("Entrez une carte : ");
     Scan(card, 7);
     UpperCase(card);
     if (ConvertCardString(card) == -1) {
       printf("La carte utilisee n'est pas autorise.\n");
       continue;
     }
     break;
   }
   cards_played[i] = ReverseCardConvert(entame_nbr, entame_color);

   if (i == 4)
     i = 0;
 }
}
