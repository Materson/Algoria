#pragma once
#include"Animal.h"

class Antelope : public Animal
{
public:
	Antelope(int power, int activity, World *world, int x, int y);
	
	void action(int dx, int dy);

	void collision(Organism *attacker);
};