#pragma once

#include "ElStosu.h"
class Stos
{
private:

public:
	Stos();
	~Stos();
	ElStosu* wierzcholek;
	void push(Fruit *owoc);
	ElStosu* pop();
	int policz();

	void wyswietl();

	void czysc();
};
