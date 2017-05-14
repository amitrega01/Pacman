#include "Mapa.h"
#include "Cords.h"
#include <iostream>

using namespace std;

Mapa::Mapa()
{
}

Mapa::~Mapa()
{
}
void Mapa::draw() {
	HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(con, 01);
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			if (map[i][j] == 1) cout << (char)219;
			else if (map[i][j] == 7)  cout << (char)176;
			else if (map[i][j] == 3)  cout << (char)178;
			else cout << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(con, 15);
}