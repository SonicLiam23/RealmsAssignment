#pragma once
#include "ObjectBase.h"
#include "vector"
class Coin; class Player;
class CoinDisplay : public ObjectBase
{
public:
	~CoinDisplay();
	void AddCoin(Coin* coinToAdd);
	void SpendCoin(int amt);
	static CoinDisplay* Get(Player* playerClass = nullptr);
	static void DeleteInstance();

private:
	Player* m_playerClass;
	const int m_maxCoins;
	std::vector<Coin*> m_coins;
	static CoinDisplay* s_instance;
	CoinDisplay();

	// Inherited via ObjectBase
	void Update() override;
	const char* GetName() override;
	void Execute() override;
};

