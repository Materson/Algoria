#pragma once
#include"Animal.h"
class World;

class Human : public Animal
{
private:

public:
	Human(int sila, int activity, World *world, int x, int y);

	~Human();

	void action(int dx, int dy);

	void collistion(Organism *attacker);

	void fire(int dx = 0, int dy = 0);
};
