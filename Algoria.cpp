#include<iostream>
#include "World.cpp"
#include"Animal.h"
using namespace std;

int main()
{
	World *map= new World(4, 6);
	//map->drawWorld();
	while (1)
	{
		map->nextTurn();
		map->drawWorld();
	}

    return 0;
}

