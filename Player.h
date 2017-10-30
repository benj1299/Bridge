#pragma once

typedef struct Player Player;
struct Player {
	char name_player[1000];
    int nb_points_total;
	int position;
	int deck[13];
	int role; // déclarant/mort/autres
	int nb_raises; //nombre de levée personnel
};

/*
 Créer les équipes en attribuant un nom et une position à chaque joueur
 */
void CreateTeams(Player players[])
{
    for (int i = 0; i < 4; i++) {
        printf("Joueur %d, entrer votre nom :", i+1);
        scan(players[i].name_player);
        //Capitalize(players[i].name_player);
    }
    
	players[0].position = 0;//N
	players[1].position = 1;//S
	players[2].position = 2;//E
	players[3].position = 3;//W
}

char * NameTeam(int team)
{
    char name_team[10];
    if (team == 0) {
        name_team[10] = "Nord-Sud";
    }
    else
    {
        name_team[10] = "Est-Ouest";
    }
    return name_team;
}

/*
 Retourne le score de levée d'une équipe
 return int;
 */
int SumRaisesTeam(Player players[], int team)
{
    return (team == 0) ? players[0].nb_raises + players[1].nb_raises : players[2].nb_raises + players[3].nb_raises;
}
