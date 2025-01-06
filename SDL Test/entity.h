#pragma once
#include "ObjectBase.h"
class entity :
    public ObjectBase
{
    // Inherited via ObjectBase
    void Update() override;
    const char* GetName() override;

};

