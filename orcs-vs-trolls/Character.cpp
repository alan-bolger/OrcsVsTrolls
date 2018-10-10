#include "Character.h"
#include <iostream>

Character::Character()
{
	// Default constructor
}

Character::~Character()
{
	// Destructor (not used)
}

bool Character::checkIfDead()
{
	if (attributes.attack <= 0 && attributes.defence <= 0 &&
		attributes.intelligence <= 0 && attributes.charisma <= 0 &&
		attributes.luck <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
