#include "Orc.h"
#include <iostream>

Orc::Orc()
{
	// Default constructor
}

Orc::~Orc()
{
	// Destructor (not used)
}

void Orc::barrelRoll()
{
	std::cout << "rooooooolllllllllllinggggggg" << std::endl;
}

void Orc::walk()
{
	std::cout << "Doopers have a really cool walk!" << std::endl;
}

void Orc::fly()
{
	std::cout << "Dooper is flapping and flying" << std::endl;
}