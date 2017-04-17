#pragma once
#include<iostream>
using namespace std;

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
		for (int i = 0; i <= height * 2; i++)
		{
			for (int j = 0; j <= width * 2; j++)
			{
				if (i % 2 == 0 && j%2 == 0) cout << "+";
				else if (i % 2 == 0 && j % 2 == 1) cout << "-";

				if (i % 2 == 1 && j % 2 == 0)cout << "|";
				if (i % 2 == 1 && j % 2 == 1)cout << " ";
			}
			cout << endl;
		}
	}
};