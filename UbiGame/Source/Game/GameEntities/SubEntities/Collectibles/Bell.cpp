#include "Bell.h"

using namespace Game;

Bell::Bell()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Bell);
	m_renderComponent->SetZLevel(3);

	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");

	SetName("Bell");
}


Bell::~Bell()
{
}
