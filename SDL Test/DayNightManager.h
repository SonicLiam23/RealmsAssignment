#pragma once
#include "ObjectBase.h"
#include "IState.h"


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

	void OnEnter() override;

	void OnExit() override;
	void Update() override;
	bool CanExit() override;
};

class NightState : public IState
{
	float m_timer;
	const float m_nightTimeInS = 30;

	float m_MaxEnemyCooldown = 2;
	float m_EnemyCooldown = 0;
	SDL_Rect* dest = new SDL_Rect({ 0,0,1,1 });

	int m_enemiesSpawned;
	int m_TotalEnemiesToSpawn = 4;
	int m_normalEnemyChance = 100;
	int m_lightArmourChance = 0;
	int m_heavyArmourChance = 0;

	int m_currentNight = 0;

	// Inherited via IState
	void OnEnter() override;

	void OnExit() override;
	void Update() override;
	bool CanExit() override;
};

