#pragma once
#include "Animal.h"
#include"World.h"
#include"config.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
using namespace std;

//Zwierze::Zwierze(int sila, int inicjatywa, world *world, int x, int y)
//	:Organizm(sila, inicjatywa, world, x, y) {}

void Animal::action()
{
	int dx[] = { MOVE_RANGE_X };
	int dy[] = { MOVE_RANGE_Y };
	bool findPlace = false;
	int range = sizeof(dx) / sizeof(dx[0]);
	while (range-- > 0 && !findPlace)
	{
		int move = rand() % (sizeof(dx) / sizeof(dx[0]));
		if (x + dx[move] >= world->getWidth() || y + dy[move] >= world->getHeight()
			|| x + dx[move] < 0 || y + dy[move] < 0)
			continue;

		findPlace = true;
		x += dx[move];
		y += dy[move];
	}
}

void Animal::collision()
{
	char place = world->checkPlace(x, y);

	if (place == ' ')
	{
		//move
		world->moveOrganism(prev_x, prev_y, x, y);
	}
	else if (place == image)
	{
		//rozmnazanie	
		x = prev_x;
		y = prev_y;

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
		world->battle(this, x, y);

	}
}

void Animal::draw()
{
	cout << image;
}