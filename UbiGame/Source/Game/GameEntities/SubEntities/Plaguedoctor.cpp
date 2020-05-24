#include "Plaguedoctor.h"

#include "GameEngine/Util/AnimationManager.h"

using namespace Game;

Plaguedoctor::Plaguedoctor()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(GameEngine::eTexture::PlagueDoctor);
	m_renderComponent->SetZLevel(2);

	//Collision
	collider = static_cast<GameEngine::CollidableComponent*>(AddComponent<GameEngine::CollidableComponent>());
	collider->SetTag("NPC");

	dialogues.at(0) = std::string("Hello! I am the Plague Doctor.");
	dialogues.at(2) = std::string("The Blacksmith has been up to suspicious activity recently.\n You should talk to him.");
	SetDialogue(0);

	threatenableItem = "Green Vial";
}

Plaguedoctor::~Plaguedoctor()
{
}

void Plaguedoctor::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (uiEntity)
	{
		uiEntity->SetText("");
		uiEntity->SetTextSize(18);
		uiEntity->SetColor(sf::Color::Red);
	}

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Plaguedoctor::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Plaguedoctor::OnInteract()
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
		//Correct dice roll
		if (randomInteractCheck())
		{
			SetDialogue(1);
			randomFirstCheckIndex = 1;
		}
		else
		{
			SetDialogue(2);
			randomFirstCheckIndex = 2;
		}
		randomInteractChecked = true;
	}
}

void Plaguedoctor::OnThreaten(bool threatened)
{
	if (!uiEntity)
	{
		return;
	}
	if (threatened)
	{
		//Success
		SetDialogue(4);
	}
	else
	{
		SetDialogue(5);
		isPlayerKilled = true;
	}
}

void Plaguedoctor::OnArrest()
{
	if (uiEntity)
	{
		SetDialogue(7);
	}
}
