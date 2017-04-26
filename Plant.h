#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	void action();

	void collision(Organism *attacker);

	void draw();
};