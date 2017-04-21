#include"Sheep.h"

Sheep::Sheep(int power, int activity, World *world, int x, int y)
{
	this->power = power;
	this->activity = activity;
	this->world = world;
	this->x = x;
	this->y = y;
	this->prev_x = x;
	this->prev_y = y;
	image = 's';
}