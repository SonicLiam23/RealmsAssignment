#pragma once
#include "SDL_ttf.h"
#include "SDL.h"
#include <string>

class Text
{
public:
	Text(const char* fontPath, int fontSize, const char* text, SDL_Colour colour);
	~Text();
	void DisplayText(int x, int y);
	SDL_Texture* showFont(const char* fontPath, int fontSize, const char* text, SDL_Colour colour);


private:
	SDL_Texture* textTexture;
	SDL_Rect* textRect;

};

