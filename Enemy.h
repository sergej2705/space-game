#pragma once
#include "Bullet.h"

using namespace std;

class Enemy {
public:
	Enemy(int number, int startPosition, int health);
	~Enemy();

	Enemy();		//Test

	int getPosition();
	int move();
	int hit();


private:
	int m_position;
	int m_number;
	int m_health;


};

//----------------------------------------------------------------------------------------
//cpp


Enemy::Enemy(int number, int startposition, int health)
{
	m_position = startposition;
	m_health = health;
	m_number = number;

}

Enemy::Enemy()
{
	m_position = 30;
	m_health = 1;
}


Enemy::~Enemy()
{
}

int Enemy::getPosition()
{
	return m_position;
}

int Enemy::move()
{
	if (m_health > 0) {
		return m_position--;
	}
}

int Enemy::hit()
{
	cout << "Aua_Enemy" << endl;
	return m_health--;
	if (m_health >= 0) {
		Enemy::~Enemy();
	}


}