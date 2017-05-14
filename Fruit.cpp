#include "Fruit.h"
#include "Cords.h"
#include <iostream>

using namespace std;

Fruit::Fruit(int x, int y)
{
	this->x = x;
	this->y = y;
}

Fruit::~Fruit()
{
}

void Fruit::draw() {
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	Cords::gotoXY(x, y);

	SetConsoleTextAttribute(con, 15);
	cout << (char)254;
}
void Fruit::drawE() {
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	Cords::gotoXY(x, y);

	SetConsoleTextAttribute(con, 55);
	//cout << (char)8;
	cout << (char)254;

	SetConsoleTextAttribute(con, 15);
}