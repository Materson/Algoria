#include "Fox.h"
#include "World.h"
#include "config.h"

Fox::Fox(int power, int activity, World *world, int x, int y)
	:Animal(power, activity, world, x, y)
{
	image = 'f';
}

void Fox::action(int a, int b)
{
	int dx[] = { MOVE_RANGE_X };
	int dy[] = { MOVE_RANGE_Y };
	bool findPlace = false;
	int move_num = (sizeof(dx) / sizeof(dx[0]));
	int *move = new int[move_num];
	int rand_int;
	char place;
	for (int i = 0; i < move_num; i++)
	{
		move[i] = i;
	}

	while (move_num >= 0 && !findPlace)
	{
		rand_int = world->randInt(0, move_num--);
		place = world->checkPlace(x + dx[move[rand_int]], y + dy[move[rand_int]]);
		if (place == '!')
		{
			move[rand_int] = move[move_num];
			continue;
		}

		if (place != ' ')
		{
			if (world->checkOrganismPower(x + dx[move[rand_int]], y + dy[move[rand_int]]) > power)
			{
				move[rand_int] = move[move_num];
				world->addComment(string(1, image), "hissed", string(1,place));
				continue;
			}
		}

		findPlace = true;
		Animal::action(dx[move[rand_int]], dy[move[rand_int]]);
	}
	delete(move);
}
