#include <stdio.h>
#include "Battle.h"

/*
Lance la 2ème phase du jeu
*/
void Battle(GameConfig game_config, Player players[], int winner)
{
	int westmost_player, mort, cards_played;
	char entame_nbr[7], entame_color[8], parsed_entame[20];

	PlayerSitting(players, winner, &westmost_player, &mort);

	/*for (int i = 0; i < 4; i++)
	printf("Joueur %d : role -> %d, pos -> %d\n", i + 1, players[i].role, players[i].position);
	*/

    printf("\nVoici le jeu du mort (joueur %s) : \n", players[mort].name);
    ShowDeck(players[mort]);
    
	printf("\nA vous de jouer %s, voici vos cartes :\n", players[westmost_player].name);
	ShowDeck(players[westmost_player]);
	SelectCardBattle(entame_color, entame_nbr);
	cards_played = ReverseCardConvert(entame_nbr, entame_color);

	// Affiche la carte selectionnée par le joueur
	ShowCard(cards_played, parsed_entame);
	printf("\n\nEntame : %s", parsed_entame);

    EntameGame(westmost_player, players, cards_played, entame_color, entame_nbr);
}

void EntameGame(int first, Player players[], int cards_played, int entame_color[], int entame_nbr[]){
    int i = 0;
    while (i < 4)
    {
        if (i == first) {
            if (first == 3) {
                i = 4;
                continue;
            }
            else{
                i++;
            }
        }
        
        printf("\n\nA vous de jouer %s, voici vos cartes :\n\n", players[i].name);
        ShowDeck(players[i]);
        SelectCardBattle(entame_color, entame_nbr);
        
        for (int j = 0; j < 13; j++)
        {
            if (players[i].deck[j] == cards_played)
            {
                players[i].deck[j] = 100;
                break;
            }
        }
        i++;
    }
}
