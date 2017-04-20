#include"Czlowiek.h"
#include"Zwierze.h"
#include"Swiat.h"

Czlowiek::Czlowiek(int sila, int inicjatywa, Swiat *swiat, int x, int y)
	:Zwierze(sila, inicjatywa, swiat, x, y)
{
	obraz = 'C';
}