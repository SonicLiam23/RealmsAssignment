#include "DayNightManager.h"
#include "Enemy.h"
#include "LightArmourEnemy.h"
#include "HeavyArmourEnemy.h"
#include "Player.h"
#include "Engine.h"
#include <math.h>
#include <ctime>

void NightState::OnEnter()
{
	srand(time(NULL));
	// rand() seems to always be high, so run it a few times
	rand();
	rand();
	m_timer = 0;
	m_EnemyCooldown = m_MaxEnemyCooldown;
	m_enemiesSpawned = 0;
	m_currentNight++;

	// manual waves for now, it sucks but oh well. Given the limited upgrades, it can only go on for so long anyway

	// normal, light, heavy
    switch (m_currentNight)
    {
    case 1:
        // 100, 0, 0
        m_normalEnemyChance = 100;

        // 5
        m_TotalEnemiesToSpawn = 5;
        break;

    case 2:
        break;

    case 3:
        // 75, 25, 0
        m_lightArmourChance += 25;
        m_normalEnemyChance -= m_lightArmourChance;

        // 7
        m_TotalEnemiesToSpawn += 2;
        break;

    case 4:
        // 8
        m_TotalEnemiesToSpawn += 1;
        break;

    case 5:
        m_MaxEnemyCooldown -= 0.5;
        break;

    case 6:
        // 40, 50, 10
        m_lightArmourChance += 25;
        m_normalEnemyChance -= 25;
        m_heavyArmourChance += 10;
        m_normalEnemyChance -= 10;
        break;

    case 7:
        // 10
        m_TotalEnemiesToSpawn += 2;
        break;

    case 8:
        break;

    case 9:
        // 0, 75, 25
        m_normalEnemyChance = 0;
        m_lightArmourChance = 75;
        m_heavyArmourChance = 25;
        break;

    case 10:
        // 12
        m_TotalEnemiesToSpawn += 2;

        m_MaxEnemyCooldown -= 0.5;
        break;

    case 11:
        break;

    case 12:
        // 0, 0, 100
        m_heavyArmourChance = 100;
        m_lightArmourChance = 0;
        break;


    default:
        // WHEN AT END OF GAME
        m_TotalEnemiesToSpawn += 1;
    }


	// std::cout << "NIGHT STATE\n";
}

void NightState::OnExit()
{
}

void NightState::Update()
{
	m_timer += Engine::Get()->DT();

	m_EnemyCooldown -= Engine::Get()->DT();
	if (m_EnemyCooldown <= 0 && m_enemiesSpawned != m_TotalEnemiesToSpawn)
	{
		// range is always 100 (for a %) but this is proof of concept
		int range = m_normalEnemyChance + m_lightArmourChance + m_heavyArmourChance;
		int roll = rand() % range;
		m_EnemyCooldown = m_MaxEnemyCooldown;
		m_enemiesSpawned++;

		int side = rand() % 2 == 1 ? 1 : -1;

		// SPEND AGES COMING UP WITH THIS. but accuratley gets a random of 3 based on %
		if (roll < m_normalEnemyChance)
		{
			Enemy* en = new Enemy(dest);
			en->rect.x = 2500 * side;
			en->rect.y = 350;
			Engine::Get()->AddObject(en);
			return;
		}

		roll -= m_normalEnemyChance; 

		if (roll < m_lightArmourChance)
		{
			LightArmourEnemy* en = new LightArmourEnemy(dest);
			en->rect.x = 2500 * side;
			en->rect.y = 350;
			Engine::Get()->AddObject(en);
		}

		else
		{
			HeavyArmourEnemy* en = new HeavyArmourEnemy(dest);
			en->rect.x = 2500 * side;
			en->rect.y = 350;
			Engine::Get()->AddObject(en);
		}
	}
}

bool NightState::CanExit()
{
	return m_timer >= m_nightTimeInS;
}