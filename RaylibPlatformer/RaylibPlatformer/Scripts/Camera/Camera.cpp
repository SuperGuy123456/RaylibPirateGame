#include "Camera.h"

GameCamera::GameCamera() {};

void GameCamera::ChangePlayerPos(int _x, int _y) {
    playerposx = _x;
    playerposy = _y;
}

Vector2 GameCamera::Pos(int _x, int _y) {
    Vector2 screenPos;
    screenPos.x = (_x - playerposx + screenwidth / 2) + 500;
    screenPos.y = (_y - playerposy + screenheight / 2)-500;
    return screenPos;
}

bool GameCamera::InScreen(int _x, int _y) {
    Vector2 screenPos = Pos(_x, _y);
    return (screenPos.x >= 0 && screenPos.x <= screenwidth &&
        screenPos.y >= 0 && screenPos.y <= screenheight);
}
