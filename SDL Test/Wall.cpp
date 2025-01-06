#include "Wall.h"

Wall::Wall()
{
	m_currLevel = 0;
}

int Wall::Upgrade()
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
		coinsToUpgrade = 8;
		break;

	case 3:
		coinsToUpgrade = 10;
		break;

	case 4:
		// MAX LEVEL
		return m_currLevel;

	}
}

void Wall::Update()
{
}

const char* Wall::GetName()
{
	return "Wall";
}

void Wall::Execute()
{
	m_health -= 10;
}
