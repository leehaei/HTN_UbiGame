#include "Collectible.h"
#include "GameEngine/GameEngineMain.h"


Collectible::Collectible(): hidden(false)
{
	
}


Collectible::~Collectible()
{
}

void Collectible::OnInteract()
{
	if(!hidden)
	{
		m_renderComponent->SetZLevel(-1);
		dialogues[0] = "";
	}
	
}

void Collectible::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (uiEntity)
	{
		uiEntity->SetTextSize(24);
		uiEntity->SetColor(sf::Color::Magenta);
		uiEntity->AttachToEntity(this, 5.0f, -5.0f);
	}
}

void Collectible::SetName(std::string name_)
{
	name = name_;
	dialogues.push_back(name);
	SetDialogue(0);
}

std::string Collectible::GetName()
{
	return name;
}
