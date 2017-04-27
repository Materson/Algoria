#include "Guarana.h"
#include"config.h"
#include"World.h"

Guarana::Guarana(int power, World * world, int x, int y)
	:Plant(power,world,x,y)
{
	image = 'G';
}

void Guarana::collision(Organism * attacker)
{
	attacker->setPower(attacker->getPower() + GU_STRENGTH);
	world->addComment(string(1, attacker->getImage()), "ate", string(1, image)+" strength +"+to_string(GU_STRENGTH));
	Plant::collision(attacker);
}
