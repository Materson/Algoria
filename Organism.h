#pragma once
class World;

class Organism
{
protected:
	int power, activity, old = 1;
	int x, y, prev_x, prev_y;
	char image;
	World *world;
	int skill = 0;
public:
	/*Organizm::Organizm(int sila, int inicjatywa, Swiat *swiat, int x, int y)*/

	virtual void action() = 0;
	virtual void collision() = 0;
	virtual void draw() = 0;
	
	int getX();
	int getY();
	int getPrev_x();
	int getPrev_y();
	void setX(int x);
	void setY(int y);
	void setPrev_x(int prev_x);
	void setPrev_y(int prev_y);
	char getImage();
};