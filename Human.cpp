#include"Human.h"
#include"Animal.h"
#include"World.h"
#include<conio.h>
#include"config.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

Human::Human(int power, int activity, World *world, int x, int y)
	:Animal(power, activity, world, x, y)
{
	image = 'H';
}

Human::~Human()
{
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
			if (skill > 0)
				fire(0, -1);
			else
				Animal::action(0, -1);
			break;
		case RIGHT:
			if (skill > 0)
				fire(1, 0);
			else
				Animal::action(1, 0);
			break;
		case DOWN:
			if (skill > 0)
				fire(0, 1);
			else
				Animal::action(0, 1);
			break;
		case LEFT:
			if (skill > 0)
				fire(-1, 0);
			else
				Animal::action(-1, 0);
			break;
		case ESC:
			world->endGame();
			break;
		case ' ':
			if (skill > 0)
				move = false;
			if (skill == 0)
			{
				skill = SKILL_DURATION;
				image = 'O';
				fire();
			}
			break;
		default:
			move = false;
		}
	}

	if (skill < 0) skill++;
}

void Human::collistion(Organism * attacker)
{
	if (skill > 0)
	{
		world->delOrganism(attacker);
	}
	else
	{
		Animal::collision(attacker);
	}
}

void Human::fire(int move_x, int move_y)
{
	if (move_x != 0 || move_y != 0)
	{
		char place = world->checkPlace(x + move_x, y + move_y);
		if(place != ' ' && place != '!')
			world->delOrganism(NULL, x + move_x, y + move_y);
		Animal::action(move_x, move_y);
	}

	int dx[] = { MOVE_RANGE_X };
	int dy[] = { MOVE_RANGE_Y };

	for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++)
	{
		char place = world->checkPlace(x + dx[i], y + dy[i]);
		if (place != ' ' && place != '!')
		{
			world->delOrganism(0, x + dx[i], y + dy[i]);
		}
	}
	if (--skill == 0)
	{
		skill = -SKILL_DURATION-1;
		image = 'H';
	}
}
