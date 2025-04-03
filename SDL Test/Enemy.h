#pragma once
#include "ObjectBase.h"
class Enemy : public ObjectBase
{
public:
    Enemy(ObjectBase* Target);
    Enemy(SDL_Rect* Target);
    float GetInvincibilityTime();
    int m_health;
    int GetDamage();
private:
    // Inherited via ObjectBase
    void Update() override;
    const char* GetName() override;
    virtual void init();


protected:
    int speed;
    int m_dmg;
    SDL_Rect* m_Target;

    float m_invincibilityAfterHit;
    float m_currentInv;

    // Inherited via ObjectBase
    void Execute() override;
};

