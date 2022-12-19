#include "Artillery_01.h"
#include "Enemy_01.h"
#include "Bullet_01.h"

#include <array>
#include <iostream>
#include <thread>


using namespace std;

Artillery Artillery_1(1, 0, 3); //Nummer,Position,Leben
Bullet Bullet_1(1, 1, 1, 1);  //Nummer,Position,Leben,Schaden
Enemy Enemy_1(1, 10, 1);	//Nummer,Position,Leben

//----------------------------------------------------------------------------

void Tick() {
	
	Artillery_1.shoot();
	Bullet_1.move();


	if (Bullet_1.getPosition() == Enemy_1.getPosition())
	{
		Enemy_1.hit();
		Bullet_1.hit();
	}

	if (Artillery_1.getPosition() == Enemy_1.getPosition())
	{
		Artillery_1.hit();
		Enemy_1.hit();
		
	}

	Enemy_1.move();


}




//----------------------------------------------------------------------------
//SpielFeld:

int länge = 20;

string print() {
	

	char* lane = new char[länge];
	for (size_t y = 0; y < länge; y++) {
		lane[y] = ' ';
	}
	
	lane[Artillery_1.getPosition()] = 'G';
	
	lane[Bullet_1.getPosition()] = '-';
	lane[Enemy_1.getPosition()] = 'X';
	

	if (Bullet_1.getPosition() == Enemy_1.getPosition())
	{
		lane[Bullet_1.getPosition()] = ' ';
		lane[Enemy_1.getPosition()] = ' ';
	}

	cout << lane;

	std::this_thread::sleep_for(std::chrono::milliseconds(550));
	system("cls");

	return string();

}

//---------------------------------------------------------------------------
//Main:


int main() 
{
	int e = 0;

	while (e<20)
	{		
		Tick();
		print();
		e++;
	}



}
