#pragma once 

#include "GameEngine\EntitySystem\Entity.h" 
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h" 
#include <vector> 

namespace Game
{
	class BackgroundEntity : public GameEngine::Entity
	{

	public:
		BackgroundEntity();
		~BackgroundEntity();
		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		std::vector<GameEngine::Entity*> renderObjects();
	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
	};

}