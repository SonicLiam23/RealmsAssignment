#include "Tower.h"
#include "Engine.h"
#include "Player.h"


const char* Tower::m_UpgradeImgNames[] = { "TowerUpgrade0.bmp", "TowerUpgrade1.bmp", "TowerUpgrade2.bmp", "TowerUpgrade3.bmp", "TowerUpgrade4.bmp"};

Tower::Tower() : m_currLevel(0), m_Damage(0)
{
}

int Tower::Upgrade()
{
	switch (m_currLevel)
	{
	case 0:
		coinsToUpgrade = 3;
		m_Damage = 1;
		break;

	case 1:
		coinsToUpgrade = 5;
		m_Damage = 2;
		break;

	case 2:
		coinsToUpgrade = 8;
		m_Damage = 3;
		break;

	case 3:
		coinsToUpgrade = 10;
		m_Damage = 4;
		break;
		
	case 4:
		m_Damage = 5;
		return m_currLevel;
	}
	
	if (Player::coins >= coinsToUpgrade)
	{
		Player::coins -= coinsToUpgrade;
		m_currLevel++;
		/*std::stringstream SSfileName;
		SSfileName << "TowerUpgrade" << m_currLevel << ".bmp";
		std::string SfileName = SSfileName.str();
		const char* fileName = SfileName.c_str();

		std::cout << Player::coins << std::endl;
		std::cout << fileName << std::endl;*/

		SetImage(m_UpgradeImgNames[m_currLevel]);
	}

	return m_currLevel;
}

int Tower::GetDamage()
{
	return m_Damage;
}

void Tower::Update()
{
	
}

const char* Tower::GetName()
{
	return "Tower";
}

void Tower::Execute()
{
	Upgrade();
}
