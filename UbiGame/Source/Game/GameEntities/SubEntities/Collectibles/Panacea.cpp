#include "Panacea.h"

using namespace  Game;

Panacea::Panacea()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Panacea);
	m_renderComponent->SetZLevel(3);

	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");

	SetName("Panacea");
}


Panacea::~Panacea()
{
}
