#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "UIEntity.h"

namespace Game
{
	class NPCEntity : public GameEngine::Entity
	{
	public:
		NPCEntity();
		~NPCEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		virtual void OnInteract();
		virtual void DisplayDialogue();
		virtual void HideDialogue();
		virtual void SetDialogue(int dialogueIndex_);

	protected:
		bool IsDisplayString();

		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::AnimationComponent* m_animComponent;

		GameEngine::CollidableComponent* collider;

		//UI
		UIEntity* uiEntity;
		bool uiActive;

		std::vector<std::string> dialogues;
		int currentDialogueIndex;
		std::string currentDisplayString;
	};

}
