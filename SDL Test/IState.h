#pragma once
class IState
{
private:
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
	virtual void Update() = 0;

	friend class StateMachine;
};

