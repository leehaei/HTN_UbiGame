#pragma once

#include "Game/GameEntities/SuspectEntity.h"

namespace Game
{
	class Plaguedoctor : public SuspectEntity
	{
	public:
		Plaguedoctor();
		~Plaguedoctor();

		void OnAddToWorld();
		void OnRemoveFromWorld();
		void OnInteract();
		void OnThreaten(bool threatened) override;
		void OnArrest();
	};
}