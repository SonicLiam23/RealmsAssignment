#include "GameState.h"
#include "GameStateMachine.h"
#include "InputManager.h"
#include "Engine.h"
#include "img.h"
#include "Enemy.h"
#include "Player.h";
#include "Tower.h";
#include "Farm.h";
#include "Coin.h"
#include "Renderer.h"
#include "DayNightManager.h"
#include "CoinDisplay.h"
#include <vector>

void GameState::OnEnter()
{
	Engine* e = Engine::Get();

	img* background = new img();
	background->SetImage("Background.bmp");
	background->rect.w = 100 * 100;
	background->rect.h = 144 * 8;
	background->rect.y -= 185;

	img* ground = new img();
	ground->SetImage("Ground.bmp");
	ground->rect.w = 100 * 100;
	ground->rect.h = 200;
	ground->rect.y = 490;




	Player* p = new Player();
	p->SetImage("Player.bmp");
	p->rect.y = 200;
	p->SetGameStateMachine(FSM);


	Tower* t = new Tower();
	t->SetImage("TowerSpot.bmp");
	t->rect.x = 1300;
	t->rect.y = 350;


	Tower* t2 = new Tower();
	t2->SetImage("TowerSpot.bmp");
	t2->rect.x = 900;
	t2->rect.y = 350;


	Tower* t3 = new Tower();
	t3->SetImage("TowerSpot.bmp");
	t3->rect.x = -1300;
	t3->rect.y = 350;



	Tower* t4 = new Tower();
	t4->SetImage("TowerSpot.bmp");
	t4->rect.x = -900;
	t4->rect.y = 350;



	Farm* f = new Farm();
	f->SetImage("FarmSpot.bmp");
	f->rect.x = -350;
	f->rect.y = 350;

	Farm* f2 = new Farm();
	f2->SetImage("FarmSpot.bmp");
	f2->rect.x = 350;
	f2->rect.y = 350;

	Coin* StartCoin1 = new Coin();
	StartCoin1->rect.x = 120; StartCoin1->rect.y = 350;
	StartCoin1->rect.w = 50;
	StartCoin1->rect.h = 50;

	Coin* StartCoin2 = new Coin();
	StartCoin2->rect.x = 180; StartCoin2->rect.y = 350;
	StartCoin2->rect.w = 50;
	StartCoin2->rect.h = 50;

	Coin* StartCoin3 = new Coin();
	StartCoin3->rect.x = 240; StartCoin3->rect.y = 350;
	StartCoin3->rect.w = 50;
	StartCoin3->rect.h = 50;


	// ADD BACKGROUND FIRST
	e->AddObject(background);
	e->AddObject(ground);

	// ADD OTHER OBJECTS HERE
	e->AddObject(t);
	e->AddObject(t2);
	e->AddObject(t3);
	e->AddObject(t4);

	e->AddObject(f);
	e->AddObject(f2);

	e->AddObject(StartCoin1);
	e->AddObject(StartCoin2);
	e->AddObject(StartCoin3);

	DayNightManager* DNM = new DayNightManager();
	e->AddObject(DNM);


	
	// ADD PLAYER LAST
	e->AddObject(p);
	//Text* text = new Text(SDL_GetRenderer(SDLClasses::GetWindow()), coins.c_str());

	Renderer::Get()->SetCamera(p);
}

void GameState::OnExit()
{
	Engine::Get()->ClearScreen();
}

void GameState::Update()
{
	Engine::Get()->Update();
	if (InputManager::Get()->GetKeyDown(SDLK_ESCAPE))
	{
		Engine::Get()->StopGame();
	}

}

bool GameState::CanExit()
{
    return false;
}

GameState::GameState(GameStateMachine* machine) : FSM(machine)
{
    FSM->states[GAME] = this;
}
