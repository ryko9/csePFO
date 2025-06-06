#ifndef Enemy_h
#define Enemy_h

#include "TexRect.h"
#include "AnimatedRect.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

class Enemy
{
	bool alive;
	bool right;
	bool left;
	bool down;
	bool shot;
	int rows;
	int cols;
	float cornerX;
	float cornerY;
	float width;
	float height;
	float moverate;
	TexRect *enemy;
	AnimatedRect *enemyfade;

public:
	Enemy(const char* filename1, const char* filename2, int rows, int cols, float x, float y, float w, float h)
	{
		enemy = new TexRect(filename1, x, y, w, h);
		enemyfade = new AnimatedRect(filename2, rows, cols, x, y, w, h);
		this->rows = rows;
		this->cols = cols;
		cornerX = x;
		cornerY = y;
		width = w;
		height = h;
		alive = true;
		shot = false;
		moverate = 0.006; //0.001
	}

	void setshotfalse()
	{
		shot = false;
	}

	bool getAlive()
	{
		return alive;
	}

	float getX()
	{
		return cornerX;
	}

	float getY()
	{
		return cornerY;
	}

	float setX(float x)
	{
		cornerX = x;
	}

	float setY(float y)
	{
		cornerY = y;
	}

	float getWidth()
	{
		return width;
	}

	float getHeight()
	{
		return height;
	}

	void isDead()
	{
		alive = false;
	}

	void setMove(bool l, bool r, bool d)
	{
		left = l;
		right = r;
		down = d;
	}
	
	void draw()
	{
		if(alive)
		{
			enemy->draw();
		}

		if(left)
		{
			cornerX -= moverate;
			enemy->moveLeft(moverate);
			enemyfade->moveLeft(moverate);
		}
		else if(right)
		{
			cornerX += moverate;
			enemy->moveRight(moverate);
			enemyfade->moveRight(moverate);
		}
		else if(down)
		{
			cornerY -= moverate;
			enemy->moveDown(moverate);
			enemyfade->moveDown(moverate);
		}
	}

	bool contains(float x, float y)
	{
		if(enemy->contains(x,y) && alive == true)
		{
			alive = false;
			return true;
		}
	}

};

#endif
