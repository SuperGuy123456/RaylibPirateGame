#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"
#include <iostream>
class Object
{
public:
	int x;
	int y;
	int width;
	int height;
	Texture2D ctex;
	Object(int x, int y, Texture2D alltxs);
	~Object();

	void ChangeCtex(Texture2D _newctex);
};

#endif