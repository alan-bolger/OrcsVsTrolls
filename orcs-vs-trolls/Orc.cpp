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

void Orc::rest()
{
	std::cout << "The Orc has rested and gained +5 defence points." << std::endl;

	attributes.defence += 5;
}

void Orc::crotchKick(Character *t_object)
{
	std::cout << "A swift kick to the nads, and the Troll is injured!" << std::endl;
	std::cout << "The kick was so hard, the Troll has lost some intelligence!" << std::endl;

	t_object->attributes.intelligence -= 10;
}

void Orc::uppercut(Character *t_object)
{
	std::cout << "An amazing uppercut has wounded the Troll!" << std::endl;
	std::cout << "The Troll has lost some defence points!" << std::endl;

	t_object->attributes.defence -= 10;
}

void Orc::eyeGouge(Character *t_object)
{
	std::cout << "The Orc gouges the Troll's eyes!" << std::endl;
	std::cout << "The Troll has lost charisma and defence points!" << std::endl;

	t_object->attributes.charisma -= 5;
	t_object->attributes.defence -= 5;
}

void Orc::punch(Character *t_object)
{
	std::cout << "The Orc punches the Troll square in the face." << std::endl;
	std::cout << "The Troll has lost some attack points!" << std::endl;

	t_object->attributes.attack -= 15;
}

void Orc::specialAbility(Character *t_object)
{
	std::cout << "The Orc has unleashed the beast....." << std::endl;
	std::cout << "PUNCH! KICK! SCREAM! ETC!" << std::endl;
	std::cout << "The Troll has lost charisma and luck points!" << std::endl;

	t_object->attributes.charisma -= 7;
	t_object->attributes.luck -= 8;
}