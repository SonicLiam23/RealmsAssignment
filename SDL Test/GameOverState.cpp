#include "GameOverState.h"
#include "Engine.h"
#include "InputManager.h"
#include "img.h"
#include "ObjectBase.h"
#include "Globals.h"
#include "GameStateMachine.h"
#include "Renderer.h"

void GameOverState::OnEnter()
{
    screen = new img();
    screen->SetImage("GameOver.bmp");
    screen->rect.x = 0;
    screen->rect.y = 0;
    screen->rect.w = Globals::SCREEN_WIDTH;
    screen->rect.h = Globals::SCREEN_HEIGHT;

    Engine::Get()->AddObject(screen);
    Renderer::Get()->SetCamera(screen);
}

void GameOverState::OnExit()
{
    Engine::Get()->ClearScreen();
}

void GameOverState::Update()
{

    Engine::Get()->Update();
    if (InputManager::Get()->GetKeyDown(SDLK_SPACE))
    {
        FSM->ChangeState(FSM->states[MENU]);
    }
    
    else if (InputManager::Get()->GetKeyDown(SDLK_ESCAPE))
    {
        Engine::Get()->StopGame();
    }

}

bool GameOverState::CanExit()
{
    return false;
}

GameOverState::GameOverState(GameStateMachine* machine) : IState(), FSM(machine)
{
}
