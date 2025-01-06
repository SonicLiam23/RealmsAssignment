#pragma once
#include "ObjectBase.h"
class img :
    public ObjectBase
{
public:
    img();
    // Inherited via ObjectBase
    void Update() override;
    const char* GetName() override;

    // Inherited via ObjectBase
    void Execute() override;
};

