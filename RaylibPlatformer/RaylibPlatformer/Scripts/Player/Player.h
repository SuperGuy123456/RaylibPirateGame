#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "../Ship/Ship.h"
#include <vector>
#include <iostream>
#include "../Object.h"
#include "../CoreEngine/InstanceTracker.h"
#include "../Weapons/SpecificWeapons/Flintlock.h"
using namespace std;

class Player
{
public:
	int x;
	int y;
	int boby = 0;
	int depth;
	int bobtimer = 0;
	float bobamount = 1.1f;

	Player(int _x, int _y, int _startdepth, Ship* _ship);
	~Player();

	void Draw();
	void Update();
	void setCoords(vector<Object> _object);
	void setWeapons()
	{
		vector<Weapon*> weapons;
		for (int i = 0; i < AllInstances<Flintlock>::objects.size(); i++)
		{
			weapons.push_back(AllInstances<Flintlock>::objects[i]);
		}
	}

	bool controllingship = false;
	bool canchangey = true;
private:
	void nextFrame();
	float timer = 0.0f;
	int idleindex= 0;
	int runindex = 0;
	/*Texture2D IdleTexs[4] = {LoadTexture("D:/C++/RaylibPlatformer/RaylibPlatformer/images/Player/Idle/idle_0.png"),
		LoadTexture("D:/C++/RaylibPlatformer/RaylibPlatformer/images/Player/Idle/idle_1.png"),
		LoadTexture("D:/C++/RaylibPlatformer/RaylibPlatformer/images/Player/Idle/idle_2.png"),
		LoadTexture("D:/C++/RaylibPlatformer/RaylibPlatformer/images/Player/Idle/idle_3.png")};*/
	Texture2D idle0 = LoadTexture("./images/Player/Idle/idle_0.png");
	Texture2D idle1 = LoadTexture("./images/Player/Idle/idle_1.png");
	Texture2D idle2 = LoadTexture("./images/Player/Idle/idle_2.png");
	Texture2D idle3 = LoadTexture("./images/Player/Idle/idle_3.png");
	Texture2D idleTexs[4] = { idle0,idle1,idle2,idle3 };

	Texture2D run0 = LoadTexture("./images/Player/Run/run_0.png");
	Texture2D run1 = LoadTexture("./images/Player/Run/run_1.png");
	Texture2D run2 = LoadTexture("./images/Player/Run/run_2.png");
	Texture2D run3 = LoadTexture("./images/Player/Run/run_3.png");
	Texture2D run4 = LoadTexture("./images/Player/Run/run_4.png");
	Texture2D run5 = LoadTexture("./images/Player/Run/run_5.png");
	Texture2D runTexs[6] = { run0,run1,run2,run3, run4, run5};

	bool rightHeld = false;
	bool leftHeld = false;
	bool upHeld = false;
	bool downHeld = false;
	
	bool onGround = false;
	int facingleft = -1;
	int screenWidth = 1800;
	int screenHeight = 800;
	Ship* ship;
	vector<Texture2D> alltexs;
	vector<Vector2> allpos;
};
#endif