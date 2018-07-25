#include "creatMap.h"

#define SIZE_WALL 18


creatMap::creatMap()
{
	/* creat object stone */
	stone.destructable = 0;
	stone.rect.setSize(Vector2f(47, 45));
	stone.rect.setFillColor(Color::White);

	stone.sprite.scale(0.06, 0.06);
	stone.sprite.setOrigin(500, 35);
	stone.destructable = 0;

	/* creat object brick */
	brick.destructable = 1;
	brick.rect.setFillColor(Color::Red);
	brick.rect.setSize(Vector2f(SIZE_WALL, SIZE_WALL));
	brick.rect.setPosition(20 * 30, 20 * 15);
	brick.rect.setOrigin(-1, -1);

	brick.sprite.scale(0.1, 0.1);
	brick.sprite.setOrigin(1.5, 2);
	brick.sprite.scale(0.2, 0.2);

	/* creat object water */
	Water1.destructable = 3;
	Water1.rect.setFillColor(Color::Blue);
	Water1.rect.setSize(Vector2f(SIZE_WALL + 23, SIZE_WALL + 25));

	Water2.destructable = 3;
	Water2.rect.setFillColor(Color::Blue);
	Water2.rect.setSize(Vector2f(SIZE_WALL + 23, SIZE_WALL + 25));

	Water1.sprite.setTextureRect(IntRect(91, 64, 14, 20));
	Water2.sprite.setTextureRect(IntRect(0, 104, 20, 20));
	Water2.sprite.setOrigin(6, 0);
	Water1.sprite.scale(2.5, 2.5);
	Water2.sprite.scale(2.5, 2.5);

	/* creat object glass */
	glass.destructable = 3;
	glass.rect.setFillColor(Color::Blue);
	glass.rect.setSize(Vector2f(SIZE_WALL + 40, SIZE_WALL + 40));
	glass.sprite.setOrigin(600, 200);
	glass.sprite.scale(0.095, 0.095);
}

void creatMap::creatWater()
{
	for (int r = 16; r < 26; r++)
	{
		Water1.rect.setPosition(35 * r, 35 * 15);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 35 * 15);
		wallArrayWater2.push_back(Water2);
	}

	for (int r = 28; r < 37; r++)
	{
		Water1.rect.setPosition(35 * r, 35 * 15);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 35 * 15);
		wallArrayWater2.push_back(Water2);
	}

	for (int r = 11; r < 21; r++)
	{
		Water1.rect.setPosition(35 * r, 52 * 15);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 52 * 15);
		wallArrayWater2.push_back(Water2);
	}
	for (int r = 11; r < 13; r++)
	{
		Water1.rect.setPosition(35 * r, 49.3 * 15);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 49.3 * 15);
		wallArrayWater2.push_back(Water2);
	}

	for (int r = 11; r < 13; r++)
	{
		Water1.rect.setPosition(35 * r, 50 * 14);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 50 * 14);
		wallArrayWater2.push_back(Water2);
	}

	for (int r = 33; r < 42; r++)
	{
		Water1.rect.setPosition(35 * r, 52 * 15);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 52 * 15);
		wallArrayWater2.push_back(Water2);
	}

	for (int r = 40; r < 42; r++)
	{
		Water1.rect.setPosition(35 * r, 49.3 * 15);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 49.3 * 15);
		wallArrayWater2.push_back(Water2);
	}

	for (int r = 40; r < 42; r++)
	{
		Water1.rect.setPosition(35 * r, 50 * 14);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 50 * 14);
		wallArrayWater2.push_back(Water2);
	}

	for (int r = 21; r < 32; r++)
	{
		Water1.rect.setPosition(35 * r, 17 * 16);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 17 * 16);
		wallArrayWater2.push_back(Water2);
	}
	for (int r = 21; r < 32; r++)
	{
		Water1.rect.setPosition(35 * r, 17 * 18);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 17 * 18);
		wallArrayWater2.push_back(Water2);
	}
	/*for (int r = 21; r < 32; r++)
	{
		Water1.rect.setPosition(35 * r, 17 * 20);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 17 * 20);
		wallArrayWater2.push_back(Water2);
	}*/
	for (int r = 3; r < 6; r++)
	{
		Water1.rect.setPosition(35 * r, 17 * 10);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 17 * 10);
		wallArrayWater2.push_back(Water2);
	}
	for (int r = 3; r < 6; r++)
	{
		Water1.rect.setPosition(35 * r, 17 * 8);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 17 * 8);
		wallArrayWater2.push_back(Water2);
	}
	for (int r = 47; r < 50; r++)
	{
		Water1.rect.setPosition(35 * r, 17 * 10);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 17 * 10);
		wallArrayWater2.push_back(Water2);
	}
	for (int r = 47; r < 50; r++)
	{
		Water1.rect.setPosition(35 * r, 17 * 8);
		wallArrayWater1.push_back(Water1);

		Water2.rect.setPosition(35 * r, 17 * 8);
		wallArrayWater2.push_back(Water2);
	}

}

