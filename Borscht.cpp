#include "Borscht.h"
#include"config.h"
#include"World.h"

Borscht::Borscht(int power, World *world, int x, int y)
	:Plant(power, world, x, y)
{
	image = 'X';
}

void Borscht::action(int a, int b)
{
	int dx[] = { MOVE_RANGE_X };
	int dy[] = { MOVE_RANGE_Y };

	for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++)
	{
		char place = world->checkPlace(x + dx[i], y + dy[i]);
		if (place != ' ' && place != '!' && world->checkOrganismActivity(x + dx[i], y + dy[i]) > 0)
		{
			world->delOrganism(0, x + dx[i], y + dy[i]);
		}
	}
}

void Borscht::collision(Organism *attacker)
{
	world->delOrganism(attacker);
}