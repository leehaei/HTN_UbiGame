#include "SuspectEntity.h"
#include <ctime>

using namespace Game;

std::vector<std::string> dialogueOptions = {
	std::string("Hello! I am the Suspect."),
	std::string("I wouldn't know anything. \n You should ask someone else."),
	std::string("The Plague Doctor has been up to suspicious activity recently.\n You should talk to him."),
	std::string("The Plague Doctor would have done it!\n Leave me alone."),
	std::string("I cannot say!\n You would have to arrest me!"),
	std::string("You have no grounds to force me!"),
	std::string("I am innocent!"),
	std::string("I would have gotten away with it!")
};

SuspectEntity::SuspectEntity() : randomInteractChecked(false), threatenableItem(std::string(""))
{
	dialogues = dialogueOptions;
}


SuspectEntity::~SuspectEntity()
{
}

std::string SuspectEntity::getThreatenableItem()
{
	return threatenableItem;
}

bool SuspectEntity::randomInteractCheck()
{
	std::srand(time(NULL));
	return std::rand()%4 == 0;
}

bool SuspectEntity::isPlayerDead()
{
	return isPlayerKilled;
}