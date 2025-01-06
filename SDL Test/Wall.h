#pragma once
#include "ObjectBase.h"

class Wall : public ObjectBase
{
public:
	Wall();
	int Upgrade();
	int m_health;

private:
	int coinsToUpgrade;
	int m_currLevel;
	void Update() override;
	const char* GetName() override;

	// Inherited via ObjectBase
	void Execute() override;
};

