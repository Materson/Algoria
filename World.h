#pragma once
#include "stdafx.h"
class Organism;
using namespace std;

class World
{
private:
	int height, width;
	int orgNum = 0;
	Organism ***map;
	Organism **order;

public:
	World(int width, int height);

	~World();
	
	int getHeight();

	int getWidth();

	void nextTurn();

	void drawWorld();

	/*Organism* randOrganism();*/

	void moveOrganism(Organism *org, int x, int y);

	char checkPlace(int x, int y);

	int findFreeSpace(int *x, int *y, int range);

	int randInt(int min, int max);

	void addOrganism(char image, int x, int y);

	void fillWorld();
	
	void battle(Organism *attacker, Organism *defender);

	void delOrganism(int x, int y);

	void setOrder();

	int static sortOrder(const void *or1, const void *or2);
	

	void collision(Organism *attacker, int x, int y);
};