#include "Gun.h"

Gun::Gun(int _damage, int _worn, int _worndegrader, int ammo, Texture2D _weapontex, Texture2D _sweapontex, Texture2D _ammotex)
    : Weapon(_damage, _worn, _worndegrader, false, _weapontex, _sweapontex), ammotex(_ammotex)
{
}

Gun::~Gun()
{
    UnloadTexture(ammotex);
}