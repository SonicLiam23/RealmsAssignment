#pragma once
#include "ObjectBase.h"
#include "IState.h"
#include "Engine.h"
#include <iostream>

class StateMachine;
class DayNightManager : public ObjectBase
{
	// Inherited via ObjectBase
	void Update() override;
	const char* GetName() override;
	void Execute() override;
	StateMachine* m_FSM;
	IState** m_states;

	enum CURRENT_STATE
	{
		day = 0,
		night = 1
	};
	CURRENT_STATE m_state;

public:
	DayNightManager();
	~DayNightManager();
};

// STATES HERE
class DayState : public IState
{
	float m_timer = 0;
	const float dayTimeInS = 1;

	void OnEnter() override
	{
		m_timer = 0;
		// SET BACKGROUND TO DARK
		std::cout << "DAY STATE\n";
	}
	void OnExit() override
	{

	}
	void Update() override
	{
		m_timer += Engine::Get()->DT();
	}
	bool CanExit() override
	{
		return m_timer >= dayTimeInS;
	}
};

class NightState : public IState
{
	float m_timer;
	const float m_nightTimeInS = 2;
	// Inherited via IState
	void OnEnter() override
	{
		m_timer = 0;
		std::cout << "NIGHT STATE\n";
	}
	void OnExit() override
	{

	}
	void Update() override
	{
		m_timer += Engine::Get()->DT();
	}
	bool CanExit() override
	{
		return m_timer >= m_nightTimeInS;
	}
};

