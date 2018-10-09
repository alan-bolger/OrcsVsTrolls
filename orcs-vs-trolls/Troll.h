#pragma once

#include "Character.h"
#include <iostream>

class Troll : public Character
{
public:
	Troll();
	void fly() { std::cout << "The Troll is flying....." << std::endl; }
	void specialAbility();
	void attack();
	void displayStats();
};