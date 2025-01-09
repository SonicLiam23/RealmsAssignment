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
            // isnt invincible
            if (m_currentInv <= 0)
            {
                m_currentInv = m_invincibilityAfterHit;
                Tower* TowerOB = (Tower*)OB;
                m_health -= TowerOB->GetDamage();

                if (m_health <= 0)
                {
                    Coin* newCoin = new Coin();
                    newCoin->rect = this->rect;
                    Engine::Get()->AddObject(newCoin);
                    Engine::Get()->DeleteObject(this);
                }
            }
        }
        else if (OB->GetName() == "Wall")
        {
            Wall* WallOB = (Wall*)OB;
            WallOB->m_health -= m_dmg;
            rect.x += -dir * 20;
        }
        
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
    speed = 2;
    m_health = 5;
    m_invincibilityAfterHit = 0.5;
}

void Enemy::Execute()
{
}

