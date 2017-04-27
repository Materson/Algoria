#include"World.h"
#include"IncludeOrganisms.h"
#include"config.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

World::World(int width, int height)
	:width(width), height(height)
{
	srand(time(NULL));
	map = new Organism**[width];
	for (int i = 0; i < width; i++)
	{
		map[i] = new Organism*[height];
	}
	comment_i = 0;
	human = false;
	fillWorld();
	drawWorld();
	order = new Organism*[width*height];
	setOrder();
}

//World::~World()
//{
//	for (int i = 0; i < height; i++)
//	{
//		for (int j = 0; j < width; j++)
//		{
//			if(map[j][i] != NULL)
//				delete(map[j][i]);
//		}
//		delete[](map[i]);
//	}
//	delete[](map);
//	
//	delete[](order);
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
	int num = orgNum;
	for (int i = 0; i < num; i++)
	{
		if (order[i] != NULL)
			order[i]->increaseOld();
	}

	for (int i = 0; i < num; i++)
	{
		if(order[i] != NULL)
			order[i]->action();
	}
	setOrder();
}

void World::drawWorld()
{
	system("cls");
	cout << "Mateusz Szymanowski, nr:165319" << endl;
	for (int i = 0; i <= height * 2; i++)
	{
		for (int j = 0; j <= width * 2; j++)
		{
			if (i % 2 == 0 && j%2 == 0) cout << "+";
			else if (i % 2 == 0 && j % 2 == 1) cout << "-";

			if (i % 2 == 1 && j % 2 == 0)cout << "|";
			if (i % 2 == 1 && j % 2 == 1)
			{
				if (map[j / 2][i / 2] == NULL)
					cout << " ";
				else
					map[j / 2][i / 2]->draw();
			}
		}
		cout << endl;
	}
	printComments();
}

//Organism* World::randOrganism()
//{
//	//Organizm *organizmy[] = { new Czlowiek(1,2,this,2,1) };
//	int rand;
//	switch (rand)
//	{
//	case 1:
//		return new Human(1, 2, this, 2, 1);
//	default:
//		break;
//	}
//}

void World::moveOrganism(Organism *org, int x, int y)
{
	map[x][y] = org;
	map[org->getX()][org->getY()] = NULL;
	org->setX(x);
	org->setY(y);
}

char World::checkPlace(int x, int y)
{
	if (x >= width || y >= height
		|| x < 0 || y < 0)
		return '!';
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
			char place = checkPlace((*x) + (dx[i] * j), (*y) + (dy[i] * j));
			if (place == '!' || place != ' ')
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
	case 's':
		map[x][y] = new Sheep(S_POWER, S_ACTIVITY, this, x, y);
		break;
	case 'f':
		map[x][y] = new Fox(F_POWER, F_ACTIVITY, this, x, y);
		break;
	case 't':
		map[x][y] = new Turtle(T_POWER, T_ACTIVITY, this, x, y);
		break;
	case 'a':
		map[x][y] = new Antelope(A_POWER, A_ACTIVITY, this, x, y);
		break;
	case 'H':
		map[x][y] = new Human(H_POWER, H_ACTIVITY, this, x, y);
		break;
	case 'g':
		map[x][y] = new Grass(G_POWER, this, x, y);
		break;
	case 'm':
		map[x][y] = new Milk(M_POWER, this, x, y);
		break;
	case 'G':
		map[x][y] = new Guarana(GU_POWER, this, x, y);
		break;
	case 'b':
		map[x][y] = new Berry(X_POWER, this, x, y);
		break;
	case 'X':
		map[x][y] = new Borscht(X_POWER, this, x, y);
		break;
	default:
		map[x][y] = NULL;
		orgNum--;
		break;
	}
	orgNum++;
}

void World::fillWorld()
{
	string organism = ORGANISM_RATIO;
	int h_x = -1, h_y = -1;
	for (int i = 0; i < organism.size(); i++)
	{
		if (organism[i] == 'H')
		{
			if (!human)
			{
				h_x = randInt(0, width);
				h_y = randInt(0, height);
				addOrganism('H', h_x, h_y);
				addComment(string(1, 'H'), "created");
				human = true;
			}
			organism[i] = ' ';
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == h_y && j == h_x)
				continue;
			if (randInt(1, 100) <= FILL_RATIO*10)
			{
				int rand_org = randInt(1, 100) % organism.size();
				addOrganism(organism[rand_org], j, i);
				if (organism[rand_org] != ' ')
					addComment(string(1, organism[rand_org]), "created");
			}
			else
			{
				map[j][i] = NULL;
			}
		}
	}
	

}

void World::delOrganism(Organism *org, int x, int y)
{
	if(org == NULL)
	{
		org = map[x][y];
	}

	if(map[org->getX()][org->getY()] == org)
		map[org->getX()][org->getY()] = NULL;
	for (int i = 0; i < orgNum; i++)
	{
		if (order[i] == org)
		{
			delete(org);
			order[i] = NULL;
			break;
		}
	}
	orgNum--;
}

void World::setOrder()
{
	int k = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			order[k++] = map[j][i];
		}
	}

	qsort(order, height*width, sizeof(Organism*), sortOrder);
}

int World::sortOrder(const void *or1, const void *or2)
{
	Organism *org1 = *(Organism**) or1;
	Organism *org2 = *(Organism**) or2;

	if (org1 == NULL && org2 == NULL)
		return 0;
	else if (org1 != NULL && org2 == NULL)
		return -1;
	else if(org1 == NULL && org2 != NULL)
		return 1;

	if (org1->getActivity() > org2->getActivity())
		return -1;
	else if (org1->getActivity() < org2->getActivity())
		return 1;
	else
	{
		if (org1->getOld() > org2->getOld())
			return -1;
		else if (org1->getOld() < org2->getOld())
			return 1;
	}

	return 0;
}

void World::collision(Organism *attacker, int x, int y)
{
	map[x][y]->collision(attacker);
}

int World::checkOrganismPower(int x, int y)
{
	if (map[x][y] != NULL)
	{
		return map[x][y]->getPower();
	}
}

int World::checkOrganismActivity(int x, int y)
{
	if (map[x][y] != NULL)
	{
		return map[x][y]->getActivity();
	}
}

void World::humanDie()
{
	human = false;
}

bool World::humanAlive()
{
	return human;
}

bool World::game()
{
	return play;
}

void World::endGame()
{
	play = false;
}

void World::addComment(string org1, string action, string org2)
{
	comments[comment_i] = org1 + " " + action + " " + org2;
	comment_i++;
	comment_i = comment_i % (COMMENTS_AMOUNT+1);
	comments[comment_i] = "*********************************";
}

void World::printComments()
{
	for (int i = 0; i < COMMENTS_AMOUNT+1; i++)
	{
		if(comments[i] != "")
			cout<<comments[i]<<endl;
	}
}

void World::save()
{
	ofstream file("save.txt");
	file << width << " " << height<<endl;
	for (int i = 0; i < orgNum; i++)
	{

	}

}
