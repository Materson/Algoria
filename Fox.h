#pragma once
#include"Animal.h"

class Fox : public Animal
{
public:
	Fox(int power, int activity, World *world, int x, int y);

	void action();
};
