#include "Ghost.h"
#include "Cords.h"
#include "Mapa.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

Ghost::Ghost(int x, int y, int c, int sx, int sy)
{
	posX = x;
	posY = y;
	speedX = sx;
	speedY = sy;
	color = c;
}

Ghost::~Ghost()
{
}

void Ghost::draw(Mapa* mapa) {
	move(mapa);
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	Cords::gotoXY(posX, posY);
	SetConsoleTextAttribute(con, color);
	cout << (char)4;
	SetConsoleTextAttribute(con, 15);
}

void Ghost::move(Mapa* mapa) {
	srand(time(NULL));
	int nx, ny;
	int d;

	while (mapa->map[posY + speedY][posX + speedX] == 1) {
		d = std::rand() % 4;
		switch (d)
		{
		case 0: {
			speedX = 1;
			speedY = 0;
			break;
		}
		case 1: {
			speedX = -1;
			speedY = 0;
			break;
		}
		case 2: {
			speedX = 0;
			speedY = 1;
			break;
		}
		case 3: {
			speedX = 0;
			speedY = -1;
			break;
		}
		default:
			break;
		}
	}

	posX = posX + speedX;
	posY = posY + speedY;
}