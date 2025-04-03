#include "Text.h"

Text::Text(SDL_Renderer* renderer, const char* Text) : m_Renderer(renderer), m_Text(Text), Rect({ 0, 0, 150, 50 })
{
	TTF_Init();
	White = { 255, 255, 255 };
	m_Font = TTF_OpenFont("Font/arial.ttf", 24);
	Surface = TTF_RenderText_Solid(m_Font, Text, White);
	Message = SDL_CreateTextureFromSurface(renderer, Surface);
}

void Text::Render()
{
	SDL_RenderCopy(m_Renderer, Message, NULL, &Rect);
}

void Text::SetText(const char* NewText)
{
	SDL_FreeSurface(Surface);
	SDL_DestroyTexture(Message);

	Surface = TTF_RenderText_Solid(m_Font, NewText, White);
	Message = SDL_CreateTextureFromSurface(m_Renderer, Surface);
}

Text::~Text()
{
	TTF_CloseFont(m_Font);
	SDL_FreeSurface(Surface);
	SDL_DestroyTexture(Message);
}