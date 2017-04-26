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

void Animal::action(int move_x, int move_y)
{
	if (move_x == 0 && move_y == 0)
	{
		randMove(&move_x, &move_y, 1);
	}

	if (world->checkPlace(x + move_x, y + move_y) == ' ')
	{
		world->moveOrganism(this, x + move_x, y + move_y);
	}
	else
	{
		world->collision(this, x + move_x, y + move_y);
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

void Animal::draw()
{
	cout << image;
}

void Animal::randMove(int *move_x, int *move_y, int range)
{
	int tmpx[] = { MOVE_RANGE_X };
	int tmpy[] = { MOVE_RANGE_Y };

	bool findPlace = false;
	int move_num = (sizeof(tmpx) / sizeof(tmpx[0]))*range;
	int *dx = new int[move_num];
	int *dy = new int[move_num];
	for (int i = 1; i <= range; i++)
	{
		for (int j = 0; j < move_num / range; j++)
		{
			dx[j*i] = tmpx[j] * i;
			dy[j*i] = tmpy[j] * i;
		}
	}

	int place;
	int *move = new int[move_num];
	for (int i = 0; i < move_num; i++)
	{
		move[i] = i;
	}

	while (move_num > 0 && !findPlace)
	{
		place = world->randInt(0, move_num--);
		if (x + dx[move[place]] >= world->getWidth() || y + dy[move[place]] >= world->getHeight()
			|| x + dx[move[place]] < 0 || y + dy[move[place]] < 0)

		{
			move[place] = move[move_num];
			continue;
		}

		findPlace = true;
		place = move[place];
		*move_x = dx[place];
		*move_y = dy[place];
	}
	delete[](move);
	delete[](dx);
	delete[](dy);
}