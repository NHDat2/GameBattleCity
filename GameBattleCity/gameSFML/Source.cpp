#include <iostream>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <cstdio>

#define SIZE_WALL 18
#define MAX_SIZE_MAP_WIDTH 1858
#define MAX_SIZE_MAP_HEIGHT 1027
#define SET_SCALE_IMAGE_WITH 1
#define SET_SCALE_IMAGE_HEIGHT 1

/* Creating player */
#include "player.h"

/* creating temp player */
#include "entity.h"

/* creating buller */
#include "projecttile.h"

/* creating bots player */
#include "enemy.h"

/* creating fuctions random to move botsplayer */
#include "random.h"

/* Displaying hp and damage attack */
#include "textDisplay.h"

/* Creating events such as eat bullet or coin */
#include "pickUp.h"

/* Creating wall */
//#include "wall.h"
#include "creatMap.h"


#define MAX_WIDTH 1000
#define MAX_HEIGHT 900

using namespace std;
using namespace sf;

/*************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

/* Enemy Collides */
void enemyCollidesWater(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, creatMap &waterr);

void enemyCollidesBrick(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, creatMap &brickk);

void enemyCollidesStone(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, creatMap &stonee);

void enemyCollidesTogether(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<enemy>::const_iterator i5);

void enemyCollides(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<enemy>::const_iterator i5, creatMap &waterr, creatMap &brickk, creatMap &stonee);

/*************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

/* Player Collides */
void playerCollidesWater(player &Player1, creatMap &waterr);

void playerCollidesBrick(player &Player1, creatMap &brickk);

void playerCollidesStone(player &Player1, creatMap &stonee);

void playerCollidesItem(player &Player1, vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i);

bool gameOverr(vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, enemy &eagle, player &Player1);

void playerCollides(player &Player1, creatMap &waterr, creatMap &brickk, creatMap &stonee, vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i);

/*************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

/* Player and enemy take damage */
void takeDamage(player &Player1, vector<enemy>::const_iterator i4, vector<enemy> &enemyArray, Time elapsed2, Clock clock2);

/*************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

/* Projecttile Collides */
void projecttileCollidesBrick(player &Player1, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, creatMap &brickk);

void projecttileCollidesStone(player &Player1, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, creatMap &stonee, Sound &soundCollisionWithStone);

void projecttileCollidesEnemy(textDisplay &textDisplay1, vector<textDisplay> &textDisplayArray, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, player &Player1, SoundBuffer &bufferCollisionWithEnemy, Sound &soundCollisionWithEnemy);

void projecttileCollides(player &Player1, textDisplay &textDisplay1, vector<textDisplay> &textDisplayArray,  vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, class creatMap &brickk, class creatMap &stonee, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, SoundBuffer &bufferCollisionWithEnemy, Sound &soundCollisionWithEnemy, Sound &soundCollisionWithStone);

/*************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

/* Delete */
void deleteProjecttile(vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i);

void deleteEnemy(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<pickUp> &pickUpArrayBullet, vector<pickUp> &pickUpArrayCoin, pickUp &pickUp1, pickUp &pickUp2, vector<enemy> &bloodArray, enemy &blood1, Sound &soundDead);

void deleteBlood(vector<enemy>::const_iterator i30, vector<enemy> &bloodArray);

void deleteTextDisplay(vector<textDisplay> &textDisplayArray, vector<textDisplay>::const_iterator i8);

void deletePickUpItem(vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14, bool &bullet, Sound &soundPickUpCoin, Sound &soundPowerUp);

void deleteBrick(creatMap &brickk, vector<pickUp> &pickUpArrayCoin, vector<pickUp> &pickUpArrayBullet, pickUp &pickUp1, pickUp &pickUp2);

void deletee(vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<pickUp> &pickUpArrayBullet, vector<pickUp> &pickUpArrayCoin, class pickUp &pickUp1, class pickUp &pickUp2, vector<textDisplay> &textDisplayArray, vector<textDisplay>::const_iterator i8, vector<pickUp>::const_iterator i11, vector<pickUp>::const_iterator i14, bool &bullet, class creatMap &brickk, vector<enemy> &bloodArray, vector<enemy>::const_iterator i30, enemy &blood1, Sound &soundPickUpCoin, Sound &soundPowerUp, Sound &soundDead);

/*************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

/* Draw */

void drawWater(RenderWindow &window, creatMap &waterr);

void drawBrick(RenderWindow &window, creatMap &brickk);

void drawStone(RenderWindow &window, creatMap &stonee);

void drawMap(RenderWindow &window, creatMap &waterr, creatMap &brickk, creatMap &stonee, creatMap &glasses);

void drawPickUpItem(RenderWindow &window, vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14);

void drawProjecttile(RenderWindow &window, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, bool bullet);

void drawEnemy(RenderWindow &window, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4);

void drawBlood(RenderWindow &window, vector<enemy>::const_iterator i30, vector<enemy> &bloodArray);

void drawTextDamage(RenderWindow &window, vector<textDisplay> &textDisplayArray, vector<textDisplay>::const_iterator i8);

void drawPoint(RenderWindow &window, player &Player1, Text &text);

void drawEagle(RenderWindow &window, enemy &eagle);

void draw(RenderWindow &window, vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, bool bullet, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<textDisplay> &textDisplayArray, vector<textDisplay>::const_iterator i8, player &Player1, Text &text, creatMap &waterr, creatMap &brickk, creatMap &stonee, creatMap &glasses, vector<enemy>::const_iterator i30, vector<enemy> &bloodArray, enemy &eagle);

/*************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

/* Up date move and position and draw player */
void updateAndDrawPlayer(RenderWindow &window, player &Player1, vector<enemy>::const_iterator i30, vector<enemy> &bloodArray);

/*************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************/

void creatBot(RenderWindow &window, Time &elapsedCreatEnemy, Clock &clockCreatEnemy, int countEnemy, enemy &enemy1, vector<enemy> &enemyArray);

