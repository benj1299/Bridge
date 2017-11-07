#pragma once

#include "Functions.h"

typedef struct Player Player;
struct Player {
    char name[100];
    int nb_points_total;
    
    int position;
    int deck[13];
    int role; // déclarant (1) / mort (-1) / flancs (0)
    int nb_raises; // nombre de levées personnelles
    
    Player *suivant;
};

typedef struct PlayerListe PlayerListe;
struct PlayerListe
{
    Player *premier;
};

PlayerListe *InitPlayerList(void);
void InsertPlayer(PlayerListe *player_liste);
void DeletePlayer(PlayerListe *player_liste);
void ShowPlayerListe(PlayerListe *player_liste);
void CreateTeams(Player players[]);
char * NameTeam(int team);
int SumRaisesTeam(Player players[], int team);
