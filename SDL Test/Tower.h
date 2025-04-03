#pragma once
#include "ObjectBase.h"

class Tower : public ObjectBase
{
public:
	Tower();
	int Upgrade();
	int GetDamage();
	int GetUpgradeCost();
	int m_health;

private:
	int m_coinsToUpgrade;
	int m_currLevel;
	void Update() override;
	const char* GetName() override;
	int m_Damage;
	float m_attackCooldown;
	float m_currentCooldown;

	static const char* m_UpgradeImgNames[];

	// Inherited via ObjectBase
	void Execute() override;

	const int m_maxLevel = 3;
};

