#include "Troll.h"

Troll::Troll()
{
	// All stats are out of 100
	attributes.attack = 60;
	attributes.defence = 90;
	attributes.intelligence = 40;
	attributes.charisma = 70;
	attributes.luck = 20;
}

void Troll::specialAbility()
{
	std::cout << "The Troll is summoning his inner monster....." << std::endl;
}

void Troll::attack()
{
	std::cout << "The Troll is attacking....." << std::endl;
}

void Troll::displayStats()
{
	std::cout << "------------------." << std::endl;
	std::cout << "TROLL             |" << std::endl;
	std::cout << "------------------|" << std::endl;
	std::cout << "Attack:       " << attributes.attack << "  |" << std::endl;
	std::cout << "Defense:      " << attributes.defence << "  |" << std::endl;
	std::cout << "Intelligence: " << attributes.intelligence << "  |" << std::endl;
	std::cout << "Charisma:     " << attributes.charisma << "  |" << std::endl;
	std::cout << "Luck:         " << attributes.luck << "  |" << std::endl;
}