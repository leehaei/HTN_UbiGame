#include "Plagued.h"

#include "GameEngine/Util/AnimationManager.h"

using namespace Game;

Plagued::Plagued()
{
}

Plagued::~Plagued()
{
}

void Plagued::OnAddToWorld()
{
	__super::OnAddToWorld();

	if (m_animComponent)
	{
		//m_animComponent->PlayAnim(GameEngine::EAnimationId::BirdIdle);
	}
}

void Plagued::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void Plagued::OnInteract()
{

}
