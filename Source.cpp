#pragma comment(lib, "winmm.lib")
#include "Gra.h"
#include "Cords.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int m = 1;
Gra gra;
void menu() {
	Cords::gotoXY(9, 15);

	cout << "  PACMAN  " << endl;
	Cords::gotoXY(0, 31);
	cout << "1. START" << endl;
	cout << "Wybor: ";
	cin >> m;
	switch (m)
	{
	case 1: {
		while (gra.status)
		{
			gra.render();
		}
		gra.dispose();
		Cords::gotoXY(9, 15);
		cout << "Koniec Gry";
		system("pause > nul");
		menu();
		break;
	}

	case 4: return;
	default:
		break;
	}
}
void main() {
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(con, 15);
	//cout << "Dla najlepszego efektu wejdz w Wlasciwosci konsoli > Czcionka > Czcionki rastowe 8x8";
	system("pause > nul");
	menu();
}