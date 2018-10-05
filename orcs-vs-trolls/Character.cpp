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
	std::cout << "I know how to flip and I will flipping do it" << std::endl;
}

void Character::walk()
{
	std::cout << "just in case they are too young to walk yet" << std::endl;
}

