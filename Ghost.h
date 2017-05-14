#include "Mapa.h"
#pragma once
class Ghost
{
public:
	int posX;
	int posY;
	int speedX;
	int speedY;
	int color;
	Ghost(int x, int y, int c, int sx, int sy);
	~Ghost();

	void draw(Mapa * mapa);

	void move(Mapa * mapa);
};
