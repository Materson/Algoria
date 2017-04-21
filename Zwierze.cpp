#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include"config.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
using namespace std;

Zwierze::Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y)
	:Organizm(sila, inicjatywa, swiat, x, y) {}

void Zwierze::akcja()
{
	int dx[] = { MOVE_RANGE_X };
	int dy[] = { MOVE_RANGE_Y };
	bool findPlace = false;
	int range = sizeof(dx) / sizeof(dx[0]);
	while (range-- > 0 && !findPlace)
	{
		int move = rand() % (sizeof(dx) / sizeof(dx[0]));
		if (x + dx[move] >= swiat->getWidth() || y + dy[move] >= swiat->getHeight()
			|| x + dx[move] < 0 || y + dy[move] < 0)
			continue;

		findPlace = true;
		x += dx[move];
		y += dy[move];
	}
}

void Zwierze::kolizja()
{
	char place = swiat->checkPlace(x, y);

	if (place == ' ')
	{
		swiat->moveOrganism(prev_x, prev_y, x, y);
	}
	else if (place == obraz)
	{
		//rozmnazanie	
		x = prev_x;
		y = prev_y;

		int new_x = x;
		int new_y = y;
		if (swiat->findFreeSpace(&new_x, &new_y, FIND_RANGE))
		{
			swiat->addOrganism(obraz, new_x, new_y);
		}
	}
	else
	{
		//kolizja
	}
}

void Zwierze::rysowanie()
{
	cout << obraz;
}