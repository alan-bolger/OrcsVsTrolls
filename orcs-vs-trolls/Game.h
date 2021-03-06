#pragma once

#include "Orc.h"
#include "Troll.h"
#include <iostream>
#include <string>
#include <time.h>

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
		EMPTY,
		KNIFE,
		SHIELD,
		SUDOKU_PUZZLE,
		BOTTLE_OF_BEER,
		RABBIT_FOOT
	};

	static const int MAX_LOOT = 5;
	LootType lootTable[MAX_LOOT];

	char textInput; // Input char
	int numInput; // Input integer
	bool loop;// Used to keep while loops looping
	bool humanTurn; // False if it's the computer's turn

	Side chosenSide; // Enum type to store chosen side					 
	Orc orc; // Create Orc	
	Troll troll; // Create Troll
	Character *player; // Pointer to address of chosen character
	Character *computer; // Pointer to address of computer character

	void print(PrintType t_type); // Function to print a line space or decoration line
	void print(std::string t_string); // Overloaded function to print text
	void print(LootType t_type); // Overloaded function to print inventory contents
	void introduction(); // Game intro
	void chooseSide(); // Choose Orcs or Trolls
	void showInventory(); // Show inventory (loot table)						  
	void useItem(int t_input); // Check is item is valid and use							   
	void exploreArena(); // Explore arena						 
	void exploreResult(); // Exploration result
	void pickUp(LootType t_type); // Pickup loot is there's room in your inventory
	void gamePlayInput(); // Main input
	void battleArena(); // The battle
	void fightInput(); // Fight input
	int numberInput(std::string t_input); // Number input with validation
};