#include "BloodiedHammer.h"

using namespace Game;

BloodiedHammer::BloodiedHammer()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::BloodiedHammer);
	m_renderComponent->SetZLevel(3);

	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");

	SetName("Blood Stained Hammer");
}


BloodiedHammer::~BloodiedHammer()
{
}
