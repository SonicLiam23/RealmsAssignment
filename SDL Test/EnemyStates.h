#pragma once
#include "IState.h"
class StateBasicEnemy : public IState
{
	// Inherited via IState
	void OnEnter() override
	{
		// set object image to Enemy.bmp

	}
	void OnExit() override
	{
		// enemy dead
	}
	void Update() override
	{

	}
};

class StateLightArmourEnemy : public IState
{
	// Inherited via IState
	void OnEnter() override
	{
		// set image to EnemyArmour1.bmp
	}
	void OnExit() override
	{
		
	}
	void Update() override
	{

	}
};

class StateHeavyArmourEnemy : public IState
{

};