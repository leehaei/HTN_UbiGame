#pragma once

#include "UIEntity.h"
#include "GameEngine/GameEngineMain.h"

Game::UIEntity::UIEntity()
{
	//TODO: Testing text comp
	textComp = static_cast<GameEngine::TextComponent*>(AddComponent<GameEngine::TextComponent>());
	textComp->SetFont("arial.ttf");
	textComp->SetText("Hello World", 32, sf::Color::Red);
	textComp->SetZLevel(4);
}


Game::UIEntity::~UIEntity()
{
	delete textComp;
	textComp = nullptr;
}

void Game::UIEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void Game::UIEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Game::UIEntity::Update()
{
	if (parentEntity) {
		SetPos(parentEntity->GetPos() + sf::Vector2f(offX, offY));
	}
}

void Game::UIEntity::AttachToEntity(Entity* entityToAttachTo_ ,float offX_, float offY_)
{
	parentEntity = entityToAttachTo_;

	offX = offX_;
	offY = offY_;

	this->SetPos(parentEntity->GetPos() + sf::Vector2f(offX, offY));
	__super::SetSize(sf::Vector2f(40.f, 40.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(this);
}

void Game::UIEntity::SetText(std::string text_)
{
	textComp->SetText(text_);
}

void Game::UIEntity::SetTextSize(int size_)
{
	textComp->SetSize(size_);
}

void Game::UIEntity::SetColor(sf::Color color_)
{
	textComp->SetColor(color_);
}
