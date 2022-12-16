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
	Artillery m_artillery; // gibt einen póinter auf ein geschütz
	Bullet m_bullets; // kein Char mehr weil Enemy auch nicht mehr (glaube ist aber noch nötig weil 3Kugeln am stück) 
	Enemy m_enemies; // kein Char mehr weil sonst keine werte für position von m_enemies



};