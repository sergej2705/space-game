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

		cout << "Choose a difficulty: 1 (easy) to 3 (hard)" << endl;
		cin >> difficultyInput;
		difficulty = difficultyInput - 48;
	} while (difficulty < 1 || difficulty > 3);

	SpaceGame game(difficulty);

	game.start();

	system("clear");
}