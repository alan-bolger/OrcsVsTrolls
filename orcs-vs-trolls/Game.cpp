// Gameplay Programming
// Practical
// Text Based Orcs vs Trolls Game
// Name: Alan Bolger
// Student No: C00232036

#include "Game.h"

using namespace std;

Game::Game()
{
	// Set random seed
	std::srand(time(NULL));

	for (int i = 0; i < MAX_LOOT; i++)
	{
		lootTable[i] = LootType::EMPTY;
	}

	// Test section
	lootTable[0] = LootType::RABBIT_FOOT;
	lootTable[1] = LootType::BOTTLE_OF_BEER;
	lootTable[2] = LootType::KNIFE;
	lootTable[3] = LootType::SUDOKU_PUZZLE;
	lootTable[4] = LootType::SHIELD;
}

Game::~Game()
{
	// Destructor (not used)
}

void Game::run()
{
	loop = true;
	introduction();
	chooseSide();
	beginBattle();
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

// Overloaded function to print loot inventory contents
void Game::print(LootType t_type)
{
	switch (t_type)
	{
	case LootType::EMPTY:
		print("This pocket is empty.");
		break;

	case LootType::KNIFE:
		print("A sharp knife with a wooden handle.");
		break;

	case LootType::SHIELD:
		print("A shield that's actually a dustbin lid.");
		break;

	case LootType::SUDOKU_PUZZLE:
		print("A sudoku puzzle. Orcs and Trolls love sudoku.");
		break;

	case LootType::BOTTLE_OF_BEER:
		print("A bottle of the finest Fairy beer.");
		break;

	case LootType::RABBIT_FOOT:
		print("A lucky rabbit's foot. Not very lucky for the rabbit.");
		break;
	}
}

// The start of the game
void Game::introduction()
{
	print(PrintType::LINE);
	print("ORCS VS TROLLS (BATTLE ARENA EDITION)");
	print(PrintType::LINE);
	print("Welcome to Orcs vs Trolls,  a turn-based game where Orcs battle");
	print("Trolls in an arena for the entertainment of all the monsters in");
	print("attendance.");
	print("You  start the game in  the arena, ready to  battle your rival.");
	print("You can search the  arena for loot that  may help you, but this");
	print("will use up precious attack points (each search costs 15 attack");
	print("points). The last beast standing is the winner!");
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
		case 'O': // Choose Orcs
		case 'o':
			print(PrintType::LINE);
			print("You have chosen to play as the Orcs.");
			print(PrintType::LINE);
			chosenSide = Side::ORCS;

			// Set pointers
			player = &orc;
			computer = &troll;

			loop = false;
			break;

		case 'T': // Choose Trolls
		case 't':
			print(PrintType::LINE);
			print("You have chosen to play as the Trolls.");
			print(PrintType::LINE);
			chosenSide = Side::TROLLS;

			// Set pointers
			player = &troll;
			computer = &orc;

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
	system("CLS");
}

// Start main game
void Game::beginBattle()
{
	gamePlayInput();
	system("Pause");
}

// Show inventory
void Game::showInventory()
{
	print(PrintType::LINE);
	print("INVENTORY (AKA: YOUR POCKETS)");
	print(PrintType::LINE);

	for (int i = 0; i < MAX_LOOT; i++)
	{
		std::cout << i + 1 << ": ";
		print(lootTable[i]);
	}

	print(PrintType::LINE);
	numInput = numberInput("To use an item, enter its pocket number (0 to exit)");

	if (numInput < 0 || numInput > 5)
	{
		print(PrintType::LINE);
		print("That is not a valid pocket number!");
	}
	else
	{
		useItem(numInput);
	}
}

// Check is item is valid and use
void Game::useItem(int t_input)
{
	if (lootTable[t_input - 1] == LootType::EMPTY)
	{
		print(PrintType::LINE);
		print("That pocket is empty!");
	}
	else if (lootTable[t_input - 1] == LootType::KNIFE)
	{
		print(PrintType::LINE);
		print("You have equipped the knife and gained +20 attack points!");

		player->attributes.attack += 20;		
		lootTable[t_input - 1] = LootType::EMPTY; // Empty pocket
	}
	else if (lootTable[t_input - 1] == LootType::SHIELD)
	{
		print(PrintType::LINE);
		print("You have equipped the shield and gained +5 defence points!");

		player->attributes.defence += 5;
		lootTable[t_input - 1] = LootType::EMPTY; // Empty pocket
	}
	else if (lootTable[t_input - 1] == LootType::SUDOKU_PUZZLE)
	{
		print(PrintType::LINE);
		print("You've completed the sudoku puzzle and gained +5");
		print("intelligence points!");

		player->attributes.intelligence += 5;
		lootTable[t_input - 1] = LootType::EMPTY; // Empty pocket
	}
	else if (lootTable[t_input - 1] == LootType::BOTTLE_OF_BEER)
	{
		print(PrintType::LINE);
		print("You have drank the beer and gained +5 charisma points!");

		player->attributes.charisma += 5;
		lootTable[t_input - 1] = LootType::EMPTY; // Empty pocket
	}
	else if (lootTable[t_input - 1] == LootType::RABBIT_FOOT)
	{
		print(PrintType::LINE);
		print("You've equipped the rabbit's foot and gained +15 luck points!");

		player->attributes.luck += 15;
		lootTable[t_input - 1] = LootType::EMPTY; // Empty pocket
	}
}

// Explore arena
void Game::exploreArena()
{
	if (player->attributes.attack <= 15)
	{
		print(PrintType::LINE);
		print("You don't have enough attack points to do that!");
	}
	else
	{
		print(PrintType::LINE);
		player->attributes.attack -= 15;
		exploreResult();
	}
}

// Exploration result
void Game::exploreResult()
{
	int randomNum = std::rand() % 50 + 1;

	if ((randomNum / 2) + player->attributes.luck > 30)
	{
		print("You've found something!");

		randomNum = std::rand() % 5;

		switch (randomNum)
		{
		case 0:
			print("It's a knife! A pointy knife! Yay!");
			print("Using a knife will boost your attack by 20 points!");
			pickUp(LootType::KNIFE);
			break;

		case 1:
			print("It's a shield that looks a bit like a dustbin lid");
			print("Using a shield will boost your defence by 5 points!");
			pickUp(LootType::SHIELD);
			break;

		case 2:
			print("It's a sudoku puzzle! WTF?!?");
			print("Doing a puzzle will boost your intelligence by 5 points!");
			pickUp(LootType::SUDOKU_PUZZLE);
			break;

		case 3:
			print("It's a bottle of Fairy beer! Lovely stuff.");
			print("Use this to boost charisma by 5 points!");
			pickUp(LootType::BOTTLE_OF_BEER);
			break;

		case 4:
			print("Gross, it's a rabbit's foot. These things are lucky.");
			print("Using a rabbit's foot will boost your luck by 15 points!");
			pickUp(LootType::RABBIT_FOOT);
			break;
		}
	}
	else
	{
		print("You've found nothing (and wasted 15 attack points).");
	}
}

// Pickup loot is there's room in your inventory
void Game::pickUp(LootType t_type)
{
	for (int i = 0; i < MAX_LOOT;)
	{
		if (lootTable[i] == LootType::EMPTY)
		{
			lootTable[i] = t_type;
			break;
		}
		else
		{
			i++;

			if (i > 4)
			{
				print("You can't pick that up as there's no more room in your pockets!");
				print("You can make room in your inventory by using items");
			}
		}
	}
}

// Main input
void Game::gamePlayInput()
{
	loop = true;

	while (loop)
	{
		print(PrintType::LINE);
		print("S - Show your stats  | I - Inventory     | B - Begin battle");
		print("O - Opponent's stats | E - Explore arena | C - Clear window");
		print("X - Exit game");
		std::cin >> textInput;

		switch (textInput)
		{
		case 'S': // Show stats
		case 's':
			print(PrintType::LINE);
			print("YOUR STATS:");
			player->displayStats();
			break;

		case 'I': // Show inventory (loot table)
		case 'i':
			showInventory();
			break;

		case 'B': // Begin battle
		case 'b':
			break;

		case 'O': // Show opponents stats
		case 'o':
			print(PrintType::LINE);
			print("OPPONENT'S STATS:");
			computer->displayStats();
			break;

		case 'E': // Explore arena
		case 'e':
			exploreArena();
			break;

		case 'C': // Clear window
		case 'c':
			system("CLS");
			break;

		case 'X': // Exit game
		case 'x':
			exit(0);
			break;

		default: // Error
			print(PrintType::LINE);
			print("That is not a valid command! Try again!");
			break;
		}
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
