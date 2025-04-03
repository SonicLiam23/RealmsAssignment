#pragma once
#include "IState.h"
class img; class GameStateMachine;
class GameOverState :
    public IState
{
    // Inherited via IState
    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    bool CanExit() override;

    img* screen;
    GameStateMachine* FSM;

public:
    GameOverState(GameStateMachine* machine);
};

