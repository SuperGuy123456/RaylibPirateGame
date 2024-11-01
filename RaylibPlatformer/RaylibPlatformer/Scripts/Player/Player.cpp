#include "Player.h"

Player::Player(int _x, int _y, int _startdepth)
{
	x = _x;
	y = _y;
	depth = _startdepth;
}
Player::~Player()
{
	for (int i = 0; i<=3; i++)
	{
		UnloadTexture(idleTexs[i]);
	}

}
void Player::Draw()
{
	//DrawTexture(IdleTexs[idleindex], x, y, LIGHTGRAY);
	DrawTexture(idleTexs[idleindex], x, y, RAYWHITE);
}

void Player::Update()
{
	timer += GetFrameTime();
	if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT))
	{
		rightHeld = true;
	}
	if (IsKeyReleased(KEY_D) or IsKeyReleased(KEY_RIGHT))
	{
		rightHeld = false;
	}

	if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT))
	{
		leftHeld = true;
	}
	if (IsKeyReleased(KEY_A) or IsKeyReleased(KEY_LEFT))
	{
		leftHeld = false;
	}
	if (rightHeld or leftHeld)
	{
		if (rightHeld)
		{
			x += 2;
		}
		if (leftHeld)
		{
			x -= 2;
		}
	}
	else
	{
		nextFrame();
	}
}

void Player::nextFrame()
{
	if (timer >= 0.15)
	{
		if (idleindex == 3)
		{
			idleindex = 0;
		}
		else
		{
			idleindex += 1;
		}
		timer = 0.0f;
	}
}