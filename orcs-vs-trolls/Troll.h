#pragma once

#include "Character.h"
#include <iostream>

class Troll : public Character
{
public:
	Troll();
	void displayStats();
	void rest();
	void crotchKick(Character *t_object);
	void uppercut(Character *t_object);
	void eyeGouge(Character *t_object);
	void punch(Character *t_object);
	void specialAbility(Character *t_object);
};