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

Orc::~Orc()
{
	// Destructor (not used)
}

void Orc::specialAbility()
{
	std::cout << "The Orc is rolling....." << std::endl;
}

void Orc::walk()
{
	std::cout << "The Orc is walking....." << std::endl;
}