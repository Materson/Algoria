#pragma once
#include"Animal.h"

class Wolf : public Animal
{
public:
	Wolf(int power, int activity, World *world, int x, int y);
};