void creatMap::creatBrick()
{
	for (int r = 27; r < 36; r++)
	{
		for (int k = 12; k < 15; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 32; r < 36; r++)
	{
		for (int k = 8; k < 12; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 17; r < 20; r++)
	{
		for (int k = 0; k < 2; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 82; r < 85; r++)
	{
		for (int k = 0; k < 2; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 70; r < 79; r++)
	{
		for (int k = 12; k < 15; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 70; r < 74; r++)
	{
		for (int k = 8; k < 12; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL * k);
			wallArrayBrick.push_back(brick);
		}
	}

	for (int r = 28; r < 31; r++)
	{
		for (int k = 29; k < 40; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 72; r < 75; r++)
	{
		for (int k = 29; k < 40; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL * k);
			wallArrayBrick.push_back(brick);
		}
	}

	for (int r = 18; r < 31; r++)
	{
		for (int k = 46; k < 49; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, 17.8  * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 18; r < 21; r++)
	{
		for (int k = 43; k < 46; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, 17.8  * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 72; r < 85; r++)
	{
		for (int k = 46; k < 49; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, 17.8  * k);
			wallArrayBrick.push_back(brick);
		}
	}
	for (int r = 82; r < 85; r++)
	{
		for (int k = 43; k < 46; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, 17.8  * k);
			wallArrayBrick.push_back(brick);
		}
	}

	for (int r = 0; r < 3; r++)
	{
		for (int k = 35; k < 45; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL  * k);
			wallArrayBrick.push_back(brick);
		}
	}

	for (float r = 103.8; r < 107; r++)
	{
		for (int k = 35; k < 45; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL  * k);
			wallArrayBrick.push_back(brick);
		}
	}

	for (float r = 47; r < 49; r++)
	{
		for (int k = 54; k < 60; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL  * k);
			wallArrayBrick.push_back(brick);
		}
	}

	for (float r = 54; r < 56; r++)
	{
		for (int k = 54; k < 60; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL  * k);
			wallArrayBrick.push_back(brick);
		}
	}

	for (float r = 49; r < 54; r++)
	{
		for (int k = 54; k < 56; k++)
		{
			brick.rect.setPosition(SIZE_WALL * r, SIZE_WALL  * k);
			wallArrayBrick.push_back(brick);
		}
	}
}

void creatMap::creatStone()
{
	
	for (int k = 19; k < 21; k++)
	{
		stone.rect.setPosition(47 * k, 34.8 * 15);
		wallArrayStone.push_back(stone);
	}

	for (int k = 18; k < 22; k++)
	{
		stone.rect.setPosition(47 * k, 47.5 * 15);
		wallArrayStone.push_back(stone);
	}

	stone.rect.setPosition(47 * 10.5, 68.7 * 15);
	wallArrayStone.push_back(stone);

	stone.rect.setPosition(47 * 28, 68.7 * 15);
	wallArrayStone.push_back(stone);

	for (int k = 17; k < 22; k++)
	{
		stone.rect.setPosition(47.4 * k, 17.2 * 13);
		wallArrayStone.push_back(stone);
	}

	for (int k = 22; k < 35; k++)
	{
		stone.rect.setPosition(47.4 * 0, 17.2 * k);
		wallArrayStone.push_back(stone);
	}

	for (int k = 22; k < 35; k++)
	{
		stone.rect.setPosition(1870, 17.2 * k);
		wallArrayStone.push_back(stone);
	}
	for (int k = 0; k <= 26; k++)
	{
		stone.rect.setPosition(-54, 40 * k);
		wallArrayStone.push_back(stone);
		stone.rect.setPosition(1920, 40 * k);
		wallArrayStone.push_back(stone);
	}
	for (int k = 1; k <= 46; k++)
	{
		stone.rect.setPosition(40 * k, -52);
		wallArrayStone.push_back(stone);
		stone.rect.setPosition(40 * k, 1080);
		wallArrayStone.push_back(stone);
	}

}

void creatMap::creatGlass()
{
	for (int k = 18; k <= 21; k++)
	{
		glass.rect.setPosition(46.25 * k, 64);
		wallArrayGlass.push_back(glass);
	}

	for (int k = 15; k <= 21; k++)
	{
		glass.rect.setPosition(50 * k, 120);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 6; k <= 11; k++)
	{
		glass.rect.setPosition(53.4 * k, 270);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 5; k <= 13; k++)
	{
		glass.rect.setPosition(53.3 * 6, 54.3 * k);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 29; k <= 34; k++)
	{
		glass.rect.setPosition(43.2 * k, 270);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 5; k <= 13; k++)
	{
		glass.rect.setPosition(43.3 * 34, 54.5 * k);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 15; k <= 23; k++)
	{
		glass.rect.setPosition(48 * k, 762);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 12; k <= 15; k++)
	{
		glass.rect.setPosition(46 * k, 762 + 58);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 25; k <= 27; k++)
	{
		glass.rect.setPosition(46 * k, 762 + 58);
		wallArrayGlass.push_back(glass);
	}
	for (int k = -1; k <= 4; k++)
	{
		glass.rect.setPosition(54 * k, 1025);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 15; k <= 18; k++)
	{
		glass.rect.setPosition(54 * -0.1, 55 * k);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 31; k <= 36; k++)
	{
		glass.rect.setPosition(53.5 * k, 1025);
		wallArrayGlass.push_back(glass);
	}
	for (int k = 15; k <= 18; k++)
	{
		glass.rect.setPosition(51.8 * 36, 55 * k);
		wallArrayGlass.push_back(glass);
	}
}