#pragma once
class Swiat;

class Organizm
{
protected:
	int sila, inicjatywa, wiek = 1;
	int x, y, prev_x, prev_y;
	char obraz;
	Swiat *swiat;
	int skill = 0;
public:
	/*Organizm::Organizm(int sila, int inicjatywa, Swiat *swiat, int x, int y)*/

	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;
	
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