#include "Realms.h"
#include <iostream>
#include "Engine.h"
#include "Player.h"
#include "entity.h"
#include "img.h"
#include "Renderer.h"
#include "Enemy.h"
#include "InputManager.h"
#include "Tower.h"
#include "Coin.h"
#include "Wall.h"
#include "Farm.h"
#include "Objects.h"
#include <SDL_mixer.h>
#include <string>
#include "DayNightManager.h"
#include "StateMachine.h"
#include "GameStateMachine.h"
#include "GameState.h"
#include "MenuState.h"
#include "StartState.h"
#include "GameOverState.h"
#include "SDL_ttf.h"


void Realms::init()
{
	TTF_Init();
	Engine* e = Engine::Get();
	e->Init();
	Renderer::Get();

	int init = Mix_Init(0);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	sound = Mix_LoadWAV("Audios/Pickup.wav");

	StartState start;
	FSM = new GameStateMachine(&start);

	menu = new MenuState(FSM);
	game = new GameState(FSM);
	dead = new GameOverState(FSM);

	FSM->states[GAME] = game;
	FSM->states[MENU] = menu;
	FSM->states[DEAD] = dead;

	FSM->ChangeState(menu);
}

void Realms::Start()
{
	Engine::Get()->Start();

	// STart update loop
	Update();
}

void Realms::Update()
{
	// the game while is in here
	while (Engine::Get()->IsGameRunning())
	{
		FSM->Update();
	}

	// if this ends, we quit the game
	Quit();
}

void Realms::Quit()
{
	delete game;
	delete dead;
	delete menu;
	delete FSM;
	Engine::Get()->Uninit();
	SDL_Quit;
}
