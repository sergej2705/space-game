#include "Enemy.h"

Enemy::Enemy(int startposition)
{
	m_position = startposition;
}

Enemy::Enemy() {} // weil compeiler sonst nicht funktioniert

Enemy::~Enemy()
{
}

int Enemy::getPosition()
{
	return m_position;
}

int Enemy::move()
{
	return m_position = m_position - 1;
}

void Enemy::hit()
{
}
