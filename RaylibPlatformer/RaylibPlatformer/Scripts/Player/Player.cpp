#include "Player.h"

Player::Player(int _x, int _y, int _startdepth, Ship* _ship)
{
    x = _x;
    y = _y;
    depth = _startdepth;
    ship = _ship;
}

Player::~Player()
{
    for (int i = 0; i <= 3; i++)
    {
        UnloadTexture(idleTexs[i]);
    }
    for (int i = 0; i <= 5; i++)
    {
        UnloadTexture(runTexs[i]);
    }
}

void Player::Draw()
{
    bobtimer += 1;
    if (controllingship)
    {
        ship->Draw();
    }
    else
    {
        Rectangle sourceRec = { 0, 0, idleTexs[idleindex].width * facingleft, idleTexs[idleindex].height };
        Rectangle runScourceRec = { 0,0, runTexs[runindex].width * facingleft, runTexs[runindex].height };
        if (leftHeld == false and rightHeld == false or (leftHeld && rightHeld))
        {
            DrawTextureRec(idleTexs[idleindex], sourceRec, { (float)800, (float)15+400 }, WHITE);
        }
        else if (!(leftHeld && rightHeld))
        {
            boby = cos(bobtimer * 0.13)*bobamount;
            cout << bobamount << endl;
            y += boby;
            DrawTextureRec(runTexs[runindex], runScourceRec, { (float)800, (float)boby+400 }, WHITE);
        }
    }
}

void Player::Update()
{
    if (controllingship)
    {
        ship->Update();
    }
    else
    {
        timer += GetFrameTime();
        /*
        **************************DEBUG: Control Bobrate, current is 1.1 ************************************
        if (IsKeyPressed(KEY_ONE))
        {
            bobamount += 0.1f;
        }
        if (IsKeyPressed(KEY_TWO))
        {
            bobamount -= 0.1f;
        }*/
        if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT))
        {
            rightHeld = true;
            facingleft = 1;
        }
        if (IsKeyReleased(KEY_D) or IsKeyReleased(KEY_RIGHT))
        {
            rightHeld = false;
        }

        if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT))
        {
            leftHeld = true;
            facingleft = -1;
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
        if (IsKeyDown(KEY_UP) or IsKeyDown(KEY_W))
        {
            upHeld = true;
        }
        if (IsKeyReleased(KEY_UP) or IsKeyReleased(KEY_W))
        {
            upHeld = false;
        }
        if (IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S))
        {
            downHeld = true;
        }
        if (IsKeyReleased(KEY_DOWN) or IsKeyReleased(KEY_S))
        {
            downHeld = false;
        }
        if (upHeld)
        {
            for (size_t i = 0; i < alltexs.size(); ++i)
            {
                // Check if the player is trying to move behind an object
                Rectangle playerrect = { x, y - 90, (float)idle0.width, 10 };
                Rectangle objrect = { allpos[i].x, allpos[i].y, (float)alltexs[i].width, (float)alltexs[i].height };
                if (CheckCollisionRecs(playerrect, objrect))
                {
                    canchangey = false;
                    y = allpos[i].y - 10; // Position player just below the object to avoid getting stuck
                    break;
                }
            }
            if (canchangey)
            {
                y -= 2;
            }
            canchangey = true;
        }
        if (downHeld)
        {
            for (size_t i = 0; i < alltexs.size(); ++i)
            {
                Rectangle playerrect = { x, y + 90, (float)idle0.width,10.0f };
                Rectangle objrect = { allpos[i].x, allpos[i].y + alltexs[i].height / 2, (float)alltexs[i].width, (float)alltexs[i].height / 2 };
                // Check if the player is trying to move in front of an object
                if (CheckCollisionRecs(playerrect, objrect))
                {
                    canchangey = false;
                    y = allpos[i].y + 10.0f; // Position player just above the object to avoid getting stuck
                    break;
                }
            }
            if (canchangey)
            {
                y += 2;
            }
            canchangey = true;
        }
        nextFrame();
    }
}

void Player::nextFrame()
{
    if (timer >= 0.13)
    {
        if (runindex == 5)
        {
            runindex = 0;
        }
        else
        {
            runindex += 1;
        }
        timer = 0.0f;
    }
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

void Player::setCoords(vector<Object> _object)
{
    alltexs.clear();
    allpos.clear();
    for (size_t i = 0; i < _object.size(); ++i)
    {
        alltexs.push_back(_object[i].ctex);
        allpos.push_back(Vector2{ (float)_object[i].x, (float)_object[i].y });
    }
}

