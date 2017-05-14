#pragma once
#include <Windows.h>

#include <iostream>
class Cords
{
public:
	Cords();
	~Cords();
	static void gotoXY(int x, int y);
	static void getCursorXY(int &x, int&y);
};
