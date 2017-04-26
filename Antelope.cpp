#include "Antelope.h"
#include"World.h"

Antelope::Antelope(int power, int activity, World *world, int x, int y)
	:Animal(power, activity, world, x, y)
{
	image = 'a';
}

void Antelope::action(int dx = 0, int dy = 0)
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
			int dx = x, dy = y;
			if (world->findFreeSpace(&dx, &dy, 2))
			{
				int a = x, b = y;
				Animal::action(dx - x, dy - y);
				world->moveOrganism(attacker, a, b);
			}
			else
			{
				Animal::collision(attacker);
			}
		}
		else
		{
			Animal::collision(attacker);
		}
	}
	else
	{
		Animal::collision(attacker);
	}
}
