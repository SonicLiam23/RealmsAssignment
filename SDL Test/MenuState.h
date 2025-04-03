#pragma once
#include "IState.h"

class GameStateMachine; class img;
class MenuState :
    public IState
{
    // Inherited via IState
    void OnEnter() override;
    void OnExit() override;
    void Update() override;
    bool CanExit() override;
    GameStateMachine* FSM;
    img* menuImg;

public:
    MenuState(GameStateMachine* machine);
};

