#include "Renderer.h"
#include "Globals.h"
#include "SDLCLasses.h"
#include "Image.h"
#include "ObjectBase.h"
#include "SDL.h"

Renderer* Renderer::s_instance = nullptr;

Renderer::Renderer()
{
    // creates a renderer if it doesnt exist
    SDLClasses::GetRenderer();
    SDLClasses::GetWindow();

    CameraCentre = nullptr;
}

Image* Renderer::AddImage(const char* Path)
{
	m_StoredImages.insert({ Path, new Image(Path) });
    return m_StoredImages.at(Path);
}

Image* Renderer::AddImage(const char* Path, const char* Path2)
{
    return nullptr;
}

void Renderer::DrawImage(Image* img, SDL_Rect* rect, int YOffset)
{
    SDL_Rect temp = *rect;
    float OffsetX = rect->w / 2;
    float OffsetY = YOffset + (rect->h / 2);
    if (CameraCentre != nullptr)
    {
        temp.x += (Globals::HALF_SCREEN_WIDTH - CameraCentre->rect.x - OffsetX);
        temp.y += (Globals::HALF_SCREEN_HEIGHT - CameraCentre->rect.y - OffsetY);
    }

	SDL_RenderCopy(SDLClasses::GetRenderer(), img->GetTexture(), NULL, &temp);
}

void Renderer::SetCamera(ObjectBase* centre)
{
    CameraCentre = centre;
}

Renderer* Renderer::Get()
{
    return s_instance != nullptr ? s_instance : s_instance = new Renderer();
}
