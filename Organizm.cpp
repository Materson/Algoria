#include"Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, Swiat *swiat, int x, int y)
	:sila(sila), inicjatywa(inicjatywa), swiat(swiat), x(x), y(y), prev_x(x), prev_y(y) {}

int Organizm::getX()
{
	return x;
}

int Organizm::getY()
{
	return y;
}
int Organizm::getPrev_x()
{
	return prev_x;
}

int Organizm::getPrev_y()
{
	return prev_y;
}

void Organizm::setX(int x)
{
	this->x = x;
}

void Organizm::setY(int y)
{
	this->y = y;
}

void Organizm::setPrev_x(int x)
{
	this->prev_x = x;
}

void Organizm::setPrev_y(int y)
{
	this->prev_y = y;
}

char Organizm::getImage()
{
	return obraz;
}