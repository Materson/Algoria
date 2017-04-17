#include "Organizm.h"

class Zwierze : public Organizm
{
public:
	Zwierze(int sila, int inicjatywa)
		:Organizm(sila, inicjatywa)
	{
		wiek = 1;
	}

	void akcja()
	{

	}

	void kolizja()
	{

	}
};