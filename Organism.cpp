#include"Organism.h"

//Organizm::Organizm(int sila, int inicjatywa, Swiat *swiat, int x, int y)
//	:sila(sila), inicjatywa(inicjatywa), swiat(swiat), x(x), y(y), prev_x(x), prev_y(y)
//	{
//		obraz = ' ';
//		wiek = 1;
//		skill = 0;
//	}

int Organism::getX()
{
	return x;
}

int Organism::getY()
{
	return y;
}
int Organism::getPrev_x()
{
	return prev_x;
}

int Organism::getPrev_y()
{
	return prev_y;
}

void Organism::setX(int x)
{
	this->x = x;
}

void Organism::setY(int y)
{
	this->y = y;
}

void Organism::setPrev_x(int x)
{
	this->prev_x = x;
}

void Organism::setPrev_y(int y)
{
	this->prev_y = y;
}

char Organism::getImage()
{
	return image;
}

int Organism::getActivity()
{
	return activity;
}

int Organism::getOld()
{
	return old;
}

int Organism::getPower()
{
	return power;
}