#include "Mapa.h"
#pragma once
class Pacman
{
public:
	int posX;
	int posY;
	int speedX;
	int speedY;

	Pacman(int x, int y);
	~Pacman();

	void draw(Mapa * mapa);

	void move(Mapa * mapa);

	void setPosition();

private:
};
