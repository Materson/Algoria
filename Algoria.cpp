#include<iostream>
#include "World.cpp"
#include<conio.h>
#define ESC 27
using namespace std;

int main()
{
	World *algoria= new World(10, 5);
	int zn;
	while (algoria->humanAlive() || ((zn=getch()) != ESC))
	{
		if (algoria->humanAlive() || zn == ' ')
		{
			algoria->nextTurn();
			algoria->drawWorld();
		}
		if (!algoria->game()) break;
	}

    return 0;
}

