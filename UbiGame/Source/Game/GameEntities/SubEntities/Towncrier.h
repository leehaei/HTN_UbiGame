#pragma once

#include "Game/GameEntities/SuspectEntity.h"

namespace Game
{
	class Towncrier : public SuspectEntity
	{
	public:
		Towncrier();
		~Towncrier();

		void OnAddToWorld();
		void OnRemoveFromWorld();
		void OnInteract();
		void OnThreaten(bool threatened) override;
		void OnArrest();

	};
}