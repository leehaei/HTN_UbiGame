#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextComponent.h"

namespace  Game
{
	class UIEntity : public GameEngine::Entity
	{
	public:
		UIEntity();
		~UIEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void Update() override;

		void AttachToEntity(Entity* entityToAttachTo_, float offX_, float offY_);
		void SetText(std::string text_);
		void SetTextSize(int size_);
		void SetColor(sf::Color color_);

	private:
		GameEngine::TextComponent* textComp;

		float offX;
		float offY;

		Entity* parentEntity;
	};
}
