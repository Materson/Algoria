#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:

	/*Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y);*/

	void action();

	void collision();

	void draw();
};