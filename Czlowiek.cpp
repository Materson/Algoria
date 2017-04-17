#include"Zwierze.cpp"

class Czlowiek : public Zwierze
{
private:

public:
	Czlowiek(int sila, int inicjatywa)
		:Zwierze(sila, inicjatywa)
	{
		obraz = 'C';
	}
};