int main()
{
	/* Creating sence window to render image and cosole out sence */
	RenderWindow window(VideoMode(MAX_HEIGHT, MAX_HEIGHT), "Tank 90", Style::Close | Style::Fullscreen);

	/* Set up Speed of Game */
	window.setFramerateLimit(550);

	Clock clock;
	Clock clock2;
	Clock clock3;
	Clock clock4;
	Clock clockCreatEnemy;

	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	int countEnemy = 1;
	int countGameOver = 0;

	/* case player eat pickUp bullet and change bullet */
	bool bullet = false;

	/* Loading image and storing tank */
	Texture spriteSheet;
	Sprite playerSprite;
	if (!(spriteSheet.loadFromFile("data/image/redtank.png")))
	{
		return EXIT_FAILURE;
	}

	/* Loading image bots tank */
	Texture textureEnemy;
	if (!(textureEnemy.loadFromFile("data/image/enemy.png")))
	{
		return EXIT_FAILURE;
	}

	/* Loading image item bullet */
	Texture textureBullet;
	if (!(textureBullet.loadFromFile("data/image/bulletFire.png")))
	{
		return EXIT_FAILURE;
	}
	

	/* Loading image item coin */
	Texture textureCoin;
	if (!(textureCoin.loadFromFile("data/image/coinn.png")))
	{
		return EXIT_FAILURE;
	}

	/* Loading image fire bullet Update */
	Texture textureFireBulletUpdate;
	if (!(textureFireBulletUpdate.loadFromFile("data/image/bulletFire.png")))
	{
		return EXIT_FAILURE;
	}

	/* Load image water */
	Texture textureWater1;
	if (!(textureWater1.loadFromFile("data/image/water4.png")))
	{
		return EXIT_FAILURE;
	}

	/* Load image Stone */
	Texture textureStone;
	if (!(textureStone.loadFromFile("data/image/stone3.png")))
	{
		return EXIT_FAILURE;
	}

	/* Load image Bricks */
	Texture textureBrick;
	if (!(textureBrick.loadFromFile("data/image/Bricks.png")))
	{
		return EXIT_FAILURE;
	}

	Texture textureGlass;
	if (!(textureGlass.loadFromFile("data/image/glass6.png")))
	{
		return EXIT_FAILURE;
	}

	Texture textureEagle;
	if (!(textureEagle.loadFromFile("data/image/eagle.png")))
	{
		return EXIT_FAILURE;
	}

	Texture textureEnemyDead;
	if (!(textureEnemyDead.loadFromFile("data/image/enemyDead.png")))
	{
		return EXIT_FAILURE;
	}

	Texture textturePlayerDead;
	if (!(textturePlayerDead.loadFromFile("data/image/enemyDead.png")))
	{
		return EXIT_FAILURE;
	}

	/* Set graphical text to display */
	Font font;
	if (!font.loadFromFile("data/text/victor-pixel.ttf"))
	{
		return EXIT_FAILURE;
	}

	Texture textureGameOver;
	if (!(textureGameOver.loadFromFile("data/image/gameOver2.png")))
	{
		return EXIT_FAILURE;
	}

	Music music;
	if (!(music.openFromFile("data/sound/musicOfGame.ogg")))
	{
		return EXIT_FAILURE;
	}
	music.play();

	SoundBuffer bufferDead;
	if (!(bufferDead.loadFromFile("data/sound/die.wav")))
	{
		return EXIT_FAILURE;
	}
	Sound soundDead;
	soundDead.setBuffer(bufferDead);

	SoundBuffer bufferShot;
	if (!(bufferShot.loadFromFile("data/sound/shot.ogg")))
	{
		return EXIT_FAILURE;
	}
	Sound soundShot;
	soundShot.setBuffer(bufferShot);

	SoundBuffer bufferCollisionWithEnemy;
	if (!(bufferCollisionWithEnemy.loadFromFile("data/sound/collisionWithEnemy2.ogg")))
	{
		return EXIT_FAILURE;
	}
	Sound soundCollisionWithEnemy;
	soundCollisionWithEnemy.setBuffer(bufferCollisionWithEnemy);

	SoundBuffer bufferPickUpCoin;
	if (!(bufferPickUpCoin.loadFromFile("data/sound/pickUpCoin.ogg")))
	{
		return EXIT_FAILURE;
	}
	Sound soundPickUpCoin;
	soundPickUpCoin.setBuffer(bufferPickUpCoin);
	
	SoundBuffer bufferPowerUp;
	if (!(bufferPowerUp.loadFromFile("data/sound/Powerup.ogg")))
	{
		return EXIT_FAILURE;
	}
	Sound soundPowerUp;
	soundPowerUp.setBuffer(bufferPowerUp);

	SoundBuffer bufferCollisionWithStone;
	if (!(bufferCollisionWithStone.loadFromFile("data/sound/collisionWithStone2.ogg")))
	{
		return EXIT_FAILURE;
	}

	Sound soundCollisionWithStone;
	soundCollisionWithStone.setBuffer(bufferCollisionWithStone);




	Sprite spritePlayer(spriteSheet);
	playerSprite.setTexture(spriteSheet);

	/* Set up first position for tank */
	spritePlayer.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	spritePlayer.setTextureRect(IntRect(0, 0, 28.5f, 28));
		
	/* Create text point */
	Text text("Score : ", font, 25);
	text.setPosition(0, 0);

	/* adjust size for tank */
	spritePlayer.scale(1.8f, 1.8f);
	
	/* Class Object*/
	player Player1;
	Player1.sprite.setTexture(spriteSheet);
	Player1.rect.setPosition(750, 1020);
	/* Projecttile Vector array */
	vector<projecttile>::const_iterator i;
	vector<projecttile> projecttileArray;

	/* projecttile Object store bullet */
	projecttile projecttile1;
	projecttile1.sprite.setTexture(textureFireBulletUpdate);

	/* Enemy Vector array */
	vector<enemy>::const_iterator i4;
	vector<enemy>::const_iterator i5;
	vector<enemy> enemyArray;

	/* enemy object */
	enemy enemy1;
	enemy1.sprite.setTexture(textureEnemy);
	enemy1.rect.setPosition(1500, 75);

	/* adjusting size for tank */
	enemyArray.push_back(enemy1);

	/* Blood vector Array */
	vector<enemy>::const_iterator i30;
	vector<enemy> bloodArray;

	/* blood object */
	enemy blood1;
	blood1.isBlood = true;
	blood1.sprite.setTexture(textureEnemyDead);
	blood1.sprite.scale(0.08, 0.08);
	blood1.sprite.setOrigin(700, 150);

	/* Text Vector array */
	vector<textDisplay>::const_iterator i8;
	vector<textDisplay> textDisplayArray;

	/* Text display object */
	textDisplay textDisplay1;
	textDisplay1.text.setFont(font);
	
	/* creat object water */
	creatMap waterr;
	waterr.Water1.sprite.setTexture(textureWater1);
	waterr.Water2.sprite.setTexture(textureWater1);

	/* creat object brickk */
	creatMap brickk;
	brickk.brick.sprite.setTexture(textureBrick);
	
	/* creat object stone */
	creatMap stonee;
	stonee.stone.sprite.setTexture(textureStone);

	creatMap glasses;
	glasses.glass.sprite.setTexture(textureGlass);
	
	/* creat map with stone, brick and water */
	stonee.creatStone();
	brickk.creatBrick();
	waterr.creatWater();
	glasses.creatGlass();

	/* pickUp bullet Vector array */
	vector<pickUp>::const_iterator i11;
	vector<pickUp> pickUpArrayBullet;

	/* item Bullet object */
	pickUp pickUp1;
	pickUp1.sprite.setTexture(textureBullet);

	/* pickUp coin Vector array */
	vector<pickUp>::const_iterator i14;
	vector<pickUp> pickUpArrayCoin;

	/* item coin object */
	pickUp pickUp2;
	pickUp2.sprite.setTexture(textureCoin);

	enemy eagle;
	eagle.sprite.setTexture(textureEagle);
	eagle.sprite.scale(0.1, 0.1);
	eagle.sprite.setOrigin(550, 250);
	eagle.rect.setPosition(890, 1020);

	wall gameOver;
	gameOver.sprite.setTexture(textureGameOver);
	//gameOver.sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	gameOver.sprite.setOrigin(400, 0);
	gameOver.sprite.scale(2, 1.2);
	/* Starting Looping Game */
	while (window.isOpen())
	{
		Event evnt;
		/* Condition to exit */
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
		}
		
		/* Creating Back-Ground for console seen */
		window.clear(Color::Black);

		/* Clock */
		Time elapsed1 = clock.getElapsedTime();
		Time elapsed2 = clock2.getElapsedTime();
		Time elapsed3 = clock3.getElapsedTime();
		Time elapsed4 = clock4.getElapsedTime();
		Time elapsedCreatEnemy = clockCreatEnemy.getElapsedTime();

		/* Enemy Collides Wall */
		enemyCollides(enemyArray, i4, i5, waterr, brickk, stonee);

		/* Player collides */
		playerCollides(Player1, waterr, brickk, stonee, pickUpArrayBullet, i11, pickUpArrayCoin, i14, projecttileArray, i);

		/* Player and enemy take damage */
		takeDamage(Player1, i4, enemyArray, elapsed2, clock2);

		/* Projecttile Collides */
		projecttileCollides(Player1, textDisplay1, textDisplayArray, projecttileArray, i, brickk, stonee, enemyArray, i4, bufferCollisionWithEnemy, soundCollisionWithEnemy, soundCollisionWithStone);
		
		/* Delete object */
		deletee(projecttileArray, i, enemyArray, i4, pickUpArrayBullet, pickUpArrayCoin, pickUp1, pickUp2, textDisplayArray, i8, i11, i14, bullet, brickk, bloodArray, i30, blood1, soundPickUpCoin, soundPowerUp, soundDead);

		

		/* Creating Bot */
		creatBot(window, elapsedCreatEnemy, clockCreatEnemy, countEnemy, enemy1, enemyArray);
		/* enemy counterattack and tagged Player */
		int counter, counter2;
		counter = 0;
		for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
		{
			if (enemyArray[counter].aggroed == true)
			{
				if (elapsed3.asSeconds() >= 0.2)
				{
					clock3.restart();
					int tempRand = generateRandom(3);
					if (tempRand == 1)
					{
						projecttile1.attackDamage = enemyArray[counter].attackDamege;
						/* Player to Right */
						if ((Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
						{
							projecttile1.enemyProjecttile = true;
							projecttile1.direction = 3;
							projecttile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2 - projecttile1.rect.getSize().x / 2
								, enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y / 2 - projecttile1.rect.getSize().y / 2);
							projecttileArray.push_back(projecttile1);
							projecttile1.enemyProjecttile = false;
							enemyArray[counter].direction2 = 3;
						}

						/* Player to Left */
						if ((Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
						{
							projecttile1.enemyProjecttile = true;
							projecttile1.direction = 4;
							projecttile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2 - projecttile1.rect.getSize().x / 2
								, enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y / 2 - projecttile1.rect.getSize().y / 2);
							projecttileArray.push_back(projecttile1);
							projecttile1.enemyProjecttile = false;
							enemyArray[counter].direction2 = 4;
						}

						/* Player to Up */
						if ((Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y) && (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
						{
							projecttile1.enemyProjecttile = true;
							projecttile1.direction = 1;
							projecttile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2 - projecttile1.rect.getSize().x / 2
								, enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y / 2 - projecttile1.rect.getSize().y / 2);
							projecttileArray.push_back(projecttile1);
							projecttile1.enemyProjecttile = false;
							enemyArray[counter].direction2 = 1;
						}

						/* Player to Down */
						if ((Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y) && (abs(Player1.rect.getPosition().x - enemyArray[counter].rect.getPosition().x) <= 40))
						{
							projecttile1.enemyProjecttile = true;
							projecttile1.direction = 2;
							projecttile1.rect.setPosition(enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2 - projecttile1.rect.getSize().x / 2
								, enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y / 2 - projecttile1.rect.getSize().y / 2);
							projecttileArray.push_back(projecttile1);
							projecttile1.enemyProjecttile = false;
							enemyArray[counter].direction2 = 2;
						}
					}
					/* Enemy chasas Player */
					else if (tempRand == 2)
					{
						if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction2 = 1;
						}
						else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction2 = 2;
						}
						else if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction2 = 3;
						}
						else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction2 = 4;
						}
					}
					/* Enemy chasas Player */
					else
					{
						if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction2 = 3;
						}
						else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction2 = 4;
						}
						else if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction2 = 1;
						}
						else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction2 = 2;
						}

					}
				}
			}
			counter++;
		}



		/* Exit game */
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			return EXIT_FAILURE;
		}

		if (elapsed1.asSeconds() >= 0.2)
		{
			clock.restart();
			if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::K))
			{
				soundShot.play();
				projecttile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projecttile1.rect.getSize().x / 2, Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projecttile1.rect.getSize().y / 2);
				projecttile1.direction = Player1.direction;
				projecttileArray.push_back(projecttile1);
				window.setFramerateLimit(400);
			}
		}

		bool checkGameOver = gameOverr(projecttileArray, i, eagle, Player1);
		if (!(checkGameOver))
		{
			music.pause();
			if (countGameOver <= 1)
			{
				Sleep(200);
				soundDead.play();
				Sleep(800);
			}
			window.draw(gameOver.sprite);
			/* Draw Point */
			drawPoint(window, Player1, text);
			countGameOver = 2;
		}

		
		else
		{
		
			/* Update Player */
			updateAndDrawPlayer(window, Player1, i30, bloodArray);

			/* Draw Water */
			drawWater(window, waterr);
			/* Draw out the window */
			draw(window, pickUpArrayBullet, i11, pickUpArrayCoin, i14, projecttileArray, i, bullet, enemyArray, i4, textDisplayArray, i8, Player1, text, waterr, brickk, stonee, glasses, i30, bloodArray, eagle);
		}
		
	}
	return 0;
}

