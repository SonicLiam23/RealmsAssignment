#include "Farm.h"
#include "Engine.h"
#include "Player.h"
#include "Coin.h"
#include "CoinDisplay.h"

Farm::Farm() : m_currLevel(0), m_generateCoinCooldown(0), m_coinsToGenerate(0), coinsToUpgrade(5)
{
}

int Farm::Upgrade()
{

		CoinDisplay::Get()->SpendCoin(coinsToUpgrade);
		switch (m_currLevel)
		{
		case 0:
			coinsToUpgrade = 7;
			m_generateCoinCooldown = 15;
			m_coinsToGenerate = 1;
			break;

		case 1:
			coinsToUpgrade = 10;
			m_generateCoinCooldown = 10;
			break;

		case 2:
			return m_currLevel;
		}
		m_currLevel++;
		/*std::stringstream SSfileName;
		SSfileName << "TowerUpgrade" << m_currLevel << ".bmp";
		std::string SfileName = SSfileName.str();
		const char* fileName = SfileName.c_str();

		std::cout << Player::coins << std::endl;
		std::cout << fileName << std::endl;*/
		
		SetImage("Farm.bmp");
}

void Farm::Update()
{
	if (m_currentCoinCooldown <= 0 && m_currLevel > 0)
	{
		m_currentCoinCooldown = m_generateCoinCooldown;// cooldown
		Coin* newCoin = new Coin();
		newCoin->rect.x = this->rect.x;
		newCoin->rect.y = this->rect.y;
		newCoin->rect.w = 50;
		newCoin->rect.h = 50;
		Engine::Get()->AddObject(newCoin);
	}

	if (m_currentCoinCooldown > 0)
	{
		m_currentCoinCooldown -= Engine::Get()->DT();
	}
}

const char* Farm::GetName()
{
	return "Farm";
}

void Farm::Execute()
{
}

int Farm::GetUpgradeCost()
{
	return coinsToUpgrade;
}
