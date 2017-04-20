#include<iostream>
#include "Swiat.cpp"
#include"Zwierze.h"
using namespace std;

int main()
{
	Swiat *mapa = new Swiat(5, 5);
	mapa->rysujSwiat();
	/*Zwierze *byk = new Zwierze();
	byk->rysowanie();*/
	Zwierze zw(0,0, mapa, 2, 3);

    return 0;
}

