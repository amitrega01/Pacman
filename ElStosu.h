#pragma once
#include "Fruit.h"

class ElStosu
{
public:
	Fruit *owoc;
	ElStosu* next;

	ElStosu(Fruit* inFruit);
	void dodaj(int x, int y);
	void wyswietl();
	void ElStosu::zmienNast(ElStosu *in);
	ElStosu* pobierzNast();
	ElStosu::~ElStosu();
};
