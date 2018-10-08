#pragma once

#include "Character.h"
#include <iostream>

class Orc : public Character
{
public:
	Orc();
	~Orc();
	void fly() { std::cout << "The Orc is flying....." << std::endl; }
	void specialAbility();
	void walk();
};