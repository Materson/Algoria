#pragma once
#include "Organism.h"
#include"stdafx.h"

class Animal : public Organism
{
public:

	/*Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y);*/

	void action(int move_dx = 0, int move_dy = 0);

	void collision(Organism *attacker);

	void draw();
};