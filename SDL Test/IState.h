#pragma once
class IState
{
public:
	virtual void OnEnter() = 0;
	virtual void OnExit() = 0;
	virtual void Update() = 0;
	virtual bool CanExit() = 0;
};

