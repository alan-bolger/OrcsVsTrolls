#include "Orc.h"

Orc::Orc()
{
	// All stats are out of 100
	attributes.attack = 90;
	attributes.defence = 60;
	attributes.intelligence = 70;
	attributes.charisma = 40;
	attributes.luck = 20;
}

void Orc::specialAbility()
{
	std::cout << "The Orc is unleashing the beast....." << std::endl;
}

void Orc::attack()
{
	std::cout << "The Orc is attacking....." << std::endl;
}

void Orc::displayStats()
{
	std::cout << "------------------." << std::endl;
	std::cout << "ORC               |" << std::endl;
	std::cout << "------------------|" << std::endl;
	std::cout << "Attack:       " << attributes.attack << "  |" << std::endl;
	std::cout << "Defense:      " << attributes.defence << "  |" << std::endl;
	std::cout << "Intelligence: " << attributes.intelligence << "  |" << std::endl;
	std::cout << "Charisma:     " << attributes.charisma << "  |" << std::endl;
	std::cout << "Luck:         " << attributes.luck << "  |" << std::endl;
}