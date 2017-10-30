#pragma once

/*
Renvoie un nombre aléatoire compris entre a et b
return int;
*/
int RandRange(int a, int b) {
	return rand() % (b - a) + a;
}


/*
Crée un tableau de nombres ordonnés de a à b
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
Mélange un tableau de nombres passé en argument
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
