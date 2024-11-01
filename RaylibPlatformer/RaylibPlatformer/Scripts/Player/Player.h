#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include <iostream>

using namespace std;

class Player
{
public:

	int x;
	int y;
	int depth;

	Player(int _x, int _y, int _startdepth);
	~Player();

	void Draw();
	void Update();
	void CheckInput();
private:
	void nextFrame();
	float timer = 0.0f;
	int idleindex= 0;
	/*Texture2D IdleTexs[4] = {LoadTexture("D:/C++/RaylibPlatformer/RaylibPlatformer/images/Player/Idle/idle_0.png"),
		LoadTexture("D:/C++/RaylibPlatformer/RaylibPlatformer/images/Player/Idle/idle_1.png"),
		LoadTexture("D:/C++/RaylibPlatformer/RaylibPlatformer/images/Player/Idle/idle_2.png"),
		LoadTexture("D:/C++/RaylibPlatformer/RaylibPlatformer/images/Player/Idle/idle_3.png")};*/
	Texture2D idle0 = LoadTexture("./images/Player/Idle/idle_0.png");
	Texture2D idle1 = LoadTexture("./images/Player/Idle/idle_1.png");
	Texture2D idle2 = LoadTexture("./images/Player/Idle/idle_2.png");
	Texture2D idle3 = LoadTexture("./images/Player/Idle/idle_3.png");
	Texture2D idleTexs[4] = { idle0,idle1,idle2,idle3 };

	bool rightHeld = false;
	bool leftHeld = false;
	bool onGround = false;
	
};
#endif