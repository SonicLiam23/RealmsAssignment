#include "Player.h"
#include <iostream>
#include "InputManager.h"
#include "Renderer.h"

int Player::coins = 10;

Player::Player()
{
    // CHANGE THIS WHEN NEEDED
    CameraOffset = -160;
}

void Player::Update()
{
    if (InputManager::Get()->GetKeyHeld(SDLK_d))
    {
        rect.x += 3;
    }
    if (InputManager::Get()->GetKeyHeld(SDLK_a))
    {
        rect.x -= 3;
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

void Player::Execute()
{
}


