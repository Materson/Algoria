#include"Zwierze.cpp"

class Czlowiek : public Zwierze
{
private:

public:
	Czlowiek(int sila, int inicjatywa, Swiat *swiat, int x, int y)
		:Zwierze(sila, inicjatywa, swiat, x, y)
	{
		obraz = 'C';
	}
};