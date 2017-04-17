#pragma once
#include "Organizm.h"
#include<iostream>
using namespace std;

class Zwierze : public Organizm
{
public:
	
	Zwierze(int sila, int inicjatywa)
		:Organizm(sila, inicjatywa)
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