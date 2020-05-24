#include "AnimationManager.h"


using namespace GameEngine;

AnimationManager* AnimationManager::sm_instance = nullptr;

AnimationManager::AnimationManager()
{

}


AnimationManager::~AnimationManager()
{

}


void AnimationManager::InitStaticGameAnimations()
{
	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerRight,
			eTexture::Player,
			sf::Vector2i(0, 0),
			8,
			10)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerLeft,
			eTexture::Player,
			sf::Vector2i(0, 1),
			8,
			10)
	);

	/*m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerIdle,
			eTexture::PlayerIdle,
			sf::Vector2i(0, 0),
			1,
			1)
	);*/

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerAttack,
			eTexture::Player,
			sf::Vector2i(0, 3),
			15,
			10)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerDead,
			eTexture::Player,
			sf::Vector2i(0, 2),
			18,
			8)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::CowAnim,
			eTexture::Cow,
			sf::Vector2i(0, 0),
			10,
			6)
	);
	/*
	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::Fire1,
			eTexture::Cow,
			sf::Vector2i(0, 0),
			10,
			8)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::Fire2,
			eTexture::Cow,
			sf::Vector2i(0, 0),
			10,
			8)
	);
	*/
}


void AnimationManager::ReleaseStaticGameAnimations()
{
	m_animDefinitions.clear();
}


const SAnimationDefinition* AnimationManager::GetAnimDefinition(EAnimationId::type animId) const
{
	for (int a = 0; a < m_animDefinitions.size(); ++a)
	{
		if (m_animDefinitions[a].m_animId == animId)
			return &m_animDefinitions[a];
	}

	return nullptr;
}