void enemyCollidesWater(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, creatMap &waterr)
{
	int counter, counter2;
	counter = 0;
	for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
	{
		counter2 = 0;
		for (waterr.i17 = waterr.wallArrayWater1.begin(); waterr.i17 != waterr.wallArrayWater1.end(); waterr.i17++)
		{
			if (enemyArray[counter].rect.getGlobalBounds().intersects(waterr.wallArrayWater1[counter2].rect.getGlobalBounds()))
			{
				/* Hitting wall */
				//srand(time(0));
				//enemyArray[counter].direction2 = rand() % 4 + 1;
				//enemyArray[counter].direction2 = rand() % 4 + 1;
				
				if (enemyArray[counter].direction2 == 1) /* Up */
				{
					enemyArray[counter].canMoveUp = false;
					enemyArray[counter].rect.move(0, 0.05f);
				//	enemyArray[counter].direction2 = 4;
				}
				else if (enemyArray[counter].direction2 == 2) /* Down */
				{
					enemyArray[counter].canMoveDown = false;
					enemyArray[counter].rect.move(0, -0.05f);
				//	enemyArray[counter].direction2 = 3;
				}
				else if (enemyArray[counter].direction2 == 3) /* Left */
				{
					enemyArray[counter].canMoveLeft = false;
					enemyArray[counter].rect.move(0.05f, 0);
				//	enemyArray[counter].direction2 = 2;
				}
				else if (enemyArray[counter].direction2 == 4) /* Right */
				{
					enemyArray[counter].canMoveRight = false;
					enemyArray[counter].rect.move(-0.05f, 0);
				//	enemyArray[counter].direction2 = 1;
				}
				else
				{
					/* Don't anything */
				}	
			}
			counter2++;
		}
		counter++;
	}
}

