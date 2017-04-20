#include"Organizm.h"

Organizm::Organizm(int sila, int inicjatywa, Swiat *swiat, int x, int y)
	:sila(sila), inicjatywa(inicjatywa), swiat(swiat), x(x), y(y) {}

int Organizm::getX()
{
	return x;
}

int Organizm::getY()
{
	return y;
}

void Organizm::setX(int x)
{
	this->x = x;
}

void Organizm::setY(int y)
{
	this->y = y;
}