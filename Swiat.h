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

	/*~Swiat()
	{
	for (int i = 0; i < height; i++)
	{
	for (int j = 0; j < width; j++)
	{
	delete(map[i][j]);
	}
	delete[](map[i]);
	}
	delete[](map);
	}*/

	void wykonajTure();

	void rysujSwiat();
};