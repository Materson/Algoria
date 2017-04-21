#include<iostream>
#include "World.cpp"
#include"Animal.h"
using namespace std;

int main()
{
	World *map= new World(5, 5);
	map->drawWorld();
	/*Zwierze *byk = new Zwierze();
	byk->rysowanie();*/
	Wolf zw(0,0, map, 2, 3);

    return 0;
}

