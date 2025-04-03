#include "GameStateMachine.h"

GameStateMachine::GameStateMachine(IState* initState) : StateMachine(initState)
{
	states[MENU] = nullptr;
	states[GAME] = nullptr;
	states[DEAD] = nullptr;
}
