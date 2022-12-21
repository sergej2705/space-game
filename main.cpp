#include "Firinglane.h"

using namespace std;

int length = 50;

int life = 3;
int *health = &life;

int main()
{
	Firinglane lane(length, health);

	while (*health > 0)
	{
		lane.tick();

		system("clear");
		cout << lane.print() << endl;
		cout << *health << " lifes left" << endl;
		this_thread::sleep_for(chrono::milliseconds(300));
	}

	cout << "You lose!" << endl;
}