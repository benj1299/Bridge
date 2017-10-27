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

void majuscule(char *chaine)
{
    for (int i = 0 ; chaine[i] != '\0' ; i++)
    {
        chaine[i] = toupper(chaine[i]);
    }
}

#endif /* Functions_h */
