#pragma once
#include "stdafx.h"
class Organism;
using namespace std;

class World
{
private:
	int height, width;
	int orgNum = 0;
	bool human, play;
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

	void delOrganism(Organism *org, int x=0, int y=0);

	void setOrder();

	int static sortOrder(const void *or1, const void *or2);

	void collision(Organism *attacker, int x, int y);

	int checkOrganismPower(int x, int y);

	int checkOrganismActivity(int x, int y);

	void humanDie();

	bool humanAlive();

	bool game();

	void endGame();
};