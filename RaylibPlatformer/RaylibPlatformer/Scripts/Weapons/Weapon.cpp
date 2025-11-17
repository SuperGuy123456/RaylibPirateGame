#include "Weapon.h"

Weapon::Weapon(int _damage, int _worn, int _worndegrader, bool _melee, Texture2D _weapontex, Texture2D _weaponSilloette)
{
	damage = _damage;
	worn = _worn;
	worndegrader = _worndegrader;
	melee = _melee;
	weaponTexture = _weapontex;
	sweaponTexture = _weaponSilloette;
	unloadtexs.push_back(weaponTexture);
	unloadtexs.push_back(sweaponTexture);
	cout << "Weapon contructer activated" << endl;
}
Weapon::~Weapon()
{
	int arraySize = sizeof(unloadtexs) / sizeof(unloadtexs[0]);
	for (size_t i = 0; i < arraySize; ++i)
	{
		UnloadTexture(unloadtexs[i]);
	}
	cout << "Weapon destructor ran" << endl;
}