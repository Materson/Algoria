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
	for (int i = 0; i < range; i++)
	{
		for (int j = 0; j < move_num / range; j++)
		{
			dx[(move_num/range)*i + j] = tmpx[j] * (i+1);
			dy[(move_num / range)*i + j] = tmpy[j] * (i+1);
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
		if (world->checkPlace(x + dx[move[place]],y + dy[move[place]]) == '!')
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