#pragma once
#include<iostream>
#include"Organizm.h"
#include"Zwierze.cpp"
using namespace std;

class Swiat
{
private:
	int height, width;
protected:
	Organizm ***map;
public:
	Swiat(int width, int height)
		:width(width), height(height)
	{
		map = new Organizm**[height];
		for (int i = 0; i < height; i++)
		{
			map[i] = new Organizm*[width];
		}

		for(int i=0; i<height; i++)
			for (int j = 0; j < width; j++)
			{
				map[i][j] = new Zwierze(0, 0);
			}
	}

	~Swiat()
	{
		for (int i = 0; i < height; i++)
		{
			delete[](*map);
		}
		delete[](map);
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
				if (i % 2 == 1 && j % 2 == 1) map[i/2][j/2]->rysowanie();
			}
			cout << endl;
		}
	}
};