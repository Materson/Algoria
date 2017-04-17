#pragma once
class Organizm
{
protected:
	int sila, inicjatywa, wiek;
	char obraz=' ';
public:
	Organizm(int sila, int inicjatywa)
		:sila(sila), inicjatywa(inicjatywa)
	{
	
	}
	virtual void akcja() = 0;
	virtual void kolizja() = 0;
	virtual void rysowanie() = 0;

};