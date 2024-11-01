#include "raylib.h"
#include "iostream"

#include "./Scripts/Player/Player.h"

using namespace std;

const int screenWidth = 1800;
const int screenHeight = 800;

int main()
{
	InitWindow(screenWidth, screenHeight, "Raylib Platformer");
	SetTargetFPS(60);
	Player player(0,0,0);
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(SKYBLUE);
		player.Draw();
		player.Update();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}