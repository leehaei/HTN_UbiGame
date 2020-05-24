#include "GroundEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include <SFML/Graphics.hpp>

using namespace Game;

GroundEntity::GroundEntity()
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Red);
	m_renderComponent->SetTexture(GameEngine::eTexture::Ground);
	m_renderComponent->SetZLevel(1);
	m_renderComponent->SetTileIndex(0, 0);

	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("Ground");
}


GroundEntity::~GroundEntity()
{

}


void GroundEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void GroundEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}
