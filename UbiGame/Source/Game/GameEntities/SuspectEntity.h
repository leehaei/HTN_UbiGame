#pragma once
#include "NPCEntity.h"

namespace Game
{
	class SuspectEntity : public NPCEntity
	{
	public:
		SuspectEntity();
		~SuspectEntity();

		virtual void OnThreaten(bool threatened) = 0;
		virtual void OnArrest() = 0;
		bool randomInteractCheck();
		std::string getThreatenableItem();
		bool isPlayerDead();

	protected:
		bool randomInteractChecked;
		int randomFirstCheckIndex;
		std::string threatenableItem;
		bool isPlayerKilled;
	};
}
