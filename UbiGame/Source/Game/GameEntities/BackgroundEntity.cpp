#include "BackgroundEntity.h" 
#include <SFML/Graphics.hpp> 
#include "GameEngine/GameEngineMain.h" 

using namespace Game;

BackgroundEntity::BackgroundEntity()
{

}

BackgroundEntity::~BackgroundEntity()
{

}

std::vector<GameEngine::Entity*> BackgroundEntity::renderObjects() {

	std::vector<GameEngine::Entity*> m_backgroundObjects;
	for (int i = 0; i < 4; ++i) {
		GameEngine::Entity* bg = new GameEngine::Entity();
		GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>(bg->AddComponent<GameEngine::SpriteRenderComponent>());
		render->SetTexture(GameEngine::eTexture::BGObject2);
		render->SetZLevel(1);
		bg->SetPos(sf::Vector2f(-10 + 4000 * (i), 10.f));
		bg->SetSize(sf::Vector2f(500.f, 500.f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg);

		m_backgroundObjects.push_back(bg);

		GameEngine::Entity* bg1 = new GameEngine::Entity();
		GameEngine::SpriteRenderComponent* render1 = static_cast<GameEngine::SpriteRenderComponent*>(bg1->AddComponent<GameEngine::SpriteRenderComponent>());
		render1->SetTexture(GameEngine::eTexture::BGObject1);
		render1->SetZLevel(1);
		bg1->SetPos(sf::Vector2f(400.0f + 4000 * (i), 235.0f));
		bg1->SetSize(sf::Vector2f(50.f, 50.f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg1);

		m_backgroundObjects.push_back(bg1);

		GameEngine::Entity* bg2 = new GameEngine::Entity();
		GameEngine::SpriteRenderComponent* render2 = static_cast<GameEngine::SpriteRenderComponent*>(bg2->AddComponent<GameEngine::SpriteRenderComponent>());
		render2->SetTexture(GameEngine::eTexture::BGObject3);
		render2->SetZLevel(1);
		bg2->SetPos(sf::Vector2f(1000.0f + 4000 * (i), 150.0f));
		bg2->SetSize(sf::Vector2f(120.f, 250.f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg2);

		m_backgroundObjects.push_back(bg2);

		GameEngine::Entity* bg3 = new GameEngine::Entity();
		GameEngine::SpriteRenderComponent* render3 = static_cast<GameEngine::SpriteRenderComponent*>(bg3->AddComponent<GameEngine::SpriteRenderComponent>());
		render3->SetTexture(GameEngine::eTexture::BGObject4);
		render3->SetZLevel(1);
		bg3->SetPos(sf::Vector2f(1700 + 4000 * (i), 140.f));
		bg3->SetSize(sf::Vector2f(500.f, 280.f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg3);

		m_backgroundObjects.push_back(bg3);

		GameEngine::Entity* bg4 = new GameEngine::Entity();
		GameEngine::SpriteRenderComponent* render4 = static_cast<GameEngine::SpriteRenderComponent*>(bg4->AddComponent<GameEngine::SpriteRenderComponent>());
		render4->SetTexture(GameEngine::eTexture::BGObject5);
		render4->SetZLevel(1);
		bg4->SetPos(sf::Vector2f(3000 + 4000 * (i), 150.f));
		bg4->SetSize(sf::Vector2f(300.f, 300.f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg4);

		m_backgroundObjects.push_back(bg4);

		GameEngine::Entity* bg5 = new GameEngine::Entity();
		GameEngine::SpriteRenderComponent* render5 = static_cast<GameEngine::SpriteRenderComponent*>(bg5->AddComponent<GameEngine::SpriteRenderComponent>());
		render5->SetTexture(GameEngine::eTexture::BGObject6);
		render5->SetZLevel(1);
		bg5->SetPos(sf::Vector2f(800 + 4000 * (i), 230.f));
		bg5->SetSize(sf::Vector2f(70.f, 70.f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg5);

		m_backgroundObjects.push_back(bg5);

		GameEngine::Entity* bg6 = new GameEngine::Entity();
		GameEngine::SpriteRenderComponent* render6 = static_cast<GameEngine::SpriteRenderComponent*>(bg6->AddComponent<GameEngine::SpriteRenderComponent>());
		render6->SetTexture(GameEngine::eTexture::BGObject7);
		render6->SetZLevel(1);
		bg6->SetPos(sf::Vector2f(2500 + 4000 * (i), 230.f));
		bg6->SetSize(sf::Vector2f(70.f, 70.f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bg6);

		m_backgroundObjects.push_back(bg6);
	}

	return m_backgroundObjects;

}

void BackgroundEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void BackgroundEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();

}