#include"Human.h"
#include"Animal.h"
#include"World.h"
#include<conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

Human::Human(int power, int activity, World *world, int x, int y)
{
	this->power = power;
	this->activity = activity;
	this->world = world;
	this->x = x;
	this->y = y;
	this->prev_x = x;
	this->prev_y = y;
	this->image = 'H';
}

void Human::action(int dx, int dy)
{
	bool move = false;
	int zn = 0;
	while (!move)
	{
		zn = 0;
		move = true;
		zn = getch();
		switch (zn)
		{
		case UP:
			Animal::action(0, -1);
			break;
		case RIGHT:
			Animal::action(1, 0);
			break;
		case DOWN:
			Animal::action(0, 1);
			break;
		case LEFT:
			Animal::action(-1, 0);
			break;
		default:
			move = false;
		}
	}
}
