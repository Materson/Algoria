#include"Sheep.h"

Sheep::Sheep(int power, int activity, World *world, int x, int y)
	:Animal(power, activity, world, x, y)
{
	image = 's';
}