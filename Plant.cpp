#include "Plant.h"
#include"config.h"
#include"World.h"

Plant::Plant(int power, World *world, int x, int y)
{
	this->power = power;
	this->world = world;
	this->x = x;
	this->y = y;
}

void Plant::action(int move_dx, int move_dy)
{
	if (world->randInt(0, 100) <= PLANT_RATIO*10)
	{
		int new_x = x;
		int new_y = y;
		if (world->findFreeSpace(&new_x, &new_y, PLANT_RANGE))
		{
			world->addOrganism(image, new_x, new_y);
		}
	}
}

void Plant::collision(Organism *attacker)
{
	//attack
	if (attacker->getPower() < power)
	{
		world->delOrganism(attacker);
	}
	else
	{
		int a = x, b = y;
		world->moveOrganism(attacker, a, b);
		world->delOrganism(this);
	}
}
