#pragma once
#include"Zwierze.h"
class Swiat;

class Czlowiek : public Zwierze
{
private:

public:
	Czlowiek(int sila, int inicjatywa, Swiat *swiat, int x, int y);
};
