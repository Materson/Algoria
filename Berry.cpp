#include "Berry.h"
#include"World.h"

Berry::Berry(int power, World * world, int x, int y)
	:Plant(power, world, x, y)
{
	image = 'b';
}

void Berry::collision(Organism * attacker)
{
	world->addComment(string(1, image), "poisoned", string(1, attacker->getImage()));
	world->delOrganism(attacker);
}