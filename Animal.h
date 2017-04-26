#pragma once
#include "Organism.h"
#include"stdafx.h"

class Animal : public Organism
{
public:

	/*Zwierze(int sila, int inicjatywa, Swiat *swiat, int x, int y);*/

	void action(int move_x, int move_y);

	void collision(Organism *attacker);

	void draw();

	void randMove(int *move_x, int *move_y);
};