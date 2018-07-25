#include "wall.h"
#include <Windows.h>

#define SIZE_WALL_WIDTH 30
#define SIZE_WALL_HEIGHT 30

wall::wall()
{
	/* Creating tank player */
	rect.setSize(Vector2f(SIZE_WALL_WIDTH, SIZE_WALL_HEIGHT));
	rect.setPosition(0, 0);
	rect.setFillColor(Color::Blue);
	//sprite.setTextureRect(IntRect(0, 0, 28.5f, 28));
	/*rect.setSize(Vector2f(25, 25));
	rect.setPosition(350, 350);
	rect.setFillColor(Color::White);*/
	//sprite.scale(0.05f, 0.05f);


}

void wall::update()
{
	sprite.setPosition(rect.getPosition());
}
