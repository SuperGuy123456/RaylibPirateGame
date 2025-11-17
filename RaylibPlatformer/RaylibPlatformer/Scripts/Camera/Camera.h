#ifndef GAME_CAMERA_H
#define GAME_CAMERA_H

#include "raylib.h"

class GameCamera {
public:
    GameCamera();
    int playerposx = 0;
    int playerposy = 0;
    int screenwidth = 800;
    int screenheight = 1800;
    bool InScreen(int _x, int _y);
    Vector2 Pos(int _x, int _y);
    void ChangePlayerPos(int _x, int _y);
};

#endif
