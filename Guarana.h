#pragma once
#include"Plant.h"

class Guarana : public Plant
{
public:
	Guarana(int power, World *world, int x, int y);

	void collision(Organism *attacker);
};