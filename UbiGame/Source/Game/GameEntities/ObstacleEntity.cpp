#include "ObstacleEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include <SFML/Graphics.hpp>

using namespace Game;

ObstacleEntity::ObstacleEntity()	
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Red);
	m_renderComponent->SetTexture(GameEngine::eTexture::Tileset);
	m_renderComponent->SetZLevel(2);
	m_renderComponent->SetTileIndex(0, 0);

	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("Ground");
}


ObstacleEntity::~ObstacleEntity()
{

}


void ObstacleEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void ObstacleEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}
