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
	double m_deltaTime, LAST, NOW;
	Engine();

	std::vector<ObjectBase*> m_ObjsToDelete;
	void DeleteObjects();
	bool m_deleteAll;

public:
	static Engine* Get();
	void Update();
	const bool IsGameRunning() const;
	void StopGame();
	void Init();
	void Start();
	void Uninit();
	void AddObject(ObjectBase* obj);
	void DeleteObject(ObjectBase* obj);
	// Deletes all objects. ForceDelete will delete all objects now instead of at the end of the frame. only use if you know what you are doing.
	void ClearScreen(bool forceDelete = false);

	// Returns every object that is colliding with it as a vector
	std::vector<ObjectBase*> GetAllCollisionsWith(ObjectBase* Obj);
	// returns true if the 2 objects are colliding
	bool IsColliding(ObjectBase* obj1, ObjectBase* obj2);
	ObjectBase* GetClosestObject(ObjectBase* obj, const char* findOnly = "");
	std::vector<ObjectBase*> GetObjectsWithName(const char* nameToSearch);

	double DT();
};