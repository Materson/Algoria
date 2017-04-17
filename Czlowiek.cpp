#include"Zwierze.cpp"

class Czlowiek : public Zwierze
{
private:

public:
	Czlowiek(int sila, int inicjatywa, Organizm ****map, int x, int y)
		:Zwierze(sila, inicjatywa, map, x, y)
	{
		obraz = 'C';
	}
};