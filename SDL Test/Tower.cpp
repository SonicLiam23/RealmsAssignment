#include "Tower.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "Coin.h"
#include "CoinDisplay.h"


const char* Tower::m_UpgradeImgNames[] = { "TowerUpgrade0.bmp", "TowerUpgrade1.bmp", "TowerUpgrade2.bmp", "TowerUpgrade3.bmp", "TowerUpgrade4.bmp"};

Tower::Tower() : m_currLevel(0), m_Damage(0), m_health(0), m_attackCooldown(0), m_coinsToUpgrade(1)
{
}

int Tower::Upgrade()
{
	CoinDisplay::Get()->SpendCoin(m_coinsToUpgrade);
	switch (m_currLevel)
	{
	case 0:
		m_coinsToUpgrade = 3;
		m_Damage = 1;
		m_health = 10;
		m_attackCooldown = 1;
		break;

	case 1:
		m_coinsToUpgrade = 6;
		m_Damage = 2;
		m_health = 15;
		m_attackCooldown = 1;
		break;

	case 2:
		m_coinsToUpgrade = 10;
		m_Damage = 3;
		m_health = 25;
		m_attackCooldown = 1;
		break;

	case 3:
		m_coinsToUpgrade = 15;
		m_Damage = 4;
		m_health = 40;
		m_attackCooldown = 1;
		break;

	case 4:
		m_Damage = 5;
		m_health = 50;
		m_attackCooldown = 1;
		return m_currLevel;
	}
		
	m_currLevel++;
	/*std::stringstream SSfileName;
	SSfileName << "TowerUpgrade" << m_currLevel << ".bmp";
	std::string SfileName = SSfileName.str();
	const char* fileName = SfileName.c_str();

	std::cout << Player::coins << std::endl;
	std::cout << fileName << std::endl;*/

	SetImage(m_UpgradeImgNames[m_currLevel]);

	return m_currLevel;
}

int Tower::GetDamage()
{
	return m_Damage;
}

int Tower::GetUpgradeCost()
{
	return m_coinsToUpgrade;
}

void Tower::Update()
{
	for (ObjectBase* OB : Engine::Get()->GetAllCollisionsWith(this))
	{
		if (OB->GetName() == "Enemy" && m_currentCooldown <= 0)
		{
			Enemy* enemyOB = (Enemy*)OB;
			m_currentCooldown = m_attackCooldown;
			enemyOB->m_health -= m_Damage;

			if (enemyOB->m_health <= 0)
			{
				Coin* newCoin = new Coin();
				newCoin->rect.x = enemyOB->rect.x;
				newCoin->rect.y = enemyOB->rect.y;
				newCoin->rect.w = 50;
				newCoin->rect.h = 50;
				Engine::Get()->AddObject(newCoin);
				Engine::Get()->DeleteObject(enemyOB);
			}
		}
	}

	if (m_currentCooldown > 0)
	{
		m_currentCooldown -= Engine::Get()->DT();
	}
}

const char* Tower::GetName()
{
	return "Tower";
}

void Tower::Execute()
{
	Upgrade();
}
