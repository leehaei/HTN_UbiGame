#include "PawnPhysicsComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "PlayerCollisionComponent.h"


Game::PawnPhysicsComponent::PawnPhysicsComponent():velocity(0.0f,0.0f), mass(1.0f), acceleration(0.0f, 0.0f)
{
}


Game::PawnPhysicsComponent::~PawnPhysicsComponent()
{
}

void Game::PawnPhysicsComponent::OnAddToWorld()
{
	//lastPos = GetEntity()->GetPos();
}

void Game::PawnPhysicsComponent::Update()
{
	
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	float gravity = 100.0f;

	velocity.y += gravity;

	//sf::Vector2f deltaPos = velocity * dt + 0.5f * acceleration * dt * dt;

	sf::Vector2f deltaVelocity = velocity * dt;

	GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);
	
	__super::Update();

	if (GetEntity()->GetComponent<PlayerCollisionComponent>()->DidCollide())
	{
		velocity.y = 0;
		GetEntity()->SetPos(GetEntity()->GetPos() - deltaVelocity);
	}

}

void Game::PawnPhysicsComponent::AddForce(sf::Vector2f force_)
{
	acceleration = force_ / mass;
}

void Game::PawnPhysicsComponent::SetVelocity(sf::Vector2f velocity_)
{
	velocity = velocity_;
}
