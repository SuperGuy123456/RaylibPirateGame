#include "raylib.h"
#include <iostream>
#include <vector>

// Include header files
#include "AllIncludes.h"

using namespace std;

const int screenWidth = 1800;
const int screenHeight = 800; 
GameCamera camera;
int map[16][21] =
{ {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 2, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 2, 2, 2, 2},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 2, 2, 2, 2} };
void ParseMap() {
    for (int row = 0; row < 16; row++) {
        for (int col = 0; col < 21; col++) {
            // Calculate the base position
            int baseX = col * 120;
            int baseY = row * 120;

            // Get the adjusted position based on the camera
            int x = camera.Pos(100, 100).x;
            int y = camera.Pos(100, 100).y;

            // Draw the tiles
            if (map[row][col] == 1) {
                DrawRectangle(x, y, 120, 120, BLUE);
            }
            else if (map[row][col] == 2) {
                DrawRectangle(x, y, 120, 120, GREEN);
            }
            else if (map[row][col] == 3) {
                DrawRectangle(x, y, 120, 120, YELLOW);
            }
        }
    }
}



int main()
{
    InitWindow(screenWidth, screenHeight, "PixaPirate");
    SetTargetFPS(60);
    OpeningCutscene openingcine;
    Ship ship(screenWidth / 2, screenHeight / 2, 10, screenWidth, screenHeight);
    Player player(0, 0, 1, &ship);
    int rectx = 400;
    int recty = 100;
    MainHandler mainhandle(&player);
    Texture2D shiptex = LoadTexture("./images/Ship/StarterShip/StarterShipSide.png");
    Object shipobj(100, 100, shiptex);
    mainhandle.addDrawCall(&shipobj);
    player.setCoords(mainhandle.alldraws);
    
    Chest chest(100, 100, 1);
    Flintlock flintlock(0, 1, 20);
    Flintlock flintlock1(0, 1, 20);
    player.setWeapons();

    Texture2D gunHUD = LoadTexture("./images/UI/GunHUD.png");
    Rectangle srect = { 0,0,gunHUD.width, gunHUD.height };
    Rectangle drect = { 0,650, gunHUD.width * 5, gunHUD.height * 5 }; // 300 x 150
    Vector2 origin = { 0,0 };

    /*int y = 0;
    int x = 0;
    for (int i = 0; i < 500; i++)
    {
        new NormalNPC(x, y, true, true);
        y++;
    }*/
    //vector<Texture2D> oceantiles;
    //vector<Vector2> oceantilepos;
    //for (int y = 0; y <= 27; y++)
    //{
    //    for (int x = 0; x <= 59; x++)
    //    {
    //        oceantiles.push_back(LoadTexture("./images/Ocean/OceanTileF1.png"));
    //        oceantilepos.push_back(Vector2{ (float)x * 31.0f,(float)y * 31.0f });
    //    }
    //}
    while (!WindowShouldClose())
    {
        // Update logic
        camera.ChangePlayerPos(ship.position.x, ship.position.y);

        // Begin drawing
        BeginDrawing();
        ClearBackground(DARKBLUE);
        //for (int index = 0; index <= 1593; index++)
        //{
        //    DrawTexture(oceantiles[index], oceantilepos[index].x, oceantilepos[index].y,WHITE);
        //}
        // Draw ship
        openingcine.Draw();
        
        //chest.Draw();
        if (openingcine.playingcine == false)
        {
            //ParseMap();
            mainhandle.Draw();
            player.Update();
            DrawFPS(0, 0);
            player.setCoords(mainhandle.alldraws);
            camera.ChangePlayerPos(player.x, player.y);

            //cout << AllInstances<NormalNPC>::objects.size() << endl;
            /*for (int npcindex = 0; npcindex <= AllInstances<NormalNPC>::objects.size() - 1; npcindex++)
            {
                AllInstances<NormalNPC>::objects[npcindex]->Update();
                AllInstances<NormalNPC>::objects[npcindex]->Draw();
            }*/
            DrawRectangle(camera.Pos(200, 100).x, camera.Pos(200, 100).y, 10, 10, BLACK);
            DrawTexturePro(gunHUD, srect, drect, origin, 0.0f, WHITE);
            
        }
        EndDrawing();
    }
    //for (int i = 0; i <= 1593; i++)
    //{
    //    UnloadTexture(oceantiles[i]);
    //}
    UnloadTexture(gunHUD);
    UnloadTexture(shiptex);
    CloseWindow();
    return 0;
}
