#ifndef NORMAL_NPC
#define NORMAL_NPC

#include "raylib.h"
#include <iostream>
#include <cmath>
#include <vector>
#include "../../CoreEngine/InstanceTracker.h"

class NormalNPC : public NPCInstance, AllInstances<NormalNPC>
{
public:
    float x, y;
    int dir = 1;
    const float radius = 50; // Half the width/height of the cube (50 / 2)
    float timer = 00.0f;
    int randy;
    NormalNPC(int _x, int _y, int _pref_direction, bool randomimg) : NPCInstance(), AllInstances<NormalNPC>(this)
    {
        x = _x;
        y = _y;
        dir = _pref_direction;
        if (randomimg)
        {
            // Add image load here, currently early stage which means it will simply be an arrow which points in its desired path
        }
    }

    void Update()
    {
        timer += GetFrameTime();
        x += dir;  // Move in the given direction
        randy = static_cast<float>(rand() % 800);
        if (timer >= 5)
        {
            cout << randy << endl; 
            timer = 0;
        }
            
        if (y < randy) { y += 1.0f; }
        else if (y > randy) { y -= 1.0f; }

        // Optional: remove boid-like behavior
        /*
        for (auto& npc : AllInstances<NormalNPC>::objects)
        {
            if (npc != this )
            {
                float dx = npc->x - x;
                float dy = npc->y - y;
                float distance = sqrt(dx * dx + dy * dy);

                if (distance < radius * 2) // Sum of radii (circle collider)
                {
                    // Boids in crash course
                    if (dir == 1)
                    {
                        y += 1;
                    }
                    else
                    {
                        y -= 1;
                    }
                }
                else
                {
                    cout << "Clear" << endl;
                }
            }
        }
        */
    }

    void Draw()
    {
        // Draw the circle collider for visualization (optional)
        DrawCircle(x + 25, y + 25, radius, Fade(RED, 0.3f)); // 30% opacity
        // Draw the rectangle (for testing purposes)
        DrawRectangle(x, y, 50, 50, ORANGE);
    }
};

#endif
