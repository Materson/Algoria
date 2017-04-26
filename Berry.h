#pragma once
#include"Plant.h"

class Berry: public Plant
{
public:
	Berry(int power, World *world, int x, int y);

	void collision(Organism *attacker);
};