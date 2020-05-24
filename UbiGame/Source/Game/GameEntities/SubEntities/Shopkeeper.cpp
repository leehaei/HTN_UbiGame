#include "Shopkeeper.h"

#include "GameEngine/Util/AnimationManager.h"

using namespace Game;

Shopkeeper::Shopkeeper()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::Shopkeeper);
	m_renderComponent->SetZLevel(2);

	//Collision
	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");

	dialogues.at(0) = std::string("Hello! I am the Shopkeeper.");
	SetDialogue(0);

	threatenableItem = "Panacea";
}

Shopkeeper::~Shopkeeper()
{
}

void Shopkeeper::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (uiEntity)
	{
		uiEntity->SetText("");
		uiEntity->SetTextSize(18);
		uiEntity->SetColor(sf::Color::Yellow);
	}

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Shopkeeper::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Shopkeeper::OnInteract()
{
	if (!uiEntity)
	{
		return;
	}

	if (randomInteractChecked)
	{
		SetDialogue(randomFirstCheckIndex);
	}
	else
	{
		// Correct Dice Roll
		if (randomInteractCheck())
		{
			SetDialogue(2);
			randomFirstCheckIndex = 2;
		}
		else
		{
			SetDialogue(1);
			randomFirstCheckIndex = 1;
		}
		randomInteractChecked = true;
	}
}

void Shopkeeper::OnThreaten(bool threatened)
{
	if (!uiEntity)
	{
		return;
	}
	if (threatened)
	{
		//Success
		SetDialogue(3);
	}
	else
	{
		SetDialogue(5);
		isPlayerKilled = true;
	}
}

void Shopkeeper::OnArrest()
{
	if (uiEntity)
	{
		SetDialogue(6);
		isPlayerKilled = true;
	}
}
