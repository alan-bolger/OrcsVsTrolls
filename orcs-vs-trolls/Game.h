#pragma once

#include "Orc.h"
#include "Troll.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	// Enums used for printing to screen
	enum class PrintType
	{
		SPACE,
		LINE
	};

	// Enums for side selection
	enum class Side
	{
		ORCS,
		TROLLS
	};

	char textInput;
	bool loop;
	Side chosenSide;

	void createCharacters();
	void print(PrintType t_type);
	void print(std::string t_string);
	void introduction();
	void chooseSide();

	int numberInput(std::string t_input);
};