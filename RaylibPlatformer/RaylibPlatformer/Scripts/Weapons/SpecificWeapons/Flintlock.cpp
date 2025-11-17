#include "Flintlock.h"


Flintlock::Flintlock(int _worn, int _worndegrader, int ammo) :
	Gun(damage, _worn, worndegrader, ammo, weapontex, sweapontex, ammotex),WeaponInstance(), AllInstances<Flintlock>(this)
{
	unloadtexs.push_back(weapontex);
	unloadtexs.push_back(sweapontex);
	unloadtexs.push_back(ammotex);
}
Flintlock::~Flintlock()
{
	
}

void Flintlock::Draw(int _x, int _y)
{
	Rectangle texrect = { 0,0,weapontex.width, sweapontex.height };
	Rectangle texdestrect = { _x , _y , weapontex.width * 5, weapontex.height * 5 };
	Vector2 weaponorigin = { 0,0 };

	DrawTexturePro(weapontex, texrect, texdestrect, weaponorigin, 0.0f, RAYWHITE);
}