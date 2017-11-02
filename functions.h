#pragma once

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Vide le buffer
void FreeBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

/*
Stocke un tableau de caractères vide et renvoie dans celui-ci la reponse de Scan().
Sécurise face aux attaques buffer overflow et retire \n du fgets qui n'est pas esthétique.
*/
int Scan(char * string, int size)
{
	char * entr_key_pos = NULL;

	if (fgets(string, size, stdin) != NULL)
	{
		entr_key_pos = strchr(string, '\n');

		if (entr_key_pos != NULL)
		{
			*entr_key_pos = '\0';
		}
		else {
			FreeBuffer();
		}
		return 1;
	}
	else
	{
		FreeBuffer();
		return 0;
	}
}


void UpperCase(char * string)
{
	for (int i = 0; string[i] != '\0'; i++)
	{
		string[i] = toupper(string[i]);
	}
}

void Capitalize(char * string) {
	toupper(string[0]);

	for (int i = 1; string[i] != '\0'; i++)
	{
		string[i] = tolower(string[i]);
	}
}
