#include <iostream>
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
}