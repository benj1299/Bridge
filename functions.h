//
//  Functions.h
//  Bridge
//
//  Created by Benjamin Kauffmann on 26/10/2017.
//  Copyright © 2017 Benjamin Kauffmann. All rights reserved.
//

#ifndef Functions_h
#define Functions_h
#include <ctype.h>
#include <string.h>

/*Vide le buffer*/
void freeBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/*
 Sécurise face aux attaques buffer overflow et retire \n du fgets qui n'est pas esthétique
 */
int scan(char *chaine, int longueur)
{
    char *positionEntree = NULL;
    
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else {
            freeBuffer();
        }
        return 1;
    }
    else
    {
        freeBuffer();
        return 0;
    }
}


void majuscule(char *chaine)
{
    for (int i = 0 ; chaine[i] != '\0' ; i++)
    {
        chaine[i] = toupper(chaine[i]);
    }
}

#endif /* Functions_h */
