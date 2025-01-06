#pragma once

#include "SDLClasses.h"
#include <vector>

class ObjectBase;
class Engine
{
private:
	static Engine* s_Instance;
	bool m_Running;
	std::vector<ObjectBase*> m_Objects;
	Engine();

public:
	static Engine* Get();
	void Update();
	const bool IsGameRunning() const;
	void Init();
	void Start();
	void Uninit();
	void AddObject(ObjectBase* obj);
	void DeleteObject(ObjectBase* obj);

	// Returns every object that is colliding with it as a vector
	std::vector<ObjectBase*> GetAllCollisionsWith(ObjectBase* Obj);
	// returns true if the 2 objects are colliding
	bool IsColliding(ObjectBase* obj1, ObjectBase* obj2);
	ObjectBase* GetClosestObject(ObjectBase* obj, const char* findOnly = "");
};