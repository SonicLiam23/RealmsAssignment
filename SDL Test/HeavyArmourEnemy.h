#pragma once
#include "Enemy.h"
class HeavyArmourEnemy :
    public Enemy
{
    void init() override;

public:
    HeavyArmourEnemy(SDL_Rect* target);
    HeavyArmourEnemy(ObjectBase* target);
};

