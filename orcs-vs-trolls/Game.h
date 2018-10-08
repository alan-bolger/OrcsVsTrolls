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

	// Loot types
	enum class LootType
	{
		KNIFE,
		SHIELD,
		SUDOKU_PUZZLE,
		BOTTLE_OF_BEER,
		RABBIT_FOOT
	};

	LootType lootTable[5];

	char textInput; // Input char
	bool loop;// Used to break out of loops
	Side chosenSide; // Enum type to store chosen side					 
	Orc orc; // Create Orc	
	Troll troll; // Create Troll

	void createCharacters(); // Setup the characters
	void print(PrintType t_type); // Function to print a line space or decoration line
	void print(std::string t_string); // Overloaded function to print text
	void introduction(); // Game intro
	void chooseSide(); // Choose Orcs or Trolls
	void beginBattle(); // Start main game
	void showStats(Side t_side); // Display player stats
	int numberInput(std::string t_input); // Number input with validation
};