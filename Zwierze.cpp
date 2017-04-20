#pragma once
#include "Zwierze.h"
#include<iostream>
using namespace std;

Zwierze::Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y)
		:Organizm(sila, inicjatywa, swiat, x, y)
	{
		wiek = 1;
	}

	void Zwierze::akcja()
	{

	}

	void Zwierze::kolizja()
	{

	}

	void Zwierze::rysowanie()
	{
		cout << obraz;
	}