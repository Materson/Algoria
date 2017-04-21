#include"Wolf.h"

Wolf::Wolf(int sila, int inicjatywa, World *world, int x, int y)
{
	this->power = sila;
	this->activity = inicjatywa;
	this->world = world;
	this->x = x;
	this->y = y;
	this->prev_x = x;
	this->prev_y = y;
	image = 'w';
}