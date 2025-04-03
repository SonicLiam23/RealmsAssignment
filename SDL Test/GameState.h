#pragma once
#include "IState.h"

class GameStateMachine;
class GameState :
    public IState
{
    // Inherited via IState
    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    bool CanExit() override;

    GameStateMachine* FSM;

public:
    GameState(GameStateMachine* machine);
};

