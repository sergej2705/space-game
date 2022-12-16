#include "Bullet.h"

Bullet::Bullet()
{
	 m_position = 1;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
	m_position = m_position + 1;
}

int Bullet::getPosition()
{
	return m_position; 
}

int Bullet::getDamage()
{
	return 0;
}