void enemyCollidesBrick(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, creatMap &brickk)
{
	int counter, counter2;
	counter = 0;
	for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
	{
		counter2 = 0;
		for (brickk.i23 = brickk.wallArrayBrick.begin(); brickk.i23 != brickk.wallArrayBrick.end(); brickk.i23++)
		{
			if (enemyArray[counter].rect.getGlobalBounds().intersects(brickk.wallArrayBrick[counter2].rect.getGlobalBounds()))
			{
				/* Hitting wall */				
				if (enemyArray[counter].direction2 == 1) /* Up */
				{
					enemyArray[counter].canMoveUp = false;
					enemyArray[counter].rect.move(0, 0.05f);
				}
				else if (enemyArray[counter].direction2 == 2) /* Down */
				{
					enemyArray[counter].canMoveDown = false;
					enemyArray[counter].rect.move(0, -0.05f);
				}
				else if (enemyArray[counter].direction2 == 3) /* Left */
				{
					enemyArray[counter].canMoveLeft = false;
					enemyArray[counter].rect.move(0.05f, 0);
				}
				else if (enemyArray[counter].direction2 == 4) /* Right */
				{
					enemyArray[counter].canMoveRight = false;
					enemyArray[counter].rect.move(-0.05f, 0);
				}
				else
				{
					/* Don't anything */
				}
			}
			counter2++;
		}
		counter++;
	}
}

void enemyCollidesStone(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, creatMap &stonee)
{
	int counter, counter2;
	counter = 0;
	for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
	{
		counter2 = 0;
		for (stonee.i27 = stonee.wallArrayStone.begin(); stonee.i27 != stonee.wallArrayStone.end(); stonee.i27++)
		{
			if (enemyArray[counter].rect.getGlobalBounds().intersects(stonee.wallArrayStone[counter2].rect.getGlobalBounds()))
			{
				/* Hitting wall */
				if (enemyArray[counter].direction2 == 1) /* Up */
				{
					enemyArray[counter].canMoveUp = false;
					enemyArray[counter].rect.move(0, 0.05f);			
				}
				else if (enemyArray[counter].direction2 == 2) /* Down */
				{
					enemyArray[counter].canMoveDown = false;
					enemyArray[counter].rect.move(0, -0.05f);
				}
				else if (enemyArray[counter].direction2 == 3) /* Left */
				{
					enemyArray[counter].canMoveLeft = false;
					enemyArray[counter].rect.move(0.05f, 0);
				}
				else if (enemyArray[counter].direction2 == 4) /* Right */
				{
					enemyArray[counter].canMoveRight = false;
					enemyArray[counter].rect.move(-0.05f, 0);
				}
				else
				{
					/* Don't anything */
				}
			}
			counter2++;
		}
		counter++;
	}
}

void enemyCollidesTogether(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<enemy>::const_iterator i5)
{
	int counter, counter2;
	counter = 0;
	for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
	{

		counter2 = 0;
		for (i5 = enemyArray.begin(); i5 != enemyArray.end(); i5++)
		{
			if (enemyArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()) == true && counter != counter2)
			{
				if (enemyArray[counter].direction2 == 1)
				{
					enemyArray[counter].canMoveUp = false;
					enemyArray[counter].rect.move(0, 0.05f);
				}
				else if (enemyArray[counter].direction2 == 2)
				{
					enemyArray[counter].canMoveDown = false;
					enemyArray[counter].rect.move(0, -0.05f);
				}
				else if (enemyArray[counter].direction2 == 3)
				{
					enemyArray[counter].canMoveLeft = false;
					enemyArray[counter].rect.move(0.05f, 0);
				}
				else if (enemyArray[counter].direction2 == 4)
				{
					enemyArray[counter].canMoveRight = false;
					enemyArray[counter].rect.move(-0.05f, 0);
				}
				else
				{

				}
				if (enemyArray[counter2].direction2 == 1)
				{
					enemyArray[counter2].canMoveUp = false;
					enemyArray[counter2].rect.move(0, 0.05f);
				}
				else if (enemyArray[counter2].direction2 == 2)
				{
					enemyArray[counter2].canMoveDown = false;
					enemyArray[counter2].rect.move(0, -0.05f);
				}
				else if (enemyArray[counter2].direction2 == 3)
				{
					enemyArray[counter2].canMoveLeft = false;
					enemyArray[counter2].rect.move(0.05f, 0);
				}
				else if (enemyArray[counter2].direction2 == 4)
				{
					enemyArray[counter2].canMoveRight = false;
					enemyArray[counter2].rect.move(-0.05f, 0);
				}
				else
				{

				}

			}
			counter2++;
		}
		counter++;
	}
}

