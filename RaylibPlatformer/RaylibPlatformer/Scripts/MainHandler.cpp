#include "MainHandler.h"

MainHandler::MainHandler(Player* _player)
{
    player = _player;
}

MainHandler::~MainHandler()
{
}

void MainHandler::StartCine()
{
    OpeningCutscene openingcutscene();
}

void MainHandler::Draw()
{
    // Temporary sorted vector indices by the y position and the height of the objects
    vector<size_t> sortedIndices(alldraws.size());
    iota(sortedIndices.begin(), sortedIndices.end(), 0);

    // Sort the indices based on the y position and the height of the objects
    sort(sortedIndices.begin(), sortedIndices.end(), [this](size_t a, size_t b) {
        return (alldraws[a].y + alldraws[a].height) < (alldraws[b].y + alldraws[b].height);
        });

    // Draw the objects based on sorted order
    for (size_t i : sortedIndices)
    {
        // Draw objects that are in front of the player
        if (player->y + 100 <= alldraws[i].y + alldraws[i].height)
        {
            player->Draw();
            playerdrawn = true; // Prevent drawing the player again
        }

        // Draw the object using its texture and position
        DrawTexture(alldraws[i].ctex, alldraws[i].x, alldraws[i].y, WHITE);
    }

    // Draw the player if it hasn't been drawn yet
    if (!playerdrawn)
    {
        player->Draw();
    }
    playerdrawn = false;

    if (!player->canchangey)
    {
        DrawCircle(player->x, player->y + 100, 10, RED);
    }
    else
    {
        DrawCircle(player->x, player->y + 100, 10, GREEN);
    }
}

void MainHandler::addDrawCall(Object* _object)
{
    alldraws.push_back(*_object);
}
