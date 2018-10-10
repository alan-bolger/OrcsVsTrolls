#include "Troll.h"

Troll::Troll()
{
	attributes.attack = 60;
	attributes.defence = 90;
	attributes.intelligence = 40;
	attributes.charisma = 70;
	attributes.luck = 20;
}

void Troll::displayStats()
{
	std::cout << "------------------" << std::endl;
	std::cout << "TROLL             " << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "Attack:       " << attributes.attack << std::endl;
	std::cout << "Defense:      " << attributes.defence << std::endl;
	std::cout << "Intelligence: " << attributes.intelligence << std::endl;
	std::cout << "Charisma:     " << attributes.charisma << std::endl;
	std::cout << "Luck:         " << attributes.luck <<  std::endl;
}

void Troll::rest()
{
	std::cout << "The Troll has rested and gained +15 defence points." << std::endl;

	attributes.defence += 15;
}

void Troll::crotchKick(Character *t_object)
{
	std::cout << "A swift kick to the nads, and the Orc is injured!" << std::endl;
	std::cout << "The Orc has lost 25 intelligence and 20 defence points!" << std::endl;

	t_object->attributes.intelligence -= 25;
	t_object->attributes.defence -= 20;

	// Get rid of negative values, set to 0
	if (t_object->attributes.intelligence < 0)
	{
		t_object->attributes.intelligence = 0;
	}

	if (t_object->attributes.defence < 0)
	{
		t_object->attributes.defence = 0;
	}
}

void Troll::uppercut(Character *t_object)
{
	std::cout << "An amazing uppercut has wounded the Orc!" << std::endl;
	std::cout << "The Orc has lost 30 defence, 20 charisma and" << std::endl;
	std::cout << "15 attack points!" << std::endl;

	t_object->attributes.defence -= 30;
	t_object->attributes.charisma -= 20;
	t_object->attributes.attack -= 15;

	// Get rid of negative values, set to 0
	if (t_object->attributes.defence < 0)
	{
		t_object->attributes.defence = 0;
	}

	if (t_object->attributes.charisma < 0)
	{
		t_object->attributes.charisma = 0;
	}

	if (t_object->attributes.attack < 0)
	{
		t_object->attributes.attack = 0;
	}
}

void Troll::eyeGouge(Character *t_object)
{
	std::cout << "The Troll gouges the Orc's eyes!" << std::endl;
	std::cout << "The Orc has lost 20 charisma and 30 defence points!" << std::endl;

	t_object->attributes.charisma -= 20;
	t_object->attributes.defence -= 30;

	// Get rid of negative values, set to 0
	if (t_object->attributes.charisma < 0)
	{
		t_object->attributes.charisma = 0;
	}

	if (t_object->attributes.defence < 0)
	{
		t_object->attributes.defence = 0;
	}
}

void Troll::punch(Character *t_object)
{
	std::cout << "The Orc punches the Troll square in the face." << std::endl;
	std::cout << "The Troll has lost 35 attack and 10 defence points!" << std::endl;

	t_object->attributes.attack -= 35;
	t_object->attributes.defence -= 10;

	// Get rid of negative values, set to 0
	if (t_object->attributes.attack < 0)
	{
		t_object->attributes.attack = 0;
	}

	if (t_object->attributes.defence < 0)
	{
		t_object->attributes.defence = 0;
	}
}

void Troll::specialAbility(Character *t_object)
{
	int magicNumber = std::rand() % 6;

	if (magicNumber >= 4)
	{
		std::cout << "The Troll has summoned his inner monster....." << std::endl;
		std::cout << "PUNCH! KICK! SCREAM! ETC!" << std::endl;
		std::cout << "The Orc has lost 20 attack, 30 defence, 15 intelligence," << std::endl;
		std::cout << "30 charisma and 10 luck points!" << std::endl;

		t_object->attributes.attack -= 20;
		t_object->attributes.defence -= 30;
		t_object->attributes.intelligence -= 15;
		t_object->attributes.charisma -= 30;
		t_object->attributes.luck -= 10;

		// Get rid of negative values, set to 0
		if (t_object->attributes.attack < 0)
		{
			t_object->attributes.attack = 0;
		}

		if (t_object->attributes.defence < 0)
		{
			t_object->attributes.defence = 0;
		}

		if (t_object->attributes.intelligence < 0)
		{
			t_object->attributes.intelligence = 0;
		}

		if (t_object->attributes.charisma < 0)
		{
			t_object->attributes.charisma = 0;
		}

		if (t_object->attributes.luck < 0)
		{
			t_object->attributes.luck = 0;
		}
	}
	else
	{
		std::cout << "The Troll has summoned his inner monster....." << std::endl;
		std::cout << ".....but failed miserably. No damage was done." << std::endl;
	}
}