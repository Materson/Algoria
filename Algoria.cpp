#include<iostream>
#include "World.cpp"
#include"Animal.h"
using namespace std;

int main()
{
	World *map= new World(1, 8);
	//map->drawWorld();
	char z;
	cin >> z;
	while (z == 'n')
	{
		map->nextTurn();
		map->drawWorld();
		cin >> z;
	}

    return 0;
}

