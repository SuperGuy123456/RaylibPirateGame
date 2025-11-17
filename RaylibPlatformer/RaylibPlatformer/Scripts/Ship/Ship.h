#ifndef SHIP_H
#define SHIP_H

#include "raylib.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Ship
{

public:
	string type = "Starter";
	int topdowntrue = 1;
	int x, y, depth,screenwidth,screenheight;
	Ship(int _x, int _y, int _depth, int _screenx, int _screeny);
	~Ship();
	void Draw();
	void Update();
	Vector2 position;
	float direction;

private:
	Texture2D SideTex = LoadTexture("./images/Ship/StarterShip/StarterShipSide.png");
	Texture2D TopTex = LoadTexture("./images/Ship/Startership/StarterShipTopView.png");

	Texture2D Texs[2] = { SideTex,TopTex };

	Rectangle SidetexsourceRec = { 0, 0, (float)SideTex.width, (float)SideTex.height };
	Rectangle SidetexdestRec = { 0, 0, (float)SideTex.width * 4, (float)SideTex.height * 2 };
	Vector2 Sidetexorigin = { 0, 0 };

	//Resize Texture data

	Rectangle ToptexsourceRec = { 0, 0, (float)TopTex.width, (float)TopTex.height };
	Rectangle ToptexdestRec = { 800, 600, (float)TopTex.width * 10, (float)TopTex.height * 10 };
	Vector2 toptexorigin = { 80, 180 };
	float toprotation = 0.0f;

	//keyboard input

	bool holdingright = false;
	bool holdingleft = false;
	bool holdingforward = false;
	float forwardspeed = 0.0f;
};

#endif