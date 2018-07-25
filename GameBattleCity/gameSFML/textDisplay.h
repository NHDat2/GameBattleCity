#include "entity.h"


class textDisplay : public entity
{
public:
	float movementSpeed = 0.05;
	string myString = "Default";
	int counter = 0;
	int lifeTimeCounter = 100;
	bool destroy = false;

	textDisplay();
	void update();
	//void updateMovement();
};
