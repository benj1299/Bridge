// main.c: Defines the entry point for the console application.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "Game.h"

void  INThandler(int sig);

int main(void)
{
	srand(time(NULL));
	CreateGame();
	return 0;
}
