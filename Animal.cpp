#pragma once
#include "Animal.h"
#include"World.h"
#include"config.h"
#include<iostream>
using namespace std;

Animal::Animal(int power, int activity, World *world, int x, int y)
{
	this->power = power;
	this->activity = activity;
	this->world = world;
	this->x = x;
	this->y = y;
}


void Animal::action(int move_dx, int move_dy)
{
	if (move_dx == 0 && move_dy == 0)
	{
		randMove(&move_dx, &move_dy, 1);
	}

	if (world->checkPlace(x + move_dx, y + move_dy) != '!')
	{
		if (world->checkPlace(x + move_dx, y + move_dy) == ' ')
		{
			world->moveOrganism(this, x + move_dx, y + move_dy);
		}
		else
		{
			world->collision(this, x + move_dx, y + move_dy);
		}

	}
}

void Animal::collision(Organism *attacker)
{

	if (attacker->getImage() == image)
	{
		//copulate
		int new_x = x;
		int new_y = y;
		if (world->findFreeSpace(&new_x, &new_y, FIND_RANGE))
		{
			world->addOrganism(image, new_x, new_y);
		}
	}
	else
	{
		//attack
		if (attacker->getPower() < power)
		{
			world->delOrganism(attacker);
		}
		else
		{
			int a = x, b = y;
			world->moveOrganism(attacker, a, b);
			world->delOrganism(this);
		}
	}
}