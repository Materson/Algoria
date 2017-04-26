#include"Human.h"
#include"Animal.h"
#include"World.h"
#include<conio.h>
#include<iostream>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

Human::Human(int power, int activity, World *world, int x, int y)
	:Animal(power, activity, world, x, y)
{
	image = 'H';
}

Human::~Human()
{
	int a;
	std::cout << "Czlowiek umiera";
	//std::cin >> a;
	world->humanDie();
}

void Human::action(int dx, int dy)
{
	bool move = false;
	int zn = 0;
	while (!move)
	{
		zn = 0;
		move = true;
		zn = getch();
		switch (zn)
		{
		case UP:
			Animal::action(0, -1);
			break;
		case RIGHT:
			Animal::action(1, 0);
			break;
		case DOWN:
			Animal::action(0, 1);
			break;
		case LEFT:
			Animal::action(-1, 0);
			break;
		default:
			move = false;
		}
	}
}
