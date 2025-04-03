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

void StateMachine::Update()
{
	this;
	m_currentState->Update();
}

StateMachine::StateMachine(IState* startState) : m_currentState(startState)
{
}
