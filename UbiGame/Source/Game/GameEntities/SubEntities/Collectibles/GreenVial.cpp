#include "GreenVial.h"

using namespace Game;

GreenVial::GreenVial()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::GreenVial);
	m_renderComponent->SetZLevel(3);

	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");

	SetName("Green Vial");
}


GreenVial::~GreenVial()
{
}
