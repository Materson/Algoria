#pragma once
#include"Animal.h"
class World;

class Human : public Animal
{
private:

public:
	Human(int sila, int activity, World *world, int x, int y);

	void action(int dx, int dy);
};
