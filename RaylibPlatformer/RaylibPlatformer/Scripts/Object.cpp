#include "Object.h"
Object::Object(int x, int y, Texture2D basetx)
{
	x = x;
	y = y;
	width = basetx.width;
	height = basetx.height;
	ctex = basetx;
}

Object::~Object()
{

}

void Object::ChangeCtex(Texture2D _newctex)
{
	ctex = _newctex;
}