#pragma once
#include <vector>
#include <string>

#include "Artillery.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace std;

class FiringLane {
public:
	FiringLane();
	~FiringLane();
	void nextTick();
	string print();

private:
	int m_length;
	Artillery m_artillery; // gibt einen p�inter auf ein gesch�tz
	Bullet m_bullets; // kein Char mehr weil Enemy auch nicht mehr (glaube ist aber noch n�tig weil 3Kugeln am st�ck) 
	Enemy m_enemies; // kein Char mehr weil sonst keine werte f�r position von m_enemies



};