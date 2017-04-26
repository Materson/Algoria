#pragma once
#include"Animal.h"

class Turtle : public Animal
{
public:
	Turtle(int power, int activity, World *world, int x, int y);

	void action(int dx = 0, int dy = 0) override;

	void collision(Organism *attacker);
};