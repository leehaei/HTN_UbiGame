#pragma once
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "Game/GameEntities/PlayerEntity.h"

namespace Game
{

	class PlayerCollisionComponent : public GameEngine::CollidablePhysicsComponent
	{
	public:
		PlayerCollisionComponent();
		~PlayerCollisionComponent();

		virtual void OnAddToWorld() override;

		virtual void Update() override;

		virtual void CheckCollisionTag(CollidableComponent* collidedComponent) override;
		void CheckForOverlapTrigger();

		bool DidCollide() { return m_didCollide; }

	protected:
		Game::PlayerEntity* player;

		bool m_didCollide;

		bool isOverlapping;
	};

}
