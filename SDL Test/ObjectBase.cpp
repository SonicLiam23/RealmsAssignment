#include "ObjectBase.h"
#include "Renderer.h"

ObjectBase::ObjectBase(SDL_Rect pos) : m_img(nullptr), rect(pos), CollisionEnabled(true)
{

}

void ObjectBase::Render()
{
	if (m_img != nullptr)
	{
		Renderer::Get()->DrawImage(m_img, &rect);
	}
}

void ObjectBase::SetImage(const char* Path)
{
	m_img = Renderer::Get()->AddImage(Path);
}

SDL_Rect* ObjectBase::GetPosition()
{
	return &rect;
}
