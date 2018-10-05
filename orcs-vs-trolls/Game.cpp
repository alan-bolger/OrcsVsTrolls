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
}
					 
void Game::createCharacters()
{
	cout << "Let go virtual" << endl;
	//Character character;
	//character.flip();
	//character.walk();

	cout << "Let go create an Orc" << endl;
	Orc orc;
	orc.walk();
	orc.fly();
	orc.flip();

	cout << "Let go create an Troll" << endl;
	Troll troll;
	troll.walk();
	troll.fly();
	troll.flip();

	Character* npc = &orc;
	npc->flip();
	npc->fly();
	npc->walk();

	npc = &troll;
	npc->flip();
	npc->fly();
	npc->walk();

	// cin.get();
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
	print("Trolls over the ownership of an island called Travania. You can");
	print("choose to fight as either the Orcs or Trolls,  and you must use");
	print("your skills to try and defeat your opponents, and take over the");
	print("island of Travania.");
	print(PrintType::LINE);
	print("Orcs vs Trolls is a turn-based game.");
	print("Blah, blah, blah.....");
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
			chosenSide = Side::ORCS;
			loop = false;
			break;

		case 'T':
		case 't':
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

	system("Pause");
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
