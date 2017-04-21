#pragma once
class Organism;
using namespace std;

class World
{
private:
	int height, width;
	Organism ***map;

public:
	World(int width, int height);

	~World();
	
	int getHeight();

	int getWidth();

	void nextTurn();

	void drawWorld();

	Organism* randOrganism();

	void moveOrganism(int prev_x, int prev_y, int x, int y);

	char checkPlace(int x, int y);

	int findFreeSpace(int *x, int *y, int range);

	int randInt(int min, int max);

	void addOrganism(char image, int x, int y);

	void fillWorld();
	
	void battle(Organism *attacker, int x, int y);

	void delOrganism(int x, int y);
};