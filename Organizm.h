#pragma once
class Organizm
{
protected:
	int sila, inicjatywa, wiek;
public:
	Organizm(int sila, int inicjatywa)
		:sila(sila), inicjatywa(inicjatywa)
	{
	
	}
	void virtual akcja();
	void virtual kolizja();
	void virtual rysowanie();

};