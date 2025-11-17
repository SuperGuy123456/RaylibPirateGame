#include "Chest.h"


Chest::~Chest()
{

}

void Chest::Draw()
{
	DrawTexture(closedtex, x, y, RAYWHITE);
}