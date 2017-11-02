#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <wchar.h>

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
void DistribCards(int nb_cards, Player players[4]);
void UpperCase(char * string);
int ConvertCardsString(char card[8]);
int SumRaisesTeam(Player players[], int team);
int Scan(char * string, int size);
char * NameTeam(int team);


/*
Jeu d'enchère de début de partie
*/
int Auction(GameConfig game_config, Player players[4])
{
	int contrat_tmp = 0;
	int contrat = 0;
	int winner = -1;
	char passe[] = "PASSE", enchere[] = "ENCHERE";

	for (int i = 0; i < 4; i++)
	{
		int action = 1;
		printf("\nJoueur %s : \n", players[i].name);
		while (action)
		{
			char choice[8];
			printf("Entrez PASSE pour passer ou ENCHERE pour enchérir : ");
			Scan(choice, 8);
			UpperCase(choice);

			if (strcmp(choice, passe) == 0) {
				action = 0;
			}
			else if (strcmp(choice, enchere) != 0 && strcmp(choice, passe) != 0 && strlen(choice) > 0) {
				printf("Le mot utilisé n'est pas pris en charge.");
				action = 0;

			}
			else if (strcmp(choice, enchere) == 0)
			{
				char card[7], color[8];

				printf("Entrez une couleur de carte : ");
				Scan(color, 8);

				printf("Entrez une carte : ");
				Scan(card, 7);

				UpperCase(color);
				UpperCase(card);

				if (ConvertCardsString(card) > 7) {
					printf("La carte utilisée n'est pas autorisé.\n");
					continue;
				}

				contrat_tmp = ConvertCardsString(card) + abs(ConvertColorString(color) - 4);

				if (contrat_tmp > contrat)
				{
					contrat = contrat_tmp;
					contrat_tmp = 0;

					game_config.levee_goal = 6 + ConvertCardsString(card);
					game_config.atout = ConvertColorString(color);
					winner = i;

					action = 0;
				}

				else
				{
					printf("\nL'enchère est trop basse, veuillez en sélectionner une plus haute ou passer.\n");
					continue;
				}
			}

			else { continue; }
		}
	}
	return winner;
}


/*
End Game
*/
int EndGame(Player players[], GameConfig game_config) {
	char choice[5], stop[] = "STOP";
	int team;

	printf("\n");

	for (int i = 0; i < 4; i++) {
		printf("%s a réalisé %d levées.\n", players[i].name, players[i].nb_raises);
	}

	printf("\nL'équipe Nord-Sud a réalisé %d levées et l'équipe Est-Ouest a réalisé %d levées.\n",
		SumRaisesTeam(players, 0), SumRaisesTeam(players, 1));

	for (int i = 0; i < 4; i++) {
		if (players[i].role == 1) {

			if (i < 2) { team = SumRaisesTeam(players, 0); }
			else { team = SumRaisesTeam(players, 1); }

			if (SumRaisesTeam(players, team) >= game_config.levee_goal)
			{
				printf("\nLe joueur %s a réalisé son contrat, l'équipe a gagné !\n", players[i].name);
			}
			else {
				printf("Le contrat n'as pas été rempli, l'équipe %s a gagné !", NameTeam(abs(team - 1)));
			}
		}
	}

	printf("\nTapez STOP pour arrêter de jouer ou appuyez sur Entrer pour continuer : ");
	Scan(choice, 5);
	UpperCase(choice);

	if (strcmp(choice, stop) == 0) { return 1; }
	else
	{
		for (int i = 0; i < 4; i++) {
			players[i].nb_points_total += players[i].nb_raises;
		}
		return 0;
	}

}


/*
Déclencheur de partie
*/
void CreateGame()
{
	int nb_card = 51;
	Player players[4];
	GameConfig game_config;

    printf("Bienvenue sur le super Jeu de Bridge que l'on a conçu !\n");
    
	while (1) {
		CreateTeams(players);
		DistribCards(nb_card, players);
		game_config.donneur = RandRange(0, 4);

		printf("\nPhase d'enchère :\n");
		int winner = Auction(game_config, players);
		players[winner].role = 1;

		printf("\nJeu de la carte :\n");


		if (EndGame(players, game_config)) { break; }
	}

	printf("\nMerci d'avoir joué a notre super jeu, on vous kiffe <3 !");
	exit(0);
}
