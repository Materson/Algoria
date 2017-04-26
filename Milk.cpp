#include "Milk.h"
#include"config.h"



Milk::Milk(int power, World * world, int x, int y)
	:Plant(power, world, x, y)
{
	image = 'm';
}

void Milk::action(int dx, int dy)
{
	for (int i = 0; i < MILK_TRIES; i++)
	{
		Plant::action();
	}
}
