#pragma once

#include "Character.h"
#include <iostream>

class Orc : public Character
{
public:
	Orc();
	~Orc();
	void barrelRoll();
	void walk();
	void fly();
};