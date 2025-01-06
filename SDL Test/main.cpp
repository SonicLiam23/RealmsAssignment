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

#define GETCOINSNOW std::cout << p.coins << std::endl;


class Object {};
int main(int argc, char* argv[])
{
	Engine* e = Engine::Get();
	e->Init();
	Renderer::Get();


	img background;
	background.SetImage("Background.bmp");
	background.rect.w = 640 * 8;
	background.rect.h = 144 * 8;
	background.rect.y -= 185;  
	
	Player p;
	p.SetImage("Player.bmp");
	p.rect.y = 50;

	Enemy* en = new Enemy(&p);
	en->SetImage("Enemy.bmp");
	en->rect.x += 1000;
	Objects::Enemies.push_back(en);


	Tower* t = new Tower();
	t->SetImage("TowerSpot.bmp");
	t->rect.x = 1000;
	t->rect.y = 200;
	Objects::Towers.push_back(t);

	Tower* t2 = new Tower();
	t2->SetImage("TowerSpot.bmp");
	t2->rect.x = 500;
	t2->rect.y = 200;


	// ADD BACKGROUND FIRST
	e->AddObject(&background);

	// ADD OTHER OBJECTS HERE
	e->AddObject(t);
	e->AddObject(t2);


	e->AddObject(en);

	// ADD PLAYER LAST
	e->AddObject(&p);
	

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
			else if (OB->GetName() == "Wall")
			{
				if (InputManager::Get()->GetKeyDown(SDLK_s))
				{
				    OB->Execute();
				}
			}
			else if (OB->GetName() == "Farm")
			{
				if (InputManager::Get()->GetKeyDown(SDLK_s))
				{
					OB->Execute();
				}
			}
			else if (OB->GetName() == "Coin")
			{
				e->DeleteObject(OB);
				p.coins += 1;
			}
		}


		if (InputManager::Get()->GetKeyDown(SDLK_ESCAPE))
		{
			e->Uninit();
		}
	}

	return 0;
}