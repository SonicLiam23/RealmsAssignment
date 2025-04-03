#include "Engine.h"
#include "CoinDisplay.h"
#include "Player.h"
#include "Tower.h"
#include "Farm.h"
#include "Coin.h"
#include <iostream>
#include "InputManager.h"
#include "Renderer.h"
#include <SDL_mixer.h>
#include "GameStateMachine.h"

int Player::coins = 0;

Player::Player()
{
    // CHANGE THIS WHEN NEEDED
    CameraOffset = -160;
	sound = Mix_LoadWAV("Audios/Pickup.wav");
	CoinDisplay::DeleteInstance();
	Engine::Get()->AddObject(CoinDisplay::Get(this));
	
}

void Player::Update()
{
    if (InputManager::Get()->GetKeyHeld(SDLK_d))
    {
        rect.x = std::min(rect.x + 3, 1700);
    }
    if (InputManager::Get()->GetKeyHeld(SDLK_a))
    {
		rect.x = std::max(rect.x - 3, -1700);
    }
	std::cout << rect.x << std::endl;
	for (ObjectBase* OB : Engine::Get()->GetAllCollisionsWith(this))
	{
		
		if (OB->GetName() == "Enemy")
		{
			Engine::Get()->DeleteObject(OB);
			if (coins > 0)
			{
				CoinDisplay::Get()->SpendCoin(1);
			}
			else
			{
				FSM->ChangeState(FSM->states[DEAD]);
			}
			
		
		}
		else if (OB->GetName() == "Tower")
		{
			if (InputManager::Get()->GetKeyDown(SDLK_s))
			{
				Tower* TowerObj = (Tower*)OB;
				if (coins >= TowerObj->GetUpgradeCost())
				{
					TowerObj->Upgrade();
					//coins -= TowerObj->GetUpgradeCost();
				}
			}

		}
		else if (OB->GetName() == "Farm")
		{
			if (InputManager::Get()->GetKeyDown(SDLK_s))
			{
				Farm* FarmObj = (Farm*)OB;
				if (coins >= FarmObj->GetUpgradeCost())
				{
					FarmObj->Upgrade();
					//coins -= FarmObj->GetUpgradeCost();
				}
			}
		}
		else if (OB->GetName() == "Coin")
		{
			Coin* coinOB = (Coin*)OB;
			CoinDisplay::Get()->AddCoin(coinOB);
			coins += 1;
			Mix_PlayChannel(-1, sound, 0);
		}
	}
}

const char* Player::GetName()
{
    return "Player";
}

void Player::Render()
{
    if (m_img != nullptr)
    {
        Renderer::Get()->DrawImage(m_img, &rect, CameraOffset);
    }
}

void Player::SetGameStateMachine(GameStateMachine* machine)
{
	FSM = machine;
}

void Player::Execute()
{
}
