#include "Turtle.h"
#include "World.h"

Turtle::Turtle(int power, int activity, World *world, int x, int y)
{
	this->power = power;
	this->activity = activity;
	this->world = world;
	this->x = x;
	this->y = y;
	image = 't';
}

void Turtle::action(int dx, int dy)
{
	dx = world->randInt(0,100);
	if (dx >= 75)
	{
		Animal::action();
	}
}

void Turtle::collision(Organism *attacker)
{
	if (attacker->getImage() == image)
	{
		Animal::collision(attacker);
	}
	else if (attacker->getPower() >= 5)
	{
		Animal::collision(attacker);
	}
}
