#include <array>
#include <iostream>
#include "FiringLane.h"

using namespace std;

FiringLane::FiringLane()
{
	m_length = 20;
	m_artillery = Artillery();
	m_bullets = {};
	m_enemies = {Enemy(m_length)};
}

FiringLane::~FiringLane()
{
}

void FiringLane::nextTick()
{
	m_enemies.move();
	m_artillery.shoot();
	m_bullets.move();
}

string FiringLane::print()
{
	char *lane = new char[m_length];
	for (size_t y = 0; y < m_length; y++)
	{
		lane[y] = ' ';
	}
	lane[0] = 'G';
	lane[m_enemies.getPosition()] = 'X';
	lane[m_bullets.getPosition()] = '-';

	cout << lane << endl;

	return string();
}
