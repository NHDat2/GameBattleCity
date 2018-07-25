#pragma once
#include "entity.h"

using namespace std;

class projecttile : public entity
{
public:
	/* Creating speed, damege and some attribute fo bullet */
	float movementSpeedd = 1.8;
	int attackDamage = 2;
	int direction = 0;
	bool destroy = false;
	int counter = 0;
	bool enemyProjecttile = false;
	projecttile();
	void update();
	//void updateMovement();
};

