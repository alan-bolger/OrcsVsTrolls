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

void Character::flip()
{
	std::cout << "The character is flipping....." << std::endl;
}

void Character::walk()
{
	std::cout << "The character is walking....." << std::endl;
}

