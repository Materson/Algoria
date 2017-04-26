#pragma once
#include"Plant.h"

class Milk : public Plant
{
public:
	Milk(int power, World *world, int x, int y);

	void action(int dx=0, int dy=0);
};