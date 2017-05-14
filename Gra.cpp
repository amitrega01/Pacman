#include "Gra.h"
#include "Cords.h"
#include "Mapa.h"
#include "Ghost.h"
#include "Fruit.h"
#include "Pacman.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <ctime>

using namespace std;
Mapa* mapa;
Fruit* owoce[232];
Fruit* eOwoce[4];
Pacman* pac;
int score;
int a;
int lives;
HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
Ghost* duch[4];
Gra::Gra()
{
	score = 0;
	mapa = new Mapa();
	pac = new Pacman(13, 21);

	duch[0] = new Ghost(13, 11, 12, -1, 0);
	duch[1] = new Ghost(14, 11, 13, 1, 0);
	duch[2] = new Ghost(15, 11, 3, 0, 1);
	duch[3] = new Ghost(16, 11, 10, 0, -1);
	status = true;
	lives = 3;
	create();
	render();
	PlaySound(TEXT("pacman_beginning.wav"), NULL, SND_FILENAME | SND_ASYNC);
	Cords::gotoXY(0, 30);
}

Gra::~Gra()
{
	dispose();
}

int Gra::render() {
	Sleep(1000 / 15);

	system("cls");
	for (int i = 0; i < a; i++)
	{
		if (owoce[i] != nullptr)
		{
			if (pac->posX == owoce[i]->x && pac->posY == owoce[i]->y) {
				delete owoce[i];
				owoce[i] = nullptr;
				score += 11;
				PlaySound(TEXT("Laser_Shoot.wav"), NULL, SND_FILENAME | SND_ASYNC);
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (pac->posX == duch[i]->posX && pac->posY == duch[i]->posY)
		{
			if (lives > 1)
			{
				PlaySound(TEXT("pacman_death.wav"), NULL, SND_FILENAME | SND_ASYNC);
				lives--;
				delete pac;
				pac = new Pacman(13, 21);
			}
			else {
				lives--;
				PlaySound(TEXT("pacman_death.wav"), NULL, SND_FILENAME | SND_ASYNC);
				status = 0;
			}
		}
	}
	mapa->draw();
	for (int i = 0; i < a; i++)
		if (owoce[i] != nullptr) owoce[i]->draw();
	for (int i = 0; i < 4; i++)
		if (eOwoce[i] != nullptr) eOwoce[i]->drawE();
	for (int i = 0; i < 4; i++)
	{
		duch[i]->draw(mapa);
	}
	pac->draw(mapa);

	checkInput();
	Cords::gotoXY(0, 30);
	cout << "SCORE: " << score << "\t\t";
	SetConsoleTextAttribute(con, 14);
	for (int i = 0; i < lives; i++)
	{
		cout << (char)2;
	}
	SetConsoleTextAttribute(con, 15);
	return 1;
}
void Gra::checkInput() {
	if (_kbhit()) {
		char key = _getch();
		switch (key) {
		case 'd': {
			if (mapa->map[pac->posY][pac->posX + 1] == 0 || mapa->map[pac->posY][pac->posX + 1] == 2 || mapa->map[pac->posY][pac->posX + 1] == 9)
			{
				pac->speedX = 1;
				pac->speedY = 0;
			}
			break;
		}
		case 's': {
			if (mapa->map[pac->posY + 1][pac->posX] == 0 || mapa->map[pac->posY + 1][pac->posX] == 2 || mapa->map[pac->posY + 1][pac->posX] == 9)
			{
				pac->speedX = 0;
				pac->speedY = 1;
			}
			break;
		}
		case 'a': {
			if (mapa->map[pac->posY][pac->posX - 1] == 0 || mapa->map[pac->posY][pac->posX - 1] == 2 || mapa->map[pac->posY][pac->posX - 1] == 9)
			{
				pac->speedX = -1;
				pac->speedY = 0;
			}
			break;
		}
		case 'w': {
			if (mapa->map[pac->posY - 1][pac->posX] == 0 || mapa->map[pac->posY - 1][pac->posX] == 2 || mapa->map[pac->posY - 1][pac->posX] == 9)
			{
				pac->speedX = 0;
				pac->speedY = -1;
			}
			break;
		}
		default:
			break;
		}
	}
	return;
}

void Gra::create() {
	a = 0;
	int b = 0;
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			if (mapa->map[i][j] == 2)
			{
				owoce[a] = new Fruit(j, i);
				a++;
			}
			else if (mapa->map[i][j] == 9)
			{
				eOwoce[b] = new Fruit(j, i);
				b++;
			}
		}
	}
}
void Gra::dispose() {
}