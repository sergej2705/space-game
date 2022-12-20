#pragma once
#include <iostream>
#include <string>
#include "Bullet.h"

using namespace std;

class Artillery {
public:
	Artillery(int number, int position, int health);
	~Artillery();
	void shoot();
	void hit();
	int getPosition();



private:
	int m_energylevel;
	int m_number;
	int m_position;
	int m_health;
};


//----------------------------------------------------------------------------------------
//cpp





Artillery::Artillery(int number, int position, int health) {
	m_energylevel = 3;
	m_number = number;
	m_position = position;
	m_health = health;

}
Artillery::~Artillery() 
{
	
}


void Artillery::shoot() {
	if (m_health > 0) {
		int i = 0;
		while (m_energylevel > 0) {
			//Bullet::Bullet(5, 1, 1, 1);
			m_energylevel = m_energylevel - 1;
			i++;
		}
	}

}
void Artillery::hit() {
	m_health--;
	cout << "Aua_Artillery" << endl;

}

int Artillery::getPosition() {
	return m_position;
}


