#pragma once
#include "Animal.h"
#include"World.h"
#include"config.h"
#include"stdafx.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
using namespace std;

//Zwierze::Zwierze(int sila, int inicjatywa, world *world, int x, int y)
//	:Organizm(sila, inicjatywa, world, x, y) {}

void Animal::action()
{
	old++;
	int dx[] = { MOVE_RANGE_X };
	int dy[] = { MOVE_RANGE_Y };
	bool findPlace = false;
	int range = sizeof(dx) / sizeof(dx[0]);
	int *move = new int[range];
	int place;
	for (int i = 0; i < range; i++)
	{
		move[i] = i;
	}

	while (range >= 0 && !findPlace)
	{
		place = world->randInt(0, range--);
		if (x + dx[move[place]] >= world->getWidth() || y + dy[move[place]] >= world->getHeight()
			|| x + dx[move[place]] < 0 || y + dy[move[place]] < 0)

		{
			move[place] = move[range];
			continue;
		}

		findPlace = true;
		place = move[place];
	}

	if (world->checkPlace(x + dx[place], y + dy[place]) == ' ')
	{
		world->moveOrganism(this, x + dx[place], y + dy[place]);
	}
	else
	{
		world->collision(this, x + dx[place], y + dy[place]);
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
		if (attacker->getActivity() < activity)
		{
			world->delOrganism(attacker->getX(), attacker->getY());
		}
		else
		{
			world->delOrganism(x, y);
			world->moveOrganism(attacker, x, y);
		}
	}
}

void Animal::draw()
{
	cout << image;
}