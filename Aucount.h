//
//  Aucount.h
//  Bridge
//
//  Created by Benjamin Kauffmann on 25/10/2017.
//  Copyright © 2017 Benjamin Kauffmann. All rights reserved.
//

#ifndef Aucount_h
#define Aucount_h
#include <string.h>
#include "Game.h"

int Auction(GameConfig game_config)
{
    int contrat_tmp = 10; //temporaire mettre à 0
    int contrat = 11; //temporaire mettre à 0
    char card[7], color[8];
    int winner;
    
    for (int i = 0; i < 4; i++)
    {
        char choice[8], passe[] = "PASSE", enchere[] = "ENCHERE";
        int action = 1;
        
        while (action)
        {
            scanf("Entrer PASSE pour passer ou ENCHERE pour encherir : %s", choice);
            
            if (strcmp(choice, passe) == 0) {
                action = 0;
            }
            
            else if(strcmp(choice, enchere) == 0)
            {
                scanf("Entrez une carte : %s", card);
                scanf("Entrez une couleur : %s", color);
                
                //convertir carte puis retourner un nombre dans contrat_tmp
                
                if (contrat_tmp > contrat)
                {
                    contrat = contrat_tmp;
                    contrat_tmp = 0;
                    
                    game_config.levee_goal = 6 + card;
                    game_config.atout = 4;// mettre une fonction ColorConvert(color);
                    winner = i;
                    
                    action = 0;
                }
                
                else
                {
                    printf("L'enchère est trop basse, veuillez en sélectionner une plus haute ou passer\n");
                    action = 1;
                }
            }
            
            else {action = 1;}
        }
    }
    
    return winner;
    
}

#endif /* Aucount_h */
