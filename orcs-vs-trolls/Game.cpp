// Gameplay Programming
// Practical
// Text Based Orcs vs Trolls Game
// Name: Alan Bolger
// Student No: C00232036

#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

Game::Game()
{
	// Default constructor
}

Game::~Game()
{
	// Destructor (not used)
}

void Game::run()
{
	loop = true;
	createCharacters();
	introduction();
	chooseSide();
	beginBattle();
}
					 
void Game::createCharacters()
{
	//cout << "Let go virtual" << endl;
	//Character character;
	//character.flip();
	//character.walk();

	//Orc orc;
	//orc.walk();
	//orc.fly();
	//orc.flip();
	//print(PrintType::LINE);

	//cout << "Let go create an Troll" << endl;
	//Troll troll;
	//troll.walk();
	//troll.fly();
	//troll.flip();
	//print(PrintType::LINE);

	//Character* npc = &orc;
	//npc->flip();
	//npc->fly();
	//npc->walk();
	//print(PrintType::LINE);

	//npc = &troll;
	//npc->flip();
	//npc->fly();
	//npc->walk();
	//print(PrintType::LINE);
}

// Overloaded function to insert a line or a break
void Game::print(PrintType t_type)
{
	switch (t_type)
	{
	case PrintType::SPACE:
		std::cout << std::endl;
		break;

	case PrintType::LINE:
		std::cout << "---------------------------------------------------------------" << std::endl;
		break;
	}
}

// Overloaded function to print text
void Game::print(std::string t_string)
{
	std::cout << t_string << std::endl;
}

// The start of the game
void Game::introduction()
{
	print(PrintType::LINE);
	print("ORCS VS TROLLS");
	print(PrintType::LINE);
	print("Welcome to Orcs vs Trolls,  a turn-based game where Orcs battle");
	print("Trolls over  something that  happened so  long ago, they  can't");
	print("actually remember  what it was. Take control of either the Orcs");
	print("or the Trolls, and destroy the  opposition by  pressing various");
	print("keys on your 'enchanted' keyboard.....");
	print(PrintType::LINE);
	print("All controls needed are displayed throughout the game.");
	print("Now go forth, and press some keys!!!!!");
	print(PrintType::LINE);
}

// Choose your side
void Game::chooseSide()
{
	print("It's time to choose your side ('O' for Orcs or 'T' for trolls):");
	std::cin >> textInput;

	while (loop)
	{
		switch (textInput)
		{
		case 'O':
		case 'o':
			print(PrintType::LINE);
			print("You have chosen to play as the Orcs.");
			print(PrintType::LINE);
			chosenSide = Side::ORCS;
			loop = false;
			break;

		case 'T':
		case 't':
			print(PrintType::LINE);
			print("You have chosen to play as the Trolls.");
			print(PrintType::LINE);
			chosenSide = Side::TROLLS;
			loop = false;
			break;

		default:
			print(PrintType::LINE);
			print("Stop messing about!");
			print("Choose your side now! ('O' for Orcs or 'T' for trolls):");
			std::cin >> textInput;
			break;
		}
	}

	print(PrintType::SPACE);
	system("Pause");
	system("CLS");
}

// Start main game
void Game::beginBattle()
{
	showStats(chosenSide);
	system("Pause");
}

// Display player stats
void Game::showStats(Side t_side)
{
	print(PrintType::LINE);

	switch (t_side)
	{
	case Side::ORCS:
		print("YOUR STATS (ORC)");
		print("----------------");
		print("Attack:       " + std::to_string(orc.attributes.attack));
		print("Defense:      " + std::to_string(orc.attributes.defence));
		print("Intelligence: " + std::to_string(orc.attributes.intelligence));
		print("Charisma:     " + std::to_string(orc.attributes.charisma));
		print("Luck:         " + std::to_string(orc.attributes.luck));
		print(PrintType::LINE);
		break;

	case Side::TROLLS:
		print("YOUR STATS (TROLL)");
		print("------------------");
		print("Attack:       " + std::to_string(troll.attributes.attack));
		print("Defense:      " + std::to_string(troll.attributes.defence));
		print("Intelligence: " + std::to_string(troll.attributes.intelligence));
		print("Charisma:     " + std::to_string(troll.attributes.charisma));
		print("Luck:         " + std::to_string(troll.attributes.luck));
		print(PrintType::LINE);
		break;
	}
}

// Take user input for numbers
 int Game::numberInput(std::string t_input)
{
	int n;
	print(t_input);
	std::cin >> n;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		print(PrintType::LINE);
		print(t_input);
		std::cin >> n;
	}

	return n;
 }
