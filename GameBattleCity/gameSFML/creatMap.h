#pragma once
#include "wall.h"
class creatMap : public entity
{
public:

	/* Wall vector array water */
	vector<wall> wallArrayWater1;
	vector<wall> wallArrayWater2;
	vector<wall>::const_iterator i17;

	/* Wall vector array brick */
	vector<wall> wallArrayBrick;
	vector<wall>::const_iterator i23;

	/* Wall vector array stone */
	vector<wall> wallArrayStone;
	vector<wall>::const_iterator i27;

	vector<wall> wallArrayGlass;
	vector<wall>::const_iterator i29;
	
	wall stone;
	wall brick;
	wall Water1;
	wall Water2;
	wall glass;
	

	creatMap();
	void creatWater();
	void creatStone();
	void creatBrick();
	void creatGlass();
};