#pragma once
#include "Globals.h"
#include <map>
class SDL_Texture; class Image; class SDL_Rect; class ObjectBase;
class Renderer
{
public:
	static Renderer* Get();
	Image* AddImage(const char* Path);
	void DrawImage(Image* img, SDL_Rect* rect, int YOffset = 0);
	ObjectBase* CameraCentre;
	void SetCamera(ObjectBase* centre);


private:
	Renderer();
	//~Renderer();
	static Renderer* s_instance;
	// Key - Image Path
	// Value - Image Class
	std::map<const char*, Image*> m_StoredImages;

};

