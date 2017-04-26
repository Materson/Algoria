#pragma once
#include "Organism.h"
#include"stdafx.h"

class Animal : public Organism
{
public:

	/*Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y);*/

	void action(int move_x = 0, int move_y = 0);

	void collision(Organism *attacker);

	void draw();

	void randMove(int *move_x, int *move_y, int range);
};