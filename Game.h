#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <wchar.h>


typedef struct GameConfig GameConfig;
struct GameConfig {
	int levee_goal; //nombre de levées à réaliser
	int atout;
	int donneur;
	int avancement[]; //nombre de levées en cours
};


#include "Functions.h"
#include "Player.h"
#include "Cards.h"


void CreateTeams(Player players[]);
void DistribCards(int nb_cards, Player players[4]);
void UpperCase(char * string);
int ConvertCardString(char card[8]);
int SumRaisesTeam(Player players[], int team);
int Scan(char * string, int size);
char * NameTeam(int team);


/*
Jeu d'enchère de début de partie
*/
int Auction(GameConfig game_config, Player players[4])
{
	int contrat_tmp = 10; // temporaire mettre à 0
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
			printf("Entrez PASSE pour passer ou ENCHERE pour encherir : ");
			Scan(choice, 8);
			UpperCase(choice);

			if (strcmp(choice, passe) == 0) {
				action = 0;
			}
			else if (strcmp(choice, enchere) != 0 && strcmp(choice, passe) != 0 && strlen(choice) > 0) {
				printf("Le mot utilise n'est pas pris en charge.\n");
				continue;
			}
			else if (strcmp(choice, enchere) == 0)
			{
				char card[7], color[8];

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
				if (ConvertCardString(card) > 7) {
					printf("La carte utilisee n'est pas autorise.\n");
					continue;
				}
				

				//contrat_tmp = ConvertCardString(card) + ConvertColorString(color);

				if (contrat_tmp > contrat)
				{
					contrat = contrat_tmp;
					contrat_tmp = 0;

					game_config.levee_goal = 6 + ConvertCardString(card);
					game_config.atout = ConvertColorString(color);
					winner = i;

					action = 0;
				}

				else
				{
					printf("\nL'enchere est trop basse, veuillez en selectionner une plus haute ou passer.\n");
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
int EndGame(GameConfig game_config, Player players[4]) {
	char choice[5], stop[] = "STOP";
	int team;

	printf("\n----\n\n");

	for (int i = 0; i < 4; i++) {
		printf("%s a realise %d levees.\n", players[i].name, players[i].nb_raises);
	}

	printf("\nL'equipe Nord-Sud a realise %d levees et l'equipe Est-Ouest a realise %d levees.\n",
		SumRaisesTeam(players, 0), SumRaisesTeam(players, 1));

	for (int i = 0; i < 4; i++) {
		if (players[i].role == 1) {

			if (i < 2) { team = SumRaisesTeam(players, 0); }
			else { team = SumRaisesTeam(players, 1); }

			if (SumRaisesTeam(players, team) >= game_config.levee_goal)
			{
				printf("\nLe joueur %s a realise son contrat, l'equipe a gagne !\n", players[i].name);
			}
			else {
				printf("Le contrat n'a pas ete rempli, l'equipe %s a gagne !", NameTeam(abs(team - 1)));
			}
		}
	}

	printf("\nTapez STOP pour arreter de jouer ou appuyez sur Entrer pour continuer : ");
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

	while (1) {
		printf("Bienvenue sur le super Jeu de Bridge que l'on a concu !\n");


		CreateTeams(players);
		DistribCards(nb_card, players);
		game_config.donneur = RandRange(0, 4);

		printf("\n\nPhase d'enchere :\n");
		int winner = Auction(game_config, players);

		printf("\n\nJeu de la carte :\n");


		if (EndGame(game_config, players)) { break; }
	}

	printf("\nMerci d'avoir joue a notre super jeu, on vous kiffe <3 !");
	exit(0);
}
