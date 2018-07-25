#include "entity.h"
#include "random.h"

class enemy : public entity
{
public:
	/* Creating speed, attackDamege and some attribute for tank bot*/
	float movementSpeed = 1.25;
	int attackDamege = 2;
	int counterWalking = 0;
	int direction2 = 0;
	int counter = 0;
	int hp = 5;
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;
	bool alive = true;
	bool aggroed = false;
	bool isBlood = false;
	int bloodCounter = 0;
	int bloodLifeTime = 200;
	bool canFire = false;
	bool eagleAlive = true;

	//int value = 5;

	enemy();
	void update();
	void updateMovement();
};