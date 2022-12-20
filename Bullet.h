#pragma once
using namespace std;

class Bullet {
public:
	Bullet(int number, int position, int health, int damage);
	~Bullet();

	Bullet();		//Test

	void move();
	int getPosition();
	int getDamage();
	void hit();




private:
	int m_damage;
	int m_number;
	int m_position;
	int m_health;



};

//----------------------------------------------------------------------------------------
//cpp

Bullet::Bullet(int number, int position, int health, int damage)
{
	m_damage = damage;
	m_number = number;
	m_position = position;
	m_health = health;

}

Bullet::Bullet()
{
	m_position = 1;
	m_health = 1;
}

Bullet::~Bullet()
{

}

void Bullet::hit() {
	m_health--;
	if (m_health >= 0) {
		Bullet::~Bullet();
	}
	cout << "Aua_Bullet" << endl;

}

void Bullet::move()
{
	if (m_health > 0) {
		m_position = m_position + 1;
	}
	
}

int Bullet::getPosition()
{
	return m_position;
}

int Bullet::getDamage()
{
	return m_damage;
}

