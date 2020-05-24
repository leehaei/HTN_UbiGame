#include "PlayerCollisionComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameEntities/NPCEntity.h"
#include "GameEngine/Util/CollisionManager.h"


Game::PlayerCollisionComponent::PlayerCollisionComponent(): player(nullptr)
{
}


Game::PlayerCollisionComponent::~PlayerCollisionComponent()
{
}

void Game::PlayerCollisionComponent::OnAddToWorld()
{
	__super::OnAddToWorld();

	player = dynamic_cast<Game::PlayerEntity*>(GetEntity());
}

void Game::PlayerCollisionComponent::Update()
{	
	__super::Update();

	CheckForOverlapTrigger();
}

void Game::PlayerCollisionComponent::CheckCollisionTag(CollidableComponent* collidedComponent)
{
	__super::CheckCollisionTag(collidedComponent);

	if(collidedComponent->GetTag() == "Ground")
	{
		player->GetComponent<Game::PlayerMovementComponent>()->SetGrounded(true);
		player->GetComponent<PawnPhysicsComponent>()->SetVelocity(sf::Vector2f(0.0f, 0.0f));
	}
	//if(collidedComponent->GetTag() == "NPC")
	//{
	//	//TODO: NPC dialogue logic
	//	if(player->lastNPCRef)
	//	{
	//		//GameEngine::CollisionManager::GetInstance()->RegisterCollidable(static_cast<CollidableComponent*>(collidedComponent));
	//	}
	//	player->lastNPCRef = static_cast<NPCEntity*>(collidedComponent->GetEntity());
	//	player->lastNPCRef->DisplayDialogue();
	//}
}

void Game::PlayerCollisionComponent::CheckForOverlapTrigger()
{
	//Check colisions with obstacles
	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector< GameEngine::CollidableComponent*>& collidables = GameEngine::CollisionManager::GetInstance()->GetCollidables();

	for (int a = 0; a < collidables.size(); ++a)
	{
		GameEngine::CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;

		GameEngine::AABBRect intersection;
		GameEngine::AABBRect myBox = GetWorldAABB();
		GameEngine::AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			if (colComponent->GetTag() == "NPC")
			{
				//Collision occured!
				//TODO: NPC dialogue logic
				player->lastNPCRef = static_cast<NPCEntity*>(colComponent->GetEntity());
				player->lastNPCRef->DisplayDialogue();
			}
			else if(colComponent->GetTag() == "Ground")
			{
				player->GetComponent<Game::PlayerMovementComponent>()->SetGrounded(true);
			}
		}
		else
		{
			if(player && player->lastNPCRef)
			{
				if(abs(player->lastNPCRef->GetPos().x - player->GetPos().x) >= 50.0f)
				{
					player->lastNPCRef->HideDialogue();
				}
			}
			
		}
	}
}
