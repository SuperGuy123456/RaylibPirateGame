#ifndef WEAPONS_HUD
#define WEAPONS_HUD

#include "../InstanceTracker.h"
#include "../../Weapons/SpecificWeapons/Flintlock.h"
#include "raylib.h"
class WeaponsHUD
{
public:
	WeaponsHUD() {};
	~WeaponsHUD() {};

	void DrawShadows()
	{
		for (int i = 0; i < AllInstances<Flintlock>::objects.size(); i++)
		{

		}
	}
};

#endif