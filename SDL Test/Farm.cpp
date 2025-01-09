#include "Farm.h"
#include "Player.h"

Farm::Farm() : m_currLevel(0)
{
}

int Farm::Upgrade()
{
	switch (m_currLevel)
	{
	case 0:
		coinsToUpgrade = 3;
		break;

	case 1:
		coinsToUpgrade = 5;
		break;

	case 2:
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

		SetImage("Farm.bmp");
	}
}

void Farm::Update()
{
}

const char* Farm::GetName()
{
	return "Farm";
}

void Farm::Execute()
{
}
