#include "CreatPlayer.h"



CreatPlayer::CreatPlayer(Texture* texture, Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(Vector2f(100.0f, 150.0f));
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
	body.scale(0.35f, 0.35f);
}


CreatPlayer::~CreatPlayer()
{
}

void CreatPlayer::update(float deltaTime)
{
	char c;
	Vector2f movement(0.0f, 0.0f);

	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		movement.x -= speed * deltaTime;
		body.setTextureRect(IntRect(0, 32 * 1, 32, 32));
		c = 'a';
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		movement.x += speed * deltaTime;
		body.setTextureRect(IntRect(0, 32 * 2, 32, 32));
		c = 'd';
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		movement.y += speed * deltaTime;
		body.setTextureRect(IntRect(0, 0, 32, 32));
		c = 's';
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		movement.y -= speed * deltaTime;
		body.setTextureRect(IntRect(0, 32 * 3, 32, 32));
		c = 'w';
	}
	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else if (c == 'd' || c == 'a')
	{
		row = 1;

		if (movement.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}
	else if (c == 's' || c == 'w')
	{
		row = 2;

		if (movement.y > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}
	}

	animation.update(row, deltaTime, faceRight, c);
	animation.update2(row, deltaTime, faceRight, c);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void CreatPlayer::draw(RenderWindow& window)
{
	window.draw(body);
}
