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
	vector<Bullet> m_bullets;
	vector<Enemy> m_enemies;



};