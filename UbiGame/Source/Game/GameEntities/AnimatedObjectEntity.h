#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\AnimationComponent.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"


namespace Game
{

	class AnimatedObjectEntity : public GameEngine::Entity
	{
	public:
		AnimatedObjectEntity();
		AnimatedObjectEntity(GameEngine::EAnimationId::type anim, GameEngine::eTexture::type text);
		~AnimatedObjectEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::AnimationComponent* m_animComponent;

		void SetupObject();

		GameEngine::EAnimationId::type animation;
		GameEngine::eTexture::type texture;

	};
}

