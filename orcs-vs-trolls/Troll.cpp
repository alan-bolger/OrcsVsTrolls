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

void Troll::rest()
{
	std::cout << "The Troll has rested and gained +5 defence points." << std::endl;

	attributes.defence += 5;
}

void Troll::crotchKick(Character *t_object)
{
	std::cout << "A swift kick to the nads, and the Orc is injured!" << std::endl;
	std::cout << "The kick was so hard, the Orc has lost some intelligence!" << std::endl;

	t_object->attributes.intelligence -= 10;
}

void Troll::uppercut(Character *t_object)
{
	std::cout << "An amazing uppercut has wounded the Orc!" << std::endl;
	std::cout << "The Orc has lost some defence points!" << std::endl;

	t_object->attributes.defence -= 10;
}

void Troll::eyeGouge(Character *t_object)
{
	std::cout << "The Troll gouges the Orc's eyes!" << std::endl;
	std::cout << "The Orc has lost charisma and defence points!" << std::endl;

	t_object->attributes.charisma -= 5;
	t_object->attributes.defence -= 5;
}

void Troll::punch(Character *t_object)
{
	std::cout << "The Orc punches the Troll square in the face." << std::endl;
	std::cout << "The Troll has lost some attack points!" << std::endl;

	t_object->attributes.attack -= 15;
}

void Troll::specialAbility(Character *t_object)
{
	std::cout << "The Troll has summoned his inner monster....." << std::endl;
	std::cout << "PUNCH! KICK! SCREAM! ETC!" << std::endl;
	std::cout << "The Orc has lost charisma and luck points!" << std::endl;

	t_object->attributes.charisma -= 7;
	t_object->attributes.luck -= 8;
}