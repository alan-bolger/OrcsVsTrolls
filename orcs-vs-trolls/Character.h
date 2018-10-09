#pragma once

#include <iostream>
#include <string>

class Character
{
public:
	Character();
	virtual ~Character();
	void flip();
	virtual void walk();
	// virtual void attack() = 0;
	virtual void displayStats() = 0;

	struct stats
	{
		int attack;
		int defence;
		int intelligence;
		int charisma;
		int luck;
	} attributes;
};