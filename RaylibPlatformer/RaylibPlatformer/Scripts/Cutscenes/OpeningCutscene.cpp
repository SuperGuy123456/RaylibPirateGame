#include "OpeningCutscene.h"

OpeningCutscene::OpeningCutscene()
{
	
}

OpeningCutscene::~OpeningCutscene()
{
	for (int i = 0; i <= 4; i++)
	{
		UnloadTexture(Texs[i]);
	}
	for (int i = 0; i <= 3; i++)
	{
		UnloadTexture(RainTexs[i]);
	}
}

void OpeningCutscene::Draw()
{
	if (playingcine)
	{
		Rectangle Wave1ddestRec = { Wave1dx, 650, 1800.0f, (float)Wave1tex.height * 10 };
		Rectangle Wave2ddestRec = { Wave2dx, 600, 1800.0f, (float)Wave2tex.height * 10 };
		Rectangle Wave3ddestRec = { Wave3dx, 550, 1800.0f, (float)Wave3tex.height * 10 };

		Rectangle Wave1destRec = { Wave1dx + 1800, 650, 1800.0f, (float)Wave1tex.height * 10 };
		Rectangle Wave2destRec = { Wave2dx + 1800, 600, 1800.0f, (float)Wave2tex.height * 10 };
		Rectangle Wave3destRec = { Wave3dx + 1800, 550, 1800.0f, (float)Wave3tex.height * 10 };

		Wave1dx += Wave1dmultiplier;
		Wave2dx += Wave2dmultiplier;
		Wave3dx += Wave3dmultipilier;

		DrawTexture(Backtex, 0, 0, RAYWHITE);
		DrawTexturePro(Wave3tex, WavesourceRec, Wave3destRec, WaveOrigin, 0.0f, WHITE);
		DrawTexturePro(Wave3tex, WavesourceRec, Wave3ddestRec, WaveOrigin, 0.0f, WHITE);
		DrawTexturePro(Shiptex, ShiptexsourceRec, ShiptexdestRec, Shiptexorigin, ShipRot, WHITE);
		DrawTexturePro(Wave2tex, WavesourceRec, Wave2destRec, WaveOrigin, 0.0f, WHITE);
		DrawTexturePro(Wave2tex, WavesourceRec, Wave2ddestRec, WaveOrigin, 0.0f, WHITE);
		DrawTexturePro(Wave1tex, WavesourceRec, Wave1destRec, WaveOrigin, 0.0f, WHITE);
		DrawTexturePro(Wave1tex, WavesourceRec, Wave1ddestRec, WaveOrigin, 0.0f, WHITE);

		DrawTexturePro(RainTexs[rainindex], RaintexsourceRec, RaintexdestRec, Raintexorigin, 0.0f, Color{ 255, 255, 255, (unsigned char)(150) });
		ShipRot = sin(timer * 3) * 5; // Use the accumulated time for smoother rotation
		timer += GetFrameTime();
		raintimer += GetFrameTime();

		
		if (timer >= 6.0f)
		{
			playingcine = false;
		}
		else if (raintimer >= 0.1f)
		{
			if (rainindex < 3)
			{ 
				rainindex += 1; 
			}
			else
			{
				rainindex = 0;
			}
			raintimer = 0.0f;
		}
		DrawTextEx(piratescript, "Created By Manomay Tyagi", { 0,0 }, 50, 10, RED);
		DrawTextEx(piratescript, "PIXAPIRATE", { 1800 / 2 - 400,800/2-100 }, 100, 10, Color{ 255, 0, 0, (unsigned char)(titlealpha) });
		if (titlealpha < 220)
		{
			titlealpha += 5.25f;
		}
		else
		{
			titlealpha = 255;
			fading = true;
		}
		if (fading)
		{
			DrawRectangle(0, 0, 1800, 800, Color{ 0,0,0,(unsigned char)(fade) });
			fade += 0.7f;
		}
	}	

}