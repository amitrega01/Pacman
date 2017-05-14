#include "Fruit.h"
#include "ElStosu.h"

ElStosu::ElStosu(Fruit* inFruit) {
	next = nullptr;
	owoc = inFruit;
}
void ElStosu::dodaj(int x, int y) {
	owoc = new Fruit(x, y);
}

void ElStosu::wyswietl() {
	owoc->draw();
}

void ElStosu::zmienNast(ElStosu *in) {
	next = in;
}

ElStosu* ElStosu::pobierzNast() {
	return next;
}

ElStosu::~ElStosu() {
	delete owoc;
	owoc = nullptr;
}