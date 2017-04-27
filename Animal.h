#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:

	Animal(int power, int activity, World *world, int x, int y);

	void action(int move_dx = 0, int move_dy = 0);

	void collision(Organism *attacker);
};