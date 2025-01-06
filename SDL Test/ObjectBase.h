#pragma once
#include "SDL_rect.h"
class Image;


/*
* Base for the objects
* each object will need an update, render, start, end and a function to return its own name
* each class inherited from this will be its own object, like unity, each unique object will have its own class
* 
*/
class ObjectBase
{
public:
	ObjectBase(SDL_Rect pos = { 0, 0, 320, 320 });
	virtual void Update() = 0;
	virtual void Render();
	virtual const char* GetName() = 0;
	virtual void Execute() = 0;
	void SetImage(const char* Path);
	bool CollisionEnabled;
	bool isStatic;
	SDL_Rect* GetPosition();
	SDL_Rect rect;

protected:
	int CameraOffset;
	Image* m_img;
	
};

