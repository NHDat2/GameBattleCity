#include "random.h"
#include <ctime>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <vector>
#include <windows.h>


/* Creating function random movement for tank bot */
int generateRandom(int max)
{
	srand(time(0));
	int randomNumber = rand();
	int random = (randomNumber % max) + 1;
	return random;
}
/*
int generateRandom0(int max)
{
	srand(time(0));
	int randomNumber = rand();
	float random = (randomNumber % max);
	int myRandom = random;
	return myRandom;
}

int generateRandomBool()
{
	srand(time(0));
	int randomNumber = rand();
	float random = (randomNumber % 2) + 1;
	int myRandom = random;
	if (myRandom == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	return myRandom;
}*/