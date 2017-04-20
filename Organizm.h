#pragma once
class Swiat;

class Organizm
{
protected:
	int sila, inicjatywa, wiek;
	int x,y;
	char obraz='#';
	Swiat *swiat;
public:
	Organizm(int sila, int inicjatywa, Swiat *swiat, int x, int y);

	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;
	
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
};