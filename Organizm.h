#pragma once
class Polozenie
{
private:
	int x, y;
public:
	Polozenie(int x, int y)
		:x(x), y(y) {}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	void setX(int x)
	{
		this->x = x;
	}

	void setY(int y)
	{
		this->y = y;
	}
};

class Organizm
{
protected:
	int sila, inicjatywa, wiek;
	Polozenie poz;
	char obraz=' ';
	Organizm ****map;
public:
	Organizm(int sila, int inicjatywa, Organizm ****map, int x, int y)
		:sila(sila), inicjatywa(inicjatywa), map(map), poz(x,y) {}

	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;

};