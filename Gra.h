#pragma once
class Gra
{
public:
	bool status;
	Gra();
	~Gra();
	int render();
	void create();
	void dispose();
	void checkInput();
};
