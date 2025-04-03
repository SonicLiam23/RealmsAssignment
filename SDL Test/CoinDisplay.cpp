#include "CoinDisplay.h"
#include "Engine.h"
#include "Player.h"
#include "Coin.h"
#include "Globals.h"

CoinDisplay* CoinDisplay::s_instance = nullptr;

CoinDisplay::~CoinDisplay()
{
	s_instance = nullptr;
}

void CoinDisplay::AddCoin(Coin* coinToAdd)
{
	m_coins.push_back(coinToAdd);


	coinToAdd->rect.x = rect.x;
	coinToAdd->rect.y = rect.y;
	
}

void CoinDisplay::SpendCoin(int amt)
{
	if (m_coins.size() >= amt)
	{
		for (int i = 0; i < amt; ++i)
		{
			Player::coins--;
			Coin* coinToDelete;
			coinToDelete = m_coins.back();
			m_coins.pop_back();
			Engine::Get()->DeleteObject(coinToDelete);
		}
	}
}

void CoinDisplay::Update()
{
	// coinToAdd->rect.x += rect.x + (m_coins.size() * 60);

	rect.x = m_playerClass->rect.x - Globals::HALF_SCREEN_WIDTH + 50;
	for (int i = 0; i < m_coins.size(); ++i)
	{
		m_coins[i]->rect.x = rect.x + (60 * i);
	}
}

const char* CoinDisplay::GetName()
{
	return "CoinDisplay";
}

void CoinDisplay::Execute()
{
}

CoinDisplay::CoinDisplay() : m_maxCoins(15)
{
	rect.y = -30;
}

CoinDisplay* CoinDisplay::Get(Player* playerClass)
{
	if (playerClass != nullptr)
	{
		Get()->m_playerClass = playerClass;
	}
	return s_instance == nullptr ? s_instance = new CoinDisplay() : s_instance;
}

void CoinDisplay::DeleteInstance()
{
	s_instance = nullptr;;
}
