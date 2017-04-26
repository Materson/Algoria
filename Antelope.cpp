#include "Antelope.h"
#include"World.h"

Antelope::Antelope(int power, int activity, World * world, int x, int y)
{
	this->power = power;
	this->activity = activity;
	this->world = world;
	this->x = x;
	this->y = y;
	this->prev_x = x;
	this->prev_y = y;
	image = 'a';
}

void Antelope::action(int dx, int dy)
{
	randMove(&dx, &dy, 2);
	Animal::action(dx, dy);
}

void Antelope::collision(Organism *attacker)
{
	if (attacker->getImage() != image)
	{
		if (world->randInt(0, 100) <= 50)
		{
			int dx = 0, dy = 0;
			if (world->findFreeSpace(&dx, &dy, 2))
			{
				int a = x, b = y;
				Animal::action(dx, dy);
				world->moveOrganism(attacker, a, b);
			}
			else
			{
				Animal::collision(attacker);
			}
		}
	}
	else
	{
		Animal::collision(attacker);
	}
}
