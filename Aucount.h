//
//  Aucount.h
//  Bridge
//
//  Created by Benjamin Kauffmann on 25/10/2017.
//  Copyright © 2017 Benjamin Kauffmann. All rights reserved.
//

#ifndef Aucount_h
#define Aucount_h

void Auction(GameConfig game_config)
{
    int contrat_tmp = 10; //temporaire mettre à 0
    int contrat = 11; //temporaire mettre à 0
    int *card[7], *color[8];
    int winner;
    
    for (i = 0; i < 4; i++)
    {
        char choice[8];
        bool action = FALSE;
        
        while action
        {
            scanf("Entrer PASSE pour passer ou ENCHERE pour encherir : %s", choice);
            
            if (choice[8] == "PASSE") {
                action = TRUE;
            }
            
            else if(choice[8] == "ENCHERE")
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
                    
                    action = TRUE;
                }
                
                else
                {
                    printf("L'enchère est trop basse, veuillez en sélectionner une plus haute ou passer");
                    action = FALSE;
                }
            }
            
            else {action = FALSE;}
        }
    }
    
    return winner;
    
}

#endif /* Aucount_h */
