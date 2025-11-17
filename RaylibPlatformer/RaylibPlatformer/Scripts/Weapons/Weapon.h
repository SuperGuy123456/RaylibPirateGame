#ifndef WEAPON_H
#define WEAPON_H

#include "raylib.h"
#include <vector>
#include <iostream>

using namespace std;

class Weapon
{
public:
	int damage;
	int worn;
	int worndegrader;
	bool melee;
	Texture2D weaponTexture;
	Texture2D sweaponTexture;
	vector<Texture2D> unloadtexs;
	Weapon(int _damage, int _worn, int _worndegrader, bool _melee, Texture2D _weapontex, Texture2D _weaponSilloette);
	~Weapon();
	virtual void Draw(int x, int y) = 0;
	virtual void DrawSilloette() = 0;
	virtual void Drawicon() = 0;
	virtual void DrawStats() = 0;
};

#endif