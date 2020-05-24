#include "PlayerEntity.h"

#include "Game/GameComponents/PlayerSoundComponent.h"
#include "Game/GameComponents/PlayerCameraComponent.h"

#include "Game/GameComponents/PlayerCollisionComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"
#include "GameEngine/Util/AnimationManager.h"
#include "GameEngine/Util/CollisionManager.h"
#include "SuspectEntity.h"
#include <iostream>
#include "Collectible.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

PlayerEntity::PlayerEntity() : lastNPCRef(nullptr), isInteractKeyPressed(false), isThreatKeyPressed(false), isArrestKeyPressed(false), isDead(false)
{
	//Movement
	m_playerMovementComponent = static_cast<PlayerMovementComponent*>(AddComponent<PlayerMovementComponent>());

	//Movement
	pawnPhysicsComponent = static_cast<PawnPhysicsComponent*>(AddComponent<PawnPhysicsComponent>());

	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	m_renderComponent->SetZLevel(2);

	//Animation
	m_animComponent = static_cast<GameEngine::AnimationComponent*>(AddComponent<GameEngine::AnimationComponent>());

	//Collisions
	AddComponent<PlayerCollisionComponent>();

	//Sound
	GameEngine::SoundComponent* const soundComponent = static_cast<GameEngine::SoundComponent*>(AddComponent<GameEngine::SoundComponent>());
	soundComponent->SetNumSimultaneousSounds(2); // Hard coded 5 simultaneous sounds for the player

	AddComponent<PlayerSoundComponent>();

	//Camera control
	AddComponent<PlayerCameraComponent>();

	items = "Items: \n";

	ui = new UIEntity();
	ui->SetText(items);
	ui->SetTextSize(18);
	ui->SetColor(sf::Color::Green);
}


PlayerEntity::~PlayerEntity()
{

}


void PlayerEntity::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (m_animComponent)
	{
		m_animComponent->PlayAnim(GameEngine::EAnimationId::None);
	}

	GameEngine::GameEngineMain::GetInstance()->AddEntity(ui);
	//ui->AttachToEntity(this, -100.0f, -300.0f);
}


void PlayerEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void PlayerEntity::Death()
{
	if (m_animComponent)
	{
		m_animComponent->PlayAnim(GameEngine::EAnimationId::None);
		while (m_animComponent->IsAnimPlaying()) {};
	}
}

void PlayerEntity::Attack()
{
	if (m_animComponent)
	{
		m_animComponent->PlayAnim(GameEngine::EAnimationId::None);
		while (m_animComponent->IsAnimPlaying()) {};
	}
}

void PlayerEntity::Update()
{
	__super::Update();

	//UI
	ui->SetPos(sf::Vector2f(GetPos().x - 400.0f, -250.0f));
	ui->Update();

	//Gamepad logic
	if (sf::Joystick::isConnected(0))
	{
		if (sf::Joystick::isButtonPressed(0, 1))
		{
			isInteractKeyPressed = true;
		}
		else
		{
			if (lastNPCRef && isInteractKeyPressed)
			{

				isInteractKeyPressed = false;
				lastNPCRef->OnInteract();
				if (Collectible* col = dynamic_cast<Collectible*>(lastNPCRef))
				{
					if (!col->GetHidden())
					{
						list.push_back(col->GetName());
						items.append(col->GetName() + "\n");
						ui->SetText(items);
						col->hidden = true;
					}
				}
				//std::cout << "OnInteract\n";
			}

		}

		if (sf::Joystick::isButtonPressed(0, 3))
		{
			isThreatKeyPressed = true;
		}
		else
		{
			//Threaten
			if (isThreatKeyPressed)
			{
				isThreatKeyPressed = false;
				if (SuspectEntity* se = dynamic_cast<SuspectEntity*>(lastNPCRef))
				{
					bool threatenable = false;
					for (auto item : list)
					{
						if (item == se->getThreatenableItem())
						{
							threatenable = true;
						}
					}
					se->OnThreaten(threatenable);
					isDead = se->isPlayerDead();
					//std::cout << "Threaten\n";
				}
			}
		}
		//Arrest
		if (sf::Joystick::isButtonPressed(0, 2))
		{
			isArrestKeyPressed = true;
		}
		else
		{
			if (isArrestKeyPressed)
			{
				isArrestKeyPressed = false;
				if (SuspectEntity* se = dynamic_cast<SuspectEntity*>(lastNPCRef))
				{
					se->OnArrest();
					Attack();
					isDead = se->isPlayerDead();
					//std::cout << "Arrest\n";
				}
			}
		}

	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			if (lastNPCRef && !isInteractKeyPressed)
			{
				isInteractKeyPressed = true;
				lastNPCRef->OnInteract();
				if (Collectible* col = dynamic_cast<Collectible*>(lastNPCRef))
				{
					items.append(col->GetName() + "\n");
				}
			}
			else
			{
				isInteractKeyPressed = false;
			}
		}
	}
}
