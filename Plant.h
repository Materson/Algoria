#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	Plant(int power, World *world, int x, int y);

	void action(int move_dx = 0, int move_dy = 0);

	void collision(Organism *attacker);
};