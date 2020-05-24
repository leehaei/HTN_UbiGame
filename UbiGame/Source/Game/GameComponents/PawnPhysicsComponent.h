#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/System/Vector2.hpp>
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace Game
{

	class PawnPhysicsComponent : public GameEngine::Component
	{
	public:
		PawnPhysicsComponent();
		~PawnPhysicsComponent();

		void OnAddToWorld() override;

		void Update() override;

		void AddForce(sf::Vector2f force_);

		void SetVelocity(sf::Vector2f velocity_);

	private:
		float mass;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
	};

}
