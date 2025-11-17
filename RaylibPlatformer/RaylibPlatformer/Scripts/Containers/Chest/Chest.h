#ifndef CHEST_H
#define CHEST_H

#include "raylib.h"
#include <iostream>
#include <memory>
#include <vector>
#include "../../Object.h"
#include "../../CoreEngine/InstanceTracker.h"

using namespace std;
class Chest : public ContainerInstance , public AllInstances<Chest>
{
public:
	int x, y;
	Chest(int _x, int _y, vector<Object> _inventory, int _slots) : ContainerInstance(), AllInstances<Chest>(this)
	{
		x = _x;
		y = _y;
		for (int item = 0; item <= _inventory.size(); item++)
		{
			inventory.push_back(_inventory[item]);
		}
		capacity = _slots;
	}
	Chest(int _x, int _y, int _slots) : ContainerInstance(), AllInstances<Chest>(this)
	{
		x = _x;
		y = _y;
		capacity = _slots;
	}
	~Chest();
	vector<Object> inventory;
	int capacity = 5;
	void Draw();
private:
	Texture2D closedtex = LoadTexture("./images/Containers/WoodenChestClosed.png");
};

#endif