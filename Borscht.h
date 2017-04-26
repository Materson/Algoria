#pragma once
#include"Plant.h"

class Borscht : public Plant
{
public:
	Borscht(int power, World *world, int x, int y);

	void action(int dx = 0, int dy = 0);

	void collision(Organism *attacker);
};