#pragma once
#include "Organism.h"
#include"stdafx.h"

class Animal : public Organism
{
public:

	/*Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y);*/

	void action();

	status collision(Organism *attacker);

	void draw();
};