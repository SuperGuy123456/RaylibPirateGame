#ifndef MAINHANDLER_H
#define MAINHANDLER_H
#include "Cutscenes/OpeningCutscene.h"
#include "Player/Player.h"
#include "Object.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
class MainHandler
{
public:
	MainHandler(Player* _player);
	~MainHandler();
	void StartCine();
	void Draw();
	//Object has a x attribute, y attribute, height attribute, and width attribute. doing [object].width or height will get the value. also, has [object].ctex (that is the texture to draw)
	void addDrawCall(Object* _object);
	vector<Object> alldraws;
private:
	Player* player;
	bool playerdrawn = false;
};

#endif