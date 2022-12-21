#pragma once

class Bullet
{
public:
	Bullet(int position, int health, int damage)
	{
		m_damage = damage;
		m_position = position;
		m_health = health;
	}

	~Bullet() {}

	void move()
	{
		m_position++;
	}

	int getPosition()
	{
		return m_position;
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
