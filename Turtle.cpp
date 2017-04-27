#include "Turtle.h"
#include "World.h"

Turtle::Turtle(int power, int activity, World *world, int x, int y)
	:Animal(power, activity, world, x, y)
{
	image = 't';
}

void Turtle::action(int dx, int dy)
{
	dx = world->randInt(0,100);
	if (dx >= 75)
	{
		Animal::action();
	}
	else
	{
		world->addComment(string(1, image), "resting");
	}
}

void Turtle::collision(Organism *attacker)
{
	if (attacker->getImage() == image)
	{
		Animal::collision(attacker);
	}
	else if (attacker->getPower() >= 5)
	{
		Animal::collision(attacker);
	}
	else
	{
		world->addComment(string(1, image), "blocked", string(1, attacker->getImage()));
	}
}
