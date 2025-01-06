#include "Enemy.h"
#include "Engine.h"
#include "Tower.h"

#include <iostream>

Enemy::Enemy(ObjectBase* Target) : m_Target(Target->GetPosition())
{
    init();
}

Enemy::Enemy(SDL_Rect* Target) : m_Target(Target)
{
    init();
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
        if (OB->GetName() == "Tower")
        {
            Tower* TowerOB = (Tower*)OB;
            std::cout << TowerOB->GetDamage();
            
        }
        //else if (OB->GetName() == "Coin")
        //{
        //    Engine::Get()->DeleteObject(OB);
        //    Engine::Get()->DeleteObject(this);
        //}
    }
}

const char* Enemy::GetName()
{
    return "Enemy";
}

void Enemy::init()
{
    speed = 2;
}

void Enemy::Execute()
{
}
