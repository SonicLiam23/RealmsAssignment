#include <iostream>
#include "Engine.h"
#include "Player.h"
#include "entity.h"
#include "img.h"
#include "Enemy.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Tower.h"
#include "Coin.h"
#include "Wall.h"
#include "Farm.h"
#include "Objects.h"
#include <SDL_mixer.h>
#include "Text.h"
#include <string>
#include "DayNightManager.h"

#define GETCOINSNOW std::cout << p.coins << std::endl;


class Object {};
int main(int argc, char* argv[])
{
	Engine* e = Engine::Get();
	e->Init();
	Renderer::Get();

	int init = Mix_Init(0);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	Mix_Chunk* sound = Mix_LoadWAV("Audios/Pickup.wav");

	if (TTF_Init() == -1)
	{
		return false;
	}


	img background;
	background.SetImage("Background.bmp");
	background.rect.w = 100 * 100;
	background.rect.h = 144 * 8;
	background.rect.y -= 185;  

	img ground;
	ground.SetImage("Ground.bmp");
	ground.rect.w = 100 * 100;
	ground.rect.h = 200;
	ground.rect.y = 490;

	img mapEdgeRight;
	mapEdgeRight.SetImage("mapEdge.bmp");
	mapEdgeRight.rect.w = 300;
	mapEdgeRight.rect.h = 5000;
	mapEdgeRight.rect.y = 500;
	mapEdgeRight.rect.x = 5000;

	img mapEdgeLeft;
	mapEdgeLeft.SetImage("mapEdge.bmp");
	mapEdgeLeft.rect.w = 300;
	mapEdgeLeft.rect.h = 5000;
	mapEdgeLeft.rect.y = 500;
	mapEdgeLeft.rect.x = -5000;


	
	Player p;
	p.SetImage("Player.bmp");
	p.rect.y = 200;


	Enemy* en = new Enemy(&p);
	en->SetImage("Enemy.bmp");
	en->rect.x += 2000;
	en->rect.y = 350;

	Objects::Enemies.push_back(en);


	Tower* t = new Tower();
	t->SetImage("TowerSpot.bmp");
	t->rect.x = 1300;
	t->rect.y = 350;

	Objects::Towers.push_back(t);

	Tower* t2 = new Tower();
	t2->SetImage("TowerSpot.bmp");
	t2->rect.x = 900;
	t2->rect.y = 350;

	Objects::Towers.push_back(t2);

	Tower* t3 = new Tower();
	t3->SetImage("TowerSpot.bmp");
	t3->rect.x = -1300;
	t3->rect.y = 350;

	Objects::Towers.push_back(t3);

	Tower* t4 = new Tower();
	t4->SetImage("TowerSpot.bmp");
	t4->rect.x = -900;
	t4->rect.y = 350;

	Objects::Towers.push_back(t4);

	Farm* f = new Farm();
	f->SetImage("FarmSpot.bmp");
	f->rect.x = -350;
	f->rect.y = 350;

	Farm* f2 = new Farm();
	f2->SetImage("FarmSpot.bmp");
	f2->rect.x = 350;
	f2->rect.y = 350;




	// ADD BACKGROUND FIRST
	e->AddObject(&background);
	e->AddObject(&ground);
	e->AddObject(&mapEdgeRight);
	e->AddObject(&mapEdgeLeft);

	// ADD OTHER OBJECTS HERE
	e->AddObject(t);
	e->AddObject(t2);
	e->AddObject(t3);
	e->AddObject(t4);

	e->AddObject(f);
	e->AddObject(f2);


	e->AddObject(en);

	DayNightManager DNM;
	e->AddObject(&DNM);


	// ADD PLAYER LAST
	e->AddObject(&p);
	std::string coins = std::to_string(p.coins);
	Text* m_text = new Text("Font/arial.ttf", 35, coins.c_str(), { 0, 255, 255, 255 });

	Renderer::Get()->SetCamera(&p);


	e->Start();
	while (e->IsGameRunning())
	{
		e->Update();
		//GETCOINSNOW



		if (InputManager::Get()->GetKeyDown(SDLK_c))
		{
			p.coins += 10;
		}
 
		for (ObjectBase* OB : e->GetAllCollisionsWith(&p))
		{

			if (OB->GetName() == "Enemy")
			{
				e->DeleteObject(OB);
				p.coins -= 1;
				if (p.coins < 0)
				{
					//e.Uninit();
				}
			}
     		else if (OB->GetName() == "Tower")
			{
				if (InputManager::Get()->GetKeyDown(SDLK_s))
				{
					Tower* TowerObj = (Tower*)OB;
					TowerObj->Upgrade();
				}
				
			}
			else if (OB->GetName() == "Farm")
			{
				if (InputManager::Get()->GetKeyDown(SDLK_s))
				{
					Farm* FarmObj = (Farm*)OB;
					FarmObj->Upgrade();
				}
			}
			else if (OB->GetName() == "Coin")
			{
				e->DeleteObject(OB);
				p.coins += 1;
				Mix_PlayChannel(-1, sound, 0);
			}
		}


		if (InputManager::Get()->GetKeyDown(SDLK_ESCAPE))
		{
			e->Uninit();
		}
	}

	return 0;
}