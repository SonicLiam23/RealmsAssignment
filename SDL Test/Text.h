#pragma once
#include "SDL_ttf.h"

class Text
{
public:
	Text(SDL_Renderer* renderer, const char* Text);
	void Render();
	void SetText(const char* NewText);
	~Text();


private:
	SDL_Renderer* m_Renderer;
	TTF_Font* m_Font;
	SDL_Color White;
	SDL_Surface* Surface;
	const char* m_Text;
	SDL_Texture* Message;
	const SDL_Rect Rect;

};

