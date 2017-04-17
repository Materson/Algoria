#pragma once
class Swiat
{
private:
	int height, width;
protected:
	char **map;
public:
	Swiat(int width, int height)
		:width(width), height(height)
	{
		map = new char*[height];
		for (int i = 0; i < height; i++)
		{
			map[i] = new char[width];
		}
	}
	void wykonajTure()
	{

	}

	void rysujSwiat()
	{

	}
};