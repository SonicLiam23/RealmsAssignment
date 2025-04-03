#include "HeavyArmourEnemy.h"

void HeavyArmourEnemy::init()
{
    SetImage("EnemyArmour2.bmp");
    speed = 1;
    m_health = 25;
    m_invincibilityAfterHit = 0.5;
    m_dmg = 10;
}

HeavyArmourEnemy::HeavyArmourEnemy(SDL_Rect* target) : Enemy(target)
{
    init();
}

HeavyArmourEnemy::HeavyArmourEnemy(ObjectBase* target) : Enemy(target->GetPosition())
{
    init();
}
