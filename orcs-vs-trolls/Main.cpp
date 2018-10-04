// Gameplay Programming
// Practical
// Text Based Orcs vs Trolls Game
// Name: Alan Bolger
// Student No: C00232036

#include <iostream>
#include <string>

using namespace std;

void introduction(); // Forward declaration

					 // Enums used for printing to screen
enum class PrintType
{
	SPACE,
	LINE
};

class Character
{
public:
	void flip()
	{
		cout << "I know how to flip and I will flipping do it" << endl;
	}

	virtual void walk()
	{
		cout << "just in case they are too young to walk yet" << endl;
	}

	virtual void fly() = 0; // Pure virtual function
};

class Orc : public Character
{
public:
	void barrelRoll()
	{
		cout << "rooooooolllllllllllinggggggg" << endl;
	}

	void walk()
	{
		cout << "Doopers have a really cool walk!" << endl;
	}

	void fly()
	{
		cout << "Dooper is flapping and flying" << endl;
	}
};

class Troll : public Character
{
public:
	void fly()
	{
		cout << "Average Dooper is flapping and flying" << endl;
	}
};

int main(void)
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

	introduction(); // Run introduction
}

// Overloaded function to insert a line or a break
void print(PrintType t_type)
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
void print(std::string t_string)
{
	std::cout << t_string << std::endl;
}

// The start of the game
void introduction()
{
	print(PrintType::LINE);
	print("ORCS VS TROLLS");
	print(PrintType::LINE);
	print("Welcome to Orcs vs Trolls, a game based on the real-life events");
	print("of 1916, where the Orcs fought back against the Trolls and took");
	print("back their country.");
	print(PrintType::LINE);
	print(PrintType::SPACE);
	system("Pause");
}