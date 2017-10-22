//
//  Random.h
//  Bridge
//
//  Created by Benjamin Kauffmann on 21/10/2017.
//  Copyright © 2017 Benjamin Kauffmann. All rights reserved.
//

#ifndef Random_h
#define Random_h

/*
 Renvoie un nombre aléatoire compris entre a et b
 return int;
 */
int RandRange(int a, int b) {
    return rand() % (b - a) + a;
}


/*
 Créer un tableau de nombre ordonné de a à b
 
 a = limite inférieur
 b = limite supérieur
 return array;
 */

int* InitNoDuplicates(int a, int b) {
    int size = b - a;
    int* result = malloc((size) * sizeof(int));
    int i = 0;
    
    // Filling the array with ordered data
    for (i = 0; i < size; i++) {
        result[i] = i + a;
    }
    return result;
}

/*
 Melange un tableau de nombre passé en argument
 */

void Mix(int* numbers_array, int size) {
    int drawn_number = 0, temp = 0;
    
    for (int i = 0; i < size; i++) {
        drawn_number = RandRange(0, size);
        
        // Swap the value of i and drawn_number
        temp = numbers_array[i];
        numbers_array[i] = numbers_array[drawn_number];
        numbers_array[drawn_number] = temp;
    }
}


#endif /* Random_h */
