#pragma once

#include "Game/GameEntities/NPCEntity.h"

namespace Game
{

	class Plagued : public NPCEntity
	{
	public:
		Plagued();
		~Plagued();

		void OnAddToWorld();
		void OnRemoveFromWorld();
		void OnInteract();

	};
}