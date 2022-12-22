#include "SpaceGame.h"

using namespace std;

char difficultyInput;
int difficulty;

int length = 50;
int tickLength = 300;

int main()
{
	do
	{
		system("clear");

		cout << "Choose a difficulty: 1 (easy) to 4 (extreme)" << endl;
		cin >> difficultyInput;
		difficulty = difficultyInput - 48;
	} while (difficulty < 1 || difficulty > 4);

	system("clear");

	SpaceGame game(difficulty);

	game.start();

	system("clear");
}