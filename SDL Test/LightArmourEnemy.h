#pragma once
#include "Enemy.h"
class LightArmourEnemy :
    public Enemy
{
    void init() override;

public:
    LightArmourEnemy(SDL_Rect* target);
    LightArmourEnemy(ObjectBase* target);
};

