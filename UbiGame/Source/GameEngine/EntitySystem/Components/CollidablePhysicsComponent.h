#pragma once
#include "GameEngine\EntitySystem\Components\CollidableComponent.h"

namespace GameEngine
{
	//This one allows for movement and obstacle detection, 
	class CollidablePhysicsComponent : public CollidableComponent
	{
	public:
		CollidablePhysicsComponent();
		virtual ~CollidablePhysicsComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void Update() override;

		virtual void CheckCollisionTag(CollidableComponent* collidedComponent);

		bool DidCollide() { return m_didCollide; }
	protected:
		bool m_didCollide;
	};
}

