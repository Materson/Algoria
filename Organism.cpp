#include"Organism.h"
#include"World.h"
#include"config.h"
#include<iostream>

//Organizm::Organizm(int sila, int inicjatywa, Swiat *swiat, int x, int y)
//	:sila(sila), inicjatywa(inicjatywa), swiat(swiat), x(x), y(y), prev_x(x), prev_y(y)
//	{
//		obraz = ' ';
//		wiek = 1;
//		skill = 0;
//	}

Organism::~Organism()
{
}

void Organism::draw()
{
	std::cout << image;
}

int Organism::getX()
{
	return x;
}

int Organism::getY()
{
	return y;
}

void Organism::setX(int x)
{
	this->x = x;
}

void Organism::setY(int y)
{
	this->y = y;
}

char Organism::getImage()
{
	return image;
}

void Organism::increaseOld()
{
	old++;
}

int Organism::getActivity()
{
	return activity;
}

int Organism::getOld()
{
	return old;
}

int Organism::getPower()
{
	return power;
}

void Organism::setPower(int x)
{
	power = x;
}

void Organism::randMove(int *move_x, int *move_y, int range)
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
			dx[(move_num / range)*i + j] = tmpx[j] * (i + 1);
			dy[(move_num / range)*i + j] = tmpy[j] * (i + 1);
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
		if (world->checkPlace(x + dx[move[place]], y + dy[move[place]]) == '!')
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