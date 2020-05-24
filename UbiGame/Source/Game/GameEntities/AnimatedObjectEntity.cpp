#include "AnimatedObjectEntity.h"

#include "GameEngine/Util/AnimationManager.h"


using namespace Game;


AnimatedObjectEntity::AnimatedObjectEntity()
	: animation(GameEngine::EAnimationId::None)
	, texture(GameEngine::eTexture::None)
{
	SetupObject();
}


AnimatedObjectEntity::AnimatedObjectEntity(GameEngine::EAnimationId::type anim, GameEngine::eTexture::type text)
	: animation(anim)
	, texture(text)
{
	SetupObject();
}


AnimatedObjectEntity::~AnimatedObjectEntity()
{

}


void AnimatedObjectEntity::SetupObject()
{
	//Render 
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetTexture(texture);
	m_renderComponent->SetZLevel(1);

	//Animation
	m_animComponent = static_cast<GameEngine::AnimationComponent*>(AddComponent<GameEngine::AnimationComponent>());
}


void AnimatedObjectEntity::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (m_animComponent)
	{
		m_animComponent->PlayAnim(animation);
	}
}


void AnimatedObjectEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

