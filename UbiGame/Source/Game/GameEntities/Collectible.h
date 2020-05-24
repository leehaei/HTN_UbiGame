#pragma once
#include "NPCEntity.h"

class Collectible : public Game::NPCEntity
{
public:
	Collectible();
	~Collectible();

	virtual void OnInteract() override;
	bool GetHidden() const { return hidden; }

	virtual void OnAddToWorld() override;

	void SetName(std::string name_);
	std::string GetName();

	bool hidden;
private:
	std::string name;

	
};

