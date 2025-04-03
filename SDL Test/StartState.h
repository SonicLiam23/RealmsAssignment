#pragma once
#include "IState.h"

// an empty state to init a FSM to nothing (only used when creating a state machine to immediatley change
class StartState :
    public IState
{
    // Inherited via IState
    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    bool CanExit() override;
};

