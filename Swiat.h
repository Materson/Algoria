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
	

	void wykonajTure();

	void rysujSwiat();

	Organizm* losujOrganizm();
};