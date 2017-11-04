PlayerListe *InitPlayer(void);
void InsertPlayer(PlayerListe *player_liste);
void DeletePlayer(PlayerListe *player_liste);
void ShowPlayerListe(PlayerListe *player_liste);
void CreateTeams(Player players[]);
char * NameTeam(int team);
int SumRaisesTeam(Player players[], int team);
