#include "enemy.h"


#define SIZE_BLOCK_WIDTH 56
#define SIZE_BLOCK_HEIGHT 57
#define SET_SCALE_IMAGE_WITH 1
#define SET_SCALE_IMAGE_HEIGHT 1
#define MAX_SIZE_MAP_WIDTH 1858
#define MAX_SIZE_MAP_HEIGHT 1027

enemy::enemy()
{
	/* Creating tank bot */
	rect.setSize(Vector2f(SIZE_BLOCK_WIDTH, SIZE_BLOCK_HEIGHT));
	rect.setPosition(400, 200);
	rect.setFillColor(Color::Blue);

}

void enemy::update()
{
	sprite.setPosition(rect.getPosition());
	if (isBlood == true)
	{
		bloodCounter++;
		if (bloodCounter >= bloodLifeTime)
		{
			alive = false;
		}
	}
}

void enemy::updateMovement()
{
	direction2 = rand() % 4 + 1;
	/* Creating movement for tank */
	if (Keyboard::isKeyPressed(Keyboard::Y))
	{
		
		if (counter > 5)
		{
			movementSpeed += 0.045;
		}
		else
		{
			movementSpeed += 0.0045;
		}
		counter++;

	}
		if (direction2 == 1) /* Up */
		{
			if (canMoveUp == true)
			{
				rect.move(0, -movementSpeed);
				sprite.setTextureRect(IntRect(43.5f * 3, 46.5f * 4, 80, 90));
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
				direction2 = 1;
			}
		}
		else if (direction2 == 2) /* Down */
		{
			if (canMoveDown == true)
			{
				rect.move(0, movementSpeed);
				sprite.setTextureRect(IntRect(43.5f * 0, 41 * 0, 63, 70));
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
				direction2 = 2;
			}
		}
		else if (direction2 == 3) /* Left */
		{
			if (canMoveLeft == true)
			{
				rect.move(-movementSpeed, 0);
				sprite.setTextureRect(IntRect(43.5f * 3, 34 * 2, 80, 60));
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
				direction2 = 3;
			}
		}
		else if (direction2 == 4) /* Right */
		{
			if (canMoveRight == true)
			{
				rect.move(movementSpeed, 0);
				sprite.setTextureRect(IntRect(43.5f * 3, 44 * 3, 63, 60));
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
				direction2 = 4;
			}
		}
		else
		{
			/* No Movement */
		}
	
}