#pragma once

#include <iostream>

class Character
{
public:
	Character();
	virtual ~Character();
	void flip();
	virtual void walk();
	virtual void fly() = 0; // Pure virtual function

	struct stats
	{
		int attack;
		int defence;
		int intelligence;
		int charisma;
		int luck;
	} attributes;
};