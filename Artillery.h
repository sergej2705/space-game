#pragma once

#include "Bullet.h"

class Artillery
{
public:
	Artillery(int *health)
	{
		m_energylevel = 0;
		m_position = 0;
		m_health = health;
	}

	~Artillery() {}

	Bullet *tick(int ticksPassed)
	{
		if (ticksPassed % 2 == 0)
		{
			if (m_energylevel > 0)
			{
				m_energylevel--;
				return new Bullet(0, 1, 1);
			}
		}

		return nullptr;
	}

	void load(int energy)
	{
		m_energylevel = m_energylevel + energy;
	}

	void hit()
	{
		*m_health = *m_health - 1;
	}

	int getPosition()
	{
		return m_position;
	}

private:
	int m_energylevel;
	int m_position;
	int *m_health;
};
