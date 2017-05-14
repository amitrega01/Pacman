#include "Fruit.h"
#include "Stos.h"
#include "Cords.h"

Stos::Stos() {
	wierzcholek = nullptr;
}

void Stos::push(Fruit* owoc) { //dodaje element na stos
	ElStosu *bufor;
	bufor = new ElStosu(owoc);
	bufor->zmienNast(wierzcholek);
	wierzcholek = bufor;
	bufor = nullptr;
}

void Stos::wyswietl() { //wyswielta elementy stsu od lewej do prawej
	ElStosu *bufor = wierzcholek;
	while (bufor != nullptr) {
		bufor->wyswietl();
		bufor = bufor->pobierzNast();
	}
}

ElStosu* Stos::pop() { //usuwa element ze stosu i zwraca go
	ElStosu *bufor = wierzcholek;
	if (wierzcholek != nullptr)
	{
		wierzcholek = wierzcholek->pobierzNast();
	}

	return bufor;
}

int Stos::policz() {
	ElStosu *bufor = wierzcholek;
	int a = -1;
	while (bufor != nullptr) {
		bufor = bufor->pobierzNast();
		a++;
	}
	return a;
}

void Stos::czysc() { //czysci stos
	ElStosu *bufor;
	while (wierzcholek != nullptr) {
		bufor = wierzcholek;
		wierzcholek = wierzcholek->pobierzNast();
		delete bufor;
	}
}

Stos::~Stos() {
	czysc();
}