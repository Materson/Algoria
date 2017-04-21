#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
using namespace std;

Zwierze::Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y)
		:Organizm(sila, inicjatywa, swiat, x, y){}

void Zwierze::akcja()
{
	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	int move = rand() % 4;
	x += dx[move];
	y += dy[move];
}

void Zwierze::kolizja()
{
	char place = swiat->checkPlace(x, y);
	if (place == ' ')
	{
		swiat->moveOrganism(prev_x, prev_y, x, y);
	}
	else if(place == obraz)
	{
		//rozmnazanie	
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