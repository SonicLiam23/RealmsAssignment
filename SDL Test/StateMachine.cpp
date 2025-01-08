#include "StateMachine.h"
#include "IState.h"

void StateMachine::ChangeState(IState* change)
{
	m_currentState->OnExit();
	m_currentState = change;
	m_currentState->OnEnter();
}

IState* StateMachine::GetState()
{
	return m_currentState;
}
