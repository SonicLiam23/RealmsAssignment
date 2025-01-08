#pragma once
class IState;

class StateMachine
{
private:
	IState* m_currentState;

public:
	void ChangeState(IState* change);
	IState* GetState();
};

