#pragma once
#include"Plant.h"

class Grass : public Plant
{
public:
	Grass(int power, World *world, int x, int y);
};