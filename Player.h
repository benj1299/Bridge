#pragma once

typedef struct Player Player;
struct Player {
	char name_player[1000];
	char position;
	int deck[13];
	int role; // déclarant/mort/autres
	int nb_raises; //nombre de levée personnel
	int nb_points_total;
};

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
 Créer les équipes en attribuant un nom et une position à chaque joueur
 */
void CreateTeams(Player players[])
{
    for (int i = 0; i < 4; i++) {
        scanf("Entrer votre nom : %s", players[i].name_player);
    }
    
	players[0].position = 'N';
	players[1].position = 'S';
	players[2].position = 'E';
	players[3].position = 'W';
}
