#include "Engine.h"

#include <cmath>
#include "Globals.h"
#include "Renderer.h"
#include "InputManager.h"
#include "ObjectBase.h"

#include "SDL.h"

Engine* Engine::s_Instance = nullptr;

Engine* Engine::Get()
{
	return s_Instance != nullptr ? s_Instance : s_Instance = new Engine();
}

Engine::Engine() : m_Running(false), LAST(0), NOW(0), m_deltaTime(0)
{

}

void Engine::DeleteObjects()
{
	for (ObjectBase* obj : m_ObjsToDelete)
	{
		for (int i = 0; i < m_Objects.size(); ++i)
		{
			if (obj == m_Objects[i])
			{
				m_Objects.erase(m_Objects.begin() + i);
				m_ObjsToDelete.pop_back();
				delete obj;
				break;
			}
		}
	}

	// if some object has been left over, erase it
	if (m_ObjsToDelete.size() > 0)
	{
		for (ObjectBase* obj : m_ObjsToDelete)
		{
			m_ObjsToDelete.pop_back();
		}
	}

	if (m_deleteAll)
	{
		m_deleteAll = false;
		m_Objects.clear();
	}
}

void Engine::Update()
{
	InputManager::Get()->Update();
	SDL_RenderClear(SDLClasses::GetRenderer());

	int testint = 0;
	DeleteObjects();
	// call update on each object
	for (ObjectBase* CurrObj : m_Objects)
	{
		CurrObj->Update();
		CurrObj->Render();	
		testint++;
	}
	SDL_RenderPresent(SDLClasses::GetRenderer());
	// 1000 -> ms in seconds. 60 -> times a second
	SDL_Delay(1000/60);

	NOW = SDL_GetPerformanceCounter();
	m_deltaTime = (NOW - LAST) / (double)SDL_GetPerformanceFrequency();
	LAST = NOW;

	
}

const bool Engine::IsGameRunning() const
{
	return m_Running;
}

void Engine::StopGame()
{
	m_Running = false;
}

void Engine::Init()
{
	if (m_Running)
	{
		return;
	}
	SDL_Init(SDL_INIT_EVERYTHING);
	m_Objects.reserve(Globals::ESTIMATED_AMT_OF_OBJECTS);
	// creates classes if they dont already exist
	Renderer::Get();
	InputManager::Get();
}

// Run this after added all objects
void Engine::Start()
{
	m_Running = true;
}

void Engine::Uninit()
{
	SDLClasses::DeleteAll();
	m_ObjsToDelete = m_Objects;

	SDL_Quit();
}

void Engine::AddObject(ObjectBase* obj)
{
	m_Objects.push_back(obj);
}

void Engine::DeleteObject(ObjectBase* obj)
{
	m_ObjsToDelete.push_back(obj);
}

void Engine::ClearScreen(bool forceDelete)
{
	for (ObjectBase* OB : m_Objects)
	{
		m_ObjsToDelete.push_back(OB);
	}
	if (forceDelete)
	{
		m_deleteAll = true;
		DeleteObjects();
	}
}



std::vector<ObjectBase*> Engine::GetAllCollisionsWith(ObjectBase* Obj)
{
	std::vector<ObjectBase*> ReturnVector;
	for (ObjectBase* CurrObj : m_Objects)
	{
		if (CurrObj->CollisionEnabled)
		{
			if (IsColliding(Obj, CurrObj))
			{
				ReturnVector.push_back(CurrObj);
			}
		}
	}
	return ReturnVector;
}

bool Engine::IsColliding(ObjectBase* obj1, ObjectBase* obj2)
{
	if (!obj1->CollisionEnabled || !obj2->CollisionEnabled)
	{
		return false;
	}
	if (obj1->isStatic && obj2->isStatic)
	{
		return false;
	}

	if (obj1 == obj2)
	{
		return false;
	}

	SDL_Rect* rect1 = obj1->GetPosition();
	SDL_Rect* rect2 = obj2->GetPosition();

	int objA_MinX = rect1->x;
	int objA_MinY = rect1->y;
	int objA_MaxX = rect1->x + rect1->w;
	int objA_MaxY = rect1->y + rect1->h;

	int objB_MinX = rect2->x;
	int objB_MinY = rect2->y;
	int objB_MaxX = rect2->x + rect2->w;
	int objB_MaxY = rect2->y + rect2->h;

	//If any of the sides from A are outside of B
	if (objA_MinY >= objB_MaxY)
	{
		return false;
	}

	if (objA_MaxY <= objB_MinY)
	{
		return false;
	}

	if (objA_MinX >= objB_MaxX)
	{
		return false;
	}

	if (objA_MaxX <= objB_MinX)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

ObjectBase* Engine::GetClosestObject(ObjectBase* obj, const char* findOnly)
{
	float closestDistance = INT_MAX;
	ObjectBase* closestObject = nullptr;
	if (findOnly == "")
	{
		for (ObjectBase* currObj : m_Objects)
		{
			if (obj != currObj)
			{
				int dX;
				int dY;
				dX = obj->rect.x - currObj->rect.x;
				dY = obj->rect.y - currObj->rect.y;

				float hyp;
				hyp = (dX * dX) + (dY * dY);
				hyp = std::sqrt(hyp);

				if (hyp < closestDistance)
				{
					closestObject = currObj;
				}
			}
		}
	}

	else
	{
		for (ObjectBase* currObj : m_Objects)
		{
			if (obj != currObj && currObj->GetName() == findOnly)
			{
				int dX;
				int dY;
				dX = obj->rect.x - currObj->rect.x;
				dY = obj->rect.y - currObj->rect.y;

				float hyp;
				hyp = (dX * dX) + (dY * dY);
				hyp = std::sqrt(hyp);

				if (hyp < closestDistance)
				{
					closestObject = currObj;
				}
			}
		}
	}

	return closestObject;
}

std::vector<ObjectBase*> Engine::GetObjectsWithName(const char* nameToSearch)
{
	std::vector<ObjectBase*> objects;
	for (ObjectBase* OB : m_Objects)
	{
		if (OB->GetName() == nameToSearch)
		{
			objects.push_back(OB);
		}
	}

	return objects;
}

double Engine::DT()
{
	
	return m_deltaTime;
}