void enemyCollides(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<enemy>::const_iterator i5, creatMap &waterr, creatMap &brickk, creatMap &stonee)
{
	/* Enemy collides with water */
	enemyCollidesWater(enemyArray, i4, waterr);

	/* Enemy collides with brick */
	enemyCollidesBrick(enemyArray, i4, brickk);

	/* Enemy collides with stone */
	enemyCollidesStone(enemyArray, i4, stonee);

	/* Enemy collides together*/
	enemyCollidesTogether(enemyArray, i4, i5);
}

void playerCollidesWater(player &Player1, creatMap &waterr)
{
	int counter;
	counter = 0;
	for (waterr.i17 = waterr.wallArrayWater1.begin(); waterr.i17 != waterr.wallArrayWater1.end(); waterr.i17++)
	{
		/* Check duplication of 2 object is that Player and wall */
		if (Player1.rect.getGlobalBounds().intersects(waterr.wallArrayWater1[counter].rect.getGlobalBounds()))
		{
			/* Hitting wall */
			if (Player1.direction == 1) /* Up */
			{
				Player1.canMoveUp = false;
				Player1.rect.move(0, 0.05f);
			}
			else if (Player1.direction == 2) /* Down */
			{
				Player1.canMoveDown = false;
				Player1.rect.move(0, -0.05f);
			}
			else if (Player1.direction == 3) /* Left */
			{
				Player1.canMoveLeft = false;
				Player1.rect.move(0.05f, 0);
			}
			else if (Player1.direction == 4) /* Right */
			{
				Player1.canMoveRight = false;
				Player1.rect.move(-0.05f, 0);
			}
			else
			{
				/* Don't anything */
			}
		}
		counter++;
	}
}

void playerCollidesBrick(player &Player1, creatMap &brickk)
{
	int counter;
	counter = 0;
	for (brickk.i23 = brickk.wallArrayBrick.begin(); brickk.i23 != brickk.wallArrayBrick.end(); brickk.i23++)
	{
		/* Check duplication of 2 object is that Player and wall */
		if (Player1.rect.getGlobalBounds().intersects(brickk.wallArrayBrick[counter].rect.getGlobalBounds()))
		{
			/* Hitting wall */
			if (Player1.direction == 1) /* Up */
			{
				Player1.canMoveUp = false;
				Player1.rect.move(0, 0.05f);
			}
			else if (Player1.direction == 2) /* Down */
			{
				Player1.canMoveDown = false;
				Player1.rect.move(0, -0.05f);
			}
			else if (Player1.direction == 3) /* Left */
			{
				Player1.canMoveLeft = false;
				Player1.rect.move(0.05f, 0);
			}
			else if (Player1.direction == 4) /* Right */
			{
				Player1.canMoveRight = false;
				Player1.rect.move(-0.05f, 0);
			}
			else
			{
				/* Don't anything */
			}
		}
		counter++;
	}
}

void playerCollidesStone(player &Player1, creatMap &stonee)
{
	int counter;
	counter = 0;
	for (stonee.i27 = stonee.wallArrayStone.begin(); stonee.i27 != stonee.wallArrayStone.end(); stonee.i27++)
	{
		/* Check duplication of 2 object is that Player and wall */
		if (Player1.rect.getGlobalBounds().intersects(stonee.wallArrayStone[counter].rect.getGlobalBounds()))
		{
			/* Hitting wall */
			if (Player1.direction == 1) /* Up */
			{
				Player1.canMoveUp = false;
				Player1.rect.move(0, 0.05f);
			}
			else if (Player1.direction == 2) /* Down */
			{
				Player1.canMoveDown = false;
				Player1.rect.move(0, -0.05f);
			}
			else if (Player1.direction == 3) /* Left */
			{
				Player1.canMoveLeft = false;
				Player1.rect.move(0.05f, 0);
			}
			else if (Player1.direction == 4) /* Right */
			{
				Player1.canMoveRight = false;
				Player1.rect.move(-0.05f, 0);
			}
			else
			{
				/* Don't anything */
			}
		}
		counter++;
	}
}

void playerCollidesItem(player &Player1, vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i)
{
	int counter, counter2;
	counter = 0;
	for (i11 = pickUpArrayBullet.begin(); i11 != pickUpArrayBullet.end(); i11++)
	{
		/* Check duplication of 2 object is that player and item bullet */
		if (Player1.rect.getGlobalBounds().intersects(pickUpArrayBullet[counter].rect.getGlobalBounds()))
		{
			if (pickUpArrayBullet[counter].bullet == true)
			{
				Player1.gil1 += pickUpArrayBullet[counter].bulletValue;
			}
			pickUpArrayBullet[counter].destroyBullet = true;
			counter2 = 0;
			for (i = projecttileArray.begin(); i != projecttileArray.end(); i++)
			{
				projecttileArray[counter2].attackDamage = 6;
				counter2++;
			}
		}
		counter++;
	}
	/* Player collides with pickUp Items coin */
	counter = 0;
	for (i14 = pickUpArrayCoin.begin(); i14 != pickUpArrayCoin.end(); i14++)
	{
		/* Check duplication of 2 object is that player and item coin */
		if (Player1.rect.getGlobalBounds().intersects(pickUpArrayCoin[counter].rect.getGlobalBounds()))
		{
			if (pickUpArrayCoin[counter].bullet == true)
			{
				Player1.gil1 += pickUpArrayCoin[counter].coinValue;
			}
			pickUpArrayCoin[counter].destroyCoin = true;
		}
		counter++;
	}
}

void playerCollides(player &Player1, creatMap &waterr, creatMap &brickk, creatMap &stonee, vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i)
{
	/* Player Collides with water */
	playerCollidesWater(Player1, waterr);

	/* Player Collides with Bricks */
	playerCollidesBrick(Player1, brickk);

	/* Player Collides with Stone */
	playerCollidesStone(Player1, stonee);

	/* Player collides with pickUp Items bullet */
	playerCollidesItem(Player1, pickUpArrayBullet, i11, pickUpArrayCoin, i14, projecttileArray, i);
}

void takeDamage(player &Player1, vector<enemy>::const_iterator i4, vector<enemy> &enemyArray, Time elapsed2, Clock clock2)
{
	int counter = 0;
	if (elapsed2.asSeconds() >= 0.15)
	{
		clock2.restart();
		/* Enemy collides with Player and Player takes damage */
		counter = 0;
		for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
		{
			if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
			{
				Player1.hp -= enemyArray[counter].attackDamege;
			}
			counter++;
		}
	}
}

