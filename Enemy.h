#pragma once

class Enemy
{
public:
	Enemy(int startPosition, int health, int damage)
	{
		m_damage = damage;
		m_position = startPosition;
		m_health = health;
	}

	~Enemy()
	{
	}

	int getPosition()
	{
		return m_position;
	}

	void move()
	{
		m_position--;
	}

	int getDamage()
	{
		return m_damage;
	}

	void hit(int damage)
	{
		m_health = m_health - damage;
	}

private:
	int m_damage;
	int m_position;
	int m_health;
};
