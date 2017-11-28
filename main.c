// main.c: Defines the entry point for the console application.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "Cards.h"

int main(void)
{
    srand(time(NULL));
    CreateGame();
	return 0;
}
