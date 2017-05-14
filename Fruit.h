#pragma once
class Fruit
{
public:
	int x;
	int y;
	Fruit(int x, int y);
	~Fruit();
	void setPosition(int x, int y);
	void draw();
	void drawE();
	void eat();
};
