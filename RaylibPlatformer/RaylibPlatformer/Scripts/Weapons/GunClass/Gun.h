#ifndef GUN_H
#define GUN_H

#include "../Weapon.h"


class Gun : public Weapon
{
public:
	Texture2D ammotex;
	Gun(int _damage, int _worn, int _worndegrader, int ammo, Texture2D _weapontex, Texture2D _sweapontex, Texture2D _ammotex);
	~Gun();
	
};

#endif