#include "entity.h"


class player : public entity
{
public:
	/* Creating move, attackDamege and some attribute of player */
	float movementSpeed = 1.25;
	int attackDamage = 2;
	int counterWalking = 0;
	int direction = 0;
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;
	int hp = 1;
	int gil1 = 0;
	int count = 0;
	bool alive = false;

	player();
	void update();
	void updateMovement();
};