void projecttileCollidesBrick(player &Player1, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, creatMap &brickk)
{
	int counter, counter2;
	counter = 0;
	for (i = projecttileArray.begin(); i != projecttileArray.end(); i++)
	{
		counter2 = 0;
		for (brickk.i23 = brickk.wallArrayBrick.begin(); brickk.i23 != brickk.wallArrayBrick.end(); brickk.i23++)
		{
			/* Check duplication of 2 object is that projectile and wall */
			if (projecttileArray[counter].rect.getGlobalBounds().intersects(brickk.wallArrayBrick[counter2].rect.getGlobalBounds()))
			{
				projecttileArray[counter].destroy = 1;
				if (brickk.wallArrayBrick[counter2].destructable == 1)
				{
					brickk.wallArrayBrick[counter2].hp -= Player1.attackDamage;
					if (brickk.wallArrayBrick[counter2].hp <= 0)
					{
						brickk.wallArrayBrick[counter2].destroy = 1;
					}
				}
			}
			counter2++;
		}
		counter++;
	}
}

void projecttileCollidesStone(player &Player1, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, creatMap &stonee, Sound &soundCollisionWithStone)
{
	int counter, counter2;
	counter = 0;
	for (i = projecttileArray.begin(); i != projecttileArray.end(); i++)
	{
		counter2 = 0;
		for (stonee.i27 = stonee.wallArrayStone.begin(); stonee.i27 != stonee.wallArrayStone.end(); stonee.i27++)
		{
			/* Check duplication of 2 object is that projectile and wall */
			if (projecttileArray[counter].rect.getGlobalBounds().intersects(stonee.wallArrayStone[counter2].rect.getGlobalBounds()))
			{
				soundCollisionWithStone.play();
				projecttileArray[counter].destroy = 1;
				if (stonee.wallArrayStone[counter2].destructable == 1)
				{
					stonee.wallArrayStone[counter2].hp -= Player1.attackDamage;
					if (stonee.wallArrayStone[counter2].hp <= 0)
					{
						stonee.wallArrayStone[counter2].destroy = 1;
					}
				}
			}
			counter2++;
		}
		counter++;
	}
}

bool gameOverr(vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, enemy &eagle, player &Player1)
{
	int counter;
	counter = 0;
	for (i = projecttileArray.begin(); i != projecttileArray.end(); i++)
	{
		if (projecttileArray[counter].rect.getGlobalBounds().intersects(eagle.rect.getGlobalBounds()))
		{
			eagle.eagleAlive = false;
			projecttileArray[counter].destroy = true;
				
		}
		counter++;
	}
	bool checkGameOver = true;
	if (Player1.hp < 0)
	{
		Player1.alive = true;
		checkGameOver = false;
	}
	bool check = true;
	if (eagle.eagleAlive == false || checkGameOver == false)
	{
		check = false;
	}
	return check;
}


void projecttileCollidesEnemy(textDisplay &textDisplay1, vector<textDisplay> &textDisplayArray, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, player &Player1, SoundBuffer &bufferCollisionWithEnemy, Sound &soundCollisionWithEnemy)
{
	int counter, counter2;
	counter = 0;
	/* In here having a error is that when type Space to fire is maded the speed of tank player and tank bots decrese */
	for (i = projecttileArray.begin(); i != projecttileArray.end(); i++)
	{
		counter2 = 0;
		for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
		{
	
			if (projecttileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
			{
				if (projecttileArray[counter].enemyProjecttile == false)
				{
					soundCollisionWithEnemy.play();
					projecttileArray[counter].destroy = true;

					/* Text Display */
					textDisplay1.text.setString(to_string(projecttileArray[counter].attackDamage));
					textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x, enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y / 2);
					textDisplayArray.push_back(textDisplay1);
					enemyArray[counter2].hp -= projecttileArray[counter].attackDamage;
					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
					}
					/* Aggro */
					enemyArray[counter2].aggroed = true;
				}
			}
			counter2++;
		}
		counter++;
	}



	/* Enemy projecttile collides with player */
	counter = 0;
	/* In here having a error is that when type Space to fire is maded the speed of tank player and tank bots decrese */
	for (i = projecttileArray.begin(); i != projecttileArray.end(); i++)
	{
		if (projecttileArray[counter].enemyProjecttile == true)
		{
			if (projecttileArray[counter].rect.getGlobalBounds().intersects(Player1.rect.getGlobalBounds()))
			{
				Player1.hp -= projecttileArray[counter].attackDamage;
				/* Text Display */
				textDisplay1.text.setString(to_string(projecttileArray[counter].attackDamage));
				textDisplay1.text.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x, Player1.rect.getPosition().y - Player1.rect.getSize().y / 2);
				textDisplayArray.push_back(textDisplay1);
				projecttileArray[counter].destroy = true;
			}
		}
		counter++;
	}
}

void projecttileCollides(player &Player1, textDisplay &textDisplay1, vector<textDisplay> &textDisplayArray, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, class creatMap &brickk, class creatMap &stonee, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, SoundBuffer &bufferCollisionWithEnemy, Sound &soundCollisionWithEnemy, Sound &soundCollisionWithStone)
{
	/* Projecttile collides with wall */
	projecttileCollidesBrick(Player1, projecttileArray, i, brickk);

	/* Projecttile collides with stone */
	projecttileCollidesStone(Player1, projecttileArray, i, stonee, soundCollisionWithStone);


	/* Projecttile collides with Enemy */
	projecttileCollidesEnemy(textDisplay1, textDisplayArray, projecttileArray, i, enemyArray, i4, Player1, bufferCollisionWithEnemy, soundCollisionWithEnemy);
}

void deleteProjecttile(vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i)
{
	int counter;
	counter = 0;
	for (i = projecttileArray.begin(); i != projecttileArray.end(); i++)
	{
		if (projecttileArray[counter].destroy == true)
		{
			projecttileArray.erase(i);
			break;
		}
		counter++;
	}
}

void deleteEnemy(vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<pickUp> &pickUpArrayBullet, vector<pickUp> &pickUpArrayCoin, pickUp &pickUp1, pickUp &pickUp2, vector<enemy> &bloodArray, enemy &blood1, Sound &soundDead)
{
	int counter;
	counter = 0;
	for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
	{
		if (enemyArray[counter].alive == false)
		{
			/* drop item when bot tank die */
			if (generateRandom(15) == 1)
			{
				pickUp1.rect.setPosition(enemyArray[counter].rect.getPosition());
				pickUp1.rect.setOrigin(-60, -45);
				pickUp1.rect.scale(0.3, 0.3);
				pickUpArrayBullet.push_back(pickUp1);

			}
			else if (generateRandom(5) == 2)
			{
				pickUp2.rect.setPosition(enemyArray[counter].rect.getPosition());
				pickUpArrayCoin.push_back(pickUp2);
			}

			/* create enemy blood stain */
			blood1.rect.setPosition(enemyArray[counter].rect.getPosition());
			bloodArray.push_back(blood1);
			soundDead.play();
			enemyArray.erase(i4);
			break;
		}
		counter++;
	}

}

