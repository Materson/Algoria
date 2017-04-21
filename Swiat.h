#pragma once
class Organizm;
using namespace std;

class Swiat
{
private:
	int height, width;
	Organizm ***map;

public:
	Swiat(int width, int height);

	~Swiat();
	
	int getHeight();

	int getWidth();

	void wykonajTure();

	void rysujSwiat();

	Organizm* losujOrganizm();

	void moveOrganism(int prev_x, int prev_y, int x, int y);

	char checkPlace(int x, int y);

	int findFreeSpace(int *x, int *y, int range);

	int randInt(int min, int max);

	void addOrganism(char image, int x, int y);
};