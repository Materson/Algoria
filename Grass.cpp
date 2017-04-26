#include "Grass.h"

Grass::Grass(int power, World * world, int x, int y)
	:Plant(power, world, x, y)
{
	this->image = 'g';
}
