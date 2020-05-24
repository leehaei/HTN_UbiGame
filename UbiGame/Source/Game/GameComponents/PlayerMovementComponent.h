#pragma once
#include "GameEngine\EntitySystem\Component.h"
#include "GameEngine\EntitySystem\Components\AnimationComponent.h"
#include "GameEngine\Util\SoundManager.h"

namespace Game
{	
	class PlayerSoundComponent;

	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		PlayerMovementComponent();
		~PlayerMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

		void SetGrounded(bool grounded_);

	private:
		float m_flyTimerDt;
		float m_flyTimerMaxTime;

		float jumpSpeed;
		bool jumping;
		bool grounded;

		bool wasNothingPressed = true;
		bool wasRightPressed = false;
		bool wasLeftPressed = false;

		GameEngine::AnimationComponent* m_animComponent;
		PlayerSoundComponent*			m_playerSoundComponent;

	};
}


