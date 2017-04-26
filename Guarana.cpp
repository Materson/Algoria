#include "Guarana.h"
#include"config.h"

Guarana::Guarana(int power, World * world, int x, int y)
	:Plant(power,world,x,y)
{
	image = 'G';
}

void Guarana::collision(Organism * attacker)
{
	attacker->setPower(attacker->getPower() + GU_STRENGTH);
	Plant::collision(attacker);
}
