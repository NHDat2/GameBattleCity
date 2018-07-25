#include "textDisplay.h"
#include <Windows.h>

#define SIZE_TEXT 30

textDisplay::textDisplay()
{
	//text.setColor(Color::Green);
	text.setCharacterSize(SIZE_TEXT);
	text.setString(myString);
}

void textDisplay::update()
{
	text.move(0, -movementSpeed);

	counter++;
	if (counter >= lifeTimeCounter)
	{
		destroy = true;
	}
}
