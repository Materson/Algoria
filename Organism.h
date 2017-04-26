#pragma once
#include"stdafx.h"
class World;

class Organism
{
protected:
	int power, activity, old = 1;
	int x, y;
	char image;
	World *world;
	int skill = 0;
public:
	/*Organizm::Organizm(int sila, int inicjatywa, Swiat *swiat, int x, int y)*/
	virtual ~Organism();

	virtual void action(int move_x = 0, int move_y = 0) = 0;
	virtual void collision(Organism * attacker) = 0;

	void draw();
	int getX();
	int getY();
	int getActivity();
	int getOld();
	int getPower();
	void setX(int x);
	void setY(int y);
	char getImage();
	void increaseOld();
	void randMove(int *move_x, int *move_y, int range);
};