#pragma once
#include "ObjectBase.h"

class Tower : public ObjectBase
{
public:
	Tower();
	int Upgrade();
	int GetDamage();

private:
	int coinsToUpgrade;
	int m_currLevel;
	void Update() override;
	const char* GetName() override;
	int m_Damage;

	static const char* m_UpgradeImgNames[];

	// Inherited via ObjectBase
	void Execute() override;

	const int m_maxLevel = 3;
};