void deleteBlood(vector<enemy>::const_iterator i30, vector<enemy> &bloodArray)
{
	int counter;
	counter = 0;
	for (i30 = bloodArray.begin(); i30 != bloodArray.end(); i30++)
	{
		if (bloodArray[counter].alive == false)
		{
			bloodArray.erase(i30);
			break;
		}
		counter++;
	}
}


void deleteTextDisplay(vector<textDisplay> &textDisplayArray, vector<textDisplay>::const_iterator i8)
{
	int counter;
	counter = 0;
	for (i8 = textDisplayArray.begin(); i8 != textDisplayArray.end(); i8++)
	{
		if (textDisplayArray[counter].destroy == true)
		{
			textDisplayArray.erase(i8);
			break;
		}
		counter++;
	}
}

void deletePickUpItem(vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14, bool &bullet, Sound &soundPickUpCoin, Sound &soundPowerUp)
{
	int counter;
	counter = 0;
	for (i11 = pickUpArrayBullet.begin(); i11 != pickUpArrayBullet.end(); i11++)
	{
		if (pickUpArrayBullet[counter].destroyBullet == true)
		{
			soundPowerUp.play();
			bullet = true;
			pickUpArrayBullet.erase(i11);
			break;
		}
		counter++;
	}

	counter = 0;
	for (i14 = pickUpArrayCoin.begin(); i14 != pickUpArrayCoin.end(); i14++)
	{
		if (pickUpArrayCoin[counter].destroyCoin == true)
		{
			soundPickUpCoin.play();
			pickUpArrayCoin.erase(i14);
			break;
		}
		counter++;
	}
}

void deleteBrick(creatMap &brickk, vector<pickUp> &pickUpArrayCoin, vector<pickUp> &pickUpArrayBullet, pickUp &pickUp1, pickUp &pickUp2)
{
	int counter;
	counter = 0;
	int x_pickUp, y_pickUp;
	int ranDom_coin_drop = generateRandom(10);
	int ranDom_bullet_drop = generateRandom(30);
	for (brickk.i23 = brickk.wallArrayBrick.begin(); brickk.i23 != brickk.wallArrayBrick.end(); brickk.i23++)
	{
		if (brickk.wallArrayBrick[counter].destroy == 1)
		{
			/* Drop coin */
			if (ranDom_coin_drop == 2)
			{
				x_pickUp = rand() % 700 + 1;
				y_pickUp = rand() % 800 + 1;
				pickUp2.rect.setPosition(x_pickUp, y_pickUp);
				pickUpArrayCoin.push_back(pickUp2);
				brickk.wallArrayBrick.erase(brickk.i23);
				break;
			}
			/* Drop bullet */
			else if (ranDom_bullet_drop == 8)
			{
				x_pickUp = rand() % 1200 + 1;
				y_pickUp = rand() % 700 + 1;
				pickUp1.rect.setPosition(x_pickUp, y_pickUp);
				pickUpArrayBullet.push_back(pickUp1);
				brickk.wallArrayBrick.erase(brickk.i23);
				break;
			}
			brickk.wallArrayBrick.erase(brickk.i23);
			break;
		}
		counter++;
	}
}

void deletee(vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<pickUp> &pickUpArrayBullet, vector<pickUp> &pickUpArrayCoin, class pickUp &pickUp1, class pickUp &pickUp2, vector<textDisplay> &textDisplayArray, vector<textDisplay>::const_iterator i8, vector<pickUp>::const_iterator i11, vector<pickUp>::const_iterator i14, bool &bullet, class creatMap &brickk, vector<enemy> &bloodArray, vector<enemy>::const_iterator i30, enemy &blood1, Sound &soundPickUpCoin, Sound &soundPowerUp, Sound &soundDead)
{
	/* Delete Projecttile*/
	deleteProjecttile(projecttileArray, i);

	/* Deleting enemy */
	deleteEnemy(enemyArray, i4, pickUpArrayBullet, pickUpArrayCoin, pickUp1, pickUp2, bloodArray, blood1, soundDead);

	/* Deleting Text Display */
	deleteTextDisplay(textDisplayArray, i8);

	/* Delete pickUp Items */
	deletePickUpItem(pickUpArrayBullet, i11, pickUpArrayCoin, i14, bullet, soundPickUpCoin, soundPowerUp);

	/* Delete Bricks */
	deleteBrick(brickk, pickUpArrayCoin, pickUpArrayBullet, pickUp1, pickUp2);

	deleteBlood(i30, bloodArray);
}

void drawWater(RenderWindow &window, creatMap &waterr)
{
	int counter;
	counter = 0;
	for (waterr.i17 = waterr.wallArrayWater1.begin(); waterr.i17 != waterr.wallArrayWater1.end(); waterr.i17++)
	{
		waterr.wallArrayWater1[counter].update();
		waterr.wallArrayWater2[counter].update();
		window.draw(waterr.wallArrayWater1[counter].sprite);
		int timeChangeImage = generateRandom(2);
		if (timeChangeImage == 1)
		{
			//window.draw(waterr.wallArrayWater1[counter].rect);
			window.draw(waterr.wallArrayWater1[counter].sprite);
		}
		else
		{
			//window.draw(waterr.wallArrayWater2[counter].rect);
			window.draw(waterr.wallArrayWater2[counter].sprite);
		}

		counter++;
	}
}

void drawBrick(RenderWindow &window, creatMap &brickk)
{
	int counter;
	counter = 0;
	for (brickk.i23 = brickk.wallArrayBrick.begin(); brickk.i23 != brickk.wallArrayBrick.end(); brickk.i23++)
	{
		brickk.wallArrayBrick[counter].update();
		window.draw(brickk.wallArrayBrick[counter].sprite);
		//window.draw(brickk.wallArrayBrick[counter].rect);
		counter++;
	}

}

