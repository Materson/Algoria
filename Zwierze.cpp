#pragma once
#include "Organizm.h"
#include<iostream>
using namespace std;

class Zwierze : public Organizm
{
public:
	
	Zwierze(int sila, int inicjatywa, Organizm ****map, int x, int y)
		:Organizm(sila, inicjatywa, map, x, y)
	{
		wiek = 1;
	}

	void akcja()
	{

	}

	void kolizja()
	{

	}

	void rysowanie()
	{
		cout << obraz;
	}
};