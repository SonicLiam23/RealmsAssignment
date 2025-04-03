#include "MenuState.h"
#include "InputManager.h"
#include "Engine.h"
#include "img.h"
#include "GameStateMachine.h"
#include "Globals.h"
#include "Renderer.h"

void MenuState::OnEnter()
{
    menuImg = new img();
    menuImg->SetImage("Menu.bmp");

    menuImg->rect = { 0, 0, Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT };

    Engine::Get()->AddObject(menuImg);

    Renderer::Get()->SetCamera(menuImg);
}

void MenuState::OnExit()
{
    Engine::Get()->ClearScreen(true);
}

void MenuState::Update()
{
    Engine::Get()->Update();
    if (InputManager::Get()->GetKeyDown(SDLK_SPACE))
    {
        FSM->ChangeState(FSM->states[GAME]);
        return;
    }
    else if (InputManager::Get()->GetKeyDown(SDLK_ESCAPE))
    {
        Engine::Get()->StopGame();
    }
}

bool MenuState::CanExit()
{
    return false;
}

MenuState::MenuState(GameStateMachine* machine) : FSM(machine)
{
    FSM->states[MENU] = this;
}