void drawStone(RenderWindow &window, creatMap &stonee)
{
	int counter;
	counter = 0;
	for (stonee.i27 = stonee.wallArrayStone.begin(); stonee.i27 != stonee.wallArrayStone.end(); stonee.i27++)
	{
		stonee.wallArrayStone[counter].update();
		window.draw(stonee.wallArrayStone[counter].sprite);
		//window.draw4(stonee.wallArrayStone[counter].rect);
		counter++;
	}
}

void drawGlass(RenderWindow &window, creatMap &glasses)
{
	int counter;
	counter = 0;
	for (glasses.i29 = glasses.wallArrayGlass.begin(); glasses.i29 != glasses.wallArrayGlass.end(); glasses.i29++)
	{
		glasses.wallArrayGlass[counter].update();
		window.draw(glasses.wallArrayGlass[counter].sprite);
		//window.draw(glasses.wallArrayGlass[counter].rect);
		counter++;
	}
}

void drawMap(RenderWindow &window, creatMap &waterr, creatMap &brickk, creatMap &stonee, creatMap &glasses)
{
	/* Draw Water */
	//drawWater(window, waterr);

	/* Draw Brick */
	drawBrick(window, brickk);

	/* Draw Stone */
	drawStone(window, stonee);

	/* Draw Glass */
	drawGlass(window, glasses);
}

void drawPickUpItem(RenderWindow &window, vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14)
{
	int counter;
	counter = 0;
	for (i11 = pickUpArrayBullet.begin(); i11 != pickUpArrayBullet.end(); i11++)
	{
		pickUpArrayBullet[counter].update();
		//window.draw(pickUpArrayBullet[counter].rect);
		window.draw(pickUpArrayBullet[counter].sprite);
		counter++;
	}

	/* Draw pickUp Items */
	counter = 0;
	for (i14 = pickUpArrayCoin.begin(); i14 != pickUpArrayCoin.end(); i14++)
	{
		pickUpArrayCoin[counter].update();
		//window.draw(pickUpArrayCoin[counter].rect);
		window.draw(pickUpArrayCoin[counter].sprite);
		counter++;
	}
}

void drawProjecttile(RenderWindow &window, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, bool bullet)
{
	int counter;
	counter = 0;
	for (i = projecttileArray.begin(); i != projecttileArray.end(); i++)
	{
		projecttileArray[counter].update();

		if (bullet == false)
		{
			window.draw(projecttileArray[counter].rect);
		}
		else if (bullet == true)
		{
			window.draw(projecttileArray[counter].sprite);
		}
		counter++;
	}
}

void drawEnemy(RenderWindow &window, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4)
{
	int counter;
	counter = 0;
	for (i4 = enemyArray.begin(); i4 != enemyArray.end(); i4++)
	{
		enemyArray[counter].update();
		enemyArray[counter].updateMovement();
		//window.draw(enemyArray[counter].rect);
		window.draw(enemyArray[counter].sprite);
		counter++;
	}
}

void drawBlood(RenderWindow &window, vector<enemy>::const_iterator i30, vector<enemy> &bloodArray)
{
	int counter;
	counter = 0;
	for (i30 = bloodArray.begin(); i30 != bloodArray.end(); i30++)
	{
		bloodArray[counter].update();
		window.draw(bloodArray[counter].sprite);
		//window.draw(bloodArray[counter].rect);
		counter++;
	}
}

void updateAndDrawPlayer(RenderWindow &window, player &Player1, vector<enemy>::const_iterator i30, vector<enemy> &bloodArray)
{
	Player1.update();
	//Player2.update();
	
	if (Player1.alive == false)
	{
		Player1.updateMovement();
		window.draw(Player1.sprite);
	}
	else
	{
		int counter;
		counter = 0;
		for (i30 = bloodArray.begin(); i30 != bloodArray.end(); i30++)
		{
			bloodArray[counter].update();
			window.draw(bloodArray[counter].sprite);
			window.draw(bloodArray[counter].rect);
			counter++;
		}
	}
}

void drawTextDamage(RenderWindow &window, vector<textDisplay> &textDisplayArray, vector<textDisplay>::const_iterator i8)
{
	int counter;
	counter = 0;
	for (i8 = textDisplayArray.begin(); i8 != textDisplayArray.end(); i8++)
	{
		textDisplayArray[counter].update();
		window.draw(textDisplayArray[counter].text);
		counter++;
	}
}

void drawPoint(RenderWindow &window, player &Player1, Text &text)
{
	text.setString("Score : " + to_string(Player1.gil1));
	window.draw(text);
	window.display();
}

void drawEagle(RenderWindow &window, enemy &eagle)
{
	eagle.update();
	window.draw(eagle.sprite);
	//window.draw(eagle.rect);
}

void draw(RenderWindow &window, vector<pickUp> &pickUpArrayBullet, vector<pickUp>::const_iterator i11, vector<pickUp> &pickUpArrayCoin, vector<pickUp>::const_iterator i14, vector<projecttile> &projecttileArray, vector<projecttile>::const_iterator i, bool bullet, vector<enemy> &enemyArray, vector<enemy>::const_iterator i4, vector<textDisplay> &textDisplayArray, vector<textDisplay>::const_iterator i8, player &Player1, Text &text, creatMap &waterr, creatMap &brickk, creatMap &stonee, creatMap &glasses, vector<enemy>::const_iterator i30, vector<enemy> &bloodArray, enemy &eagle)
{
	/* Draw eagle */
	drawEagle(window, eagle);

	/* Draw pickUp Items */
	drawPickUpItem(window, pickUpArrayBullet, i11, pickUpArrayCoin, i14);

	/* Draw enemy */
	drawEnemy(window, enemyArray, i4);
	
	/* Draw blood */
	drawBlood(window, i30, bloodArray);

	/* Draw Projecttile */
	drawProjecttile(window, projecttileArray, i, bullet);

	/* Draw Map */
	drawMap(window, waterr, brickk, stonee, glasses);

	/* Draw text damage */
	drawTextDamage(window, textDisplayArray, i8);

	/* Draw Point */
	drawPoint(window, Player1, text);

}

void enemyAggro()
{
	
}

void creatBot(RenderWindow &window, Time &elapsedCreatEnemy, Clock &clockCreatEnemy, int countEnemy, enemy &enemy1, vector<enemy> &enemyArray)
{
	int random = generateRandom(10) + generateRandom(2);
	if (elapsedCreatEnemy.asSeconds() > random && countEnemy <= 10)
	{
		/* Creating coordirate ramdom */
		int xx = rand() % window.getSize().x + 1;
		int yy = rand() % window.getSize().y + 1;
		enemy1.rect.setPosition(generateRandom(xx), 400);
		enemyArray.push_back(enemy1);
		countEnemy++;
		clockCreatEnemy.restart();
	}
}
