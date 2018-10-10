#pragma once

#include <iostream>
#include <string>

class Character
{
public:
	Character();
	virtual ~Character();
	virtual void rest() = 0;
	virtual void crotchKick(Character *t_object) = 0;
	virtual void uppercut(Character *t_object) = 0;
	virtual void eyeGouge(Character *t_object) = 0;
	virtual void punch(Character *t_object) = 0;
	virtual void specialAbility(Character *t_object) = 0;
	virtual void displayStats() = 0;
	bool checkIfDead();

	struct
	{
		int attack;
		int defence;
		int intelligence;
		int charisma;
		int luck;
	} attributes;
};