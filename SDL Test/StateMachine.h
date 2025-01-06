#pragma once
class IState;

class StateMachine
{
private:
	IState* m_currentState;
	void ChangeState(IState* change);


};

