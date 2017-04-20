#pragma once
#include "Zwierze.h"
#include"Swiat.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<typeinfo>
using namespace std;

Zwierze::Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y)
		:Organizm(sila, inicjatywa, swiat, x, y)
	{
		wiek = 1;
	}

	void Zwierze::akcja()
	{
		int dx[] = { 0, 1, 0, -1 };
		int dy[] = { 1, 0, -1, 0 };
		int move = rand() % 4;
		this->setX(this->getX + dx[move]);
		this->setY(this->getY + dy[move]);
	}

	void Zwierze::kolizja()
	{

		if (swiat->map[this->getX][this->getY] == NULL)
		{
			swiat->map[this->getX][this->getY] = swiat->map[this->getPrev_x][this->getPrev_y];
		}
	}

	void Zwierze::rysowanie()
	{
		cout << obraz;
	}