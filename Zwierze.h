#pragma once
#include "Organizm.h"

class Zwierze : public Organizm
{
public:

	/*Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y);*/

	void akcja();

	void kolizja();

	void rysowanie();
};