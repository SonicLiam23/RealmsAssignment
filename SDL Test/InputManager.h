#pragma once
#include "SDL_scancode.h"
#include "SDL_events.h"
class InputManager
{
public:
	static InputManager* Get();
	void Update();
	
	bool GetKeyUp(SDL_Keycode Key) const;
	bool GetKeyDown(SDL_Keycode Key) const;
	bool GetKeyHeld(SDL_Keycode Key) const;
	

private:	
	enum KEYPOS
	{
		NONE,
		UP,
		DOWN,
		HELD
	};

	InputManager();
	static InputManager* s_Instance;
	SDL_Scancode NewScanCode;
	KEYPOS m_PressedKeys[SDL_NUM_SCANCODES];


};