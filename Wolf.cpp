#include"Wolf.h"

Wolf::Wolf(int power, int activity, World *world, int x, int y)
	:Animal(power, activity, world, x, y)
{
	image = 'w';
}