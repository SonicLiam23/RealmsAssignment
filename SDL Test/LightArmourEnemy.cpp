#include "LightArmourEnemy.h"

void LightArmourEnemy::init()
{
    SetImage("EnemyArmour1.bmp");
    speed = 2;
    m_health = 12;
    m_invincibilityAfterHit = 0.5;
    m_dmg = 10;
}

LightArmourEnemy::LightArmourEnemy(SDL_Rect* target) : Enemy(target)
{
    init();
}

LightArmourEnemy::LightArmourEnemy(ObjectBase* target) : Enemy(target->GetPosition())
{
    init();
}
