#include "SDLCLasses.h"
#include "Text.h"
#include <iostream>

Text::Text(const char* fontPath, int fontSize, const char* text, SDL_Colour colour)
{
	textRect = new SDL_Rect{ 10, 10, 20, 20 };
	textTexture = showFont(fontPath, fontSize, text, colour);
	SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect->w, &textRect->h);
}


void Text::DisplayText(int x, int y)
{
	textRect->x = x;
	textRect->y = y;
	SDL_RenderCopy(SDLClasses::GetRenderer(), textTexture, nullptr, textRect);
}



SDL_Texture* Text::showFont(const char* fontPath, int fontSize, const char* text, SDL_Colour colour)
{
	TTF_Font* font = TTF_OpenFont(fontPath, fontSize);

	if (!font)
	{
		std::cout << "No font for you!" << std::endl;
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, colour);

	if (!textSurface)
	{
		std::cout << "No surface for you!" << std::endl;
	}

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(SDLClasses::GetRenderer(), textSurface);

	if (!textTexture)
	{
		std::cout << "No texture for you!" << std::endl;
	}


	SDL_FreeSurface(textSurface);

	return textTexture;


}

Text::~Text()
{
	delete textRect;
	SDL_DestroyTexture(textTexture);
}