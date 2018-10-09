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
			loop = false;
			break;

		case 'T': // Choose Trolls
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
	gamePlayInput();
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
		break;

	case Side::TROLLS:
		print("YOUR STATS (TROLL)");
		print("------------------");
		print("Attack:       " + std::to_string(troll.attributes.attack));
		print("Defense:      " + std::to_string(troll.attributes.defence));
		print("Intelligence: " + std::to_string(troll.attributes.intelligence));
		print("Charisma:     " + std::to_string(troll.attributes.charisma));
		print("Luck:         " + std::to_string(troll.attributes.luck));
		break;
	}
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
	print("To exit your inventory, enter the number 0");
	numInput = numberInput("To use an item, enter its pocket number (1 to 5)");

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
		print("You have equipped the knife and gained +5 attack points!");

		// Buff attack
		if (chosenSide == Side::ORCS)
		{
			orc.attributes.attack += 5;
		}
		else
		{
			troll.attributes.attack += 5;
		}
		
		lootTable[t_input - 1] = LootType::EMPTY;
	}
	else if (lootTable[t_input - 1] == LootType::SHIELD)
	{
		print(PrintType::LINE);
		print("You have equipped the shield and gained +5 defence points!");

		// Buff defence
		if (chosenSide == Side::ORCS)
		{
			orc.attributes.defence += 5;
		}
		else
		{
			troll.attributes.defence += 5;
		}

		lootTable[t_input - 1] = LootType::EMPTY;
	}
	else if (lootTable[t_input - 1] == LootType::SUDOKU_PUZZLE)
	{
		print(PrintType::LINE);
		print("You've completed the sudoku puzzle and gained +5");
		print("intelligence points!");

		// Buff intelligence
		if (chosenSide == Side::ORCS)
		{
			orc.attributes.intelligence += 5;
		}
		else
		{
			troll.attributes.intelligence += 5;
		}

		lootTable[t_input - 1] = LootType::EMPTY;
	}
	else if (lootTable[t_input - 1] == LootType::BOTTLE_OF_BEER)
	{
		print(PrintType::LINE);
		print("You have drank the beer and gained +5 charisma points!");

		// Buff charisma
		if (chosenSide == Side::ORCS)
		{
			orc.attributes.charisma += 5;
		}
		else
		{
			troll.attributes.charisma += 5;
		}

		lootTable[t_input - 1] = LootType::EMPTY;
	}
	else if (lootTable[t_input - 1] == LootType::RABBIT_FOOT)
	{
		print(PrintType::LINE);
		print("You've equipped the rabbit's foot and gained +15 luck points!");

		// Buff luck
		if (chosenSide == Side::ORCS)
		{
			orc.attributes.luck += 5;
		}
		else
		{
			troll.attributes.luck += 5;
		}

		lootTable[t_input - 1] = LootType::EMPTY;
	}
}

// Explore arena
void Game::exploreArena()
{
	if (chosenSide == Side::ORCS)
	{
		if (orc.attributes.attack <= 15)
		{
			print(PrintType::LINE);
			print("If you orc around any more, you'll have no attack points!");
		}
		else
		{
			orc.attributes.attack -= 15;
			exploreResult();
		}
	}
	else
	{
		if (troll.attributes.attack <= 15)
		{
			print(PrintType::LINE);
			print("If you troll any more, you'll have no attack points!");
		}
		else
		{
			troll.attributes.attack -= 15;
			exploreResult();
		}
	}
}

// Exploration result
void Game::exploreResult()
{
	int randomNum = std::rand() % 100 + 1;


}

// Main input
void Game::gamePlayInput()
{
	loop = true;

	while (loop)
	{
		print(PrintType::LINE);
		print("S - Show stats    | I - Inventory    | B - Begin battle");
		print("E - Explore arena | C - Clear window | X - Exit game");
		std::cin >> textInput;

		switch (textInput)
		{
		case 'S': // Show stats
		case 's':
			showStats(chosenSide);
			break;

		case 'I': // Show inventory (loot table)
		case 'i':
			showInventory();
			break;

		case 'B': // Begin battle
		case 'b':
			break;

		case 'E': // Explore arena
			exploreArena();
		case 'e':
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
