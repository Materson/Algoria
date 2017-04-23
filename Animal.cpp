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
	int move;
	while (range-- > 0 && !findPlace)
	{
		move = rand() % (sizeof(dx) / sizeof(dx[0]));
		if (x + dx[move] >= world->getWidth() || y + dy[move] >= world->getHeight()
			|| x + dx[move] < 0 || y + dy[move] < 0)
			continue;

		findPlace = true;
	}

	if (world->checkPlace(x + dx[move], y + dy[move]) == ' ')
	{
		world->moveOrganism(x, y, x + dx[move], y + dy[move]);
	}
	else
	{
		world->collision(this, x + dx[move], y + dy[move]);
	}
}

status Animal::collision(Organism *attacker)
{

	if (attacker->getImage() == image)
	{
		//copulate
		int new_x = x;
		int new_y = y;
		if (world->findFreeSpace(&new_x, &new_y, FIND_RANGE))
		{
			world->addOrganism(image, new_x, new_y);
			return COPULATE;
		}
	}
	else
	{
		//attack
		if (attacker->getActivity() < activity)
		{
			return DEF_WIN;
		}
		else
		{
			return AT_WIN;
		}
	}
}

void Animal::draw()
{
	cout << image;
}