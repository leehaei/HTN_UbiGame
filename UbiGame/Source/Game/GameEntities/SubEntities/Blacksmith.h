#pragma once

#include "Game/GameEntities/SuspectEntity.h"

namespace Game
{

	class Blacksmith : public SuspectEntity
	{
	public:
		Blacksmith();
		~Blacksmith();

		void OnAddToWorld();
		void OnRemoveFromWorld();
		void OnInteract();
		void OnThreaten(bool threatened) override;
		void OnArrest();

	};
}
