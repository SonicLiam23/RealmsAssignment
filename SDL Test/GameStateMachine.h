#pragma once
#include "StateMachine.h"
#include <vector>

enum GAME_STATES
{
    GAME = 0,
    MENU = 1,
    DEAD = 2
};

class IState;
class GameStateMachine :
    public StateMachine
{
public:
    IState* states[3];
    GameStateMachine(IState* initState);
};

