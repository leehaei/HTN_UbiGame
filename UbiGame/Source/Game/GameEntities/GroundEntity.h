#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"

namespace Game
{

	class GroundEntity : public GameEngine::Entity
	{
	public:
		GroundEntity();
		~GroundEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;

		GameEngine::CollidableComponent* collider;
	};
}

