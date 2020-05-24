#pragma once

#include "Game/GameEntities/SuspectEntity.h"

namespace Game
{
	class Shopkeeper : public SuspectEntity
	{
	public:
		Shopkeeper();
		~Shopkeeper();

		void OnAddToWorld();
		void OnRemoveFromWorld();
		void OnInteract();
		void OnThreaten(bool threatened) override;
		void OnArrest();
	};
}