#include "PlayerMovementComponent.h"

#include "GameEngine\GameEngineMain.h"
#include "GameEngine\EntitySystem\Components\SoundComponent.h"

#include "GameEngine\Util\AnimationManager.h"

#include "Game\GameComponents\PlayerSoundComponent.h"

#include <SFML/Window/Keyboard.hpp>
#include "PawnPhysicsComponent.h"

using namespace Game;

PlayerMovementComponent::PlayerMovementComponent()
	: m_flyTimerDt(0.f)
	, m_flyTimerMaxTime(2.f)
	, m_animComponent(nullptr)
	, m_playerSoundComponent(nullptr)
	, jumpSpeed(50000.0f)
	, jumping(false)
	, grounded(true)
{

}


PlayerMovementComponent::~PlayerMovementComponent()
{

}

void PlayerMovementComponent::OnAddToWorld()
{
	m_animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
	m_playerSoundComponent = GetEntity()->GetComponent<PlayerSoundComponent>();
}

void PlayerMovementComponent::SetGrounded(bool grounded_)
{
	grounded = grounded_;
}


void PlayerMovementComponent::Update()
{
	__super::Update();

	if (GameEngine::GameEngineMain::GetInstance()->IsGameOver())
	{
		return;
	}

	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	static bool  debugSounds = false;
	static float playerVel = 150.0f; //Pixels/s


	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);
	bool wantsToFly = false;

	PawnPhysicsComponent* pawnPhy = GetEntity()->GetComponent<PawnPhysicsComponent>();

	//Gamepad logic
	if (sf::Joystick::isConnected(0))
	{
		// joystick number 0 is connected
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		if (x == -100)
		{
			wantedVel.x += x;
			if (wasNothingPressed)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::PlayerLeft);
			}
			wasNothingPressed = false;
			wasLeftPressed = true;
			wasRightPressed = false;
		}
		else if (x == 100)
		{
			wantedVel.x += x;
			if (wasNothingPressed)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::PlayerRight);
			}
			wasNothingPressed = false;
			wasRightPressed = true;
			wasLeftPressed = false;
		}
		else
		{
			wasNothingPressed = true;
			if (wasRightPressed || wasLeftPressed) {
				m_animComponent->PlayAnim(GameEngine::EAnimationId::None);
			}
		}

		if (sf::Joystick::isButtonPressed(0, 0))
		{
			if (grounded)
			{
				grounded = false;
				wantedVel.y -= jumpSpeed;
			}
		}

		if(pawnPhy)
			pawnPhy->SetVelocity(wantedVel);
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			wantedVel.x -= playerVel;
			if (wasNothingPressed)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::PlayerLeft);
			}
			wasNothingPressed = false;
			wasLeftPressed = true;
			wasRightPressed = false;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			wantedVel.x += playerVel;
			if (wasNothingPressed)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::PlayerRight);
			}
			wasNothingPressed = false;
			wasRightPressed = true;
			wasLeftPressed = false;
		} 
		else 
		{
			wasNothingPressed = true;
			if (wasRightPressed || wasLeftPressed) {
				m_animComponent->PlayAnim(GameEngine::EAnimationId::None);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (!jumping && grounded)
			{
				jumping = true;
				grounded = false;
				wantedVel.y -= jumpSpeed;
				//pawnPhy->AddForce(sf::Vector2f(0.0f,1000.0f));
			}
		}
		else
		{
			jumping = false;
		}

	}

	if (pawnPhy)
	{
		pawnPhy->SetVelocity(wantedVel);
	}

	if (wantedVel != sf::Vector2f(0.f, 0.f))
	{
		m_flyTimerDt = m_flyTimerMaxTime;
	}
	else
	{
		m_flyTimerDt -= dt;
	}

	static float rotationVel = 50.f; //Deg/s
	static float maxRotation = 20.f; //Deg

	float currentRotation = GetEntity()->GetRot();
	float wantedRot = 0.f;
	bool  reseting = false;

	if (wantedVel.y > 0.f)
		wantedRot = rotationVel;
	else if (wantedVel.y < 0.f)
		wantedRot = -rotationVel;
	else
	{
		if (currentRotation > 0.f)
			wantedRot = -rotationVel;
		else if (currentRotation < 0.f)
			wantedRot = rotationVel;
	}

	float frameRot = wantedRot * dt;
	float totalRot = currentRotation + frameRot;

	if (!reseting)
	{
		if (totalRot > maxRotation)
			totalRot = maxRotation;
		else if (totalRot < -maxRotation)
			totalRot = -maxRotation;
	}
	else
	{
		if (currentRotation > 0.f && totalRot < 0.f)
			totalRot = 0.f;
		if (currentRotation < 0.f && totalRot > 0.f)
			totalRot = 0.f;
	}

	GetEntity()->SetRotation(totalRot);
}
