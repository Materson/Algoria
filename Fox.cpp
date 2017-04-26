#include "Fox.h"
#include "World.h"
#include "config.h"

Fox::Fox(int power, int activity, World *world, int x, int y)
{
	this->power = power;
	this->activity = activity;
	this->world = world;
	this->x = x;
	this->y = y;
	image = 'f';
}

void Fox::action(int a, int b)
{
	int dx[] = { MOVE_RANGE_X };
	int dy[] = { MOVE_RANGE_Y };
	bool findPlace = false;
	int move_num = (sizeof(dx) / sizeof(dx[0]));
	int *move = new int[move_num];
	int place;
	for (int i = 0; i < move_num; i++)
	{
		move[i] = i;
	}

	while (move_num >= 0 && !findPlace)
	{
		place = world->randInt(0, move_num--);
		if (x + dx[move[place]] >= world->getWidth() || y + dy[move[place]] >= world->getHeight()
			|| x + dx[move[place]] < 0 || y + dy[move[place]] < 0)

		{
			move[place] = move[move_num];
			continue;
		}

		if (world->checkPlace(x + dx[move[place]], y + dy[move[place]]) != ' ')
		{
			if (world->getOrganismPower(x + dx[move[place]], y + dy[move[place]]) > power)
			{
				move[place] = move[move_num];
				continue;
			}
		}

		findPlace = true;
		place = move[place];
		Animal::action(dx[place], dy[place]);
	}
	delete(move);
}
