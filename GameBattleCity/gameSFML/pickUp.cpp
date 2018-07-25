#include "pickUp.h"

#define SIZE_BLOCK_ITEM_WIDTH 10
#define SIZE_BLOCK_ITEM_HEIGHT 13
#define SET_POSITION_BLOCK_IMAGE_ITEM_WITH -6
#define SET_POSITION_BLOCK_IMAGE_ITEM_HEIGHT -4
#define SET_SCALE_IMAGE_WITH 0.1
#define SET_SCALE_IMAGE_HEIGHT 0.1

pickUp::pickUp()
{
	/* Creating tank player */
	rect.setSize(Vector2f(SIZE_BLOCK_ITEM_WIDTH, SIZE_BLOCK_ITEM_HEIGHT));
	rect.setFillColor(Color::Green);
	rect.setOrigin(SET_POSITION_BLOCK_IMAGE_ITEM_WITH, SET_POSITION_BLOCK_IMAGE_ITEM_HEIGHT);
	//sprite.setPosition(0, 0);
	//sprite.setTextureRect(IntRect(5, 1, 50, 50));
	/* adjusting size for tank */
	sprite.scale(SET_SCALE_IMAGE_WITH, SET_SCALE_IMAGE_HEIGHT);
	//rect.setPosition(200, 250);
}

void pickUp::update()
{
	/* Updating position for tank player */
	sprite.setPosition(rect.getPosition());
}