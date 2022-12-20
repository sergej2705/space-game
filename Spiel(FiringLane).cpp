#include "Artillery.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Test_01.h"

#include <array>
#include <iostream>
#include <thread>


using namespace std;

Artillery Artillery_1(1, 0, 3);
Enemy Enemy_3[5] = {};			
Bullet Bullet_3[5];			



void Tick() {

	

	for (int i = 0; i < 5; i++)
	{
		
		Artillery_1.shoot();
		Bullet_3[i].move();

		


		if (Bullet_3[i].getPosition() == Enemy_3[i].getPosition())
		{
			Enemy_3[i].hit();
			Bullet_3[i].hit();
		}

		if (Artillery_1.getPosition() == Enemy_3[i].getPosition())
		{
			Artillery_1.hit();
			Enemy_3[i].hit();

		}

		Enemy_3[i].move();
	}
	

}


//----------------------------------------------------------------------------
//SpielFeld:

int länge = 30;

string print() {
	

	char* lane = new char[länge];
	for (size_t y = 0; y < länge; y++) {
		lane[y] = ' ';
	}
	
	lane[Artillery_1.getPosition()] = 'G';
	

	for (int i = 0; i < 5; i++)
	{
		lane[Enemy_3[i].getPosition()] = 'X';
		lane[Bullet_3[i].getPosition()] = '-';


		if (Bullet_3[i].getPosition() == Enemy_3[i].getPosition())
		{
			lane[Bullet_3[i].getPosition()] = ' ';
			lane[Enemy_3[i].getPosition()] = ' ';
		}


		if (Bullet_3[i].getPosition() == Enemy_3[i].getPosition())
		{
			lane[Bullet_3[i].getPosition()] = ' ';
			lane[Enemy_3[i].getPosition()] = ' ';
		}


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

	Enemy_3[1] = Enemy(1, 15, 1);
	Enemy_3[2] = Enemy(1, 20, 1);
	//Enemy_3[3] = Enemy(3, 15, 1);
	//Enemy_3[4] = Enemy(4, 15, 1);


	Bullet_3[1] = Bullet(1, 10, 1, 1);
	Bullet_3[2] = Bullet(1, 5, 1, 1);



	while (e<30)
	{	
		Tick();
		print();
		e++;
	}



}