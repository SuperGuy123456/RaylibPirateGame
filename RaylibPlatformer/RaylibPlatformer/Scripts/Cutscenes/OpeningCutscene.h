#ifndef OPENGINGCUTSCENE_H
#define OPENGINGCUTSCENE_H

#include <iostream>
#include "raylib.h"
#include <math.h>
#include <iostream>
using namespace std;
class OpeningCutscene
{
public:
	OpeningCutscene();
	~OpeningCutscene();
	void Draw();
	bool playingcine = false;

private:
	float titlealpha = 0;
	Font piratescript = LoadFont("./Fonts/pixel_pirate.ttf");
	bool fading = false;
	float fade = 0.0f;
	Texture2D Shiptex = LoadTexture("./images/Ship/Cutscene/ShipWithPlayer.png");
	Texture2D Backtex = LoadTexture("./images/Ship/Cutscene/StormBack.png");
	Texture2D Wave1tex = LoadTexture("./images/Ship/Cutscene/Wave1.png");
	Texture2D Wave2tex = LoadTexture("./images/Ship/Cutscene/Wave2.png");
	Texture2D Wave3tex = LoadTexture("./images/Ship/Cutscene/Wave3.png");
	Texture2D Rain1tex = LoadTexture("./images/Ship/Cutscene/RainFrame1.png");
	Texture2D Rain2tex = LoadTexture("./images/Ship/Cutscene/RainFrame2.png");
	Texture2D Rain3tex = LoadTexture("./images/Ship/Cutscene/RainFrame3.png");
	Texture2D Rain4tex = LoadTexture("./images/Ship/Cutscene/RainFrame4.png");

	Texture2D Texs[5] = { Shiptex,Backtex,Wave1tex,Wave2tex,Wave3tex};
	Texture2D RainTexs[4] = { Rain1tex, Rain2tex, Rain3tex, Rain4tex };
	

	//Ship Rotation Variable

	float ShipRot = 0.0f;
	float timer = 0.0f;
	float raintimer = 0.0f;
	int rainindex = 0;

	//rain texture data

	Rectangle RaintexsourceRec = { 0, 0, (float)Rain1tex.width, (float)Rain1tex.height };
	Rectangle RaintexdestRec = { 0, 0, (float)Rain1tex.width * 4, (float)Rain1tex.height * 2 };
	Vector2 Raintexorigin = { 0, 0 };

	//Resize Texture data

	Rectangle ShiptexsourceRec = { 0, 0, (float)Shiptex.width, (float)Shiptex.height };
	Rectangle ShiptexdestRec = { 800, 600, (float)Shiptex.width * 10, (float)Shiptex.height * 10 };
	Vector2 Shiptexorigin = { 510, 510 };


	Rectangle WavesourceRec = { 0, 0, (float)Wave1tex.width, (float)Wave1tex.height };
	Vector2 WaveOrigin = { 0,0 };

	//Each Wave has a different destination rect
	Rectangle Wave1destRec = { 0, 650, 1800.0f, (float)Wave1tex.height * 10 };
	Rectangle Wave2destRec = { 0, 600, 1800.0f, (float)Wave2tex.height * 10 };
	Rectangle Wave3destRec = { 0, 550, 1800.0f, (float)Wave3tex.height * 10 };

	//Each Wave duplicate's x
	int Wave1dx = -1800;
	int Wave1dmultiplier = 4;
	int Wave2dx = -1800;
	int Wave2dmultiplier = 3;
	int Wave3dx = -1800;
	int Wave3dmultipilier = 2;
};
#endif