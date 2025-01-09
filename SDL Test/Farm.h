#pragma once
#include "ObjectBase.h"

class Farm : public ObjectBase
{
public:
	Farm();
	int Upgrade();
private:
	int coinsToUpgrade;
	int m_currLevel;
	void Update() override;
	const char* GetName() override;
	// Inherited via ObjectBase
	void Execute() override;
	const int m_maxLevel = 3;
};

