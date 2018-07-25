#pragma once
#include "entity.h"

class pickUp : public entity
{
public:
	/* Creating move, attackDamege and some attribute of player */
	bool bullet = true;
	bool destroyBullet = false;
	bool coin = true;
	bool destroyCoin = false;
	int bulletValue = 5;
	int coinValue = 30;

	pickUp();
	void update();
};

