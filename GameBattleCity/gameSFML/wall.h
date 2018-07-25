#include "entity.h"


class wall : public entity
{
public:
	int destructable = 0;
	/* 1 : Destructable
	   2 : Undestructable but still can't through the object
	   3 : Undestructable but can through the object */
	int hp = 1;
	int destroy = 0;
	/* 1 : Can destroy object 
	   2 : Can't destroy object */

	wall();
	void update();
};
