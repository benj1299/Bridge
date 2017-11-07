#include <stdio.h>
#include <stdlib.h>

#include "Player.h"

PlayerListe *InitPlayerList()
{
    PlayerListe *player_liste = malloc(sizeof(*player_liste));
    Player *player = malloc(sizeof(*player));
    
    if (player_liste == NULL || player == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    player->suivant = NULL;
    player_liste->premier = player;
    
    return player_liste;
}


void InsertPlayer(PlayerListe *player_liste)
{
    /* Création du nouvel élément */
    Player *nouveau = malloc(sizeof(*nouveau));
    if (player_liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = player_liste->premier;
    player_liste->premier = nouveau;
}


void DeletePlayer(PlayerListe *player_liste)
{
    if (player_liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    if (player_liste->premier != NULL)
    {
        Player *aSupprimer = player_liste->premier;
        player_liste->premier = player_liste->premier->suivant;
        free(aSupprimer);
    }
}

void ShowPlayerList(PlayerListe *player_liste)
{
    if (player_liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    Player *actuel = player_liste->premier;
    
    while (actuel != NULL)
    {
        //printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

/*
Crée les équipes en attribuant un nom et une position à chaque joueur
*/
void CreateTeams(Player players[])
{
	for (int i = 0; i < 4; i++) {
		printf("Joueur %d, entrez votre nom : ", i + 1);
		Scan(players[i].name, 100);
		Capitalize(players[i].name);
	}

	players[0].position = 0; // N
	players[1].position = 1; // S
	players[2].position = 2; // E
	players[3].position = 3; // W
}

/*
Retourne le nom de l'équipe selon son numéro
*/
char * NameTeam(int team)
{
	return (team == 0) ? "Nord-Sud" : "Est-Ouest";
}

/*
Retourne le score de levée d'une équipe
return int;
*/
int SumRaisesTeam(Player players[], int team)
{
	return (team == 0) ? players[0].nb_raises + players[1].nb_raises : players[2].nb_raises + players[3].nb_raises;
}
