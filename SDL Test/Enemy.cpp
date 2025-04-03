#include "Enemy.h"
#include "Engine.h"
#include "Tower.h"
#include "Wall.h"
#include "IState.h"
#include "Coin.h"
#include <iostream>

Enemy::Enemy(ObjectBase* Target) : m_Target(Target->GetPosition())
{
    init();
}

Enemy::Enemy(SDL_Rect* Target) : m_Target(Target)
{
    init();
}

float Enemy::GetInvincibilityTime()
{
    return m_invincibilityAfterHit;
}

int Enemy::GetDamage()
{
    return m_dmg;
}

void Enemy::Update()
{
    // enemies should just chase the player for now
    int dir = m_Target->x - rect.x;
    if (dir != 0)
    {
        dir = (dir > 0 ? 1 : -1);
        
        rect.x += dir * speed;
    }

    for (ObjectBase* OB : Engine::Get()->GetAllCollisionsWith(this))
    {
        
    }

    if (m_currentInv > 0)
    {
        m_currentInv -= Engine::Get()->DT();
    }

}

const char* Enemy::GetName()
{
    return "Enemy";
}

void Enemy::init()
{
    SetImage("Enemy.bmp");
    speed = 2;
    m_health = 4;
    m_invincibilityAfterHit = 0.5;
    m_dmg = 10;
}

void Enemy::Execute()
{
}

