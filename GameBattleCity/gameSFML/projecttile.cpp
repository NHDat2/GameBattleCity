#include "projecttile.h"
#include <Windows.h>

#define SIZE_BULLET_WIDTH 10
#define SIZE_BULLET_HEIGHT 10

projecttile::projecttile()
{
	/* Creating bullet */
	rect.setSize(Vector2f(SIZE_BULLET_WIDTH, SIZE_BULLET_HEIGHT));
	rect.setFillColor(Color::Green);
	//rect.setPosition(10, 10);
	//sprite.setTextureRect(IntRect(0, 0, 32, 32));
	sprite.scale(0.08f, 0.05f);
}

/* Update bullet */
void projecttile::update()
{
	if (Keyboard::isKeyPressed(Keyboard::Y))
	{
		if (counter > 5)
		{
			movementSpeedd += 5;
		}
		else
		{
			movementSpeedd += 3;
		}

		/* Using Sleep to Sleeping Bot player to avoid inserting image because insert image to cooridate of bot player */
		//Sleep(50);
		//direction = 5;
		counter++;
	}
	if (direction == 1)
	{
		rect.move(0, -movementSpeedd);
		sprite.setPosition(rect.getPosition().x - 12, rect.getPosition().y);
		movementSpeedd = 1.8;
	}
	else if (direction == 2)
	{
		rect.move(0, movementSpeedd);
		sprite.setPosition(rect.getPosition().x - 12, rect.getPosition().y);
		movementSpeedd = 1.8;
	}
	else  if (direction == 3)
	{
		rect.move(-movementSpeedd, 0);
		sprite.setPosition(rect.getPosition().x, rect.getPosition().y - 5);
		movementSpeedd = 1.8;
	}
	else if (direction == 4)
	{
		rect.move(movementSpeedd, 0);
		sprite.setPosition(rect.getPosition().x, rect.getPosition().y - 5);
		movementSpeedd = 1.8;
	}

	/* Sprite set at Rect */
//	sprite.setPosition(rect.getPosition().x - 5, rect.getPosition().y);
	
}