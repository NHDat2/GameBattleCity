#include "player.h"
#include <Windows.h>

#define SIZE_BLOCK_WIDTH 52
#define SIZE_BLOCK_HEIGHT 53
#define POSITION_X 400
#define POSITION_Y 200
#define MAX_SIZE_MAP_WIDTH 1858
#define MAX_SIZE_MAP_HEIGHT 1027

player::player()
{
	/* Creating tank player */
	rect.setSize(Vector2f(SIZE_BLOCK_WIDTH, SIZE_BLOCK_HEIGHT));
	rect.setPosition(POSITION_X, POSITION_Y);
	rect.setFillColor(Color::Blue);
	sprite.setTextureRect(IntRect(1.5f, 0, 30, 28));
	/* adjusting size for tank */
	sprite.scale(1.8f, 1.8f);
}

void player::update()
{
	/* Updating position for tank player */
	sprite.setPosition(rect.getPosition());
	/**/
}

void player::updateMovement()
{
	/* Creating movement for tank */
	/*if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		movementSpeed += 0.0005;
	}*/
	if (Keyboard::isKeyPressed(Keyboard::Y))
	{
		if (count > 5)
		{
			movementSpeed += 0.02;
		}
		else
		{
			movementSpeed += 0.001;
		}

		/* Using Sleep to Sleeping Bot player to avoid inserting image because insert image to cooridate of bot player */
		Sleep(50);
		//direction = 5;
		count++;
	}


//	cout << canMoveUp << " " << canMoveLeft << " " << canMoveDown << " " << canMoveRight << endl;
	/*if ((rect.getPosition().x < MAX_SIZE_MAP_WIDTH && rect.getPosition().x > 0) && (rect.getPosition().y < MAX_SIZE_MAP_HEIGHT && rect.getPosition().y > 0))
	{*/
		if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
		{
			if (canMoveUp == true)
			{
				rect.move(0, -movementSpeed);
				sprite.setTextureRect(IntRect(1.5f, 0, 30, 28));
				direction = 1;
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
		{
			if (canMoveDown == true)
			{
				rect.move(0, movementSpeed);
				sprite.setTextureRect(IntRect(1.5f, 33 * 1, 29, 35.0f));
				direction = 2;
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
		{
			if (canMoveLeft == true)
			{
				rect.move(-movementSpeed, 0);
				sprite.setTextureRect(IntRect(0.5f, 33.3 * 2, 30.0f, 27.8f));
				direction = 3;
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
		{
			if (canMoveRight == true)
			{
				rect.move(movementSpeed, 0);
				sprite.setTextureRect(IntRect(counterWalking * 32, 32.5f * 3, 30.0f, 27.5f));
				direction = 4;
				canMoveUp = true;
				canMoveDown = true;
				canMoveLeft = true;
				canMoveRight = true;
			}
		}
		else
		{
			/* Don't anything */
		}
		
//	}
	//else
	//{		
	
	//}
}