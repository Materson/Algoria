#include<iostream>
#include "World.cpp"
#include"Animal.h"
using namespace std;

int main()
{
	World *map= new World(5, 5);
	map->drawWorld();
	char z;
	cin >> z;
	while (z == 'n')
	{
		map->nextTurn();
		map->drawWorld();
		cin >> z;
	}
	/*Zwierze *byk = new Zwierze();
	byk->rysowanie();*/

    return 0;
}

