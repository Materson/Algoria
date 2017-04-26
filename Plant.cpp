#include "Plant.h"
#include"config.h"
#include"World.h"

void Plant::action()
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
