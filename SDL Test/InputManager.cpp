#include "InputManager.h"
InputManager* InputManager::s_Instance = nullptr;

InputManager::InputManager() : NewScanCode(SDL_SCANCODE_UNKNOWN)
{
	for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
	{
		m_PressedKeys[i] = NONE;
	}
}


InputManager* InputManager::Get()
{
	return s_Instance != nullptr ? s_Instance : s_Instance = new InputManager();
}

void InputManager::Update()
{
	SDL_Event Event;
	for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
	{
		if (m_PressedKeys[i] == DOWN)
		{
			m_PressedKeys[i] = HELD;
		}
		else if (m_PressedKeys[i] == UP)
		{
			m_PressedKeys[i] = NONE;
		}
	}

	while (SDL_PollEvent(&Event))
	{
		SDL_Scancode NewScanCode = SDL_GetScancodeFromKey(Event.key.keysym.sym);


		if (Event.type == SDL_KEYDOWN)
		{
			if (m_PressedKeys[NewScanCode] == NONE)
			{
				m_PressedKeys[NewScanCode] = DOWN;
			}
		}
		else if (Event.type == SDL_KEYUP)
		{
			m_PressedKeys[NewScanCode] = UP;
		}
	}
}

bool InputManager::GetKeyUp(SDL_Keycode Key) const
{
	SDL_Scancode Scan = SDL_GetScancodeFromKey(Key);
	return m_PressedKeys[Scan] == UP;
}

bool InputManager::GetKeyDown(SDL_Keycode Key) const 
{
	SDL_Scancode Scan = SDL_GetScancodeFromKey(Key);
	return m_PressedKeys[Scan] == DOWN;
}

bool InputManager::GetKeyHeld(SDL_Keycode Key) const
{
	SDL_Scancode Scan = SDL_GetScancodeFromKey(Key);
	return m_PressedKeys[Scan] == HELD;
}

