#include "Plant.h"
#include"config.h"
#include"World.h"

Plant::Plant(int power, World *world, int x, int y)
{
	this->power = power;
	this->world = world;
	this->x = x;
	this->y = y;
	activity = 0;
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
			world->addComment(string(1, image), "spread");
		}
	}
}

void Plant::collision(Organism *attacker)
{
	int a = x, b = y;
	world->moveOrganism(attacker, a, b);
	world->addComment(string(1, attacker->getImage()), "ate", string(1, image));
	world->delOrganism(this);
}
