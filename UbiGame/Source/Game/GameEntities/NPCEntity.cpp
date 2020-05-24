#include "NPCEntity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

NPCEntity::NPCEntity(): uiActive(false), uiEntity(nullptr), currentDialogueIndex(0)
{
}


NPCEntity::~NPCEntity()
{
}

void NPCEntity::OnAddToWorld()
{
	__super::OnAddToWorld();

	uiEntity = new UIEntity();
	uiEntity->SetText("");
	uiEntity->SetTextSize(18);
	uiEntity->SetColor(sf::Color::Green);
	uiEntity->AttachToEntity(this, ((float)(-GetSize().x) / 2), (float)(-GetSize().y*0.65));
}

void NPCEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}

void NPCEntity::DisplayDialogue()
{
	if(!uiActive)
	{
		uiActive = true;
		uiEntity->SetText(dialogues.at(currentDialogueIndex));
		currentDisplayString = dialogues.at(currentDialogueIndex);
	}
	if (!IsDisplayString())
	{
		uiEntity->SetText(dialogues.at(currentDialogueIndex));
	}
}

void NPCEntity::HideDialogue()
{
	uiEntity->SetText("");
	uiActive = false;
}

void NPCEntity::SetDialogue(int dialogueIndex_)
{
	currentDialogueIndex = dialogueIndex_;
}

void NPCEntity::OnInteract()
{
	HideDialogue();
}

bool NPCEntity::IsDisplayString()
{
	return currentDisplayString == dialogues.at(currentDialogueIndex);
}
