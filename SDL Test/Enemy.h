#pragma once
#include "ObjectBase.h"
class Enemy : public ObjectBase
{
public:
    Enemy(ObjectBase* Target);
    Enemy(SDL_Rect* Target);
private:
    // Inherited via ObjectBase
    void Update() override;
    const char* GetName() override;
    void init();



    int speed;
    int m_dmg;
    int m_health;
    SDL_Rect* m_Target;

    float m_invincibilityAfterHit;
    float m_currentInv;

    // Inherited via ObjectBase
    void Execute() override;
};

