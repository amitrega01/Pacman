#include "Pacman.h"
#include "Cords.h"
#include "Mapa.h"
#include <iostream>

using namespace std;

Pacman::Pacman(int x, int y) {
	posX = x;
	posY = y;
	speedX = 0;
	speedY = 0;
}

Pacman::~Pacman()
{
}

void Pacman::draw(Mapa* mapa) {
	move(mapa);
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	Cords::gotoXY(posX, posY);
	SetConsoleTextAttribute(con, 14);
	cout << (char)2;
	SetConsoleTextAttribute(con, 15);
}

void Pacman::move(Mapa* mapa) {
	if (mapa->map[posY][posX] == 5) posX = 0;
	else if (mapa->map[posY][posX] == 4) posX = 27;
	int nx = posX + speedX;
	int ny = posY + speedY;
	if (mapa->map[ny][nx] != 1)
	{
		posX = nx;
		posY = ny;

		return;
	}
	else {
		speedX = 0;
		speedY = 0;
		return;
	}
}