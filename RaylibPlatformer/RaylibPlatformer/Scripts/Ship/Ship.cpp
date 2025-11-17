#include "Ship.h"

Ship::Ship(int _x, int _y, int _depth, int _screenx, int _screeny) {
    position = { (float)_x, (float)_y };
    direction = 0.0f;
    depth = _depth;
    screenwidth = _screenx;
    screenheight = _screeny;
    SidetexdestRec = { position.x, position.y, (float)SideTex.width * 4, (float)SideTex.height * 2 };
    ToptexdestRec = { position.x, position.y, (float)TopTex.width * 10, (float)TopTex.height * 10 };
}

Ship::~Ship() {
    for (int i = 0; i <= 1; i++) {
        UnloadTexture(Texs[i]);
    }
}

void Ship::Draw() {
    DrawTexturePro(TopTex, ToptexsourceRec, ToptexdestRec, toptexorigin, toprotation, WHITE);
}

void Ship::Update() {
    SidetexdestRec = { position.x, position.y, (float)SideTex.width * 4, (float)SideTex.height * 2 };
    //ToptexdestRec = { position.x, position.y, (float)TopTex.width * 10, (float)TopTex.height * 10 };
    ToptexdestRec = { 900, 400, (float)TopTex.width * 10, (float)TopTex.height * 10 };

    if (IsKeyDown(KEY_UP)) {
        holdingforward = true;
    }
    if (IsKeyReleased(KEY_UP)) {
        holdingforward = false;
    }
    if (holdingforward) {
        forwardspeed += 0.5f;
    }
    if (IsKeyDown(KEY_LEFT)) {
        holdingleft = true;
    }
    if (IsKeyReleased(KEY_LEFT)) {
        holdingleft = false;
    }
    if (holdingleft && forwardspeed > 0) {
        toprotation -= 0.1f * forwardspeed; // Adjust rotation speed based on forward speed
    }
    if (IsKeyDown(KEY_RIGHT)) {
        holdingright = true;
    }
    if (IsKeyReleased(KEY_RIGHT)) {
        holdingright = false;
    }
    if (holdingright && forwardspeed > 0) {
        toprotation += 0.1f * forwardspeed; // Adjust rotation speed based on forward speed
    }

    if (holdingforward) {
        // Calculate the change in position using the direction angle
        float radians = DEG2RAD * toprotation; // Convert degrees to radians
        position.x += sin(radians) * forwardspeed;
        position.y -= cos(radians) * forwardspeed;
    }

    if (forwardspeed < 0.5) {
        forwardspeed = 0.0f;
    }
    else {
        forwardspeed -= 0.5;
    }

    //cout << "Forward Speed: " << forwardspeed << " | X: " << position.x << " | Y: " << position.y << " | Rotation: " << toprotation << endl;
}
