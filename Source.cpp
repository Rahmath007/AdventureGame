#include "Header.h"
using namespace std;

int main()
{
	// Prints a welcome message for the game
	cout << " Hello, Welcome to Adventure Game where your Task is to fight with monster and gain as much gold as possile \n with the gold you can bribe the moster if you are on low health. ENJOY THE GAME AND GOOD LUCK \n";

	// Prints the name of the game
	cout << "[Adventure Game]" << endl;

	// Asks user to press enter to start the game
	cout << "Press Enter to start...";
	// Wait for user to press Enter

	cin.get();
	cout << "Starting game..." << endl;
	// Prints a loading animation for the game

	std::cout << "[";
	for (int i = 0; i <= 100; i++)
	{
		std::cout << "=";
		std::cout.flush();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	std::cout << "] " << 100 << "%\r" << endl
		<< std::flush;
	// Clears the console screen
	system("cls");
	cout << "[Adventure Game]" << endl;
	// Initializes random seed
	srand(time(0));

	// Map variables
	const int MAP_WIDTH = 10;
	const int MAP_HEIGHT = 5;
	shared_ptr<Map> gameMap = make_shared<Map>(MAP_WIDTH, MAP_HEIGHT);

	// Player variables
	shared_ptr<Player> player =
		make_shared<Player>(MAP_WIDTH / 2, MAP_HEIGHT / 2);

	// Monster variables
	shared_ptr<Monster> monster =
		make_shared<Monster>(rand() % MAP_WIDTH, rand() % MAP_HEIGHT);

	// Game loop
	while (player->health > 0)
	{
		gameMap->Draw(player, monster);

		// Show player stats
		cout << "Health: " << player->health << endl;
		cout << "Attack: " << player->attack << endl;
		cout << "Defense: " << player->defense << endl;
		cout << "Gold: " << player->gold << endl;
		cout << "Experience: " << player->experience << endl;


		// Get player action
		cout << "What do you want to do?" << endl;
		cout << "[m] Move" << endl;
		cout << "[b] Attack" << endl;
		cout << "[q] Quit" << endl;
		char input;
		cin >> input;
		switch (input)
		{
		case 'm':
		{
			// Move player
			cout << "Move in which direction?" << endl;
			cout << "[w] Up" << endl;
			cout << "[a] Left" << endl;
			cout << "[s] Down" << endl;
			cout << "[d] Right" << endl;
			char direction;
			cin >> direction;

			switch (direction)
			{
			case 'w':
				player->y--;
				break;
			case 'a':
				player->x--;
				break;
			case 's':
				player->y++;
				break;
			case 'd':
				player->x++;
				break;
			}
			break;
		}
		case 'b':
		{
			// Attack monster
			monster->health -= player->attack;

			if (monster->health <= 0)
			{
				cout << "You killed the monster!" << endl;
				player->gold += 50;
				player->experience += 100;
				monster = make_shared<Monster>(rand() % MAP_WIDTH, rand() % MAP_HEIGHT);
			}
			else
			{
				// Monster counter attack
				player->health -= monster->attack;

				cout << "The monster counter attacked and dealt " << monster->attack
					<< " damage." << endl;
			}
			break;
		}
		case 'q':
			// Quit game
			return 0;
		}
	}

	cout << "You died." << endl;
	return 0;
}





}