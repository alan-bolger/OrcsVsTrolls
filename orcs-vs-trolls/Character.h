#pragma once

#include <iostream>

class Character
{
public:
	Character();
	~Character();
	void flip();
	virtual void walk();
	virtual void fly() = 0; // Pure virtual function
};