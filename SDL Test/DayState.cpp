#include "DayNightManager.h"
#include "Enemy.h"
#include "LightArmourEnemy.h"
#include "Player.h"
#include "Engine.h"

void DayState::OnEnter()
{
	m_timer = 0;
	// SET BACKGROUND TO DARK
	// std::cout << "DAY STATE\n";
}

void DayState::OnExit()
{
}

void DayState::Update()
{
	m_timer += Engine::Get()->DT();
}

bool DayState::CanExit()
{
	return m_timer >= dayTimeInS;
}