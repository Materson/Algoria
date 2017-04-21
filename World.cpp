#include"World.h"
#include"Organism.h"
#include"Human.h"
#include"Wolf.h"
#include"config.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

World::World(int width, int height)
	:width(width), height(height)
{
	srand(time(NULL));
	map = new Organism**[height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new Organism*[width];
	}

	fillWorld();
}

//Swiat::~Swiat()
//{
//	for (int i = 0; i < height; i++)
//	{
//		delete[](*map);
//	}
//	delete[](map);
//}

int World::getHeight()
{
	return height;
}

int World::getWidth()
{
	return width;
}

void World::nextTurn()
{
	cout << "wykonana tura";
}

void World::drawWorld()
{
	for (int i = 0; i <= height * 2; i++)
	{
		for (int j = 0; j <= width * 2; j++)
		{
			if (i % 2 == 0 && j%2 == 0) cout << "+";
			else if (i % 2 == 0 && j % 2 == 1) cout << "-";

			if (i % 2 == 1 && j % 2 == 0)cout << "|";
			if (i % 2 == 1 && j % 2 == 1) map[j/2][i/2]->draw();
		}
		cout << endl;
	}
}

Organism* World::randOrganism()
{
	//Organizm *organizmy[] = { new Czlowiek(1,2,this,2,1) };
	int rand;
	switch (rand)
	{
	case 1:
		return new Human(1, 2, this, 2, 1);
	default:
		break;
	}
}

void World::moveOrganism(int prev_x, int prev_y, int x, int y)
{
	map[x][y] = map[prev_x][prev_y];
	map[prev_x][prev_y] = NULL;
}

char World::checkPlace(int x, int y)
{
	if (map[x][y] == NULL) return ' ';
	return map[x][y]->getImage();
}

//set x, y at free place and return 1, otherwise return 0
int World::findFreeSpace(int *x, int *y, int range)
{
	int dx[] = { MOVE_RANGE_X };
	int dy[] = { MOVE_RANGE_Y };

	for (int j = 1; j <= range; j++)
	{
		for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++)
		{
			if ((*x) + (dx[i] * j) >= width || (*y) + (dy[i] * j) >= height
				|| ((*x) + dx[i] * j) < 0 || (*y) + (dy[i] * j) < 0)
				continue;
			else if (checkPlace((*x) + (dx[i] * j), (*y) + (dy[i] * j)) != ' ')
				continue;

			*x += (dx[i] * j);
			*y += (dy[i] * j);
			return 1;
		}
	}
	return 0;
}

int World::randInt(int min, int max)
{
	return rand() % (max - min) + min;
}

void World::addOrganism(char image, int x, int y)
{
	switch (image)
	{
	case 'w':
		map[x][y] = new Wolf(W_POWER, W_ACTIVITY, this, x, y);
		break;
	}
}

void World::fillWorld()
{
	string organism = ORGANISM_RATIO;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (randInt(1, 10) % FILL_RATIO == 0)
			{
				addOrganism(organism[randInt(1, 100) % organism.length()], j, i);
			}
		}
	}
	

}