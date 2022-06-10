#ifndef  QUADTREE_H_
#define  QUADTREE_H_

#pragma once

#include <iostream>

#pragma region Datatypes
class Rectangle
{
private:
	int x, y, w, h;
public:
	Rectangle(int x, int y, int w, int h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
};

#pragma endregion


void QuadTreeTest();

#endif // !