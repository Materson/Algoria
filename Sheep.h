#pragma once
#include"Animal.h"

class Sheep : public Animal
{
public:
	Sheep(int power, int activity, World *world, int x, int y);
};
